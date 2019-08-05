#include <iostream>
#include <math.h>

using namespace std;

void prime(long a)
{
    double b;
    b=pow(a,.5);
    int counts=0;
    for(int i=2;i<b;i++)
    {
        if(a%i==0)
        {
            counts++;
            break;
        }
    }
    if(counts==1)
    {
        cout<< "Not a Prime" ;
    }
    else
    {
        cout<< "A prime no. has been spotted";
    }
}

int main()
{
    int n;
    cin>>n;
    long arr[n];
    for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    }
    cout<<endl;
    for(int j=0;j<n;j++)
    {
        prime(arr[j]);
        cout<<endl;
    }
    return 0;
}
