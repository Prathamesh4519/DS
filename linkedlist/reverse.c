#include <stdio.h>
#include <stdlib.h>

struct listnode
{
    int data;
    struct listnode *next;
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
    
       void print(list *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
list *reverse(list*pt,int n){
    list*temp= pt->next->next;
   pt->next->next=pt;
   pt->next=temp;
    free(temp);
return ;
}

int main()
{
    list *head = (list *)malloc(sizeof(list));
    if (head == NULL)
    {
        printf("No Space Available");
        exit(0);
    }
    int n;
    printf("Enter the number of elements in linked list");
    scanf("%d", &n);
    create(head, n);
    print(head);
   head= reverse(head,n);
    print(head);
return 0;
}