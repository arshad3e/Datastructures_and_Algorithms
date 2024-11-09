#include<iostream>
using namespace std;

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
