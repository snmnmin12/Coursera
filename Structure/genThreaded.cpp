//
//  genThreaded.cpp
//  Structure
//
//  Created by Song on 1/12/16.
//  Copyright © 2016 Song. All rights reserved.
//

#include "genThreaded.h"
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