////
////  heapsort.cpp
////  Algorithm
////
////  Created by Song on 1/2/16.
////  Copyright © 2016 Song. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//void swap(int & a, int &b)
//{
//    int temp=a;
//    a=b;
//    b=temp;
//}
//void Max_Heapify(int* A, int length,int i)
//{
//    
//    int largest=i;
//    int l=2*i+1;
//    int r=2*(i+1);
//    if (l<length && A[l]>A[i])
//        largest=l;
//    if (r<length && A[r]>A[largest])
//        largest=r;
//    if (largest!=i)
//    { swap(A[i],A[largest]);
//    Max_Heapify(A,length,largest);
//    }
//}
//void Buid_Max_Heap(int* A, int length){
//    if (length<2) return;
//    for (int i=length/2-1; i>=0; i--)
//        Max_Heapify(A, length,i);
//}
//void HeapSort(int *A, int length)
//{
//    Buid_Max_Heap(A, length);
//    for (int i=length-1; i>0; i--)
//    {
//        swap(A[0], A[i]);
//        length--;
//        Max_Heapify(A, length, 0);
//    }
//}
//int Heap_Maximum(int* A, int length)
//{
//    if (length>1)
//    return A[0];
//    else
//        return 0;
//}
//int Heap_Extract_Max(int*A, int &length){
//    if (length<1)
//        cerr<<"heap underflow";
//    int max=A[0];
//    A[0]=A[length-1];
//    length--;
//    Max_Heapify(A, length, 0);
//    return max;
//}
//void Heap_Increase_Key(int *A, int length, int i,int key){
//    if (key<A[i])
//        cerr<<"new key is smaller than current key";
//    A[i]=key;
//    while (i>0) {
//        int parent=(i-1)/2;
//        if (parent<1) break;
//        if (A[i]<=A[parent]) break;
//        swap(A[i], A[parent]);
//        i=parent;
//    }
//}
//void Max_Heap_Insert(int*A, int& length,int key){
//    length+=1;
//    A[length-1]=-1000;
//    Heap_Increase_Key(A, length, length-1, key);
//}
//int main()
//{
//    //int A[]={0,27, 17, 3, 16,13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
//    //int A[]={0, 4 ,1, 3, 2, 16, 9, 10, 14, 8,7 };
//    //int A[]={5,13,2,25,7,17,20,8,4};
//    int A[]={15,13,9,5,12,8,7,4,0,6,2,1};
//    int length=12;
//    for (int i=0; i<length; i++)
//        printf("%d ",A[i]);
//    printf("\n");
//
//   // Buid_Max_Heap(A,10);
//   // HeapSort(A,length);
//    //Heap_Extract_Max(A, length);
//    Max_Heap_Insert(A, length, 10);
//    for (int i=0; i<length; i++)
//        printf("%d ",A[i]);
//    printf("\n");
//
//    return 0;
//}