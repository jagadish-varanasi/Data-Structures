#include<stdio.h>
#include<stdlib.h>
struct inheap{
    int len;
    int bre;
};
int main(){
    struct inheap *h;
     h=(struct inheap *)malloc(sizeof(struct inheap));
     h->len=10;
     h->bre=20;
     printf("%d\t",(*h).len);
     printf("%d",(*h).bre);
}
