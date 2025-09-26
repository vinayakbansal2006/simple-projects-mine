#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

node* create(){
    struct node *start=NULL,*temp=NULL,*newnode;
    int choice;
    do{
        newnode=new node;
        cout << "enter the data ";
        cin >> newnode->data;
        newnode->prev=NULL;
        newnode->next=NULL;
        if(start==NULL){
            start = newnode;
            temp = newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        cout << "Do u want to continue (1/0) ";
        cin >> choice;
    }while(choice==1);
    return start;
}

void display(node* start) {
    node* temp = start;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insatbeg(struct node **start,int data){
    node *newnode = new node;
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = *start;
    if(*start != NULL)
        (*start)->prev = newnode;
    *start = newnode;
}

void insatend(struct node **start,int data){
    node *newnode = new node;
    newnode->data = data;
    newnode->next = NULL;
    if(*start == NULL){
        newnode->prev = NULL;
        *start = newnode;
        return;
    }
    node *temp = *start;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void insatbet(struct node **start,int data,int pos){
    if(*start == NULL) return;
    node *newnode = new node;
    newnode->data = data;
    node *temp = *start;
    int i=0;
    while(i<pos-1 && temp->next!=NULL){
        temp=temp->next;
        i++;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if(temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
}

void delatbeg(struct node **start){
    if(*start == NULL) return;
    node *temp = *start;
    *start = (*start)->next;
    if(*start != NULL)
        (*start)->prev = NULL;
    delete temp;
}

void delatend(struct node **start){
    if(*start == NULL) return;
    node *temp = *start;
    if(temp->next == NULL){
        *start = NULL;
        delete temp;
        return;
    }
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}

void delatbet(struct node **start,int pos){
    if(*start == NULL) return;
    node *temp = *start;
    int i=1;
    while(i<pos-1 && temp->next!=NULL){
        temp=temp->next;
        i++;
    }
    node *ptr = temp->next;
    if(ptr == NULL) return;
    temp->next = ptr->next;
    if(ptr->next != NULL)
        ptr->next->prev = temp;
    delete ptr;
}

int main(){
    node *start = create();

    insatbeg(&start, 100);
    insatend(&start, 200);
    insatbet(&start, 150, 2);


    display(start);
    return 0;
}   

