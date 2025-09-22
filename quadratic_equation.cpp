#include<iostream>
#include<cmath>
using namespace std;


void quadratic(int a, int b,int c){
    double x1,x2,discriminant,sqrt1,answer;
    discriminant =b*b-4*a*c;
    if(discriminant=0){
        cout << "x1=x2"<< -b/(2.00*a)<<endl;
    }else if(discriminant<0){
     cout<<"The discriminant is less than 0 , no real solution";
    
    }else{
        x1=(-b+sqrt1)/(2*a);
        x2=(-b-sqrt1)/(2*a);
        cout << "x1="<< x1<<"x2="<<x2<<endl;
    }
    sqrt1=sqrt(discriminant);
    if(sqrt1*sqrt1==discriminant){
        
    }else{

    }
    
}

int main(){
    int a,b,c;
    cout << "Quadratic Equation Solver\n========================"<< endl;
    cout << "Enter coefficients a: ";
    cin >> a;
    cout << "Enter coefficients b: ";
    cin >> b;
    cout << "Enter coefficients c: ";
    cin >> c;

    quadratic(a,b,c);


    return 0;
}