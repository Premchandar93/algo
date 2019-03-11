
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *newnode (int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->data = data;
    return temp;
}


void deletenode(struct node *root, int data){
    struct node *temp;
    
    while( root->data != data ){
        temp = root;
        root = root->next;
    }
    
    temp->next = root->next;
    root->next = NULL;
    free(root);
}

void printlist(struct node *root){
    while(root->next != NULL){
        cout<<root->data<<"\n";
        root = root->next;
    }
    
    cout<<root->data<<"\n";
}


int main(){
    struct node *root = newnode(1);
    root->next = newnode(2);
    root->next->next = newnode(3);
    root->next->next->next = newnode(4);
    printlist(root);
    deletenode(root, 3);
    printlist(root);
}
