
/*
 * File:   question2.cpp
 * Author: rupali bhatnagar
 *
 * Created on 14 January, 2017, 10:40 AM
 */


#include <cstdlib>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    long long N ;
    cin>>N;
    long long digitArray[500];
    int digits=0, start=9;
    bool done =false;
    
    if(N==1){
        digitArray[digits]=1;
        digits++;
        done=true;
    }
    
    if(!done){
        while(start>1){
            while(N%start==0){
                digitArray[digits]=start;
                digits++;
                N=N/start;
            }
            start--;
        }
        if(N>9){
            digits=-1;
        }
        done=true;
    }
    cout<<digits<<"\n";
    
//    for(int a=0;a<digits;++a){
//        cout<<digitArray[a];
//    }
    
    return 0;
}

