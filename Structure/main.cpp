//////
//////  main.cpp
//////  Structure
//////
//////  Created by Song on 12/17/15.
//////  Copyright © 2015 Song. All rights reserved.
//////
////
//#include <iostream>
//using std::cin;
//using std::cout;
//using std::endl;
//
//template<class T>
//class List{
//    void clear();
//    bool isEmpty();
//    bool append(const T value);
//    bool insert(const int p, const T value);
//    bool del(const int p);
//    bool getPos(int& p, const T value);
//    bool getValue(const int p, T& value);
//    bool setValue(const int p, const T value);
//};
//
//template<class T>
//class arrList//:public List<T>{
//{private:
//    T* aList;   //私有变量，存贮顺序表实例
//    int maxSize; //私有变量，顺序表的最大长度
//    int curLen;  //私有变量，顺序表的当前长度
//    int poistion;//私有变量，顺序表的当前处理位置
//public:
//    arrList(const int size){
//        maxSize=size;
//        aList=new T[maxSize];
//        curLen=poistion=0;
//    }
//    ~arrList(){
//        delete [] aList;
//    }
//    void clear(){
//        delete [] aList;
//        curLen=poistion=0;
//        aList=new T[maxSize];
//    }
//    int length(){return curLen;};
//    bool append(T value);
//    bool insert(int p, T value);
//    bool del(int p);
//    int getPos(const T value);
//    void print(const int p);
//};
//
//template<class T>
//int arrList<T>::getPos(const T value){
//    int i;
//    for (i=0; i< curLen;i++) {
//        if (value==aList[i])
//            return i;
//    }
//    return -1;
//}
//template<class T>
//bool arrList<T>::append(T value){
//    if (curLen>=maxSize) {
//        cout<<"The list is overflow"<<endl;
//        return false;
//    }
//    aList[curLen++]=value;
//    //curLen++;
//    return true;
//}
//
//template<class T>
//bool arrList<T>::insert(int p, T value){
//    int i;
//    if (curLen>maxSize) {
//        cout<<"The list is overflow"<<endl;
//    }
//    if (p<0||p>curLen) {
//        cout<<"Insertion is illege \n"<<endl;
//        return false;
//    }
//    for (i=curLen; i>p; i--)
//        aList[i]=aList[i-1];
//    aList[p]=value;
//    curLen++;
//    return true;
//    
//}
//template<class T>
//bool arrList<T>::del(int p){
//    int i;
//    if (curLen<=0) {
//        cout<<"No element to delete \n"<<endl;
//        return false;
//    }
//    if (p<0 || p>curLen-1) {
//        cout<<"deletion is illege\n"<<endl;
//        return false;
//    }
//    for (i=p; i<curLen-1; i++)
//        aList[i]=aList[i+1];
//    curLen--;
//    return true;
//}
//template<class T>
//void arrList<T>::print(const int i){
//   // for (int i=0; i<curLen; i++)
//        cout<<aList[i];
//    cout<<endl;
//}
//
//int main()
//{
//    const int SIZE =300;
//    arrList<int> arr(SIZE);
//    
//    int n,m;
//    cin>>n>>m;
//    
//    int i;
//    for (i=0; i<n; i++)
//    arr.append(i+1);
//    
//    int pos=0;
//    //int offset=-1;
//    while (arr.length()>1) {
//        pos=(pos-1+m)%arr.length();
//        arr.del(pos);
//    }
//    arr.print(0);
//    return 0;
//}
//
////
////#include <iostream>
////using namespace std;
////typedef struct _LinkNode {
////    int value;
////    struct _LinkNode* next;
////} LinkNode, *LinkNodePtr;
////
////LinkNodePtr createCycle(int total) {
////    int index = 1;
////    LinkNodePtr head = NULL, curr = NULL, prev = NULL;
////    head = (LinkNodePtr) malloc(sizeof(LinkNode));
////    head->value = index;
////    prev = head;
////    
////    while (--total > 0) {
////        curr = (LinkNodePtr) malloc(sizeof(LinkNode));
////        curr->value = ++index;
////        prev->next = curr;
////        prev = curr;
////    }
////    curr->next = head;
////    return head;
////}
////
////void run(int total, int tag) {
////    LinkNodePtr node = createCycle(total);
////    LinkNodePtr prev = NULL;
////    int start = 1;
////    int index = start;
////    while (node && node->next) {
////        if (index == tag) {
////            printf("\n%d", node->value);
////            if (tag == start) {
////                prev = node->next;
////                node->next = NULL;
////                free(node);
////                node = prev;
////            } else {
////                prev->next = node->next;
////                node->next = NULL;
////                free(node);
////                node = prev->next;
////            }
////            index = start;
////        } else {
////            prev = node;
////            node = node->next;
////            index++;
////        }
////    }
////}
////int main() {
////    run(5, 999999);
////    return 0;
////}
//
////#include <stdio.h>
////#define N 12    //总人数
////#define M 4     //数到第几个人就自杀
//////主程序，不清楚的参考注释
////int main()
////{
////int man[N] = {0};//排列顺序数组，里面有所有的人，下标从0开始
////int count = 1;//自杀了多少人，<=N
////int i = 0;//0<=i<=3，用于临时计数
////int pos = -1;//数到第几个人了，算是标记
////int alive = 0;
////
////while(count <= N) {//还有人存活，继续
////    do {
////        pos = (pos+1) % N;  //环状处理，>N时，pos进入下一圈儿
////        if(man[pos] == 0)//如果这个位置的人还活着
////            i++;//计数+1
////        
////        if(i == M) {//报数为3了
////            i = 0;//计数清零
////            break;//跳出，去执行自杀
////        }
////    } while(1);
////    man[pos] = count;//第count个自杀的人，在排列上是第pos个位置，
////    count++;//自杀完成，自杀人数+1
////}
////
////printf("\n约琴夫排列：");
////for(i = 0; i < N; i++)
////printf("%d ", man[i]);
////alive = 1;//还有alive个人活着
////
////printf("\nL表示这%d人要放的位置：\n", alive);
////for(i = 0; i < N; i++) {
////    if(man[i] > (N - alive))
////        printf("L");//最后还有alive个人活着，不知道还是不是继续，哈哈
////        else
////            printf("D");//自杀的人
////            if((i+1) % 5 == 0)  printf("  ");
////                }
////printf("\n");
////    return 0;
////}
//
////#include <iostream>
////using namespace std;
////int josephus(int n, int k) {
////    int s = 0;
////    for (int i = 2; i <= n; i++)
////        s = (s + k) % i;
////    return s;
////}
////int main() {
////   // for (int i = 1; i <= 100; i++)
////    int n,m;
////    cin>>n>>m;
////    cout<< josephus(n, m)+1<<endl;
////    return 0;
////}
