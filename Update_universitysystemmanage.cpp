// UniversitySystemManagement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<conio.h>
#include<fstream>
#include <bits/stdc++.h>
#include <iterator>
#include <algorithm>
#include<map>

using namespace std;

multimap <int, string> savedstudent;


class CSVReader
{
	std::string fileName;
	char delimeter;
public:
	CSVReader() {}
	CSVReader(std::string filename, char delm = ',') :
		fileName(filename), delimeter(delm) { }
	// Function to fetch data from a CSV File
	vector<vector<string> > getData()
	{
		ifstream file(fileName);
		vector<vector<string> > dataList;
		vector<string> vec;
		string line = "", word;
		while (getline(file, line))
		{
			vec.clear();
			stringstream s(line);
			while (getline(s, word, delimeter)) {

				vec.push_back(word);

			}
			dataList.push_back(vec);
		}
		file.close();


		return dataList;
	}




};

/*
* Parses through csv file line by line and returns the data
* in vector of vector of strings.
*/


class Phone {


private:

	string mobile;
public:
	string get_phone() {

		//char msg1[] = "Mobile number is 11 digits";
		char msg1[] = "Mobile number is not 11 digits, tray again";
		char msg2[] = "Mobile does not start with 0";

	START:
		try {
			mobile.clear();
			cin >> mobile;

			if (mobile.length() != 11) {
				throw msg1;
			}



			if (mobile[0] != '0') {

				throw msg2;

			}


		}

		catch (char msg[]) {

			cout << msg << endl;
			goto START;
		}

		return mobile;
	}



};
class Password {

private:
	string pass;
	string username;
	fstream passfile;
public:
	Password() {}
	void input_password()
	{
		char msg1[] = "Wrong, tray again";

		cout << "\nPlease Choose A Username For User's System :" << endl;
		cin >> username;
		cout << "\nPlease Choose A Password For User's System :" << endl;
	START:
		pass.clear();
		char ch;
		int count = 0;
		try {
			ch = _getch();
			while (ch != 13)
			{

				if (ch != 8)
				{
					cout << "*";
					pass.push_back(ch);
				}
				if (ch == 8)
				{
					cout << "\b \b";
					pass.pop_back();
				}
				count++;
				ch = _getch();

			}
			if (count < 8)
			{
				throw msg1;

			}

		}

		catch (char msg[]) {

			cout << msg << endl;
			goto START;
		}


		passfile.open("password.csv", ios::app);
		passfile << username + "," + pass << endl;

	}
	//template <typename T, typename T>
	/*	string verify_password(string password, string  username) {

	ifstream fin;
	fin.open("password.csv");

	if (fin.is_open())
	{
	cout << "File opened successfully" << "\n";

	string line, word, temp;
	vector<string> row;
	while (fin.good()) {
	getline(fin, line);
	cout << line << endl;
	row.clear();
	stringstream s(line);
	while (getline(s, word, ',')) {
	row.push_back(word);
	}
	if (row[0] == username)
	return row[1];
	else
	return "false";
	//cout << token << " not found" << endl;

	}
	}

	fin.close();
	}
	*/
	string get_password(string  username) {
		CSVReader reader("password.csv");

		vector<vector<string> > dataList = reader.getData();
		for (vector<string> vec : dataList)
		{ 


			for (string data : vec)
			{
				
				if (data == username) { return vec[1]; }


			}
		}






	}








};
class Person {

	string name, family, address, phone;
	int age;

public:

	Person() {}
	~Person() { cout << "destructor of person is called!" << endl; }
	Person(string name, string family, string address, string phone, int age) {

		this->name = name;
		(*this).family = family;
		this->address = address;
		this->phone = phone;
		this->age = age;
	}
	void setName(string name) {
		this->name = name;
	}
	void setFamily(string family) {
		this->family = family;
	}
	void setAddress(string address) {
		this->address = address;
	}
	void setPhone(string phone) {
		this->phone = phone;
	}
	void setAge(int age) {
		this->age = age;
	}
	string getName() const {
		return name;
	}
	string getFamily()const {
		return family;
	}
	string getAddress()const {
		return address;
	}
	string getPhone()const {
		return phone;
	}
	int getAge()const {
		return age;
	}
	void report(string filename) const {
		// Creating an object of CSVWriter
		CSVReader reader(filename);
		// Get the data from CSV File
		std::vector<std::vector<std::string> > dataList = reader.getData();
		// Print the content of row by row on screen
		for (std::vector<std::string> vec : dataList)
		{
			for (std::string data : vec)
			{
				std::cout << data << setw(6);
			}
			std::cout << std::endl;
		}

		//cout << name << setw(6) << " " << family << setw(10) << address << setw(4) << phone << setw(4) << age << endl;

	}



};
class Employee :public Person {

	int idnumber;
	string group;

public:
	Employee() {}
	~Employee() { cout << "destructor of Employee is called!" << endl; }
	Employee(string name, string family, string address, string phone, int age, int idnumber, string group)
		:Person(name, family, address, phone, age) {

		this->idnumber = idnumber;
		(*this).group = group;

	}

	int getIdnumber()const {

		return idnumber;

	}
	string getgroup()const {

		return group;

	}
	void setIdnumber(int idnumber) {

		this->idnumber = idnumber;

	}
	void setgroup(string group) {

		this->group = group;

	}



};
class Course {

	int year, courseNumber, room, beginTime, endTime;
	string term, meetingDays, teacherName;

	vector<Course> registerdata;

public:
	Course() {}
	~Course() { cout << "destructor of course is called!" << endl; }
	Course(int year, string term, int courseNumber, int room, int beginTime, int endTime, string meetingDays, string teacherName) {

		this->year = year;
		this->courseNumber = courseNumber;
		this->room = room;
		this->beginTime = beginTime;
		this->term = term;
		this->meetingDays = meetingDays;
		this->teacherName = teacherName;
		this->endTime = endTime;




	}

	int  getYaer()
	{
		return year;
	}
	void  setYear(int year)
	{
		this->year = year;
	}
	void  setTerm(string term)
	{
		this->term = term;
	}
	void  setCourseNumber(int courseNumber)
	{
		this->courseNumber = courseNumber;


	}
	void  setRoom(int room)
	{
		this->room = room;

	}
	void  setBeginTime(int beginTime)
	{
		this->beginTime = beginTime;
	}
	void  setEndTime(int endTime)
	{
		this->endTime = endTime;
	}
	void  setMeetingDays(string meetingDays)
	{
		this->meetingDays = meetingDays;
	}
	string  getTerm()const
	{
		return term;
	}
	int   getCourseNumber()const {
		return courseNumber;
	}
	int  getBeginTime()const
	{
		return beginTime;
	}
	int  getEndTime()const {
		return endTime;
	}
	int  getRoom()const
	{
		return room;
	}
	void setTeacherName(string teacherName) {
		this->teacherName = teacherName;
	}
	string getTeacherName()const { return teacherName; }
	string getMeetingDays()const {
		return meetingDays;
	}


	void report() {
		cout << courseNumber << setw(6) << " " << teacherName << setw(10) << beginTime << setw(4) << endTime << setw(4) << meetingDays << setw(4) << room << endl;

	}




};
class Student : public Employee {


private:

	
	string grade;

	vector<Course> Courses;
public:
	Student() {}
	~Student() { cout << "destructor of student is called!" << endl; }
	Student(string name, string family, string address, string phone, int age, int idnumber, string group)
		:Employee(name, family, address, phone, age, idnumber, group) {}

	/*Student(int idnumber, string group){
	//	this->idnumber = idnumber;
	this->group = group;//}*/

	void registerCourse();

	void setgrade(string grade) {

		this->grade = grade;

	}


	string getgrade()const { return grade; }


	void report() const {

		cout << getName() << setw(6) << " " << getFamily() << setw(10) << getAddress() << setw(4) << getPhone() << setw(4) << getAge() << setw(4) << getIdnumber() << setw(4) << getgroup() << endl;

	}


};
class Teacher :public Employee {


public:
	Teacher() {}
	~Teacher() { cout << "destructor of teacher is called!" << endl; }
	Teacher(string name, string family, string address, string phone, int age, int idnumber, string group) :Employee(name, family, address, phone, age, idnumber, group) {}
	void report() const {

		cout << getName() << setw(6) << " " << getFamily() << setw(10) << getAddress() << setw(4) << getPhone() << setw(4) << getAge() << setw(4) << getIdnumber() << setw(4) << getgroup() << endl;

	}


};



//##############################################################
//
//#########################  COURSE  ###########################




vector<Course> listcs, listcs2;
fstream outputfileCS;
void writeCS() {
	int year, courseNumber, room, beginTime, endTime;
	string term, meetingDays, teacherName;

	cout << "Enter year:";
	cin >> year;
	cout << "Enter courseNumber:";
	cin >> courseNumber;
	cout << "Enter room:";
	cin >> room;
	cout << "Enter beginTime:";
	cin >> beginTime;
	cout << "Enter endTime:";
	cin >> endTime;
	cout << "Enter term:";
	cin >> term;
	cout << "Enter meetingDays:";
	cin >> meetingDays;
	cout << "Enter teacherName:";
	cin >> teacherName;

	listcs.push_back(Course(year, term, courseNumber, room, beginTime, endTime, meetingDays, teacherName));
	outputfileCS.open("course.csv", ios::out | ios::app);

	//outputfileCS << "a,b,c";
	outputfileCS <<  to_string(courseNumber) + "," + to_string(year) + "," + term + "," + to_string(room) + "," + to_string(beginTime) + "," + to_string(endTime) + "," + meetingDays + "," + teacherName << endl;

}
void displayallCS() {


	system("cls");
	cout << "\n\n\t\tALL COURSES OF TERM ONE RESULT \n\n";
	cout << "==========================================================\n";
	cout << "Code       Teacher       Time   Exam Time   Day   Room " << endl;
	cout << "==========================================================\n";


	for (int i = 0; i < listcs.size(); i++) {

		listcs[i].report();

	}




}
void displayOneCS(int coursenumber) {


	system("cls");
	cout << "\n\n\t\tALL COURSES OF TERM ONE RESULT \n\n";
	cout << "==========================================================\n";
	cout << "Code       Teacher       Time   Exam Time   Day   Room " << endl;
	cout << "==========================================================\n";


	for (int i = 0; i < listcs.size(); i++) {
		if (listcs[i].getCourseNumber() == coursenumber) {
			listcs[i].report();
		}

	}




}
void modifyCS(int coursenumber) {

	int room, code;
	string teachername;

	int a;
	for (int i = 0; i < listcs.size(); i++) {
		if (listcs[i].getCourseNumber() == coursenumber) {
			cout << "\n\n\n\tSELECT MENU";
			cout << "\n\n\n\t1. CODE";
			cout << "\n\n\t2. TEACHER NAME";
			cout << "\n\n\t3. ROOM";
			cout << "\n\n\n\tEnter Choice (1/2/3)? ";
			cin >> a;

			switch (a)
			{
			case 1: cout << "Enter code:"; cin >> code; listcs[i].setCourseNumber(code); break;
			case 2: cout << "Enter teacher name:"; cin >> teachername; listcs[i].setTeacherName(teachername); break;
			case 3: cout << "Enter room:"; cin >> room; listcs[i].setRoom(room); break;

			default:
				break;
			}




		}

	}


	// File pointer 
	fstream fin, fout;

	// Open an existing record 
	 fin.open("course.csv", ios::in);

	// Create a new file to store updated data 
	fout.open("coursenew.csv", ios::out);

	int rollnum, roll1, marks, count = 0, i;
	char sub;
	int index, new_marks;
	string line, word;
	vector<string> row;

	// Get the roll number from the user 
	//cout << "Enter the roll number "
	//	<< "of the record to be updated: ";
	//cin >> rollnum;
	cout << "\n\n\n\tSELECT MENU";
	cout << "\n\n\n\t1. CODE";
	cout << "\n\n\t2. YEAR";
	cout << "\n\n\t3. TERM";
	cout << "\n\n\t4. ROOM";
	cout << "\n\n\n\tEnter Choice (1/2/3)? ";
	cin >> a;
	// Get the data to be updated 
	//cout << "Enter the subject "
	//	<< "to be updated(M/P/C/B): ";
	//cin >> sub;

	// Determine the index of the subject 
	// where Maths has index 2, 
	// Physics has index 3, and so on 
	if (a == 1)
	{
		index = 0;
		cout << "index is: " << index << "\n";
	}
	else if (a==2)
		index = 1;
	else if (a==3)
		index = 2;
	else if (a==4)
		index = 3;
	else {
		cout << "Wrong choice.Enter again\n";
		//modifyCS(int coursenumber);
	}

	// Get the new marks 
	cout << "Enter New Data: ";
	cin >> new_marks;

	// Traverse the file 
	while (getline(fin, line)) {

		row.clear();
		cout << "row.clear() \n";

		//getline(fin, line);
		//if (line.empty()) { break; }
		stringstream s(line);

		while (getline(s, word, ',')) {
			cout << "row.push_back(word) \n";

			row.push_back(word);
		}

		roll1 = stoi(row[0]);
		cout << "stoi(row[0]): " << roll1 << "\n";
		int row_size = row.size();

		if (roll1 == coursenumber) {
			count = 1;
			stringstream convert;

			// sending a number as a stream into output string 
			convert << new_marks;

			// the str() converts number into string 
			row[index] = convert.str();
			cout << "row[index]: " << row[index] << "\n";

			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {
					cout << " write the updated data \n";
					// write the updated data 
					// into a new file 'reportcardnew.csv' 
					// using fout 
					fout << row[i] << ", ";
				}

				fout << row[row_size - 1] << "\n";
			}
		}
		else {
			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {

					// writing other existing records 
					// into the new file using fout. 
					fout << row[i] << ", ";
				}

				// the last column data ends with a '\n' 
				fout << row[row_size - 1] << "\n";
			}
		}
		if (fin.eof())
			break;
	}
	if (count == 0)
		cout << "Record not found\n";

	fin.close();
	fout.close();

	// removing the existing file 
	remove("course.csv");

	// renaming the updated file with the existing file name 
	rename("coursenew.csv", "course.csv");
 


}
void deleteallCS() { listcs.clear(); }
void deleteOneCS(int coursenumber) {

	for (int i = 0; i < listcs.size(); i++) {
		if (listcs[i].getCourseNumber() != coursenumber) {
			listcs2.push_back(listcs[i]);
		}

	}


	listcs = listcs2;
	vector<Course>().swap(listcs2);

	//#######################################################################


	

		// Open FIle pointers 
		fstream fin, fout;

		// Open the existing file 
		fin.open("course.csv", ios::in);

		// Create a new file to store the non-deleted data 
		fout.open("coursenew.csv", ios::out);

		int rollnum, roll1, marks, count = 0, i;
		char sub;
		int index, new_marks;
		string line, word;
		vector<string> row;

		// Get the roll number 
		// to decide the data to be deleted 
		cout << "Enter the roll number "
			<< "of the record to be deleted: ";
		cin >> rollnum;

		// Check if this record exists 
		// If exists, leave it and 
		// add all other data to the new file 
		while (!fin.eof()) {

			row.clear();
			getline(fin, line);
			stringstream s(line);

			while (getline(s, word, ',')) {
				row.push_back(word);
			}

			int row_size = row.size();
			roll1 = stoi(row[0]);

			// writing all records, 
			// except the record to be deleted, 
			// into the new file 'reportcardnew.csv' 
			// using fout pointer 
			if (roll1 != coursenumber) {
				if (!fin.eof()) {
					for (i = 0; i < row_size - 1; i++) {
						fout << row[i] << ", ";
					}
					fout << row[row_size - 1] << "\n";
				}
			}
			else {
				count = 1;
			}
			if (fin.eof())
				break;
		}
		if (count == 1)
			cout << "Record deleted\n";
		else
			cout << "Record not found\n";

		// Close the pointers 
		fin.close();
		fout.close();

		// removing the existing file 
		remove("course.csv");

		// renaming the new file with the existing file name 
		rename("coursenew.csv", "course.csv");
	 














}
vector<Course> getdataregister() {
	return listcs;
}






//##############################################################
//
//#########################  STUDENT  ###########################

vector <Student> listst, listst2;
fstream outputfile;
void writest() {

	int idnumber, age;
	string name, family, address, phone, grade, group;
	Password ps;
	cout << "\n Enter the number of student: ";
	cin >> idnumber;
	cout << "\n Enter the name of student: ";
	cin >> name;
	cout << "\n Enter the family of student: ";
	cin >> family;
	cout << "\n Enter the address of student: ";
	cin >> address;
	cout << "\n Enter the phone of student: ";
	Phone ph;
	phone = ph.get_phone();
	ps.input_password();

	cout << "\n Enter the grade of student: ";
	cin >> grade;
	cout << "\n Enter the group of student: ";
	cin >> group;
	cout << "\n Enter the age of student: ";
	cin >> age;
	listst.push_back(Student(name, family, address, phone, age, idnumber, group));

	outputfile.open("student.csv", ios::app);
	outputfile << name + "," + family + "," + address + "," + to_string(age) + phone + ","
		+ to_string(idnumber) + "," + group << endl;



}
void displayallstu() {

	system("cls");
	cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
	cout << "==========================================================\n";
	cout << "Name       Family        Address   Phone   age   idnumber   garde   group" << endl;
	cout << "==========================================================\n";
	for (int i = 0; i < listst.size(); i++)
	{
		listst[i].report();
	}

}
void displayonest(int idnumber) {

	system("cls");
	cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
	cout << "==========================================================\n";
	cout << "Name       Family        Address   Phone   age   idnumber   garde   group" << endl;
	cout << "==========================================================\n";

	for (int i = 0; i < listst.size(); i++)
	{
		if (listst[i].getIdnumber() == idnumber) {
			listst[i].report();
		}
	}

}
void modify(int idnumber) {
	string name, family, phone;
	int a;
	for (int i = 0; i < listst.size(); i++)
	{
		if (listst[i].getIdnumber() == idnumber) {
			cout << "\n\n\n\tSELECT MENU";
			cout << "\n\n\n\t1. NAME";
			cout << "\n\n\t2. FAMILY";
			cout << "\n\n\t3. PHONE";
			cout << "\n\n\n\tEnter Choice (1/2/3)? ";
			cin >> a;
			switch (a)
			{
			case 1: cout << "Enter a name" << endl; cin >> name; listst[i].setName(name); break;
			case 2: cout << "Enter a family" << endl; cin >> family; listst[i].setFamily(family); break;
			case 3: cout << "Enter a phone" << endl; cin >> phone; listst[i].setPhone(phone); break;

			}

		}
	}

}
void deleteallstudent() {

	listst.clear();

}
void delete_student(int idnumber) {


	for (int i = 0; i < listst.size(); i++) {

		if (listst[i].getIdnumber() != idnumber) {

			listst2.push_back(listst[i]);


		}
	}

	listst = listst2;
	vector<Student>().swap(listst2);


}
void selectCourse(int idnumber) {


	for (int i = 0; i < listst.size(); i++) {

		if (listst[i].getIdnumber() == idnumber) {

			listst[i].registerCourse();
		}

	}


}
void Student::registerCourse() {
	displayallCS();
	int code;
	char ch;
	do {
		cout << "Enter the code of course for register" << endl;
		cin >> code;
		vector<Course> listcourse = getdataregister();
		for (int i = 0; i < listcourse.size(); i++) {

			if (listcourse[i].getCourseNumber() == code) {

				Courses.push_back(listcourse[i]);
				savedstudent.insert(pair<int, string>(code, getName() + " " + getFamily()));

			}



		}
		cout << "Are you continue? (Y|y)" << endl;
		cin >> ch;

	} while (ch == 'y' || ch == 'Y');
}
multimap <int, string> getsavedstudent() {
	return savedstudent;
}
//##############################################################
//
//#########################  TEACHER  ###########################

vector <Teacher> listTA, listTA2;
fstream outputfileTA;
void writeTA() {

	int codeteacher, age;
	string name, family, address, phone, group;
	Password ps;
	cout << "\n Enter the number of Teacher: ";
	cin >> codeteacher;
	cout << "\n Enter the name of Teacher: ";
	cin >> name;
	cout << "\n Enter the family of Teacher: ";
	cin >> family;
	cout << "\n Enter the address of Teacher: ";
	cin >> address;

	cout << "\n Enter the group of Teacher: ";
	cin >> group;
	cout << "\n Enter the age of Teacher: ";
	cin >> age;
	cout << "\n Enter the phone of Teacher: ";
	Phone ph;
	phone = ph.get_phone();
	ps.input_password();
	listTA.push_back(Teacher(name, family, address, phone, age, codeteacher, group));
	outputfileTA.open("teacher.csv", ios::app);
	outputfileTA << name + "," + family + "," + address + "," + to_string(age) + phone + ","
		+ to_string(codeteacher) + "," + group << endl;

}
void displayallteach() {

	system("cls");
	cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
	cout << "============================================================================\n";
	cout << "Name       Family        Address       Phone       age       code       group" << endl;
	cout << "============================================================================\n";
	/*
	CSVReader reader("teacher.csv");
	// Get the data from CSV File
	std::vector<std::vector<std::string> > dataList = reader.getData();
	// Print the content of row by row on screen
	for (std::vector<std::string> vec : dataList)
	{
	for (std::string data : vec)
	{
	std::cout << data << setw(6);
	}
	std::cout << std::endl;
	}

	*/





	for (int i = 0; i < listTA.size(); i++)
	{

		listTA[i].report();
	}







}
void displayoneTA(int idnumber) {

	system("cls");
	cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
	cout << "============================================================================\n";
	cout << "Name       Family        Address       Phone       age       code       group" << endl;
	cout << "============================================================================\n";

	for (int i = 0; i < listTA.size(); i++)
	{
		if (listTA[i].getIdnumber() == idnumber) {
			listTA[i].report();
		}
	}

}
void modifyTA(int idnumber) {
	string name, family, phone;
	int a;
	for (int i = 0; i < listTA.size(); i++)
	{
		if (listTA[i].getIdnumber() == idnumber) {
			cout << "\n\n\n\tSELECT MENU";
			cout << "\n\n\n\t1. NAME";
			cout << "\n\n\t2. FAMILY";
			cout << "\n\n\t3. PHONE";
			cout << "\n\n\n\tEnter Choice (1/2/3)? ";
			cin >> a;
			switch (a)
			{
			case 1: cout << "Enter a name" << endl; cin >> name; listTA[i].setName(name); break;
			case 2: cout << "Enter a family" << endl; cin >> family; listTA[i].setFamily(family); break;
			case 3: cout << "Enter a phone" << endl; cin >> phone; listTA[i].setPhone(phone); break;

			}

		}
	}

}
void deleteallTA() {

	listTA.clear();

}
void delete_TA(int tanumber) {


	for (int i = 0; i < listTA.size(); i++) {

		if (listTA[i].getIdnumber() != tanumber) {

			listTA2.push_back(listTA[i]);


		}
	}

	listTA = listTA2;
	vector<Teacher>().swap(listTA2);


}

void printsavedstudent(int code) {

	multimap<int, string> list = getsavedstudent();
	for (multimap<int, string> ::iterator it = list.begin(); it != list.end(); it++) {

		if (code == it->first) {
			cout << it->second;
		}



	}

}

//##############################################################################
//
//###################################  MENU ####################################

void intro() {
	system("cls");
	cout << "\n\n\n\t\t  SYSTEM UNIVERSITY";
	cout << "\n\n\t\t  ADVANCED C++ PROJECT";
	cout << "\n\n\n\tMADE BY : MAHBOOBE REZAEI";
	cout << "\n\tSCHOOL : QOM UNIVERSITY";
	cin.get();
}
void report_men() {

	int a, e, f, idnumber;
	system("cls");
	cout << "\n\n\n\tREPORT MENU";
	cout << "\n\n\n\t1. REPORTS";
	cout << "\n\n\t2. Back to Main Menu";
	cout << "\n\n\n\tEnter Choice (1/2/3)? ";
	cin >> a;
	switch (a)
	{
	case 1:
	{	system("cls");
	cout << "\n\n\n\tREPORTs MENU";
	cout << "\n\n\t1. Student Reports";
	cout << "\n\n\t2. Teacher Reports";
	cout << "\n\n\t3. Course Reports";
	cout << "\n\n\n\tEnter Choice (1/2/3)? ";
	cin >> e;
	switch (e)
	{
	case 1:
	{	system("cls");
	cout << "\n\n\n\tSELECT";
	cout << "\n\n\t1. All Student Report";
	cout << "\n\n\t2. Student Report";
	cout << "\n\n\n\tEnter Choice (1/2)? ";
	cin >> f;
	switch (f)
	{
	case 1:  displayallstu(); _getch(); break;
	case 2: cout << "\n Enter the number of student: "; cin >> idnumber;
		displayonest(idnumber);  break;
	default:
		break;
	}
}
	case 2:
	{	system("cls");
	cout << "\n\n\n\tSELECT";
	cout << "\n\n\t1. All Teacher Report";
	cout << "\n\n\t2. Teacher Report";
	cout << "\n\n\t3. Course Report";
	cout << "\n\n\n\tEnter Choice (1/3)? ";
	cin >> f;
	switch (f)
	{
	case 1:  displayallteach();break;
	case 2: cout << "\n Enter the number of teacher: "; cin >> idnumber;
		displayoneTA(idnumber);break;
	case 3: cout << "\n Enter the code of course for report: "; cin >> idnumber;
		printsavedstudent(idnumber);break;
	default:
		break;
	}
 }

	case 3:
	{	system("cls");
	cout << "\n\n\n\tSELECT";
	cout << "\n\n\t1. All Course Report";
	cout << "\n\n\t2. Course Report";
	cout << "\n\n\n\tEnter Choice (1/2)? ";
	cin >> f;
	switch (f)
	{
	case 1:  displayallCS();break;
	case 2: cout << "\n Enter the number of Course: "; cin >> idnumber;
		displayOneCS(idnumber);break;
	default:
		break;
	}

	}


	default:
		break;
	}


	

	}
	case 2:break;
	}

}

void entry_men() {
	int a, num;
	char choice;
	system("cls");
	cout << "\n\n\n\tENTRY MENU";
	cout << "\n\n\t1.ENTRY MENU STUDENT";
	cout << "\n\n\t2.ENTRY MENU TEACHER";
	cout << "\n\n\t3.ENTRY MENU EMPLOYEE";
	cout << "\n\n\t4.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-4) ";

	cin >> a;
	switch (a)
	{
	case 1:
	{    system("cls");

	cout << "\n\n\n\n\n\t\t  UNIVERSITY MANAGEMENT SYSTEM \n\n";
	cout << "\t\t------------------------------";
	cout << "\n\t\t \t    LOGIN \n";
	cout << "\t\t------------------------------\n\n";
	

	char ch;
	int count = 0;
	string user, pass;
	Password ps;
	while (count < 3)
	{
		cout << "Enter your's User: " << endl;
		cin >> user;
		cout << "Enter your's Password: " << endl;
		ch = _getch();
		while (ch != 13) {//character 13 is enter
			if (ch != 8) {
				pass.push_back(ch);
				cout << '*';
			}
			else
			{
				pass.pop_back();
				cout << "\b \b";
			}
			ch = _getch();
		}
		string pas = ps.get_password(user);

		if (pas == pass) {
			cout << "\n\n\t1.SELECT COURSE";
			cout << "\n\n\t2.BACK TO MAIN MENU";
			cout << "\n\n\tPlease Enter Your Choice (1-2) ";
			cin >> a;
			switch (a) {
			case 1: cout << "\nEnter the idnumber of student " << endl;
				cin >> num; selectCourse(num); break;
			case 2: break;
			}

		}

		else
		{
			//system("CLS");
			count++;
			cout << "Incorrect username or password, try again.";
			cout << "\nAttempts remaining: " << 3 - count << endl;
		}
	}
	cout << "Out of attempts, access denied.";


	}

	case 2:
	{   system("cls");
	cout << "\n\n\n\tENTRY MENU TEACHER";
	cout << "\n\n\t5.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-5) ";
	cin >> a;
	switch (a) {
	}

	}

	case 3:
	{   system("cls");
	cout << "\n\n\n\tENTRY MENU EMPLOYEE";
	cout << "\n\n\t1.CREATE TEACHER RECORD";
	cout << "\n\n\t2.MODIFY TEACHER RECORD";
	cout << "\n\n\t3.DELETE TEACHER RECORD";
	cout << "\n\n\t4.DELETE TEACHER RECORDS";
	cout << "\n\n\t5.CREATE STUDENT RECORD";
	cout << "\n\n\t6.MODIFY STUDENT RECORD";
	cout << "\n\n\t7.DELETE STUDENT RECORD";
	cout << "\n\n\t8.DELETE STUDENT RECORDS";
	cout << "\n\n\t9.CREATE COURSE RECORD";
	cout << "\n\n\t10.MODIFY COURSE RECORD";
	cout << "\n\n\t11.DELETE COURSE RECORD";
	cout << "\n\n\t12.DELETE COURSE RECORDS";
	cout << "\n\n\t13.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-14) ";
	cin >> a;
	switch (a) {

	case 1:
		do {
			writeTA();
			cout << "\n Teacher record has been created";

			system("cls");
			cout << "Do you want to insert new record of Teacher? Y|N";
			cin >> choice;
			system("cls");
		} while (choice == 'Y' || choice == 'y');
		break;
	case 2: cout << "\nEnter the number of teacher " << endl;
		cin >> num; modifyTA(num); break;
		
	case 3: cout << "\nEnter the number of teacher " << endl;
		cin >> num; delete_TA(num); break;
		
	case 4:  deleteallTA(); break;
	case 5:
		do {
			writest();
			cout << "\n Student record has been created";

			system("cls");
			cout << "Do you want to insert new record of student? Y|N";
			cin >> choice;
			system("cls");
		} while (choice == 'Y' || choice == 'y');
		break;
	case 6: cout << "\nEnter the number of student " << endl;
		cin >> num; modify(num); break;
		break;
	case 7: cout << "\nEnter the number of student " << endl;
		cin >> num; delete_student(num); break;
	
	case 8:  deleteallstudent(); break;

	case 9:
		do {
			writeCS();
			cout << "\n Course record has been created";

			system("cls");
			cout << "Do you want to insert new record of Course? Y|N";
			cin >> choice;
			system("cls");
		} while (choice == 'Y' || choice == 'y');
		break;
	case 10: cout << "\nEnter the number of Course " << endl;
		cin >> num; modifyCS(num); break;
		
	case 11: cout << "\nEnter the number of Course " << endl;
		cin >> num; deleteOneCS(num); break;
		
	case 12:  deleteallCS(); break;
	case 13: break;
	}

	}

	case 4:break;

	}
















}




int main()
{
	int a;





	do {
		system("cls");

		cout << "\n\t\t\t\t  UNIVERSITY MANAGEMENT SYSTEM \n\n";
		cout << "\n\n\t\t\tPlease,  Choose from the following Options: \n\n";
		cout << "\t\t\t _________________________________________________________________ \n";
		cout << "\t\t\t|                                           	                  |\n";
		cout << "\t\t\t|             1  >> REPORT MENU                                   |\n";
		cout << "\t\t\t|             2  >> ENTRY/EDIT MENU                               |\n";
		cout << "\t\t\t|             3  >> EXIT THE PROGRAM                              |\n";
		cout << "\t\t\t|                                                                 |\n";
		cout << "\t\t\t|                                                                 |\n";
		cout << "\t\t\t|_________________________________________________________________|\n\n";
  

		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:report_men(); break;
		case 2:entry_men();
		case 3:break;
		}
	} while (a != 3);


	_getch();
	return 0;
}

