//
//  week8_2.cpp
//  Structure
//
//  Created by Song on 1/19/16.
//  Copyright © 2016 Song. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int num_v;
int num_e;
struct compare
{
    bool operator()(const int&l, const int &r) {return l>r;}
};
vector<vector<int> > vec(1000);
int indegree[100];
int mark[100];
void topgrapsort()
{
    memset(mark, 0, sizeof(mark));
    
    priority_queue<int,vector<int>,compare> que;
    for (int i=1; i<=num_v; i++)
    {
        if (indegree[i]==0)
            que.push(i);
    }
    while (!que.empty())
    {
        int i=que.top();
        que.pop();
        mark[i]=1;
        cout<<"v"<<i<<" ";
        for (int j=0; j<vec[i].size(); j++)
        {
            int k=vec[i][j];
            indegree[k]--;
            if (indegree[k]==0) que.push(k);
        }
    }
    cout<<endl;
    
    for (int i=1; i<=num_v; ) {
        if (mark[i]==0)
            cout<<"此图环状"<<endl;
        break;
    }

}

int main()
{
   
    cin>>num_v;
    cin>>num_e;
    int x,y;
    memset(indegree, 0, sizeof(indegree));
    while (num_e--)
    {
        cin>>x;
        cin>>y;
        vec[x].push_back(y);
        indegree[y]++;
    }
    topgrapsort();
}