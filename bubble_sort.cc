#include <iostream>

using namespace std;

void bubblesort(int arr[], int n){
    int swapped =0;
    int outerloop = 0;
    int innerloop = 0;
    for (int i=0; i< n-1; i++){
        
        swapped = 0;
        for ( int j=0; j< n-1; j++){
            
            if ( arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = 1;
            }
        }
        if (swapped == 0){
            break;
        }
    }
    
    for(int k =0; k< n;k++){
        cout<<arr[k]<<" ";
    }

}


int main()
{
    
    int array[] = {5,4,3,2,1};
    int n = sizeof(array)/sizeof(array[0]);
    
    bubblesort(array,n);
   
    return 0;
}