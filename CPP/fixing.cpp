#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        //making a constructor
        this->data=data;
        left=NULL;
        right=NULL;
    }

};
class BST{
    public:
    Node *newnode(int data){
        Node *temp=new Node(data);
        return temp;
    }
    Node *insertNode(Node *root,int ele){
        if(root==NULL){
            return newnode(ele);
        }
        queue<Node *> q;
        q.push(root);
        //pushed it
        while(!q.empty()){
            //checks for if the queue is empty
            //if it is not then go with left
            //and then pop it
            Node *temp=q.front();
            //now temp has root
            q.pop();
            if(temp->left==NULL){
                //now it's null so i need to push ele here
                //and then create a newnode for ele
                //but it needs to be attached to it temp->left
                //if i do newnode(ele) it would create it but won't
                temp->left=newnode(ele);
                return root;
            }
            else{
                q.push(temp->left);
            }
            if(temp->right==NULL){
                temp->right=newnode(ele);
            }
            else{
                q.push(temp->right);
            }
        }
        return root;
    }
    Node *buildTree(vector<int> a){
        Node *root=NULL;
        for(int x:a){
            root=insertNode(root,x);
        }
        return root;
    }

    void levelOrder(Node *root){
        if(root==NULL){
            cout<<"It's empty can't do shit";
            return;
        }
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            Node *temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
        return;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int >v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    //now vector is ready
    Node *root=NULL;
    BST tree;
    root=tree.buildTree(v);
    tree.levelOrder(root);
}