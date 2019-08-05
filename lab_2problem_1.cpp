#include<iostream>
#include<cmath>
using namespace std;
struct node{
int x;
int y;
struct node *next;
};
void addfirst(int a,int b);
void delfirst();
void del(int a,int b);
void search(int d);
bool search(int x,int y);
int length();

void decide(int a,int x,int y)
{
	switch(a)
	{
		case 1: addfirst(x,y); break;
		case 2: delfirst(); break;
		case 3: del(x,y); break;
		case 4: search(x); break;        
		case 5: if(search(x,y)) cout<<"true"<<endl;
		else cout<<"false"<<endl;
			break;  
		case 6: length(); break;
	}
}
struct node *start=NULL;


void addfirst(int a,int b)
{
	struct node *temp=new node;
	temp->x=a;
	temp->y=b;
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		temp->next=start; 
		start=temp;
	}
}   
void delfirst()
{	struct node *temp;
	temp=start;
	start=temp->next;
	delete temp;
}

void del(int a,int b)
{	struct node *temp,*prev;
	temp=start;
	if (temp != NULL && (temp->x==a&&temp->y==b)) 
	{ 
		start = temp->next;    
		delete temp;              
		return; 
	} 

	while (temp != NULL && (temp->x==a&&temp->y==b)) 
	{ 
		prev = temp;               
		temp = temp->next; 
	}
	if (temp == NULL) return;
	prev->next = temp->next; 
	delete temp;
}

void search(int d)
{	int x,y;
	struct node *temp;
	temp=start;
	while(temp!=NULL)
	{
		float r=sqrt((temp->x)*(temp->x)+(temp->y)*(temp->y));
		if(r<=d)
		{  
			cout<<"("<<temp->x<<","<<temp->y<<")";
		}
		temp=temp->next;
	}
	cout<<endl;
}

bool search(int a,int b)
{	struct node *temp;
	temp =start;
	while (temp != NULL)  
	{  
		if (temp->x == a && temp->y == b)  
		    return true;  
		temp = temp->next;  
	}  
	return false;
}

int length()
{	struct node *temp;
	temp=start;
	int n=1;
	 for(int i=0;temp->next!=NULL;i++)
	 { 
		n=n+1;
		temp=temp->next;
	 }
	cout<<n<<endl;
	return 0;
}

int main()
{ 
	int n;
	cin>>n;
	int arr[n][3];
	for(int i=0;i<n;i++)
	{
		int a=0,x=0,y=0;
		cin>>a;
		if(a==0)
		{
			break; 
		}
	if(!(a==2||a==6||a==4))
	{
		cin>>x;
		cin>>y;
	}
	if(a==4)
	{
		cin>>x;
	}
	arr[i][0]=a;
	arr[i][1]=x;
	arr[i][2]=y;
	}
	cout<<endl;
	for(int j=0;j<n;j++)
	{
		decide(arr[j][0],arr[j][1],arr[j][2]);	
	}

}





















