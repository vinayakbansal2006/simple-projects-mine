#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};
Node *create(int item){
    Node *node = new Node;
    node->data=item;
    node->right=node->left=NULL;
    return node;
}
Node *insertion(struct Node *root,int item){
    if(root==NULL){
        return create(item);
    }
    if(item < root->data){
        root->left= insertion(root->left,item);
    }
    else{
        root->right=insertion(root->right,item);
    }
    return root;
}
void inorder(struct Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}
Node *search(Node *root,int key){
    if(root==NULL || root->data==key){
        return root;
    }
    if(key<root->data){
        return search(root->left,key);
    }
    return search(root->right,key);
}
Node *delofleaf(Node *root,int item){
    Node *parent=NULL ,*curr=root;
    if(curr==NULL) return;
    if(curr->left==NULL && curr->right==NULL){
        if(curr!=root){
            if(parent->left==curr){
                parent->left=NULL;
            }
            else{
                parent->right=NULL;
            }
        }
        else{
            root=NULL;
        }
        delete curr;
    }
}
Node *delofonechild(Node *root,int item){
    Node *parent=NULL ,*curr=root,*child=NULL;
    if(curr==NULL) return;
    if(curr->left==NULL && curr->right!=NULL){
        child=curr->right;
    }
    if(curr->left!=NULL && curr->right==NULL){
        child=curr->left;
    }
    if(curr!=root){
        if(curr==parent->left){
            parent->left=child;
        }
        else{
            parent->right=child;
        }
    }
    else{
        root=child;
    }
    delete curr;
}
Node *findminimum(Node *curr){
    curr=curr->right;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node *deloftwochild(Node *root,int item){
    Node *parent=NULL ,*curr=root,*child=NULL;
    if(curr==NULL) return;
    if(curr->left && curr->right){
        Node *succ =findminimum(curr->right);
        int val = succ->data;
        deloftwochild(root,succ->data);
        curr->data=val;
    }
}
int main() {
    return 0;
}