#include <stdio.h>
#include <stdlib.h>
struct listnode {
    int data;
    struct listnode* next;
};
typedef struct listnode list;



void create(list *ptr, int n)
{
    

    while (n>0)
    {

        printf("Enter the value\n");
        int value;
        scanf("%d", &value);
        ptr->data = value;
        if(n-1>0){
        ptr->next = (list *)malloc(sizeof(list));

        if (ptr->next == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(0);
        }
        ptr = ptr->next;}
        else{
            ptr->next=NULL;
        }
        n--;
    }

       }
void insert(int n,list*ptr,int value){
    int i=0;
    list*node=(struct list*)malloc(sizeof(list));
    while (i!=n-1)
    {
        ptr=ptr->next;
        i++;
    }
    node->data=value;
   node->next=ptr->next;
   ptr->next=node;
}

void print(list* ptr) {
    while(ptr!=NULL) {
        printf("%d,",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}


int main() {
    list* head=(list*)malloc(sizeof(list));
    if(head==NULL) {
        printf("Error,No space availed\n");
        exit(0);
    }
    int n;
    printf("Enter the number of elements in linked list \n");
    scanf("%d", &n);
    create(head, n);
    print(head);
    return 0;
}
