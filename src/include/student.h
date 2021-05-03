#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

struct Student
{
    int student_id, student_age;
    string student_name, student_gender;

    //Constructors
    Student()
    {
        student_id = 0, student_age = 18;
        student_name = "unknown", student_gender = "unknown";
    }

    Student(int student_id, string student_name, int student_age = 0, string student_gender = "unknown")
    {
    this->student_id = student_id;
    this->student_name = student_name;
    this->student_age = student_age;
    this->student_gender = student_gender;
    }
};

bool sortByName(Student First, Student Next)
{
	if (First.student_name < Next.student_name) 
		return true; 
	if (First.student_name > Next.student_name) 
		return false;
	return false;
}

bool are_sameStudent(Student First, Student Next)
{ 
    return ( First.student_name == Next.student_name  && First.student_name == Next.student_name );
}

#endif