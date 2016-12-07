//
//  Week10_P.cpp
//  Algorithm
//
//  Created by Song on 12/25/15.
//  Copyright © 2015 Song. All rights reserved.
//

//编程题＃2：最大公约
//#include <stdio.h>
//#include <tuple>
//#include <cmath>
//#include <iostream>
//using namespace std;
////
//int gcd(int M, int N){
//    if (N%M==0) return M;
//    return gcd(N,M%N);
//}
//typedef tuple<int,int,int> TuInt;
//typedef pair<int , int > pint;
//TuInt exteded_euclid(int a, int b)
//{
//    //int t;
//    int x;
//    int y;
//    TuInt p;
//    if (b==0) {
//        x=1;
//        y=0;
//        p=make_tuple(a,x, y);
//    }
//    else
//    {
//        p=exteded_euclid(b, a%b);
//        //t=get<1>(p);
//        x=get<2>(p);
//        y=get<1>(p)-(a/b)*x;
//        int d=a*x+b*y;
//        p=make_tuple(d,x, y);
//    }
//    return p;
//}
//int solutions[100];
//int nn[10];
//int rr[10];
//int solve_linear_modu(int a, int b,int n)
//{
//    TuInt ti=exteded_euclid(a, n);
//    int d=get<0>(ti);
//    if (d%b!=0) return 0;
//        //cout<<"No Solutions!";
//        int x=get<1>(ti);
//        int x0=x*(d/b)%n;
//        for (int i=0; i<d; i++)
//        solutions[i]=(x0+i*n/d+n)%n;
//        return d;
//}
//
//int solve_euqaitons(int num)
//{
//    int n=1;
//    int a=0;
//    for (int i=0; i<num; i++)
//        n*=nn[i];
//    for (int i=0; i<num; i++) {
//        int m=n/nn[i];
//        TuInt ti=exteded_euclid(nn[i], m);
//        int minv=get<2>(ti);
//        int c=m*((minv+nn[i])%nn[i]);
//        //a=(a+rr[i]*c+n)%n;
//        a=(a+minv*m*rr[i]+n)%n;
//    }
//    return a;
//}
//
//int modu_expone(int a,int b,int n)
//{
//    int d=a;
//    for (int i=2; i<=b; i++)
//        d=(d%n)*a;
//    d=d%n;
//    return d;
//}
//
//int main()
//{
//    int M,N;
////    while (cin>>N>>M) {
////        cout<<(gcd(abs(M),abs(N)))<<endl;
////    }
//    //cin>>N>>M;
////    int d=gcd(M, N);
////    if (d==1) cout<<"No answer!"<<endl;
////    else
////    {
////        cout<<"The hare can't hide in "<<endl;
////        for (int i=0; i<=N/d-1; i++)
////            cout<<i*d<<" ";
////        cout<<endl;
//    //}
//    TuInt ti;
//    //ti=make_tuple(1,1,1);
////    int a,b,n;
////    cin>>a>>b>>n;
////    
////    int d=solve_linear_modu(a, b, n);
////    if (d)
////    for(int i=0;i<d;i++)
////    cout<<solutions[i]<<" ";
////    cout<<endl;
//    //cout<< (-2)%5 <<endl;
////    ti=exteded_euclid(N, M);
////    cout<<get<0>(ti) <<" "<<get<1>(ti) <<" "<<get<2>(ti)<<endl;
//    
////    int num;
////    cin>>num;
////    for (int i=0; i<num; i++)
////    cin>>rr[i]>>nn[i];
////    int sum=solve_euqaitons(num);
////    cout<<sum<<endl;
//    int a,b,n;
//    cin>>a>>b>>n;
//    cout<<modu_expone(a, b, n);
//    return 0;
//}

//编程题＃1：垃圾炸弹
//很奇怪 为什么 用函数不行
//#include <stdio.h>
//#include <cstring>
//#include <iostream>
//using namespace std;
//int city[1026][1026];
//int maxrubbish;
//int num,d;
//struct point{
//    int x;
//    int y;
//    int m;
//   }lo[22];
//int locsearch(int d)
//{
//    memset(city, 0, sizeof(city));
//    maxrubbish=0;
//    int countN=0;
//    for (int t=0; t<num; t++)
//    {
//        int i=lo[t].x;
//        int j=lo[t].y;
//        int m=lo[t].m;
//           // sum=0;
//            for (int k=i-d; k<=i+d; k++)
//            for (int p=j-d; p<=j+d; p++)
//            {
//            if ((k>=0 && k<1025) && (p>=0 && p<1025))
//            {
//            city[k][p]+=m;
//            if (city[k][p]>maxrubbish) {maxrubbish=city[k][p];countN=1;}
//            else if(city[k][p]==maxrubbish) countN++;
//            }
//            }
//        }
//    return countN;
//};
//int main()
//{
//    int T;
//    //cin>>t;
//    scanf("%d",&T);
//    while (T--) {
//        cin>>d>>num;
//        for (int i=0; i<num; i++)
//        cin>>lo[i].x>>lo[i].y>>lo[i].m;
////        memset(city, 0, sizeof(city));
////        maxrubbish=0;
////        int countN=0;
////        for (int t=0; t<num; t++)
////        {
////            int i=lo[t].x;
////            int j=lo[t].y;
////            int m=lo[t].m;
////            // sum=0;
////            for (int k=i-d; k<=i+d; k++)
////                for (int p=j-d; p<=j+d; p++)
////                {
////                    if ((k>=0 && k<1025) && (p>=0 && p<1025))
////                    {
////                        city[k][p]+=m;
////                        if (city[k][p]>maxrubbish) {maxrubbish=city[k][p];countN=1;}
////                        else if(city[k][p]==maxrubbish) countN++;
////                    }
////                }
////        }
//        //cout<<countN<<" "<<maxrubbish<<endl;
//        cout<<locsearch(d)<<" "<<maxrubbish<<endl;
//    }
//    return 0;
//}
//
//#include <iostream>
//using namespace std;
//int integer(int N, int j)
//{
//    
//    if (N==1 ||j==1) return 1;
//    if (N<j) return integer(N, N);
//    else if (N==j) return 1+integer(N, j-1);
//    else  return (integer(N-j, j)+integer(N,j-1));
//}
//int main()
//{
//    int N;
//    cin>>N;
//    cout<<integer(N, N)<<endl;
//
//    return 0;
//}

//
//#include <iostream>
//#include <climits>
//using namespace std;
//long long int a[50];
//bool test(int n)
//{
//    
//    for (int i=n; i>1; i--) {
//        if (n*a[i]%(n-1)!=0) return false;
//        else a[i-1]=(n*a[i])/(n-1)+1;
//    }
//    
//    return true;
//}
//int main()
//{
//    int N;
//    long long int maxN = LLONG_MAX;
//    while (cin>>N,N) {
//       
//        for (long long int i=1; i< maxN; i++) {
//             a[N]=N*i+1;
//            if (test(N)) break;
//        }
//        cout<<a[1]<<endl;
//    }
//
//    return 0;
//}
//
// 编程题＃6：献给阿尔吉侬的花束
//#include <stdio.h>
//#include<iostream>
//#include <queue>
//using namespace std;
//#define inf 1<<30
//struct Point{
//    int x,y;
//    Point(int xx, int yy):x(xx),y(yy){}
//};
//char maze[200][200];
//int weight[200][200];
//int R,C;
//
//void bfs(int startx,int starty)
//{
//    weight[startx][starty]=0;
//    queue<Point> que;
//    que.push(Point(startx,starty));
//    while (!que.empty())
//    {
//        Point p1=que.front();
//        que.pop();
//        int x=p1.x;
//        int y=p1.y;
//        int dir_x[4]={-1,1,0,0};
//        int dir_y[4]={0,0,-1,1};
//        for (int i=0; i<=3; i++)
//        {
//            int newx=x+dir_x[i];
//            int newy=y+dir_y[i];
//        if ((newx>=0 && newx<R && newy>=0 && newy<C) && weight[newx][newy]==inf && maze[newx][newy]!='#')
//        {  que.push(Point(newx,newy));
//            weight[newx][newy]=weight[x][y]+1;
//        }
//        }
//    }
//             
//}
//
//int main()
//{
//    int T;
//    scanf("%d",&T);
//    while (T--)
//    {
//        scanf("%d%d",&R,&C);
//        int start_x=0,start_y=0, end_x=0,end_y=0;
//        for (int i=0; i<R; i++)
//        for (int j=0; j<C; j++)
//            {
//                char c;
//                scanf(" %c",&c);
//                maze[i][j]=c;
//                if (c=='S') {start_x=i; start_y=j;}
//                if (c=='E') {end_x=i;end_y=j;}
//                weight[i][j]=inf;
//            }
//        bfs(start_x,start_y);
//        if (weight[end_x][end_y]!=inf)
//            printf("%d\n",weight[end_x][end_y]);
//        else printf("oop!\n");
//    }
//
//}

//编程题＃7：复杂的整数划分问题
//#include <iostream>
//#include <stdio.h>
//#define maxN 51
//int DP1[maxN][maxN];
//int DP2[maxN][maxN];
//int DP3[maxN][maxN];
//void dp1(int N,int k)
//{
//        for (int i=1; i<=N; i++)
//        for (int j=1; j<=k; j++)
//    {
//        if (j==1 || i==j)
//        DP1[i][j]=1;
//        else if(i>j )
//        DP1[i][j]=DP1[i-1][j-1]+DP1[i-j][j];
//    }
//}
//void dp2(int N,int k){
//    
//   
//    for (int i=1; i<=N;i++)
//    for (int j=1;j<=k; j++) {
//        DP2[0][j]=0;DP2[i][0]=0;
//    }
//    for (int i=1; i<=N;i++)
//    for (int j=1;j<=k; j++) {
//    if (i<j) DP2[i][j]=DP2[i][i];
//    else if(i==j) DP2[i][j]=1+DP2[i][j-1];
//    else if(i>j)  DP2[i][j]=DP2[i-j][j-1]+DP2[i][j-1];
//    
//    }
//}
//void dp3(int N, int k){
//    
//    for (int i=1; i<=N;i++)
//        for (int j=1;j<=k; j++) {
//            DP3[0][j]=0;DP3[i][0]=0;
//        }
//    
//    for (int i=1; i<=N;i++)
//        for (int j=1;j<=k; j=j+2) {
//            if (i<j) DP3[i][j]=DP3[i][i];
//            else if (i==j) DP3[i][j]=1+DP3[i][j-1];
//            else if (i>j)  DP3[i][j]=DP3[i-j][j]+DP3[i][j-1];
//            DP3[i][j+1]=DP3[i][j];
//        }
//}
//int main()
//{
//    int N,k;
//    while(scanf("%d%d",&N,&k)!=EOF){
//    dp1(N,k);
//    dp2(N,N);
//    dp3(N,N);
//    printf("%d\n",DP1[N][k]);
//    printf("%d\n",DP2[N][N]);
//    printf("%d\n",DP3[N][N]);
//    }
//    return 0;
//}
//
//#include <stdio.h>
//#include <cstring>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct crop{
//    int x;
//    int y;
//    int damage;
//    crop(int xx,int yy,int dd=0):x(xx),y(yy),damage(dd){}
//};
//
//bool operator<(const crop& c1, const crop c2)
//{
//    if(c1.x==c2.x) return c1.y<c2.y;
//    else return c1.x<c2.x;
//}
//bool operator==(const crop& c1, const crop c2)
//{
//    return (c1.x==c2.x) && (c1.y==c2.y);
//}
////int field[51][51];
//int R,C;
//vector<crop> vec;
//int frogn=0;
//int searchpath(const crop & c, int dx,int dy)
//{
//    crop c2(c.x,c.y,c.damage);
//    int steps=2;
//    while (c2.x<=R && c2.x>=1 && c2.y<=C && c2.y>=1) {
//        if (!binary_search(vec.begin(), vec.end(), c2) || c2.damage==0){
//            steps=0;
//            break;
//        }
//        c2.x+=dx;
//        c2.y+=dy;
//        steps++;
//    }
//    return steps;
//}
//
//int len(vector<crop> & vec)
//{
//    int length=0;
//    for (vector<crop>::iterator it=vec.begin(); it!=vec.end(); it++)
//        if(it->damage!=0) length++;
//    return length;
//}
//bool dfs(vector<crop>& vec)
//{
//    // frogn=0;
//   
//    if (!len(vec))
//        return true;
//    if (frogn>15) return false;
//    vector<crop> vec2=vec;
//    int n=vec.size();
//    for (int i=0; i<n-1; i++)
//    {
//        
//    if (vec[i].damage==0) continue;
//    for (int j=i+1; j<n;j++)
//    {
//        if( vec[j].damage==0) continue;
//        int x=vec[i].x;
//        int y=vec[i].y;
//        int dx=vec[j].x-vec[i].x;
//        int dy=vec[j].y-vec[i].y;
//        int pX=vec[i].x-dx;
//        int py=vec[i].y-dy;
//        int nx=vec[j].x+dx;
//        int ny=vec[j].y+dy;
//        if (pX<=R && pX>=1 && py<=C && py>=1) continue;
//        if (nx>R) break;
//        if(ny<1 || ny>C) continue;
//        int steps=searchpath(vec[j], dx, dy);
//        if (steps>2) {
//            for (int p=0; p<=steps; p++)
//            {
//                int nnx=x+p*dx;
//                int nny=y+p*dy;
//                crop temp(nnx,nny);
//                vector<crop>::iterator it=find(vec.begin(), vec.end(), temp);
//                if (it!=vec.end())
//                {
//                    if(it->damage>0)
//                    {
//                        it->damage--;
//                        if (it->damage==0) vec.erase(it);
//                    }
//                
//                }
//            }
//            frogn++;
//            if (dfs(vec)) return true;
//            frogn--;
//            vec=vec2;
//           // if (frogn>50) return false;
//        }
//    }
// }
//    
//    return false;
//}
//
//int main()
//{
//    
//    int total;
//   // vec.reserve(1000);
//    freopen("in5.txt", "r", stdin);
//    scanf("%d",&total);
//    while (total--) {
//        vec.clear();
//        scanf("%d%d",&R,&C);
//        int number;
//        scanf("%d",&number);
//        int x,y,d;
//        for (int i=0; i<number; i++)
//        {
//            scanf("%d%d%d",&x,&y,&d);
//            vec.push_back(crop(x,y,d));
//        }
//        sort(vec.begin(), vec.end());
//        if (dfs(vec)) {
//            cout<<frogn<<endl;
//        }
//    }
//    fclose(stdin);
////    for (int i=1; i<=10; i++)
////        for (int j=1;j<=10;j++)
////        {
////            if (i<=10 && i!=j )
////            cout<<i<<" "<<j<<" "<<1<<endl;
////            else if(i<=14)
////             cout<<i<<" "<<j<<" "<<2<<endl;
////    }
//    
//    return 0;
//}
//
//int search(int num)
//{
//    int frogn=0;
//    
//    
//    for (int i=0; i<vec.size()-1; i++)
//    for (int j=i+1; j<vec.size(); j++)
//    {
//        
//        int x1=vec[i].x;
//        int y1=vec[i].y;
//        int x2=vec[j].x;
//        int y2=vec[j].y;
//        
//        if (field[x1][y1]!=0 && field[x2][y2]!=0)
//        {
//        int dx=x2-x1;
//        int dy=y2-y1;
//        
//        if ((x1-dx)>0 && (x1-dx)<=R && (y1-dy) <=C && (y1-dy)>0) continue;
//        
//        if (x2+dx>R) break;
//        if(y2+dy<1 || y2+dy>C) continue;
//        
//        int n;
//            if (dx!=0) n=R/dx+1;
//            else n=C/dy+1;
//        bool flag=false;
//        for (int t=0; t<n; t++)
//        if ((x1+t*dx>0) && (x1+t*dx<=R) && (y1+t*dy>0) && (y1+t*dy<=C))
//        {
//            if (field[x1+t*dx][y1+t*dy]==0)
//            {
//                flag=true;
//                break;
//            }
//            field[x1+t*dx][y1+t*dy]--;
//        }
//        if (!flag)
//        frogn++;
//    }
//    
//    }
//    return frogn;
//}
//
//int main()
//{
//    int total;
//    scanf("%d",&total);
//    while (total--) {
//    memset(field, 0, sizeof(field));
//    scanf("%d%d",&R,&C);
//        int number;
//        scanf("%d",&number);
//        int x,y;
//        for (int i=0; i<number; i++)
//        {
//            scanf("%d%d",&x,&y);
//            vec.push_back(crop(x,y));
//            scanf("%d",&field[x][y]);
//        }
//        sort(vec.begin(), vec.end());
//        cout<<search(number)<<endl;
//    }
//
//
//    return 0;
//}
