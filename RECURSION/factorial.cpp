/Code for performing factorial using recursion*/

/* include all the header files required*/

#include <iostream>
#include <cstdlib>
using namespace std;


// Define recursive function called factorial
int factorial(int num){
    if (num < 0){ return false;}
    if (num ==0 || num ==1)
         {
                return 1;
         }else{
                return num*factorial(num-1);
              }
}

int main(){

        int number = 0;
        cout << "Please enter your input:" << endl;
        cin >> number;

        cout << "fact is :" << factorial(number) << endl;

        return 0;
}
