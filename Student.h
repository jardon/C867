#pragma once
#include <string>
#include "Degree.h"

using namespace std;

class Student {
    public:

        // Constructors/Deconstructors
        Student();
        Student(string id, string firstName, string lastName, string email, int age, int toComplete []);
        ~Student();

        // Getters
        string getId();
        string getFirstName();
        string getLastName();
        string getEmail();
        int getAge();
        int* getToComplete();

        // Setters
        void setId(string id);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setAge(int age);
        void setToComplete(int toComplete[]);
        
        // Virtual methods
        virtual void print();
        virtual Degree getDegreeProgram();


    private:
        string id;
        string firstName;
        string lastName;
        string email;
        int age;
        int* toComplete;


};