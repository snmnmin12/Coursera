//
//  nodevist.cpp
//  Structure
//
//  Created by Song on 1/14/16.
//  Copyright © 2016 Song. All rights reserved.
//

//template<class T>
//void BinaryTree<T>::PreOrderWithoutRecusion (BinaryTreeNode<T>* root)
//{
//    using std::stack; // 使用STL中的stack
//    stack<BinaryTreeNode<T>* > aStack;
//    BinaryTreeNode<T>* pointer=root;
//    aStack.push(NULL); // 栈底监视哨
//    while(pointer) { // 或者!aStack.empty()
//        Visit(pointer->value()); // 访问当前结点
//        if (pointer->rightchild() != NULL) // 右孩子入栈
//            aStack.push(pointer->rightchild());
//        if (pointer->leftchild() != NULL)
//            pointer = pointer->leftchild(); //左路下降
//        else { // 左子树访问完毕，转向访问右子树
//            pointer = aStack.top();
//            aStack.pop(); // 栈顶元素退栈 }
//        }
//}
//
//
//
//template<class T>
//void BinaryTree<T>::InOrderWithoutRecusion(BinaryTreeNode<T>*root)
//{
//    using std::stack; // 使用STL中的stack
//    stack<BinaryTreeNode<T>* > aStack;
//    BinaryTreeNode<T>* pointer = root;
//    while (!aStack.empty() || pointer) {
//        if (pointer ) {
//            // Visit(pointer->value()); // 前序访问点
//            aStack.push(pointer); // 当前结点地址入栈
//            // 当前链接结构指向左孩子
//            pointer = pointer->leftchild();
//        } //end if
//        else { //左子树访问完毕，转向访问右子树
//            pointer = aStack.top();
//            aStack.pop(); //栈顶元素退栈
//            Visit(pointer->value()); //访问当前结点
//            //当前链接结构指向右孩子
//            pointer=pointer->rightchild();
//        } //end else
//    } //end while
//}

    
//template<class T>
//void BinaryTree<T>::InOrderWithoutRecusion(BinaryTreeNode<T>*root)
//{
//    using std::stack; // 使用STL中的stack
//    stack<BinaryTreeNode<T>* > aStack;
//    BinaryTreeNode<T>* pointer = root;
//    while (pointer)
//    {
//        for (; pointer->left!=NULL; pointer=pointer->left)
//        {
//            // Visit(pointer->value()); // 前序访问点
//            aStack.push(pointer); // 当前结点地址入栈
//            // 当前链接结构指向左孩子
//            pointer = pointer->leftchild();
//        } //end if
//        
//        else { //左子树访问完毕，转向访问右子树
//            pointer = aStack.top();
//            aStack.pop(); //栈顶元素退栈
//            Visit(pointer->value()); //访问当前结点
//            //当前链接结构指向右孩子
//            pointer=pointer->rightchild();
//        } //end else
//    } //end while
//}

