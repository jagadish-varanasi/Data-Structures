#include<stdio.h>
#include<stdlib.h>

struct  Node
{
   struct Node *prev;
   int data;
   struct Node *next;
};

struct Node *head=NULL;
void doublyinsert(struct Node *p,int ele,int pos){
    struct Node *temp;
    int i;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=ele;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL){
         head=temp;
        head->next=head;
        head->prev=head;
    }
    else if(pos==1){
        temp->next=head;
        temp->prev=head->prev;
        head->prev=temp;
        temp->prev->next=temp;
        head=temp;
    }else if(pos>1){
        for(i=0;i<pos-1;i++){
            p=p->next;
        }
       temp->next=p->next;
       temp->prev=p;
       if(p->next)
       p->next->prev=temp;
       p->next=temp;

    }
}

void display(){
    struct Node *p=head;
    do{
        printf("%d\t",p->data);
        p=p->next;

    }while(p!=head);
}


int deleteNode(struct Node *p,int pos){
   int i;int x;
   struct Node *q;
   if(pos==0){
       q=head;
       head=head->next;
       head->prev=q->prev;
       head->prev->next=head;
        x=q->data;
         free(q);  
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

// void reversedll(struct Node *p){
//     struct Node *temp;
//     //by swaping the links we can reverse easily
//     p=head;
//     while(p!=NULL){
//         temp=p->next;
//         p->next=p->prev;
//         p->prev=temp;
//         p=p->prev;

//         if(p!=NULL&&p->next==NULL)
//           head=p;
//     }
// }




int main(){
    int ele;
    int ch;
    int pos;
    int dele;

     do{
     printf("Enter the elements to be inserted\n");
        scanf("%d",&ele);
     printf("Enter the position to be inserted\n");
        scanf("%d",&pos);   
       doublyinsert(head,ele,pos);
     printf("Enter 0 to exit::::::::");
        scanf("%d",&ch);
    }while(ch!=0);
    // do{
    //  printf("Enter the elements to be inserted\n");
    //     scanf("%d",&ele);
    //  printf("Enter the position at which element need to be inserted\n");
    //      scanf("%d",&pos);   
    //      insertatpos(head,ele,pos);
    
    //  printf("Enter 0 to exit::::::::");
    //     scanf("%d",&ch);
    // }while(ch!=0);
     display();  

     printf("\nEnter the positon at which element need to be deleted\n");
       scanf("%d",&pos);
     dele=deleteNode(head,pos); 
     printf("Deleted element is %d\n",dele);
      display();
    // printf("\n");
    //   reversedll(head);
    //   display();

}
