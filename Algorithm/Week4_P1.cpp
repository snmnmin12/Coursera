////
////  Week4_P1.cpp
////  Algorithm
////
////  Created by Song on 12/12/15.
////  Copyright © 2015 Song. All rights reserved.
////
//
//#include <stdio.h>
//
//int A[10000];
//int B[10000];
//int main()
//{
//    int num;
//    scanf("%d",&num);
//    while (num--)
//    {
//        int count=0;
//        int s;
//        scanf(" %d",&s);
//        
//        int a;
//        scanf(" %d",&a);
//        for (int i=0; i<a; i++)
//            scanf(" %d", &A[i]);
//        
//        int b;
//        scanf(" %d",&b);
//        for (int i=0; i<b; i++)
//            scanf(" %d", &B[i]);
//        
//        for (int i=0; i<a;i++)
//            for (int j=0; j<b; j++)
//                if (A[i]+B[j]==s) ++count;
//        printf("%d\n",count);
//    }
//
//    return 0;
//}