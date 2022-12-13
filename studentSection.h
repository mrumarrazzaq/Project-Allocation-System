#include<iostream>
#include<conio.h>
#include<fstream>
#include <sstream>
using namespace std;

void StudentSection();
void writeStudentData(int i);
void writeStudentId();
int readStudentId();

//set the user id from where do you want to start
static int currentStudentId=1000;
int startingStudentId=currentStudentId;

struct StudentData
{
	int studentId ;
	string studentName;
	string studentRegistrationNumber;
	string email;
}stu[10];

void StudentSection()
{
	static int index=0;
	cout<<"\n\t ---------------------------------\n";
	cout<<"\t|        Student Secttion         |\n";
	cout<<"\t ---------------------------------\n";
	//Taking Student Data from user
	cout<<"\n__________ Student Data _____________\n";
	cin.ignore();
	cout<<"Enter Student Name                :  ";getline(cin,stu[index].studentName);
	cout<<"Enter Student Registration Number :  ";cin>>stu[index].studentRegistrationNumber;
	cout<<"Enter Student Email               :  ";cin>>stu[index].email;
	cout<<"\n_____________________________________\n";
	
	stu[index].studentId=readStudentId();
	currentStudentId=readStudentId()+1;
	writeStudentId();
	writeStudentData(index);
	index++;
	cout<<"\n=> Student Details are Added Successfully \n";
}

void writeStudentData(int i)
{
	//Create a ofstream variable
	ofstream writeStuData;
	//Open a particular file name 
		writeStuData.open("StudentData.csv",fstream::app);
		//if any error occur in saving data into file display error massage
		if(writeStuData.fail())
		{
			cout<<"Error while Saving Data in the file\n";
//			exit(0);
		}
		//Save all the recors into the csv file by the name
		if(readStudentId()==startingStudentId+1)
		{
			writeStuData<<"Student Id"<<", "<<"Student Name"<<", "<<"Student Registration"<<", "<<"Email"<<"\n";
		
		}
		
		writeStuData<<stu[i].studentId<<", "<<stu[i].studentName<<", "<<stu[i].studentRegistrationNumber<<", "<<stu[i].email<<endl;
		writeStuData.close();
		
}


//Function to save and maintain the system record
void writeStudentId()
{
	//Create a ofstream variable
	ofstream writeSID;
	 // opening a particular name file
		writeSID.open("StudentId.txt");
	//if any error occur in saving data into the file and display error massage
		if(writeSID.fail())
		{
			cout<<"Error while Saving Data in the file\n";
//			exit(0);
		}
		writeSID<<currentStudentId;
		writeSID.close();
		
}
int readStudentId()
{
	char ch;
	int StuID;
	ifstream readStuID;
  	string str;
  	stringstream ss; 
    // opening file
	readStuID.open("StudentId.txt");
	//if any error occur in opening file and display error massage
	if(!readStuID.is_open())
	{
		cout<<"Error while opening System File\n";
//		exit(0);
	}
	//Fetch all the system file data(like StudentId) and convert it into number 
	readStuID.get(ch);
	while(!readStuID.eof())
	{
		 str+=ch;	
		readStuID.get(ch);	
	}
	readStuID.close();
	ss << str;  
  	ss >> StuID;
	return StuID;
}
