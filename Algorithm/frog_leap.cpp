//
//  frog_leap.cpp
//  Algorithm
//
//  Created by Song on 12/29/15.
//  Copyright © 2015 Song. All rights reserved.
//
#include <stdio.h>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct crop{
    int x;
    int y;
    int damage;
    crop(int xx,int yy,int dd=0):x(xx),y(yy),damage(dd){}
};

bool operator<(const crop& c1, const crop c2)
{
    if(c1.x==c2.x) return c1.y<c2.y;
    else return c1.x<c2.x;
}
bool operator==(const crop& c1, const crop c2)
{
    return (c1.x==c2.x) && (c1.y==c2.y);
}
//int field[51][51];
int R,C;
vector<crop> vec;
int frogn=0;
int searchpath(const crop & c, int dx,int dy)
{
    crop c2(c.x,c.y,c.damage);
    int steps=2;
    while (c2.x<=R && c2.x>=1 && c2.y<=C && c2.y>=1) {
        if (!binary_search(vec.begin(), vec.end(), c2) || c2.damage==0){
            steps=0;
            break;
        }
        c2.x+=dx;
        c2.y+=dy;
        steps++;
    }
    return steps;
}

int len(vector<crop> & vec)
{
    int length=0;
    for (vector<crop>::iterator it=vec.begin(); it!=vec.end(); it++)
        if(it->damage!=0) length++;
    return length;
}
bool dfs(vector<crop>& vec)
{
    // frogn=0;

    if (!len(vec))
        return true;
    if (frogn>15) return false;
    int n=vec.size();
    for (int i=0; i<n-1; i++)
    {

    if (vec[i].damage==0) continue;
        
    for (int j=i+1; j<n;j++)
    {
        if( vec[j].damage==0) continue;
        int x=vec[i].x;
        int y=vec[i].y;
        if (x-vec[0].x>1/2*(vec[n-1].x-vec[0].x)) break;
        if ((y-vec[0].y)>1/2*(vec[n-1].y-vec[0].y)) break;
        int dx=vec[j].x-vec[i].x;
        int dy=vec[j].y-vec[i].y;
        int pX=vec[i].x-dx;
        int py=vec[i].y-dy;
        int nx=vec[j].x+dx;
        int ny=vec[j].y+dy;
        if (pX<=R && pX>=1 && py<=C && py>=1) continue;
        if (nx>R) break;
        if(ny<1 || ny>C) continue;
        int steps=searchpath(vec[j], dx, dy);
        if (steps<=2) continue;
        
        vector<crop> vec2=vec;
            for (int p=0; p<=steps; p++)
            {
                int nnx=x+p*dx;
                int nny=y+p*dy;
                crop temp(nnx,nny);
                vector<crop>::iterator it=find(vec.begin(), vec.end(), temp);
                if (it!=vec.end())
                {
                    if(it->damage>0)
                    {
                        it->damage--;
                        if (it->damage==0) vec.erase(it);
                    }

                }
            }
            frogn++;
            if (dfs(vec)) return true;
            else {
            frogn--;
            vec=vec2;
            }
           // if (frogn>50) return false;
       }
 }

    return false;
}

int main()
{

    int total;
   // vec.reserve(1000);
    freopen("in5.txt", "r", stdin);
    scanf("%d",&total);
    while (total--) {
        vec.clear();
        scanf("%d%d",&R,&C);
        int number;
        scanf("%d",&number);
        int x,y,d;
        for (int i=0; i<number; i++)
        {
        scanf("%d%d%d",&x,&y,&d);
        vec.push_back(crop(x,y,d));
        }
        sort(vec.begin(), vec.end());
        if (dfs(vec))
        cout<<frogn<<endl;
    }
    fclose(stdin);
    return 0;
}

