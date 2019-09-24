#include<bits/stdc++.h> 
typedef long long int lli;

using namespace std; 

lli partition(lli arr[], lli l, lli r, lli k); 

lli findMedian(lli arr[], lli n) 
{ 
	sort(arr, arr+n);  
	return arr[n/2]; 
} 


lli kthSmallest(lli arr[], lli l, lli r, lli k) 
{ 
	
	if (k > 0 && k <= r - l + 1) 
	{ 
		lli n = r-l+1; 

		
		lli i, median[(n+4)/5];
		for (i=0; i<n/5; i++) 
			median[i] = findMedian(arr+l+i*5, 5); 
		if (i*5 < n) 
		{ 
			median[i] = findMedian(arr+l+i*5, n%5); 
			i++; 
		}	 

		
		lli medOfMed = (i == 1)? median[i-1]: 
								kthSmallest(median, 0, i-1, i/2); 

		
		lli pos = partition(arr, l, r, medOfMed); 

		
		if (pos-l == k-1) 
			return arr[pos]; 
		if (pos-l > k-1) 
			return kthSmallest(arr, l, pos-1, k); 

		
		return kthSmallest(arr, pos+1, r, k-pos+l-1); 
	} 

	
	return INT_MAX; 
} 

void swap(lli *a, lli *b) 
{ 
	lli temp = *a; 
	*a = *b; 
	*b = temp; 
} 


lli partition(lli arr[], lli l, lli r, lli x) 
{ 
	
	lli i; 
	for (i=l; i<r; i++) 
		if (arr[i] == x) 
		break; 
	swap(&arr[i], &arr[r]); 

	
	i = l; 
	for (lli j = l; j <= r - 1; j++) 
	{ 
		if (arr[j] <= x) 
		{ 
			swap(&arr[i], &arr[j]); 
			i++; 
		} 
	} 
	swap(&arr[i], &arr[r]); 
	return i; 
} 


int main() 
{ 
	lli t;
	cin >> t;
	
	while(t--){
		lli n;	
	
		cin >> n;
		lli d[n];
		for(lli i=0;i<n;i++){
		lli a,b;
		cin >>a>>b;
		d[i]=a*a+b*b;
	}
	long  double k ;
	if(n%2){
    	k=sqrtl((double)(kthSmallest(d,0,n-1,n/2+1)));
	}
    else {
        k=sqrtl((double)(kthSmallest(d,0,n-1,n/2)));
    }
	cout << k << endl;
	}
	return 0; 
}

