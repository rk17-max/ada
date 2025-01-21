// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<vector>

int main() {
   
    
    int n;
    cout<<"Enter no of inputs ";
    cin>>n;
    vector<int>arr(n);
    
    for(int i=0;i<n;i++){
        
        int t=rand();
        arr[i]=t;
    }
    
   int count=0;
    for(int i=0;i<n-1;i++){
         count++;
        for(int j=i+1;j<n;j++){
               count++;
            if(arr[j]<arr[i]){
                
                swap(arr[i],arr[j]);
                count++;
            }
        }
    }
    cout<<count;
    
    
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<endl;
    // }
    
   

    return 0;
}
