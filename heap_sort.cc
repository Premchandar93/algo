#include <iostream>
using namespace std;

int heapify(int arr[], int ind, int n){
    int root = ind;
    int left = root*2 + 1;
    int right = root*2 + 2;
    
    if ( root > n){
        return 0;
    }
    
    if ( left < n && arr[left] < arr[root]){
        swap(arr[root], arr[left]);
        
    }
    
    if ( right < n && arr[right] < arr[root]){
        swap(arr[root], arr[right]);
        
    }

    heapify(arr, left,n);
    heapify(arr, right,n);
    
}

void heapsort(int arr[], int n){
    int startindex = 0;
    heapify(arr,startindex,n);

    swap(arr[0],arr[n-1]);
    for( int i=n-1;i>0 ;i--){
        heapify(arr,0,i);
        swap(arr[0],arr[i-1]);
    }

    for( int i=0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    
    
}


int main() {
    int array[] = {1,5,2,4,3,6};
    int n = sizeof(array)/sizeof(array[0]);

    heapsort(array, n);

	return 0;
}

