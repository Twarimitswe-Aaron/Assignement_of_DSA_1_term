#include <bits/stdc++.h>

using namespace std;

class Stack{
	public:
		int size;
		int top;
		int *arr;
	
	Stack(int size){
		this->size=size;
		this->top=-1;
		this->arr=new int[size];
	}
	
	void push(int num){
		if (top<size-1){
			arr[++top]=num;
		}
	}
	
	int getSize(){
		return this->top+1;
	}
	
	int pop(){
		if(top>=0){
			return arr[top--];
		}
		return -1;
	}
	
	bool empty(){
		return top ==-1;
	}
	void display(){
		if(top >=0){
			for(int i=0;i<=top;i++){
				cout<< arr[i]<< " ";
				
			}
			cout <<endl;
		}else{
			cout<<"Stack is empty"<<endl;
		}
	}
};

int main(){
	int size, operation;
	bool running=true;
	cout<<"Enter the size of the stack: ";
	cin>> size;
	Stack stack(size);
	
	while(running){
		cout<< "Choose 1 option"<<endl;
	cout<< "==============="<<endl;
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3.size"<<endl;
	cout<<"4.display"<<endl;
	cout<<"5.end"<<endl;
	
	cin>>operation;
	
	switch(operation){
		case 1:
			int noElm,elm,remaining,full;
			cout << "Enter number of elements you want to add: ";
			cin >>noElm;
			remaining=size-stack.getSize();
			full=noElm+stack.getSize();
			
			if(full>size){
				cout <<"elements are exceeding the size "<<endl;
				cout <<"currently you have "<<stack.getSize()<< " elements and the maximum elements must be "<< size<<endl;
				cout << "i.e: you are remaining with : " <<remaining << " remaining elements to fill up your stack";
				
			}else{
					for(int i=0;i<noElm;i++ ){
				cout << "Enter element to push: ";
				cin >> elm;
				stack.push(elm);
				
			}
			}
		
			break;
		case 2:
			stack.pop();
			break;
		case 3:
			cout << stack.getSize();
			break;
			
		case 4:
			stack.display();
			break;
		case 5:
			running=false;
			break;
		default:
			cout<< "Enter a valid option";
	}
	}
	

	return 0;
}