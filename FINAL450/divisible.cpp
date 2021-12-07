#include <iostream>
using namespace std;

int fm = 0;
int fp = 0;

int Minus(int num){
    if((num - 1)%3==0){
        fm += 1;
        return 1;   
    }
    else 
        return 0; 
}

int Plus(int num){
    if((num + 1)%3==0){
        fp += 1;
        return 1;   
    }
    else 
        return 0; 
}

int main() {
	int T;
	cin>>T;
	while(T>0){
	    fp = 0;
	    fm = 0;
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    //Code
	    
	    int times = 0;
	    for(int i=0;i<n;i++){
	       if(arr[i]%3!=0){
	           if(Minus(arr[i])){
	                times += 1;
	            }else if(Plus(arr[i])){
	                times += 1;
	            }
	        }
	        
	    }
	    
	    if(fp==fm){
	        if(fp==0 && fm==0){
	            cout<<fp<<"\n";
	        }else{
	            cout<<fp<<"\n";  
	        }
	    }else{
	        cout<<"-1"<<"\n";
	    }
	    
	    T--;
	}
	return 0;
}
