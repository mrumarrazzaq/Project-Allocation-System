#include<iostream>
#include<conio.h>
#include<fstream>
#include <sstream>
#include"studentSection.h"
#include"supervisorSection.h"
#include"projectSection.h"
using namespace std;

void Welcome();
void MainMenu();
void InputManager();
void StudentSection();
void SupervisorSection();
void ProjectSection();


//Global Data Types Decrlaration and initilization
bool isContinuous=true;



void Welcome()
{
	cout<<"\n\n\t\t ------------WELCOME------------\n";
	cout<<"\t\t|   Project Allocation System   |\n";	
	cout<<"\t\t|_______________________________|\n";
	cout<<"\t\t_________________________________\n";
}
void MainMenu()
{
	cout<<"\n\t......................................\n";
	cout<<"\t Press S => To open  Student    Section \n";
	cout<<"\t Press V => To open  Supervisor Section \n";
	cout<<"\t Press P => To open  project    Section \n";
	cout<<"\t Press C => To Clear the        Screen \n";
	cout<<"\t Press E => For Exit Program \n";
	cout<<"\t......................................\n";
	
}
void InputManager()
{
	char input;
	cout<<"\n________________________\n";
	cout<<"Enter your choice : ";cin>>input;
	cout<<"________________________\n";
	switch(input)
	{
		case 'S':
			//Taking projects details from the user
			StudentSection();
			break;
		case 'V':
			//Display all the saving records in the console
			SupervisorSection();
			break;
		case 'P':
			ProjectSection();
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

int main()
{
	Welcome();
	while(isContinuous)
	{
		//Display the program options 
		MainMenu();
		//Taking and handline all the user input
		InputManager();	
	}
		//After exit the program display a massage to user 
	cout<<"\n\n----------------------------------------\n";
	cout<<" Thanks for using this SOFTWARE \n\n\n";
	
	return 0;
}





