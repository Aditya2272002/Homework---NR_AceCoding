#include<bits/stdc++.h>
using namespace std;

bool containRedunded(string s){
   stack<char> st;
   int n = s.length();

   for(int i=0;i<n;i++){
      if(s[i]=='('){
         st.push('(');
      }else if(s[i]=='+'){
         st.push('+');
      }else if(s[i]=='-'){
         st.push('+');
      }else if(s[i]=='-'){
         st.push('+');
      }else if(s[i]=='*'){
         st.push('*');
      }else if(s[i]=='/'){
         st.push('/');
      }

      if(s[i]==')'){
         if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
            while(st.top() != '('){
               st.pop();
            }
            st.pop();
         }else{
            return false;
         }
      }
   }
   return true;
}


int main()
{
   string s1 = "(a+b)";
   string s2 = "(a+(b)/c)";
   string s3 = "(a+b*(c-d))";

   containRedunded(s1) ? cout<<"No\n":cout<<"Yes\n";
   containRedunded(s2) ? cout<<"No\n":cout<<"Yes\n";
   containRedunded(s3) ? cout<<"No\n":cout<<"Yes\n";



   return 0;
}