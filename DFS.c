#include<stdio.h>
int visited[8]={0};
int A[8][8]={
    {0,0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0,1},
    {0,1,0,1,0,0,1,0},
    {0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1},
    {0,0,1,0,0,0,0,0},
    {0,1,0,0,0,1,0,0}
    };

void DFS(int ele){
    if(visited[ele]==0){
        printf("%d\t",ele);
        visited[ele]=1;
        for(int v=1;v<=7;v++){
            if(A[ele][v]==1&&visited[v]==0){
                DFS(v);
            }
        }
    }
}

void main(){
    DFS(1);
}
