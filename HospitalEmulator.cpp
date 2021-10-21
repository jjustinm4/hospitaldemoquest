//program for demonstrating structures and acces functions
//written by kiran , karthika and justin.m on 19th octiber 2021

#include<iostream>
//for functions like system(cls)
#include<stdlib.h>
//for handling string variables
#include<string>
//for _getchar() function
#include<conio.h>
//all dattaypes are defined inside this header
#include "Datatypes.h"
//all functions are defined inside this header
#include "Operations.h"

using namespace std;

int main()
{
	//driver code
	//boolean variable for controlling the while loop on line 399 , which controls the whole flow
	bool bControlFlag = true;
	//this integer variable is responsible for invoking individual fucntions
	int nControl;
	//character variable helps to exit program if needed ,  this if not entered as 'y' will set the control flag to false
	char control;
	//defining structure variables
	stHospital hospital;
	stDoctor doctors[5];
	stPatient patients[5];
	stAdmin admin;
	//starting the infinite while loop 
	while (bControlFlag)
	{

		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "                        Welcome to APOLLO hospitals" << endl;
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "     kindly use the folllowing serial numbers to perform the respective operation" << endl;
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "       Sno.                  Respective operation" << endl;
		cout << "       ||                              ||" << endl;
		cout << "       \\/                              \\/                   " << endl;
		cout << endl;
		cout << "     | 1 |                         For adding a patient (Admin only)" << endl;
		cout << endl;
		cout << "     | 2 |                         For requesting a service" << endl;
		cout << endl;
		cout << "     | 3 |                         For viewing patient details " << endl;
		cout << endl;
		cout << "     | 4 |                         To alter the resources / add a doctor  (Admin only)" << endl;
		cout << endl;
		cout << "     | 5 |                         For slot booking" << endl;
		cout << endl;
		cout << "     | 6 |                         For schedule related queries" << endl;
		cout << endl;
		cout << endl;
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

		cout << "      *You can enter any other key for killing the program " << endl;
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

		cout << "Enter your choice  : ";
		cin >> nControl;
		cout << endl;
		//switching with enumerator to avoid numericals values 
		switch(nControl)
		{
		case Operations::AddPatient :
		{
			system("cls");
			PatientAdder(admin, patients ) ;
			_getch();
			system("cls");
			break;
		}
		case Operations::AddService:
		{
			system("cls");
			ResourceRequestHandler(hospital);
			_getch();
			system("cls");
			break;
		}
		case Operations::PatientDetails:
		{
			//this is a numerical comparison , hence switch is not used
			if (nPatientCount > 0)
			{
				system("cls");
				int structid = 100;
				int nID;
				cout << "==================================================================================" << endl;
				cout << "Enter patient id    :" << endl;
				cout << "==================================================================================" << endl;
				cin >> nID;
				for (int i = 0; i < nPatientCount; i++)
				{
					if (patients[i].nId == nID)
					{
						structid = i;
						break;
					}
				}
				if (structid != 100)
				{
					PatientViewer(patients[structid]);
				}
				else
				{
					cout << "Sorry..!! couldnt find the patient with given id..!" << endl;
				}
				_getch();
				system("cls");
			}
			else
			{
				cout << "Sorry..!! No patient data exist as of now...!!" << endl;
				_getch();
				system("cls");
			}
			break;
		}
		case Operations::AlterResources:
		{
			system("cls");
			ResourceHandler(admin, hospital, doctors[nDoctorCount]);
			_getch();
			system("cls");
			break;
		}
		case Operations::BookSlots:
		{
			system("cls");
			cout << "==================================================================================" << endl;
			cout << "==================================================================================" << endl;
			cout << "The list of doctors and their available slots are" << endl;
			cout << "==================================================================================" << endl;
			cout << "==================================================================================" << endl;

			for (int i = 0; i < nDoctorCount; i++)
			{
				cout << doctors[i].nId << "----" << doctors[i].csName << "-------" << doctors[i].nSlots << endl;
			}
			cout << "==================================================================================" << endl;
			cout << "Please enter the id of the doctor you wish to book a slot for" << endl;
			cout << "==================================================================================" << endl;
			int nDocId;
			cin >> nDocId;
			SlotHandler(doctors[nDocId - 1]);
			_getch();
			system("cls");
			break;
		}
		case Operations::ScheduleView:
		{
			system("cls");
			int nTemp;
			cout << "==================================================================================" << endl;
			cout << "           If you wish to know the schedule of a doctor enter '1'" << endl;
			cout << "==================================================================================" << endl;
			cout << "          If you wish to know the schedule of a department enter '2'" << endl;
			cout << "==================================================================================" << endl;
			cin >> nTemp;
			switch (nTemp)
			{
			case 1:
			{
				if (nDoctorCount > 0)
				{
					cout << "==================================================================================" << endl;
					cout << "The doctors are" << endl;
					cout << "==================================================================================" << endl;
					for (int i = 0; i < nDoctorCount; i++)
					{
						cout << doctors[i].nId << "   " << doctors[i].csName;
						cout << endl;
						cout << endl;
						cout << "==================================================================================" << endl;
					}
					cout << "==================================================================================" << endl;
					cout << "Enter the serial number of the doctor whoose schedule you wish to know" << endl;
					cin >> nTemp;
					cout << "==================================================================================" << endl;
					cout << "Dr. " << doctors[nTemp - 1].csName << " is available on " << endl;
					for (int i = 0; i < 3; i++)
					{
						cout << doctors[nTemp - 1].csDays[i] << "---" << endl;
					}
					cout << "==================================================================================" << endl;
					cout << endl;
				}
				else
				{
					cout << "No doctor data available as of now , please check later...!!" << endl;
				}
				break;
			}
			case 2:
			{
				cout << "==================================================================================" << endl;
				cout << "The available departments are " << endl;
				cout << "==================================================================================" << endl;
				cout << endl;
				cout << "1.'Onkology', 2.'Pediatrecian'  3.'General Medicine'" << endl;
				cout << "==================================================================================" << endl;
				cout << endl;
				cout << "Enter the corresponding serial number to get info" << endl;
				cout << "==================================================================================" << endl;
				cin >> nTemp;

				string department;
				switch (nTemp)
				{
				case 1:department = "onkology"; break;
				case 2:department = "pediatrecian"; break;
				case 3:department = "general"; break;
				default:cout << "Invalid entry" << endl; break;
				}
				for (int i = 0; i < nDoctorCount; i++)
				{
					if (doctors[i].csDepartment == department)
					{
						//temporarly setting this ntemp to 10 to indicate we foud atleast one match
						nTemp = 10;
						cout << "Dr." << doctors[i].csName << " serves in " << department << "  and he is available on " << doctors[i].csDays[0] << "--" << doctors[i].csDays[1] << "--" << doctors[i].csDays[2] << endl;
					}
				}
				if (nTemp != 10)
				{
					cout << "==================================================================================" << endl;
					cout << "Sorry , Currently no doctors available for this department" << endl;
					cout << "==================================================================================" << endl;
				}
				break;
			}
			default:
			{
				cout << "Invalid input..!" << endl;
				break;
			}
			}
			_getch();
			system("cls");
			break;
		}
		default :
		{
			system("cls");
			cout << "==================================================================================" << endl;
			cout << "Invalid choice" << endl;
			cout << "==================================================================================" << endl;
			cout << "Enter 'y' for continue , any other key for termination...!!!" << endl;
			cout << "==================================================================================" << endl;
			cin >> control;
			if (control != 'y')
			{
				bControlFlag = false;
			}
			else
			{
				bControlFlag = true;
			}
			_getch();
			system("cls");
			break;
		}//switch ends
       }
	}
}