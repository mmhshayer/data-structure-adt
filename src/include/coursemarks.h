#ifndef COURSEMARKS_H
#define COURSEMARKS_H

#include <iostream>
using namespace std;

struct Coursemarks
{
    int course_id, store_marks;
    string stundet_name;

    Coursemarks()
    {
        course_id = 0, stundet_name = "unknown"; store_marks = 0;
    }

    Coursemarks(int course_id, string stundet_name, int store_marks)
    {
        this-> course_id = course_id;
        this-> stundet_name = stundet_name;
        this-> store_marks = store_marks;
    }
};

bool sortByMarks(Coursemarks First, Coursemarks Next)
{
	if (First.store_marks < Next.store_marks) 
		return true; 
	if (First.store_marks > Next.store_marks) 
		return false;
	return false;
}

bool are_sameMarks(Coursemarks First, Coursemarks Next)
{ 
    return ( First.store_marks == Next.store_marks  && First.store_marks == Next.store_marks );
}


#endif