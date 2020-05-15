#include<stdio.h>
#include<stdlib.h>

struct  Node
{
   struct Node *prev;
   int data;
   struct Node *next;
};

struct Node *root=NULL;
void doublyinsert(struct Node *p,int ele){
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=ele;
    temp->prev=NULL;
    if(root==NULL){
         root=temp;
        temp->next=NULL;
    }
    else{
        temp->next=root;
        root->prev=temp;
        root=temp;
    }
}

void display(){
    struct Node *p=root;
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;

    }
}


void insertatpos(struct Node *p,int ele,int pos){
    struct Node *temp;
    int i;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=ele;
    temp->prev=NULL;
    if(root==NULL){
         root=temp;
        temp->next=NULL;
    }
    else if(pos==1){
        temp->next=root;
        root->prev=temp;
        root=temp;
    }else
    {
     for(i=0;i<pos-1;i++){
         p=p->next;
     }
     temp->next=p->next;
     temp->prev=p;
     p->next->prev=temp;
     p->next=temp;



    }
}
int deleteNode(struct Node *p,int pos){
   int i;int x;
   struct Node *q;
   if(pos==0){
       q=root;
       root=root->next;
        x=q->data;
         free(q);
         if(root)
           root->prev=NULL;
      
   }
   else{
       for(i=0;i<pos-1;i++){
           p=p->next;
       }
       if(p->next)
         p->next->prev=p->prev;
       p->prev->next=p->next;
       x=p->data;
       free(p);
   }
   return x;
}




int main(){
    int ele;
    int ch;
    int pos;
    int dele;

     do{
     printf("Enter the elements to be inserted\n");
        scanf("%d",&ele);
       doublyinsert(root,ele);
     printf("Enter 0 to exit::::::::");
        scanf("%d",&ch);
    }while(ch!=0);
    do{
     printf("Enter the elements to be inserted\n");
        scanf("%d",&ele);
     printf("Enter the position at which element need to be inserted\n");
         scanf("%d",&pos);   
         insertatpos(root,ele,pos);
    
     printf("Enter 0 to exit::::::::");
        scanf("%d",&ch);
    }while(ch!=0);
     display();  

     printf("\nEnter the positon at which element need to be deleted\n");
       scanf("%d",&pos);
     dele=deleteNode(root,pos); 
     printf("Deleted element is %d\n",dele);
      display();

}
