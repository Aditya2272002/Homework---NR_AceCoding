#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[],int l,int e){
    while(l<e){
        int temp = arr[l];
        arr[l] = arr[e];
        arr[e] = temp;
        l++;
        e--;
    }
}

void rotateArray(int arr[],int n,int d){
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 1;
    rotateArray(arr,n,d);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
