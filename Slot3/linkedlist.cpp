#include <bits/stdc++.h>

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
		case 5: if(search(x,y)) cout<<"True"<<endl;
           			else cout<<"False"<<endl;
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
{
	if(start==NULL)
	{
		cout<<"-1";
		return;
	}	
	struct node *temp=new node;
	temp=start;
	start=temp->next;
	delete temp;
}

bool search(int a,int b)
{ 
	struct node *temp;
	temp =start;
	while (temp != NULL)  
	{  
		if (temp->x == a && temp->y == b)  
		return true;  
		temp = temp->next;  
	}  
	return false;
}

void del(int x,int y)
{
	if (start == NULL)
	{
	        cout<<"-1"<<endl;
	        return ;
	}

	node* temp = start;

	node* prev = NULL;

	if ((start->x)==x&&(start->y)==y)
	{
		start = temp->next;
		free(temp);
		return;
	}


	for (int i=0; temp!=NULL; i++)
	{
		if(temp->x==x&&temp->y==y)
		{
			break;
		}
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL )
	{
		cout<<"-1"<<endl;
		return;
	}

	struct node *next = temp->next;

	free(temp);

	prev->next = next;
}

void search(int d)
{
	struct node* temp = start;
	int a,b;
	int c= 0;
	while (temp!= NULL)
	{
	        a = temp->x;
	        b = temp->y;
	        if(a*a+b*b<=d*d)
	        {
			c++;
        	}
        temp=temp->next;
	}
	if(c==0)
	{
	        cout<<"-1";
	}
	else
	{
	        cout<<c<<endl;
	}
}



int length()
{
	struct node *temp;
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