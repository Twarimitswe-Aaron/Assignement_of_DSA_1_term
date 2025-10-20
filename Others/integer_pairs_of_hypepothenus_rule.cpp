#include<iostream>
#include<cmath>
using namespace std;
bool functionToCheck(int n){
    int root=sqrt(n);
    return root*root==n;
}

int main(){
    int count=0;
    for(int i=1;i<100;i++){
        for(int j=i;j<100;j++){
            int sum =i *i + j*j;
            if(functionToCheck(sum)){
                cout << "<"<<i<<","<<j<<">"<< endl;
                count++;
            }
        }
    }
    cout << "Total pairs: "<< count << endl;

    return 0;
}