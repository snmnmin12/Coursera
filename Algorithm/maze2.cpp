////
////  maze2.cpp
////  Algorithm
////
////  Created by Song on 12/4/15.
////  Copyright © 2015 Song. All rights reserved.
////
//
//#include <stdio.h>
//#include <stack>
//#define MAXIN 100
//#define inf 10000
//char puzzle[MAXIN+2][MAXIN+2];
//int ministep,w,h;
//int to[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//unsigned int mark[MAXIN+2][MAXIN+2];
//using namespace std;
//
//struct Point{
//    int x, y;
//    Point(int _x,int _y):x(_x),y(_y){}
//};
//
//stack<Point> st1;
//stack<Point> st2;
//void Search(stack<Point> & st2,Point start, Point end){
//    //    if (mark[now_y][now_x]<inf && mark[now_y][now_x]!=0) return;
//    
//    if (st2.empty()) st2.push(start);
//    
//    if (start.x==end.x && start.y==end.y)
//    {
//        if (st2.size()<st1.size()||st1.empty())
//            st1=st2;
//         return ;
//    }
//    
//       // return true;
//    
//    for (int i=0; i<4; i++)
//    {
//        int x=start.x+to[i][0];
//        int y=start.y+to[i][1];
//        if ((x>-1) && (x<w+2) && (y>-1)&&(y<h+2)
//            &&(puzzle[y][x]!='#'))
//        {
//            if (mark[y][x]>mark[start.y][start.x]+1)
//            {
//                mark[y][x]=mark[start.y][start.x]+1;
//                //Search(x, y, end_x, end_y);
//                st2.push(Point(x,y));
//                Search(st2,Point(x,y), end);
//                st2.pop();
//            }
//        }
//    }
//}
//
//void printPath(stack<Point> &path)
//{
//    while (!st2.empty()) st2.pop();
//    while (!path.empty())
//    {
//        st2.push(path.top());
//        path.pop();
//    }
//    while (!st2.empty())
//    {
//        printf("[%d][%d] ==>> [%2d]\n",
//               st2.top().y, st2.top().x,mark[st2.top().y][st2.top().x]);
//        st2.pop();
//    }
//}
//
//
//int main(){
//           freopen("data.txt", "r", stdin);
//    //        freopen("out.txt", "w", stdout);
//    scanf("%d %d",&h,&w);
//    int i,j;
//    for (i=0; i<MAXIN+2; i++) puzzle[0][i]=puzzle[i][0]='#';
//    for (i=1; i<=h; i++)
//        for (j=1; j<=w; j++)
//        {   scanf(" %c",&puzzle[i][j]);
//            mark[i][j]=inf;
//        }
//    
//    for (i=0; i<=w; i++) puzzle[h+1][i+1]='#';
//    for (i=0; i<=h; i++) puzzle[i+1][w+1]='#';
//    int begin_x=0,begin_y=0,end_x=0,end_y=0;
//    for (i=1; i<=h; i++)
//        for (j=1; j<=w; j++)
//        {    if (puzzle[i][j]=='S') {begin_x=j;begin_y=i;}
//            if (puzzle[i][j]=='T') {end_x=j;end_y=i;}
//        }
//    
//    mark[begin_y][begin_x]=0;
//    Point start(begin_x,begin_y),end(end_x, end_y);
//    Search(st2,start, end);
//    ministep=mark[end_y][end_x];
//    if (ministep<inf) printf("%d\n",ministep);
//    else printf("Path impossible.\n");
//    printPath(st1);
//        fclose(stdin);
//    //       fclose(stdout);
//    return 0;
//}
