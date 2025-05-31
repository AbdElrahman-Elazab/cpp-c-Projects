#pragma once

#include<iostream>
#include"clsPerson.h"
using namespace std;

class clsEmpolyee :public clsPerson {
private:
    string _Title;
    string _Department;
    float _Salary;
public:
    
    clsEmpolyee( string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary)
        :clsPerson( FirstName, LastName, Email, Phone) {
        _Title = Title;
        _Department = Department;
        _Salary = Salary;
    }

    //Property Set
    void setTitle(string Title)
    {
        _Title = Title;
    }
    //Property Get
    string GetTitle()
    {
        return _Title;
    }
    //Property Set
    void setDepartment(string Department)
    {
        _Department = Department;
    }
    //Property Get
    string GetDepartment()
    {
        return _Department;
    }
    //Property Set
    void setSalary(float Salary)
    {
        _Salary = Salary;
    }
    //Property Get
    float GetSalary()
    {
        return _Salary;
    }
    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
       
        cout << "\nFirstName : " << GetFirstName();
        cout << "\nLastName : " << GetLastName();
        cout << "\nFull Name : " << FullName();
        cout << "\nEmail : " << GetEmail();
        cout << "\nPhone : " << GetPhone();
        cout << "\nTitle : " << _Title;
        cout << "\nDepartment: " << _Department;
        cout << "\nSalary : " << _Salary;
        cout << "\n___________________\n";
    }
};
class clsprogramer :public clsEmpolyee {
private:
    string _MainProgrammingLanguage;
public:
    clsprogramer( string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary, string MainProgrammingLanguage)
        :clsEmpolyee( FirstName, LastName, Email, Phone, Title, Department, Salary)\
    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }
    //Property Set
    void setMainProgrammingLanguage(string MainProgrammingLanguage)
    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }
    //Property Get
    string MainProgrammingLanguage()
    {
        return _MainProgrammingLanguage;
    }
    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
      
        cout << "\nFirstName               : " << GetFirstName();
        cout << "\nLastName                : " << GetLastName();
        cout << "\nFull Name               : " << FullName();
        cout << "\nEmail                   : " << GetEmail();
        cout << "\nPhone                   : " << GetPhone();
        cout << "\nTitle                   : " << GetTitle();
        cout << "\nDepartment              : " << GetDepartment();
        cout << "\nSalary                  : " << GetSalary();
        cout << "\nMainProgrammingLanguage : " << _MainProgrammingLanguage;
        cout << "\n___________________\n";
    }

};

