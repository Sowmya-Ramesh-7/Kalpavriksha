#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
void insert_at_begining(int data);
void insert_at_end(int data);
void insert_at_position(int data, int position);
void delete_from_begining();
void delete_from_end();
void delete_from_position(int position);
void display();
typedef struct node{
    int data;
    struct node *next;
}Node;

Node* head=NULL;
Node* tail=NULL;
int size=0;
int main() {
    int choice,data,position;
    bool isContinue=false;
    do{
        printf("\nEnter the operation you want to perform in Linked list:\n"); 
        printf("1.Insert at Begining\n2. Insert at end\n3. Insert at the Position\n4. Delete from Begining \n5.Delete from end\n6.Delete from a Position");
        printf("\n7.size \n8. display\n9. Exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nEnter the element to insert at begining :");
                    scanf("%d",&data);
                    insert_at_begining(data);
                    break;
            case 2: printf("\nEnter the element to insert at end :");
                    scanf("%d",&data);
                    insert_at_end(data);
                    break;
            case 3: printf("\nEnter the element to insert at position");
                    scanf("%d",&data);
                    printf("\nEnter the position");
                    scanf("%d",&position);
                    insert_at_position(data,position);
                    break;
            case 4: delete_from_begining();
                    break;
            case 5: delete_from_end();
                    break;
            case 6: printf("\nEnter the position at which the element has to be deleted");
                    scanf("%d",&position);
                    delete_from_position(position);
                    break;
            case 7: printf("\n%d is size",size);
                    break;
            case 8: display();
                    break;
            case 9: exit(1);
            default:printf("\nInvalid choice");
        }
        printf("\nDo you want to continue? (Enter any number for Yes or 0 for No) ");
        scanf("%d",&isContinue);
    }while(isContinue);
}
Node* create_node(int data){
    Node* newNode=(struct node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insert_at_begining(int data){
    Node* newNode=create_node(data);
    size++;
    if(head==NULL){
        head=tail=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;
    printf("\n%d inserted at begining",data);
}

void insert_at_end(int data){
    Node* newNode=create_node(data);
    size++;
    if(tail==NULL){
        head=tail=newNode;
        return;
    }
    Node* temp=tail;
    temp->next=newNode;
    tail=newNode;
    printf("\n%d inserted at end",data);
}

void insert_at_position(int data,int position){
    if(position<1||position>size){
        printf("invalid position");
        return;
    }
    int i=1;
    size++;
    Node* newNode=create_node(data);
    if(head==NULL){
        head=tail=newNode;
        return;
    }
    Node* temp=head;
    if(position==1){
        insert_at_begining(data);
        return;
    }
    while(temp!=NULL&& i!=position-1){
        i++;
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    printf("\n%d inserted at position %d",data, position);
}

void delete_from_begining(){
    if(head==NULL){
        printf("Linked List is Empty");
        return;
    }
    Node* temp=head;
    head=head->next;
    size--;
    printf("\n%d deleted from begining",temp->data);
    free(temp);
}

void delete_from_end(){
    if(tail==NULL){
        printf("Linked List is Empty");
        return;
    }
    Node* temp=head;
    int i=1;
    while(i=size-1){
        i++;
        temp=temp->next;
    }
    printf("\n%d deleted from end",tail->data);
    tail=temp;
    free(temp->next);
    temp->next=NULL;
    size--;
}

void delete_from_position(int position){
    Node* curr;
    if(head==NULL){
        printf("Linked List is Empty\n");
        return;
    }
    if(position<1||position>size){
        printf("invalid position\n");
        return;
    }
    int i=1;
    Node* temp=head;
    while(temp!=NULL&& i!=position-1){
        i++;
        temp=temp->next;
    }
    curr=temp->next;
    temp->next=temp->next->next;
    printf("\n%d deleted from position %d",curr->data, position);
    free(curr);
    size--;
     
}


void display(){
    Node* temp=head;
    if(head==NULL){
        printf("Linked List is empty");
        return;
    }
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

