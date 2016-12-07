//
//  dfs_sticks.cpp
//  Algorithm
//
//  Created by Song on 12/29/15.
//  Copyright © 2015 Song. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int sticks[64];
bool used[64];
int N,L;
int nLastStick;
struct comp
{
   bool operator()(int x, int y)
    {
        return x>y;
    }
}compare;
bool dps(int sticknLeft, int nleft)
{
    if (sticknLeft==0 && nleft==0) return true;
    
    if (nleft==0) nleft=L;
    int nstartN=0;
    if (nleft!=L) nstartN=nLastStick+1;
    for (int i=nstartN; i<N;i++)
    {
        if (i>0)
        {
            if(!used[i-1] && sticks[i]==sticks[i-1])
            continue;
        }
        if (!used[i] && sticks[i]<=nleft)
        {
            used[i]=true; nLastStick=i;
            
            if(dps(sticknLeft-1, nleft-sticks[i]))
            return true;
            else
            {
                used[i]=false;
                if (nleft==L || nleft==sticks[i])
                return false;
            }
        }
    }
  
    return false;
}

int main(){
    
 
    while(scanf("%d",&N),N)
    {
      
        int nTotalLen=0;
        for (int i=0; i<N; i++){
        scanf("%d",&sticks[i]);
        nTotalLen+=sticks[i];
        }
       
        sort(sticks, sticks+N, compare);
        
        for (L=sticks[0]; L<=nTotalLen/2; L++)
        {
            if (nTotalLen%L!=0) continue;
            //int S=nTotalLen/L;
            memset(used, 0, sizeof(used));
            if(dps(N,L))
            {
                printf("%d\n",L);
                break;
            }
        }
        if (L>nTotalLen/2)
        printf("%d\n",nTotalLen);
    }
    return 0;
}