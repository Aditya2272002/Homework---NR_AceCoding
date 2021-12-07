#include<iostream>
using namespace std;

template<typename T1,typename T2>
struct fun1{
   fun1(T1 d1,T2 d2){
      cout<<d1<<" "<<d2<<"\n";
   } 
};

template<typename T>
struct fun2{
   T y;
   fun2(T a){
      y = a;
   }
   T getSecond();
};

template<typename T>
T fun2<T>::getSecond(){
return y;
};

int main()
{
   fun1<int,int> t(30,50);
   fun2<int> t2(200);
   cout<<t2.getSecond();
   return 0;
} 