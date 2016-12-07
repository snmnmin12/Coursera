//
//  expressiontree.cpp
//  Structure
//
//  Created by Song on 1/13/16.
//  Copyright © 2016 Song. All rights reserved.
//

#include <stdio.h>
#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;
class ExpNode{
public:
    bool isLeaf(){return (left==0&&right==0);}
    ExpNode(const string& str, ExpNode*le=NULL,ExpNode*ri=NULL) {st=str;left=le;right=ri;}
    string st;
    ExpNode*left, *right;

};
class Tree{
public:
    Tree(){root=0;}
    int  findrightparen(string& str, int leftPos);
    void parseExpression(string & str){root=parse(str);}
    int getValue(string&,int);
private:
    ExpNode* root;
    ExpNode* parse(string &str);
};

ExpNode* Tree::parse(string & str)
{
    ExpNode* currentNode=NULL, *treeroot=NULL;
    int i=0;
    while (i<str.length())
    {
        if(isalnum(str[i]))
        {
        
            int k=i;
            for (; i<str.length() && isalnum(str[i]);++i);
            ExpNode *p=new ExpNode(str.substr(k,i-k));
            if (currentNode==NULL)
            treeroot=currentNode=p;
            else
            currentNode->right=p;
        }
        else if(str[i]=='+'||str[i]=='-')
        {
            ExpNode*p=new ExpNode(str.substr(i,1));
            p->left=treeroot;
            treeroot=p;
            currentNode=p;
            i++;
        }
        else if(str[i]=='*'||str[i]=='/')
        {
            ExpNode*p=new ExpNode(str.substr(i,1));
            
            if (currentNode->right==NULL || str[i-1]==')')
            {
                p->left=treeroot;
                treeroot=currentNode=p;
            }
            else
            {
                p->left=currentNode->right;
                currentNode->right=p;
                currentNode=p;
            }
            i++;
        }
        else if(str[i]=='(')
        {
            int m=findrightparen(str,i);
            string sub=str.substr(i+1,m-i-1);
            if (currentNode==0) currentNode=treeroot=parse(sub);
            else currentNode->right=parse(sub);
            i=m+1;
        }
        
    }
    return treeroot;
}
int Tree::getValue(string& str, int i)
{
    int k=str[i]-'0';
    for (int j=i+1; j<str.length() && isdigit(str[j]);j++)
    k=10*k+str[j]-'0';
    return k;
}
int Tree::findrightparen(string&str, int lefpos)
{
    stack<char> sta;
    for (int i=lefpos; i<str.length(); i++)
    {
        if (str[i]=='(')
            sta.push(str[i]);
        else if(str[i]==')')
        {
            sta.pop();
            if(sta.empty()) return i;
        }
    }
    return -1;
}
