#include<bits/stdc++.h>
#include<stdlib.h>

using namespace std;

struct Point
{
    int x,y;
};

Point p0;

int swap(Point &p1 ,Point &p2)
{
    Point temp = p1;
    p1=p2;
    p2=temp;
}

int distsq(Point p1, Point p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

int orient(Point p , Point q , Point r)
{
    int value = (q.y - p.y)*(r.x - q.x) -(q.x - p.x)*(r.y - q.y);
    
    if (value == 0) 
        return 0;
    return (value>0)?1:2;
}

int compare(const void *vp1,const void *vp2)
{
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;
    
    int o = orient(p0,*p1,*p2);
    
    if(o==0)
        return (distsq(p0,*p2)>=distsq(p0,*p1))? -1:1;
    
    return (o==2)? -1:1;
    
}

Point nexttotop(stack<Point> &s)
{
    Point p=s.top();
    s.pop();
    Point result = s.top();
    s.push(p);
    return result;
}

void convexHull(Point points[],int n)
{
    int ymin = points[0].y , min=0;
    for(int i=1;i<n;i++)
    {
        int y=points[i].y;
        
        if((y<ymin) || (ymin==y && points[i].x<points[min].x))
            ymin = points[i].y , min=i;
        
    }
    
    swap(points[0],points[min]);
    
    p0 = points[0];
    qsort(&points[1] , n-1 , sizeof(Point) , compare);
    
    int m=1;
    for(int i=1;i<n;i++)
    {
        while(i<n-1 && orient(p0,points[i],points[i+1])==0)
            i++;
        
        points[m] = points[i];
        m++;
    }
    
    if (m<3) return;
    
    stack<Point> s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);
    
    for(int i=3;i<m;i++)
    {
        while (orient(nexttotop(s),s.top(),points[i])!=2)
            s.pop();
        s.push(points[i]);
    }
    
    vector<Point> v ;
    
    while(!s.empty())
    {
        Point p =s.top();
        v.push_back(p);
        s.pop();
    }
    
    int len=v.size();
    
    int xco=v[0].x;
    int yco=v[0].y;
    int index=0;
    
    for(int i=0;i<len;i++)
    {
        if(xco>v[i].x)
        {
            index=i;
            xco=v[i].x;
            yco=v[i].y;
        }
    }
    cout<<endl<<len<<endl;
    
    for(int i=index;i<len;i++)
    {
        cout<<"("<<v[i].x<<" , "<<v[i].y<<")"<<endl;
    }
    
    for(int i=0;i<index;i++)
    {
        cout<<"("<<v[i].x<<" , "<<v[i].y<<")"<<endl;
    }
    
}

int main()
{
    Point p1;
    int T;
    cin>>T;
    Point points[T] ; 
    for(int i=0;i<T;i++)
    {
        cin>>p1.x>>p1.y;
        points[i]=p1;
    }
    convexHull(points,T);
}

