//
//  Minimum_Spanning_Tree.cpp
//  Structure
//
//  Created by Song on 1/24/16.
//  Copyright © 2016 Song. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;
#define INF 1<<20;
#define MAXIN_N 100
#define EDGE_N 500

class ParNode
{
public:
    int x;
    int parent;
};
class Par
{
public:
    Par(const int num); //make set
    int FindSet(const int i);
    int PathCompression(const int i);
    bool Union(const int i, const int j);
private:
    ParNode* arr;
    int Size;
    
};
Par::Par(const int num)
{
    Size=num;
    arr=new ParNode[Size];
    for (int i=0; i<Size; i++) {
        arr[i].x=i;
        arr[i].parent=i;
    }
}
int Par::FindSet(const int i)
{
    int k=i;
    while(arr[k].parent!=k)
        k=arr[k].parent;
    return k;
}
bool Par::Union(int i,int j)
{
    int pa1=FindSet(i);
    int pa2=FindSet(j);
    if (pa1!=pa2)
    {   arr[pa2].parent=pa1;
        return true;
    }
    return false;
}
int Par::PathCompression(const int i)
{
    
    int k=arr[i].parent;
    if (k==i) return k;
    else
        arr[i].parent=PathCompression(k);
    return arr[i].parent;
}

class edge
{
public:
    int from;
    int to;
    int weight;
    edge(int f=0, int t=0, int w=0){from=f;to=t;weight=w;}
    void set(int f,int t,int w){from=f;to=t;weight=w;}
    bool operator<(const edge &edge2) const{return weight>edge2.weight;}
};

template<class T>
class Graph
{
public:
    vector<T> vertices;
    vector<edge> edges;
    vector<list<edge>> arr;
    int num_vert;
    int num_edge;
    vector<edge> MST;
    Graph(int,int);
    int getIndex(T&);
    void insertvertex(T& el){vertices.push_back(el);}
    void insertedge(T&, T&, int w=1);
    void Kruska();
    void Prim(int );
};
template<class T>
Graph<T>::Graph(int nv, int ne)
{
    num_vert=nv;
    num_edge=ne;
//    vertices.resize(num_vert);
//    edges.resize(num_edge);
      arr.resize(num_vert);
      MST.resize(num_vert);
}

template<class T>
int Graph<T>::getIndex(T &val)
{
    int i;
    for (i=0; i<num_vert; i++)
        if (vertices[i]==val) break;
    return i;
}
template<class T>
void Graph<T>::insertedge(T& from, T& to, int weight)
{
    int indexf=getIndex(from);
    int indext=getIndex(to);
    edges.push_back(edge(indexf,indext,weight));
    arr[indexf].push_back(edge(indexf,indext,weight));
    arr[indext].push_back(edge(indext,indexf,weight));
}
template<class T>
void Graph<T>::Kruska()
{
    priority_queue<edge> aQueue;
    
    for (int i=0; i<num_edge; i++)
        aQueue.push(edges[i]);
    Par uset(num_vert);
    int k=1;
    while(k<num_vert)
    {
        edge tempedge=aQueue.top();
        aQueue.pop();
        int from=tempedge.from;
        int to=tempedge.to;
        
        if(uset.Union(from,to))
        {
            MST[k]=tempedge;
            k++;
        }
        
    }
    for (int i=1; i<num_vert; i++)
    cout<<MST[i].from<<" "<<MST[i].to<<" "<<MST[i].weight<<endl;
}
class Dis
{
public:
    int index;
    int key;
    int pre;
    bool visited;
    bool operator<(const Dis& dis)const {return key>dis.key;}
};
template<class T>
void Graph<T>::Prim(int r)
{
    //Dis dist[num_vert];
    vector<Dis> dist(num_vert);
    //vector<bool> visited(num_vert);
    //int key[num_vert];
    //int pre[num_vert];
    for (int i=0; i<num_vert; i++)
    {
        dist[i].index=i;
        dist[i].key=INF;
        dist[i].pre=-1;
        dist[i].visited=false;
    }
    int m=0;
    dist[r].key=0;
    priority_queue<Dis> aQueue;
    aQueue.push(dist[r]);
    while (!aQueue.empty())
    {
        Dis temp=aQueue.top();
        aQueue.pop();
        if (dist[temp.index].visited==true) continue;
        if (temp.pre!=-1)
        MST[m++]=edge(temp.pre,temp.index,temp.key);

        int j=temp.index;
        dist[j].visited=true;
        for (list<edge>::iterator it=arr[j].begin(); it!=arr[j].end();it++)
        {
            int to=it->to;
            if ( (dist[to].visited==false) && (dist[to].key>it->weight))
            {
                dist[to].key=it->weight;
                dist[to].pre=j;
                aQueue.push(dist[to]);
            }
        }
    }
    
    for (int i=0; i<num_vert-1; i++)
        cout<<vertices[MST[i].from]<<" "<<vertices[MST[i].to]<<" "<<MST[i].weight<<endl;
}
//int main()
//{
//    string vetex;
//    int num_v;
//    int num_e;
//    cin>>num_v>>num_e;
//    
//    Graph<string> G(num_v,num_e);
//    for (int i=0; i<num_v; i++)
//    {   cin>>vetex;
//        G.insertvertex(vetex);
//    }
//    
//    string f1, t1;
//    int w;
//    for (int i=0; i<num_e; i++)
//    {
//        cin>>f1;
//        cin>>t1;
//        cin>>w;
//        G.insertedge(f1, t1, w);
//    }
//    
//   // G.Kruska();
//    G.Prim(0);
//}