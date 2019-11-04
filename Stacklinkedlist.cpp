#include<bits/stdc++.h>

using namespace std;

class Stacknode 
{
    public:
    int key;
    Stacknode* next;
};

Stacknode* top;

Stacknode* newnode(int key)
{
    Stacknode* node =new Stacknode();
    node->key=key;
    node->next=NULL;
    return node;
}

int isempty(Stacknode* node)
{
    return !node;
}

void push(int key)
{
    Stacknode* temp=newnode(key);
    temp->next=top;
    top=temp;
}

void pop()
{
    if(top==NULL)
    {
        cout<<"Stack Underflow";
    }
    else
    {
        Stacknode* temp=top;
        top=top->next;
        free(temp);
    }
}

int topelement()
{
    if(isempty(top))
    {
        return INT_MIN;
    }
    else
        return top->key;
}

int main()
{
    push(10);
    push(20);
    push(30);
    cout<<"Top element is:"<<topelement()<<endl;
    pop();
    cout<<"Top element is:"<<topelement()<<endl;
}
