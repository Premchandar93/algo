#include <iostream>
using namespace std;


struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode (int passeddata){
    struct node *creatednode = (struct node*) malloc (sizeof( struct node));
    creatednode->data = passeddata;
    creatednode->left = NULL;
    creatednode->right = NULL;
    
    return creatednode;
}

int main() {
	struct node *root = newnode(11);
	root->left = newnode(22);
	root->right = newnode(33);
	
	cout<<"root = "<<root->data<<"\n left ="<<root->left->data<<"\n right = "<<root->right->data;
	
}
