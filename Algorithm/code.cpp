
//
//#include <stdio.h>
//#include <algorithm>
//#include <stdlib.h>
//#include <memory.h>
//#define MAXIN 100
//#define inf 10000
//char puzzle[MAXIN+2][MAXIN+2];
//int ministep=inf,w,h,step=0;
//int begin_x,begin_y,end_x,end_y;
//int to[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
////int to[4][2]={ {0,-1},{-1,0},  {1,0},{0,1}};
//unsigned int mark[MAXIN+2][MAXIN+2];
//bool visit[MAXIN+2][MAXIN+2];
//using std::min;
//bool Search(int now_x, int now_y, int end_x,int end_y){
//    
//   // if (ministep<=step) return false;
//    
//    if (now_x==end_x && now_y==end_y) {
//        if (step<ministep)
//            ministep=step;
//        return true;
//    }
//    for (int i=0; i<4; i++)
//    {
//        int x=now_x+to[i][0];
//        int y=now_y+to[i][1];
//        if ((x>-1) && (x<w+2) && (y>-1)&&(y<h+2)
//            &&((puzzle[y][x]!='#')))
//        {
//            //mark[y][x]=min(mark[y][x],mark[now_y][now_x]+1);
//           // if(mark[y][x]>mark[now_y][now_x]+1){
//            if(mark[y][x]==inf){
//                mark[y][x]=mark[now_y][now_x]+1;
//                step+=1;
//                //if(Search(x, y, end_x, end_y))
//                Search(x, y, end_x, end_y);
//                    //return true;
//                step-=1;
//                }
//         }
//    }
//    
//   return false;
//}
//int main(){
//    freopen("data.txt", "r", stdin);
//    //freopen("out.txt", "w", stdout);
//    scanf("%d %d",&h,&w);
//    int i,j;
//    for (i=0; i<MAXIN+2; i++) puzzle[0][i]=puzzle[i][0]='#';
//    for (i=1; i<=h; i++)
//        for (j=1; j<=w; j++)
//        {   scanf(" %c",&puzzle[i][j]);
//            mark[i][j]=inf;
//        }
//    
//    for (i=0; i<=w; i++) puzzle[h+1][i+1]='#';
//    for (i=0; i<=h; i++) puzzle[i+1][w+1]='#';
//    begin_x=0,begin_y=0,end_x=0,end_y=0;
//    for (i=1; i<=h; i++)
//    for (j=1; j<=w; j++)
//        {    if (puzzle[i][j]=='S') {begin_x=j;begin_y=i;}
//            if (puzzle[i][j]=='T') {end_x=j;end_y=i;}
//        }
//    //memset(visit, -1, sizeof(visit));
//   // memset(mark,-1,sizeof(mark));
//    //visit[begin_x][begin_y]=true;
//    mark[begin_y][begin_x]=0;
//    Search(begin_x, begin_y, end_x, end_y);
//    if (ministep<inf) printf("%d\n",ministep);
//    else printf("Path impossible.\n");
//    fclose(stdin);
//   // fclose(stdout);
//    return 0;
//}








//
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//const int INF = 100000000;
//typedef pair<int, int> P;
//
//vector<vector<char> > maze; // 迷宫的字符串数组
//int N, M; // 行数, 列数
//int sx, sy; // 起始坐标
//int gx, gy; // 终点坐标
//vector<vector<int> > d; //到各个位置的最短距离的数组
//int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};  // 4个方向的移动向量
//
//int bfs(){
//    queue<P> que;
//    for(int i=0; i<N; i++){
//        d.push_back(vector<int>(M));
//        for(int j=0; j<M; j++){
//            d[i][j] = INF;
//        }
//    }
//    que.push(P(sx, sy));
//    d[sx][sy] = 0;
//    
//    while(que.size()){
//        P p = que.front();
//        que.pop();
//        if(p.first == gx && p.second == gy)
//            break;
//        for(int i=0; i<4; i++){
//            int nx = p.first + dx[i], ny = p.second + dy[i];
//            if(nx >= 0 && nx < N && ny >= 0 && ny < M
//               && maze[nx][ny] != '#' && d[nx][ny] == INF){
//                que.push(P(nx, ny));
//                d[nx][ny] = d[p.first][p.second] + 1;
//            }
//        }
//    }
//    
//    return d[gx][gy];
//}
//
//int main(){
//    freopen("data.txt", "r", stdin);
//    cin >> N >> M;
//    for(int i=0; i<N; i++){
//        maze.push_back(vector<char>(M));
//        for(int j=0; j<M; j++){
//            cin >> maze[i][j];
//            if(maze[i][j] == 'S'){
//                sx = i;
//                sy = j;
//            } else if(maze[i][j] == 'T'){
//                gx = i;
//                gy = j;
//            }
//        }
//    }
//    
//    int res = bfs();
//    cout << res << endl;
//    fclose(stdin);
//    return 0;
//}
