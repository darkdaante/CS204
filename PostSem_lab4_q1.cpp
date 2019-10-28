#include <bits/stdc++.h> 

using namespace std; 

void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  
bool isBipartite(vector<int> adj[], int v, vector<bool>& visited, vector<int>& color) 
{ 
  
    for (int u : adj[v]) { 

        if (visited[u] == false) { 
 
            visited[u] = true; 

            color[u] = !color[v]; 

            if (!isBipartite(adj, u, visited, color)) 
                return false; 
        } 
  
        else if (color[u] == color[v]) 
            return false; 
    } 
    return true; 
} 
  
 
int main() 
{  
    int N , M;
    cin>>N>>M;
    vector<int> adj[N + 1];
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        addEdge(adj,a,b);
    }  
   
    vector<bool> visited(N + 1); 
   
    vector<int> color(N + 1); 

    visited[1] = true; 
   
    color[1] = 0;
    int count=0; 
    for(int i=0;i<N;i++)
    {
        if (isBipartite(adj, i, visited, color)) 
        {
            continue; 
        }
        else 
        {
            cout << "NO";
            count=1;
            break; 
        }
    } 
    if(count==0)
    {
        cout << "YES";
    }
  
    return 0;
}