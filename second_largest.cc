#include <iostream>
using namespace std;

void findsecondmax(int arr[], int n, int k){
    
    int firstmax = arr[0];
    int secondmax = -1;
    
    
    for ( int i=1; i<n; i++){
        if ( arr[i] > firstmax){
            secondmax = firstmax;
            firstmax = arr[i];
        }
    }
    
    if ( secondmax == -1){
        cout<<"Nothing found";
    }
    else {
        cout<<secondmax;
    }
    
}

int main() {
	int array[] = {1,1,1};
	int size = sizeof(array)/sizeof(array[0]);
	int max = 2;
	
	findsecondmax(array, size, max);
	return 0;
}
