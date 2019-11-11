#include<bits/stdc++.h>

using namespace std;

class QueueNode{
    public:
        int key;
        QueueNode* next;
};

class Queue{
    public:
        QueueNode *front, *rear;
};

QueueNode* newnode(int k)
{
    QueueNode* temp=new QueueNode();
    temp->key=k;
    temp->next=NULL;
    return temp;
}

Queue* createqueue()
{
    Queue* q=new Queue();
    q->front=q->rear=NULL;
    return q;
}

void enqueue(Queue* q,int k)
{
    QueueNode* temp=newnode(k);
    if(q->rear==NULL)
    {
        q->front=q->rear=temp;
    }
    else
    {
        q->rear->next=temp;
        q->rear=temp;
    }
}

QueueNode* dequeue(Queue* q)
{
    if(q->front==NULL)
        return NULL;

    QueueNode* temp=q->front;
    q->front=q->front->next;

    if(q->front==NULL)
        q->rear=NULL;

    return temp;
}

void Display(Queue * q)
{
    if(q->front==NULL)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"Queue Elements are:";
    QueueNode* temp =q->front;
    while(temp!=NULL)
    {
        cout<<temp->key<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Queue* q=createqueue();
    enqueue(q,10);
    enqueue(q,20);
    QueueNode* n=dequeue(q);
    cout<<"Dequeued element is:"<<n->key<<endl;
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    Display(q);
    return 0;
}
