#include<stdio.h>
int t[4][51];

int max(int n1,int n2){
    if(n1>n2){
        return n1;
    }
    else{
        return n2;
    }
}

int knapsack(int wt[],int val[],int W,int n){
    for(int i=0;i<=n;i++){
        t[0][i]=0;
    }
    for(int i=0;i<=W;i++){
        t[i][0]=0;
    }
   
   for(int i=1;i<=n;i++){
       for(int j=1;j<=W;j++){
           if(wt[i]<=j){
               t[i][j]=max(val[i]+t[i-1][j-wt[i-1]],t[i-1][j]);
           }
           else{
               t[i][j]=t[i-1][j];
           }
       }
   }
    return t[3][50];
}









void main(){
    int val[]={60,100,121};
    int wt[]={10,20,30};
    int W=50;
    printf("%d",knapsack(wt,val,W,3));
}