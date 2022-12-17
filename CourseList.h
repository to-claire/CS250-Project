/*
    BLACKPINK

    To, Claire
    Vo, Leanne
    Ha, Tri

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

#include <string>
#include <set>

class Node
{
public:
	Node() : course(), next(nullptr) {}
	Node(const Course& newCourse, Node* newNext)
		: course(newCourse), next(newNext) {}
	Course getCourse() const { return course; }
	Node* getNext() const { return next; }
	void setCourse(const Course& newCourse) { course = newCourse; }
	void setNext(Node* newNext) { next = newNext; }
	~Node() {}
private:
	Course course;
	Node* next;
};

class CourseList
{
public:
	// Default constructor
	CourseList() : first(nullptr), last(nullptr), count(0) {}

	// Functions addCourse
    void addCourse(const Course& newCourse);
    void addCourse(int newCourseNumber,
                   const std::string& newCourseName,
                   int newCourseUnits,
                   const std::set<int>& newPrereqs);

	// Accessor functions
    static std::string getPrefix();
	
	// Boolean functions
    bool getNumberOfCourses() const;
    bool isEmpty() const;
    Node* searchCourse(int aCourseNumber) const;
    bool searchCourse(int aCourseNumber,
                      std::string& aCourseName) const;
    bool searchCourse(int aCourseNumber,
                      Course& aCourseObj) const;

	// Function deleteCourse
    void deleteCourse(int aCourseNumber);

	// Function retrieveAllCourses
    void retrieveAllCourses(std::string& courses) const;

	// Function clearList
    void clearList();

	/********************* THE BIG THREE *********************/

	// Copy constructor	
    CourseList(const CourseList& otherList);
	
	// Overloaded assignment operator
     CourseList& operator=(const CourseList& rightSide);

	// Destructor
    ~CourseList();

private:
	// Function getCourseLocation
    Node* getCourseLocation(int aCourseNumber) const;

	// Function insertInOrder
    void insertInOrder(Node* aNode);
	
	// Helper functions for overloaded assignment operator
    void copyCallingObjIsEmpty(const CourseList& aCourseList);
    void copyObjectsSameLength(const CourseList& aCourseList);
    void copyCallingObjLonger(const CourseList& aCourseList);
    void copyCallingObjShorter(const CourseList& aCourseList);

	Node* first;
	Node* last;
	int count;
};

#endif
