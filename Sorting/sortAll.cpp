#include<bits/stdc++.h>
using namespace std;

void fun(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   #ifndef ONLINE_JUDGE
   freopen("i.txt","r",stdin);
   freopen("o.txt","w",stdout);
   #endif
}

void printing(int arr[],int n){
   for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
   }
   cout<<"\n";
}

void selectionSort(int arr[],int n){
   for(int i=0;i<n;i++){
      int smallestIndex = i;
      for(int j=i+1;j<n;j++){
         if(arr[j] < arr[smallestIndex]){
            smallestIndex = j;
         }
      }
      swap(arr[i],arr[smallestIndex]);
   }
}

void bubbleSort(int arr[],int n){
   for(int i=0;i<n;i++){
      for(int j=0;j<n-1-i;j++){
         if(arr[j] > arr[j+1]){
            swap(arr[j],arr[j+1]);
         }
      }
   }
}

void insertionSort(int arr[],int n){
   for(int i=1;i<n;i++){
      int j = i-1;
      int temp = arr[i];
      while(j>=0 && arr[j] > temp){
         arr[j+1] = arr[j];
         j--;
      }
      arr[j+1] = temp;
   }
}

int merges(int arr[],int l,int mid,int h){
  vector<int> arr1;
  vector<int> arr2;

   for(int i=l;i<=mid;i++){
      arr1.push_back(arr[i]);
   }

   for(int i=mid+1;i<=h;i++){
      arr2.push_back(arr[i]);
   }

   int n = arr1.size();
   int m = arr2.size();
   int i=0,j=0;
   
   int k = l;
   while(i<n && j<m){
      if(arr1[i] < arr2[j]){
         arr[k] = arr1[i];
         i++;
      }else {
         arr[k] = arr2[j];
         j++;
      }
      k++;
   }

   while(i<n){
      arr[k] = arr1[i];
      i++;
      k++;
   }

   while(j<m){
      arr[k] = arr2[j];
      j++;
      k++;
   }
}

void mergeSorts(int arr[],int l,int h){
   if(l>=h) return;
   int mid = (l+h)/2;
   mergeSorts(arr,l,mid);
   mergeSorts(arr,mid+1,h);
   merges(arr,l,mid,h);
}

int partitions(vector<int>&arr,int l,int h){
   int less = l,more = h;
   int pivot = arr[l];

   while(less < more){
      while(less < h && arr[less] <= pivot){
         less++;
      }

      while(more > l && arr[more] > pivot){
         more--;
      }
      if(less < more){
         swap(arr[less], arr[more]);
      }
   }

   swap(arr[l],arr[more]);
   return more;
}

void quickSort(vector<int> &arr,int l,int h){

   if(l>=h) return;

   int piovot_index = partitions(arr,l,h);
   quickSort(arr,l,piovot_index-1);
   quickSort(arr,piovot_index+1,h);
}


int main(){
   fun();
   // int n;
   // cin>>n;
   // int arr[n];
   // for(int i=0;i<n;i++){
   //    cin>>arr[i];
   // }
   int n = 6;
   int arr[n] = {5,87,23,1,34,9};

   // O(n^2)
   //selectionSort(arr,n); 
   //bubbleSort(arr,n);
   // insertionSort(arr,n);

   //O(nlogn)
   mergeSorts(arr,0,n-1);
   //quickSort(arr,0,n-1);

   printing(arr,n);
   return 0;
}