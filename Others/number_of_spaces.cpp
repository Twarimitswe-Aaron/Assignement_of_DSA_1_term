#include <iostream>
#include <cctype>
using namespace std;

int countSpaces(const string& str){
    int count =0;
    for (char c:str){
        if(c==' '){
            count++;
        }
    }
    return count;
}

void checkCharacterState(char c){
	if(isalpha(c)){
		cout << c << " it is a character"<<endl;
	}else if(isdigit(c)){
		cout << c << " is a number"<<endl;
	}else {
		cout << c << " is neither a character or a number"<<endl;
	}
}

int countWords(const string& str){
    int count=0;
    bool inWord = false;
    for(char c:str){
        if(isspace(c)){
            inWord = false;
        }else{
            if(!inWord){
                count++;
                inWord = true;
            }
        }
    }
    return count;
}
int main(){
    string input;
    char ch;
    cout<< "NUMBER OF SPACES CALCULATOR"<<endl;
    cout<< "==========================="<<endl;
    cout<<"Enter a string: ";
    getline(cin,input);
    int spaceCount = countSpaces(input);
    cout<<"Number of spaces: "<<spaceCount<<endl;
    cout<<"\nSTATE OF CHARACTER IDENTIFIER"<<endl;
    cout<< "============================"<<endl;
    cout<< "Enter character you want to test"<<endl;
    cin >> ch;
    checkCharacterState(ch);
    cout<<"\nWORD COUNTER"<<endl;
    cout<<"============"<<endl;
    cout<<"Enter a string: ";
    cin.ignore(); // To ignore the newline character left in the buffer
    getline(cin,input);
    int wordCount = countWords(input);
    cout<<"Number of words: "<<wordCount<<endl;
    
    
    return 0;
}