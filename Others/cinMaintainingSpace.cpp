#include<iostream>

using namespace std;
int main(){
	string name;
	cout<<"Try to type something and see the magic of using getline(cin, variable)\n=======================================================================\n";
	getline(cin, name);
	
	cout<<"You have entered:"<<name<<endl;
	
	return 0;
}
