#include <string>

using namespace std;

class Roster {
    public:
        Roster();
        Roster(int size);
        ~Roster();
        void add(string id, string firstName, string lastName, string email, int age, int course1, int course2, int course3, int degree);
        void remove(string id);
        void printAll();
        void printDaysInCourse(string id);
        void printInvalidEmails();
        void printByDegreeProgram(int degree);
    
    private:
        Student* classRosterArray = NULL;
        int size;
};