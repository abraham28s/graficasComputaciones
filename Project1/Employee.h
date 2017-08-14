#pragma once
#include <string>
class Employee
{
public:
	Employee(int id, std::string firstName, std::string lastName, int salary);
	int GetID();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetName();
	int GetSalary();
	void SetSalary(int salary);
	int GetAnnualSalary();
	int RaiseSalary(int percent);
	std::string Print();


private:
	int _id, _salary;
	std::string _firstName, _lastName;

};

