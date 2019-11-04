#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int key;
    Node *left;
    Node *right;
};

Node* newnode(int key)
{
    Node* node=new Node();
    node->left=node->right=NULL;
    node->key=key;
}

Node* insert(Node* node, int key)
{
    if(node==NULL)
        return (newnode(key));
    
    if(key<node->key)
        node->left=insert(node->left,key);
    else if(key>node->key)
        node->right=insert(node->right,key);
    else
        return node;
}

Node* search(Node* node,int key)
{
    if(node==NULL || node->key==key)
        return node;
    
    if(node->key<key)
        return search(node->right,key);
    
    return search(node->right, key);
}

Node* minvaluenode(Node* node)
{
    Node* currentnode=node;
    while(currentnode && currentnode->left !=NULL)
        currentnode=currentnode->left;
    return currentnode;
}

void inorder(Node* node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        cout<<node->key<<" ";
        inorder(node->right);
    }
}

Node* deletenode(Node* node,int key)
{
    if(node==NULL)
        return node;
    if(key<node->key)
        node->left=deletenode(node->left,key);
    else if(key>node->key)
        node->right=deletenode(node->right,key);
    else
    {
        if(node->left==NULL)
        {
            Node* temp=node->right;
            free(node);
            return temp;
        }
        else if(node->right==NULL)
        {
            Node* temp=node->left;
            free(node);
            return temp;
        }
        
        Node* temp=minvaluenode(node->right);
        node->key=temp->key;
        node->right=deletenode(node->right,temp->key);
    }
}

int main()
{
    Node* node=NULL;
    for(int i=0;i<10;i++)
    {
        node=insert(node,10-i);
    }
    cout<<"Binary tree inorder traverser\n";
    inorder(node);
    cout<<"\nRoot Node:"<<node->key;
    int k=node->key;
    node=deletenode(node,k);
    cout<<"\nAfter deleting Root New Root is:"<<node->key;
    cout<<"\nNew Sequence:";
    inorder(node);
}

