//
//  week6_1.cpp
//  Structure
//
//  Created by Song on 1/13/16.
//  Copyright © 2016 Song. All rights reserved.
//

#include <iostream>
using namespace std;
int DefaultSize=100;
int MaxSize=100000;
template <class T>
class MinHeap
{
private:
    T* arr;
    int curSize;
    void BuildHeap();
public:
    MinHeap(const int n=DefaultSize);
    virtual ~MinHeap(){delete[] arr;}
    void SiftDown(int position);
    void SiftUp(int left);
    bool Insert(const T& newNode);
    T RemoveMin();
};
template <class T>
MinHeap<T>::MinHeap(const int n)
{
    curSize=(n>DefaultSize)?n:DefaultSize;
    arr=new T[n];
    curSize=0;
}
template <class T>
void MinHeap<T>::BuildHeap()
{
    for (int i=(curSize-1)/2; i>=0; i--)
        SiftDown(i);
}
template <class T>
void MinHeap<T>::SiftDown(int position)
{
    int i=position;
    int j=2*i+1;
    T temp=arr[i];
    while (j<curSize)
    {
        if(j+1<curSize && arr[j]>arr[j+1])
            j++;
        if (temp>arr[j])
        {
            arr[i]=arr[j];
            i=j;
            j=2*i+1;
        }
        else break;
    }
    arr[i]=temp;
}
template <class T>
void MinHeap<T>::SiftUp(int position)
{
    int i=position;
    int j=(i-1)/2;
    T temp;
    while (j>=0)
    {
        if (arr[i]<arr[j])
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i=j;
            j=(i-1)/2;
        }
        else break;
        
    }
    
}
template<class T>
bool MinHeap<T>::Insert(const T& newNode)
{
    if (curSize==MaxSize) return false;
    else
        arr[curSize]=newNode;
    SiftUp(curSize);
    curSize++;
    return true;
}
template<class T>
T MinHeap<T>::RemoveMin()
{
    T temp=arr[0];
    arr[0]=arr[curSize-1];
    curSize--;
    SiftDown(0);
    return temp;
}

template <class T>
struct HuffmanTreeNode
{
    HuffmanTreeNode()
    {
        parent=left=right=0;
    }
    HuffmanTreeNode(const T& e,HuffmanTreeNode<T>*pa=0,HuffmanTreeNode<T> *le=0,HuffmanTreeNode<T> *ri=0)
    {
        element=e;left=le; right=ri;parent=pa;
    }
    bool operator<(const HuffmanTreeNode<T> & huff2) const {return element<huff2.element;}
    bool operator>(const HuffmanTreeNode<T> & huff2) const {return element>huff2.element;}
    T element;
    HuffmanTreeNode<T>* parent;
    HuffmanTreeNode<T>* left;
    HuffmanTreeNode<T>* right;
};

template <class T>
class HuffmanT
{
public:
    HuffmanT(T weight[],int n);
    int shortest(){return shortest(root,0);}
    virtual~HuffmanT(){DeleteTree(root);}
private:
    HuffmanTreeNode<T>* root;
    void MergeTree(HuffmanTreeNode<T> &ht1,HuffmanTreeNode<T> &ht2,HuffmanTreeNode<T>* parent);
    void DeleteTree(HuffmanTreeNode<T>* node);
    int shortest(HuffmanTreeNode<T>*, int);
};
template <class T>
HuffmanT<T>::HuffmanT(T weight[], int n)
{
    MinHeap<HuffmanTreeNode<T> > heap;
    HuffmanTreeNode<T>* parent;
    HuffmanTreeNode<T>*firstchild,*secondchild;
    HuffmanTreeNode<T>* NodeList=new HuffmanTreeNode<T>[n];
    for (int i=0; i<n; i++)
    {
        NodeList[i].element=weight[i];
        NodeList[i].parent= NodeList[i].left= NodeList[i].right=NULL;
        heap.Insert(NodeList[i]);
    }
    for (int i=0; i<n-1; i++)
    {
        parent=new HuffmanTreeNode<T>;
        firstchild=new HuffmanTreeNode<T>;
        secondchild=new HuffmanTreeNode<T>;
        *firstchild=heap.RemoveMin();
        *secondchild=heap.RemoveMin();
        MergeTree(*firstchild, *secondchild, parent);
        heap.Insert(*parent);
        root=parent;
    }
    delete []NodeList;
}
template<class T>
void HuffmanT<T>::MergeTree(HuffmanTreeNode<T> &ht1,HuffmanTreeNode<T> &ht2,HuffmanTreeNode<T>* parent)
{
    parent->element=ht1.element+ht2.element;
    parent->left=&ht1;
    parent->right=&ht2;
}
template<class T>
void HuffmanT<T>::DeleteTree(HuffmanTreeNode<T>* node)
{
 
    if (node==NULL) return;
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
}
template<class T>
int HuffmanT<T>::shortest(HuffmanTreeNode<T>* node, int i)
{
    
    if (node->left==NULL && node->right==NULL) return node->element*i;
    else return shortest(node->left,i+1)+shortest(node->right,i+1);
    return 0;
}
int main()
{
    int a[100];
    int n;
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    HuffmanT<int> huff(a,n);
    cout<<huff.shortest()<<endl;
    return 0;
}