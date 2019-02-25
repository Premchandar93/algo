#include <iostream>
using namespace std;

#include <queue>

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

void inorder(struct node *node){
    if (!node){
        return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

void insert(struct node *temp, int data){
    queue<struct node*> q;
    q.push(temp);
    
    
    while(!q.empty()){
        struct node* temp = q.front();
        q.pop();
        
        if ( !temp->left){
            temp->left = newnode(data);
            break;
        }
        else {
            q.push(temp->left);
        }
        
        if (!temp->right){
            temp->right = newnode(data);
            break;
        }
        else{
            q.push(temp->right);
        }
    }
}


int main() {
    struct node* root = newnode(10);
    root->left = newnode(11);
    root->left->left = newnode(7);
    root->right = newnode(9);
    root->right->left = newnode(15);
    root->right->right = newnode(8);
    cout<<"Inorder before=";
    inorder(root);
    
    insert(root, 13);
    cout<<"\n Inorder after=";
    inorder(root);
    
	
}
