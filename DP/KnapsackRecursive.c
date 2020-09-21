#include<stdio.h>

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

  if(wt[n-1]<=W)
    return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));

  if(wt[n-1]>W)
    return knapsack(wt,val,W,n-1);   

}


int main(){
    int val[]={60,100,120};
    int wt[]={10,20,30};
    int W=50;
    printf("%d",knapsack(wt,val,W,6));
}
