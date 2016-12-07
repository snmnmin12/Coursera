//
//  castle.cpp
//  Algorithm
//
//  Created by Song on 12/29/15.
//  Copyright © 2015 Song. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
int castle[50][50];
int color[50][50];
int m,n;
int roomNum=0;
int maxRoomArea=0;
int roomArea;
int roominfo[10];
void dps(int i, int j)
{
    if (color[i][j]) return;
    color[i][j]=roomNum;
    roomArea++;
    
    if ((i-1>=0) && ((castle[i][j]&2)==0))
        dps(i-1, j);
    if ((i+1<m) && ((castle[i][j]&8)==0))
        dps(i+1, j);
    if ((j-1>=0) && ((castle[i][j]&1)==0))
        dps(i, j-1);
    if ((j+1<n) &&((castle[i][j]&4)==0))
        dps(i, j+1);
    
}

int main()
{
    scanf("%d%d",&m,&n);
    
    for (int i=0; i<m; i++)
    for (int j=0;j<n;j++)
    scanf("%d",&castle[i][j]);
    
    memset(color, 0, sizeof(color));
    
    for (int i=0; i<m; i++)
    for (int j=0; j<n; j++)
    {
        if (!color[i][j]) {
            ++roomNum;
            roomArea=0;
            dps(i,j);
            roominfo[roomNum]=roomArea;
            maxRoomArea=max(maxRoomArea,roomArea);
        }
    }
    printf("%d\n",roomNum);
    printf("%d\n", maxRoomArea);
    return 0;
}