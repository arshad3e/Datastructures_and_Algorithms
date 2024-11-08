/* this insertion sort has a time complexity on o(n^2) and time complexity of o(1) */

#include<iostream>
#include<cstdlib>
using namespace std;

void insertion(int arr[], int n){

        for(int i=1 ; i<n; i++){
                int key = arr[i];
                int j = i-1;

                while(j >=0 && arr[j] > key){
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = key;
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
