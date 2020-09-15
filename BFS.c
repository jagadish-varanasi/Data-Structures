#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int *Q;
    int front;
    int rear;
};
struct Queue q;
void CreateQ(int size){
     q.Q=(int *)malloc(sizeof(int)*size);
     q.front=-1;
     q.rear=-1;
     q.size=size;
}

void EnQueue(int ele){
    if(q.rear==q.size-1){
        printf("Queue is full");
        return;
    }
      
    else{
         q.Q[++q.rear]=ele;
    }  
}

int DeQueue(){
    if(q.front==q.rear)
       return -1;
    else
    {
        return q.Q[++q.front];
    
    }
}

int isEmpty(){
    if(q.front==q.rear)
      return 1;
    else
      return 0;  
}

int visited[10]={0};
int A[7][7]={
    {0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0},
    {0,1,0,0,0,0,0},
    {0,1,0,0,1,0,0},
    {0,0,0,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};
void BFS(int ele){
    int u;
    printf("%d\t",ele);
    EnQueue(ele);
    visited[ele]=1;
    while (!isEmpty())
    {
         u=DeQueue();
         for(int v=1;v<=7;v++){
             if(A[u][v]==1&&visited[v]==0){
                 printf("%d\t",v);
                 visited[v]=1;
                 EnQueue(v);
             }
         }
    }
    
}





void main(){
    CreateQ(8);

    BFS(6);
}
