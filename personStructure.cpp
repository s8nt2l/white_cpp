#include <iostream>
#include <vector>
#include <map>
//#include <stl_pair.h>
using namespace std;

struct Person{
private:
    string first_name = "", last_name = "";
    map<int, Person> persons;
public:
    void ChangeFirstName(int year, const string& first_name){
        persons[year].first_name = first_name;
    }
    void ChangeLastName(int year, const string& last_name){
        persons[year].last_name = last_name;
    }
    string GetFullName(int year){
        int position = -1;
        for(int i = 0; i < persons.length(); i++){
            if(persons[i].first == year){
                position = i;
                break;
            }

        }
        if(position == -1)
            cout << "Incognito" << end;
        else{
            string temp_first_name, temp_last_name;
            int v = 0;
            for(int i = position; i >= 0; i--){
                if(persons[i].second.first_name != "" && temp_first_name.length() == 0)
                    temp_first_name = persons[i].second.first_name;
                if(persons[i].second.last_name != "" && temp_last_name.length() == 0)
                    temp_last_name = persons[i].second.last_name;
                if(!temp_first_name.length() && !temp_last_name.length()){
                    cout << temp_first_name << " " << temp_last_name << endl;
                    break;
                    v = 1;
                }
            }
            if(!v && !temp_last_name.length()){
                cout << temp_first_name << "  with unknown last name" << endl; 
            }

        }
    }
};

int main(){
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    system("pause");
    return 0;
}