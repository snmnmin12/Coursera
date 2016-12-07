//
//  Week5_lec.cpp
//  Algorithm
//
//  Created by Song on 12/19/15.
//  Copyright © 2015 Song. All rights reserved.
//

// 最长上升子序列
//#include <iostream>
//using namespace std;
//const int MAXN=1010;
//int a[MAXN]; int maxLen[MAXN];
//int main()
//{
//    int N;
//    cin>>N;
//    for (int i=1; i<=N; i++) {
//        cin>>a[i];
//        maxLen[i]=1;
//    }
//    
//    for (int i=2; i<=N; i++)
//    {
//        for (int j=1; j<i;j++) {
//            if(a[i]>a[j])
//            maxLen[i]=max(maxLen[i],maxLen[j]+1);
//        }
//    }
//    
//    cout<<*max_element(maxLen+1, maxLen+N+1)<<endl;
//
//    return 0;
//}
//最长公共子序列
//#include <iostream>
//#include <cstring>
//using namespace std;
//char sz1[1000];
//char sz2[1000];
//char sz3[1000];
//int maxLen[1000][1000];
//int main(){
//    while (cin>>sz1>>sz2) {
//        memset(sz3, 0, 1000);
//        int length1=strlen(sz1);
//        int length2=strlen(sz2);
//        int i,j;
//        for (i=0; i<=length1; i++)
//            maxLen[i][0]=0;
//        for (int j=0; j<=length2; j++)
//            maxLen[0][j]=0;
//        for (i=1; i<=length1; i++)
//            for (int j=1; j<=length2; j++)
//            {
//                if(sz1[i-1]==sz2[j-1])
//                    maxLen[i][j]=maxLen[i-1][j-1]+1;
//                else
//                    maxLen[i][j]=max(maxLen[i][j-1], maxLen[i-1][j]);
//            }
//        int index=maxLen[length1][length2];
//        i=length1;j=length2;
//        while (i>0 && j>0) {
//            if(sz1[i-1]==sz2[j-1])
//            {
//                sz3[index-1]=sz1[i-1];
//                i--;j--;index--;
//            }
//            else if(maxLen[i-1][j]>maxLen[i][j-1])
//                i--;
//            else
//                j--;
//        }
//        if (strlen(sz3)!=0)
//        cout<<"Longest common subsequence is "<<sz3<<" with size of "<<maxLen[length1][length2]<<endl;
//        else
//        cout<<"No longest common subsequence"<<endl;
//    }
//    return 0;
//}
//
/*Description

"Help Jimmy" 是在下图所示的场景上完成的游戏。


场景中包括多个长度和高度各不相同的平台。地面是最低的平台，高度为零，长度无限。

Jimmy老鼠在时刻0从高于所有平台的某处开始下落，它的下落速度始终为1米/秒。当Jimmy落到某个平台上时，游戏者选择让它向左还是向右跑，它跑动的速度也是1米/秒。当Jimmy跑到平台的边缘时，开始继续下落。Jimmy每次下落的高度不能超过MAX米，不然就会摔死，游戏也会结束。

设计一个程序，计算Jimmy到底地面时可能的最早时间。
Input

第一行是测试数据的组数t（0 <= t <= 20）。每组测试数据的第一行是四个整数N，X，Y，MAX，用空格分隔。N是平台的数目（不包括地面），X和Y是Jimmy开始下落的位置的横竖坐标，MAX是一次下落的最大高度。接下来的N行每行描述一个平台，包括三个整数，X1[i]，X2[i]和H[i]。H[i]表示平台的高度，X1[i]和X2[i]表示平台左右端点的横坐标。1 <= N <= 1000，-20000 <= X, X1[i], X2[i] <= 20000，0 < H[i] < Y <= 20000（i = 1..N）。所有坐标的单位都是米。

Jimmy的大小和平台的厚度均忽略不计。如果Jimmy恰好落在某个平台的边缘，被视为落在平台上。所有的平台均不重叠或相连。测试数据保证问题一定有解。
Output

对输入的每组测试数据，输出一个整数，Jimmy到底地面时可能的最早时间。
Sample Input

1
3 8 17 20
0 10 8
0 10 13
4 14 3
Sample Output

23
8 */
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//#define MAX_N 1000
//#define INFINITE 1000000
//int t,n,x,y,maxHeight;
//struct Platform{
//    int Lx;
//    int Rx;
//    int h;
//    bool operator<(const Platform& plat) const{
//        return h>plat.h;
//    }
//};
//Platform platForms[MAX_N+1];
//int leftMinTime[MAX_N+1];
//int rightMinTime[MAX_N+1];

//int mintime(int i,bool blfet){
//    int x;
//    if (blfet)
//        x=platForms[i].Lx;
//    else x=platForms[i].Rx;
//    int y=platForms[i].h;
//    int j;
//    //processing the left platform
//    for (j=i+1; j<=n; j++)
//        if(platForms[j].Lx<=x && x<=platForms[j].Rx)
//            break;
//    if(j>n){
//           if(y>maxHeight) return INFINITE;
//            else return y;
//           }
//    else{
//        if(y-platForms[j].h>maxHeight)
//        return  INFINITE;
//    }
//    
//    int leftime=y-platForms[j].h+x-platForms[j].Lx;
//    int rightime=y-platForms[j].h+platForms[j].Rx-x;
//    if (leftMinTime[j]==-1)
//        leftMinTime[j]=mintime(j, true);
//    leftime+=leftMinTime[j];
//    if (rightMinTime[j]==-1)
//        rightMinTime[j]=mintime(j, false);
//    rightime+=rightMinTime[j];
//    
//    return min(leftime, rightime);
//}
//递推的形式
//void mintime()
//{
//
//    for (int i=n; i>=0; i--)
//    {
//    
//        int lx=platForms[i].Lx;
//        int rx=platForms[i].Rx;
//        int h=platForms[i].h;
//        int j;
//        for (j=i+1; j<=n; j++)
//            if(platForms[j].Lx<=lx && lx<=platForms[j].Rx)
//                break;
//        if(j>n){
//            if(h>maxHeight) {leftMinTime[i]= INFINITE;}
//            else leftMinTime[i]=h;
//        }
//        else{
//            if(h-platForms[j].h>maxHeight)
//            {leftMinTime[i]= INFINITE;}
//            else{
//                leftMinTime[i]=min(lx-platForms[j].Lx+h-platForms[j].h+leftMinTime[j],
//                                   platForms[j].Rx-lx+h-platForms[j].h+rightMinTime[j]);
//            }
//            }
//
//        for (j=i+1; j<=n; j++)
//            if(platForms[j].Lx<=rx && rx<=platForms[j].Rx)
//                break;
//        if(j>n){
//            if(h>maxHeight) {rightMinTime[i]= INFINITE;}
//            else rightMinTime[i]=h;
//        }
//        else{
//                if(h-platForms[j].h>maxHeight)
//                {rightMinTime[i]= INFINITE;}
//                else{
//                    rightMinTime[i]=min(rx-platForms[j].Lx+h-platForms[j].h+leftMinTime[j],
//                                       platForms[j].Rx-rx+h-platForms[j].h+rightMinTime[j]);
//                }
//        
//        }
//    }
//
//}
//
//int main()
//{
//    cin>>t;
//    while (t--) {
//        memset(leftMinTime, -1, sizeof(leftMinTime));
//        memset(rightMinTime, -1, sizeof(rightMinTime));
//        cin>>n>>x>>y>>maxHeight;
//        platForms[0].Lx=x;platForms[0].Rx=x;platForms[0].h=y;
//        for (int i=1; i<=n; i++)
//        cin>>platForms[i].Lx>>platForms[i].Rx>>platForms[i].h;
//        sort(platForms, platForms+1+n);
//        mintime();
//        cout<<min(leftMinTime[0],rightMinTime[0])<<endl;
//        //cout<<mintime(0, true)<<endl;
//    }
//    
//    return 0;
//}

//#include <iostream>
//#include <cstring>
//#include <queue>
//using namespace std;
//const int INFINITE=1<<30;
//const int MAXL=1000;
//const int MAXN=100;
//int F[MAXL];
//int cowThere[MAXL];
//int N,L,A,B;
//struct Fx{
//    int x;
//    int f;
//    Fx(int _x=0, int _f=0):x(_x),f(_f){}
//    bool operator<(const Fx&a)const {
//        return f>a.f;
//    }
//};
//priority_queue<Fx> qFx;
//int main()
//{
//    cin>>N>>L;
//    cin>>A>>B;
//    A<<=1;B<<=1;
//    memset(cowThere, 0, sizeof(cowThere));
//    for (int i=0; i<N; i++) {
//        int s,e;
//        cin>>s>>e;
//        ++cowThere[s+1];
//        --cowThere[e];
//    }
//    int inCows=0;
//    for (int i=0; i<=L; i++) {
//        F[i]=INFINITE;
//        inCows+=cowThere[i];
//        cowThere[i]=inCows>0;
//    }
//    
//    for (int i=A;i<=B; i+=2) {
//        if (!cowThere[i]) {
//            F[i]=1;
//            if (i<B+2-A)
//                qFx.push(Fx(i,1));
//        }
//    }
//    
//    for (int i=B+2; i<=L; i+=2) {
//        if (!cowThere[i]) {
//            Fx fx;
//            while (!qFx.empty()) {
//                fx=qFx.top();
//                if (fx.x<i-B)
//                    qFx.pop();
//                else
//                    break;
//            }
//            if (!qFx.empty())
//                F[i]=fx.f+1;
//        }
//        if (F[i-A+2]!=INFINITE)
//        qFx.push(Fx(i-A+2,F[i-A+2]));
//    }
//    if (F[L]==INFINITE)
//        cout<<-1<<endl;
//    else
//        cout<<F[L]<<endl;
//    return 0;
//}

