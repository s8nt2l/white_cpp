#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<char, int> BuildCharCounters(string s){
    map<char, int> result;
    for(auto c : s)
        result[c]++;
    return result;

}

int main(){
    int n;
    cin >> n;
    string temp1, temp2;
    for(int i = 0; i < n; i++){
        cin >> temp1;
        cin >> temp2;
        if(BuildCharCounters(temp1) == BuildCharCounters(temp2))
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    return 0;
}