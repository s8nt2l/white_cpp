#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <vector>
using namespace std;

bool reg(char c1, char c2){
    return (tolower(c1) < tolower(c2));
}

int main(){
    int n;
    cin >> n;
    vector<char> v(n);
    for(char& c : v)
        cin >> c;
    sort(v.begin(), v.end(), reg);
    for(auto c : v)
        cout << c;
    system("pause");
    return 0;
}