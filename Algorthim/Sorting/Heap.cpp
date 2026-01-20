#include <iostream.h>

void heapify(vector<int>& array, int size, int largest){
	int i=largest;
	int l=i*2+1;
	int r=i*2+2;
	
	if(l<size && array[l]>array[largest]){
		largest=l;
	}
	if(r<size && array[r]>array[largest]){
		largest=r;
	}
	
	if(largest!=i){
		swapp(array[r],array[largest]);
		
	}
	
}

void swapp(int a,int b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void HeapSort(vector<int>& array ){
	
	int size=array.size();
	for (int i=size/2-1;i>=0;i--){
		heap
	}
	
	
}


int main(){
	vector<int> array={1,5,3,4,7,9};
	
	
	
	
	return 0;
}