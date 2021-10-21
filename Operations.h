#pragma once

#include <iostream>
#include "Datatypes.h"

using namespace std;

//function for handling the slot management
//argument is the particular doctor structure instance whoose slot needs to be manipulated
void SlotHandler( stDoctor & doc )
{
	int slot;
	cout << "==================================================================================" << endl;
	cout << "How many slots do you need   :" << endl;
	cout << "==================================================================================" << endl;
	cin >> slot;
	cout << endl;
	if ( slot > doc.nSlots )
	{
		cout << "==================================================================================" << endl;
		cout << "Sorry..!! The request number exceeds the available slots hence cannot be allocated..!!" << endl;
		cout << "==================================================================================" << endl;
		return;
	}
	else
	{
		cout << "==================================================================================" << endl;
		cout << slot << " Slots are allocated...!!" << endl;
		cout << "==================================================================================" << endl;
		doc.nSlots -= slot;
	}
}
//major function for handling central assets like hospital resources and doctors
//theres another function that manipulates the resource but this one decides the change in actual number of resources
//admin is passed for security purpose , hospital instance is for changing the number of resources
//doctor instance is passed for adding a doctor instance
void ResourceHandler( stAdmin ad, stHospital & hosp, stDoctor & doc )
{

	int nTemp;
	string csIdTemp;
	string csPasswd;
	system("cls");
	cout << "Welcome admin , enter your credentials" << endl;
	cout << "Id         :";
	cin >> csIdTemp;
	cout << endl;
	cout << "Password   :";
	cin >> csPasswd;
	cout << endl;
	//checking the negative condition first for faster execution

	//found credentials valid  , hence executing the exit-controlled loop
	do
	{
		if (csIdTemp != ad.csId || csPasswd != ad.csPassword)
		{
			cout << "Invalid credentials..!!" << endl;
			return;
		}
		cout << "=====================================================================================" << endl;
		cout << "Which operation you wish to perform , enter the serial number associated with it.." << endl;
		cout << "=====================================================================================" << endl;
		cout << "1. Alter the resource availabilty " << endl;
		cout << "=======================================" << endl;
		cout << "2. Add a doctor" << endl;
		cout << "=======================================" << endl;
		cin >> nTemp;
		switch (nTemp)
		{
		case 1:
		{
			//showing the available resources at present
			cout << "The resource availabilty is " << endl;
			cout << "=============================" << endl;
			cout << "1.Beds                : " << hosp.nBeds << endl;
			cout << "=============================" << endl;
			cout << "2.Cylinders           :" << hosp.nCyliders << endl;
			cout << "=============================" << endl;
			cout << "3.Operation theatres  :" << hosp.nOp_theatres << endl;
			cout << "=============================" << endl;
			cout << "4.Ambulances          :" << hosp.nAmbulance << endl;
			cout << "=============================" << endl;
			cout << "5.Available rooms     :" << hosp.nRooms << endl;
			cout << "=============================" << endl;
			cout << "Enter the resource number to modify" << endl;
			cout << "=============================" << endl;
			cin >> nTemp;
			//choosing which resource to modify
			//here evevry value is accepetd because in real life an admin can add any number of resources
			switch (nTemp)
			{
			case  1:
			{
				cout << "Enter new availability of beds : ";
				cin >> nTemp;
				cout << endl;
				hosp.nBeds = nTemp;
				cout << "Beds availabilty has been updated , now there are " << hosp.nBeds << " available..!" << endl;
				break;
			}
			case 2:
			{
				cout << "Enter new availability of cylinders : ";
				cin >> nTemp;
				cout << endl;
				hosp.nCyliders = nTemp;
				cout << "Cylinders availabilty has been updated , now there are " << hosp.nCyliders << " available..!" << endl;
				break;
			}
			case 3:
			{
				cout << "Enter new availability of operation theatres : ";
				cin >> nTemp;
				cout << endl;
				hosp.nOp_theatres = nTemp;
				cout << "Operation theatres availabilty has been updated , now there are " << hosp.nOp_theatres << " available..!" << endl;
				break;
			}
			case 4:
			{
				cout << "Enter new availability of  ambulances : ";
				cin >> nTemp;
				cout << endl;
				hosp.nAmbulance = nTemp;
				cout << "Ambulance availabilty has been updated , now there are " << hosp.nAmbulance << "  available..!" << endl;
				break;
			}
			case 5:
			{
				cout << "Enter new availability of rooms : ";
				cin >> nTemp;
				cout << endl;
				hosp.nRooms = nTemp;
				cout << "Rooms availabilty has been updated , now there are " << hosp.nRooms << "  available..!" << endl;
				break;
			}
			default:
			{
				cout << "Invalid option" << endl;
			}
			}
			break;
		}
		case 2:
		{
			cout << "Enter details of the doctor" << endl;
			cout << "===============================" << endl;
			cout << "\nID          :";
			cin >> doc.nId;
			cout << "\nSLOTS       :";
			cin >> doc.nSlots;
			cout << "\nName        :";
			cin >> doc.csName;
			cout << "\nDEAPRTMENT  :";
			cin >> doc.csDepartment;
			cout << "===============================" << endl;
			cout << "\nEnter days of availabilty  : " << endl;
			cout << "===============================" << endl;
			cout << "\nEnter in 'mon' , 'tue' , 'wed' ,' thu' , 'fri' , 'sat'  format only" << endl;
			cout << "=====================================================================" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << "DAY " << i + 1 << " doctor will be available is :";
				cin >> doc.csDays[i];
				cout << endl;
			}
			//updating the count of available doctors
			nDoctorCount += 1;
			break;
		}
		default:
		{
			//handling the error scenario
			cout << "Invalid entry ..!" << endl;
			break;
		}
		}
	} while (false);

}
void ResourceRequestHandler ( stHospital & hosp )
{

	//this fucntion is accessible to public ,  through which the demand will be read and if satisfiable
	//will be allocated 
	int nTemp = 0;
	cout << "The resource availabilty status on APOLLO hospital is listed below" << endl;
	cout << "======================================================================" << endl;
	cout << "1. Beds                : " << hosp.nBeds << endl;
	cout << "======================================================================" << endl;
	cout << "2. Cylinders           :" << hosp.nCyliders << endl;
	cout << "======================================================================" << endl;
	cout << "3. Operation theatres  :" << hosp.nOp_theatres << endl;
	cout << "======================================================================" << endl;
	cout << "4. Ambulances          :" << hosp.nAmbulance << endl;
	cout << "======================================================================" << endl;
	cout << "5. Available rooms     :" << hosp.nRooms << endl;
	cout << "======================================================================" << endl;
	cout << "Enter the serial number of the resource you wish to access" << endl;
	cout << "======================================================================" << endl;
	cin >> nTemp;
	switch (nTemp)
	{
	case 1:
	{
		cout << "Enter necessity of beds: ";
		cin >> nTemp;
		cout << endl;
		//checking the negative condition first
		if (nTemp > hosp.nBeds)
		{
			cout << "Sorry..! We Cannot allocate resource as they exceed the actual availabilty..!" << endl;
			//exiting the fucntion as user demanded more than what is available in the pool
			//this logic is applied on every cases followed
			return;
		}
		hosp.nBeds -= nTemp;
		cout << nTemp << "  Beds are allocated" << endl;
		break;
	}
	case 2:
	{
		cout << "Enter necessity of cylinders : ";
		cin >> nTemp;
		cout << endl;
		if (nTemp > hosp.nCyliders)
		{
			cout << "Sorry..! We Cannot allocate resource as they exceed the actual availabilty..!" << endl;
			return;
		}
		hosp.nCyliders -= nTemp;
		cout << nTemp << " cylinders are allocated" << endl;
		break;
	}
	case 3:
	{
		cout << "Enter necessity of  operation theatres : ";
		cin >> nTemp;
		cout << endl;
		if (nTemp > hosp.nOp_theatres)
		{
			cout << "Sorry..! We Cannot allocate resource as they exceed the actual availabilty..!" << endl;
			return;
		}
		hosp.nOp_theatres -= nTemp;
		cout << nTemp << " Operation theatres are allocated" << endl;
		break;
	}
	case 4:
	{
		cout << "Enter necessity of   ambulances : ";
		cin >> nTemp;
		cout << endl;
		if (nTemp > hosp.nAmbulance)
		{
			cout << "Sorry..! We  Cannot allocate resource as they exceed the actual availabilty..!" << endl;
			return;
		}
		hosp.nAmbulance -= nTemp;
		cout << nTemp << "  Ambulances are allocated" << endl;
		break;
	}
	case 5:
	{
		cout << "Enter necessity of  rooms : ";
		cin >> nTemp;
		cout << endl;
		if (nTemp > hosp.nRooms)
		{
			cout << "Sorry..! We  Cannot allocate resource as they exceed the actual availabilty" << endl;
			return;
		}
		hosp.nRooms -= nTemp;
		cout << nTemp << "  Rooms are allocated" << endl;
		break;
	}
	default:
	{
		//error input
		cout << "Invalid input..!" << endl;
	}
	}
}
void PatientViewer(stPatient pat)
{

	//fucntion accessible to public , for viewing purpose only

	cout << "==========================================" << endl;
	cout << "Name            :" << pat.csName << endl;
	cout << "==========================================" << endl;
	cout << "Age             :" << pat.nAge << endl;
	cout << "==========================================" << endl;
	cout << "Blood group     :" << pat.csBlood << endl;
	cout << "==========================================" << endl;
	cout << "Other details   :" << pat.csComment << endl;
	cout << "==========================================" << endl;

}
void PatientAdder(stAdmin ad, stPatient patient[])
{

	//function for adding a patient
	string csIdTemp;
	string csPasswd;
	cout << "welcome admin , enter your credetials" << endl;
	cout << "Id         :";
	cin >> csIdTemp;
	cout << endl;
	cout << "Password   :";
	cin >> csPasswd;
	cout << endl;
	do
	{
		if (csIdTemp != ad.csId || csPasswd != ad.csPassword)//nEGATIVE CONDITIONS 
		{
			//winding up oprations here
			cout << "Invalid credentials..!!" << endl;
			return;
		}
		cout << "Enter details of the patient" << endl;
		int nIdtemp;
		int nAgetemp;
		string csNametemp;
		string csBloodtemp;
		string csCommenttemp;
		cout << "ID                         :";
		cin >> nIdtemp;
		cout << endl;
		cout << "Age                        :";
		cin >> nAgetemp;
		cout << endl;
		cout << "Name                        :";
		cin >> csNametemp;
		cout << endl;
		cout << "Blood Group                 :";
		cin >> csBloodtemp;
		cout << endl;
		cout << "Commnets on health status    :";
		cin >> csCommenttemp;
		cout << endl;
		patient[nPatientCount].nId = nIdtemp;
		patient[nPatientCount].nAge = nAgetemp;
		patient[nPatientCount].csName = csNametemp;
		patient[nPatientCount].csBlood = csBloodtemp;
		patient[nPatientCount].csComment = csCommenttemp;
		nPatientCount += 1;

	} while (false);

}