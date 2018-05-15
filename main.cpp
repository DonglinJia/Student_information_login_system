//
//  main.cpp
//  Student_information_system_look_up
//
//  Created by Leo Jia on 2018-04-17.
//  Copyright © 2018 Leo Jia. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

struct student {
    bool coop;
    string name;
    string major;
    string current_level;
    string login;
    string addr;
    string email;
    string cell;
    string number;
    int height;
    int weight;
    int current_gpa;
};

string combine(string a, string b) {
    return a + b;
}


void open() {
    cout << "Please enter the name of the university: ";
    string univer;
    cin >> univer;
    cout <<"Please enter the name of the student: ";
    string name;
    cin >> name;
    string path  = combine(combine(combine(combine("/Users/Leo/Desktop/", univer),"/"),name),".txt");
    char cmd[1024];
    memset(cmd,0,1024);
    sprintf(cmd, "open %s", path.c_str());
    system(cmd);
}

void mydelete() {
    cout << "Please enter the name of the university: ";
    string univer;
    cin >> univer;
    cout <<"Please enter the name of the student: ";
    string name;
    cin >> name;
    string path  = combine(combine(combine(combine("/Users/Leo/Desktop/", univer),"/"),name),".txt");
    char cmd[1024];
    memset(cmd,0,1024);
    sprintf(cmd, "rm %s", path.c_str());
    system(cmd);
}

bool check_psw(string pass) {
    int count = 1;
    int upper = 0;
    int special = 0;
    for (string::iterator it = pass.begin(); it != pass.end(); it++) {
        if (*it >= 'A' && *it <= 'Z') upper++;
        if (*it < 'A' || (*it > 'Z' && *it < 'a') || *it > 'z') special++;
        ++count;
    }
    return (count >= 8) && upper && special;
}

void print(struct student *s) {
    cout<< "Student name: "<<s->name<<endl;
    cout<< "Student's number: "<<s->number<<endl;
    cout<< "Student's height: "<<s->height<<"cm"<<endl;
    cout<< "Studnet's weight: "<<s->weight<<"kg"<<endl;
    cout<< "Student's major: "<<s->major<<endl;
    cout<< "Student's current_year: "<<s->current_level<<endl;
    cout<< "Student's current_gpa: "<<s->current_gpa<<"%"<<endl;
    if (s->coop) {
        cout<< "Is student in Coop-Program: Yes"<<endl;
    } else {
        cout<< "Is student in Coop-Program: No"<<endl;
    }
}

void fix(struct student *s) {
    cout << "Which section do you want to fix? "<<endl;
    string selection;
    cin.ignore();
    getline(cin, selection);
    if (!selection.compare("name")){
        string name;
        cout<< "Student name: ";
        getline(cin, name);
        s->name = name;
    } else if (!selection.compare("number")) {
        string num;
        cout<< "Student's number: ";
        cin>>num;
        s->number = num;
    } else if (!selection.compare("height")) {
        int hei;
        cout<< "Student's height: ";
        cin>>hei;
        s->height = hei;
    } else if (!selection.compare("weight")) {
        int wei;
        cout<< "Studnet's weight: ";
        cin>>wei;
        s->weight = wei;
    } else if (!selection.compare("major")) {
        string maj;
        cout<< "Student's major: ";
        getline(cin, maj);
        s->major = maj;
    } else if (!selection.compare("current_year")) {
        string lvl;
        cout<< "Student's current_year: ";
        getline(cin, lvl);
        s->current_level = lvl;
    } else if (!selection.compare("gpa")) {
        int gpa;
        cout<< "Student's current_gpa: ";
        cin>>gpa;
        s->current_gpa = gpa;
    } else if (!selection.compare("coop")) {
        char a;
        cout<<"In coop? ";
        cin>>a;
        if (a == 'y' || a == 'Y') {
            s->coop = 1;
        } else {
            s->coop = 0;
        }
    }
}


void info(struct student *stud) {
    string num;
    int hei;
    int wei;
    int gpa;
    string cell;
    string maj;
    string lvl;
    string login;
    string name;
    string address;
    string email;
    
    cout<< "Student's name: ";
    getline(cin, name);
    stud->name = name;
    
    cout << "Student number: ";
    cin>>num;
    stud->number = num;
    
    cout << "Student's height: ";
    cin>>hei;
    stud->height = hei;
    
    cout << "Student's weight: ";
    cin>>wei;
    stud->weight = wei;
    cin.ignore();
    
    cout << "Student's major: ";
    getline(cin, maj);
    stud->major = maj;
    
    cout << "Student's current_year: ";
    getline(cin, lvl);
    stud->current_level = lvl;
    
    cout << "Student's current_grade: ";
    cin>>gpa;
    while (gpa < 0 || gpa > 100) {
        cout << "ERROR! Please enter again! ";
        cin >> gpa;
    }
    stud->current_gpa = gpa;
    
    cout<<"Student's address: ";
    cin.ignore();
    getline(cin, address);
    stud->addr = address;
    
    cout << "Student's phone number: ";
    cin>>cell;
    stud->cell = cell;
    cout << "Student's email address: ";
    cin.ignore();
    getline(cin, email);
    stud->email = email;
    cout<< "Is this student in Coop-Program? ";
    char a;
    cin>>a;
    if (a == 'y' || a== 'Y') {
        stud->coop = 1;
    } else {
        stud->coop = 0;
    }
    
    cout<< "Contain at least one Uppercase letter, special char and length must at least be 8."<<endl;
    cout<< "Student login password: ";
    cin.ignore();
    getline(cin, login);
    while (!check_psw(login)) {
        cout<< "Please enter a new password!";
        cout<< "Contain at least one Uppercase letter, special char and length must at least be 8."<<endl;
        cin.ignore();
        getline(cin, login);
    }
    stud->login = login;
}


void write_file (struct student *s, string university) {
    string fname = s->name;
    ostringstream testfile;
    string path = "/Users/Leo/Desktop/";
    string new_path = combine(combine(path, university), "/");
    
    testfile << new_path << fname << ".txt";
    ofstream out(testfile.str().c_str(),ios_base::binary);
    
    string path_to_file = combine(combine(new_path, fname), ".txt");
    
    ofstream myfile;
    myfile.open(path_to_file);
    
    if (!myfile) {
        cout<<"Cannot open file."<<endl;
    } else {
        myfile << "Stduent's name: "<<s->name<<"\n";
        myfile << "Student's number: "<<s->number<<"\n";
        myfile << "Student's phone number: "<<s->cell<<"\n";
        myfile << "Student's home address: "<<s->addr<<"\n";
        myfile << "Student's email address: "<<s->email<<"\n";
        myfile << "Student's height: "<<s->height<<"\n";
        myfile << "Student's weight: "<<s->weight<<"\n";
        myfile << "Stduent's major: "<<s->major<<"\n";
        myfile << "Student's current gpa: "<<s->current_gpa<<"\n";
        myfile << "Student's current year: "<<s->current_level<<"\n";
        myfile << "Stduent's in Coop program: "<<s->coop<<"\n";
    }
}
    
string build_folder () {
    cout<<"Please enter the name of school(use '_' to indicate ' ': ";
    char cmd_str[1024];
    memset(cmd_str, 0, 1024);
    string university;
    cin >> university;
    sprintf(cmd_str, "mkdir /Users/Leo/Desktop/%s", university.c_str());
    system(cmd_str);
    cin.ignore();
    return university;
}

int main() {
    char school = '\0';
    char anw;
    do {
        string lokup = "a";
        lokup = build_folder();
        do {
            struct student s;
            info(&s);
            print(&s);
            cout<<"Is there is an error? Enter (y/n)"<<endl;
            string a;
            cin >> a;
            while (a == "y") {
                fix(&s);
                print(&s);
                cout<<"Is there still an error? (y/n)"<<endl;
                cin>>a;
            }
            cout<<"Do you want to enrol this person? (y/n)"<<endl;
            char b;
            cin >> b;
            if (b == 'y') write_file(&s, lokup);
            cout << "Do you want to enrol another student? ";
            cin >> anw;
            if (anw != 'y') break;
            cout << "Same university? (y/n)";
            cin >> school;
            cin.ignore();
        } while (anw == 'y' && school == 'y');
    } while (anw == 'y' && school == 'n');
    
    char c;
    do {
        string see;
        cout <<"Do you want to see the file? (y/n) ";
        cin >> see;
        if (see == "y") open();
        else break;
        cout << "Do you want to see another student file? ";
        cin >> c;
    } while (c == 'y');
    
    cout << "Is this satisfied? (y/n)";
    char b;
    cin >> b;
    if (b == 'y') cout << "Thanks for your work! "<<endl;
    else {
        cout<<"Sorry about the errors! "<<endl;
        cout << "Do you want to delete the file? (y/n) ";
        char d;
        cin >> d;
        if (d == 'y') mydelete();
        cout<<"Thanks for using!"<<endl;
    }
    return 0;
}

















