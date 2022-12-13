#include<iostream>
#include<conio.h>
#include<fstream>
#include <sstream>
using namespace std;

void SupervisorSection();
void writeSupervisorData(int i);
void writeSupervisorId();
int readSupervisorId();

//set the user id from where do you want to start
static int currentSupervisorId=4010;
int startingSupervisorId=currentSupervisorId;

struct SupervisorData
{
	int supervisorId;
	string supervisorName;
}sup[10];

void SupervisorSection()
{
	static int index=0;
	cin.ignore();
	cout<<"\n\t ---------------------------------\n";
	cout<<"\t|       Supervisor Secttion        |\n";
	cout<<"\t ---------------------------------\n";
	cout<<"____________ Supervisor Data _____________\n";
//		cout<<"Enter Project ID                  : ";cin>>sup[index].supervisorId;
	cout<<"Enter Supervisor Name                : ";getline(cin,sup[index].supervisorName);
	cout<<"\n_____________________________________\n";
	
	sup[index].supervisorId=readSupervisorId();
	currentSupervisorId=readSupervisorId()+1;
	writeSupervisorId();
	writeSupervisorData(index);
	index++;
	cout<<"\n=> Supervisor Details are Added Successfully \n";
}
void writeSupervisorData(int i)
{
	//Create a ofstream variable
	ofstream writeSupData;
	//Open a particular file name 
		writeSupData.open("SupervisorData.csv",fstream::app);
		//if any error occur in saving data into file display error massage
		if(writeSupData.fail())
		{
			cout<<"Error while Saving Data in the file\n";
//			exit(0);
		}
		//Save all the recors into the csv file by the name
		if(readSupervisorId()==startingSupervisorId+1)
		{
			writeSupData<<"SupervisorId"<<", "<<"SupervisorName"<<"\n";
		
		}
		
		writeSupData<<sup[i].supervisorId<<", "<<sup[i].supervisorName<<endl;
		writeSupData.close();
		
}

void writeSupervisorId()
{
	//Create a ofstream variable SID(supervisor ID)
	ofstream writeSupID;
	 // opening a particular name file
		writeSupID.open("SupervisorId.txt");
	//if any error occur in saving data into the file and display error massage
		if(writeSupID.fail())
		{
			cout<<"Error while Saving Data in the file\n";
//			exit(0);
		}
		writeSupID<<currentSupervisorId;
		writeSupID.close();
		
}
int readSupervisorId()
{
	char ch;
	int SupID;
	ifstream readSupID;
  	string str;
  	stringstream ss; 
    // opening file
	readSupID.open("SupervisorId.txt");
	//if any error occur in opening file and display error massage
	if(!readSupID.is_open())
	{
		cout<<"Error while opening System File\n";
//		exit(0);
	}
	//Fetch all the system file data(like SupervisorId) and convert it into number 
	readSupID.get(ch);
	while(!readSupID.eof())
	{
		 str+=ch;	
		readSupID.get(ch);	
	}
	readSupID.close();
	ss << str;  
  	ss >> SupID;
	return SupID;
}
