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
using namespace std;

// Copy constructor
CourseList::CourseList(const CourseList& otherList)
{
    if (otherList.count == 0)
    {
        first = last = nullptr;
        count = 0;
    }
    else
    {
        first = last = new Node(otherList.first->getCourse(),
                                nullptr);
        Node* ptrParam = otherList.first->getNext();

        while (ptrParam != nullptr)
        {
            last->setNext(new Node(
                    ptrParam->getCourse(),
                    nullptr));
            last = last->getNext();
            ptrParam = ptrParam->getNext();
        }

        count = otherList.count;
    }
    // copyCallingObjIsEmpty(otherList);
}

// Definition overloaded assignment operator
CourseList& CourseList::operator=(const CourseList& otherList)
{
    if (this == &otherList)
    {
        cerr << "Attempted assignment to itself.\n";
    }
    else if (otherList.count == 0)
    {
        clearList();
    }
    else if (count == 0)
    {
        copyCallingObjIsEmpty(otherList);
    }
    else if (count == otherList.count)
    {
        copyObjectsSameLength(otherList);
    }
    else if (count > otherList.count)
    {
        copyCallingObjLonger(otherList);
    }
    else if (count < otherList.count)
    {
        copyCallingObjShorter(otherList);
    }
    return *this;
}

// Definition function copyCallingObjIsEmpty
void CourseList::copyCallingObjIsEmpty(const CourseList& aCourseList)
{
    if (aCourseList.count == 0)
    {
        first = last = nullptr;
        count = 0;
    }
    else
    {
        first = last = new Node(aCourseList.first->getCourse(),
                                nullptr);
        Node* ptrParam = aCourseList.first->getNext();

        while (ptrParam != nullptr)
        {
            last->setNext(new Node(
                    ptrParam->getCourse(),
                    nullptr));
            last = last->getNext();
            ptrParam = ptrParam->getNext();
        }

        count = aCourseList.count;
    }
}

// Definition function copyObjectsSameLength
void CourseList::copyObjectsSameLength(const CourseList& aCourseList)
{
    Node* ptrCalling = first;
    Node* ptrParam = aCourseList.first;

    while (ptrParam != nullptr)
    {
        ptrCalling->setCourse(ptrParam->getCourse());
        ptrCalling = ptrCalling->getNext();
        ptrParam = ptrParam->getNext();
    }

    last = ptrCalling;
    count = aCourseList.count;
}

// Definition function copyCallingObjLonger
void CourseList::copyCallingObjLonger(const CourseList& aCourseList)
{
    first->setCourse(aCourseList.first->getCourse());

    Node* ptrCalling = first->getNext();
    Node* trailCurrent = first;
    Node* ptrParam = aCourseList.first->getNext();

    while(ptrParam != nullptr)
    {
        ptrCalling->setCourse(ptrParam->getCourse());
        trailCurrent = ptrCalling;
        ptrCalling = ptrCalling->getNext();
        ptrParam = ptrParam->getNext();
    }
    last = trailCurrent;

    while(ptrCalling != nullptr)
    {
        trailCurrent = ptrCalling;
        ptrCalling = ptrCalling->getNext();
        delete trailCurrent;
    }

    trailCurrent = nullptr;
    last->setNext(nullptr);
    count = aCourseList.count;
}

// Definition function copyCallingObjShorter
void CourseList::copyCallingObjShorter(const CourseList& aCourseList)
{
    first->setCourse(aCourseList.first->getCourse());

    Node* ptrCalling = first->getNext();
    Node* trailCurrent = ptrCalling;
    Node* ptrParam = aCourseList.first->getNext();

    while (ptrCalling != nullptr)
    {
        ptrCalling->setCourse(ptrParam->getCourse());
        trailCurrent = ptrCalling;
        ptrCalling = ptrCalling->getNext();
        ptrParam = ptrParam->getNext();
    }

    while (ptrParam != nullptr)
    {
        trailCurrent->setNext(new Node(
                        ptrParam->getCourse(),
                        nullptr));
        trailCurrent = trailCurrent->getNext();
        ptrParam = ptrParam->getNext();
    }

    last = trailCurrent;
    count = aCourseList.count;
}

// Destructor
CourseList::~CourseList()
{
    if (count != 0)
    {
        clearList();
    }
}