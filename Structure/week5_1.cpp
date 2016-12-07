//////
//////  week5.cpp
//////  Structure
//////
//////  Created by Song on 1/10/16.
//////  Copyright © 2016 Song. All rights reserved.
//////
////
//#include <stdio.h>
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//class BinarytreeNode
//{
//private:
//    int data;
//    BinarytreeNode* left;
//    BinarytreeNode* right;
//public:
//    BinarytreeNode(const int d){data=d;left=NULL;right=NULL;}
//    void SetData(int d){data=d;}
//    void SetLeft(BinarytreeNode* le){left=le;}
//    void SetRight(BinarytreeNode* rl){right=rl;}
//    BinarytreeNode* GetLeft(){return left;}
//    BinarytreeNode* GetRight(){return right;}
//    int GetData() const {return data;}
//    ~BinarytreeNode(){}
//};
//void Preordervist(BinarytreeNode* parent)
//{
//    if (parent!=NULL)
//    {
//     printf("%d ",parent->GetData());
//     Preordervist(parent->GetLeft());
//     Preordervist(parent->GetRight());
//    }
//}
//BinarytreeNode* Build(vector<int>& vec1,vector<int> &vec2)
//{
//    
//    int len=vec2.size();
//    if (len==0) return NULL;
//    int data=vec2[len-1];
//    BinarytreeNode *parent=new BinarytreeNode(data);
//    if (len==1) return parent;
//    vector<int>::iterator it;
//    vector<int>::iterator it1;
//    it1=find(vec1.begin(), vec1.end(), data);
//    
//    vector<int> leftv1;
//    vector<int> rightv1;
//    for (it=vec1.begin(); it!=it1; it++)
//    leftv1.push_back(*it);
//    for (it=it1+1; it!=vec1.end(); it++)
//    rightv1.push_back(*it);
//    vector<int> leftv2;
//    vector<int> rightv2;
//    //it+1 is also first in middle order, and also in the back order vist
//    vector<int>::iterator it2;
//    if (it1+1!=vec1.end())
//    it2=find(vec2.begin(), vec2.end(), *(it1+1));
//    else it2=vec2.end()-1;
//    for (it=vec2.begin(); it!=it2; it++)
//        leftv2.push_back(*it);
//    for (it=it2; it!=vec2.end()-1; it++)
//        rightv2.push_back(*it);
//    BinarytreeNode* left=Build(leftv1, leftv2);
//    parent->SetLeft(left);
//    BinarytreeNode* right=Build(rightv1, rightv2);
//    parent->SetRight(right);
//    return parent;
//}
//
//
//int main()
//{
//    vector<int> vec1;
//    vector<int> vec2;
//    int num;
//    while (cin>>num)
//    {
//        vec1.push_back(num);
//        if( cin.get()=='\n') break;
//    }
//    while (cin>>num)
//    {
//        vec2.push_back(num);
//        if(cin.get()=='\n') break;
//    }
//    BinarytreeNode *parent=Build(vec1, vec2);
//    Preordervist(parent);
//    printf("\n");
//}