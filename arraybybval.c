#include<stdio.h>
struct new{
    int A[10];
};
//normal always arrays are passed by address as A from callin func to  A[] or A* in 
//called func....but when array is in structure we can pass by value.
void passbyvalue(struct new t,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\t",t.A[i]);
    }
}

int main(){
    struct new t1={{1,2,3,4,10}};
    passbyvalue(t1,5);
}