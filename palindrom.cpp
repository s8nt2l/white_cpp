#include <iostream>
#include <vector>
using namespace std;

bool isPalindrom(string s){
    for(int i = 0; i < s.length() / 2; i++){
        if(s[i] != s[s.length() - 1 - i])
            return false;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    cout <<  isPalindrom(s);
    return 0;
}