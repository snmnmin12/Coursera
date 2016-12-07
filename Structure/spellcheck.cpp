////
////  spellcheck.cpp
////  Structure
////
////  Created by Song on 1/10/16.
////  Copyright © 2016 Song. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <set>
//#include <string.h>
//#include <map>
//using namespace std;
//char word[10005][20], s[20];
//int wlen[10005];
//set<string> S[20];
//map<string, int> M;
//int main() {
//    int n = 0;
//    int i, j, k;
//    while(scanf("%s", &word[n]) == 1) {
//        if(!strcmp(word[n], "#"))
//            break;
//        wlen[n] = strlen(word[n]);
//        S[wlen[n]].insert(word[n]);
//        M[word[n]] = n;
//        n++;
//    }
//    while(scanf("%s", s) == 1) {
//        if(!strcmp(s, "#"))
//            break;
//        int len = strlen(s);
//        if(S[len].find(s) != S[len].end()) {
//            printf("%s is correct\n", s);
//            continue;
//        }
//        printf("%s:", s);
//        char err[20];
//        for(i = 1; i < len; i++)
//            err[i-1] = s[i];
//        err[len-1] = '\0';
//        set<string> ret;
//        for(i = 0; i < len; i++) {
//            if(S[len-1].find(err) != S[len-1].end())
//                ret.insert(err);
//            err[i] = s[i];
//        }
//        for(i = 0; i < len; i++)
//            err[i] = s[i];
//        err[len] = '\0';
//        for(i = 0; i < len; i++) {
//            for(j = 'a'; j <= 'z'; j++) {
//                if(j == s[i])    continue;
//                err[i] = j;
//                if(S[len].find(err) != S[len].end())
//                    ret.insert(err);
//            }
//            err[i] = s[i];
//        }
//        for(i = 0; i < len; i++)
//            err[i+1] = s[i];
//        err[len+1] = '\0';
//        for(i = 0; i <= len; i++) {
//            for(j = 'a'; j <= 'z'; j++) {
//                err[i] = j;
//                if(S[len+1].find(err) != S[len+1].end())
//                    ret.insert(err);
//            }
//            err[i] = s[i];
//        }
//        set<int> R;
//        for(set<string>::iterator it = ret.begin();
//            it != ret.end(); it++) {
//            R.insert(M[*it]);
//        }
//        for(set<int>::iterator it = R.begin();
//            it != R.end(); it++)
//            printf(" %s", word[*it]);
//        puts("");
//    }
//    return 0;
//}