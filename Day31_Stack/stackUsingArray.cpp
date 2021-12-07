#include<iostream>
using namespace std;

template <class T>
class Stack{
   private:
      T* S;
      int top;
      int size;

   public:
      Stack(){
         S = new T[1000];
         top = -1;
         size = 1000;
      }

      void push(T data){
         if(top==size-1){
            cout<<"Stack Full \n";
            return;
         }
         top++;
         S[top] = data;
         size--;
      }

      T pop(){
         if(top==-1){
            cout<<"Stack Empty \n";
            return NULL||0;
         }
         T del = S[top];
         top--;
         size++;
         return del;
      }

      T topMost(){
         if(top==-1){
            cout<<"Stack Empty \n";
            return NULL||0;
         }
         return S[top];
      }

      void display(){
         int i = top;
         while (i>=0)
         {
            cout<<S[i]<<"\n";
            i--;
         }
         cout<<"\n";
      }
};

int main(){
   Stack<float> st;
   st.push(120.5f);
   st.push(23.3f);
   cout<<st.topMost();
   st.display();
   return 0;
}