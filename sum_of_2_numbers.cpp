#include <iostream>

using namespace std;
int add(int a,int b){
    return a+b;
}

int main(){
    int a,b,c;
    cout << "Enter two numbers to add\n=================="<< endl;
    cin >> a>>b;
    c=add(a,b);
    cout << "The sum of "<< a << " and "<< b<< " is "<< c;
    return 0;
}