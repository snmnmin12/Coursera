
//ADT for tree
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <class T>
class TreeNode
{
public:
    TreeNode(const T& value);
    virtual ~TreeNode(){};
    bool isLeaf(){return LeftMostChild()==NULL&&RightSibling()==NULL;}
    T value(){return m_value;}
    TreeNode<T>* LeftMostChild(){return pChild;}
    TreeNode<T>* RightSibling() {return pSibling;}
    void setValue(const T& value){m_value=value;}
    void setChild(TreeNode<T>*pointer){pChild=pointer;}
    void setSibling(TreeNode<T>*pointer){pSibling=pointer;}
    void InserFirst(TreeNode<T>*node){}// 以第一个左孩子身份插入结点
    void InserNext(TreeNode<T>*node){}// 以右兄弟的身份插入结点
private:
    T m_value;
    TreeNode<T>* pChild;
    TreeNode<T>* pSibling;
    
};

template <class T>
class Tree {
public:
    Tree();
    ~Tree();
    TreeNode<T>* getRoot(){return root;}
    void CreateRoot(const T&rootValue);
    bool isEmpty() {return root==NULL;}
    TreeNode<T>* Parent(TreeNode<T>*current);
    TreeNode<T>* PrevSibling(TreeNode<T>*current);
    void DeleteSubTree(TreeNode<T>*subroot);
    void RootFirstTraverse(TreeNode<T>*root);
    void RootLastTraverse(TreeNode<T>*root);
    void WidthTraverse(TreeNode<T>*root);
private:
    TreeNode<T>* root;
    void DestroyNodes(TreeNode<T> *root);
    void Visit(const T& va)
    {
     cout<<va<<" ";
    }
};
template<class T>
void Tree<T>::RootFirstTraverse(TreeNode<T>* root)
{
    
    while (root!=NULL)
    {
        Visit(root->value);
        RootFirstTraverse(root->LeftMostChild());
        root=root->RightSibling();
    }
}
template<class T>
void Tree<T>::RootLastTraverse(TreeNode<T>* root)
{
    while (root!=NULL)
    {
        Visit(root->Value);
        RootFirstTraverse(root->LeftMostChild);
        root=root->RightSibling();
    }

}
template<class T>
void Tree<T>::WidthTraverse(TreeNode<T>*root)
{
    using std::queue;
    queue<TreeNode<T>* > aQueue;
    TreeNode<T>* pointer=root;
    while (pointer!=NULL)
    {
        aQueue.push(pointer);
        pointer=pointer->RightSibling;
    }
    while (!aQueue.empty())
    {
        pointer=aQueue.front();
        aQueue.pop();
        Visit(pointer->value());
        pointer=pointer->LeftMostChild;
        while (pointer!=NULL)
        {
        aQueue.push(pointer);
        pointer=pointer->RightSibling;
        }
        
    }
}
template<class T>
TreeNode<T>* Tree<T>::Parent(TreeNode<T>*current)
{
    using std::queue;
    queue<TreeNode<T>*> aQueue;
    TreeNode<T> *pointer=root;
    TreeNode<T> *farther,*upperlevelpointer;
    farther=upperlevelpointer=root;
    if (current!=NULL && pointer!=current)
    {
        while (pointer!=NULL)
        {
            if (current==pointer) break;
            aQueue.push(pointer);
            pointer=pointer->RightSibling();
        }
        
        while (!aQueue.empty())
        {
            pointer=aQueue.front();
            upperlevelpointer=pointer;
            pointer=pointer->LeftMostChild();
            while (pointer)
            {
                if (current==pointer)
                {
                    farther=upperlevelpointer;
                    break;
                }
                else
                {
                    aQueue.push(pointer);
                    pointer=pointer->RightSibling();}
                    
                }
            }
        }
     aQueue.clear();
     return farther;
}
template <class T>
void Tree<T>::DestroyNodes(TreeNode<T>* root) {
    if (root) {
        DestroyNodes(root->LeftMostChild());//递归删除第一子树
        DestroyNodes(root->RightSibling()); //递归删除其他子树
        delete root; //删除根结点
    }
}
template<class T>
void Tree<T>::DeleteSubTree(TreeNode<T>*subroot)
{
    if (subroot==NULL) return;
    TreeNode<T> * pointer=Parent(subroot);
    if (pointer==NULL)
    {
        pointer=root;
        while (pointer->RightSibling()!=subroot)
        pointer=pointer->RightSibling();
        pointer->setSibling(subroot->RightSibling());
    }
    else if(pointer->LeftMostChild()==subroot)
        pointer->setChild(subroot->RightSibling());
    else{
        pointer=pointer->LeftMostChild();
        while (pointer->RightSibling()!=subroot)
            pointer=pointer->RightSibling();
        pointer->setSibling(subroot->RightSibling());
    }
    subroot->setSibling(NULL);
    DestroyNodes(subroot);
}





template <class T>
class ParTreeNode {
private:
    T value;
    ParTreeNode<T>* parent;
    int nCount;
public:
    ParTreeNode(){parent=NULL;}
    ~ParTreeNode(){}
    T getValue(){return value;}
    void setValue(const T&val){value=val;}
    ParTreeNode<T>* getParent(){return parent;}
    void setParent(ParTreeNode<T>* par){parent=par;}
    int getCount(){return nCount;}
    void setCount(const int coun){nCount=coun;}
};
template<class T>
class ParTree
{
public:
    ParTreeNode<T>* array;
    int Size;
    ParTreeNode<T>*
    Find(ParTreeNode<T>* node) const;
    ParTree(const int size);
    virtual~ParTree(){if(array!=NULL) delete [] array;}
    void Union(int i,int j);
    bool Different(int i, int j);
    void Show() const;
};
template<class T>
ParTree<T>::ParTree(const int size)
{
    Size=size;
   
    array=new ParTreeNode<T>[Size];
     for(int i=0;i<Size;i++)
     {
         array[i].setValue(i);
         array[i].setCount(1);
     }
}
template<class T>
ParTreeNode<T>* ParTree<T>::Find(ParTreeNode<T>* node) const
{
    ParTreeNode<T>* pointer=node;
    while (pointer->getParent()!=NULL)
    {
        pointer=pointer->getParent();
    }
    return pointer;
}
template<class T>
void ParTree<T>::Union(int i, int j)
{
    ParTreeNode<T>* pointeri=Find(&array[i]);
    ParTreeNode<T>* pointerj=Find(&array[j]);
    if(pointeri!=pointerj)
    {
       if(pointeri->getCount()>=pointerj->getCount()){
           pointerj->setParent(pointeri);
           pointeri->setCount(pointeri->getCount()+
                              pointerj->getCount());
       
       }
       else {
           pointeri->setParent(pointerj);
           pointerj->setCount(pointeri->getCount()+
                              pointerj->getCount());
       }
    
    }
}
template<class T>
void ParTree<T>::Show() const
{
    for(int i=0;i<Size;i++)
    if(array[i].getParent()==NULL) cout<<array[i].getValue()<<" ";
    else cout<<array[i].getParent()->getValue()<<" ";
    cout<<endl;

}


//template<class T>
//class DualTagTreeNode{
//public:
//    T info;
//    int ltag,rtag;
//    DualTagTreeNode();
//    virtual ~DualTagTreeNode();
//};
//template<class T>
//Tree<T>::Tree(DualTagTreeNode<T>* nodeArray, int count)
//{
//    using std::stack;
//    stack<TreeNode<T>*> aStack;
//    TreeNode<T>* pointer=new TreeNode<T>;
//    root=pointer;
//    
//    for(int i=0;i<count-1;i++){
//        pointer=setValue(nodeArray[i].info);
//        if(nodeArray[i].rtag==0)
//        aStack.push(pointer);
//        else pointer->setSibling(NULL);
//        TreeNode<T>* temppointer=new TreeNode<T>;
//        if(nodeArray[i].ltag==0)
//            pointer->setChild(temppointer);
//        else{
//            pointer->setChild(NULL);
//            pointer=aStack.pop();
//            pointer->setSibling(temppointer);
//        }
//        pointer=temppointer;
//    }
//    pointer->setValue(nodeArray[count-1.info]);
//    pointer->setChild(NULL);
//    pointer->setSibling(NULL);
//}
//template<class T>
//Tree<T>::Tree(DualTagTreeNode<T>* nodeArray, int count)
//{
//    using std::queue;
//    queue<TreeNode<T>*> aQueue;
//    TreeNode<T>* pointer=new TreeNode<T>;
//    root=pointer;
//    for(int i=0;i<count-1;i++){
//        pointer->setValue(nodeArray[i].info);
//        if(nodeArray[i].ltag==0) aQueue.push(pointer);
//        else pointer->setChild(NULL);
//        TreeNode<T>* temppointer=new TreeNode<T>;
//        if(nodeArray[i].rtag==0)
//            pointer->setSibling(temppointer);
//        else{
//            pointer->setSibling(NULL);
//            pointer=aQueue.front();
//            aQueue.pop();
//            pointer->setChild(temppointer);
//        }
//        pointer=temppointer;
//    }
//    pointer->setValue(nodeArray[count-1].info);
//    pointer->setChild(NULL);
//    pointer->setSibling(NULL);
//}