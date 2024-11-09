/*Selection sort for example (9,8,7,6) we will select 9 as min_index and then compare with 8,7,6 since it is greater than 6 it is swapped and 6,8,7,9
time complexity of o(n^2)*/

#include<iostream>
using namespace std;

/* logic to support swapping*/
void swap(int *num1, int *num2){
        int temp =0;
        temp = *num1;
        *num1 = *num2;
        *num2 = temp;
}

void selection_sort(int arr[], int n){
        for(int i=0; i<n-1; i++){
        int min_index = i;
                for(int j=i+1; j<n;j++){
                        if(arr[j] < arr[min_index]){
                                min_index = j;
                        }
                        if(min_index !=i){
                                swap(&arr[min_index], &arr[i]);
                        }
                        }
}}

int main(){

        int arr[] = {9,8,7,6,5,4};
        int siz = sizeof(arr)/sizeof(arr[0]);
        selection_sort(arr,siz);
        for(int i=0; i<siz; i++){
                cout << arr[i] << " " ;
        }
        return 0;
}
