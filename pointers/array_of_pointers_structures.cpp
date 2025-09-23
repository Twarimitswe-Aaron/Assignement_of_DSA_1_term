#include<iostream>
#include<string>
using namespace std;
struct Employee{
    int id;
    string name;
    float salary;
};

void displayEmployees(Employee** employees, int size){
    cout<< "Employee list:"<<endl;
    for(int i=0;i<size;i++){
        cout<<"ID:"<<employees[i]->id<<", Name:"<<employees[i]->name<<", Salary:$"<<employees[i]->salary<<endl;
    }
}

int main(){
    int size =5;
    Employee* storage_of_address;
    Employee* company=new Employee[size];
    Employee** pointers=new Employee*[size];
    for(int i=0;i<size;i++){
        storage_of_address=&company[i];
        pointers[i] = storage_of_address;
    }
    for(int i=0;i<size;i++){
        cout<<"Enter details for Employee "<<i+1<<":"<<endl;
        cout<<"ID: ";
        cin>>company[i].id;
        cout<<"Name: ";
        cin>>company[i].name;
        cout<<"Salary: ";
        cin>>company[i].salary;
    }
    displayEmployees(pointers,size);
    delete[] company;
    return 0;
}