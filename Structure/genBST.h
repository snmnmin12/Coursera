

#include <stack>
#include <queue>
#include <iostream>
using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template <class T>
class Stack:public stack<T>
{
public:
    T pop()
    {
        T tmp=stack<T>::top();
        stack<T>::pop();
        return tmp;
    }
    
};

template <class T>
class Queue:public queue<T>{
public:
    T dequeue(){
        T tmp= queue<T>::front();
        queue<T>::pop();
        return tmp;
    }
    void enqueue(const T& el){
        push(el);
    }
};

template <class T>
class BSTNode
{
public:
    T el;
    BSTNode<T> *left,*right;
    BSTNode(){
        left=right=0;
    }
    BSTNode(const T&e,BSTNode<T>*l=0,BSTNode<T>*r=0)
    {
        el=e;
        left=l;
        right=r;
    }
};


template <class T>
class BST
{
public:
    BST(){root=0;}
    ~BST(){clear();}
    void clear(){clear(root);}
    bool isEmpty() const{return root==0;}
    void preorder(){preorder(root);}
    void inoder(){inorder(root);}
    void postorder(){postoder(root);}
    T*  search(const T& el) const{
        return search(root,el);
    }
    void breadthFirst();
    void iterativePreorder(){iterativePreorder(root);}
    void iterativeInorder() {iterativeInorder(root);}
    void IterativePostorder(){iterativePostorder(root);}
    void MorrisInorder();
    void insert(const T& el);
    void deleteByMerging(BSTNode<T>*&);
    void findAndDeleteByMerging(const T&);
    void deleteByCopying(BSTNode<T>*&);
    void balance(T*, int, int);
    
private:
    BSTNode<T>* root;
    void clear(BSTNode<T>*){}
    T* search(BSTNode<T>*, const T&);
    void preorder(BSTNode<T>*);
    void inorder(BSTNode<T>*);
    void postoder(BSTNode<T>*);
    void iterativePreorder(BSTNode<T>*);
    void iterativeInorder(BSTNode<T>*);
    void iterativePostorder(BSTNode<T>*);
    void visit(BSTNode<T>* p)
    {
        cout<<p->el<<" ";
    }
};
template <class T>
T* BST<T>::search(BSTNode<T> * p, const T & val)
{
    while (p!=NULL)
    {
        
        if (p->el==val)
            return p;
        if (val<p->el)
            p=p->left;
        else
            p=p->right;
    }
    return 0;
}
template <class T>
void BST<T>::breadthFirst()
{
    Queue<BSTNode<T>*> qe;
    BSTNode<T>* p=root;
    if (p!=NULL)
    {
        qe.enqueue(p);
        while (!qe.empty())
        {
            p=qe.dequeque();
            visit(p);
            if (p->left!=0)
                qe.enqueue(p->left);
            if (p->right!=0)
                qe.enqueue(p->right);
        }
    }
    
}
template <class T>
void BST<T>::iterativePreorder(BSTNode<T>*node)
{
    
    Stack<BSTNode<T>*> travStack;
    BSTNode<T> *p=node;
    
    if (p!=0)
    {
        travStack.push(p);
        while (!travStack.empty())
        {
            p=travStack.pop();
            visit(p);
            if (p->right!=0)
                travStack.push(p->right);
            if (p->left!=0)
                travStack.push(p->left);
        }
    }
    
}
template <class T>
void BST<T>::iterativeInorder(BSTNode<T>* node)
{
    
    Stack<BSTNode<T>*> travStack;
    BSTNode<T> *p=node;
    
    while (!travStack.empty() || p)
    {
        for (;p; p=p->left)  travStack.push(p);
        p=travStack.pop();
        visit(p);
        p=p->right;
    }
    
    
}
template <class T>
void BST<T>::iterativePostorder(BSTNode<T>*node)
{
    Stack<BSTNode<T>*> travStack;
    BSTNode<T> *p=node,*q=node;
    
    while (p!=0)
    {
        for (; p->left!=0; p=p->left) travStack.push(p);
        while (p->right==0 || p->right==q)
        {
            visit(p);
            q=p;
            if (travStack.empty())
                return;
            p=travStack.pop();
        }
        travStack.push(p);
        p=p->right;
    }
    
}
template <class T>
void BST<T>::MorrisInorder()
{
    Stack<BSTNode<T>*> travStack;
    BSTNode<T> *p = root;
    while (p != 0) {
        while (p != 0) { // stack the right child (if any)
            if (p->right) // and the node itself when going
                travStack.push(p->right); // to the left;
            travStack.push(p);
            p = p->left;
        }
        p = travStack.pop(); // pop a node with no left child
        while (!travStack.empty() && p->right == 0) { // visit it
            visit(p); // and all nodes with no right
            p = travStack.pop(); // child;
        }
        visit(p); // visit also the first node with
        if (!travStack.empty()) // a right child (if any);
            p = travStack.pop();
        else p = 0;
    }
    
}
template <class T>
void BST<T>::insert(const T& el)
{
    BSTNode<T>* p=root,*prev=0;
    while (p!=0)
    {
        prev=p;
        if (el<p->el)
            p=p->left;
        else
            p=p->right;
    }
    if (root==0)
        root=new BSTNode<T>(el);
    else if(el<prev->el)
        prev->left=new BSTNode<T>(el);
    else prev->right=new BSTNode<T>(el);
    
}
template <class T>
void BST<T>::deleteByMerging(BSTNode<T>*&node)
{
    BSTNode<T>* tmp=node;
    if (node!=0)
    {
        if (node->right==0)
            node=node->left;
        else if(node->left==0)
            node=node->right;
        else
        {
            tmp=node->left;
            while (tmp->right!=0)
                tmp=tmp->right;
            tmp->right=node->right;
            tmp=node;
            node=node->left;
            
        }
        delete tmp;
    }
    
}
template <class T>
void BST<T>::findAndDeleteByMerging(const T& el)
{
    BSTNode<T>* node=root,*prev=0;
    while (node!=0)
    {
        if (node->el==el) break;
        prev=node;
        if (el<node->el)
            node=node->left;
        else node=node->right;
    }
    if (node!=0 && node->el==el)
    {
        if(node==root)
            deleteByMerging(root);
        else if(prev->left==node)
            deleteByMerging(prev->left);
        else deleteByMerging(prev->right);
    }
    else if(root!=0)
        cout<<"element"<<el<<"is not in the tree\n";
    else cout<<"the tree is empty\n";
}
template <class T>
void BST<T>::deleteByCopying(BSTNode<T>*& node)
{
    BSTNode<T>* *prevous,*tmp=node;
    if (node->right==0)
        node=node->left;
    else if(node->left==0)
        node=node->right;
    else
    {
        tmp=node->left;
        prevous=node;
        while (tmp->right!=0)
        {
            prevous=tmp;
            tmp=tmp->right;
        }
        node->el=tmp->el;
        if (prevous==node)
            prevous->left=tmp->left;
        else
            prevous->right=tmp->left;
        
    }
    delete tmp;
    
}
template <class T>
void BST<T>::balance(T data[], int first, int last)
{
    if (first<=last)
    {
        int middle=(first+last)/2;
        insert(data[middle]);
        balance(data, first, middle-1);
        balance(data, middle+1, last);
    }
    
}
template <class T>
void BST<T>::preorder(BSTNode<T>* p)
{
    if (p!=0)
    {
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
    
}
template <class T>
void BST<T>::inorder(BSTNode<T>*p)
{
    if (p!=0)
    {
        inorder(p->left);
         visit(p);
        inorder(p->right);
    }
}
template<class T>
void BST<T>::postoder(BSTNode<T>*p)
{
    if (p!=0)
    {
        postoder(p->left);
        postoder(p->right);
        visit(p);
    }
}
#endif


