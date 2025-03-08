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
list *delete (list * pt, int k, int n)
{
    if (pt == NULL || k < 1 || k > n)
    {
        printf("Invalid position.\n");
        return pt;
    }

    list *head = pt;

    // If deleting the first node
    if (k == 1)
    {
        list *let = pt;
        pt = pt->next;
        free(let);
        return pt;
    }

    // Traverse to (k-1)th node
    list *prev = NULL, *current = pt;
    for (int i = 1; i < k; i++)
    {
        prev = current;
        current = current->next;
    }

    // If deleting the last node
    if (k == n)
    {
        prev->next = NULL;
        free(current);
        return head;
    }

    // If deleting a middle node
    prev->next = current->next;
    free(current);

    return head;
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