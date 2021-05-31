#include <iostream>

using namespace std;

class courseList
{
private:

    class course
    {
    public:
        string name;    //The course name
        float total;    //The course total degree
        string grade;   //The course grade
        float point;    //The course GPA points
        course* nextCourse; //Pointer points to the next course in the course linked list
    };

    //This head pointer points to the first course in the course linked list
    course* head = new course;
    course* tail = new course;

public:


    /** This constructor sets the value of the head
    with NULL value */
    courseList()
    {
        head = tail = NULL;
    }



    /** This function adds course to the course linked list
    it also adds the course name, total, grade and point */
    void addCourse(string name, float total, string grade, float point)
    {
        course* newCourse = new course;
        newCourse->name = name;
        newCourse->total = total;
        newCourse->grade = grade;
        newCourse->point = point;
        if (head == NULL) {
            head = tail = newCourse;
            newCourse->nextCourse = NULL;
        }
        else {
            tail->nextCourse = newCourse;
            newCourse->nextCourse = NULL;
            tail = newCourse;
        }
    }




    /** This function prints each course info. int the course linked list */
    void print()
    {
        course* trail = new course;
        trail = head;

        while (trail != NULL) {
            cout << "\n\n\n\t\t\tCourse name: " << trail->name;
            cout << "\n\n\t\t\tTotal degree: " << trail->total;
            cout << "\n\n\t\t\tGrade: " << trail->grade;
            cout << "\n\n\t\t\tPoint: " << trail->point;
            trail = trail->nextCourse;
        }
    }


};


/** The student linked list*/
class studentList
{
private:
    /** This class stores the info of the student*/
    class student
    {
    public:
        string name;        //The student name
        string department;  //The student department
        int courseNumber;   //The number of registered courses of the student
        courseList courses;  //The registered courses of the student
        student* nextStudent; //Pointer to the next student in the linked list
    };
    //pointer to points to the first student in the student linked list
    student* head = new student;
    student* tail = new student;

public:

    /** This constructor sets the value of the head
    with NULL value */
    studentList()
    {
        head = tail = NULL;
    }



    /** This function adds a new student in the student linked list
    it also adds the student name, department, courseNumber */
    void addStudent(string name, string department, int courseNumber, courseList& courses2)
    {
        student* newStudent = new student;
        newStudent->name = name;
        newStudent->department = department;
        newStudent->courseNumber = courseNumber;
        newStudent ->courses = courses2;
            if (head == NULL) {
                head = tail = newStudent;
                newStudent->nextStudent = NULL;
            }
            else {
                tail->nextStudent = newStudent;
                newStudent->nextStudent = NULL;
                tail = newStudent;
            }
    }




    /** This function prints students subjects and grades */
    void print()
    {
        student* trail = new student;
        trail = head;

        while (trail != NULL) {
            cout << "\n\n\t\t Name: " << trail->name;
            cout << "\n\n\t\t Department: " << trail->department;
            cout << "\n\n\t\t coursesNumber: " << trail->courseNumber;
            cout << "\n\n\t\t Courses: "; trail->courses.print();
            trail = trail->nextStudent;
        }
    }

};

int main()
{

    studentList sl;
    courseList c1;
    c1.addCourse("datastructure", 3.5, "A", 87);
    c1.addCourse("database", 3.2, "b+", 78);
    c1.addCourse("software", 4, "A+", 98);
    sl.addStudent("mohamed", "CS", 3, c1);
    courseList c2;
    c2.addCourse("webtechnology", 4, "A+", 97);
    c2.addCourse("datastructure", 3.3, "b", 68);
    sl.addStudent("maher", "IT",2,c2);
    sl.print();

    return 0;
}
