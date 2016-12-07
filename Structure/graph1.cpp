////
////  graph1.cpp
////  Structure
////
////  Created by Song on 1/18/16.
////  Copyright © 2016 Song. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <cstring>
//#include <queue>
//#define UNVISITED 0
//#define VISITED 1
//#define INFINITY 1<<30
//
//class Edge;
//template<class T>
//class Graph;
//template<class T>
//void DFS(Graph<T>& G,int v);
//template<class T>
//class Vertex
//{
//public:
//    T value;
//    Vertex() {value=0;}
//    Vertex(T& val) {value=val;}
//};
//class Edge{
//public:
//    int to;
//    int nextID;
//    int weight;
//    Edge(){
//        to=0; nextID=0;weight=0;
//    }
//    Edge(int t,int n,int w=1){
//        to=t; nextID=n;weight=w;
//    }
//};
//template <class T>
//class Graph{
//public:
//    Graph(){Mark=0;Indegree=0;vers=0;edge=edgelist=0;}
//    Graph(T *arr,int, int*, int*,int, int* w=0);
//    ~Graph();
//    void Graph_Trasver();
//    int VerticesNum();
//    int EdgesNum();
//    Edge FirstEdge(int oneVertex);
//    Edge NextEdge(Edge preEdge);
//    bool setEdge(int fromVertex, int toVertex, int weight){}
//    bool delEdge(int fromVertex, int toVertex) {}
//    bool IsEdge(Edge oneEdge);
//    //int  FromVertex(Edge oneEdge){return ;}
//    int  ToVertex(Edge oneEdge) {return oneEdge.to;}
//    int  Weight(Edge oneEdge) {return oneEdge.weight;}
//    void print();
//public:
//    int numVertex;
//    int numEdge;
//    int *Mark;
//    int *Indegree;
//    Vertex<T> *vers;
//    Edge* edge;
//    int* edgelist;
//};
//template<class T>
//Graph<T>::Graph(T *ar, int numVert, int* from, int* to, int k,int* w)
//{
//    numVertex=numVert;
//    numEdge=k;
//    Indegree=new int[numVertex];
//    Mark=new int[numVertex];
//    vers=new Vertex<T>[numVert];
//    memset(Mark,0,sizeof(int)*numVertex);
//    memset(Indegree, 0, sizeof(int)*numVertex);
//    for (int i=0;i<numVertex;i++)
//        vers[i].value=ar[i];
//    
//    edgelist=new int[numVertex];
//    memset(edgelist, 0, sizeof(int)*numVertex);
//    edge = new Edge[k+1];
//    
//    for (int i=0; i<k; i++)
//    {
//        int u=from[i];
//        int v=to[i];
//        edge[i].to=v;
//        int nextid=edgelist[u-1];
//        edge[i].nextID=nextid;
//        edgelist[u-1]=i+1;
//    }
//    
//
//}
//template<class T>
//Graph<T>:: ~Graph(){
//    delete [] Mark;
//    delete [] Indegree;
//    delete []vers;
//    delete []edgelist;
//    delete []edge;
//}
//template<class T>
//int Graph<T>::VerticesNum(){
//    return numVertex;
//}
//template<class T>
//bool Graph<T>::IsEdge(Edge oneEdge){
//    if (oneEdge.weight>0 && oneEdge.weight<INFINITY && oneEdge.to>=0)
//        return true;
//    else return false;
//}
//
//template<class T>
//Edge Graph<T>::FirstEdge(int oneVertex)
//{
//    int i=edgelist[oneVertex];
//    
//    return edge[i];
//}
//template<class T>
//Edge Graph<T>::NextEdge(Edge preEdge)
//{
//
//    int ID=preEdge.nextID;
//    return edge[ID];
//}
//
//template<class T>
//void Graph<T>:: print()
//{
//    for (int i=0; i<numVertex; i++)
//        std::cout<<i+1<<": "<<edgelist[i]<<std::endl;;
//    
//    for (int i=0;i<numEdge; i++)
//        std::cout<<i+1<<": "<<edge[i].to<<": "<<edge[i].nextID<<std::endl;
//
//}
//
//
//template<class T>
//void Visit(Graph<T>& G,int v) {using std::cout;cout<<G.vers[v].value;}
//
//template<class T>
//void Do_Trasver(Graph<T>& G, int v)
//{
//    using std::cout;
//    using std::endl;
//    Visit(G, v);
//    for (int i=0; i<G.numVertex; i++)
//    {
//        if (G.arr[v][i])
//            Visit(G, i);
//    }
//    cout<<endl;
//}
//
//
//template<class T>
//void Graph_Trasver(Graph<T>& G)
//{
//    //DFS(G,0);
//    for (int i=0; i<G.VerticesNum(); i++)
//        G.Mark[i]=UNVISITED;
//    for (int i=0; i<G.VerticesNum(); i++)
//        if (G.Mark[i]==UNVISITED)
//            BFS(G, i);
//    //DFS(G,i);
//    //Do_Trasver(G,i);
//    
//    
//}
//
//template<class T>
//void DFS(Graph<T>& G,int v)
//{
//    G.Mark[v]=VISITED;
//    Visit(G,v);
//    for (Edge e=G.FirstEdge(v); G.IsEdge(e); e=G.NextEdge(e))
//    {
//        if (G.Mark[G.ToVertex(e)]==UNVISITED)
//            DFS(G, G.ToVertex(e));
//    }
//    //PostVisit(G,v);
//}
//template<class T>
//void BFS(Graph<T>&G, int v){
//    using std::queue;
//    queue<int> Q;
//    Visit(G,v);
//    G.Mark[v]=VISITED;
//    Q.push(v);
//    while (!Q.empty())
//    {
//        int u=Q.front();
//        Q.pop();
//        for (Edge e=G.FirstEdge(u); G.IsEdge(e); e=G.NextEdge(e))
//        {
//            if (G.Mark[G.ToVertex(e)]==UNVISITED)
//            {
//                Visit(G, G.ToVertex(e));
//                G.Mark[G.ToVertex(e)]=VISITED;
//                Q.push(G.ToVertex(e));
//            }
//        }
//    }
//}
//
//int main()
//{
//    int from[10];
//    int to[10];
//    int ve[10];
//    int n=5;
//    int e=8;
//    for (int i=0; i<5; i++)
//        ve[i]=i+1;
//    from[0]=1;to[0]=2;
//    from[1]=2;to[1]=3;
//    from[2]=1;to[2]=3;
//    from[3]=1;to[3]=5;
//    from[4]=4;to[4]=3;
//    from[5]=3;to[5]=2;
//    from[6]=4;to[6]=2;
//    from[7]=2;to[7]=5;
//    Graph<int> G(ve,5,from,to,8);
//    G.print();
//    
//}