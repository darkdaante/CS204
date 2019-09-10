#include<bits/stdc++.h> 

using namespace std; 
  

int compare(string x, string y) 
{ 
    
    string xy = x.append(y);
    string yx = y.append(x); 
    return xy.compare(yx) > 0 ? 1: 0; 
} 
  

void print(vector<string> A) 
{ 
  
    sort(A.begin(), A.end(), compare); 
  
    for (int i=0; i < A.size() ; i++ ) 
        cout << A[i]; 
} 
  

int main() 
{ 
    vector<string> A; 
    long long n;
    cin>>n;
    while(n--)
    {
    	long long t;
    	cin>>t;
    	while(t--)
    	{
    		string s;
    		cin>>s;
    		A.push_back(s);
    	}
    	print(A);
    	A.clear();
    	cout<<endl;
    }
  
    
  
   return 0; 
}
