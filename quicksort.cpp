#include <iostream>
using namespace std;

//creating partition function
void partition(int *arr, int pivot, int low, int high){
	int k;
	//condition for greater numbers
	for(int i=low; i<= high; i++){
		if(arr[i]> arr[pivot]){
			k=arr[pivot];
			arr[pivot]= arr[i];
			arr[i]=k;
			pivot=i;
		}
		else{
			if(i>pivot){
				k=arr[pivot];
				arr[pivot]= arr[i];
				arr[i]= k;
				pivot= i;
			}
		}
	}
}

//function for quick sort
void qs(int *arr, int low, int high){
	//choosing pivot
	int pivot= high;
	//making partition using the pivot
	partition(arr, pivot, low, high);
	//calling the functions
	qs(arr, low, pivot-1);
	qs(arr, pivot+1, high);
}

//main function
int main(){
	int arr[7]= {2,5,6,9,1,0,56};
	qs(arr, 0, 6);
	for(int i=0; i<7; i++){
		cout<< arr[i]<< " ";
	}
}