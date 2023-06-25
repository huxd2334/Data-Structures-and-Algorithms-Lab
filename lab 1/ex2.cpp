#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    string class_;
    float mMath;
    float mPhysical;
};
void add(vector<Student>& s) {
    Student student;
    cout<<"Name: ";
    getline(cin,student.name);
    cout<<"Class: ";
    getline(cin,student.class_);
    cout<<"Math mark: ";
    cin>>student.mMath;
    cout<<"Physical mark: ";
    cin>>student.mPhysical;
    s.push_back(student);
    
}
void find(vector<Student>& s) {
	
	string name;
    getline(cin, name);
    
    bool found = false;
    for(int i=0;i<s.size();i++){
        if (s.at(i).name == name) {
        	cout<<"\n";
            cout << "Name: " << s.at(i).name << endl;
            cout << "Class: " << s.at(i).class_ << endl;
            cout << "Math score: " << s.at(i).mMath << endl;
            cout << "Physical score: " << s.at(i).mPhysical << endl;
            found = true;
            break;
        }
    
}
    if (!found) {
        cout << "Not found" << endl;
    }
}
void find_edit(vector<Student>& s) {
    string name;
    getline(cin, name);

    bool found = false;
    for(int i=0;i<s.size();i++){
        if (s.at(i).name == name) {
        	cout<<"Change class: ";
            getline(cin, s.at(i).class_);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Not found" << endl;
    }
}

int main() {
    vector<Student> std;
    char choice;

    do {
        cout << endl << "==============MENU==============" << endl;
        cout << "1. Add a new student" << endl;
        cout << "2. Search a student by name" << endl;
        cout << "3. Search a student by name and edit their class" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case '1':
                add(std);
                break;
            case '2':
            	cout<<"Enter name: ";
               	find(std);
                break;
            case '3':
            	cout<<"Enter name: ";
                find_edit(std);
                break;
            case '4':
                break;
            default:
                cout << "Invalid choice! Enter again" << endl;
                break;
        }
    } while (choice != '4');

    return 0;
}
