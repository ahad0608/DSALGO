// This code will helps us check wheather two input strings is Anagram or not.
// Anagrams - When two strings have same characters with same frequency but may be of different order(different permutations) then those two strings are called Anagram.
//Approach 1 - We can just compare two strings after sorting but the time complexity can be larger i.e O(nlogn)

#include <iostream>
using namespace std;
// It is eay to manage our code through classes.
class Solution{
    public:


    bool Anagram(string a,string b){
      int n = a.length();
      int m = b.length();
      if(n!=m){ // if the length of str a and str b are not equal then they are obviously not Anagram.
          return false;
      }
      // Created a count array to keep track of frequencies of characters.
      const int CHAR =256;
      int count[CHAR]={0};
      for(int i=0;i<n;i++){
          count[a[i]]++;
          count[b[i]]--; // Instead of creating two count arrays we have manipulated same count array.
      }
      for(int i=0;i<CHAR;i++){
          if(count[i]!=0){ // After above loop if the combined frequency does not become zero then we can say that there is mismatch. Thus, not an Anagram.
              return false;
          }
      }
      return true;

    }
};

int main(){
    string c;
    string d;
    cin>>c>>d;
    Solution obj; // class Solution is called.
    if(obj.Anagram(c,d)){
        cout<<"Yes given strings are Anagram"<<endl;
    }
    else{
        cout<<"No given strings are not an Anagram"<<endl;
    }


    return 0;
}

// Above solution does require auxiliary space and adds on time complexity but those are constant which can be helpful when dealing with large input data.
// Time Complexity - O(n);

