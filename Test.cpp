//Jonah Moon and April Shin
//CSIS 137 Wed Night Class
//Midterm Project

#include "Semester.h"
#include "CourseSchedule.h"
#include "Time.h"
#include "Date.h"
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

	int main()
	{
		string userName;
		Semester semInfo;
		int maxNum;
		char selection = 0;
		int numSelect;
		Course courses;

		cout << "Welcome to Course Schedule program!" << endl
			<< "Please enter your first name: " << endl;
			cin >> userName;
		cout << "Please enter the first four letters of the semester name, start date, end date in the following format: " << endl
			<< "Fall 09/15/1990-12/16/1990" << endl;
		cin >> semInfo;
		cout << "Please enter the maximum number of classes you are taking: " << endl;
		cin >> maxNum;
		CourseSchedule sched(userName, semInfo, maxNum);

		do 
		{
			cout << "COURSE ENTRY MENU FOR:   " << sched.getSemester() << endl
				<< "-----------------------------------------------" << endl
				<< "1) Enter a new course" << endl
				<< "2) Remove a course" << endl
				<< "3) Print semester schedule" << endl
				<< "q) Quit the program " << endl;
			cin >> selection;
			cin.ignore();
			if (selection == '1')
			{
				Time startT, endT;
				Date startD, endD;
				string cNum, cName, meetDays;
				double units;
				cout << "Please enter the course number: " << endl;
				getline(cin,cNum); 
				cout << "Please enter the course name: " << endl;
				getline(cin, cName);
				cout << "Please enter the meeting days of the course: " << endl;
				getline(cin,meetDays);
				cout << "Please enter the units the course is worth: " << endl;
				cin >> units;
				cout << "Please enter the starting time of the class. (HH:MM PM) " << endl;
				cin >> startT;
				cout << "Please enter the ending time of the class. (HH:MM PM)" << endl;
				cin >> endT;
				cout << "Please enter the starting date of the class. (MM/DD/YYYY)" << endl;
				cin >> startD;
				cout << "Please enter the ending date of the class. (MM/DD/YYYY)" << endl;
				cin >> endD;
				Course* nCourse = new Course(cNum, cName, meetDays, units, startD, endD, startT, endT);
				//Course newCourse(cNum, cName, meetDays, units, startD, endD, startT, endT);

				sched.AddCourse(*nCourse);
			}
			else if (selection == '2')
			{
				sched.RemoveCourse(sched);
			}
			else if (selection == '3')
			{
				cout << sched;
			}
			else
			{
				cout << "Invalid selection." << endl;
			}

		} while (selection != 'q' || selection != 'Q');

		cout << "You have quit the program. Thank you for using our services." << endl;
		system("PAUSE");
		return 0;
	}