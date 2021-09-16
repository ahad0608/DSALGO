#include <bits/stdc++.h>
using namespace std;
//In this code will implement search, insert operations in double hashing.

#define TABLE_SIZE 13 //Table Size was defined.
#define PRIME 7 //Prime which is set to be used in second hash function is defined.

class DoubleHash{
    int *hashtable;
    int curr_size;

    public:
        bool isfull(){
            return(curr_size == TABLE_SIZE);  //if the hash size reaches maximum size then it returns true.
        }
        // HASH1 AND HASH2 function is defined.
        int hash1(int key){
            return key%TABLE_SIZE;
        }
        int hash2(int key){
            return PRIME-(key%PRIME);
        }
        DoubleHash(){
            hashtable = new int[TABLE_SIZE];
            int curr_size=0;
            for(int i=0;i<TABLE_SIZE;i++){ //Initialized the table with -1;
                hashtable[i]=-1;
            }
        }
        void insertHash(int key){
            //If the table is already full then we can't insert.
            if(isfull()){
                return;
            }
            int i1=hash1(key);
            int i2=hash2(key);
            // If i1 is not vacant.
            if(hashtable[i1]!=-1){
                int i=1;
                while(1){
                    //Here newIndex is nothing just the double hashing case.
                    int newindex = (i1 + i*i2)%TABLE_SIZE;
                    if(hashtable[newindex]==-1){
                        hashtable[newindex]=key;
                        break;
                    }
                    i++;

                }
            }
            else{
                hashtable[i1]=key;
                curr_size++;
            }

        }
        void search(int key){
            int i1=hash1(key);
            int i2=hash2(key);
            int i=0;
            // first we will check for i1 then consecutively to others.
            while(hashtable[(i1+i*i2)%TABLE_SIZE]!=key){
                if(hashtable[(i1+i*i2)%TABLE_SIZE]==-1){
                    cout<<"Key doesn't exist"<<endl;
                    return;
                }
                i++;
            }
            cout<<key<<" is found"<<endl;
        }

        void display(){
            for(int i=0;i<TABLE_SIZE;i++){
                if(hashtable[i]!=-1){
                    cout<<i<<"--"<<hashtable[i]<<endl;
                }
                else{
                    cout<<i<<"------"<<endl;
                }
            }
        }


};

int main(){
    // Input Array Size and Array
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    DoubleHash h; // Created the Doublehash h;
    for(int i=0;i<n;i++){
        h.insertHash(arr[i]);
    }
    h.search(12);
    h.display();
    return 0;
}

