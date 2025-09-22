#include <iostream>


namespace arthimetic{
    int add(int a, int b){
        return a+b;
    }
    int subtract(int a, int b){
        return a-b;
    }
    int multiply(int a, int b){
        return a*b;
    }
    int divide(int a, int b){
        if(b==0){
            std::cerr << "Erro: Division by zero?"<<std::endl;
            return 0;
        }
        return a/b;
    }
    int modulus1(int a, int b){
        if(b==0){
            std::cerr << "Erro: Division by zero?"<<std::endl;
            return 0;
        }
        return a%b;
    }
}
using namespace std;
using namespace arthimetic;

void continuePhrase(char flag){
    if (flag=='y'||flag=='Y'){
        return;
    }
    else{
        exit(0);
    }
}

int main(){
    bool running=true;
    int choice,option,a,b,result;
    char flag;
    while (running){
        cout << "\nMENU\n===="<<endl;
        cout << "1. Add"<<endl;
        cout << "2. Subtract"<<endl;    
        cout << "3. Multiply"<<endl;    
        cout << "4. Divide"<<endl;    
        cout << "5. Modulus"<<endl;
        cout << "Choose an option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            result = add(a,b);
            cout << "Result: " << result << endl;
            cout << "Continue? ";
            cin >> flag;
            continuePhrase(flag);

            /* code */
            break;
        case 2:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            result = subtract(a,b);
            cout << "Result: " << result << endl;
            cout << "Continue";
            cin >> flag;
            continuePhrase(flag);

            break;
        case 3:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            result = multiply(a,b);
            cout << "Result: " << result << endl;
            cout << "Continue";
            cin >> flag;
            continuePhrase(flag);

            break;
        case 4:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            result = divide(a,b);
            cout << "Result: " << result << endl;
            cout << "Continue";
            cin >> flag;
            continuePhrase(flag);

          
            break;
        case 5:
             cout << "Enter two numbers: ";
            cin >> a >> b;
            result = modulus1(a,b);
            cout << "Result: " << result << endl;
              cout << "Continue";
            cin >> flag;
            continuePhrase(flag);
            break;
        
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }


    }
   


    return 0;
}