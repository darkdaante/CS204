#include<bits/stdc++.h>

using namespace std;

void diffof2num(string str1, string str2)
{
    int decide=str1.length();
    int n1=decide;
    int n2=str2.length();
    int diff=0;
    int Carry=1;
    string diffofnums="";
    string temp="";
    for(int j1=0;j1<n1-n2;j1++)
    {
        str2='0'+str2;
    }
    for(int l=0;l<decide;l++)
    {
        if((str1[decide-l-1]-'0')>(str2[decide-l-1]-'0'))
        {
            diff=(str1[decide-l-1]-'0')-(str2[decide-l-1]-'0');
            temp=diff+'0';
            diffofnums=temp+diffofnums;
        }
        if((str1[decide-l-1]-'0')<(str2[decide-l-1]-'0'))
        {
            str1[decide-l-2]=((str1[decide-l-2]-'0')-1)+'0';
            diff=(str1[decide-l-1]-'0')-(str2[decide-l-1]-'0')+10;
            temp=diff+'0';
            diffofnums=temp+diffofnums;
        }
    }
    cout<<diffofnums;
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
        diffof2num(arr[j][0],arr[j][1]);
        cout<<endl;
    }
}
