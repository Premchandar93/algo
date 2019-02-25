#include <iostream>
using namespace std;

#include <queue>



int main() {
    queue<int> q;
    
    q.push(10);
    q.push(11);
    int temp = q.front();
    cout<<temp;
    cout<<"\n";
    q.pop();
    temp = q.front();
    cout<<temp;
    	
}
