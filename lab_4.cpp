#include <bits/stdc++.h>
#define f(a, b, c) for (long long int a = b; a < c; a++)
using namespace std;


int ord(string a) 
{ 
    if(a == "^") 
    return 3; 
    else if(a == "*" || a == "/") 
    return 2; 
    else if(a == "+" || a == "-") 
    return 1; 
    else
    return -1; 
} 

vector<string> sTv(string s)
{
    int n = s.length();
    vector<string> stv;
    for(int i = 0; i<n;i++)
    {
        string temp="";
        if((s[i] >= '0' && s[i] <= '9')) 
        {
            int j = i;
            for(;(s[j] >= '0' && s[j] <= '9');j++)
            {
                temp+=s[j];
            }
            i = j-1;
        }
        else 
        {
            temp+=s[i];
        }
        stv.push_back(temp);

    }

    return stv;
}


vector<string> inftopos(vector<string> s) 
{ 
    stack<string> st; 
    st.push("N"); 
    int l = s.size(); 
    vector<string> ns;
    for(int i = 0; i < l; i++) 
    { 
        if((s[i][0] >= '0' && s[i][0] <= '9')) 
            ns.push_back(s[i]);
        else if(s[i] == "(") 
           st.push("("); 
        else if(s[i] == ")") 
        { 
            while(st.top() != "N" && st.top() != "(") 
            { 
                string c = st.top(); 
                st.pop(); 
                ns.push_back(c);
            } 
            if(st.top() == "(") 
            { 
                string c = st.top(); 
                st.pop(); 
            } 
        } 
        else{ 
            while(st.top() != "N" && ord(s[i]) <= ord(st.top())) 
            { 
                if(s[i]=="^"&&st.top()=="^") break;
                string c = st.top(); 
                st.pop(); 
                ns.push_back(c); 
            } 
            st.push(s[i]); 
        } 
  
    } 
    while(st.top() != "N") 
    { 
        string c = st.top(); 
        st.pop(); 
        ns.push_back(c); 
    } 
      
    return ns;
  
} 

struct node
{
  string s;
  node* left=NULL,*right=NULL;
};

node* ct(vector <string> PFIX)
{
       node *root=NULL;
       vector <node*> stack1;
       int i=0;
       while(i!=PFIX.size())
       {
         if(PFIX[i]!="+" && PFIX[i]!="-" && PFIX[i]!="*" && PFIX[i]!="/" && PFIX[i]!="^")
           {
                 node *temp=(node *)malloc(sizeof(node));

                 temp->s=PFIX[i];

                 f(j,0,PFIX[i].size())

                 if(PFIX[i][j]<'0' || PFIX[i][j]>'9')return NULL;

                 stack1.push_back(temp);
           } 
         else
         {
               if(stack1.size()<2)return NULL;

               node *s1=stack1.back();

               stack1.pop_back();

               node *s2=stack1.back();

               stack1.pop_back();

               node *temp=(node *)malloc(sizeof(node));

               temp->s=PFIX[i];

               temp->left=s2;

               temp->right=s1;

               stack1.push_back(temp); 
         }
         i++;
       }
       if(stack1.size()!=1)
            return NULL;
       return stack1.back();
}


long long int evaluate(node *root)
{
   string s=root->s;
   long long int answer=0;
   if(s!="+" && s!="-" && s!="*" && s!="/" && s!="^")
   return stoi(s);
   else
   {
     int lanswer=evaluate(root->left),ranswer=evaluate(root->right);

     if(s=="+")
       answer=lanswer+ranswer;
     else if(s=="-")
       answer=lanswer-ranswer;
     else if(s=="*")
       answer=lanswer*ranswer;
     else if(s=="/")
       answer=lanswer/ranswer;
     else
     {
       answer=1;
       f(i,0,ranswer)answer*=lanswer;
     }
   }
   return answer;
}
int main() 
{ 
  int q;
  cin>>q;
  while(q--)
  {
    int n;
    cin>>n;
    for(long long int i = 0;i<n;i++)
    {
      string s;

      cin>>s;

      vector <string> newv=sTv(s);

      newv=inftopos(newv);

      node* root=ct(newv);

      if(root!=NULL)
        {
          cout<<evaluate(root)<<"\n";
        }
      else 
      {
        cout<<"CANT BE EVALUATED\n";
      }
    }
  }
  return 0; 	
}

