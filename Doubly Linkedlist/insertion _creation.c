#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode* prev;
    struct ListNode* next;
};
typedef struct ListNode list;
void create(list *ptr, int n)
{
    ptr->prev=NULL;

    while (n>0)
    {

        printf("Enter the value\n");
        int value;
        scanf("%d", &value);
        ptr->data = value;
       
        
        if(n-1>0){
        ptr->next = (list *)malloc(sizeof(list));
        ptr->next->prev=ptr;

      
        ptr = ptr->next;
    }
        else{
            ptr->next=NULL;
        }
       
        n--;
    }}
    void print(list *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

       }
int main(){
    list* head=(list*)malloc(sizeof(list));
    if(head==NULL) {
        printf("Error,No space availed\n");
        exit(0);
    }
    int n;
    printf("Enter the number of elements in linked list \n");
    scanf("%d", &n);
    create(head,n);
    print(head);
}