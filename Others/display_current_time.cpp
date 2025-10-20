#include<iostream>
#include<ctime>
using namespace std;

void displayCurrentTime(){
    time_t now =time(0);
    tm* localTime=localtime(&now);
    cout << "Current time:"
        << (1900+localTime->tm_year)<< "-"
        << localTime->tm_mon << "-"
        << localTime->tm_mday<< "-"
        << localTime->tm_hour<<":"
        <<localTime->tm_sec<<endl;
}

int main(){
    cout << "Display Current Time\n==================="<< endl;
    displayCurrentTime();
    return 0;
}