

//  Week8_P1.cpp
//  Algorithm
//
//  Created by Song on 12/6/15.
//  Copyright © 2015 Song. All rights reserved.
//#include <stdio.h>
//#include <memory.h>
//int board[5][6];
//int board2[5][6];
//int operations[5][6];
//int minoperation=100000;
//bool flag;
//
//int count() //count operations
//{
//    int sum=0;
//    for(int i=0;i<5;i++)
//    for (int j=0; j<6; j++)
//        sum+=operations[i][j];
//    return sum;
//}
//
//
//void operation()
//{
//    flag=1;
//
//    for (int i=1; i<4; i++)
//    for (int j=1; j<5; j++)
//    operations[i+1][j]=(board[i][j]+operations[i][j]+operations[i-1][j]+operations[i][j-1]+operations[i][j+1])%2;
//   // operations[i+1][j]=(board[i][j]+operations[i][j]+operations[i-1][j]+operations[i][j-1]+operations[i][j+1]+1)%2;
//    
//    for (int j=1; j<5; j++)
//    {
//      if(board[4][j]+operations[4][j]+operations[4][j-1]+operations[4][j+1]+operations[3][j]!=0)
//      //if(board[4][j]+operations[4][j]+operations[4][j-1]+operations[4][j+1]+operations[3][j]!=1)
//      { flag=0;break;}
//    }
//    
//    if (flag )
//    {      int temp=count();
//           if (temp<minoperation)
//            minoperation=temp;
//    }
//}
//
//void operation2()
//{
//    flag=1;
//    
//    for (int i=1; i<4; i++)
//        for (int j=1; j<5; j++)
//            //operations[i+1][j]=(board[i][j]+operations[i][j]+operations[i-1][j]+operations[i][j-1]+operations[i][j+1])%2;
//            operations[i+1][j]=(board[i][j]+operations[i][j]+operations[i-1][j]+operations[i][j-1]+operations[i][j+1]+1)%2;
//    
//    for (int j=1; j<5; j++)
//    {
//        //if(board[4][j]+operations[4][j]+operations[4][j-1]+operations[4][j+1]+operations[3][j]!=0)
//        if(board[4][j]+operations[4][j]+operations[4][j-1]+operations[4][j+1]+operations[3][j]!=1)
//        { flag=0;break;}
//    }
//    
//    if (flag )
//    {      int temp=count();
//            if (temp<minoperation)
//            minoperation=temp;
//    }
//
//
//}
//
//
//
//int main()
//{
//    char c;
//    for (int i=1; i<5; i++)
//    for (int j=1; j<5; j++)
//    {  scanf(" %c", &c);
//       board[i][j]=(c=='b')?0:1;
//       board2[i][j]=(c=='b')?0:1;
//    }
////    
//    for (int j=0; j<6; j++)
//    board[0][j]=0;
//    for (int i=1; i<5; i++)
//    board[i][0]=board[i][5]=0;
//    
//    
//    
//    for (int j=0; j<6; j++)
//        board2[0][j]=1;
//    for (int i=1; i<5; i++)
//        board2[i][0]=board2[i][5]=1;
//    memset(operations, 0, sizeof(operations));
//
//    for (int i=0; i<15; i++)
//    {
//        operation();
//        operation2();
//        operations[1][1]+=1;
//        int c=1;
//        while (operations[1][c]>1)
//        {
//            operations[1][c]=0;
//            c++;
//            operations[1][c]+=1;
//        }
//    }
//    if (minoperation==100000)
//        printf("Impossible\n");
//    else printf("%d\n", minoperation);
//    return 0;
//}
//

////  Week8_P2.cpp
////  Algorithm
////
////  Created by Song on 12/6/15.
////  Copyright © 2015 Song. All rights reserved.
////
//
//#include <stdio.h>
//#include <queue>
//#include <stack>
//using namespace std;
//const int INF=1<<30;
//int maze[5][5];
//int pre[5][5];
//int to[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
//struct Point
//{
//    int x;
//    int y;
//    Point(int _x, int _y):x(_x),y(_y){}
//};
//
//void bfs(Point start)
//{
//    queue<Point> Q;
//    Q.push(start);
//    
//    while (!Q.empty())
//    {
//        Point temp=Q.front();
//        Q.pop();
//        int x;
//        int y;
//        for (int i=0; i<4; i++)
//        {
//            x=temp.x+to[i][0];
//            y=temp.y+to[i][1];
//            if (x<0 || x>4 || y<0|| y>4 || maze[x][y]==-1)  continue;
//            
//            if (maze[x][y]==INF)
//            {
//                maze[x][y]=maze[temp.x][temp.y]+1;
//                Q.push(Point(x,y));
//                pre[x][y]=temp.x*5+temp.y;
//            }
//        }
//        
//    }
//
//}
//
//void print()
//{
//    stack<Point> s;
//    s.push(Point(4,4));
//    int u=pre[4][4];
//    while (u!=-1) {
//        s.push(Point(u/5,u%5));
//        u=pre[u/5][u%5];
//    }
//    
//    int x;
//    int y;
//    
//    while (!s.empty()) {
//        x=s.top().x;
//        y=s.top().y;
//        printf("(%d, %d)\n",x,y);
//        s.pop();
//    }
//    
//
//}
//
//int main()
//{
//    int temp;
//    for (int i=0; i<5; i++)
//    for (int j=0; j<5; j++)
//    {
//        scanf("%d",&temp);
//        if (temp==0) maze[i][j]=INF;
//        else maze[i][j]=-1;
//        pre[i][j]=-1;
//    }
//    maze[0][0]=0;
//    bfs(Point(0,0));
//    print();
//    return 0;
//}