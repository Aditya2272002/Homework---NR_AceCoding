#include<bits/stdc++.h>
using namespace std;

/*
CONCEPT :- 
 -> Works in Divide and Conquer Algo
 -> We divide the array till we get single element and then merge(i.e conquer) them using
    two-pointer approach.
*/


void merge(vector<int>& v,int l,int mid,int h){
    vector<int>arr1;
    vector<int>arr2;

    for(int p=l;p<=mid;p++){
        arr1.push_back(v[p]);
    }

    for(int q=mid+1;q<=h;q++){
        arr2.push_back(v[q]);
    }

    int n=arr1.size();
    int m=arr2.size();
    int k=l,i=0,j=0;

    while(i<n && j<m){
        if(arr1[i] <arr2[j]){
            v[k]=arr1[i];
            k++;
            i++;
        }else{
            v[k]=arr2[j];
            k++;
            j++;
        }
    }

    while(i<n){
        v[k]=arr1[i];
        k++;
        i++;
    }

    while(j<m){
        v[k]=arr2[j];
        k++;
        j++;
    }
}

void merge_Sort(vector<int>& v,int l,int h){
    if(l>=h){
        return;
    }
    int mid=(l+h)/2;
    merge_Sort(v,l,mid);
    merge_Sort(v,mid+1,h);
    merge(v,l,mid,h);
}

int main(){
    vector<int> v={100,90,80,70,333,3,1};

    int n = v.size()-1;
    merge_Sort(v,0,n);
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}