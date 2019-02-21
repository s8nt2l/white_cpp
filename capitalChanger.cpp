#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, string> capitals;
    string command, parameter1, parameter2;
    for(int i = 0; i < n; i++){
        cin >> command;
        if(command == "CHANGE_CAPITAL"){
            cin >> parameter1 >> parameter2;
            if(capitals.find(parameter1) == capitals.end())
                cout << "Introduce new country " << parameter1 <<  " with capital "<< parameter2 << endl;            
            else if(capitals[parameter1] == parameter2){
                cout << "Country " << parameter1<< " hasn't changed its capital" << endl;
                continue;
            }
            else 
                cout << "Country " << parameter1 << " has changed its capital from " << capitals[parameter1] << " to " << parameter2 << endl;
            capitals[parameter1] = parameter2;
        }
        else if(command == "RENAME"){
            cin >> parameter1 >> parameter2;
            if(capitals.find(parameter1) == capitals.end())
                cout << "Incorrect rename, skip" << endl;
            else {
                cout <<"Country " << parameter1 << " with capital " << capitals[parameter1] << " has been renamed to " << parameter2 << endl;
                capitals[parameter2] = capitals[parameter1];
                capitals.erase(parameter1);                
            }

        }
        else if(command == "ABOUT"){
            cin >> parameter1;
            if(capitals.find(parameter1) == capitals.end())
                cout << "Country " << parameter1 << " doesn't exist" << endl;
            else
                cout << "Country " << parameter1 << " has capital " << capitals[parameter1] << endl;
        }
        else if(command == "DUMP"){
            if(!capitals.size())
                cout << "There are no countries in the world" << endl;
            else 
                for(auto c : capitals)
                    cout << c.first << ' ' << c.second;
        }

    }
    return 0;
}
/*
6
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME RussianEmpire RussianRepublic
ABOUT RussianRepublic
RENAME RussianRepublic USSR
CHANGE_CAPITAL USSR Moscow
DUMP

Introduce new country RussianEmpire with capital Petrograd
Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
Country RussianRepublic has capital Petrograd
Country RussianRepublic with capital Petrograd has been renamed to USSR
Country USSR has changed its capital from Petrograd to Moscow
USSR/Moscow


*/
