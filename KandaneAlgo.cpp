// This is the algorithm which helps us find largest sum of contiguous Subarrray.
#include <iostream>
#include <climits>
using namespace std;

int main() {
  //Input size of an Array and an Array
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
  //Traverse the array once and keep check on sum and max_sum;
  int sum=0;
  int max_sum=INT_MIN;
  for(int i=0;i<n;i++){
      sum+=arr[i];
      if(sum>max_sum){
          max_sum=sum;
      }
      if(sum<0){  // As the sum gets negative we understand that adding it to other will not lead us to largest, thus we will start afresh.
          sum=0;
      }
  }
  cout<<max_sum<<endl;
  return 0;
}