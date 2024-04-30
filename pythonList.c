#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum{
    INT,
    FLOAT,
    STRING,
    INVALID
}DataType;

typedef union {
    int int_value;
    float float_value;
    char *string_value;
} Value;

typedef struct Data{
    DataType type;
    Value value;
}Data;

typedef struct node{
    Data data;
    struct node *next;
}Node;

Node* head=NULL;
Node* tail=NULL;

void insert_at_begining(Data data);
void insert_at_end(Data data);
void insert_at_position(Data data, int position);
void delete_from_begining();
void delete_from_end();
void delete_from_position(int position);
void display();
void print_data(Data data);
Data create_data(DataType type);
Node* create_node(Data data);
int size=0;

DataType getDataType(){
    int choice;
    printf("Enter the data type (0 for INT, 1 for FLOAT, 2 for STRING): ");
    scanf("%d", &choice);
    DataType type;
    switch (choice) {
        case 0:
            type = INT;
            break;
        case 1:
            type = FLOAT;
            break;
        case 2:
            type = STRING;
            break;
        default:
            printf("Invalid choice\n");
            type=INVALID;
    }
    return type;
}
int main() {
    int choice,position;
    Data data;
    DataType type;
    bool isContinue=false;
    do{
        printf("\nEnter the operation you want to perform in Linked list:\n"); 
        printf("1.Insert at Begining\n2. Insert at end\n3. Insert at the Position\n4. Delete from Begining \n5.Delete from end\n6.Delete from a Position");
        printf("\n7.size \n8. display\n9. Exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1: type=getDataType();
                    if(type==INVALID){break;}
                    data=create_data(type);
                    insert_at_begining(data);
                    break;
            case 2: type=getDataType();
                    if(type==INVALID){break;}
                    data=create_data(type);
                    insert_at_end(data);
                    break;
            case 3: type=getDataType();
                    if(type==INVALID){break;}
                    data=create_data(type);
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

Node* create_node(Data data){
    Node* newNode=(struct node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

Data create_data(DataType type){
    Value value;
    printf("\nEnter the element to be inserted :");
    if(type==INT){
        scanf("%d",&value.int_value);
    }else if(type==FLOAT){
        scanf("%f",&value.float_value);
    }else{
        value.string_value = (char *)malloc(100 * sizeof(char));
        scanf(" %s[^\n]", value.string_value);
    }
    Data data ={type,value};
    return data;    
}

void display(){
    Node* temp=head;
    if(head==NULL){
        printf("Linked List is empty");
        return;
    }
    while(temp!=NULL){
        print_data(temp->data);
        printf("->");
        temp=temp->next;
    }
    printf("NULL");
}
void print_data(Data data){
    if(data.type==INT){
            printf("%d ",data.value.int_value);
        }else if(data.type==FLOAT){
            printf("%f ",data.value.float_value);
        }else{
            printf("%s ",data.value.string_value);
        }
}

void insert_at_begining(Data data){
    Node* newNode=create_node(data);
    size++;
    if(head==NULL){
        head=tail=newNode;
        print_data(data);
        printf("\ninserted at begining");
        return;
    }
    newNode->next=head;
    head=newNode;
    print_data(data);
    printf("\ninserted at begining");
}

void insert_at_end(Data data){
    Node* newNode=create_node(data);
    size++;
    if(tail==NULL){
        head=tail=newNode;
        return;
    }
    Node* temp=tail;
    temp->next=newNode;
    tail=newNode;
    print_data(data);
    printf("\n inserted at end");
}

void insert_at_position(Data data,int position){
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
    print_data(data);
    printf("\n inserted at position %d", position);
}

void delete_from_begining(){
    if(head==NULL){
        printf("Linked List is Empty");
        return;
    }
    Node* temp=head;
    head=head->next;
    size--;
    print_data(temp->data);
    printf("\n deleted from begining");
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
    print_data(tail->data);
    printf("\n deleted from end");
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
    print_data(curr->data);
    printf("\n deleted from position %d", position);
    free(curr);
    size--;
     
}




