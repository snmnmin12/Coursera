//
//  Min_Cut.cpp
//  Structure
//
//  Created by Song on 1/24/16.
//  This is to create a randomized method for mean cut
//  Copyright © 2016 Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
using namespace std;
class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;
    int root(int i) {while (parent[i]!=i) i=parent[i]; return i;}
public:
    UnionFind(int n)
    {
        for(int i=0;i<=n;i++)
        { parent.push_back(i);
        rank.push_back(0);
        }
    }
    int Find(int i)
    {
//        if (parent[i]!=i) {
//            parent[i]=Find(parent[i]);
//        }
        return root(i);
    }
    void Union(int i,int j)
    {
        if(Find(i)==Find(j)) return;
        int rootx=Find(i);
        int rooty=Find(j);
        parent[rooty]=rootx;
//        if (rank[rootx]>rank[rooty]) parent[rooty]=rootx;
//        else if(rank[rootx]<rank[rooty]) parent[rootx]=rooty;
//        else
//        {
//            parent[rooty]=rootx;
//            rank[rootx]++;
//        }
    }
};
class MinCut
{
private:
    vector<vector<int>> graph;
    vector<pair<int, int>> edge;
    vector<bool> visited;
    vector<bool> merged;
    vector<int> dist;
    vector<pair<int, int>> result;
    int n;
    int e;
    void dps(int n);
public:
    void init()
    {
        fill(visited.begin(), visited.end(),false);
        fill(dist.begin(), dist.end(), 0);
    }
    bool connectivity();
    void Create();
    int Contraction();
    int Contract(vector<vector<int>>& , int& , int&);
    int Stoer_Wagner();
    void Run();
};
void MinCut::Create()
{
    int a,b,w;
    cin>>n;
    cin>>e;
    graph.resize(n+1);
    edge.resize(e+1);
    for (int i=1; i<=e;i++)
    fill(graph[i].begin(), graph[i].end(), 0);
    for (int i=1; i<=n;i++) graph[i].resize(n+1);
    for (int i=1; i<=e; i++)
    {
        cin>>a>>b>>w;
        edge[i]=make_pair(a, b);
        graph[a][b]+=w;
        graph[b][a]+=w;
    }
    visited.resize(n+1);
    merged.resize(n+1);
    dist.resize(n+1);
}
int MinCut::Contraction()
{
    init();
    vector<int> pre(n+1);
    //initial the values in the begining
    for (int i=0; i<=n;i++) pre[i]=i;
    for (int i=0; i<=n;i++) merged[i]=false;
    
    vector<vector<int> > graph2=graph;
    vector<pair<int, int>> edgetemp=edge;
    UnionFind uf(n);
    
    int edgenum=e;
    int v=n;
    int num;
    int a,b;
    while (v>2)
    {
        num=rand()%edgenum+1;
        a=edgetemp[num].first;
        b=edgetemp[num].second;
        //delete the random selected edge
        edgetemp.erase(edgetemp.begin()+num);
        edgenum--;
//        a=s;
//        b=t;
        //we have to search the repsentative point in the set of all contracted points
//        while (pre[a]!=a) a=pre[a];
//        while (pre[b]!=b) b=pre[b];
        a=uf.Find(a);
        b=uf.Find(b);
        // a==b means the two points has been already contracted, no need to consider again
        if(a==b) continue;
        
        uf.Union(a, b);
        //remove point b, but we have to keep point b information
        //pre[b]=a;
        //a=s;b=t;
        //make the point b as merged
         merged[b]=true;
        
        // now we will add all the column information of b into column a
        for (int j=1; j<=n; j++)
        {
            if(!merged[j])
            {
            graph2[a][j]+=graph2[b][j];
            graph2[j][a]+=graph2[j][b];
            }
        }
        v--;
    }
   
//    int p,q;
//    p=q=0;
    int p=uf.Find(1);
    int q=p;
    for (int i=2; i<=n; i++)
    {
        q=uf.Find(i);
        if (q!=p) break;
    }
//    for (int i=1; i<=n; i++)
//        if (!merged[i]){p=q;q=i;}
    vector<int> vec1;
    vector<int> vec2;
    //we need to break the vertices into two set p and q
    for (int i=1; i<=n; i++)
        if (uf.Find(i)==p) vec1.push_back(i);
        else vec2.push_back(i);
    // check each item in p and q to know the connection
    result.clear();
    for(int i=0; i<vec1.size();i++)
        for (int j=0; j<vec2.size(); j++)
        {
            if (graph[vec1[i]][vec2[j]]!=0)
                result.push_back(make_pair(vec1[i],vec2[j]));
        }
    int minc=graph2[p][q];
    return minc;
}
bool MinCut::connectivity()
{
   
    fill(visited.begin(), visited.end(), false);
    dps(1);
    
    int i;
    for (i=1; i<n+1; i++)
    if(visited[i]==false) break;
    if(i==n+1) return true;
    else
    return false;
}
void MinCut::dps(int root)
{
    visited[root]=true;
    for (int i=1; i<=n; i++)
    {
        if (graph[root][i]!=0 && !visited[i])
            dps(i);
    }

}
void MinCut::Run()
{
    //Create();
    init();
    if (n<1)
    {  cout<<"No Cut"<<endl;
        //return 0;
    }
    if (!connectivity())
    {
        cout<<"Not connected!"<<endl;
        //return 0;
    }
    int minc=1<<20;
    vector<pair<int,int>> output;
    for (int i=0; i<10*n*n; i++)
        if(minc>Contraction())
        {
            minc=Contraction();
            output=result;
        }
    cout<<minc<<endl;
    for (int i=0; i<output.size(); i++)
        cout<<output[i].first<<" "<<output[i].second<<endl;
   // return minc;
}
int MinCut::Contract(vector<vector<int>>& vi,int &s, int &t)
{
    init();
    //fill(visited.begin(), visited.end(), 0);
    //fill(dist.begin(),dist.end(), 0);
    int k,mincut=0,maxc;
    for (int i=0; i<=n; i++)
    {
        k=-1;maxc=-1;
        for (int j=1; j<=n; j++)
        {
            if (!merged[j]&&!visited[j] && dist[j]>maxc) {
                k=j;
                maxc=dist[j];
            }
        }
        if (k==-1) return mincut;
        s=t;t=k;mincut=maxc;
        visited[k]=true;
        for (int j=1; j<=n; j++)
        {
            if (!merged[j] && !visited[j])
                dist[j]+=vi[k][j];
        }
    }
    return mincut;

}
//using the traditional way of finding the min-cut for this problem
int MinCut::Stoer_Wagner()
{
    fill(merged.begin(), merged.end(), 0);
    int mincut,i,j,s,t,ans;
    mincut=1<<10;
    vector<vector<int>> vvi=graph;
    for (i=1;i<n; i++)
    {
        ans=Contract(vvi, s, t);
        merged[t]=true;
        if (mincut>ans) mincut=ans;
        if (mincut==0) return 0;
        for (j=1; j<=n; j++)
        {
            if (!merged[j])
            {
            vvi[j][s]+=vvi[j][t];
            vvi[s][j]+=vvi[t][j];
            }
        }
    }
    //cout<<mincut<<endl;
    return mincut;
}
//int main()
//{
//    
//    srand(time(NULL));
//    MinCut example;
//    example.Create();
//    example.Run();
//    int k=example.Stoer_Wagner();
//    //cout<<j<<endl;
//    cout<<k<<endl;
//    return 0;
//};



 //Karger's algorithm to find Minimum Cut in an
 //undirected, unweighted and connected graph.
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//// a structure to represent a unweighted edge in graph
//struct Edge
//{
//    int src, dest;
//};
//
//// a structure to represent a connected, undirected
//// and unweighted graph as a collection of edges.
//struct Graph
//{
//    // V-> Number of vertices, E-> Number of edges
//    int V, E;
//    
//    // graph is represented as an array of edges.
//    // Since the graph is undirected, the edge
//    // from src to dest is also edge from dest
//    // to src. Both are counted as 1 edge here.
//    Edge* edge;
//};
//
//// A structure to represent a subset for union-find
//struct subset
//{
//    int parent;
//    int rank;
//};
//
//// Function prototypes for union-find (These functions are defined
//// after kargerMinCut() )
//int find(struct subset subsets[], int i);
//void Union(struct subset subsets[], int x, int y);
//
//// A very basic implementation of Karger's randomized
//// algorithm for finding the minimum cut. Please note
//// that Karger's algorithm is a Monte Carlo Randomized algo
//// and the cut returned by the algorithm may not be
//// minimum always
//int kargerMinCut(struct Graph* graph)
//{
//    // Get data of given graph
//    int V = graph->V, E = graph->E;
//    Edge *edge = graph->edge;
//    
//    // Allocate memory for creating V subsets.
//    struct subset *subsets = new subset[V+1];
//    
//    // Create V subsets with single elements
//    for (int v = 0; v <=V; ++v)
//    {
//        subsets[v].parent = v;
//        subsets[v].rank = 0;
//    }
//    
//    // Initially there are V vertices in
//    // contracted graph
//    int vertices = V;
//    
//    // Keep contracting vertices until there are
//    // 2 vertices.
//    while (vertices > 2)
//    {
//        // Pick a random edge
//        int i = rand() % E;
//        
//        // Find vertices (or sets) of two corners
//        // of current edge
//        int subset1 = find(subsets, edge[i].src);
//        int subset2 = find(subsets, edge[i].dest);
//        
//        // If two corners belong to same subset,
//        // then no point considering this edge
//        if (subset1 == subset2)
//            continue;
//        
//        // Else contract the edge (or combine the
//        // corners of edge into one vertex)
//        else
//        {
//            //printf("Contracting edge %d-%d\n",
//            //       edge[i].src, edge[i].dest);
//            vertices--;
//            Union(subsets, subset1, subset2);
//        }
//    }
//    
//    // Now we have two vertices (or subsets) left in
//    // the contracted graph, so count the edges between
//    // two components and return the count.
//    int cutedges = 0;
//    for (int i=0; i<E; i++)
//    {
//        int subset1 = find(subsets, edge[i].src);
//        int subset2 = find(subsets, edge[i].dest);
//        if (subset1 != subset2)
//            cutedges++;
//    }
//    
//    return cutedges;
//}
//
//// A utility function to find set of an element i
//// (uses path compression technique)
//int find(struct subset subsets[], int i)
//{
//    // find root and make root as parent of i
//    // (path compression)
//    if (subsets[i].parent != i)
//        subsets[i].parent =
//        find(subsets, subsets[i].parent);
//    
//    return subsets[i].parent;
//}
//
//// A function that does union of two sets of x and y
//// (uses union by rank)
//void Union(struct subset subsets[], int x, int y)
//{
//    int xroot = find(subsets, x);
//    int yroot = find(subsets, y);
//    
//    // Attach smaller rank tree under root of high
//    // rank tree (Union by Rank)
//    if (subsets[xroot].rank < subsets[yroot].rank)
//        subsets[xroot].parent = yroot;
//    else if (subsets[xroot].rank > subsets[yroot].rank)
//        subsets[yroot].parent = xroot;
//    
//    // If ranks are same, then make one as root and
//    // increment its rank by one
//    else
//    {
//        subsets[yroot].parent = xroot;
//        subsets[xroot].rank++;
//    }
//}
//
//// Creates a graph with V vertices and E edges
//struct Graph* createGraph(int V, int E)
//{
//    Graph* graph = new Graph;
//    graph->V = V;
//    graph->E = E;
//    graph->edge = new Edge[E];
//    return graph;
//}
//
//// Driver program to test above functions
//int main()
//{
//    /* Let us create following unweighted graph
//     0------1
//     | \    |
//     |   \  |
//     |     \|
//     2------3   */
//    /*
//     1---2---3---4
//     |  /|   |  /|
//     | / |   | / |
//     |/  |   |/  |
//     5---6---7---8
//
//     */
//    int V = 8;  // Number of vertices in graph
//    int E = 29;  // Number of edges in graph
//    struct Graph* graph = createGraph(V, E);
//    
//    // add edge 1-2
//    for (int i=0; i<E; i++)
//    scanf(" %d%d",&graph->edge[i].src,&graph->edge[i].dest);
//
//    
//    // Use a different seed value for every run.
//    int mincut=100000;
//    srand(time(NULL));
//    for (int i=0; i<1*V*V; i++)
//    {
//    int num=kargerMinCut(graph);
//    mincut=mincut<num?mincut:num;
//        printf("%d",mincut);
//        
//    }
//    printf("\nCut found by Karger's randomized algo is %d\n",
//           mincut);
//    
//    return 0;
//}