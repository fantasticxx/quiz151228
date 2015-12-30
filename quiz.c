#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define LENGTH 100
typedef struct _List {
    struct _List* next;
    int val;
} List;

List* create(int);
void print_list(List*);
List* initialize(List*);
List* bubble_sort(List*);
List* list_switch(List*,List*);
List* reverse(List*);

int main()
{
    List* newNode = NULL;
    List* curNode = NULL;
    List* head=NULL;
    //generate linkedlist
    for(int i=1; i<=LENGTH; i++) {
        newNode=create(i);
        if(curNode==NULL) {
            head=curNode=newNode;
        } else {
            curNode->next=newNode;
            curNode=curNode->next;
        }
    }
    //initialize
    head=initialize(head);
    printf("initislize\n");
    print_list(head);
    //reverse
    head=reverse(head);
    printf("reverse\n");
    print_list(head);
    //bubble sort
    head=bubble_sort(head);
    printf("bubble sort\n");
    print_list(head);
    return 0;
}

List* create(int val)
{
    List* node=(List*)malloc(sizeof(List));
    if(node==NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    node->val= val;
    node->next = NULL;

    return node;
}

void print_list(List* list)
{
    List* l=list;
    while(l) {
        printf("%d\t",l->val);

        l=l->next;
    }
    printf("\n");
}

List* initialize(List* list)
{
    int r;
    List* head=list;
    List* curNode=list;
    int tmp;
    srand(time(NULL));
    while(list!=NULL) {
        r = (int)rand()%LENGTH;
        for(int j=0; j<r-1; j++) {
            curNode=curNode->next;
        }
        tmp=curNode->val;
        curNode->val=list->val;
        list->val=tmp;
        curNode=head;
        list=list->next;
    }
    return head;
}

List* bubble_sort(List* list)
{
    List *p,*q,*top;
    int changed=1;
    top=(List*)malloc(sizeof(List));
    top->next = list;
    if(list!=NULL&&list->next!=NULL) {
        while(changed) {
            changed = 0;
            q=top;
            p=top->next;
            while(p->next!=NULL) {
                if(p->val>p->next->val) {
                    q->next=list_switch(p,p->next);
                    changed =1;
                }
                q=p;
                if(p->next!=NULL)
                    p=p->next;
            }

        }
    }
    p=top->next;
    free(top);
    return p;
}

List* list_switch(List* list1,List* list2)
{
    list1->next=list2->next;
    list2->next=list1;
    return list2;
}

List* reverse(List* list)
{
    List* new_list=NULL;
    while(list) {
        List* next=list->next;
        list->next=new_list;
        new_list=list;
        list=next;
    }
    return new_list;
}
