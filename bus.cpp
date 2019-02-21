#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    map <string, vector <string>> bus_db;
    string command, bus, stop;
    int stop_count;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> command;
        if(command == "NEW_BUS"){
            cin >> bus;
            cin >> stop_count;
            bus_db[bus].resize(stop_count);
            for(int i = 0; i < stop_count; i++)
                cin >> bus_db[bus][i];            
        }
        else if(command == "BUSES_FOR_STOP"){
            cin >> stop;
            int count = 0;            
            for(auto c : bus_db)
                if(find(c.second.begin(), c.second.end(), stop) != c.second.end())
                    count++;
            if(!count)
                cout << "No stop" << endl;
            else{                
                for(auto c : bus_db)
                    if(find(c.second.begin(), c.second.end(), stop) != c.second.end())
                        cout << c.first << ' ';
                cout << endl;
            }
        }
        else if(command == "STOPS_FOR_BUS"){
            cin >> bus;
            int count = 0;
            if(bus_db.find(bus) == bus_db.end())
                cout << "No bus" << endl;
            else{
                //cout << "Bus " << bus << ": ";
                for(auto c : bus_db[bus]){
                    cout << "Stop "<< c << ": ";
                    for(auto w : bus_db){
                        if(find(w.second.begin(), w.second.end(), c) != w.second.end() && w.first != bus){
                            cout << w.first << ' ';
                            count++;
                        }
                                               
                    }
                    if(!count)
                        cout << "no interchange"; 
                    count = 0;
                    cout << endl;
                    
                }
                cout << endl;
            }
        }
        else if(command == "ALL_BUSES"){
            if(bus_db.size() == 0)
                cout << "0 buses" << endl;
            else{                
                for(auto c : bus_db){
                    cout << "Bus " << c.first << ": ";
                    for(auto w : c.second)
                        cout << w << ' ';
                    cout << endl;
            }
            }
        }


    }
    return 0;
}
/*
10
ALL_BUSES
BUSES_FOR_STOP Marushkino
STOPS_FOR_BUS 32K
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
STOPS_FOR_BUS 272
ALL_BUSES


o buses
No stop
No bus
32 32K
Stop Vnukovo: 32 32K 950
Stop Moskovsky: no interchange
Stop Rumyantsevo: no interchange
Stop Troparyovo: 950
Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
Bus 32: Tolstopaltsevo Marushkino Vnukovo
Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
*/