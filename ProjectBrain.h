#include<iostream>
#include<conio.h>
#include<fstream>
#include <sstream>
#include"studentSection.h"
using namespace std;

void writeData(string word);
void readData();

void fetchStudentData();
void getParticularStudentData();
void fetchSupervisorData();
void getParticularSupervisorData();
void fetchProjectData();
void getParticularProjectData();
void menu();
//set the user id from where do you want to start
string StudentId;
string SupervisorId;
string ProjectId;
bool onlyTrue=true;



void fetchStudentData()
{
	char ch;
	// create a ifstream variable
	ifstream readFile;
    // opening a particular name file
	readFile.open("StudentData.csv");
	//if any error occur in opening file display error massage
	if(!readFile.is_open())
	{
		cout<<"Error while opening Record File\n";
//		exit(0);
	}
	
	//get all the data store into the file
	readFile.get(ch);
	while(!readFile.eof())
	{
	
		if(ch!=',')
		{
			cout<<ch;	
		}
		else
		{
			cout<<" | ";
		}
		readFile.get(ch);	
	
	
	}
	readFile.close();
}

void getParticularStudentData()
{
	int index=0;
	int i=0;
	char ch;
	bool isTrue=true;
	bool isSuccessfullyAdded=false;
	string word,filename;
	cout<<"\n\n Enter Student Id to get the Student Data : ";cin>>StudentId;
	cout<<endl;
	
	// create a ifstream variable
	ifstream readFile;
	filename = "StudentData.csv";
    // opening a particular name file
	readFile.open(filename.c_str(),ios::in);
	//if any error occur in opening file display error massage
	if(!readFile.is_open())
	{
		cout<<"Error while opening Record File\n";
//		exit(0);
	}
   
  
  
    // extracting words from the file
    while (readFile >> word)
    {
//    	cout<<word;
        // displaying content
        if(word==StudentId+",")
        {
        	isTrue=false;
        	isSuccessfullyAdded=true;
        	writeData(word);
        	while(readFile >> word)
        	{
        		if(i<4)
        		{
    	    		cout<<word;
    	    		writeData(word);
        			i++;
				}
				else
				{
					break;
				}
			}	
		} 
    }
    cout<<endl;
    if(isTrue)
   	{
    	cout<<"\n=> No record find at this id ! \n";
	}
	if(isSuccessfullyAdded)
	{
		writeData(",");
		cout<<"\n**********************************\n";
		cout<<"Student Data Added Successfully ! \n";
	}
	
}


void fetchSupervisorData()
{
	char ch;
	// create a ifstream variable
	ifstream readFile;
    // opening a particular name file
	readFile.open("SupervisorData.csv");
	//if any error occur in opening file display error massage
	if(!readFile.is_open())
	{
		cout<<"Error while opening Record File\n";
//		exit(0);
	}
	
	//get all the data store into the file
	readFile.get(ch);
	while(!readFile.eof())
	{
	
		if(ch!=',')
		{
			cout<<ch;	
		}
		else
		{
			cout<<" | ";
		}
		readFile.get(ch);	
	
	
	}
	readFile.close();
}
void getParticularSupervisorData()
{
	int index=0;
	int i=0;
	char ch;
	bool isTrue=true;
	bool isSuccessfullyAdded=false;
	string word,filename;
	
	cout<<"\n\n Enter Supervisor Id to get the Supervisor Data : ";cin>>SupervisorId;
	cout<<endl;
	
	// create a ifstream variable
	ifstream readFile;
	filename = "SupervisorData.csv";
    // opening a particular name file
	readFile.open(filename.c_str(),ios::in);
	//if any error occur in opening file display error massage
	if(!readFile.is_open())
	{
		cout<<"Error while opening Record File\n";
//		exit(0);
	}
   
  
  
    // extracting words from the file
    while (readFile >> word)
    {
//    	cout<<word;
        // displaying content
        if(word==SupervisorId+",")
        {
        	isTrue=false;
        	isSuccessfullyAdded=true;
        	writeData(word);
        	while(readFile >> word)
        	{
        		if(i<1)
        		{
    	    		cout<<word;
    	    		writeData(word);
        			i++;
				}
				else
				{
					break;
				}
			}	
		} 
    }
    cout<<endl;
    if(isTrue)
   	{
    	cout<<"\n=> No record find at this id ! \n";
	}
	if(isSuccessfullyAdded)
	{
		writeData("\n");
		cout<<"\n**********************************\n";
		cout<<"Supervisor Data Added Successfully ! \n";
	}
	
}
void fetchProjectData()
{
	char ch;
	// create a ifstream variable
	ifstream readFile;
    // opening a particular name file
	readFile.open("ProjectData.csv");
	//if any error occur in opening file display error massage
	if(!readFile.is_open())
	{
		cout<<"Error while opening Record File\n";
//		exit(0);
	}
	
	//get all the data store into the file
	readFile.get(ch);
	while(!readFile.eof())
	{
	
		if(ch!=',')
		{
			cout<<ch;	
		}
		else
		{
			cout<<" | ";
		}
		readFile.get(ch);	
	
	
	}
	readFile.close();
}
void getParticularProjectData()
{
	int index=0;
	int i=0;
	char ch;
	bool isTrue=true;
	bool isSuccessfullyAdded=false;
	string word,filename;
	
	cout<<"\n\n Enter Project Id to get the Project Data : ";cin>>ProjectId;
	cout<<endl;
	
	// create a ifstream variable
	ifstream readFile;
	filename = "ProjectData.csv";
    // opening a particular name file
	readFile.open(filename.c_str(),ios::in);
	//if any error occur in opening file display error massage
	if(!readFile.is_open())
	{
		cout<<"Error while opening Record File\n";
//		exit(0);
	}
   
  
  
    // extracting words from the file
    while (readFile >> word)
    {
//    	cout<<word;
        // displaying content
        if(word==ProjectId+",")
        {
        	isTrue=false;
        	isSuccessfullyAdded=true;
        	writeData(word);
        	while(readFile >> word)
        	{
        		if(i<2)
        		{
    	    		cout<<word;
    	    		writeData(word);
        			i++;
				}
				else
				{
					break;
				}
			}	
		} 
    }
    cout<<endl;
    if(isTrue)
   	{
    	cout<<"\n=> No record find at this id ! \n";
	}
	if(isSuccessfullyAdded)
	{
		writeData(",");
		cout<<"\n**********************************\n";
		cout<<"Project Data Added Successfully ! \n";
	}
	
}


//Function to Save the user input data into the csv file
void writeData(string word)
{
	//Create a ofstream variable
	ofstream writeData;
	//Open a particular file name 
		writeData.open("ProjectAllocationRecord.csv",fstream::app);
		//if any error occur in saving data into file display error massage
		if(writeData.fail())
		{
			cout<<"Error while Saving Data in the file\n";
//			exit(0);
		}
		//Save all the recors into the csv file by the name
		if(onlyTrue)
		{
			writeData<<"Stu Id"<<", "<<"Stu Name"<<", "<<"Stu Reg"<<", "<<"Email"<<", "<<"ProjectId"<<", "
		<<"ProjectTitle"<<", "<<"SupervisorId"<<", "<<"SupervisorName"<<"\n";
		onlyTrue=false;
		}
		writeData<<word;
		writeData.close();
		
}
//Function to Display the save records of project to the console
void readData()
{
	cout<<"\n====================================================================================================\n";
	cout<<"\n===================================== Project Allocation Record ====================================\n";
	char ch;
	// create a ifstream variable
	ifstream readFile;
  
    // opening a particular name file
	readFile.open("ProjectAllocationRecord.csv");
	//if any error occur in opening file display error massage
	if(!readFile.is_open())
	{
		cout<<"Error while opening Record File\n";
//		exit(0);
	}
	
	//get all the data store into the file
	readFile.get(ch);
	while(!readFile.eof())
	{
	
		if(ch!=',')
		{
			cout<<ch;	
		}
		else
		{
			cout<<" | ";
		}
		readFile.get(ch);	
	
	
	}
	readFile.close();
	cout<<"\n====================================================================================================\n";
}

