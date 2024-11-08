/* this insertion sort has a time complexity on o(n^2) and time complexity of o(1) */

#include<iostream>
#include<cstdlib>
using namespace std;

/*logic for insertion sort*/
void insertion(int arr[], int n){

        for(int i=1 ; i<n; i++){
                int key = arr[i]; //consider as a pack of cards where we start from card 2 and compare with card 1 and then exchange
                int j = i-1; //this will be the first card that was supposed to be compared

                while(j >=0 && arr[j] > key){ //this loop will continue as long as it takes for example when it comes to value 1 it will compare with 2,5,9 and new=2,2,5,9,5,6
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = key; // here is where 1 will be reassigned to the array 1,2,5,9,5,6
                }
}

int main(){

int new_arr[] = {5,2,9,1,5,6};

int n = sizeof(new_arr)/sizeof(new_arr[0]);

insertion(new_arr,n);

for(int i =0 ; i<n; i++){
        cout << new_arr[i] << " " << endl;
}

return 0;
}
