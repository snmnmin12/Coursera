//
//  cake.cpp
//  Algorithm
//
//  Created by Song on 12/29/15.
//  Copyright © 2015 Song. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
    int N,M;
int area=0;
int minV[30];
int minA[30];
int minArea=1<<30;
int MaxVNRH(int n, int r, int h);

void dfs(int v, int m, int r, int h){
    
    if (m==0) {
        if (v) return;
        else{
            minArea=min(minArea,area);
            return;
        }
    }
    
    if (v<0) return;
    if (minV[m]>v) return;
    if (area+minA[m]>=minArea)
        return;
    if (h<m || r<m) return;
    
    if (MaxVNRH(m, r, h)<v) return;
    
    for (int rr=r; rr>=m; rr--)
    {
        if (m==M) area=rr*rr;
    for (int hh=h; hh>=m; hh--)
    {
        area+=2*rr*hh;
        dfs(v-rr*rr*hh, m-1, rr-1, hh-1);
        area-=2*rr*hh;
    }
    }
    
}
int main()
{
    cin>>N>>M;
    minV[0]=0;
    minV[0]=0;
    for (int i=1; i<=M; i++)
    {
        minV[i]=minV[i-1]+i*i*i;
        minA[i]=minA[i-1]+2*i*i;
    }
    
    if (minV[M]>N)
        cout<<0<<endl;
    else{
        
        int maxH=(N-minV[M-1])/M/M+1;
        int maxR=sqrt(double(N-minV[M-1])/M)+1;
        minArea=1<<30;
        area=0;
        dfs(N,M,maxR,maxH);
        if (minArea==1<<30)
            cout<<0<<endl;
        else
        cout<<minArea<<endl;
    }
    return 0;
}
int MaxVNRH(int n, int r, int h){
    
    int v=0;
    for (int i=0; i<n; i++)
        v+=(r-i)*(r-i)*(h-i);
    return v;
}
