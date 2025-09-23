#include <iostream>
using namespace std;

void PrintArray(int* arr,int size){
    cout<<"[";
    for(int i=0;i<size;i++){
        if(i>0) cout << ",";
        cout << *(arr+i);
    }
    cout<<"]"<<endl;

}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr=arr;
    int size = sizeof(arr) / sizeof(arr[0]);
    PrintArray(ptr, size);

    return 0;
}