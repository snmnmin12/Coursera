//
//  Week4_P2.cpp
//  Algorithm
//
//  Created by Song on 12/12/15.
//  Copyright © 2015 Song. All rights reserved.
//

#include <stdio.h>
#include <map>
using namespace std;

int height[100][100];
int value[100][100];

struct Point
{
    int i;
    int j;
    Point(int _x,int _y):i(_x),j(_y){}
};

int main()
{
    
    int n,m;
   
    multimap<int, Point> m1;
    int temp;
    int maximu=0;
    scanf("%d %d",&n,&m);
    
    for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
    {
        scanf("%d",&temp);
        height[i][j]=temp;
        value[i][j]=1;
        m1.insert(make_pair(temp, Point(i,j)));
    }
    
    for (multimap<int, Point>::iterator it = m1.begin();it!=m1.end();it++)
    {
        int i=it->second.i;
        int j=it->second.j;
        if (i-1>=0 && it->first> height[i-1][j]) value[i][j]=max(value[i-1][j]+1,value[i][j]);
        if(i+1<n&& it->first>height[i+1][j]) value[i][j]=max(value[i+1][j]+1, value[i][j]);
        if (j-1>=0 && it->first>height[i][j-1]) value[i][j]=max(value[i][j-1]+1, value[i][j]);
        if (j+1<m && it->first>height[i][j+1]) value[i][j]=max(value[i][j+1]+1, value[i][j]);
        if (maximu<value[i][j]) maximu=value[i][j];
    }
    
    printf("%d\n", maximu);

    return 0;
}
