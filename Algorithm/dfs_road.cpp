//
//  dfs_road.cpp
//  Algorithm
//
//  Created by Song on 12/29/15.
//  Copyright © 2015 Song. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
struct Road{
    int end;
    int length;
    int cost;
};
vector<vector<Road> > cityMap(110);
bool visited[110];
int minLenCost[110][10100];
int minlen=1<<30;
int totalLen;
int totalCost;
int K,N,R;
void dps(int i)
{
    //if (totalCost>K) return;
   // if (totalLen>minlen) return;
    if (i==N)
    {
        minlen=min(totalLen, minlen);
        return;
    }
    
    for (int j=0; j<cityMap[i].size(); j++)
    {
        int d=cityMap[i][j].end;
        if (!visited[d])
        {
            int cost=totalCost+cityMap[i][j].cost;
            if (cost>K) continue;
            if (totalLen+cityMap[i][j].length>=minlen) continue;
            if (totalLen+cityMap[i][j].length>=minLenCost[d][cost]) continue;
            visited[d]=1;
            totalLen+=cityMap[i][j].length;
            totalCost+=cityMap[i][j].cost;
            minLenCost[d][cost]=totalLen;
            dps(d);
            visited[d]=0;
            totalLen-=cityMap[i][j].length;
            totalCost-=cityMap[i][j].cost;
        }
    }
    
    
    
}
int main(){
    
    scanf("%d%d%d",&K,&N,&R);
    for (int i=0; i<R; i++)
    {
        int s;
        Road rd;
        scanf("%d%d%d%d",&s,&rd.end,&rd.length,&rd.cost);
        if (s!=rd.end)
        cityMap[s].push_back(rd);
    }
    
    for (int i=0; i<110; i++)
    for (int j=0; j<10100; j++)
    minLenCost[i][j]=1<<30;
    
    totalLen=0;totalCost=0;
    memset(visited, 0, sizeof(visited));
    visited[1]=1;
    dps(1);
    
    if (minlen==1<<30)
        printf("-1\n");
    else
        printf("%d\n",minlen);
    return 0;
}