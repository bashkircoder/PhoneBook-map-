#include <iostream>
#include <string>
#include <map>
#include "Map_Functions.h"
#include <vector>


using namespace std;




int main() {
    string input_path = "D:\\Study\\2511Class\\persons.txt";
    map<string, map<vector<string>, vector<string>>> contact;
    int choice; int count = 0;
    bool status = true;

    count = Count_ID(input_path);

    contact = FillPersonsToMapFromFile(input_path);

    while (status == true){
        cout << "\nWhat you want to do?" << endl;
        cout << "1. Add person" << endl;
        cout << "2. Find person" << endl;
        cout << "3. Show all contacts" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:{
                cout << "Enter the last name of person" << endl;
                string last_name;
                cin >> last_name;
                cout << "Enter the first name of person" << endl;
                string first_name;
                cin >> first_name;
                cout << "Enter the mobile telephone number of a person" << endl;
                string mob_number;
                cin >> mob_number;
                cout << "Enter the home telephone number of a person" << endl;
                string home_number;
                cin >> home_number;
                AddContactsToMap(&contact, last_name, first_name, mob_number, home_number,count);
                break;
            }
            case 2:{
                cout << "Enter the name of person you want to find" << endl;
                string name, number;
                cin >> name;
                FindNumberOfPerson(contact, name);
                break;
            }
            case 3:{
                PrintMap(contact);
                break;
            }
            case 4:{
                RewriteBookFromMap(contact, input_path);
                status = false;
            }
        }

    }





    return 0;
}
