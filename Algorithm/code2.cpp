//#include <algorithm>
//#include <string>
//#include <queue>
//#include <vector>
//#include <iostream>
//#include <fstream>
//#include <set>
//
//using namespace std;
//int to[4][2]={ {0,-1},{-1,0},  {1,0},{0,1}};
//void print2D(vector<vector<int>> arr)
//{
//    for(int i=0;i<arr.size();++i)
//    {
//        for(int j=0;j<arr[0].size();++j)
//        {
//            cout << (arr[i][j]==(1<<30)?-9:arr[i][j]) << "   ";
//        }
//        cout << endl;
//    }
//}
//
//void solve(vector<vector<int>>& maze, int si, int sj, int ei, int ej)
//{
//    queue<pair<int,int>> Q;
//    set<pair<int,int>> S;
//    int M=maze.size(),N=maze[0].size();
//    S.insert(make_pair(si,sj));
//    Q.push(make_pair(si,sj));
//    
//    while(!Q.empty())
//    {
//        pair<int,int> p = Q.front();
//        Q.pop();
//        for(int m:{0,1,2,3})
//        {
//            
//                int i = p.first+to[m][0];
//                int j = p.second+to[m][1];
//                if(i<0 || i>=M || j<0 || j>=N || maze[i][j]==-1) continue;
//                maze[i][j]=min(maze[i][j],maze[p.first][p.second]+1);
//                if(S.find(make_pair(i,j))==S.end())
//                {
//                    S.insert(make_pair(i,j));
//                    Q.push(make_pair(i,j));
//                }
//        }
//    }
//}
//
//int main(int argc, char** argv)
//{
//    ifstream infile("data.txt");
//    string s;
//    int v=0,si=0,sj=0,ei=0,ej=0;
//    vector<vector<int>> maze;
//    int i=0;
//    while(infile >> s)
//    {
//        vector<int> row;
//        for(int j=0;j<s.size();++j)
//        {
//            if(s[j]=='S')
//            {
//                si=i;
//                sj=j;
//                row.push_back(0);
//            }
//            else if(s[j]=='T')
//            {
//                ei=i;
//                ej=j;
//                row.push_back((1<<30));
//            }
//            else
//            {
//                row.push_back((s[j]=='#'?-1:(1<<30)));
//            }
//        }
//        maze.push_back(row);
//        ++i;
//    }
//    
//    solve(maze,si,sj,ei,ej);
//   // print2D(maze);
//    cout << "Shortest distance to end: " << maze[ei][ej] << endl;
//    return 0;
//}
