#include <iostream>
#include <string>
using namespace std;

void reversestring(string &line, int i=0){
        int size = line.length();

        if(i == size/2){ return;} else{
        swap(line[i], line[size-1-i];
        reversestring(line, i+1);
}}

int main(){

string line_1 = "arshad";
cout << reversestring(line_1);

return 0;
