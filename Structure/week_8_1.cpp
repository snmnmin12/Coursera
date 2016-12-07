//
//  week_8_1.cpp
//  Structure
//
//  Created by Song on 1/19/16.
//  Copyright © 2016 Song. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define  INF 1<<30
struct Place
{
    string str;
    int dis;
};

vector<string> vertex;
vector<vector<Place> > places(50);

struct Dist
{
    bool mark;
    int index;
    int length;
    int pre;
    bool operator<(const Dist& pl)const {return length>pl.length;}
};

void Dijistra(string str1,string str2)
{
    priority_queue<Dist> que;
    int size=vertex.size();
    Dist D[size];
    for (int i=0; i<vertex.size(); i++)
    {
        D[i].mark=0;
        D[i].index=i;
        D[i].length=INF;
        D[i].pre=-1;
    }
    int s=find(vertex.begin(), vertex.end(), str1)-vertex.begin();
    int des=find(vertex.begin(), vertex.end(), str2)-vertex.begin();
    D[s].length=0;
    
    que.push(D[s]);
    for (int i=0; i<vertex.size(); i++)
    {
        bool FOUND=false;
        Dist d;
        while (!que.empty())
        {
            d=que.top();
            que.pop();
            if (d.mark==0)
            {
                FOUND=true;break;
            }
        }

       if (!FOUND) break;
        int v=d.index;
        if (v==des) break;
        d.mark=1;
        for (int i=0;i<places[v].size();i++) {
            int e=find(vertex.begin(),vertex.end(),places[v][i].str)-vertex.begin();
            if (D[e].length>(D[v].length+places[v][i].dis))
            {
                D[e].length=D[v].length+places[v][i].dis;
                D[e].pre=v;
                que.push(D[e]);
            }
        }
    }
    
    stack<Dist> sta;
    int i=des;
    while (D[i].pre>-1)
    {
        sta.push(D[i]);
        i=D[i].pre;
    }
    cout<<str1;
    int predistance=0;
    while (!sta.empty())
    {
        Dist dist=sta.top();
        sta.pop();
        cout<<"->("<<dist.length-predistance<<")->"<<vertex[dist.index];
        predistance=dist.length;
    }
    cout<<endl;
    
}



int main()
{
    int n;
    cin>>n;
    string str;
    while (n--)
    {
        cin>>str;
        vertex.push_back(str);
    }
    Place pl;
    cin>>n;
    while (n--)
    {
        cin>>str;
        int i=find(vertex.begin(), vertex.end(), str)-vertex.begin();
        cin>>pl.str>>pl.dis;
        places[i].push_back(pl);
        i=find(vertex.begin(), vertex.end(), pl.str)-vertex.begin();
        pl.str=str;
        places[i].push_back(pl);
    }
    cin>>n;
    while (n--)
    {
        string source;
        string desti;
        cin>>source>>desti;
        if (source==desti)
            cout<<source<<endl;
        else
            Dijistra(source, desti);
    
    }
     return 0;
}