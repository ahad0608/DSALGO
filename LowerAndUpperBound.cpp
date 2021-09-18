// Lower Bound - Given a sorted array, first element which is greater or equal to key element.
//Upper Bound - Given a sorted array, first element which is greater than key element.

#include <iostream>
using namespace std;

class Solution{
    public:
    int upperbound(int arr[],int n,int x){  //Here our key element is x;
        int ans =n; // We are initialising ans as n that if not able to find upperbound then it will return n;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>x){ // As there can be number greater than x lying towards the left thus high pointer was updated.
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int lowerbound(int arr[],int n,int x){
        int ans =n; // We are initialising ans as n that if not able to find upperbound then it will return n;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>=x){ // As there can be number greater than or equal to x lying towards the left thus high pointer was updated.
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

};

int main(){
    int n=10;
    int arr[10]={3,4,6,6,8,10,10,10,12,14}; // Sorted array was taken.
    Solution obj;
    cout<<obj.lowerbound(arr,n,10)<<endl; // Result should be 5.
    cout<<obj.upperbound(arr,n,10)<<endl; // Result should be 8.

    return 0;
}
