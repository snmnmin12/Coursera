//
//  Week7_2.cpp
//  Structure
//
//  Created by Song on 1/16/16.
//  Copyright © 2016 Song. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace::std;
template<class T>
struct BinaryTreeNode
{
    T value;
    BinaryTreeNode* pleft;
    BinaryTreeNode* pright;
    BinaryTreeNode(){pleft=pright=0;}
};
template <class T>
struct input
{
    T value;
    int check;
};
template <class T>
class BTree
{
public:
    BTree(input<T>* arr, int num);
    void preorder(){preorder(root);}
    void width(){width(root);}
private:
    BinaryTreeNode<T>* root;
    void preorder(BinaryTreeNode<T>* node);
    void width(BinaryTreeNode<T>* node);
    void visit(BinaryTreeNode<T> *node) {cout<<node->value<<" ";}
};
template <class T>
BTree<T>::BTree(input<T>* arr, int num)
{
    
    stack<BinaryTreeNode<T>* > aStack;
    BinaryTreeNode<T>* pointer=new BinaryTreeNode<T>;
    root=pointer;
    for (int i=0; i<num; i++)
    {
        
        pointer->value=arr[i].value;
        
        if (arr[i].check==1)
        pointer->pleft=pointer->pright=0;
        else aStack.push(pointer);
        
        BinaryTreeNode<T>* temppointer=new BinaryTreeNode<T>;
        
        if (!aStack.empty())
        {
            pointer=aStack.top();
            aStack.pop();
            if (pointer->pleft==NULL)
            {
                pointer->pleft=temppointer;
                aStack.push(pointer);
            }
            else
            pointer->pright=temppointer;
        }
        pointer=temppointer;
    }
}
template<class T>
void BTree<T>::preorder(BinaryTreeNode<T>* node)
{
    if (node!=NULL)
    {
    visit(node);
    preorder(node->pleft);
    preorder(node->pright);
    }
}
template<class T>
void BTree<T>::width(BinaryTreeNode<T>* node)
{
    BinaryTreeNode<T> *p=node;
    stack<BinaryTreeNode<T>*> aStack;
    queue<BinaryTreeNode<T>*> aQueue;
    while (p!=NULL)
    {
        aStack.push(p);
        p=p->pright;
    }
    while (!aStack.empty())
    {
    aQueue.push(aStack.top());
    aStack.pop();
    }
    
    
    while (!aQueue.empty())
    {
        p=aQueue.front();
        aQueue.pop();
        if (p->value!='$')
        visit(p);
        p=p->pleft;
        while (p!=NULL)
        {
            aStack.push(p);
            p=p->pright;
        }
        while (!aStack.empty())
        {
            aQueue.push(aStack.top());
            aStack.pop();
        }
        
    }
}
//int main()
//{
//    input<char> inp[50];
//    int num;
//    cin>>num;
//    for (int i=0; i<num; i++)
//    {
//        cin>>inp[i].value;
//        cin>>inp[i].check;
//    }
//    BTree<char> best(inp,num);
//    //best.preorder();
//    best.width();
//    return 0;
//}