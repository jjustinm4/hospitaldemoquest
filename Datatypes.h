#pragma once
#include<iostream>
#include<string>

using namespace std;

//for maintaining the number of patients , declared globally because in the core logic multiple fucntions access it
extern int nPatientCount = 0;
//for maintaining the number of doctors , declared globally because in the core logic multiple fucntions access it
extern int nDoctorCount = 0;

//in the main there is a logic for selecting the operation to perform 
//the enum operations represents individual operations
enum Operations
{
	AddPatient = 1,
	AddService = 2,
	PatientDetails = 3,
	AlterResources = 4,
	BookSlots = 5,
	ScheduleView = 6
};

//structure variable representing the hospital entity
struct stHospital
{
	int nBeds = 100;
	int nCyliders = 15;
	int nOp_theatres = 5;
	int nAmbulance = 3;
	int nRooms = 100;

};


//structure variable representing the doctor entity
struct stDoctor
{
	int nId;
	int nSlots;
	string csName;
	string csDepartment;
	string csDays[3];
};

//structure variable representing the patient entity
struct stPatient
{
	int nId;
	int nAge;
	string csName;
	string csBlood;
	string csComment;
};

//structure variable representing the admin entity
//helps to demonstrate security modules
struct stAdmin
{
	string csId = "1";
	string csPassword = "1";
};