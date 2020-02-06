#include "Roster.h"
#include "NetworkStudent.h"
#include "SoftwareStudent.h"
#include "SecurityStudent.h"
#include "Student.h"
#include <iostream>
#include "Degree.h"

using namespace std;

int main() {

    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                  "A5,Jarred,Wilson,jarred.wilson15@gmail.com,27,14,33,80,SOFTWARE"};
    string delimiter = ",";

    Roster roster = Roster();

    for(int i = 0; i < 5; i++) {
        size_t last = 0;
        size_t next = 0;
        string sub;
        string tempData[9];
        int j = 0;
        Degree degree;

        while((next = studentData[i].find(delimiter, last)) != string::npos) {
            sub = studentData[i].substr(last, next - last);
            tempData[j] = sub;
            j++;
            last = next + 1;
        }

        tempData[8] = studentData[i].substr(last, studentData[i].length() - 1);

        if(tempData[8] == "SOFTWARE")
            degree = SOFTWARE;
        else if (tempData[8] == "NETWORK")
            degree = NETWORK;
        else if (tempData[8] == "SECURITY")
            degree = SECURITY;

        roster.add(tempData[0], tempData[1], tempData[2], tempData[3], stoi(tempData[4]), \
               stoi(tempData[5]), stoi(tempData[6]), stoi(tempData[7]), degree);
    }

    roster.printAll();
    roster.printInvalidEmails();
    roster.printDaysInCourse("A3");
    roster.printByDegreeProgram(SOFTWARE);
    roster.remove("A3");
    roster.remove("A3");
    roster.~Roster();
    

    return 0;
}

Roster::Roster() {

}

Roster::~Roster() {
    for(int i = 0; i < size; i++) {
        if(classRosterArray[i] == nullptr) {
            delete classRosterArray[i];
        }
    }
}

void Roster::add(string id, string firstName, string lastName, string email, 
                 int age, int course1, int course2, int course3, int degree) {
    int toComplete[] = { course1, course2, course3 };
    Student* student = nullptr;

    switch(degree) {
        case SOFTWARE:
            student = new SoftwareStudent(id, firstName, lastName, email, age, toComplete);
            break;
        case SECURITY:
            student = new SecurityStudent(id, firstName, lastName, email, age, toComplete);
            break;
        case NETWORK:
            student = new NetworkStudent(id, firstName, lastName, email, age, toComplete);
            break;
        default:
            cout << "ERROR: Could not create user." << endl;
            break;
    }

    for(int i = 0; i < size; i++) {
        if(classRosterArray[i] == nullptr) {
            classRosterArray[i] = student;
            break;
        }
    }
}

void Roster::remove(string id) {
    bool found = false;

    for(int i = 0; i < size; i++) {
        if(classRosterArray[i] != nullptr) {
            if (classRosterArray[i]->getId() == id) {
                delete classRosterArray[i];
                classRosterArray[i] = nullptr;
                found = true;
                break;
            }
        }
    }
    if(!found)
        cout << "ERROR: Student not found. " << endl;
}

void Roster::printAll() {
    for(int i = 0; i < size; i++) {
        if(classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }

}

void Roster::printDaysInCourse(string id) {
    for(int i = 0; i < size; i++) {
        if(classRosterArray[i] != nullptr) {
            if (classRosterArray[i]->getId() == id) {
                int *days = classRosterArray[i]->getToComplete();
                int total = 0;
                for (int j = 0; j < 3; j++) {
                    total += *(days + j);
                }
                cout << "Average days left for " << classRosterArray[i]->getId() << ": " << (total / 3) << endl;
            }
        }
    }
}

void Roster::printInvalidEmails() {
        string email;

    for(int i = 0; i < size; i++) {
        bool space = false;
        bool atSymbol = false;
        bool validPeriod = false;

        if(classRosterArray[i] != nullptr) {
            email = classRosterArray[i]->getEmail();

            for (int j = 0; j < email.length(); j++) {
                if (email[j] == ' ') {
                    space = true;
                    break;
                } else if (email[j] == '@' && !atSymbol) {
                    atSymbol = true;
                } else if (email[j] == '.' && !validPeriod && atSymbol) {
                    validPeriod = true;
                }
            }
            if (space || !atSymbol || !validPeriod)
                cout << "Invalid email for " << classRosterArray[i]->getId() << ": "
                     << classRosterArray[i]->getEmail() << endl;
        }
    }
}

void Roster::printByDegreeProgram(int degree) {
    for(int i = 0; i < size; i++) {
        if(classRosterArray[i] != nullptr) {
            if (classRosterArray[i]->getDegreeProgram() == degree) {
                classRosterArray[i]->print();
            }
        }
    }

}