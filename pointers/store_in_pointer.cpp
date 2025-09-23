#include <iostream>
using namespace std;

int main(){
    int a,b;
    int *p1,*p2;
    p1=&a;
    p2=&b;
cout<<"Enter two numbers\n";
cout<<"a:";
cin>>*p1;
cout<<"b:";
cin>>*p2;
cout<<"Values: a="<<*p1<<" b="<<*p2<<endl;
    return 0;
}