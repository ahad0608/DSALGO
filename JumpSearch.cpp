#include <iostream>
#include <cmath>
using namespace std;
// Jump Search - In a sorted array, here we can find our element by jumping steps(optimal step is considered sqrt(size of an array i.e n))
// Time Complexity O(sqrt(n))

class Search{
    public:
        int JumpSearch(int arr[],int n,int x){
            int k = sqrt(n); // Steps for our Jump.
            int prev=0;
            // Here we have found the index at which value is less than our desired element and at next jump value is greater than our desired jump.
            // Thus our desired element if present is going to be available at this range.
            while(arr[k]<x && k<n){
                prev=k;
                k+=sqrt(n);
            }
            while(prev<n){
                prev++;
                if(arr[prev]==x){
                    return prev;
                }
            }
            return -1;
        }
        // Same as Binary Search but with the optimized position to toggle rather than middle element.
        int InterpolationSearch(int arr[],int low,int high,int x){
            int pos;
            if(low <= high && x>=arr[low] && x<=arr[high]){
                pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

                if(arr[pos]==x){
                    return pos;
                }
                else if(arr[pos]>x){
                    return InterpolationSearch(arr,low,pos-1,x);
                }
                else{
                    return InterpolationSearch(arr,pos+1,high,x);
                }

            }
            return -1; //When element is not found.
        }
        // We can also start with while loop same as binary search.

};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    Search obj;
    cout<<obj.JumpSearch(arr,n,x)<<endl;
    cout<<obj.InterpolationSearch(arr,0,n,x)<<endl;

    return 0;
}
