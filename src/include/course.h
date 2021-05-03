#ifndef COURSE_H
#define COURSE_H

#include <iostream>
using namespace std;

struct Course
{
    int course_id;
    string course_name, course_professor;

    Course()
    {
        course_id = 0;
        course_name = "unknown", course_professor = "unknown";
    }

    Course(int course_id, string course_name, string course_professor)
    {
    this->course_id = course_id;
    this->course_name = course_name;
    this->course_professor = course_professor;
    }
};

bool sortByID(Course First, Course Next)
{
	if (First.course_id < Next.course_id) 
		return true; 
	if (First.course_id > Next.course_id) 
		return false;
	return false;
}

bool are_sameCourse(Course First, Course Next)
{ 
    return ( First.course_id == Next.course_id  && First.course_name == Next.course_name );
}
#endif