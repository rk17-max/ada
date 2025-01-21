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
    
    int small;
    int counter=0;
    for(int i=0;i<n;i++){
        counter++;
        small=i;
        
        for(int j=i+1;j<n;j++){
            counter++;
            if(arr[j]<arr[small]){
                small=j;
                swap(arr[i],arr[small]);
                counter++;
            }
        }
    }
    cout<<counter<<endl;
  
    
   

    return 0;
}
