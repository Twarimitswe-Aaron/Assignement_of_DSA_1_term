#include<iostream>
using namespace std;

class Rectangle {
	
	
		private:
		double length, width;
	public:
			 Rectangle(double a, double b){
			this->lenghtSetter(a);
			this->widthSetter(b);	
		}
		void lenghtSetter(double a){
				if(a<0){
				this->length=1.0;
			}else{
				this->length=a;
			}
			
		}
		void widthSetter(double a){
			if(a<0){
				this->width=1.0;
			}else{
				this->width=a;
			}
			
		}
		
		double lengthGetter(){
			return this->length;
		}
		double widthGetter(){
			return this->width;
		}
		double area(){
			return this->length*this->width;
		}
		
		
	
	
		
		

	
		
};

int main(){
	Rectangle r(1,1);
	double area=r.area();
	cout << area;
	
	
	return 0;
}