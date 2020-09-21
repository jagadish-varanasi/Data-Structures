#include<stdio.h>
#include <string.h>
int t[100][100];



int max(int n1,int n2){
    if(n1>n2)
      return n1;
    else
      return n2;  
}

int knapsack(int wt[],int val[],int W,int n){
  //base condition
  if(W==0||n==0)
    return 0;

  if(t[n][W]!=-1)
    return t[n][W];  
   
  if(wt[n-1]<=W)
    return t[n][W]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));

  if(wt[n-1]>W)
    return t[n][W]=knapsack(wt,val,W,n-1);   

}


int main(){
  memset(t,-1,sizeof(t));
    int val[]={60,100,120};
    int wt[]={10,20,30};
    int W=50;
    printf("%d",knapsack(wt,val,W,3));

    // for(int i=0;i<3;i++){
    //   for(int j=0;j<50;j++){
    //     printf("%d\t",t[i][j]);
    //   }
    //   printf("\n");
    // }
}

