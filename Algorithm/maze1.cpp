//
///* this is to solve the maze to know the minmum number of transver in order to know maximum*/
//#include <stdio.h>
//#define MAXIN 100
//#define inf 10000
//char puzzle[MAXIN+2][MAXIN+2];
//int ministep,w,h;
//int to[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//unsigned int mark[MAXIN+2][MAXIN+2];
//bool visit[MAXIN+2][MAXIN+2];
//void Search(int now_x, int now_y, int end_x,int end_y){
////    if (mark[now_y][now_x]<inf && mark[now_y][now_x]!=0) return;
//    
//    if (now_x==end_x && now_y==end_y)
//        return;
//    
//    for (int i=0; i<4; i++)
//    {
//        int x=now_x+to[i][0];
//        int y=now_y+to[i][1];
//        if ((x>-1) && (x<w+2) && (y>-1)&&(y<h+2)
//            &&(puzzle[y][x]!='#'))
//        {
//            if (mark[y][x]>mark[now_y][now_x]+1)
//            {
//             mark[y][x]=mark[now_y][now_x]+1;
//             Search(x, y, end_x, end_y);
//            }
//        }
//    }
//}
//int main(){
////        freopen("data.txt", "r", stdin);
////        freopen("out.txt", "w", stdout);
//        scanf("%d %d",&h,&w);
//        int i,j;
//        for (i=0; i<MAXIN+2; i++) puzzle[0][i]=puzzle[i][0]='#';
//        for (i=1; i<=h; i++)
//        for (j=1; j<=w; j++)
//        {   scanf(" %c",&puzzle[i][j]);
//            mark[i][j]=inf;
//        }
//
//        for (i=0; i<=w; i++) puzzle[h+1][i+1]='#';
//        for (i=0; i<=h; i++) puzzle[i+1][w+1]='#';
//        int begin_x=0,begin_y=0,end_x=0,end_y=0;
//        for (i=1; i<=h; i++)
//        for (j=1; j<=w; j++)
//        {    if (puzzle[i][j]=='S') {begin_x=j;begin_y=i;}
//             if (puzzle[i][j]=='T') {end_x=j;end_y=i;}
//        }
//
//        mark[begin_y][begin_x]=0;
//        Search(begin_x, begin_y, end_x, end_y);
//          ministep=mark[end_y][end_x];
//        if (ministep<inf) printf("%d\n",ministep);
//        else printf("Path impossible.\n");
////        fclose(stdin);
////       fclose(stdout);
//    return 0;
//}
