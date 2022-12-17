/*
    BLACKPINK

    To, Claire
    Vo, Leanne
    Ha, Tri

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#include "CourseList.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Definition function addCourse
void CourseList::addCourse(const Course& newCourse)
{
    insertInOrder(new Node(newCourse, nullptr));
}

// Definition function addCourse
void CourseList::addCourse(int newCourseNumber,
                           const string& newCourseName,
                           int newCourseUnits,
                           const set<int>& newPrereqs)
{
    insertInOrder(new Node(Course(newCourseNumber,
                                  newCourseName, newCourseUnits,
                                  newPrereqs), nullptr));
}

// Definition function getPrefix
string CourseList::getPrefix()
{
    return Course::getPrefix();
}

// Definition function getNumberOfCourses
bool CourseList::getNumberOfCourses() const
{
    return count;
}

// Definition function isEmpty
bool CourseList::isEmpty() const
{
    return (count == 0);
}

// Definition function searchCourse (courseNumber)
// Assume list is non-empty.
Node* CourseList::searchCourse(int aCourseNumber) const
{
    return getCourseLocation(aCourseNumber);
}

// Definition function searchCourse (courseNumber, courseName)
// Assume list is non-empty.
bool CourseList::searchCourse(int aCourseNumber,
                              string& aCourseName) const
{
    Node* ptrToCourse = getCourseLocation(aCourseNumber);
    if (ptrToCourse != nullptr)
    {
        aCourseName = ptrToCourse->getCourse().getCourseName();
        return true;
    }
    return false;
}

// Definition function searchCourse(courseNumber, course) 
// Assume list is non-empty.
bool CourseList::searchCourse(int aCourseNumber,
                              Course& aCourseObj) const
{
    Node* ptrToCourse = getCourseLocation(aCourseNumber);
    if (ptrToCourse != nullptr)
    {
        aCourseObj = ptrToCourse->getCourse();
        return true;
    }
    return false;
}

// Definition deleteCourse
// Assume list is non-empty.
// Assume course is in the list.
void CourseList::deleteCourse(int aCourseNumber)
{
    if (first->getCourse().getCourseNumber()
        == aCourseNumber)
    {
        if (count == 1)
        {
            delete first;
            first = last = nullptr;
        }
        else
        {
            Node* temp = first;
            first = first->getNext();
            delete temp;
            temp = nullptr;
        }
    }
    else
    {
        Node* current = first->getNext();
        Node* trailCurrent = first;
        bool found = false;

        while (current != nullptr && !found)
        {
            if (current->getCourse().getCourseNumber()
                == aCourseNumber)
            {
                found = true;
                if (current == last)
                {
                    last = trailCurrent;
                    last->setNext(nullptr);
                }
                else
                {
                    trailCurrent->setNext(current->getNext());
                }
                delete current;
                current = nullptr;
            }
            else
            {
                trailCurrent = current;
                current = current->getNext();
            }
        }
    }

    --count;
}

// Definition retrieveAllCourses
// Assume list is non-empty.
void CourseList::retrieveAllCourses(string& courses) const
{
    ostringstream out;
    Node* current = first;
    while(current != nullptr)
    {
        out << getPrefix()
            << current->getCourse().getCourseNumber()
            << " - " << current->getCourse().getCourseName() << endl;
        current = current->getNext();
    }
    courses = out.str();
}

// Definition clearList
void CourseList::clearList()
{
    Node* trail = first;
    while (trail != nullptr)
    {
        first = first->getNext();
        delete trail;
        trail = first;
    }
    count = 0;
    last = first;
}

// Definition function getCourseLocation
Node* CourseList::getCourseLocation(int aCourseNumber) const
{
    Node* current = first;
    while (current != nullptr)
    {
        if (current->getCourse().getCourseNumber()
            == aCourseNumber)
        {
            return current;
        }
        current = current->getNext();
    }
    return current;
}

