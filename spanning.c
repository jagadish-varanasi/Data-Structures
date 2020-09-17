#include<stdio.h>
#define I 30000
int cost[][8]={
    {I,I,I,I,I,I,I,I},
    {I,I,25,I,I,I,5,I},
    {I,25,I,12,I,I,I,10},
    {I,I,12,I,8,I,I,I},
    {I,I,I,8,I,16,I,14},
    {I,I,I,I,16,I,20,18},
    {I,5,I,I,I,20,I,I},
    {I,I,10,I,14,18,I,I}
};
int near[8]={I,I,I,I,I,I,I,I};
int spanning[2][7];

void main(){
    int i,j,min,u,v,k,n=7;
    min=I;
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
             if(cost[i][j]<min){
                 min=cost[i][j];
                 u=i;
                 v=j;
             }
        }
    }

    //printf("The minimum edge in tree is(%d,%d)",u,v);

    spanning[0][0]=u;
    spanning[1][0]=v;
    near[u]=0;
    near[v]=0;
    for(i=1;i<=n;i++){
        if(near[i]!=0){
        if(cost[i][u]<cost[i][v]){
            near[i]=u;
        }else

        {
            near[i]=v;
        }
        }
    }

    for(i=1;i<n-1;i++){
        min=I;
        for(j=1;j<=n;j++){
            if(near[j]!=0&&cost[j][near[j]]<min){
                min=cost[j][near[j]];
                k=j;
            }
        }
        spanning[0][i]=k;
        spanning[1][i]=near[k];
        near[k]=0;

        for(j=1;j<=n;j++){
           if(near[j]!=0&&cost[j][k]<cost[j][near[j]]){
               near[j]=k;
           }
        }
    }
    
    for(i=0;i<n-1;i++){
        printf("(%d %d)",spanning[0][i],spanning[1][i]);
    }


}

