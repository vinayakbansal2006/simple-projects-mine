#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
typedef struct node node;
node *start=NULL;
void create(){
    node *newnode,*temp;
    int choice;
    do {
        newnode= new node;
        cout<< "enter data";
        cin >> newnode->data;
        newnode->next = NULL;
        if(start==NULL){
            start=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        cout << "do u want to continue";
        cin >> choice;

    }while(choice == 1);

}
void insatbeg(int data){
    node *newnode;
    newnode=new node;
    newnode->data=data;
    newnode->next=start;
    start=newnode;
}
void insatend(int data){
    node*newnode,*temp=start;
    newnode=new node;
    newnode->data=data;
    if (start == NULL) {
        start = newnode;
        newnode->next = NULL;
        return;
    }

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
}
void insatbet(int data,int pos){
    node *newnode,*temp=start;
    newnode=new node;
    newnode->data=data;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void delatbeg(){
    node *temp;
    temp=start;
    start=start->next;
    delete temp;
}
void delatend(){
    node *temp=start,*ptr;
    while(temp->next!=NULL){
        ptr=temp;
        temp=temp->next;
    }
    ptr->next=NULL;
    delete temp;
}
void delatbet(int pos){
    node *temp=start,*nextnode;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    delete nextnode;
}
void search(int item){
    struct node *temp;
    temp=start;
    if(temp==NULL){
        cout << "empty list";
    }
    else{
        while(temp!=NULL){
            if(temp->data==item){
                cout << "item found";
                break;
            }
            temp=temp->next;
        }
    }
}
void display(){
    node *temp = start;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main() {
    create();
    return 0;
}