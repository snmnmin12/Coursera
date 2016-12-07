////
////  kmp.cpp
////  Structure
////
////  Created by Song on 1/10/16.
////  Copyright © 2016 Song. All rights reserved.
////
//
#include <stdio.h>
//#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int nex[1000100];
char str[1000100];
////注意返回结果是一个数组next，保存m个k值得地方，即若next[j]=k
////则str[0]str[1]…str[k] = str[j-k]str[j-k+1]…str[j]
////这样当des[t+j+1]和pat[j+1]匹配失败时，下一个匹配位置为des[t+j+1]和next[j]+1
//void get_next()
//{
//    int i=1;
//    int j=0;
//    next[0]=-1;
//    size_t n=strlen(str);
//    while (i<n)
//    {
//        if (j==-1 || str[i]==str[j])
//        {
//            i++;j++;next[i]=j;
//        }
//        else
//        j=next[j];
//    }
//}
//
void findNext()
{
    int j, k;
    int m = strlen(str); // m为模式P的长度
    nex[0] = -1;
    j = 0; k = -1;
    while (j <= m-1) {
        while (k >= 0 && str[k] != str[j])// 不等则采用 KMP 自找首尾子串
            k = nex[k]; // k 递归地向前找
        j++; k++; nex[j] = k;
        if(str[k]==str[j])
            nex[j]=nex[k];
        else nex[j]=k;
    }
for(int i=0;i<m;i++)
    printf("%d ",nex[i]);
    printf("\n");
//cout<<next[i]<<" ";
    
}
//    //return next;
//}
int KMPStrMatching(char* T, char* P, int *N, int start) {
    int j= 0; // 模式的下标变量
    int i = start; // 目标的下标变量
    int pLen = strlen(P); // 模式的长度
    int tLen = strlen(T); // 目标的长度
    int k=0;
    if (tLen - start < pLen) // 若目标比模式短，匹配无法成功
        return (-1);
    while ( j < pLen && i < tLen)
    { // 反复比较，进行匹配
        if ( j == -1 || T[i] == P[j])
            i++, j++;
        else j = N[j];
        k++;
    }
    printf("%d\n",k);
    if (j >= pLen)
    return (i-pLen); // 注意仔细算下标
    return -1;
}
//int main()
//{
//    scanf("%s",str);
//    findNext();
//    char target[500];
//    scanf("%s",target);
//    KMPStrMatching(target, str, nex, 0);
//    int p=0;
//    printf("%d",p);
//}
//    int n;
//    int count=1;
//    freopen("in4.txt", "r", stdin);
//    freopen("out4.txt", "w", stdout);
//    while (scanf("%d",&n),n)
//    {
//        scanf("%s",str);
//        //get_next();
//        findNext();
//        printf("Test case #%d\n",count++);
//        for (int i=1; i<=n; i++)
//        {
//            int temp=i-next[i];
//            if (i%temp==0 && i/temp>1) {
//                printf("%d %d",i,i/temp);
//                printf("\n");
//            }
//        }
//        printf("\n");
//    }
//    fclose(stdin);
//    fclose(stdout);
//    return 0;
//}