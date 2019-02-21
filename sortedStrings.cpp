#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct sortedStrings{
private:
    vector<string> Strings;
public:
    void AddString(string String){
        Strings.push_back(String);
        sort(Strings.begin(), Strings.end());
    }
    vector<string> GetSortedStrings(){
        return Strings;
    }
};

void PrintSortedStrings(sortedStrings& strings){
    for(const string& c : strings.GetSortedStrings())
        cout << c << " ";
    cout << endl;
}

int main(){
    sortedStrings s;
    s.AddString("third");
    s.AddString("afasf");
    s.AddString("first");
    PrintSortedStrings(s);
    s.AddString("aaaaa");
    PrintSortedStrings(s);
    system("pause");
    return 0;
}