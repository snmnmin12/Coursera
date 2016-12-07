//
//  ExprTreeNode.cpp
//  Structure
//
//  Created by Song on 1/12/16.
//  Copyright © 2016 Song. All rights reserved.
//

#ifndef EXP_TREE_NODE
#define EXP_TREE_NODE
#include <iostream>
#include <cctype>
#include <string>
using namespace std;
class ExprTreeNode{
public:
ExprTreeNode(char* k, ExprTreeNode*l=0, ExprTreeNode*r=0)
{
    key=new char[strlen(k)+1];
    strcpy(key, k);
    left=l;
    right=r;
}
private:
    char* key;
    ExprTreeNode* left, *right;
    friend class ExprTree;
};
class ExprTree
{
public:
    ExprTree(){}
    void getStatement();
    void generateCode(){generateCode(root);}
    void inorder(){inorder(root); cout<<endl;}
private:
    ExprTreeNode* root;
    char token;
    char id[200];
    ExprTreeNode* factor();
    ExprTreeNode* term();
    ExprTreeNode* expression();
    void readId(char*);
    void issueError(char*s){cerr<<s<<endl;exit(1);}
    //double findValue(char*);
    //void processNode(char*,double);
    char* generateCode(ExprTreeNode* p);
    char* newTemporaryVar();
    void inorder(ExprTreeNode* p);
    void visit(ExprTreeNode*p){cout<<p->key<<" ";}
};
char*  ExprTree::generateCode(ExprTreeNode *p)
{
    if (isalnum(*p->key))
        return p->key;
    else if(*p->key =='+')
    {
        char* result = newTemporaryVar();
        char* lef=generateCode(p->left);
        char* rig=generateCode(p->right);
        cout<<"add\t"<<lef<<"\t" <<rig<<"\t"
        << result<<endl;
        return result;
    }
    else if(*p->key =='-')
    {
        char* result = newTemporaryVar();
        char* lef=generateCode(p->left);
        char* rig=generateCode(p->right);
        cout<<"minus\t"<<lef<<"\t" <<rig<<"\t"
        << result<<endl;
        return result;
    }
    else if(*p->key =='*')
    {
        char* result = newTemporaryVar();
        char* lef=generateCode(p->left);
        char* rig=generateCode(p->right);
        cout<<"mul\t"<<lef<<"\t" <<rig<<"\t"
        << result<<endl;
        return result;
    }
    else if(*p->key =='/')
    {
        char* result = newTemporaryVar();
        char* lef=generateCode(p->left);
        char* rig=generateCode(p->right);
        cout<<"div\t"<<lef<<"\t" <<rig<<"\t"
          << result<<endl;
        return result;
    }
    return 0;
}

ExprTreeNode* ExprTree::factor()
{
    cin>>token;
    if (isalpha(token))
    {
        readId(id);
       // cin>>token;
        return  new ExprTreeNode(id);
    }
    else if(isdigit(token)||token=='+'||token=='-'||token=='*'||token=='/')
    {
        id[0]=token;
        id[1]='\0';
        cin>>token;
        return  new ExprTreeNode(id);
    }
    else if(token=='(')
    {
        ExprTreeNode *p=expression();
        if(token==')'){cin>>token;return p;}
        else
        issueError("Right paren left out'");
    }
    
    return 0;
}
ExprTreeNode* ExprTree::term()
{
    ExprTreeNode *p1, *p2;
    p1=factor();
    while (token=='*' || token=='/')
    {
        char temp[2];
        temp[0]=token;
        temp[1]='\0';
        p2=factor();
        p1=new ExprTreeNode(temp,p1,p2);
    }
    return p1;
}
ExprTreeNode* ExprTree::expression()
{
    ExprTreeNode *p1,*p2;
    p1=term();
    while (token=='+'|| token=='-')
    {
        char temp[2];
        temp[0]=token;
        temp[1]='\0';
        //cin>>token;
        p2=term();
        
        p1=new ExprTreeNode(temp,p1,p2);
    }
    return p1;
}
void ExprTree::getStatement()
{

    cin>>token;
    while (isspace(token)) cin>>token;
    cin.putback(token);
    root=expression();
    if (token!=';') cout<<"error"<<endl;
}
void ExprTree::readId(char*id)
{
    int i=0;
    if (isspace(token))
        cin>>token;
    if (isalpha(token))
    {
        while (isalnum(token))
        {
            id[i++]=token;
            cin.get(token);
        }
        id[i]='\0';
    }
    else issueError("Identifier expected");
}
char* ExprTree::newTemporaryVar()
{
    static int i=0;
    char* Var=new char[7];
    strcpy(Var, "_tmp_x");
    i++;
    Var[5]=i+'0';
    return Var;
}
void ExprTree::inorder(ExprTreeNode* p)
{
    if(p!=NULL)
    {
    inorder(p->left);
        visit(p);
    inorder(p->right);
    }
}
#endif