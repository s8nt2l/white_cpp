#include <iostream>
using namespace std;

int main(){
    int n, j = 1;
    cin >> n;
    if(n < 0)
        cout << 1;        
    else if(!n)
        cout << 0;
    else 
        for(int i = 1; i <= n; i++)
            j *= i;    
    cout << j;
    return 0;
}