////
////  week4_3.cpp
////  Structure
////
////  Created by Song on 1/10/16.
////  Copyright © 2016 Song. All rights reserved.
////
//
////#include <stdio.h>
////#include <iostream>
////#include <cstring>
////using namespace std;
////string S;
////int repcount(string & str)
////{
////   
////    size_t len=str.length();
////    int j=0;
////    int k;
////    for (int i=1; i<len/2+1; i++)
////    {
////        if (len%i!=0) continue;
////        k=1;
////        string temp=str.substr(0,i);
////        j=i;
////        while (j<len) {
////            if(temp!=str.substr(j,i))
////                break;
////            j+=i;
////            k++;
////        }
////       if (j==len) return k;
////    }
////   
////    return -1;
////
////}
////void stringparse(string & str)
////{
////    int count=0;
////    int k;
////    size_t len=str.length();
////    string str1;
////    for (int i=2; i<=len; i++)
////    {
////        str1=str.substr(0,i);
////        count=repcount(str1);
////        if (count!=-1)
////            cout<<i<<" "<<count<<endl;
////    }
////}
////int main()
////{
////    
////    int n;
////    freopen("in4.txt", "r", stdin);
////    freopen("out4.txt", "w", stdout);
////    while (cin>>n,n)
////    {
////        cin.get();
////        cout<<"Test case #"<<n<<endl;
////        getline(cin,S);
////        stringparse(S);
////        cout<<endl;
////    }
////    
////    fclose(stdin);
////    fclose(stdout);
////    return 0;
////}
//
//#include<stdio.h>
//#include<string.h>
//char str[1000100];
//int n,len,next[10001000];
//void get_next()
//{
//    int i=1,j=0;
//    next[0]=-1;
//    while(i<n)
//    {
//        if(j==-1||str[i]==str[j])
//        {
//            i++;j++;next[i]=j;
//        }
//        else
//            j=next[j];
//    }
//}
//int main()
//{
//    int i,count=1;
//        freopen("in4.txt", "r", stdin);
//        freopen("out4.txt", "w", stdout);
//    while(~scanf("%d",&n),n)
//    {
//        scanf("%s",str);
//        get_next();
//        printf("Test case #%d\n",count++);
//        for(i=1;i<=n;i++)
//        {
//            int temp=i-next[i];
//            if(i%temp==0&&i/temp>1)
//            {
//                printf("%d %d",i,i/temp);
//                printf("\n");
//            }
//        }
//        printf("\n");
//    }
//        fclose(stdin);
//        fclose(stdout);
//    return 0;
//}
//
//
