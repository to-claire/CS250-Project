/*
    BLACKPINK
    
    To, Claire
    Vo, Leanne
    Ha, Tri
    
    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses    
*/

#include "Course.h"

using namespace std;

const string Course::PREFIX = "CS A";

// Definition overloaded constructor
Course::Course(int newCourseNumber, const std::string& newCourseName, 
        int newCourseUnits, const std::set<int>& newPrereqs)
{
    courseNumber = newCourseNumber;
    courseName = newCourseName;
    courseUnits = newCourseUnits;
    prereqs = newPrereqs;
}

// Definition function getCourseNumber
const string& Course::getCourseName() const
{
    return courseName;
}

// Definition function getCourseName
int Course::getCourseNumber() const
{
    return courseNumber;
}

// Definition function getCourseUnits
int Course::getCourseUnits() const
{
    return courseUnits;
}

// Definition function getPrereqs
const set<int>& Course::getCoursePrereqs() const
{
    return prereqs;
}

// Definition function getCourse
const Course& Course::getCourse() const
{
    return *this;
}

// Definition function getPrefix
string Course::getPrefix()
{
    return PREFIX;
}

// Definition function setCourseName
void Course::setCourseName(const string& newCourseName)
{
    courseName = newCourseName;
}

// Definition function setCourseNumber
void Course::setCourseNumber(int newCourseNumber)
{
    courseNumber = newCourseNumber;
}

// Definition function setCourseUnits
void Course::setCourseUnits(int newCourseUnits)
{
    courseUnits = newCourseUnits;
}

// Definition function setPrereqs
void Course::setPrereqs(const int a[], int length)
{
    prereqs.clear();

    for (int i = 0; i < length; ++i)
    {
        prereqs.insert(a[i]);
    }
}