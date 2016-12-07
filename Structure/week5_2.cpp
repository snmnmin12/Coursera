//
//  week5_2.cpp
//  Structure
//
//  Created by Song on 1/10/16.
//  Copyright © 2016 Song. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
int a[100000];
//void swap(int &a, int&b)
//{
//    int temp=a;
//    a=b;
//    b=temp;
//}
//void Heapify(int i, int& n)
//{
//    int j,temp;
//    temp=a[i];
//    j=2*i+1;
//    while (j<n)
//    {
//        if (j+1<n&& a[j+1]<a[j])
//            j++;
//        if(a[j]>=temp)
//            break;
//        swap(a[i],a[j]);
//        i=j;
//        j=2*i+1;
//    }
//    //a[i]=temp;
//}
//int Heap_Delete(int& n)
//{
//    if (n<1) cerr<<"heap underflow";
//    int min=a[0];
//    a[0]=a[n-1];
//    n--;
//    Heapify(0, n);
//    return min;
//}
//void Heap_Insert(int& n, int key)
//{
//    n++;
//    a[n-1]=key;
//    int i=n-1;
//    while (i>0)
//    {
//        int parent=(i-1)/2;
//        //if (parent<1) break;
//        if (a[i]>=a[parent]) break;
//        swap(a[i], a[parent]);
//        i=parent;
//    }
//
//}
//int main()
//{
//    int t;
//    freopen("heap.txt", "r", stdin);
//    freopen("heapre.txt", "w", stdout);
//    scanf("%d",&t);
//    while (t--) {
//        memset(a,0, sizeof(a));
//        int n;
//        scanf("%d",&n);
//        int type;
//        int value;
//        int length=0;
//        for (int i=0; i<n; i++)
//        {
//            scanf("%d",&type);
//            if (type==1)
//            {
//                cin>>value;
//                Heap_Insert(length, value);
//            }
//            else if(type==2)
//                printf("%d\n",Heap_Delete(length));
//        }
//    }
//    fclose(stdin);
//    fclose(stdout);
//
//    return 0;
//}