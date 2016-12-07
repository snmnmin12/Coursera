// /*This is the stardard code found from web for not using iteration*/
//#include <stdio.h>
////#include <algorithm>
//#include <queue>
//#include <stack>
//#include <set>
//
//
//#define MAXIN 100
//#define inf 1<<30
//using namespace std;
//int to[4][2]={ {0,-1},{-1,0},  {1,0},{0,1}};
//int h,w,maze[MAXIN][MAXIN];
//char puzzle[MAXIN][MAXIN];
//int pre[MAXIN][MAXIN];
//
//struct Point
//{
//    int x,y;
//    Point(int _x, int _y):x(_x),y(_y){}
//    void operator=(const Point p)
//    {
//        x=p.x;
//        y=p.y;
//    }
//};
//
//stack<Point> st;
//
//struct lessCompare{
//bool operator()( const Point &v1, const Point &v2) const
//{
//    if(v1.x!=v2.x)
//    return v1.x<v2.x;
//    else
//    return v1.y<v2.y;
//}
//};
//
//void printsta(stack<Point> & st)
//{
//    while (!st.empty()) {
//    printf("[%d][%d] ==>> [%2d]\n",st.top().x+1,st.top().y+1,maze[st.top().x][st.top().y]);
//        st.pop();
//    }
//
//}
//
//void solve(Point source, Point  desi)
//{
//    queue<Point> Q;
//    set<Point,lessCompare> S;
//    S.insert(source);
//    Q.push(source);
//
//    while(!Q.empty())
//    {
//        Point p = Q.front();
//        Q.pop();
//        if (p.x==desi.x && p.y==desi.y)
//        {
//            break ;
//        }
//        for(int m=0;m<4;m++)
//        {
//                int i = p.x+to[m][0];
//                int j = p.y+to[m][1];
//                if(i<0 || i>=h || j<0 || j>=w || maze[i][j]==-1) continue;
//                if(maze[i][j]>maze[p.x][p.y]+1)
//                {
//                    maze[i][j]=maze[p.x][p.y]+1; //Q.push(Point(i,j));
//                //maze[i][j]=min(maze[i][j],maze[p.x][p.y]+1);
////                if(S.find(Point (i,j))==S.end())
////                {
////                    S.insert(Point(i,j));
//                    Q.push(Point(i,j));
//                    //记忆 存储前面的
//                    pre[i][j]=p.x*w+p.y;
//                }
//        }
//    }
//    Point u=desi;
//    while (pre[u.x][u.y]!=-1) {
//        st.push(u);
//        u=Point(pre[u.x][u.y]/w,pre[u.x][u.y]%w);
//    }
//    st.push(u);
//}
//
//int main(int argc, char** argv)
//{
//    
//        freopen("data.txt", "r", stdin);
//       // freopen("out.txt", "w", stdout);
//        scanf("%d %d",&h,&w);
//        int i,j, si=0,sj=0,ei=0,ej=0;
////        for (i=0; i<MAXIN+2; i++) puzzle[0][i]=puzzle[i][0]='#';
//        for (i=0; i<h; i++)
//            for (j=0; j<w; j++)
//            {   scanf(" %c",&puzzle[i][j]);
//                if(puzzle[i][j]=='#') maze[i][j]=-1;
//                else if(puzzle[i][j]=='S') si=i,sj=j,maze[i][j]=0;
//                else if(puzzle[i][j]=='T') ei=i,ej=j,maze[i][j]=inf;
//                else maze[i][j]=inf;
//                pre[i][j]=-1;
//            }
//       solve(Point(si,sj),Point(ei,ej));
//       printsta(st);
//       printf("%d\n",maze[ei][ej]);
//    return 0;
//}
