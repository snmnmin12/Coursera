//
//  genThreaded.hpp
//  Structure
//
//  Created by Song on 1/12/16.
//  Copyright © 2016 Song. All rights reserved.
//

#ifndef genThreaded_h
#define genThreaded_h

#include <stdio.h>

template <class T>
class ThreadedNode
{
public:
    ThreadedNode(){
        left=right=0;
    }
    ThreadedNode(const T& e, ThreadedNode* l=0,ThreadedNode* r=0)
    {
        el=e; left=l;right=r;successor=0;
    }
    T el;
    ThreadedNode* left, * right;
    unsigned int successor:1;
};
template <class T>
class ThreadedTree
{
    ThreadedTree(){root=0;}
    ~ThreadedTree(){clear();}
    void clear(){clear(root);}
    bool isEmpty() const{return root==0;}
    void preorder(){preorder(root);}
    void inoder(){inoder(root);}
    void postorder(){postoder(root);}
    T*  search(const T& el) const{
        return search(root,el);
    }
    void breadthFirst();
    void iterativePreorder();
    void iterativeInorder();
    void IterativePostorder();
    void MorrisInorder();
    void insert(const T&);
    void deleteByMerging(ThreadedNode<T>*&);
    void findAndDeleteByMerging(const T&);
    void deleteByCopying(ThreadedNode<T>*&);
    void balance(T*, int, int);
    
private:
    ThreadedNode<T>* root;
    void clear(ThreadedNode<T>*);
    T* search(ThreadedNode<T>*, const T&);
    void preoder(ThreadedNode<T>*);
    void inorder(ThreadedNode<T>*);
    void postoder(ThreadedNode<T>*);
};
template<class T>
void ThreadedTree<T>::inorder(ThreadedNode<T>*)
{
    ThreadedNode<T>*prev, *p=root;
    if (p!=0) // process only nonempty trees;
    {
        while (p->left!=0)// go to the leftmost node;
            p=p->left;
        while (p!=0)
        {
            visit(p);
            prev=p;
            p=p->right;
            if (p!=0 && prev->successor==0)// go to the right node and only
                while (p->left!=0)
                    p=p->left;
            
        }
    }
}
#endif /* genThreaded_hpp */
