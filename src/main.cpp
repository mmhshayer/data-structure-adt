#include "include\student.h"
#include "include\course.h"
#include "include\coursemarks.h"
#include "include\decorations.h"
#include "include\termcolor.hpp"
//---------------------------------
#include <list>
#include<iostream>
using namespace std;
//---------------------------------

std::list<Student> studentList;
std::list<Student>::iterator sl;

std::list<Course> courseList;
std::list<Course>::iterator cl;

std::list<Coursemarks> coursemarksList;
std::list<Coursemarks>::iterator ml;

//---------------------------------
void insert();
void remove();
void update();
void inquire();
void sort();
//---------------------------------

int main()
{
    int mC;
    clear();
    titleScreen();
    mainMenuText();
    cin >> mC;
    cin.sync();
    switch( mC )
    {
    case 1:
        insert();
        break;
    case 2:
        remove();
        break;
    case 3:
        update();
        break;
    case 4:
        inquire();
        break;
    case 5:
        sort();
        break;
    case 6:
        exit(0);
        break;

    default:
        clear();
        titleScreen();
        returnToMenu();
    }
return 0;
}


void insert()
{
    int iC, si, sa, ci, mci, mm; string sn, sg, cn, cp, msi;
    clear();
    titleScreen();
    std::cout << termcolor::green << "   Choose Where to Insert:-\n    1. Student\n    2. Courses\n    3. Course Marks\n" << termcolor::white << "    4. Exit\n";
    cin >> iC;

    switch ( iC )
    {
    case 1:
        clear();
        titleScreen();
        std::cout << termcolor::green << "   Enter Student ID: "; cin >> si;
        std::cout << termcolor::green << "\n   Enter Student Name: "; cin >> sn;
        std::cout << termcolor::green << "\n   Enter Student Age: "; cin >> sa;
        std::cout << termcolor::green << "\n   Enter Student Gender: "; cin >> sg;
        studentList.push_back(Student(si, sn, sa, sg));
        returnToMenu();
        break;

    case 2:
        clear();
        titleScreen();
        std::cout << termcolor::green << "   Enter Course ID: "; cin >> ci;
        std::cout << termcolor::green << "\n   Enter Course Name: "; cin >> cn;
        std::cout << termcolor::green << "\n   Enter Course Professor: "; cin >> cp;
        courseList.push_back(Course(ci, cn, cp));
        returnToMenu();
        break;
    case 3:
        clear();
        titleScreen();
        std::cout << termcolor::green << "   Enter Course ID: "; cin >> mci;
        std::cout << termcolor::green << "\n   Enter Student Name: "; cin >> msi;
        std::cout << termcolor::green << "\n   Enter Marks: "; cin >> mm;

        for (cl = courseList.begin(); cl != courseList.end(); cl++)
        {
            if ( cl->course_id == mci )
            {

                coursemarksList.push_back(Coursemarks(mci, msi, mm));
                returnToMenu();
            }
            else
            {
                cout << "   Course Not Found !\n";
            }
        }
        break;
    case 4:
        returnToMenu();
    
    default:
        cout << "   Enter Valid Key !";
        returnToMenu();
        break;
    }
    
    returnToMenu();
}

void inquire()
{
    int iqC;
    clear();
    titleScreen();
    std::cout << termcolor::yellow << "   Choose Where to Inuire:-\n 1. Student\n 2. Courses\n 3. Course Marks\n" << termcolor::white << " 4. Exit\n";
    cin >> iqC;

    switch ( iqC )
    {
    case 1:
        clear();
        titleScreen();
        std::cout << termcolor::yellow << "   Total Students: " << studentList.size() << endl;
        std::cout << termcolor::yellow << "   Displaying Student Info\n" << endl;
        std::cout << termcolor::yellow << " ID\tName\t\tAge\tGender" << endl; line();
        for (sl = studentList.begin(); sl != studentList.end(); sl++)
        {
            std::cout << " " << sl-> student_id << "\t" << sl-> student_name << "\t\t" << sl-> student_age << "\t" << sl-> student_gender << endl;
        }
        returnToMenu();
        break;
    case 2:
        clear();
        titleScreen();
        std::cout << termcolor::yellow << "   Total Availavle Courses: " << courseList.size() << endl;
        std::cout << termcolor::yellow << "   Displaying Course Info\n" << endl;
        std::cout << termcolor::yellow << " ID\tName\t\tProfessor" << endl; line();
        for (cl = courseList.begin(); cl != courseList.end(); cl++)
        {
            std::cout << " " << cl-> course_id << "\t" << cl-> course_name << "\t\t" << cl-> course_professor << endl;
        }
        returnToMenu();
        break;
    case 3:
        clear();
        titleScreen();
        std::cout << termcolor::yellow << "   Total Availavle Courses: " << courseList.size() << endl;
        std::cout << termcolor::yellow << "   Total Availavle Marks: " << coursemarksList.size() << endl << endl;
        std::cout << termcolor::yellow << " Course ID\tStudent Name\tMarks\n" << endl;line();
        for (ml = coursemarksList.begin(); ml != coursemarksList.end(); ml++)
        {
            std::cout << " " << ml-> course_id << "\t\t" << ml-> stundet_name << "\t\t" << ml-> store_marks << endl;
        }
        returnToMenu();
        break;
    case 4:
        returnToMenu();
    
    default:
        cout << "   Enter Valid Key !";
        returnToMenu();
        break;
    }
}

void remove()
{
    int rC, gid;
    string gname;
    clear();
    titleScreen();
    std::cout << termcolor::red << "   Remove:-\n    1. Student\n    2. Courses\n    3. Course Marks\n" << termcolor::white << "    4. Exit\n";
    cin >> rC;

    switch ( rC )
    {
    case 1:
        clear();
        titleScreen();
        std::cout << termcolor::red << "   Total Students: " << studentList.size() << endl;
        std::cout << termcolor::red << "   Please Enter the Name of the Student to Delete"<< endl;
        cin >> gname;
        for (sl = studentList.begin(); sl != studentList.end(); sl++)
        {
            if ( sl->student_name == gname )
            {
                studentList.erase(sl);
                std::cout << termcolor::red << "\n   Total Students After Deleting: " << studentList.size() << endl;
                returnToMenu();
            }
        }
        break;
    case 2:
        clear();
        titleScreen();
        std::cout << termcolor::red << "   Total Courses: " << courseList.size() << endl;
        std::cout << termcolor::red << "   Please Enter the Name of the Course to Delete"<< endl;
        cin >> gname;
        for (cl = courseList.begin(); cl != courseList.end(); cl++)
        {
            if ( cl->course_name == gname )
            {
                courseList.erase(cl);
                returnToMenu();
            }
        }
        std::cout << termcolor::red << "\n   Total Courses After Deleting: " << courseList.size() << endl;
        break;

    case 3:
        clear();
        titleScreen();
        std::cout << termcolor::red << "   Total Courses: " << coursemarksList.size() << endl;
        std::cout << termcolor::red << "   Please Enter the ID of the Course to Delete"<< endl;
        cin >> gid;
        std::cout << termcolor::red << "   Please Enter the Name of the Students to Delete"<< endl;
        cin >> gname;
        for (ml = coursemarksList.begin(); ml != coursemarksList.end(); ml++)
        {
            if ( ml->stundet_name == gname && ml->course_id == gid)
            {
                coursemarksList.erase(ml);
                returnToMenu();
            }
        }
        std::cout << termcolor::red << "\n   Total Courses After Deleting: " << coursemarksList.size() << endl;
        break;
    case 4:
        returnToMenu();
    
    default:
        cout << "   Enter Valid Key !";
        returnToMenu();
        break;
    }
    returnToMenu();
}

void update()
{
    int gid, uC, si, sa, ci, ucmid, ucmn;
    string gname, sn, sg, cn, ca, ucmsn;
    clear();
    titleScreen();
    std::cout << termcolor::blue << "   Update:-\n    1. Student\n    2. Courses\n    3. Course Marks\n" << termcolor::white << "    4. Exit\n";
    cin >> uC;

    switch ( uC )
    {
    case 1:
        clear();
        titleScreen();
        std::cout << termcolor::blue << "\n   Please Enter the Name of the Student to be Updated"<< endl;
        cin >> gname;
        for (sl = studentList.begin(); sl != studentList.end(); sl++)
        {
            if ( sl->student_name == gname )
                {
                    clear();
                    titleScreen();
                    std::cout << termcolor::blue << "   Enter New Student ID: "; cin >> si;
                    std::cout << termcolor::blue << "\n   Enter New Student Name: "; cin >> sn;
                    std::cout << termcolor::blue << "\n   Enter New Student Age: "; cin >> sa;
                    std::cout << termcolor::blue << "\n   Enter New Student Gender: "; cin >> sg;

                    studentList.emplace(sl, Student(si, sn, sa, sg) );
                    studentList.erase(sl++);
                    
                    returnToMenu();
                }
        }
        break;
    case 2:
        clear();
        titleScreen();
        std::cout << termcolor::blue << "\n   Please Enter the Name of the Course to be Updated"<< endl;
        cin >> gname;
        for (cl = courseList.begin(); cl != courseList.end(); sl++)
        {
            if ( cl->course_name == gname )
                {
                    clear();
                    titleScreen();
                    std::cout << termcolor::blue << "   Enter New Course ID: "; cin >> ci;
                    std::cout << termcolor::blue << "\n   Enter New Course Name: "; cin >> cn;
                    std::cout << termcolor::blue << "\n   Enter New Professor Name: "; cin >> ca;

                    courseList.emplace(cl, Course(ci, cn, ca) );
                    courseList.erase(cl++);
                    
                    returnToMenu();
                }
        }
        break;

    case 3:
        clear();
        titleScreen();
        std::cout << termcolor::blue << "   Please Enter the ID of the Course to Update Record"<< endl;
        cin >> gid;
        std::cout << termcolor::blue << "   Please Enter the Name of the Students to Update Record"<< endl;
        cin >> gname;
        for (ml = coursemarksList.begin(); ml != coursemarksList.end(); ml++)
        {
            if ( ml->stundet_name == gname && ml->course_id == gid)
            {
                clear();
                titleScreen();
                std::cout << termcolor::blue << "   Enter New Course ID: "; cin >> ci;
                std::cout << termcolor::blue << "\n   Enter New Course Name: "; cin >> cn;
                std::cout << termcolor::blue << "\n   Enter New Professor Name: "; cin >> ca;

                coursemarksList.emplace(ml, Coursemarks(ucmid, ucmsn, ucmn) );
                coursemarksList.erase(ml++);
                returnToMenu();
            }
        }
        std::cout << "   Total Courses After Updating: " << coursemarksList.size() << endl;
    case 4:
        returnToMenu();
    
    default:
        cout << "   Enter Valid Key !";
        returnToMenu();
        break;
    }
    returnToMenu();
}

void sort()
{
    int sC;
    clear();
    titleScreen();
    std::cout << termcolor::magenta << "   Sort:-\n    1. Sort Student by Name\n    2. Sort Courses By ID\n    3. Sort Course Marks By Marks\n" << termcolor::white << "    4. Exit\n";
    switch (sC)
    {
    case 1:
        clear();
        titleScreen();
        studentList.sort(sortByName);
        studentList.unique(are_sameStudent);
        cout << termcolor::magenta << "   Sorting Done !" << termcolor::yellow << "Inquire" << termcolor::magenta << "to See Changes";
        returnToMenu();
        break;
    case 2:  
        clear();
        titleScreen();                           
        courseList.sort(sortByID);
        courseList.unique(are_sameCourse);
        cout << termcolor::magenta << "   Sorting Done !" << termcolor::yellow << "Inquire" << termcolor::magenta << "to See Changes";
        returnToMenu();
        break;
    case 3:
        clear();
        titleScreen();
        coursemarksList.sort(sortByMarks);
        coursemarksList.unique(are_sameMarks);
        cout << termcolor::magenta << "   Sorting Done !" << termcolor::yellow << "Inquire" << termcolor::magenta << "to See Changes";
        returnToMenu();
        break;
    case 4:
        returnToMenu();
    
    default:
        cout << "   Enter Valid Key !";
        returnToMenu();
        break;
    }
}