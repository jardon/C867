#pragma once
#include "Student.h"
#include "Degree.h"

using namespace std;

class SoftwareStudent : public Student {
    public:
        using Student::Student;
        Degree getDegreeProgram() override;

    protected:
        Degree degree = SOFTWARE;
};