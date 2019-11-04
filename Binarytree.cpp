#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int key;
    Node* left;
    Node* right;
    int height;
};

Node* newNode(int key)
{
    Node* node = new Node;
    node->key=key;
    node->left=node->right=NULL;
    return node;
}

void insert(Node* temp,int key)
{
    queue<Node*> q;
    q.push(temp);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        
        if(!temp->left)
        {
            temp->left=newNode(key);
            break;
        }
        else
            q.push(temp->left);
        
        if(!temp->right)
        {
            temp->right=newNode(key);
            break;
        }
        else
            q.push(temp->right);
    }
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

int main()
{
    Node* node=new Node;
    for(int i=1;i<13;i++)
    {
        insert(node,i);
    }
    inorder(node);
}