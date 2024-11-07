/* Bubble sort with time complexity of o(n^2) */

#include<iostream>
#include<cstdlib>
using namespace std;

void bubblesort(int arr[], int n){
int i,j;
        for(int i=0;i<n-1;i++){
                for(j=0;j<n-1-i;j++){
                        if(arr[j] >arr[j+1]){
                                int temp = arr[j];
                                    arr[j] = arr[j+1];
                                    arr[j+1] = temp;
                                }
                        }
                }
}

int main(){
        int arr[] = { 10,7,2,3,4};

int s= sizeof(arr)/sizeof(arr[0]);
        bubblesort(arr,s);
for(int i = 0; i < s; i++) {
        cout<<arr[i]<<"  ";
    }
return 0;
