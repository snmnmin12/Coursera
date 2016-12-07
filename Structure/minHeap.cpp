//
//  minHeap.cpp
//  Structure
//
//  Created by Song on 1/11/16.
//  Copyright © 2016 Song. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
#define DefaultSize 20
template <class T>
class MinHeap
{
public:
    T* heap;
    int currentsize;
    int maxHeapSize;
    void siftDown(int start, int m);
    void siftUp(int start);
public:
    MinHeap(int sz=DefaultSize);
    MinHeap(T arr[], int n);
    ~MinHeap(){delete []heap;}
    bool isEmpty() const {return currentsize==0;}
    bool isfull() const {return currentsize==maxHeapSize;}
    void makeempty() {currentsize=0;}
    bool insert(const T&x);
    bool removeMin(T& x);
};

template<class T>
MinHeap<T>::MinHeap(int siz){
    maxHeapSize=(siz>DefaultSize)?siz:DefaultSize;
    heap =new T[maxHeapSize];
    if (heap==NULL) cerr<<"err\n";
    currentsize=0;
}
template<class T>
MinHeap<T>::MinHeap(T arr[], int n){
    maxHeapSize=(n>DefaultSize)?n:DefaultSize;
    heap =new T[maxHeapSize];
    if (heap==NULL) cerr<<"err\n";
    currentsize=n;
    int i=0;
    while (i<n)
    {
        heap[i]=arr[i];
        i++;
    }
    int curPos=currentsize/2-1;
    while (curPos>=0) {
        siftDown(curPos, currentsize);
        curPos--;
    }
}
template<class T>
void MinHeap<T>::siftDown(int start, int m){
    int i=start;
    int j=2*i+1;
    T temp=heap[start];
    while (j<m)
    {
        if (j+1<m && heap[j+1]<heap[j])
            j++;
        if (temp<heap[j] ||temp==heap[j]) break;
        heap[i]=heap[j];
        i=j;j=2*i+1;
        heap[i]=temp;
    }
   // heap[i]=temp;
}
template<class T>
void MinHeap<T>::siftUp(int start){
    int j=start;
    int parent=(j-1)/2;
    T temp=heap[j];
    while (parent>=0)
    {
        
        if (!(temp<heap[parent])) break;
        else
        {
            heap[j]=heap[parent];
            j=parent;
            parent=(j-1)/2;
            heap[j]=temp;
        }
        
    }
    //heap[j]=temp;
}
template<class T>
bool MinHeap<T>::insert(const T&x){
    if (currentsize==DefaultSize) {cerr<<"full\n";return false;}
    heap[currentsize]=x;
    siftUp(currentsize);
    currentsize++;
    return true;
}
template<class T>
bool MinHeap<T>::removeMin(T &x){
    if (currentsize==0) {cerr<<"empty\n";return false;}
    x=heap[0];
    heap[0]=heap[currentsize-1];
    currentsize--;
    siftDown(0, currentsize);
    return true;
}
//int main()
//{
//    int arr[6]={5,4,3,2,1,0};
//    int i=0;
//    while (i<sizeof(arr)/sizeof(arr[0]))
//        cout<<arr[i++]<<" ";
//    cout<<endl;
//    MinHeap<int> h(arr,sizeof(arr)/sizeof(arr[0]));
//    i=0;
//    while (i<6)
//        cout<<h.heap[i++]<<" ";
//    cout<<endl;
//    int x=10;
//    h.insert(x);
//    i=0;
//    while (i<7) cout<<h.heap[i++]<<" ";
//    cout<<endl;
//    h.removeMin(x);
//    i=0;
//    while (i<6) cout<<h.heap[i++]<<" ";
//    cout<<endl;
//}