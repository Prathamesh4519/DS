#include <stdio.h>
#include <stdlib.h>
 struct list
 {
    int data;
    struct list*next;
 };
 void LinkedListTraversal(struct list*ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
    void insert(int n,struct list*ptr,int value){
        int i=0;
        struct list*node=(struct list*)malloc(sizeof(struct list));
        while (i!=n-1)
        {
            ptr=ptr->next;
            i++;
        }
        node->data=value;
       node->next=ptr->next;
       ptr->next=node;
    }
    void print(struct list*ptr){
        while (ptr!=NULL)
        {
            printf("%d",ptr->data);
            ptr=ptr->next;
        }
         
    }

    

 
  int main(){
    struct list*head=(struct list*)malloc(sizeof(struct list));
    struct list*second=(struct list*)malloc(sizeof(struct list));
    struct list*third=(struct list*)malloc(sizeof(struct list));
    struct list*fourth=(struct list*)malloc(sizeof(struct list));

    head->data=17;
    head->next=second;
    second->data=15;
    second->next=third;
    third->data=17;
    third->next=fourth;
    fourth->data=17;
    fourth->next=NULL;
print(head);  
 int n;
 scanf("%d",&n);
 int value;
 scanf("%d",&value); 
 insert(n,head,value);
 LinkedListTraversal(head);
 return 0; 
  }