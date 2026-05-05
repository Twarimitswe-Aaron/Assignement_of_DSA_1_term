#include<iostream>

using namespace std;

namespace values{
	int value=100;
	void printValue(){
		cout << value << "\n";
	}
}

using namespace values;
namespace nsp1{
	int value=200;
}
using namespace nsp1;

int main(){
	printValue();
	cout<<nsp1::value;
	return 0;
}



