#include<iostream>
#include<algorithm> 
using namespace std;

int diff = 0;
struct node{
    int data;
    struct node *left;
    struct node *right;
    int min;
};

int findmaxdiff(struct node *);
int populatemin(struct node *);

struct node *newnode (int data ){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->min = -1;
    return temp;
}


int populatemin( struct node *root) {

    if (!root){return -1;}
    
    int left = populatemin(root->left) ;
    int right = populatemin(root->right) ;
    if ( left == -1 && right == -1){ 
        root->min = root->data;
    }
    else {
        if ( left == -1 ) { left = right;} 
        if ( right == -1) { right = left;}
        root->min =  std::min(left, right);
    }  
    return root->min;
}

void inorder( struct node *root){
    
    if (!root) { return ;}
    
    inorder(root->left);
    cout<<root->data<<"---"<<root->min<<"\n";
    inorder(root->right);
}

int findmaxdiff ( struct node *root) {
    
    if ( !root) { return 0;}
    int leftval = root->data; int rightval = root->data;
    if ( root->left ) {
        leftval = root->left->data;
    }
    if ( root->right ) {
        rightval = root->right->data;
    }
    
    int diff = std::max(std::max( root->data - leftval , root->data - rightval), root->data- root->min);
   
    return std::max(std::max(diff, findmaxdiff(root->left)), findmaxdiff(root->right));
}

int main(){
    struct node *root = newnode(17);
    root->left = newnode(6);
    root->right = newnode(16);
    root->left->left= newnode(4);
    root->left->right = newnode(3);
    root->right->left = newnode(2);

    populatemin(root);
    //inorder(root);
    cout<<findmaxdiff(root);
    
    
}
