// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<vector>

void insertionSort(vector<int> array, int size,int &counter) {
  for (int step = 1; step < size; step++) {
      counter++;
    int key = array[step];
    counter++;
    int j = step - 1;
    counter++;

    
    while (j >=0 && key < array[j]) {
        
      array[j + 1] = array[j];
      --j;
      counter++;
    }
    array[j + 1] = key;counter++;
  }
}

int main() {
      int n;
    cout<<"Enter no of inputs ";
    cin>>n;
    vector<int>arr(n);
    
    for(int i=0;i<n;i++){
        
        int t=rand();
        arr[i]=t;
    }
    int counter=0;
    insertionSort(arr,n,counter);
    cout<<counter<<endl;
    
    
   

    return 0;
}
