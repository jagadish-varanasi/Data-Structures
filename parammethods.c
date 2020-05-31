#include <stdio.h>
struct Rectangle
{
    int len;
    int bre;
};

void initialize(struct Rectangle *r1, int l, int b)
{
    r1->len = l;
    r1->bre = b;
}

int area(struct Rectangle r)
{
    return r.len * r.bre;
}

void changebreath(struct Rectangle *r1, int val)
{
    r1->bre = val;
}

int main()
{
    struct Rectangle r;
    initialize(&r, 10, 20);
    printf("The Area of Rectangle %d \n", area(r));
    changebreath(&r, 25);
    printf("Modifide Breath %d \n", r.bre);
}