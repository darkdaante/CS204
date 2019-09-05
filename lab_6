#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n;
    cin>>n;
    int arr[n][2];
    int count=0,max=0,max_id=0;
    std::vector<string> s ;
    long long int q;
    cin>>q;
    for(long long int lm=0;lm<q;lm++)
    {
        int decide=0;
        cin>>decide;
        if(decide==1)
        {
            int m=0;n=0;
            cin>>m;
            cin>>n;
            if(count==0)
            {
                arr[count][0]=m;
                arr[count][1]=n;
		max=n;
		max_id=m;
                count++;
            }
            else if(count!=0)
            {
                int search=0;
                for(int i=0;i<count;i++)
                {
                    if(arr[i][0]==m)
                    {
                        arr[i][1]=arr[i][1]+n;
                        search=1;
			if(arr[i][1]>max){max=arr[i][1];max_id=m;}
                        break;
                    }
                }
                if(search==0)
                {
                    arr[count][0]=m;
                    arr[count][1]=n;
		    if(arr[count][1]>max){max=arr[count][1];max_id=m;}
                    count++;
                }
                search=0;
            }
        }
        else if(decide==2)
        {
            if(count==0)
            {
                s.push_back("No data available.");
            }
           else if(count!=0)
            {
		string x=to_string(max_id);
                s.push_back(x);
            }
        }
    }
    cout<<endl;
    s.shrink_to_fit();
    for(auto it =s.begin();it!=s.end();++it)
    {
        cout<<*it<<endl;
    }
    
}
