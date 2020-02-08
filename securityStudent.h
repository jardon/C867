#pragma once
#include "student.h"
#include "degree.h"

using namespace std;

class SecurityStudent : public Student {
    public:
        using Student::Student;
        Degree getDegreeProgram() override;

    protected:
        Degree degree = SECURITY;
};