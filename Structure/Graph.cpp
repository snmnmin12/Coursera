//
//  Graph.cpp
//  Structure
//
//  Created by Song on 1/18/16.
//  Copyright © 2016 Song. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include "minHeap.cpp"
using namespace std;
#define UNVISITED 0
#define VISITED 1
#define INFINITY 1<<20
class Edge;
template<class T>
class Vertex
{
public:
    T value;
    Edge *first;
    Vertex() {first=0;}
    Vertex(T& val) {value=val;first=0;}
};
class Edge{
public:
    int node;
    Edge *next;
    int weight;
    Edge(){
        node=-1;next=0;weight=0;
    }
    Edge(int n,int w=1){
        node=n;next=0; weight=w;
    }
    void setWeight(int w){weight=w;}
};
template <class T>
class Graph{
public:
    Graph(){Mark=0;Indegree=0;vers=0;}
    Graph(T* arr, int v);
    void Insert(T* from, T* to, int k,int* w=0);
    ~Graph();
    int findIndex(T& val);
    void Graph_Trasver();
    int VerticesNum(){return numVertex;}
    int EdgesNum(){return numEdge;}
    Edge FirstEdge(int oneVertex);
    Edge NextEdge(Edge preEdge);
    bool IsEdge(Edge oneEdge);
    int ToVertex(Edge e) {return e.node;}
    int  Weight(Edge oneEdge) {return oneEdge.weight;}
    void Visit(int v) {using std::cout;cout<<vers[v].value;}
    void BFS(int i);
    void DFS(int i);
    void print();
public:
    int numVertex;
    int numEdge;
    int *Mark;
    int *Indegree;
    Vertex<T> *vers;
    //新边
    Edge* edge;
    //无相图
    Edge* edge2;
    //相邻矩阵
    int** array;
};
template<class T>
Graph<T>::Graph(T* ar, int numVert)
{
    numVertex=numVert;
    numEdge=0;
    Indegree=new int[numVertex];
    Mark=new int[numVertex];
    vers=new Vertex<T>[numVert];
    for (int i=0;i<numVertex;i++)
    {
        Mark[i]=UNVISITED;
        Indegree[i]=0;
        vers[i].value=ar[i];
        vers[i].first=0;
        array=new int*[numVertex];
    }
    for (int i=0;i<numVertex;i++)
        array[i]=new int [numVertex];
}
template<class T>
void Graph<T>::Insert(T* from, T* to,int k, int* w)
{
    numEdge=k;
    edge=new Edge[numEdge];
    for (int i=0; i<numEdge; i++)
    {
        T u=from[i];
        T v=to[i];
       
        int j=findIndex(u);
        int k=findIndex(v);
        edge[i].node=k;
        edge[i].next=vers[j].first;
        vers[j].first=&edge[i];
        Indegree[k]++;
        if (w!=0) edge[i].weight=w[i];
    }

      // 无相图的构造
//    edge2=new Edge[numEdge];
//      
//    for (int i=0; i<numEdge; i++)
//    {
//        T u=from[i];
//        T v=to[i];
//        int j=findIndex(u);
//        int k=findIndex(v);
//        edge2[i].node=j;
//        edge2[i].next=vers[k].first;
//        vers[k].first=&edge2[i];
//        Indegree[j]++;
//        if (w!=0) edge2[i].weight=w[i];
//    }
    
    
    //邻接矩阵的构造
    
//    for (int i=0; i<numEdge; i++)
//    {
//        T u=from[i];
//        T v=to[i];
//        
//        int j=findIndex(u);
//        int k=findIndex(v);
//        
//        if (w!=0)
//        {
//            array[j][k]=w[i];
//            array[k][j]=w[i];
//        }
//        else{
//            array[j][k]=1;
//            array[k][j]=1;
//        }
//       
//        Indegree[k]++;
//    }

}
template<class T>
int Graph<T>::findIndex(T& val)
{

    int i=0;
    while (vers[i].value!=val && i<numVertex) i++;
    if (i<numVertex) return i;
    else return -1;
}
template<class T>
Graph<T>:: ~Graph(){
/*链表结构
//    delete [] Mark;
//    delete [] Indegree;
//   
//    for (int i=0;i<numVertex; i++)
//    {
//        Edge* e=FirstEdge(i);
//        while (e!=NULL)
//        {
//            e=e->next;
//            delete  e;
//        }
//    }
//    delete [] vers;
 链表结构*/
    delete [] Mark;
    delete [] Indegree;
    delete [] vers;
    delete [] edge;
}
template<class T>
bool Graph<T>::IsEdge(Edge oneEdge){
    if (oneEdge.weight>=0 && oneEdge.weight<INFINITY && oneEdge.node >=0)
     return true;
    else return false;
}

template<class T>
Edge Graph<T>::FirstEdge(int oneVertex)
{
    if(vers[oneVertex].first)
        return *vers[oneVertex].first;
    return Edge();
}
template<class T>
Edge Graph<T>::NextEdge(Edge preEdge)
{
    if(preEdge.next!=NULL)
        return *preEdge.next;
   return  Edge();
}
template<class T>
void Graph<T>:: print()
{
    for (int i=0; i<numVertex; i++)
    {
        std::cout<<i+1<<" "<<vers[i].value;
        if (vers[i].first==NULL)
            std::cout<<std::endl;
        else cout<<vers[i].first->node<<std::endl;
    }
   
    Edge* p;
    for (int i=0;i<numEdge; i++)
    {
        std::cout<<i+1<<": "<<edge[i].node<<": ";
        p=edge[i].next;
        while (p!=NULL)
        std::cout<<p->node<<" ";
    }

}

template<class T>
void Graph<T>::Graph_Trasver()
{
    //DFS(G,0);
    for (int i=0; i<VerticesNum(); i++)
        Mark[i]=UNVISITED;
    for (int i=0; i<VerticesNum(); i++)
    {
        Edge e=FirstEdge(i);
        Visit(i);
        while (e.node>=0)
        {
            Visit(ToVertex(e));
            e=NextEdge(e);
        }
        std::cout<<std::endl;
    
    
        if (Mark[i]==UNVISITED)
            BFS(i);
    }
    cout<<endl;
    for (int i=0; i<VerticesNum(); i++)
        Mark[i]=UNVISITED;
    
    for (int i=0; i<VerticesNum(); i++)
    if (Mark[i]==UNVISITED)
    DFS(i);
    //cout<<endl;
    
}

template<class T>
void Graph<T>:: DFS(int v)
{
    Mark[v]=VISITED;
    Visit(v);
    for (Edge e=FirstEdge(v); IsEdge(e); e=NextEdge(e))
    {
        if (Mark[ToVertex(e)]==UNVISITED)
            DFS(ToVertex(e));
    }
    //PostVisit(G,v);
}
template<class T>
void Graph<T>::BFS(int v){
    using std::queue;
    queue<int> Q;
    //priority_queue<int,vector<int>, greater<int> > Q;
    Visit(v);
    Mark[v]=VISITED;
    Q.push(v);
    while (!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for (Edge e=FirstEdge(u); IsEdge(e); e=NextEdge(e))
        {
            if (Mark[ToVertex(e)]==UNVISITED)
            {
                Visit(ToVertex(e));
                Mark[ToVertex(e)]=VISITED;
                Q.push(ToVertex(e));
            }
        }
    }
}
template<class T>
void TopsortbyQueue(Graph<T>&G)
{
    for (int i=0; i<G.VerticesNum(); i++) G.Mark[i]=UNVISITED;
    using std::queue;
   // queue<int> Q;
    priority_queue<int,vector<int>, greater<int> > Q;
    for (int i=0; i<G.VerticesNum(); i++)
        if (G.Indegree[i]==0) Q.push(i);
    while (!Q.empty())
    {
        //int v=Q.front();
        int v=Q.top();
        Q.pop();
        G.Visit(v);
        //cout<<"v"<<G.vers[v].value<<" ";
        G.Mark[v]=VISITED;
        for (Edge e=G.FirstEdge(v);
             G.IsEdge(e); e=G.NextEdge(e))
        {
            int j=G.ToVertex(e);
            G.Indegree[j]--;
            int k=G.Indegree[j];
            if (G.Indegree[j]==0) Q.push(j);
        }
    }
    
    for (int i=0; i<G.VerticesNum(); i++)
        if (G.Mark[i]==UNVISITED) {
            std::cout<<"此图有环";
            break;
        }

}
template<class T>
void Do_topsort(Graph<T>&G,int V, int *result, int& index)
{
    //G.Visit(V);
    G.Mark[V]=VISITED;
    for (Edge e=G.FirstEdge(V); G.IsEdge(e); e=G.NextEdge(e))
        if (G.Mark[G.ToVertex(e)]==UNVISITED)
            Do_topsort(G, G.ToVertex(e), result, index);
    result[index++]=V;
}

template<class T>
int* TopsortbyDFS(Graph<T>&G)
{
    for (int i=0; i<G.VerticesNum(); i++)
        G.Mark[i]=UNVISITED;
    int* result=new int[G.VerticesNum()];
    int index=0;
    for (int i=0; i<G.VerticesNum(); i++)
        if (G.Mark[i]==UNVISITED)
            Do_topsort(G, i, result, index);
    for (int i=G.VerticesNum()-1; i>=0; i--)
        G.Visit(result[i]);
         cout<<endl;
    for (int i=0;i<G.VerticesNum(); i++)
        G.Visit(result[i]);
    
        return result;
    
}

class Dist{
public:
    int index;
    int length;
    int pre;
    bool operator<(const Dist& dist) const{return length<dist.length;}
    bool operator==(const Dist& dist) const{return length==dist.length;}
};
template <class T>
void Dijistra(Graph<T>& G, int s, Dist*&D)
{
    D=new Dist[G.VerticesNum()];
    for (int i=0; i<G.VerticesNum(); i++)
    {
        G.Mark[i]=UNVISITED;
        D[i].index=i;
        D[i].length=INFINITY;
        D[i].pre=s;
    }
    D[s].length=0;
    MinHeap<Dist> H(G.EdgesNum());
    H.insert(D[s]);
    for (int i=0; i<G.VerticesNum(); i++)
    {
        bool FOUND=false;
        Dist d;
        while (!H.isEmpty())
        {
            H.removeMin(d);
            if (G.Mark[d.index]==UNVISITED)
            {
                FOUND=true;break;
            }
        }
    
       if (!FOUND) break;
        int v=d.index;
        G.Mark[v]=VISITED;
        for (Edge e=G.FirstEdge(v);
             G.IsEdge(e);
             e=G.NextEdge(e))
        {
            if (D[G.ToVertex(e)].length>(D[v].length+G.Weight(e)))
            {
                D[G.ToVertex(e)].length=D[v].length+G.Weight(e);
                D[G.ToVertex(e)].pre=v;
                Dist node=D[G.ToVertex(e)];
                H.insert(D[G.ToVertex(e)]);
                //cout<<true<<endl;
            }
        }
    }
}
template<class T>
void Dijkstar_P2P(Graph<T>& G){
    Dist** D=new Dist*[G.VerticesNum()];
    Dijistra(G, 0, D[0]);
    for (int i=0; i<G.VerticesNum(); i++)
    for (int i=0; i<G.VerticesNum();i++)
        Dijistra(G, i, D[i]);
}
template<class T>
void Floyd(Graph<T>&G,Dist**&D)
{
    int i,j,v;
    D=new Dist*[G.VerticesNum()];
    for (i=0; i<G.VerticesNum(); i++)
    D[i]=new Dist[G.VerticesNum()];
    
    for (i=0; i<G.VerticesNum(); i++)
    for (j=0; j<G.VerticesNum(); j++)
    {
        if (i==j)
        {
            D[i][j].length=0;
            D[i][j].pre=i;
        }else{
            D[i][j].length=INFINITY;
            D[i][j].pre=-1;
        }
    }
    
    for (v=0; v<G.VerticesNum();v++)
        for (Edge e=G.FirstEdge(v); G.IsEdge(e); e=G.NextEdge(e))
        {
            D[v][G.ToVertex(e)].length=G.Weight(e);
            D[v][G.ToVertex(e)].pre=v;
            
        }

    for (v=0; v<G.VerticesNum(); v++)
        for (i=0; i<G.VerticesNum(); i++)
            for (j=0; j<G.VerticesNum(); j++)
    {
        if (D[i][j].length>D[i][v].length+D[v][j].length)
        {
            D[i][j].length=D[i][v].length+D[v][j].length;
            D[i][j].pre=v;
            //D[v][j].pre;
        }
    }
}
template<class T>
void Prim(Graph<T>&G, int s, Edge*&MST)// s是始点，MST存边
{
    int MSTtag=0;   // 最小生成树的边计数
    MST=new Edge[G.VerticesNum()-1];// 为数组MST申请空间
    Dist*D;
    D=new Dist[G.VerticesNum()];// 为数组D申请空间
    
    for (int i=0;i<G.VerticesNum();i++)// 初始化Mark和D数组
    {
        G.Mark[i]=UNVISITED;
        D[i].index=i;
        D[i].length=INFINITY;
        D[i].pre=s;  // D[i].pre = -1 呢？
    }
    D[s].length=0;
    G.Mark[s]=VISITED;  // 开始顶点标记为VISITED
    int v=s;
   


}
//int main()
//{
//    using std::cin;
//    int n;
//    int k;
//    string vec[20];
//    string from[20];
//    string to[50];
//    int w[50];
//    cin>>n;
//    for (int i=0; i<n; i++)
//        cin>>vec[i];
//    cin>>k;
//    for (int i=0; i<k; i++)
//        cin>>from[i]>>to[i];//>>w[i];
//    Graph<string> G(vec,n);
//    G.Insert(from, to, k);
//    Dist** D;
//    Floyd(G,D);
//    for(int i=0;i<n;i++)
//    cout<<D[0][i].pre<<" ";
//    cout<<endl;
    //Dijkstar_P2P(G);
    //G.Graph_Trasver();
    //TopsortbyQueue(G);
    //cout<<endl;
    //TopsortbyDFS(G);
    //cout<<endl;
    
//        int from[10];
//        int to[10];
//        int ve[10];
//        int n=5;
//        int e=8;
//        for (int i=0; i<5; i++)
//            ve[i]=i+1;
//        from[0]=1;to[0]=2;
//        from[1]=2;to[1]=3;
//        from[2]=1;to[2]=3;
//        from[3]=1;to[3]=5;
//        from[4]=4;to[4]=3;
//        from[5]=3;to[5]=5;
//        from[6]=4;to[6]=2;
//        from[7]=2;to[7]=5;
//        Graph<int> G(ve,n);
//        G.Insert(from, to, e);
//        //G.print();
//        G.Graph_Trasver();
//    int a[6];
//    int N,M;
//    cin>>N>>M;
//    for (int i=0; i<N; i++)
//        a[i]=i+1;
//    int from[8],to[8];
//    for (int i=0; i<8; i++)
//        cin>>from[i]>>to[i];
//    Graph<int> G(a,6);
//    G.Insert(from, to, 8);
    //G.print();
    //TopsortbyQueue(G);
//}
