#include<iostream>

using namespace std;

int main(){
	string objects;
	cout << "Enter comma-separated values: ";
	getline(cin, objects, ',');//stop at comma
	cout << "First value:"<<objects<<endl;
	
	return 0;
}