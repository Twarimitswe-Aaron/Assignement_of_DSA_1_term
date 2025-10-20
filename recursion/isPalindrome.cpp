#include <iostream>
#include <cctype> // for tolower()
using namespace std;


bool isPalindrome(string name, int f, int l) {
    if (f >= l) return true;             
    if (name[f] != name[l]) return false; 
    return isPalindrome(name, f + 1, l - 1);
}

int main() {
    string name = "MadAm";  
    
   
    for (int i = 0; i < name.length(); i++) {
        name[i] = tolower(name[i]);
    }

    int size = name.length();
    bool answer = isPalindrome(name, 0, size - 1);

    if (answer) {
        cout << name << " is palindrome";
    } else {
        cout << name << " is not palindrome";
    }

    return 0;
}
