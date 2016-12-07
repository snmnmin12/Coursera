////
////  Week8_P1.cpp
////  Algorithm
////
////  Created by Song on 12/23/15.
////  Copyright © 2015 Song. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//#define MAXIN 100000
//int N,C;
//int a[MAXIN+10];
//bool check(int x)
//{
//    int prepos=a[0];
//    int countcow=1;
//    //int d=0;
//    for (int i=1; i<N; i++)
//    {
//        if (a[i]-prepos>=x) {
//            countcow++;
//            if (countcow==C) return true;
//            prepos=a[i];
//        }
//        
//    }
//
//    return false;
//}
//int main()
//{
//    scanf("%d %d",&N,&C);
//    for (int i=0; i<N; i++)
//    scanf("%d",&a[i]);
//    sort(a, a+N);
//    
//    int l=1;
//    int r=a[N-1]-a[0];
//    int mid;
//    while (r>=l) {
//        mid=(l+r)/2;
//        if (check(mid)) l=mid+1;
//        else r=mid-1;
//    }
//    printf("%d",r);
//
//    return 0;
//}

//#include <stdio.h>
//#include <iostream>
//#define manN 100010
//int c[manN],y[manN];
//using  namespace std;
//int main()
//{
//    freopen("in2.txt", "r", stdin);
//    int N,S;
//    scanf("%d %d", &N,&S);
//    for (int i=0; i<N; i++)
//    scanf("%d%d",&c[i],&y[i]);
//    
//    int p=c[0];
//    int j=0;
//    long long int cost=c[0]*y[0];
//    for (int i=1; i<N; i++) {
//        if (p+(i-j)*S>c[i]) {p=c[i];j=i;}
//    else p=p+(i-j)*S;
//    cost+=p*y[i];
//    }
//    printf("%lld\n",cost);
//    fclose(stdin);
//    return 0;
//}
//#include <iostream>
//#include <queue>
//using namespace std;
//const int N = 30;
//struct node {int nf, idx; void set(int nn, int ii) {nf = nn; idx = ii;}};
//int nl, ntime, f[N], t[N], d[N], totf, stay[N], beststay[N];
//typedef priority_queue<node> PQ;
//
//bool operator<(const node&a, const node& b) { if(a.nf == b.nf) return a.idx > b.idx; return a.nf < b.nf; }
//
//int main () {
//    int i, j;
//    while(scanf("%d", &nl), nl) {
//        scanf("%d", &ntime);
//        ntime *= 12;
//        int maxf = -1;
//        for(i = 0; i<nl; i++) scanf("%d", f+i);
//        for(i = 0; i<nl; i++) scanf("%d", d+i);
//        for(i = 0; i<nl-1; i++) scanf("%d", t+i);
//        for(i = 0; i<nl; i++) {
//            memset(stay, 0, sizeof(stay));
//            totf = 0;
//            if(i>0) ntime -= t[i-1];
//            node now;
//            PQ pq;
//            for(j = 0; j<=i; j++)
//            { now.set(f[j], j); pq.push(now);}
//            for(j = 0; j<ntime; j++) {
//                now = pq.top();
//                pq.pop();
//                stay[now.idx] += 5;
//                totf += now.nf;
//                now.nf -= d[now.idx];
//                if(now.nf < 0) now.nf = 0;
//                pq.push(now);
//            }
//            if(totf > maxf) {
//                maxf = totf;
//                memcpy(beststay, stay, sizeof(stay));
//            }
//        }
//        printf("%d", beststay[0]);
//        for(i = 1; i<nl; i++) printf(", %d", beststay[i]);
//        printf("\nNumber of fish expected: %d\n\n", maxf);
//    }
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct lake{
//    int i;
//    int fi;
//    int di;
//    int ti;
//    //lake(int ffi,int ddi,int tti):fi(ffi),di(ddi),ti(tti){}
//};
//struct compare{
//bool operator()(const lake& la1, const lake& la2) const {
//        if(la1.fi==la2.fi) return la1.i>la2.i;
//        else return la1.fi<la2.fi;
//    }
//}mycompare;
////vector<lake> veclake;
//lake la[30];
//lake la2[30];
//int stay[30];
//int beststay[30];
//int totoalfish;
//int maxfish;
//int main()
//{
//    freopen("in4.txt", "r", stdin);
//    freopen("out3.txt", "w", stdout);
//    int n;
//    int countN=0;
//    int totaltime;
//    while (cin>>n) {
//        if(!n) break;
//        if (countN++) cout<<endl;
//        maxfish=-1;
//        cin>>totaltime;
//        totaltime*=12;
//        for (int i=0; i<n; i++) {
//            la[i].i=i;
//            cin>>la[i].fi;
//        }
//        for (int i=0; i<n; i++) cin>>la[i].di;
//        la[0].ti=0;
//        for (int i=1; i<n; i++) cin>>la[i].ti;
//    
//        //int timeleft=totaltime;
//        for (int i=0; i<n; i++)
//        {
//            memcpy(la2, la, sizeof(la));
//            memset(stay, 0, sizeof(stay));
//            totoalfish=0;
//            totaltime-=la2[i].ti;
//            for (int j=0; j<totaltime; j++)
//            {
//             lake* maxfishindex=max_element(la2, la2+i+1,mycompare);
//             stay[maxfishindex->i]+=5;
//             totoalfish+=maxfishindex->fi;
//             maxfishindex->fi-=maxfishindex->di;
//             if (maxfishindex->fi<0) maxfishindex->fi=0;
//            }
//            if (totoalfish>maxfish)
//            {
//                maxfish=totoalfish;
//                memcpy(beststay, stay, sizeof(stay));
//            }
//        }
//        cout<<beststay[0];
//        for (int i=1; i<n;i++)
//        cout<<", "<<beststay[i];
//        cout<<endl<<"Number of fish expected: "<<maxfish<<endl;
//    }
//    fclose(stdin);
//    fclose(stdout);
//  
//}
