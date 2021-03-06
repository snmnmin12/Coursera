//
//  week6_3.cpp
//  Structure
//
//  Created by Song on 1/13/16.
//  Copyright © 2016 Song. All rights reserved.
//

#include <iostream>
#include <cctype>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
map<char, int > map1;
class ETNode{
public:
    ETNode(char k, ETNode*l=0, ETNode*r=0)
    {
        key=k;
        left=l;
        right=r;
    }
private:
    char  key;
    ETNode* left, *right;
    friend class ET;
};
class ET
{
public:
    ET(){}
    ~ET(){}
    void Create(string& str);
    void calculate(){cout<<generateCode(root)<<endl;;}
    void inorder(){inorder(root); cout<<endl;}
    void postorder(){postorder(root);cout<<endl;}
    void show(){int d=depth();int m=(1<<(d-1)); show(root,m,d);}
    int depth(){ return depth(root);}
private:
    ETNode* root;
    char* token;
    ETNode* factor();
    ETNode* term();
    ETNode* expression();
    int depth(ETNode* p);
    void show(ETNode*p,int m,int d);
    int generateCode(ETNode* p);
    void inorder(ETNode* p);
    void postorder(ETNode*p);
    void visit(ETNode*p){cout<<p->key;}
};
int  ET::generateCode(ETNode *p)
{
    if (isalpha(p->key))
        return map1[p->key];
    else if(p->key=='+')
        return generateCode(p->left)+generateCode(p->right);
    else if(p->key=='-')
        return generateCode(p->left)-generateCode(p->right);
    else if(p->key=='*')
        return generateCode(p->left)*generateCode(p->right);
    else if(p->key=='/')
        return generateCode(p->left)/generateCode(p->right);
       return 0;
}

ETNode* ET::factor()
{
    char temp;
    token++;
    if (isalpha(*token))
    {
        temp=*token;
        token++;
        return  new ETNode(temp);
    }
    else if(*token=='+'||*token=='-'||*token=='*'||*token=='/')
    {
        temp=*token;
        token++;
        return  new ETNode(temp);
    }
    else if(*token=='(')
    {
        ETNode *p=expression();
        if(*token==')')
        {
        token++;
        return p;
        }
    }
    
    return 0;
}
ETNode* ET::term()
{
    ETNode *p1, *p2;
    p1=factor();
    while (*token=='*' || *token=='/')
    {
        char temp=*token;
        p2=factor();
        p1=new ETNode(temp,p1,p2);
    }
    return p1;
}
ETNode* ET::expression()
{
    ETNode *p1,*p2;
    p1=term();
    while (*token=='+'|| *token=='-')
    {
        char temp;
        temp=*token;
        p2=term();
        p1=new ETNode(temp,p1,p2);
    }
    return p1;
}
void ET::Create(string& str)
{
    token=&str[0];
    token--;
    root=expression();
}

void ET::inorder(ETNode* p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}
void ET::postorder(ETNode*p)
{
    if (p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }

}
int ET::depth(ETNode *p)
{
    if(p==0) return 0;
    else return max(depth(p->left),depth(p->right))+1;
}
void ET::show(ETNode*p,int m,int d)
{
    queue<pair<ETNode*,int> > q;
    queue<pair<ETNode*,int> > q2;
    q.push(make_pair(p, m));
    while (!q.empty())
    {
        int num=q.size();
        int j=1;
        pair<ETNode*,int> temp;
        for (int i=0; i<num; i++)
        {
            temp=q.front();
            int number=temp.second;
            for (; j<number; j++) cout<<" ";
            cout<<temp.first->key;
                j++;
            q2.push(temp);
            q.pop();
        }
        cout<<endl;
        j=1;
        for (int i=0; i<num; i++)
        {
            temp=q2.front();
            q2.pop();
            int number=temp.second;
            if (temp.first->left==0 && temp.first->right==0) continue;
            for (; j<number-1; j++) cout<<" ";
            if(temp.first->left!=0) cout<<"/";
            else cout<<" ";
            for (j=j+1;j<number+1; j++)
             cout<<" ";
            if(temp.first->right!=0) cout<<"\\";
            else cout<<" ";
            j++;
            int shift=1<<(d-2);
            shift=shift>0?shift:0;
            if (temp.first->left!=0) q.push(make_pair(temp.first->left,number-shift));
            if (temp.first->right!=0) q.push(make_pair(temp.first->right,number+shift));
        }
        if(d>1) cout<<endl;
        d--;
    }

}
//int main()
//{
//    
//    string str;
//    getline(cin, str);
//    int num;
//    cin>>num;
//    char c;
//    int value;
//    while (num--)
//    {
//        cin>>c>>value;
//        map1.insert(make_pair(c, value));
//    }
//    ET exp;
//    exp.Create(str);
//    exp.postorder();
//    exp.show();
//    exp.calculate();
//    return 0;
//}
