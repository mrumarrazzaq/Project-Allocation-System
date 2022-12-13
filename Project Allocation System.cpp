#include<iostream>
#include<conio.h>
#include<fstream>
#include <sstream>
#include"ProjectBrain.h"
using namespace std;


//Functions prototypes
void Welcome();
void DisplayMenu();
void InputManager(char input);

void ProjectAssignmentSection();
void ProjectAssignmentInputManager();

void StudentsSection();
void SupervisorSection();
void ProjectSection();

//Global Data Types Decrlaration and initilization
bool isContinuous=true;



void Welcome()
{
	cout<<"\n\n\t\t ------------WELCOME------------\n";
	cout<<"\t\t|   Project Allocation System   |\n";	
	cout<<"\t\t|_______________________________|\n";
}
//Function to Display the Main project Options to the user 
void DisplayMenu()
{
	
	cout<<"\n\t_____________________________________\n";
	cout<<"\t Press A => Project Assignment Section \n";
	cout<<"\t Press V => For View All Data \n";
	cout<<"\t Press C => For Clear Screen \n";
	cout<<"\t Press E => For Exit Program \n";
	cout<<"\t_____________________________________\n";
	
}
//Funtion to take the input option and serve accordingly
void InputManager()
{
	char input;
	cout<<"\n________________________\n";
	cout<<"Enter your choice : ";cin>>input;
	cout<<"________________________\n";
	switch(input)
	{
		case 'A':
			ProjectAssignmentSection();
			break;
		case 'V':
			//Display all the saving records in the console
			readData();
			break;
		case 'C':
			//Clear the screen content if content cover all the screen
			system("CLS");
			break;
		case 'E':
			//Exit the running program and stop taking input from user
			isContinuous=false;
			break;
		default:
			//If user not enter correct options display a error massage
			cout<<"Please enter a valid Option ! \n";
			InputManager();
			break;
	}

}
void ProjectAssignmentSection()
{
	cout<<"\n\t ---------------------------------------------------\n";
	cout<<"\t|       Welcome to Project Assignment Section         |\n";
	cout<<"\t -----------------------------------------------------\n";
	StudentsSection();
}
void StudentsSection()
{
	cout<<"\n\t_____________________________________\n";
	cout<<"\t Press S => Search for Available Students \n";
	cout<<"\t Press M => For Go back to Main Menu \n";
	cout<<"\t Press C => For Clear Screen \n";
	cout<<"\t_____________________________________\n";
	
	ProjectAssignmentInputManager();
}
void SupervisorSection()
{
	cout<<"\n\t_____________________________________\n";
	cout<<"\t Press V => Search for Available Supervisor \n";
	cout<<"\t Press M => For Go back to Main Menu \n";
	cout<<"\t Press C => For Clear Screen \n";
	cout<<"\t_____________________________________\n";
	
	ProjectAssignmentInputManager();
}
void ProjectSection()
{
	cout<<"\n\t_____________________________________\n";
	cout<<"\t Press P => Search for Available Project \n";
	cout<<"\t Press M => For Go back to Main Menu \n";
	cout<<"\t Press C => For Clear Screen \n";
	cout<<"\t_____________________________________\n";
	
	ProjectAssignmentInputManager();
}
void ProjectAssignmentInputManager()
{
	char input;
	cout<<"\n________________________\n";
	cout<<"Enter your choice : ";cin>>input;
	cout<<"________________________\n";
	switch(input)
	{
		case 'S':
			fetchStudentData();
			getParticularStudentData();
			ProjectSection();
			break;
		case 'V':
			fetchSupervisorData();
			getParticularSupervisorData();
			break;
		case 'P':
			fetchProjectData();
			getParticularProjectData();
			SupervisorSection();
			break;
		case 'C':
			//Clear the screen content if content cover all the screen
			system("CLS");
			ProjectAssignmentSection();
			break;
		case 'M':
			writeData("\n");
			DisplayMenu();
			break;
		default:
			//If user not enter correct options display a error massage
			cout<<"Please enter a valid Option ! \n";
			ProjectAssignmentInputManager();
			break;
	}
}

//Driver of the program
int main()
{
	//Display the welcome program context
	Welcome();
//	Continues run the program 
	while(isContinuous)
	{
		//Display the program options 
		DisplayMenu();
		//Taking and handline all the user input
		InputManager();	
	}
	//After exit the program display a massage to user 
	cout<<"\n\n----------------------------------------\n";
	cout<<" Thanks for using this SOFTWARE \n\n\n";
	
	return 0;
}


