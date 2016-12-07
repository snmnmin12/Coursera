////
////  Week2_Prb22.cpp
////  Algorithm
////
////  Created by Song on 12/1/15.
////  Copyright © 2015 Song. All rights reserved.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//unsigned int clocks[9];
//int min=19683; //3^9;
//unsigned operations[9][9]={
//    // A B C D E F G H I
//    {1,1,0,1,1,0,0,0,0}, //op1
//    {1,1,1,0,0,0,0,0,0}, //op2
//    {0,1,1,0,1,1,0,0,0}, //op3
//    {1,0,0,1,0,0,1,0,0}, //op4
//    {0,1,0,1,1,1,0,1,0}, //op5
//    {0,0,1,0,0,1,0,0,1}, //op6
//    {0,0,0,1,1,0,1,1,0}, //op7
//    {0,0,0,0,0,0,1,1,1}, //op8
//    {0,0,0,0,1,1,0,1,1}  //op9
//};
//
//void clocl_op(unsigned int p[9],int i,int count)
//{
//    for (int j=0; j<9; j++)
//    {
//        p[j]+=operations[i][j]*count;
//        p[j]%=4;
//    }
//    
//}
//
//void coperation(){
//    
//    int temp;
//    unsigned int i,j,k;
//    unsigned int save[9]={0};
//    unsigned int save2[9]={0};
//    unsigned int clocks2[9];
//    bool success=false;
//    
//    //memcpy(clocks2,clocks,sizeof(unsigned)*9);
//    for (i=0; i<4; i++)
//    for (j=0; j<4; j++)
//    for (k=0; k<4; k++)
//    {       //success=false;
//         memcpy(clocks2,clocks,sizeof(unsigned)*9);
//        save[0]=i;save[1]=j;save[2]=k;
//        for (int p=0; p<7; p++)
//        {
//            if(p>2) save[p]=(4-clocks2[p-3])%4;
//            clocl_op(clocks2,p,save[p]);
//        }
//        save[8]=(4-clocks2[4])%4;
//        clocl_op(clocks2,8,save[8]);
//        save[7]=(4-clocks2[8])%4;
//        clocl_op(clocks2,7,save[7]);
//        
//        if (clocks2[5]==0 && clocks2[6]==0 && clocks2[7]==0) {
//                        success=true;
//                        temp=0;
//                        for (int m=0; m<9; m++) temp+=save[m];
//                        if (temp<min)
//                        {   min=temp;
//                            for (int m=0; m<9; m++) save2[m]=save[m];
//                        }
//                        }
//        
//        }
//    if (success) {
//    for (int b=0; b<9; b++)
//    {   if (save2[b]!=0)
//            for (int a=0; a<save2[b]; a++)
//                printf("%d ",b+1);
//    }
//    printf("\n");
//    }
//    else
//        printf("No found!");
//    
//}
//int main()
//{
//    //unsigned int clocks[3][3];
//    unsigned int i,j;
//    for (i=0; i<3; i++)
//        for (j=0;  j<3;j++)
//            scanf("%d",&clocks[j+3*i]);
//    coperation();
//    //printf("the shortest is %d",min);
//    
//    return 0;
//}