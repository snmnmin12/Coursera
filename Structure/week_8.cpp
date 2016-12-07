//
////
////  week_8.cpp
////  Structure
////
////  Created by Song on 1/17/16.
////  Copyright © 2016 Song. All rights reserved.
////
//
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
//    Edge *next;
//    Vertex() {next=NULL;}
//    Vertex(T& val) {value=val;next=NULL;}
//};
//class Edge{
//public:
//    int from,to;
//    int weight;
//    Edge(){
//        from=0;to=0;weight=0;
//    }
//    Edge(int f, int t,int w=1){
//        from=f;to=t;
//        if(f==t) weight=0;
//            else weight=w;
//    }
//};
//template <class T>
//class Graph{
//public:
//    Graph(){Mark=0;Indegree=0;vers=0;arr=0;}
//    Graph(T *arr,int, Edge* edge, int);
//    ~Graph();
//    void Graph_Trasver();
//    int VerticesNum();
//    int EdgesNum();
//    Edge FirstEdge(int oneVertex);
//    Edge NextEdge(Edge preEdge);
//    bool setEdge(int fromVertex, int toVertex, int weight) {arr[fromVertex][toVertex]=weight;}
//    bool delEdge(int fromVertex, int toVertex) {arr[fromVertex][toVertex]=0;}
//    bool IsEdge(Edge oneEdge);
//    int  FromVertex(Edge oneEdge){return oneEdge.from;}
//    int  ToVertex(Edge oneEdge) {return oneEdge.to;}
//    int  Weight(Edge oneEdge) {return oneEdge.weight;}
//public:
//    int numVertex;
//    int numEdge;
//    int *Mark;
//    int *Indegree;
//    Vertex<T> *vers;
//    int **arr ;
//};
//template<class T>
//Graph<T>::Graph(T *ar, int numVert, Edge* edge, int k){
//        numVertex=numVert;
//        numEdge=0;
//        Indegree=new int[numVertex];
//        Mark=new int[numVertex];
//        vers=new Vertex<T>[numVert];
//        for (int i=0;i<numVertex;i++)
//        {
//            Mark[i]=UNVISITED;
//            Indegree[i]=0;
//            vers[i].value=ar[i];
//        }
//    
//       arr=new int*[numVertex];
//       for (int i=0; i<numVertex; i++)
//        arr[i]=new int[numVertex];
//    
//    for (int i=0; i<numVertex; i++)
//    memset(arr[i], 0, sizeof(arr[i]));
//    
//     for (int i=0; i<k; i++)
//     {
//         int row=edge[i].from;
//         int col=edge[i].to;
//         arr[row][col]=edge[i].weight;
//     }
//}
//template<class T>
//Graph<T>:: ~Graph(){
//        delete [] Mark;
//        delete [] Indegree;
//        delete vers;
//    for (int i=0;i<numVertex; i++)
//        delete [] arr[i];
//}
//template<class T>
//int Graph<T>::VerticesNum(){
//        return numVertex;
//}
//template<class T>
//bool Graph<T>::IsEdge(Edge oneEdge){
//        if (oneEdge.weight>0 && oneEdge.weight<INFINITY && oneEdge.to>=0)
//            return true;
//        else return false;
//}
//
//template<class T>
//Edge Graph<T>::FirstEdge(int oneVertex)
//{
//    int j=oneVertex;
//    for (int i=0; i<numVertex; i++)
//        if (arr[oneVertex][i]!=0)
//        {j=i;break;}
//         
//            return Edge(oneVertex,j);
//}
//template<class T>
//Edge Graph<T>::NextEdge(Edge preEdge)
//{
//    int row=preEdge.from;
//    int col=preEdge.to;
//    int j=row;
//    for (int i=col+1; i<numVertex; i++)
//        if (arr[row][i]!=0)
//        {  j=i;break;}
//            return Edge(row,j);
//}
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
//        Visit(G, i);
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
//        for (int i=0; i<G.VerticesNum(); i++)
//            if (G.Mark[i]==UNVISITED)
//                BFS(G, i);
//                //DFS(G,i);
//            //Do_Trasver(G,i);
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
//              Visit(G, G.ToVertex(e));
//              G.Mark[G.ToVertex(e)]=VISITED;
//              Q.push(G.ToVertex(e));
//            }
//        }
//    }
//}
//int main()
//{
//    int n=7;
//    char vec[10];
//    for (int i; i<n; i++)
//        vec[i]='a'+i;
//    Edge edge[20];
//    edge[0]=Edge(0,1);
//    edge[1]=Edge(0,3);
//    edge[2]=Edge(0,4);
//    edge[3]=Edge(0,5);
//    edge[4]=Edge(1,2);
//    edge[5]=Edge(2,5);
//    edge[6]=Edge(3,2);
//    edge[7]=Edge(4,6);
//    edge[8]=Edge(6,2);
//    edge[9]=Edge(6,5);
//    Graph<char> G(vec,7,edge,10);
//    Graph_Trasver(G);
//}