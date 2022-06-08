#include<bits/stdc++.h>
using namespace std;

vector<int> allsubsets;

void func(vector<int> &v,int i,int &sum){
     if(i<0){
         allsubsets.push_back(sum);
         return;
     }
     func(v,i-1,sum);
     sum+=v[i];
     func(v,i-1,sum);
     sum-=v[i];
}

int main(){
   
    vector<int> v = {1,2,3};
    int sum=0;
    func(v,v.size()-1,sum);
   
    for(auto i:allsubsets) 
        cout<<i<<endl;

}