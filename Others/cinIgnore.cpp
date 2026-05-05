 #include <iostream>
 #include <string>
 using namespace std;
 int main() {
 int age;
 string fullName;
 cout<<"see the power of using  cin.ignore() after cin\n";
 cin >> age;
 cin.ignore();

 getline(cin, fullName);
 cout << fullName << " is " << age << " years old.\n";
 }