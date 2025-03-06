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
list* delete(list*pt,int k,int n)
{
    list*head=pt;
if(k==1){
    list*let =pt;
    pt = pt->next;
    free(let);
    return pt;}
    else if (k>1&&k<=n)
    {int i=0;
        while (i!=k)
        {
            pt=pt->next;
            i++;
        }
        list*let=pt->next;
        pt->next=let->next;
        free(let);
        return head;
    }
    
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
    int k;
    printf("Enter the node to be deleted");
    scanf("%d",&k);
    head=delete(head,k,n);
    print(head);
    return 0;
}