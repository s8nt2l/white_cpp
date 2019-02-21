#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> db;
    vector <int> result;
    int N;
    cin >> N;
    db.resize(N);
    for(int i = 0; i < N; i++)
        cin >> db[i];
    N = 0;
    for(auto i : db)
        N += i;
    N /= db.size();
    int count = 0;
    for(int i = 0; i < db.size(); i++)
        if(db[i] > N){
            count++;
            result.push_back(i);
        }
    cout << count << endl;
    for(auto i : result)
        cout << i << ' ';
    return 0;
}