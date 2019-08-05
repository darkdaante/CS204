#include<bits/stdc++.h>

using namespace std;

void sumof2num(string str1, string str2)
{
    int n1=str1.length();
    int n2=str2.length();
    int decide=n1;
    int sum=0;
    int Carry=0;
    if(n1>n2)
    {
        for(int j1=0;j1<n1-n2;j1++)
        {
            str2='0'+str2;
        }
    }

    if(n2>n1)
    {
        decide=n2;
        for(int k1=0;k1<n2-n1;k1++)
        {
            str1='0'+str1;
        }
    }
    string sumofnums="";
    string temp;
    for(int l=0;l<decide;l++)
    {
        if(l<decide-1)
        {
        sum=(str1[decide-l-1]-'0')+(str2[decide-l-1]-'0')+Carry;
        Carry=sum/10;
        temp=(sum%10)+'0';
        sumofnums=temp+sumofnums;
        }
        else if (l==decide-1)
        {
            sum=(str1[decide-l-1]-'0')+(str2[decide-l-1]-'0')+Carry;
            Carry=(sum/10);
            temp=(sum%10)+'0';
            sumofnums=temp+sumofnums;
            temp="";
            temp=Carry+'0';
            sumofnums=temp+sumofnums;
        }

    }
    cout<<sumofnums;
}

int main()
{
    int n;
    cin>>n;
    string arr[n][2];
    for(int i=0;i<n;i++)
    {
    cin>>arr[i][0];
    cin>>arr[i][1];
    }
    cout<<endl;
    for(int j=0;j<n;j++)
    {
        sumof2num(arr[j][0],arr[j][1]);
        cout<<endl;
    }
}


