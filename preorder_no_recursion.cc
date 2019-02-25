#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int data){
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void traverse(struct node *root){
    queue<struct node*> st;
    
    st.push(root);
    
    while(!st.empty()){
        struct node *temp = st.front();
        
        st.pop();
        
        if (temp->data){
            cout<<temp->data<<" ";
        }
 
        if ( temp->left){
            
            st.push(temp->left);
        } 
        
        if (temp->right){
            
            st.push(temp->right);
        }
        

    }
}

// C++ program to print inorder traversal
// using stack.
#include<bits/stdc++.h>
using namespace std;
 
/* A binary tree Node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
 
/* Iterative function for inorder tree
   traversal */
void postOrder(struct node *curr)
{
    stack<struct node*> s;
    
 
    while (curr != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the
           curr Node */
        while (curr !=  NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            cout << curr->data << " ";
            curr = curr->left;
        }
 
        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();
 
        curr = curr->right;
 
    } /* end of while */
}
int main(){
    struct node *root = newnode(1);
    root->left        = newnode(2);
    root->right       = newnode(3);
    root->left->left  = newnode(4);
    root->left->right = newnode(5);
    root->left->left->right = newnode(6);
    //cout<<root->data<<" ---";
    postOrder(root);
    
    return 0;
}
