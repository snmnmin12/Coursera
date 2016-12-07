////
////  week4.cpp
////  Structure
////
////  Created by Song on 1/9/16.
////  Copyright © 2016 Song. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <map>
//#include <cstring>
//using namespace std;
//bool success=1;
//typedef pair<string, int> pstr;
//map<string, int> map1;
//void initia()
//{
//
//    string str[32]={"negative", "zero", "one", "two", "three", "four","five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen","fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty","sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "million"};
//    int number[31]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90,100,1000,1000000};
//    
//    map1.insert(pstr(str[0],-1));
//    for (int i=1; i<32; i++)
//    map1.insert(pstr(str[i],number[i-1]));
//}
//
//void stringparse(string &s){
// 
//    size_t i=s.length()-1;
//    size_t end=s.length();
//    bool negative=false;
//    int currentUnit=1;
//    int nextUnit=1;
//    map<string, int>::iterator it;
//    string temp;
//    int temp2=0;
//    int num=0;
//    while (1)
//    {
// 
//        if (i==-1)
//        {
//            if (negative) cout<<-num<<endl;
//            else cout<<num<<endl;
//            break;
//        }
//
//        if ( s[i]==' '|| i==0)
//        {
//            if (i!=0)
//            temp=s.substr(i+1,end-i-1);
//            else
//                temp=s.substr(i,end-i);
//            if (temp=="negative") negative=true;
//            else
//            {
//                it=map1.find(temp);
//                if (temp=="hundred"||temp=="thousand"|| temp=="million")
//                {
//                    nextUnit=it->second;
//                    if (currentUnit<it->second){
//                    currentUnit=it->second;
//                        nextUnit=1;
//                    }
//                }
//                else
//                {
//                    temp2=it->second*nextUnit;
//                    num+=temp2*currentUnit;
//                }
//            }
//            
//            end=i;
//        }
//        i--;
//    }
//    
//}
//
//int main(){
//    initia();
//    string input;
//   // freopen("in_numbers.txt", "r", stdin);
//    while(getline(cin, input),!input.empty())
//    stringparse(input);
//    //fclose(stdin);
//    return 0;
//}
////#include <gtest/gtest.h>
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//enum TOKEN_TYPE
//{
//    TYPE_NUMBER,
//    TYPE_UNIT,
//    TYPE_NEGATIVE
//};
//
//struct Token
//{
//    string        StringValue;
//    int            Value;
//    TOKEN_TYPE    Type;
//};
//
//Token sTokenTable[] =
//{
//    {"zero",        0, TYPE_NUMBER},
//    {"one",            1, TYPE_NUMBER},
//    {"two",            2, TYPE_NUMBER},
//    {"three",        3, TYPE_NUMBER},
//    {"four",        4, TYPE_NUMBER},
//    {"five",        5, TYPE_NUMBER},
//    {"six",            6, TYPE_NUMBER},
//    {"seven",        7, TYPE_NUMBER},
//    {"eight",        8, TYPE_NUMBER},
//    {"nine",        9, TYPE_NUMBER},
//    {"ten",            10, TYPE_NUMBER},
//    {"eleven",        11, TYPE_NUMBER},
//    {"twelve",        12, TYPE_NUMBER},
//    {"thirteen",    13, TYPE_NUMBER},
//    {"fourteen",    14, TYPE_NUMBER},
//    {"fifteen",        15, TYPE_NUMBER},
//    {"sixteen",        16, TYPE_NUMBER},
//    {"seventeen",    17, TYPE_NUMBER},
//    {"eighteen",    18, TYPE_NUMBER},
//    {"nineteen",    19, TYPE_NUMBER},
//    {"twenty",        20, TYPE_NUMBER},
//    {"thirty",        30, TYPE_NUMBER},
//    {"forty",        40, TYPE_NUMBER},
//    {"fifty",        50, TYPE_NUMBER},
//    {"sixty",        60, TYPE_NUMBER},
//    {"seventy",        70, TYPE_NUMBER},
//    {"eighty",        80, TYPE_NUMBER},
//    {"ninety",        90, TYPE_NUMBER},
//    {"hundred",        100, TYPE_UNIT},
//    {"thousand",    1000, TYPE_UNIT},
//    {"million",        1000000, TYPE_UNIT},
//    {"negative",    -1, TYPE_NEGATIVE}
//};
//
//bool GetPreToken(const string& value, int& pos, Token& nextToken)
//{
//    bool bRetValue = false;
//    pos = value.find_last_not_of(" ", pos);
//    if (pos == string::npos)
//    {
//        return false;
//    }
//    
//    string tokenStr;
//    string::size_type next = value.rfind(" ", pos);
//    if (next != string::npos)
//    {
//        tokenStr = value.substr(next+1, pos-next);
//    }
//    else
//    {
//        tokenStr = value.substr(0, pos+1);
//    }
//    
//    for (int i=0; i<sizeof(sTokenTable)/sizeof(sTokenTable[0]); ++i)
//    {
//        if (tokenStr.compare(sTokenTable[i].StringValue)==0)
//        {
//            nextToken.Type = sTokenTable[i].Type;
//            nextToken.Value = sTokenTable[i].Value;
//            
//            bRetValue = true;
//            pos = next;
//            break;
//        }
//    }
//    
//    return bRetValue;
//}
//
//long Parse(const string& value)
//{
//    long lResult = 0;
//    int nNegatvie = 1;
//    int nPos = string::npos;
//    Token NextToken;
//    int CurrentUnitValue = 1;
//    
//    while (GetPreToken(value, nPos, NextToken))
//    {
//        switch (NextToken.Type)
//        {
//            case TYPE_NEGATIVE:
//                nNegatvie = -1;
//                break;
//                
//            case TYPE_NUMBER:
//                lResult += NextToken.Value * CurrentUnitValue;
//                break;
//                
//            case TYPE_UNIT:
//                
//                if (NextToken.Value >= CurrentUnitValue)
//                {
//                    CurrentUnitValue = NextToken.Value;
//                }
//                else
//                {
//                    CurrentUnitValue *= NextToken.Value;
//                }
//                break;
//        }
//        
//        if (nPos == string::npos)
//        {
//            break;
//        }
//    }
//    
//    lResult *= nNegatvie;
//    
//    return lResult;
//}
//
//int main()
//{
//    char input[512];
//    cin.getline(input,512);
//    string value(input);
//    while (!value.empty())
//    {
//        cout << Parse(value) << endl;
//        cin.getline(input, 512);
//        value = input;        
//    }
//    
//    return 0;
//}
