#include<bits/stdc++.h>
#define V 4
#define INF 9999999
using namespace std;

void printsol(int dist[][V])
{
    cout<<"The following matrix shows the shortest distances between every pair of vertices\n";
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(dist[i][j]==INF)
                cout<<"INF      ";
            else
                cout<<dist[i][j]<<"     ";
        }
        cout<<endl;
    }
}

void floydwarshall(int graph[][V])
{
    int dist[V][V],i,j,k;
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            dist[i][j]=graph[i][j];

    for(k=0;k<V;k++)
    {
        for(j=0;j<V;j++)
        {
            for(i=0;i<V;i++)
            {
                if(dist[j][i]+dist[k][i]<dist[j][i])
                    dist[j][i]=dist[j][k]+dist[k][i];
            }
        }
    }
    printsol(dist);
}

int main()
{
    int graph[V][V]={{0,5,INF,10},{INF,0,3,INF},{INF,INF,0,1},{INF,INF,INF,0}};
    floydwarshall(graph);
    return 0;
}
