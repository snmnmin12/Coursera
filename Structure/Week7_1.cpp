//
//  week7_1.cpp
//  Structure
//
//  Created by Song on 1/16/16.
//  Copyright © 2016 Song. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <class T>
class TreeNode
{
public:
    TreeNode(){pChild=pSibling=NULL;}
    TreeNode(const T& value){m_value=value;pChild=pSibling=NULL;}
    virtual ~TreeNode(){};
    bool isLeaf(){return LeftMostChild()==NULL&&RightSibling()==NULL;}
    T value(){return m_value;}
    TreeNode<T>* LeftMostChild(){return pChild;}
    TreeNode<T>* RightSibling() {return pSibling;}
    void setValue(const T& value){m_value=value;}
    void setChild(TreeNode<T>*pointer){pChild=pointer;}
    void setSibling(TreeNode<T>*pointer){pSibling=pointer;}
private:
    T m_value;
    TreeNode<T>* pChild;
    TreeNode<T>* pSibling;
    
    
};
template <class T>
class LevelTreeNode
{
public:
    T info;
    int deg;
    LevelTreeNode(){}
    virtual ~LevelTreeNode(){}
};

template <class T>
class Tree {
public:
    Tree();
    Tree(LevelTreeNode<T>*, int);
    ~Tree(){}
    void RootLastTraverse(){RootLastTraverse(root);}

private:
    TreeNode<T>* root;
    void RootLastTraverse(TreeNode<T>*root);
    void Visit(const T& val)
    {
        cout<<val<<" ";
    }
};
template <class T>
void Tree<T>::RootLastTraverse(TreeNode<T>*root)
{
    TreeNode<T>* p=root;
    while (p)
    {
        RootLastTraverse(p->LeftMostChild());
        Visit(p->value());
        p=p->RightSibling();
    }

}


template<class T>
Tree<T>::Tree(LevelTreeNode<T>* nodeArray,int num)
{
     using std::queue;
     queue<TreeNode<T>*> aQueue;
     TreeNode<T> *pointer=new TreeNode<T>;
     root=pointer;
    aQueue.push(pointer);
    
    for (int i=0; i<num; i++)
    {
        pointer=aQueue.front();
        aQueue.pop();
        int deg=nodeArray[i].deg;
        pointer->setValue(nodeArray[i].info);
        
        if (deg==0) pointer->setChild(NULL);
        else
        {
        
        for (int j=0; j<deg; j++)
        {
        TreeNode<T> *temppointer=new TreeNode<T>;
        if (j==0)  pointer->setChild(temppointer);
        else  pointer->setSibling(temppointer);
        pointer=temppointer;
        aQueue.push(pointer);
        }
            
        }
        

    }
}



//int main()
//{
//    LevelTreeNode<char> nodeArray[100];
//
//    int num;
//    cin>>num;
//    
//    while (num--)
//    {
//        char c;
//        int i=0;
//        while (true) {
//            cin>>c;
//            nodeArray[i].info=c;
//            cin>>nodeArray[i].deg;
//            cin.get(c);
//            i++;
//            if (c=='\n') break;
//        }
//        Tree<char> tre(nodeArray,i);
//        tre.RootLastTraverse();
//    }
//
//}