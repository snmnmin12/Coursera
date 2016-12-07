//
//  Sudoku.cpp
//  Algorithm
//
//  Created by Song on 12/30/15.
//  Copyright © 2015 Song. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool rowFlags[9][10];//rowFlag[i][num] = 1表示在 第 i行 已经放了数字num
bool colFlags[9][10];//colFlag[i][num] = 1表示在 第 i列 已经放了数字num
bool blockFlags[9][10];;//blockFlag[i][num]=1表示在第i个块已经放了数字num
int board[9][9];//整个棋盘
struct Pos{
    int r,c;
    Pos(int rr,int cc):r(rr),c(cc){}
};
inline int getBlocNum(int r, int c)
{
    int rr=r/3;
    int cc=c/3;
    return rr*3+cc;
}
vector<Pos> vec; //save the blanks
void setAllflags(int i,int j,int num, bool flag)
{
    rowFlags[i][num]=flag;
    colFlags[j][num]=flag;
    blockFlags[getBlocNum(i, j)][num]=flag;
}
bool isOK(int i, int j, int num)
{
    return (!rowFlags[i][num] && !colFlags[j][num] && !blockFlags[getBlocNum(i, j)][num]);
}
bool dfs(int n)
{
    if (n<0)
        return true;
    
    int r=vec[n].r;
    int c=vec[n].c;
    for (int num=1;num<=9;num++)
    {
        if (isOK(r, c, num))
        {
            board[r][c]=num;
            setAllflags(r, c, num,1);
            if (dfs(n-1)) return true;
            setAllflags(r, c, num, 0);
        }
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while (t--) {
        memset(rowFlags, 0, sizeof(rowFlags));
        memset(colFlags, 0, sizeof(colFlags));
        memset(blockFlags, 0, sizeof(blockFlags));
        for (int i=0; i<9; i++)
        for (int j=0; j<9; j++)
        {
            char temp;
            scanf(" %c",&temp);
            board[i][j]=temp-'0';
            if (board[i][j])
            setAllflags(i, j, board[i][j], 1);
            else
            vec.push_back(Pos(i, j));
        }
    
        if (dfs(vec.size()-1))
        {
            for (int i=0;i<9; i++)
            {
            for (int j=0; j<9; j++)
                cout<<board[i][j];
                cout<<endl;
            }
        }
    
    }
    return 0;
}
