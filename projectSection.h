#include<iostream>
#include<conio.h>
#include<fstream>
#include <sstream>
using namespace std;


void ProjectSection();
void writeProjectData(int i);
void writeProjectId();
int readProjectId();

//set the user id from where do you want to start
static int currentProjectId=2100;
int startingProjectId=currentProjectId;



struct ProjectData
{
	int projectID;
	string projecTitle;
}pro[10];


void ProjectSection()
{
	static int index=0;
	cin.ignore();
	cout<<"\n\t ---------------------------------\n";
	cout<<"\t|        Project Secttion         |\n";
	cout<<"\t ---------------------------------\n";
	cout<<"____________ Project Data __________\n";
//	cout<<"Enter Supervisor Id               : ";cin>>pro[index].projectID;
	cout<<"Enter Project Title             : ";getline(cin,pro[index].projecTitle);
	cout<<"\n_____________________________________\n";
	
	pro[index].projectID=readProjectId();
	currentProjectId=readProjectId()+1;
	writeProjectId();
	writeProjectData(index);
	index++;
	cout<<"\n=> Project Details are Added Successfully \n";
}

void writeProjectData(int i)
{
	//Create a ofstream variable
	ofstream writeproData;
	//Open a particular file name 
		writeproData.open("ProjectData.csv",fstream::app);
		//if any error occur in saving data into file display error massage
		if(writeproData.fail())
		{
			cout<<"Error while Saving Data in the file\n";
//			exit(0);
		}
		//Save all the recors into the csv file by the name
		if(readProjectId()==startingProjectId+1)
		{
			writeproData<<"ProjectId"<<", "<<"ProjectTitle"<<"\n";
		
		}
		
		writeproData<<pro[i].projectID<<", "<<pro[i].projecTitle<<endl;
		writeproData.close();
		
}


void writeProjectId()
{
	//Create a ofstream variable SID(supervisor ID)
	ofstream writePID;
	 // opening a particular name file
		writePID.open("ProjectId.txt");
	//if any error occur in saving data into the file and display error massage
		if(writePID.fail())
		{
			cout<<"Error while Saving Data in the file\n";
//			exit(0);
		}
		writePID<<currentProjectId;
		writePID.close();
		
}
//Function is used to read the Project id
int readProjectId()
{
	char ch;
	int PID;
	ifstream readPID;
  	string str;
  	stringstream ss; 
    // opening file
	readPID.open("ProjectId.txt");
	//if any error occur in opening file and display error massage
	if(!readPID.is_open())
	{
		cout<<"Error while opening System File\n";
//		exit(0);
	}
	//Fetch all the system file data(like ProjectId) and convert it into number 
	readPID.get(ch);
	while(!readPID.eof())
	{
		 str+=ch;	
		readPID.get(ch);	
	}
	readPID.close();
	ss << str;  
  	ss >> PID;
	return PID;
}
