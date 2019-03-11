
#include <iostream>
using namespace std;

void rotatematrix(int arr[3][3]){
    int size = 3;
    cout<<"Before rotation="<<"\n";
    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<"\n";
        }
    }
    int cycles = int(size/2);
    
    int i =0;
    int j=0 ;
    int n =2;
    while ( cycles > 0 ){
        int temp = arr[i][j];
        
        arr[i][j] = arr[n-j][i];
        arr[n-j][i] = arr[n][n-j];
        arr[n][n-j] = arr[j][n];
        arr[j][n] = temp;
        
        j++;
        if ( j >= n){
            i++;
            j =i;
            cycles--;
        }
    }
    cout<<"After rotation=\n";    
    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<"\n";
        }
    }
    
}

int main(){
    int array[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    
    rotatematrix(array);
    
    
}
