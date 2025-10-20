#include <iostream>
using namespace std;

int power(int n, int x){
	if(x==0)return 1;
	return n* power(n,x-1);
}
int main(){
	int answer=power(2,4);
	cout << answer;
	return 0;
}