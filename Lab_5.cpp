#include<bits/stdc++.h>
using namespace std;

struct node
{
  string data;
  node *left = NULL; 
  node *right = NULL;
};

int isoperator(string c)
{
  if (c == "^" || c == "/" || c == "*" || c == "+" || c == "-"||c=="(")
    return 1;
  
  return 0;
}

int inpre(string c)
{
  if (c == "^")
    return 5;
  
  if (c == "*" || c == "/")
    return 4;
  
  if (c == "+" || c == "-")
    return 2;
  
  return 1;
}

int outpre(string c)
{
  if (c == "^")
    return 6;
  
  if (c == "*" || c == "/")
    return 3;
  
  if (c == "+" || c == "-")
    return 1;

  return -1;
}

vector<string> strvet(string s)
{
  vector<string> v;
  
  for (int i=0; i<s.length(); i++)
  {
    string temp = "\0";
      
    if ((s[i] >= '0' && s[i] <= '9'))
    {     
      while (s[i] >= '0' && s[i] <= '9')
      {
        temp += s[i];
        i++;
      }
          
      i--;
    }
      
    else
      temp += s[i];
      
    if (temp == "-" && (v.empty() || isoperator(v.back())))
      v.push_back("0");
      
    v.push_back(temp);
  }
    
  return v;
}

vector<string> inpost(vector<string> v)
{
  stack<string> A;
  vector<string> post;
  
  for (int i=0; i<v.size(); i++)
  {
    if ((v[i][0] >= '0' && v[i][0] <= '9'))
      post.push_back(v[i]);
      
    else if (v[i] == "(")
      A.push("(");
      
    else if (v[i] == ")")
    {
      while (!A.empty() && A.top() != "(")
      {
        post.push_back(A.top());
        A.pop();
      }
          
      if (A.top() == "(")
        A.pop();
    }
      
    else
    {
      while (!A.empty() && outpre(v[i]) < inpre(A.top()))
      {
        post.push_back(A.top());
        A.pop();
      }
          
      A.push(v[i]);
    }
  }
  
  while (!A.empty())
  {
    post.push_back(A.top());
    A.pop();
  }

  return post;
}

struct node *tree(vector<string> v)
{
  struct node *root = NULL;
  stack<struct node *> tree;
  int i = 0;
    
  while (i != v.size())
  {
    if (isoperator(v[i]))
    {
      if (tree.size()< 2)
        return NULL;
            
      struct node *t1 = tree.top();
      tree.pop();
        
      struct node *t2 = tree.top();
      tree.pop();
        
      struct node *temp = new struct node;
      temp->data = v[i];
      temp->left = t2;
      temp->right = t1;
      tree.push(temp);
    }

    else
    {
      struct node *temp = new struct node;
      temp->data = v[i];
      
      for(int j=0; j<v[i].length(); j++)
      {
        if (v[i][j] < '0' || v[i][j] > '9')
          return NULL;
      }
      
      tree.push(temp);
    }
        
    i++;
  }
    
  if (tree.size() != 1)
    return NULL;
    
  return tree.top();
}

int solve(struct node *root)
{
  string s = root->data;
  int val = 0;

  if (!isoperator(s))
    return stoi(s);
    
  else
  {
    int lval = solve(root->left);
    int rval = solve(root->right);
        
    if (s == "+")
      val = lval + rval;
        
    else if (s == "-")
      val = lval - rval;
    
    else if (s == "*")
      val = lval * rval;
    
    else if (s == "/")
      val = lval / rval;
    
    else
      val = pow(lval, rval);
  }
    
  return val;
}


int main()
{
  int n1;
  cin >> n1;
    
  for(int i=0; i<n1; i++)
  {
    int n2;
    cin >> n2;
    vector <char> v1;
    vector <int> v2;
    
    for(int j=0; j<n2; j++)
    {
      string s;
      cin >> s;
      
      if(s.length() == 1)
      {
        if(s[0] >= '0' && s[0] <= '9')
          cout << s << endl;

        else
        {
          int pos = -1;

          for(int k=0; k<v1.size(); k++)
          {
            if(v1.at(k) == s[0])
              pos = k;
          }

          if(pos == -1)
            cout << "CANT BE EVALUATED\n";

          else
            cout << v2.at(pos) << endl;
        }
      }

      else
      {
        int len = s.length();
       
        if(s[1] == '=')
        {
          int pos = 1;
          v1.push_back(s[0]);
          string temp = "\0";

          for(int l=2; l<len; l++)
          {
            if((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z'))
            {
              int pos = 0;
              for(int m=0; m<v1.size(); m++)
              {
                if(v1.at(m) == s[l])
                  pos = m;
              }       

              ostringstream str1; 
              str1 << v2.at(pos); 
              string geek = str1.str(); 
              temp += geek; 
            }

            else
              temp += s[l];
          }

          vector<string> str = strvet(temp);
          str = inpost(str);
          struct node *root = tree(str);
          v2.push_back(solve(root));
        }

        else
        {
          string temp = "\0";
          for(int x=0; x<len; x++)
          {
            if((s[x] >= 'a' && s[x] <= 'z') || (s[x] >= 'A' && s[x] <= 'Z'))
            {
              int pos = 0;
              for(int y=0; y<v1.size(); y++)
              {
                if(v1.at(y) == s[x])
                  pos = y;
              }
              
              ostringstream str1; 
              str1 << v2.at(pos); 
              string geek = str1.str(); 
              temp += geek;
            }

            else
              temp += s[x];
          }

          vector<string> str = strvet(temp);
          str = inpost(str);
          struct node *root = tree(str);
          cout << solve(root) << endl;
        }
      }
    }
  }
  
  return 0;
}
