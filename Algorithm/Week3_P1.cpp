////
////  Week3_P1.cpp
////  Algorithm
////
////  Created by Song on 12/6/15.
////  Copyright © 2015 Song. All rights reserved.
////
//
//#include <stdio.h>
//int verti(int n);
//int hori(int n)
//{
//    if (n==1) return 1;
//    else if(n==0) return 0;
//    else return verti(n-1)+hori(n-2);
//
//}
//int verti(int n)
//{
//    if (n==1) return 0;
//    else if(n==0) return 1;
//    else return 2*hori(n-1)+verti(n-2);
//}
//int count(int n)
//{
//    if (n%2==1) return 0;
//    else return hori(n)+verti(n);
//}
//
//int main()
//{
//  
//    int n;
//   
//   
//    freopen("in.txt", "r", stdin);
//     scanf("%d",&n);
//    
//    while (n!=-1) {
//    printf("%d\n", count(n));
//        scanf("%d",&n);
//    }
//    fclose(stdin);
//    return 0;
//}