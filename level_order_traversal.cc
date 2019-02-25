#include <iostream>
using namespace std;


struct node {
    int data;
    struct node *left;
    struct node *right;
};
void printtree(struct node *tem,int level);
void inorder(struct node *node);
int height(struct node *temp);

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

int height(struct node *temp){
    if ( !temp){
        return 0;
    }
    
    int leftvalue = height(temp->left);
    int rightvalue = height(temp->right);
    
    if ( leftvalue > rightvalue ){
        return leftvalue + 1;
    }
    else{
        return rightvalue + 1;
    }
}

void printtree(struct node *tem,int level){
    if(!tem){
        return;
    }
    
    if ( level == 1){
        cout<<tem->data<<" ";
    }
    else if(level > 1){
        printtree(tem->left, level-1);
        printtree(tem->right, level-1);
    }
}


void printlevelorder( struct node *temp){
    int hei = height(temp);
    
    for( int i =1; i <= hei ; i++){
        printtree(temp, i);
        cout<<"\n";
    }
}




int main() {
	struct node* root = newnode(10);
    root->left = newnode(11);
    root->left->left = newnode(7);
    root->left->right = newnode(13);
    root->right = newnode(9);
    root->right->left = newnode(15);
    root->right->right = newnode(8);
    
    printlevelorder(root);
	
	
	
}
