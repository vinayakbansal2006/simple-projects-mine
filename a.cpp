#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
typedef node node;
node *start=NULL;
void create(){
    node *newnode,*temp;
    int choice;
    do{
    newnode=new node;
    cout <<"enter the data ";
    cin >> newnode->data;
    newnode->next=NULL;
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
    node *temp,*newnode;
    newnode=new node;
    newnode->data=data;
    newnode->next=start;
    start=newnode;
}
void insatend(int data){
    node *temp,*newnode;
    newnode=new node;
    newnode->data=data;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
}
void insatbet(int data,int pos){
    node *temp,*newnode;
    newnode=new node;
    newnode->data=data;
    int i=0;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;

}
void delatbeg(){
    node *temp=start;
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
int main() {
    return 0;
}