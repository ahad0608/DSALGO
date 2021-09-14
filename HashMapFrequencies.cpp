// This code will help us find the frequency of elements in an array in O(n) time using Hash Mapping.
//This is the efficient approach as it takes O(n) time rather than O(n*n) [which occurs when we use nested loop].

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// It is a better practise to use class as it helps us efficiently manage our code.
class Solution{
    public:
    
    void freqOfAnElement(int arr[], int n){
        
       unordered_map<int, int> mp; // This line has created a map named mp & two int define the type of key and value respectively.

       for(int i=0;i<n;i++){
           mp[arr[i]]++;   //Will Increase the count of that particular key.
       }

       for(auto x:mp){ 
           cout<<x.first<<" "<<x.second<<endl;  //Here x.first is key and x.second denotes count of that key i.e value.
       };
     }
    //Above function will not maintain the order of the elements as in an array, it just returns randomly.

    //Below is the function which will print the result in the same order of key as it was in an array.

    void freqInSameOrder(int arr[],int n){
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        //Here will traverse the array once again to maintain the order.
        for(int i=0;i<n;i++){
            if(mp[arr[i]]!=-1){
                cout<<arr[i]<<" "<<mp[arr[i]]<<endl;
                mp[arr[i]]=-1; //This was introduced to avoid the printing of the count of same keys when will occur later.
            }
        }
    }

};

int main(){
    int n;
    //User Input Size of an Array and an Array
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution obj;
    obj.freqOfAnElement(arr,n); //functions were called.
    cout<<"Below Output is of frequency in Same Order"<<endl; // Just to create a differentiating line between two outputs.
    obj.freqInSameOrder(arr,n);

    return 0;
}
// Space Complexity - O(n) and Time Complexity - O(n);
