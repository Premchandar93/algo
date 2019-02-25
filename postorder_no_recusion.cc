#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
    int traversed;
};

struct node *newnode(int data){
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->traversed = 0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


void postorder(struct node* root){
    stack<struct node*> st;
    root->traversed = 1;
    st.push(root);
    
    while(!st.empty()){
        struct node* temp = st.top();
        
        temp->traversed = 1;
        if (temp->right && !temp->right->traversed){
            
            st.push(temp->right);
            
        }
        
        if(temp->left && !temp->left->traversed){
            
            st.push(temp->left);
        }
        
        if (!temp->right && !temp->left && temp->traversed) {
            cout<<temp->data<<" ";
            st.pop();
        }
        else{
            int leftflag =0;
            int rightflag = 0;
            if (temp->left){
                if (temp->left->traversed == 1){
                    leftflag = 1;
                }
            }
            else{
                leftflag = 1;
            }
            
            if ( temp->right){
                if(temp->right->traversed == 1){
                    rightflag = 1;
                }
            }
            else{
                rightflag =1 ;
            }
            
            if ( leftflag && rightflag){
                cout<<temp->data<<" ";
                st.pop();
            }
            
        }
        
    }
}   
   
 
int main(){
    struct node *root = newnode(1);
    root->left        = newnode(2);
    root->right       = newnode(3);
    root->right->left  = newnode(4);
    root->right->right = newnode(5);
    
    postorder(root);
    
    return 0;
}
