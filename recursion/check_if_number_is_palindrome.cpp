#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string str){
    string cleanedString;
    for(char ch:str){
        if(isalpha(ch)){
            cleanedString+=tolower(ch);
        }
    }

    int left=0;
    int right=cleanedString.length()-1;
    while(left<right){
        if(cleanedString[left] != cleanedString[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;

}

int main(){
    string input;
    cout << "PALINDROME CHECKER\n================"<< endl;
    cout << "Enter a string: ";
    getline(cin,input);
    if(isPalindrome(input)){
        cout << "\"" << input << "\" is a palindrome."<< endl;
    }else{
        cout << "\"" << input << "\" is not a palindrome."<< endl;
    }
    return 0;
}
