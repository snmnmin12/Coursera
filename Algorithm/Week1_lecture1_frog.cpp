//
//  Week1_lecture1_frog.cpp
//  Algorithm
//
//  Created by Song on 11/30/15.
//  Copyright © 2015 Song. All rights reserved.
//
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <algorithm>
//using namespace std;
//int r,c,n;
//struct PLANT{
//    int x,y;
//};
//PLANT plants[5001];
//PLANT plant;
//int searchPath(PLANT secPlant, int dX,int dY);
//
//int main()
//{
//    int i,j,dX,dY,pX,pY,steps,max=2;
//    scanf("%d %d", &r,&c);
//    scanf("%d",&n);
//    for (int i=0; i<n; i++)
//    scanf("%d %d", &plants[i].x,&plants[i].y);
//    
//    sort(plants,plants+n);
//    
//    for (i=0; i<n-2; i++)//plants[i]是第一个点
//        for (j=i+1; j<n-1; j++) {//plants[j]是第二个点
//            dX=plants[j].x-plants[i].x;
//            dY=plants[j].y-plants[i].y;
//            pX=plants[i].x-dX;
//            pY=plants[i].y-dY;
//            if (pX<=r && pX>=1 && pY<=c && pY>=1)
//                continue;
//            //第一点的前一点在稻田里,
//            //说明本次选的第二点导致的x方向步长不合理(太小)
//            // 取下一个点作为第二点
//            if (plants[i].x+(max-1)*dX>r)
//                break;
//            pY=plants[i].y+(max-1)*dY;
//            if (pY>c||pY<1)
//                continue;
//            steps=searchPath(plants[j], dX, dY);
//            if (steps>max) max=steps;
//        }
//    if (max==2) max=0;
//    printf("%d\n",max);
//    return 0;
//}
//bool operator<(const PLANT & p1, const PLANT & p2)
//{
//       if(p1.x==p2.x)
//       return p1.y<p2.y;
//       return p1.x<p2.x;
//}
//int searchPath(PLANT secPlant,int dX, int dY)
//{
//    PLANT plant;
//    int steps;
//    plant.x=secPlant.x+dX;
//    plant.y=secPlant.y+dY;
//    steps=2;
//    while (plant.x<=r && plant.x>=1 && plant.y<=c && plant.y>=1) {
//        if(!binary_search(plants, plants+n,plant)){
//            steps=0;
//            break;
//        }
//    plant.x+=dX;
//    plant.y+=dY;
//    steps++;
//    }
//    return steps;
//}