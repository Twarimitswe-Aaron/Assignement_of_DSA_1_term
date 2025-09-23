#include <iostream>
using namespace std;

int* createDynamicArray(int size){
    int* arr=new int[size];
    for(int i=0;i<size;i++){
        arr[i]=i+1;
    }
    return arr;
}

int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    int* dynamicArray=createDynamicArray(size);
    cout<< "Enter your elements:"<<endl;
    for(int i=0;i<size;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>dynamicArray[i];
    }
    cout<<"Dynamic Array: [";
    for(int i=0;i<size;i++){
        if(i>0) cout<<",";
        cout<<dynamicArray[i];
    }
    cout<<"]"<<endl;
    delete[] dynamicArray;

    return 0;
}