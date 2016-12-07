//////
//////  week4_2.cpp
//////  Structure
//////
//////  Created by Song on 1/9/16.
//////  Copyright © 2016 Song. All rights reserved.
//////
////
//#include <stdio.h>
//#include <cstring>
//#include <algorithm>
//#include <iostream>
//#include <cmath>
//#include <vector>
//using namespace std;
//vector<string> dic;
//void strkmp(string &str1, string & str2)
//{
//    int cou;
//    int len1=str1.length();
//    int len2=str2.length();
//    if(abs(len1-len2)>1) return;
//    int index=0;
//    if (len1<len2)
//    {
//        cou=0;
//        int pos=0;
//        for (int i=0; i<len1; i++)
//        {
//        index=str2.find(str1[i],pos);
//        if (index==str2.npos)
//            cou++;
//        else  pos=index+1;
//        if (cou>0) return;
//        }
//        cout<<" "<<str2;
//    }
//    else if(len1==len2){
//        
//        cou=0;
//        for (int i=0; i<len1; i++)
//        if(str1[i]!=str2[i]) cou++;
//        if (cou>1) return;
//        cout<<" "<<str2;
//    }
//    else
//    {
//        cou=0;
//        int pos=0;
//        for (int i=0; i<len2; i++)
//        {
//          index=str1.find(str2[i],pos);
//            if (index==str1.npos)
//                cou++;
//            else pos=index+1;
//            if (cou>0) return;
//            
//        }
//        cout<<" "<<str2;
//        
//    }
//    
//}
//void strparse(string & str)
//{
//    vector<string>::iterator it=find(dic.begin(), dic.end(), str);
//    if (it!=dic.end())
//    cout<<*it<<" is correct"<<endl;
//    else
//    {
//        cout<<str<<":";
//        for (int i=0; i<dic.size(); i++)
//        strkmp(str, dic[i]);
//        cout<<endl;
//    }
//}
//int main()
//{
//    string str;
//    freopen("in_2.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    while (getline(cin,str),str!="#")
//    dic.push_back(str);
//    
//    while (getline(cin,str),str!="#")
//        strparse(str);
//    fclose(stdin);
//    fclose(stdout);
//    return 0;
//}