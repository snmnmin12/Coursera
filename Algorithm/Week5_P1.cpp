//
//  Week5_P1.cpp
//  Algorithm
//
//  Created by Song on 12/20/15.
//  Copyright © 2015 Song. All rights reserved.
//

//#include <stdio.h>
//#include <cstring>
//unsigned int S[250][250];
//int N;
//
//int pali(int n,int m){
//    //if (n==0) return S[0][m];
//    for (int i=m; i<=n; i++) {
//        if (n>=2*i) {
//            if (S[n-2*i][i]==0) S[n-2*i][i]=pali(n-2*i, i);
//            S[n][m]+=S[n-2*i][i];
//        }
//        else if(n==i) S[n][m]+=S[0][i];
//    }
//    return S[n][m];
//}
//
//int main()
//{
//    while(scanf(" %d",&N))
//    {
//    if (N==0) break;
//    memset(S, 0, sizeof(S));
//    for (int i=0; i<250; i++) S[0][i]=1;
//    printf("%d %u\n",N,pali(N, 1));
//    //printf("%u\n",N);
//    }
//}


/*Bessie has gone to the mall's jewelry store and spies a charm bracelet. Of course, she'd like to fill it with the best charms possible from the N(1 ≤ N≤ 3,402) available charms. Each charm iin the supplied list has a weight Wi(1 ≤ Wi≤ 400), a 'desirability' factor Di(1 ≤ Di≤ 100), and can be used at most once. Bessie can only support a charm bracelet whose weight is no more than M(1 ≤ M≤ 12,880).*/
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define Num 3403
#define MAXI 12881
int weigh[Num];
int desi[Num];
int S[MAXI];
//int S[Num][MAXI];
//struct goods{
//    int weight;
//    int desir;
//    goods(int wei=0,int desi=0):weight(wei),desir(desi){}
//    bool operator<(const goods& good2) const {
//        if(good2.desir!=desir)
//        return desir>good2.desir;
//        else
//        return weight<good2.weight  ;
//    }
//} good[Num];
using namespace std;
void jewry(int N, int W)
{
    for (int i=1; i<=N; i++)
        for (int j=W; j>=0; j--) {
            if(j>=weigh[i-1])
            S[j]=max(S[j],S[j-weigh[i-1]]+desi[i-1]);
    }
//    for (int i=1; i<=N;i++)
//        for (int j=1; j<=W; j++) {
//            if (weigh[i-1]<=j)
//                S[i][j]=max(S[i-1][j], S[i-1][j-weigh[i-1]]+desi[i-1]);
//            else S[i][j]=S[i-1][j];
//        }
}

int main()
{
    int N,W;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(S, 0, sizeof(int)*MAXI);
    scanf("%d %d",&N,&W);
    for (int i=0; i<N; i++)
    scanf("%d %d",&weigh[i],&desi[i]);
//    scanf("%d %d",&good[i].weight,&good[i].desir);
//    sort(good, good+N);
//    for (int i=0; i<N; i++)
//        printf("%d %d\n", good[i].weight,good[i].desir);
    //printf("%d\n",jewry(N,W));
  // /printf("%d\n",S[N][W]);
    jewry(N, W);
    //printf("%d\n",S[N][W]);
    printf("%d\n",S[W]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
