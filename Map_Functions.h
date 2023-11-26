#ifndef INC_2511CLASS_MAP_FUNCTIONS_H
#define INC_2511CLASS_MAP_FUNCTIONS_H
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

string Parser(string* str, char delimiter) {
    auto position = str->find(delimiter);
    auto result = str->substr(0, position);
    *str = str->substr(position + 1);

    return result;
}

int Count_ID (string input_path){
    int count = 0;
    ifstream file;
    file.open(input_path);
    while (!file.eof()){
        string str;
        getline(file, str);
        count++;
    }

    file.close();
    return count;
}

map<string, map<vector<string>, vector<string>>> FillPersonsToMapFromFile (string input_path){
    map<string, map<vector<string>, vector<string>>> contact;
    ifstream input;
    input.open(input_path);

    while (!input.eof()){
        string str, id, first_name, last_name, mob_number, home_number; char delimiter = ' ';
        map<vector<string>, vector<string>> Data;
        vector<string> Full_name; vector<string> Numbers;
        getline(input,str);
        id = Parser(&str, delimiter);
        last_name = Parser(&str, delimiter);
        first_name = Parser(&str, delimiter);
        mob_number = Parser(&str, delimiter);
        home_number = str;
        Full_name.push_back(last_name);
        Full_name.push_back(first_name);
        Numbers.push_back(mob_number);
        Numbers.push_back(home_number);
        Data.insert(pair<vector<string>, vector<string>>(Full_name, Numbers));
        contact.insert(pair<string, map<vector<string>, vector<string>>>(id, Data));

    }

    input.close();
    return contact;
}

void AddContactsToMap(map<string, map<vector<string>, vector<string>>>* Contact, string last_name, string first_name, string mob_number, string home_number, int count_id){
    count_id+=1;
    string id = "id" + to_string(count_id);
    map<vector<string>, vector<string>> Data;
    vector<string> Full_name; vector<string> Numbers;
    Full_name.push_back(last_name);
    Full_name.push_back(first_name);
    Numbers.push_back(mob_number);
    Numbers.push_back(home_number);
    Data.insert(pair<vector<string>, vector<string>>(Full_name, Numbers));
    Contact->insert(pair<string, map<vector<string>, vector<string>>>(id, Data));

}

void RewriteBookFromMap(map<string, map<vector<string>, vector<string>>> Contact, string output_path){
    ofstream output;
    output.open(output_path, ios_base::trunc);
    int count = 0;

    for (auto str : Contact) {
        count+=1;
        auto id = str.first;
        auto data = str.second;
        vector<string> Full_name;
        vector<string> Numbers;
        for (auto item : data){
            Full_name = item.first;
            Numbers = item.second;
        }
        if (Contact.size() == count) {
            output << id << " " << Full_name[0] << " " << Full_name[1] << " " << Numbers[0] << " " << Numbers[1];
        } else {
            output << id << " " << Full_name[0] << " " << Full_name[1] << " " << Numbers[0] << " " << Numbers[1] << endl;
        }
        data.clear();
        Full_name.clear();
        Numbers.clear();
    }

    output.close();
}

void FindNumberOfPerson (map<string, map<vector<string>, vector<string>>> Contact, string name){

    for (auto str : Contact) {
        auto id = str.first;
        auto data = str.second;
        vector<string> Full_name;
        vector<string> Numbers;
        for (auto item: data) {
            Full_name = item.first;
            Numbers = item.second;
        }
        if ((Full_name[0].find(name) != string::npos) || (Full_name[1].find(name) != string::npos)) {
            cout << "\n" << id << "\nName: " << Full_name[0] << " " << Full_name[1] << endl;
            cout << "Mobile number: " << Numbers[0] << endl;
            cout << "Home number: " << Numbers[1] << endl;
            data.clear();
            Full_name.clear();
            Numbers.clear();
        }
    }
}

void PrintMap (map<string, map<vector<string>, vector<string>>> Contact){

    for (auto str : Contact) {
        auto id = str.first;
        auto data = str.second;
        vector<string> Full_name;
        vector<string> Numbers;
        for (auto item : data){
            Full_name = item.first;
            Numbers = item.second;
        }
        cout << "\n" << id << "\nName: " << Full_name[0] << " " << Full_name[1] << endl;
        cout << "Mobile number: " << Numbers[0] << endl;
        cout << "Home number: " << Numbers[1] << endl;
        data.clear();
        Full_name.clear();
        Numbers.clear();
    }

}





#endif //INC_2511CLASS_MAP_FUNCTIONS_H
