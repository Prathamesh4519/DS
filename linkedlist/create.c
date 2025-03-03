#include <stdio.h>
#include <stdlib.h>
struct listnode {
    int data;
    struct listnode* next;
};
typedef struct listnode list;



void create(list* ptr) {
   
    while(1) {
        printf("Enter the value\n");
        int value;
        scanf("%d",&value);
        ptr->data=value;
        printf("Do you want to continue?\n1.Yes\n");
        int choice;
        scanf("%d",&choice);
        if(choice==1) {
            ptr->next=(list*)malloc(sizeof(list));
            
            if (ptr->next == NULL) {
                printf("Memory allocation failed.\n");
                exit(0);
            }
            ptr=ptr->next;
        } else {
            ptr->next=NULL;
            break;
        }
    }
}
void insert(list*ptr){
    while (ptr!=NULL)
        {
            printf("%d",ptr->data);
            ptr=ptr->next;
        }
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
    create(head);
    print(head);
    return 0;
}
