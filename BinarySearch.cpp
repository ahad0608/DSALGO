// Binary Search Algorithm whose time complexity is O(logn).
// This algorithm works when an Array is sorted.
//Approach - We check the mid element if it is greater than the key, then we will find the key in the first half of an array else on the second half of an array.

#include <iostream>
using namespace std;

int BinarySearch(int arr[],int n,int key){
    int start=0;
    int end=n;
    
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==key){
            return mid;     // We are returning the index at which that element will be found.
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1; //If the element is not found then will return -1.
}

int main(){
    //Input an array and its size.
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    int k = BinarySearch(arr,n,key);
    if(k==-1){
    	cout<<"Element is not present in an Array"<<endl;
	}
	cout<<"Element is present at an Index"<<" "<<k<<endl;


    return 0;
}
