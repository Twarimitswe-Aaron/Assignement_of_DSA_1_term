#include <iostream>
using namespace std;
int sumOfArray(int arra[],int n){
	if(n==0){
		return 0;
	}
	return arra[n-1]+ sumOfArray(arra,n-1);	
}

int main(){
	int arra[]={1,2,3,4};
	int size=sizeof(arra)/sizeof(arra[0]);
	int sum=sumOfArray(arra,size);
	cout << sum;
}