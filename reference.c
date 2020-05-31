#include<stdio.h>
struct Rectangle{
    int l;
    int b;
};
void initialize(struct Rectangle *r,int l,int b){
    r->l=l;
    r->b=b;
}

int area(struct Rectangle r){
    return r.l*r.b;
}

int main(){
     struct Rectangle r;
     initialize(&r,10,20);
     printf("The area is %d",area(r));
}