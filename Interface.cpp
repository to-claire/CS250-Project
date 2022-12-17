#include "Interface.h"

#include <iostream>
using namespace std;

void displayMenu()
{
    cout << "**************************************************************\n"
         << "                          MAIN MENU\n"
         << "**************************************************************\n";
    cout << "\nSelect one of the following:\n\n"
         << "    1: Search course\n"
         << "    2: Add course\n"
         << "    3: Delete course\n"
         << "    4: Display all courses\n"
         << "    5: Calculate hours of study required for a course\n"
         << "    6: To exit\n";
}

void processChoice(CourseList& courseList)
{
    // Write your code in here...
    if (courseList.getNumberOfCourses() == 0)
    {
        cerr << "\nThere are no classes in this list.\n";
    }
    else
    {
        cout << "\nEnter a selection: ";
        char selection;
        cin >> selection;

        if (selection == '1')
        {
            cout << "\nEnter a course number to search: ";
            int courseNumber;
            cin >> courseNumber;

            Node* course = courseList.searchCourse(courseNumber);

            while (course == nullptr)
            {
                cout << "\nCourse number is not in the list.\n"
                     << "\t1: Retry \n\t2: Make another selection.\n";
                cin >> selection;

                while (selection != '1' && selection != '2')
                {
                    cout << "\nSelection is invalid.\n"
                         << "\t1: Retry \n\t2: Make another selection.\n";
                    cin >> selection;
                }

                if (selection == '1')
                {
                    cout << "\nEnter a course number to search: ";
                    cin >> courseNumber;
                    course = courseList.searchCourse(courseNumber);
                }
                else
                {
                    displayMenu();
                    processChoice(courseList);
                }
            }

            cout << course->getCourse().getPrefix()
                 << course->getCourse().getCourseNumber() << ", "
                 << course->getCourse().getCourseName() << ", "
                 << course->getCourse().getCourseUnits() << " units\n";
        }
        else if (selection == '2')
        {
            cout << "\nContact the Curriculum Committee "
                 << "to start the process of adding a course.\n";
        }
        else if (selection == '3')
        {
            cout << "Enter a course number to delete: ";
            int courseNumber;
            cin >> courseNumber;

            Node* course = courseList.searchCourse(courseNumber);

            while (course == nullptr)
            {
                cout << "\nCourse number is not in the list.\n"
                     << "\t1: Retry \n\t2: Make another selection.\n";
                cin >> selection;

                while (selection != '1' && selection != '2')
                {
                    cout << "\nSelection is invalid.\n"
                         << "\t1: Retry \n\t2: Make another selection.\n";
                    cin >> selection;
                }

                if (selection == '1')
                {
                    cout << "\nEnter a course number to delete: ";
                    cin >> courseNumber;
                    course = courseList.searchCourse(courseNumber);
                }
                else
                {
                    displayMenu();
                    processChoice(courseList);
                }
            }

            cout << "Confirm the deletion request? \n"
                    << "Type 'y' to confirm. "
                    << "If not, please type a different key to exit. " << endl;
            cin >> selection;

            if (selection == 'y')
            {
                courseList.deleteCourse(courseNumber);
                cout << "Course is successfully deleted." << endl;
            }
        }
        else if (selection == '4')
        {
            string courses;
            courseList.retrieveAllCourses(courses);
            cout << courses;
        }
        else if (selection == '5')
        {
            cout << "Enter a course number you like to see the workload for: ";
            int courseNumber;
            cin >> courseNumber;

            Node* course = courseList.searchCourse(courseNumber);

            while (course == nullptr)
            {
                cout << "\nCourse number is not in the list.\n"
                     << "\t1: Retry \n\t2: Make another selection.\n";
                cin >> selection;

                while (selection != '1' && selection != '2')
                {
                    cout << "\nSelection is invalid.\n"
                         << "\t1: Retry \n\t2: Make another selection.\n";
                    cin >> selection;
                }

                if (selection == '1')
                {
                    cout << "\nEnter a course number you like to see the workload for: ";
                    cin >> courseNumber;
                    course = courseList.searchCourse(courseNumber);
                }
                else
                {
                    displayMenu();
                    processChoice(courseList);
                }
            }

            cout << "Hours required to study for this course each week: "
                 << course->getCourse().getCourseUnits() * 3 << endl;
        }
        else if (selection == '6')
        {
            cout << "\nThank-you, good-night, and good-bye.\n";
            exit(0);
        }
        else
        {
            cout << "\nSelection is invalid. Please try again.";
            processChoice(courseList);
        }

        cout << "\nWould you like to continue the program? \n"
                << "Type 'y' to confirm. "
                << "If not, please type a different key to exit: " << endl;
        cin >> selection;

        if (selection == 'y')
        {
            displayMenu();
            processChoice(courseList);
        }
        else
        {
            cout << "\nThank-you, good-night, and good-bye.\n";
            exit(0);
        }
    }
}