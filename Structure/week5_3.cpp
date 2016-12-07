////
////  week5_3.cpp
////  Structure
////
////  Created by Song on 1/11/16.
////  Copyright © 2016 Song. All rights reserved.
////
//
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#define defaultsize 20
template<class T>
class BiTreeNode
{
public:
    BiTreeNode(){left=right=0;}
    BiTreeNode(const T& t,BiTreeNode*l=0,BiTreeNode*r=0){data=t;left=l;right=r;}
    T data;
    //int level;
    BiTreeNode<T>* left;
    BiTreeNode<T>* right;
};
template<class T>
class BiTree{
public:
    BiTree(){root=0;}
    void SetRoot(BiTreeNode<T>* node){root=node;}
    void previst(){previst(root);cout<<endl;}
    void midorder(){midorder(root);cout<<endl;}
    void backorder(){backorder(root);cout<<endl;}
    void clear(){clear(root);}
private:
    BiTreeNode<T>* root;
    void clear(BiTreeNode<T>* node);
    void previst(BiTreeNode<T>* node);
    void midorder(BiTreeNode<T>* node);
    void backorder(BiTreeNode<T>* node);
};
template<class T>
void BiTree<T>::clear(BiTreeNode<T>* node)
{
    while (node!=NULL)
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}
template<class T>
void BiTree<T>::previst(BiTreeNode<T>* node)
{
    if (node!=NULL)
    {
    cout<<node->data;
    previst(node->left);
    previst(node->right);
    }
}
template<class T>
void BiTree<T>::midorder(BiTreeNode<T>* node)
{
    if (node!=NULL)
    {
        midorder(node->left);
        cout<<node->data;
        midorder(node->right);
    }

}
template<class T>
void BiTree<T>::backorder(BiTreeNode<T>* node)
{
    if (node!=NULL)
    {
        
        backorder(node->left);
        backorder(node->right);
        cout<<node->data;
    }
}
BiTreeNode<char>* create(vector<pair<char,int> >& vec1,int i)
{

    
    if (i>=vec1.size() || vec1[i].first=='*') return NULL;
    
    BiTreeNode<char>* root=new BiTreeNode<char>(vec1[i].first);

    if (i+1==vec1.size() || vec1[i+1].second!=vec1[i].second+1)
    {
        root->left=NULL;
        return root;
    }
    else
    root->left=create(vec1,i+1);
    
    int j=i+2;
    int m=10000;
    while(j<vec1.size()&&vec1[j].second!=vec1[i].second+1)
    { if(vec1[j].second==vec1[i].second) m=j;
        j++;
    }
    if (m<j) root->right=NULL;
    else root->right= create(vec1, j);

    return root;
}

int main()
{
    freopen("in28.txt", "r", stdin);
    freopen("out28.txt", "w", stdout);
    BiTree<char> Bi;
    vector<pair<char,int> > vec1;
    int num;
    cin>>num;
    while (num--)
    {
        vec1.clear();
        string s;
        while (cin>>s,s!="0")
        {
            int len=s.length();
            char c=s[len-1];
            vec1.push_back(pair<char,int>(c,len-1));
        }
        BiTreeNode<char>* p=create(vec1,0);
        Bi.SetRoot(p);
        {
            Bi.previst();
            Bi.backorder();
            Bi.midorder();
        }
        if (num>0) cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}




