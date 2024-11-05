#include<iostream>
#include<cstdlib>
using namespace std;

int fibonnaci(int num){
        if(num < 0){ return false;}
        if(num ==0){
                return 0;
        }else if (num ==1){
                return 1;
        } else {
                return fibonnaci(num -1) + fibonnaci(num -2);
        }}

int main(){

        int number;
        cin >> number;
        cout << "fib is:" << fibonnaci(number) ;
        return 0;
}
