#include <iostream>
using namespace std;
struct Student{
   string  name;
   int marks[5];
};

void print(Student* s, int size){
    int sum=0;
    for(int i=0;i<size;i++){
        cout<<"Name:"<<s[i].name;
        for (int j=0;j<5;j++){
            sum+=s[i].marks[j];
        }
        sum/=5;
        cout<<", Total Marks:"<<sum << "/90"<<endl;
    }

}
int main(){
    Student s1={"Alice",{85,90,78,92,88}};
    Student s2={"Bob",{80,70,75,85,90}};
    Student s3={"Charlie",{95,100,98,97,96}};

    Student student[3]={s1,s2,s3};
    int size=sizeof(student)/sizeof(student[0]);
    print(student,size);
    return 0;
}