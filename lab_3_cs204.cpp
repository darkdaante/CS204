#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	string arr[n];
	char arr1[n][100];
	int decide=0;
	for(int x=0;x<n;x++)
	{
		cin>>arr[x];
	}
	
	for(int i=0;i<n;i++)
	{
		int a=0,b=0,c=0,d=0,e=0;
		decide=0;
		int len=arr[i].length();
		int points=0;
		for(int j=0;j<len;j++)
		{
			if(arr[i][j]=='(')
			{
				arr1[i][points]=arr[i][j];
				points++;
				a++;
			}
			if(arr[i][j]=='{')
			{
				arr1[i][points]=arr[i][j];
				points++;
				b++;
			}
			if(arr[i][j]=='[')
			{
				arr1[i][points]=arr[i][j];
				points++;
				c++;
			}
			if(arr[i][j]=='<')
			{
				arr1[i][points]=arr[i][j];
				points++;d++;
			}
			if(arr[i][j]=='|' && arr1[i][points-1]=='|' && points>0)
			{
				points--;e--;
			}
			else if (arr[i][j]=='|' && arr1[i][j]!='|')
			{
				if(e!=0)
				{
					decide=1;
					break;
				}
				arr1[i][points]=arr[i][j];
				points++;e++;
			}
			if(arr[i][j]==')')
			{
				if(arr1[i][points-1]=='(')
				{
					points--;a--;
				}
				else
				{
					decide=1;
					break;
				}

			}

			if(arr[i][j]=='}')
			{
				if(arr1[i][points-1]=='{')
				{
					points--;b++;
				}
				else
				{
					decide=1;
					break;
				}

			}

			if(arr[i][j]=='>')
			{
				if(arr1[i][points-1]=='<')
				{
					points--;d--;
				}
				else
				{
					decide=1;
					break;
				}

			}

			if(arr[i][j]==']')
			{
				if(arr1[i][points-1]=='[')
				{
					points--;c--;
				}
				else
				{
					decide=1;
					break;
				}

			}
		}
		if(decide==0)
		{
			cout<<"YES"<<endl;
		}
		else if(decide==1 || a!=0 || b!=0 || c!=0 || d!=0 || e!=0)
		{
			cout<<"NO"<<endl;
		}

	}

}
	

