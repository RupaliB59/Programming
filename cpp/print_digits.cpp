
/*
 * File:   print_digits.cpp
 * Author: rupali bhatnagar
 * Problem: You are given an integer N. Your task is to find number of digits of the smallest possible integer X 
 *          such that the product of it's digits (in decimal notation) is equal to N. Your program should return 
 *          the number of digits in X, or return -1 if such a number doesn't exist.
 *          
 *          Constraints: a. The input N can be ANY integer from 1 to 10^(18)
 *                       b. Your rogram must run very quickly (logN time)
 *                    
 *          TEST CASES: 1.  Input=1     Output=1    Reason:X=1
 *                      2.  Input=10    Output=2    Reason:X=25
 *                      3.  Input=26    Output=-1   Reason:No X exists
 *                      4.  Input=100   Output=3    Reason:X=455             
 */         


#include <cstdlib>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    char *pend;
    long long N=std::strtoll(argv[1],&pend,10);
    long long digitArray[30];
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
    
    for(int a=0;a<digits;++a){
        cout<<digitArray[a];
    }
    
    return 0;
}

