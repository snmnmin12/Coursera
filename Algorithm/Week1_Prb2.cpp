////
////  Week1_Prb2.cpp
////  Algorithm
////
////  Created by Song on 12/1/15.
////  Copyright © 2015 Song. All rights reserved.
////
//
//#include <stdio.h>
//unsigned int clocks[9];
//int min=19683; //3^9;
//unsigned operations[9][9]={
//    // A B C D E F G H I
//      {1,1,0,1,1,0,0,0,0}, //op1
//      {1,1,1,0,0,0,0,0,0}, //op2
//      {0,1,1,0,1,1,0,0,0}, //op3
//      {1,0,0,1,0,0,1,0,0}, //op4
//      {0,1,0,1,1,1,0,1,0}, //op5
//      {0,0,1,0,0,1,0,0,1}, //op6
//      {0,0,0,1,1,0,1,1,0}, //op7
//      {0,0,0,0,0,0,1,1,1}, //op8
//      {0,0,0,0,1,1,0,1,1}  //op9
//};
//
//unsigned int afteroperation[9];
//bool twleveclock;
//
//void coperation(){
//    
//    int temp;
//    unsigned int i,j,k,l,m,n,p,q,r;
//    unsigned int save[9]={0};
//    int judge=0;
//    for (i=0; i<4; i++)  //operation 1
//        for (j=0; j<4; j++)  //operation 2
//            for (k=0; k<4; k++)  //operation 3
//                for (l=0; l<4;l++)  //oeration 4
//                    for (m=0; m<4; m++) // operation 5
//                        for (n=0; n<4; n++) // operation 6
//                            for (p=0;p<4;p++)  //operation 7
//                                for (q=0; q<4;q++)  //operation 8
//                                    for (r=0; r<4; r++) // operation 9
//                                    {
//                                        twleveclock=1;
//                                        for (int a=0; a<9;a++)
//                                        afteroperation[a]=(clocks[a]+i*operations[0][a]+j*operations[1][a]+
//                                            k*operations[2][a]+l*operations[3][a]+m*operations[4][a]+n*operations[5][a]
//                                            +p*operations[6][a]+q*operations[7][a]+r*operations[8][a])%4;
//                                        
//                                        for (int a=0; a<9;a++)
//                                        {     twleveclock=(twleveclock&&afteroperation[a]==0);
//                                        if (!twleveclock)
//                                            break;
//                                        }
//                                        if (twleveclock)
//                                        {
//                                            temp=i+j+k+l+m+n+p+q+r;
//                                            if (temp<min)
//                                            {
//                                            min=temp;
//                                            save[0]=i; save[1]=j;save[2]=k;save[3]=l;save[4]=m;
//                                            save[5]=n; save[6]=p;save[7]=q;save[8]=r;
//                                            }
//                                            
//                                        }
//                                            
//                                    }
//    
//    for (int b=0; b<9; b++)
//        if (save[b]!=0)
//        {
//            for (int a=0; a<save[b]; a++)
//            printf("%d ",b+1);
//            judge=1;
//        }
//    if (judge==0) printf("No found!");
//    else printf("\n");
//
//}
//int main()
//{
//    //unsigned int clocks[3][3];
//    unsigned int i,j;
//    for (i=0; i<3; i++)
//    for (j=0;  j<3;j++)
//    scanf("%d",&clocks[j+3*i]);
//    coperation();
//    //printf("the shortest is %d",min);
//
//    return 0;
//}