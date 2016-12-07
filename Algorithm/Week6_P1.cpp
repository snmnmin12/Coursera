//
//  Week6_P1.cpp
//  Algorithm
//
//  Created by Song on 12/21/15.
//  Copyright © 2015 Song. All rights reserved.
//

//#include <stdio.h>
//#include <vector>
//#include <cstring>
//using namespace std;
//char qiz[8][8];
//bool visic[8];
//bool visir[8];
//struct point{
//    int x,y;
//    point(int xx,int yy):x(xx),y(yy){}
//};
//int N,k;
//int num;
//vector<point> vec1;
//void dfs(int i,int j, int k)
//{
//    if (k==0) {num++; return;}
//        for (int m=0; m<N; m++)
//        for (int n=0; n<N; n++)
//        if(qiz[m][n]=='#' && visic[n]==false && visir[m]==false)
//         {
//             visic[n]=true;visir[m]=true;
//             dfs(m, n, k-1);
//             visic[n]=false;visir[m]=false;
//         }
//    
//}
//void dfs(int n, int k)
//{
//    if (k==0) {num++; return;}
//    if (n>=vec1.size()) return;
//    for (int p=n; p<vec1.size(); p++) {
//    int j=vec1[p].y;
//    int i=vec1[p].x;
//   if(visic[j]==false && visir[i]==false)
//    {
//        visic[j]=true;visir[i]=true;
//        dfs(p+1, k-1);
//        visic[j]=false;visir[i]=false;
//    }
//}
//    
//}
//int main()
//{
//    scanf(" %d%d", &N, &k);
//    while (N!=-1 && k!=-1) {
//        num=0;
//        vec1.clear();
//        for (int i=0; i<N; i++)
//        for (int j=0; j<N; j++)
//        {
//            scanf(" %c",&qiz[i][j]);
//            if (qiz[i][j]=='#') vec1.push_back(point(i,j));
//        }
//        memset(visic, 0, sizeof(visic));
//        memset(visir, 0, sizeof(visir));
//        //dfs(0,0,k);
////        visir[vec1[0].x]=1;
////        visic[vec1[0].y]=1;
//        dfs(0,k);
//        printf("%d\n",num);
//        scanf(" %d%d", &N, &k);
//    }
//
//}

//#include <stdio.h>
//#include <string>
//#include <sstream>
//#include <stack>
//using namespace std;
//
//struct chess{
//    int i;
//    int j;
//    int k;
//    chess(int ii,int jj,int kk):i(ii),j(jj),k(kk){}
//};
//struct location{
//    char c;
//    int i;
//    location(int cc,int ii):c(cc),i(ii){}
//};
//int chessboard[30][30];
//bool visted[30][30];
//int R,C,k;
//stack<location> loc;
////stack<location> loc2;
//string Smax;
////void dfs(int R, int C)
////{
////    int i,j,k=30;
////    stack<chess> sta;
////    stack<location> loc;
////    sta.push(chess(1,1,R*C));
////    loc.push(location('A',1));
////   // visted[1][1]=1;
////    while (!sta.empty())
////    {
////        chess temp=sta.top();
////        i=temp.i;
////        j=temp.j;
////        k=temp.k;
////        sta.pop();
////        if (k==1) break;
////        //loc.pop();
////        if (visted[i][j]) loc.pop();
////        else
////            {
////            visted[i][j]=1;
////            if (i+1<=R && j+2<=C) //&& visted[i+1][j+2]==0)
////            {
////                sta.push(chess(i+1,j+2,k-1));
////                loc.push(location('A'+j+2-1,i+1));
////                //visted[i+1][j+2]=1;
////            }
////            if (i+2<=R && j+1<=C)// && visted[i+2][j+1]==0)
////            {
////                sta.push(chess(i+2,j+1,k-1));
////                loc.push(location('A'+j+1-1,i+2));
////                //visted[i+2][j+1]=1;
////                
////            }
////            if (i+2<=R && j-1>=1)// && visted[i+2][j-1]==0)
////            {
////                sta.push(chess(i+2,j-1,k-1));
////                loc.push(location('A'+j-1-1,i+2));
////               // visted[i+2][j-1]=1;
////            }
////            if (i+1<=R && j-2>=1)// && visted[i+1][j-2]==0)
////            {
////                sta.push(chess(i+1,j-2,k-1));
////                loc.push(location('A'+j-2-1,i+1));
////                //visted[i+1][j-2]=1;
////            }
////            if (i-1>=1 && j-2>=1)// && visted[i-1][j-2]==0 )
////            {
////                sta.push(chess(i-1,j-2,k-1));
////                loc.push(location('A'+j-2-1,i-1));
////                //visted[i-1][j-2]=1;
////            }
////            if (i-2>=1 && j-1>=1)// && visted[i-2][j-1]==0)
////            {
////                sta.push(chess(i-2,j-1,k-1));
////                loc.push(location('A'+j-1-1,i-2));
////                //visted[i-2][j-1]=1;
////            }
////            if (i-2>=1 && j+1<=C)// && visted[i-2][j+1]==0)
////            {
////                sta.push(chess(i-2,j+1,k-1));
////                loc.push(location('A'+j+1-1,i-2));
////               // visted[i-2][j+1]=1;
////            }
////            if (i-1>=1 && j+2<=C)// && visted[i-1][j+2]==0)
////            {
////                sta.push(chess(i-1,j+2,k-1));
////                loc.push(location('A'+j+2-1,i-1));
////                //visted[i-1][j+2]=1;
////            }
////        }
////        
////    }
////    if (k!=1) {printf("impossible");printf("\n");}
////    else
////    {while(!loc.empty()) {printf("%c%d",loc.top().c,loc.top().i);loc.pop();}
////        printf("\n");
////    }
////}
//
//bool dfs(int i, int j, int k)
//{
//    if (k==1)  return true;
//
//        if (i-1>=1 && j-2>=1 && visted[i-1][j-2]==0 )
//        {
//            visted[i-1][j-2]=1;
//           loc.push(location('A'+j-2-1,i-1));
//            if(dfs(i-1, j-2, k-1)) return true;
//            loc.pop();
//            visted[i-1][j-2]=0;
//        }
//        if (i+1<=R && j-2>=1 && visted[i+1][j-2]==0)
//        {
//            visted[i+1][j-2]=1;
//            loc.push(location('A'+j-2-1,i+1));
//            if(dfs(i+1, j-2, k-1)) return true;
//            loc.pop();
//            visted[i+1][j-2]=0;
//        }
//
//        if (i-2>=1 && j-1>=1 && visted[i-2][j-1]==0)
//        {
//            visted[i-2][j-1]=1;
//            loc.push(location('A'+j-1-1,i-2));
//            if(dfs(i-2, j-1, k-1)) return true;
//            loc.pop();
//            visted[i-2][j-1]=0;
//        }
//
//        if (i+2<=R && j-1>=1 && visted[i+2][j-1]==0)
//        {
//            visted[i+2][j-1]=1;
//            loc.push(location('A'+j-1-1,i+2));
//            if(dfs(i+2, j-1, k-1)) return true;
//            loc.pop();
//            visted[i+2][j-1]=0;
//        }
//        if (i-2>=1 && j+1<=C && visted[i-2][j+1]==0)
//        {
//            visted[i-2][j+1]=1;
//            loc.push(location('A'+j+1-1,i-2));
//            if(dfs(i-2, j+1, k-1)) return true;
//            loc.pop();
//            visted[i-2][j+1]=0;
//        }
//        if (i+2<=R && j+1<=C && visted[i+2][j+1]==0)
//        {
//            visted[i+2][j+1]=1;
//            loc.push(location('A'+j+1-1,i+2));
//            if(dfs(i+2, j+1, k-1)) return true;
//            loc.pop();
//            visted[i+2][j+1]=0;
//        }
//
//        if (i-1>=1 && j+2<=C && visted[i-1][j+2]==0)
//        {
//             visted[i-1][j+2]=1;
//            loc.push(location('A'+j+2-1,i-1));
//            if(dfs(i-1, j+2, k-1)) return true;
//            loc.pop();
//            visted[i-1][j+2]=0;
//        }
//
//        if (i+1<=R && j+2<=C && visted[i+1][j+2]==0)
//        {
//            visted[i+1][j+2]=1;
//            loc.push(location('A'+j+2-1,i+1));
//            if(dfs(i+1, j+2,k-1)) return true;
//            loc.pop();
//            visted[i+1][j+2]=0;
//        }
//    return false;
//  
//}
//int main()
//{
//    int total;
//    scanf("%d",&total);
//    for (int i=1; i<=total; i++) {
//    scanf("%d %d",&R,&C);
//    memset(visted, 0, sizeof(visted));
//    printf("Scenario #%d:\n",i);
//    while (!loc.empty()) loc.pop();
//    loc.push(location('A',1));
//        visted[1][1]=1;
//    if(!dfs(1, 1, R*C))
//    {
//        printf("impossible");printf("\n\n");
//    }
//    else
//    {
//        stack<location> loc2;
//        while (!loc.empty())
//        {
//        loc2.push(loc.top());
//        loc.pop();
//        }
//        while (!loc2.empty())
//        {
//        printf("%c%d",loc2.top().c,loc2.top().i);
//        loc2.pop();
//        }
//        printf("\n\n");
//        }
//    }
//    
//    return 0;
//}