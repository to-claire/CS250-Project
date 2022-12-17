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

// Definition function insertInOrder
// Assume there are no duplicates.
void CourseList::insertInOrder(Node* aCourse)
{
    if (count == 0)
    {
        first = last = aCourse;
    }
    else if (aCourse->getCourse().getCourseNumber() <
        first->getCourse().getCourseNumber())
    {
        aCourse->setNext(first);
        first = aCourse;
    }
    else if (aCourse->getCourse().getCourseNumber() >
             last->getCourse().getCourseNumber())
    {
        last->setNext(aCourse);
        last = aCourse;
    }
    else
    {
        Node* current = first->getNext();
        Node* trailCurrent = first;
        bool indexFound = false;

        while (current != nullptr && !indexFound)
        {
            if (aCourse->getCourse().getCourseNumber() >
                trailCurrent->getCourse().getCourseNumber() &&
                aCourse->getCourse().getCourseNumber() <
                current->getCourse().getCourseNumber())
            {
                indexFound = true;
                trailCurrent->setNext(aCourse);
                aCourse->setNext(current);
            }
            else
            {
                trailCurrent = current;
                current = current->getNext();
            }
        }
    }

    ++count;
}