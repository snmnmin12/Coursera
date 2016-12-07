////
////  quicksort.cpp
////  Algorithm
////
////  Created by Song on 1/4/16.
////  Copyright © 2016 Song. All rights reserved.
////
//
//#include <stdio.h>
//
//void swap(int & a, int &b)
//{
//    int temp=a;
//    a=b;
//    b=temp;
//}
//int partition(int* A, int p, int r){
//    
//    int x=A[r];
//    int i=p-1;
//    for (int j=p; j<r; j++)
//    {
//        if (A[j]<=x) {
//            i=i+1;
//            swap(A[i], A[j]);
//        }
//    }
//    swap(A[i+1], A[r]);
//    return i+1;
//}
//void quicksort(int* A, int p, int r){
//    if (p<r) {
//        int q=partition(A,p,r);
//        quicksort(A, p, q-1);
//        quicksort(A, q+1, r);
//    }
//}
//int main(){
//    
//    int A[]={13,19,9,5,12,8,7,4,21,2,6,11};
//    int p=0;
//    int r=11;
//    for (int i=p; i<=r; i++)
//        printf("%d ",A[i]);
//    printf("\n");
//    quicksort(A, 0, 11);
//    for (int i=p; i<=r; i++)
//        printf("%d ",A[i]);
//    printf("\n");
//    return 0;
//}

#include <iostream>
#include <cassert>
#include <stdio.h>
#include <cstring>
using namespace std;

int FindPat_2(string T, string P, int startindex) {
    
    // 从T末尾倒数一个模板长度位置
    int len1=T.length();
    int len2=P.length();
    int LastIndex = T.length() - P.length();
    // 开始匹配位置startindex的值过大，匹配无法成功
    if (LastIndex < startindex) return (-1);
    // i 是指向T内部字符的游标，j 是指向P内部字符的游标
    int i = startindex, j = 0;
    while (i < T.length() && j < P.length()) // “<=”呢？
        if (P[j] == T[i])
        { i++; j++; }
        else
        { i = i - j + 1; j = 0; }
    if ( j >= P.length()) // “>” 可以吗？
        return (i - j); // 若匹配成功，则返回该T子串的开始位置
    else return -1; // 若失败，函数返回值为负
}

int KMPStrMatching(string T, string P, int *N, int start) {
    int j= 0; // 模式的下标变量
    int i = start; // 目标的下标变量
    int pLen = P.length( ); // 模式的长度
    int tLen = T.length( ); // 目标的长度
    if (tLen - start < pLen) // 若目标比模式短，匹配无法成功
        return (-1);
    while ( j < pLen && i < tLen) { // 反复比较，进行匹配
        if ( j == -1 || T[i] == P[j])
            i++, j++;
        else j = N[j];
    }
    if (j >= pLen)
        return (i-pLen); // 注意仔细算下标
    else return (-1);
}



int* findNext(string P) {
    int j, k;
    int m = P.length( ); // m为模式P的长度
    assert( m > 0); // 若m＝0，退出
    int *next = new int[m]; // 动态存储区开辟整数数组
    assert( next != 0); // 若开辟存储区域失败，退出
    next[0] = -1;
    j = 0; k = -1;
    while (j < m-1) {
        while (k >= 0 && P[k] != P[j])// 不等则采用 KMP 自找首尾子串
            k = next[k]; // k 递归地向前找
        j++; k++; next[j] = k;
    }
    return next;
}
int main()
{
//    string s1="aaaaaaaaaaaaaab";
//    string s2="aaaab";
    
    string t="aabcbabcaabcaababc";
    string s3="abcaababc";
//    int* N=findNext(s3);
//    int index=KMPStrMatching(t, s3, N, 0);
    
    string A="";
    string B="MULE";
    string C="OLD";
    string D="MY";
    cout<<D+C+B<<endl;
    cout<<B.substr(3,2)<<" "<<A.length()<<endl;
    
//    int index=FindPat_2(s1, s2, 0);
//    printf("%d\n",index);
    return 0;
}



