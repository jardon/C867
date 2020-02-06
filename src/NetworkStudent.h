#pragma once
#include "Student.h"
#include "Degree.h"

using namespace std;

class NetworkStudent : public Student {
    public:
        using Student::Student;
        Degree getDegreeProgram() override;

    protected:
        Degree degree = NETWORK;
};