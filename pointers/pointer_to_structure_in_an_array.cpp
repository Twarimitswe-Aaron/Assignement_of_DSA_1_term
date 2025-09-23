#include<iostream>
#include<string>
using namespace std;
struct Product{
    string name;
    int id;
    double price;
};
int main(){
    Product products[3];
    products[0]={"Acovado",1,10.5};
    products[1]={"Mango",2,20.0};
    products[2]={"Ember",3,15.75};
    int size=sizeof(products)/sizeof(products[0]);
    Product* cardt[size];
    for(int i=0;i<size;i++){
        cardt[i]=&products[i];
    }
    cout<<"Product List:"<<endl;
    for(int i=0;i<size;i++){
        cout<<"Name:"<<cardt[i]->name<<", ID:"<<cardt[i]->id<<", Price:$"<<cardt[i]->price<<endl;
    }

     
    return 0;
}