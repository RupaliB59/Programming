
/* 
 * File:   yogi_steps.cpp
 * Author: rupali bhatnagar
 *
 * Problem: Yogi and his friends
 *          Find the minimum number of non-adjacent swaps to make an array 
 *          either completely ascending or descending.
 */

#include <iostream>
#include<algorithm>
using namespace std;

int asc_steps(int*, int*,int);
int desc_steps(int*, int*,int);

int main(int argc, char** argv)
{
    int N;
    cin>>N;
    int array[N];
    int ascCopy[N],descCopy[N];
    
    for(int i=0;i<N;++i){
        cin>>array[i];
    }
   std::copy(array,array+N,ascCopy);
   std::copy(array,array+N,descCopy);
   
   std::sort(ascCopy,ascCopy+N);
   std::sort(descCopy,descCopy+N,std::greater<int>());
    
    int asc=asc_steps(ascCopy,array,N);
    int desc=desc_steps(descCopy,array,N);
    if(asc<desc){
        cout<<asc;
    }else{
        cout<<desc;
    }
}

int asc_steps(int* asc, int* array,int n){
    cout<<"\nAscending\n";
    
    int steps=0,pos=0;
    for(int i=0;i<n;++i){
        if(asc[i]!=array[i]){
            pos=i+1;
            while(array[pos]!=asc[i]){
                pos++;
            }

            int temp=array[pos];
            array[pos]=array[i];
            array[i]=temp;
            steps++;
            
            for(int a=0;a<n;++a){
                cout<<array[a]<<" ";
            }
            cout<<"\n";
        }
        
    }
    return steps;
}

int desc_steps(int* desc, int* array,int n){
    cout<<" \nDescending\n";
    
    int steps=0, pos=0;
    for(int i=0;i<n;++i){
        if(desc[i]!=array[i]){
            pos=i+1;
            while(array[pos]!=desc[i]){
                pos++;
            }

            int temp=array[pos];
            array[pos]=array[i];
            array[i]=temp;
            steps++;
            
            for(int a=0;a<n;++a){
                cout<<array[a]<<" ";
            }
            cout<<"\n";
        
        }
          
    }
    return steps;
}