#include <iostream>
using namespace std;

void kadane_algo(int arr[], int n, int k){
    int max_so_far = 0;
    int max_ending_here =0;
    
    int start= 0 ;
    int end = 0;
    int flag = 0;
    for (int i=0 ; i< n; i++){
        max_ending_here += arr[i];

        if ( max_so_far < max_ending_here ){
            max_so_far = max_ending_here;
            if ( flag == 0){
                start = i;
                flag = 1;
            }
            else {
                end = i;
                
            }
        }
        
        if  (max_ending_here < 0){
            max_ending_here = 0;
        }
    }
    
    cout<<"Sum = "<<max_so_far<<", Start index = "<<start<<", End index = "<<end;


}


int main() {
	int array[] = {-2, -3, 4, -1, -3, 5,-5, 5,-5};
	int size = sizeof(array)/sizeof(array[0]);
	int ko = 3;
	kadane_algo(array, size, ko);
	return 0;
}
