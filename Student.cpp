using namespace std;

#include <string>
#include "Student.h"
#include <iostream>

Student::Student() {
    id = "";
    firstName = "";
    lastName = "";
    email = "";
    age = -100;
}

Student::Student(string id, string firstName, string lastName, string email, int age, int toComplete []) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->toComplete = toComplete;
}

Student::~Student() {
    toComplete = NULL;
    delete toComplete;
}

inline string Student::getId() { return id; }

inline string Student::getFirstName() { return firstName; }

inline string Student::getLastName() { return lastName; }

inline string Student::getEmail() { return email; }

inline int Student::getAge() { return age; }

inline int* Student::getToComplete() { return toComplete; }

inline void Student::setId(string id) { this->id = id; }

inline void Student::setFirstName(string firstName) { this->firstName = firstName; }

inline void Student::setLastName(string lastName) { this->lastName = lastName; }

inline void Student::setAge(int age) { this->age = age; }

inline void Student::setToComplete(int toComplete []) { this->toComplete = toComplete; }

inline Degree Student::getDegreeProgram() { return degree; }

void Student::print() {
    cout << "Student ID: " << getId();
    cout << "\tFirst Name: " << getFirstName();
    cout << "\tLast Name " << getLastName();
    cout << "\tEmail: " << getEmail();
    cout << "\tAge: " << getAge();
    cout << "\tDays in Course: " << getToComplete()[0] << ", " << getToComplete()[1] << ", " << getToComplete()[2];
    cout << "\tDegree: ";

    switch (getDegreeProgram()) {
    case SOFTWARE:
        cout << "SOFTWARE";
        break;
    case NETWORK:
        cout << "NETWORK";
        break;
    case SECURITY:
        cout << "SECURITY";
        break;
    default:
        cout << "NOT FOUND";
        break;
    }

    cout << endl;
}