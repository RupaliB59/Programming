
/* 
 * File:   fraction_series.cpp
 * Author: rupali bhatnagar
 *
 * Problem: Consider the following sequence of order x that consists of fully 
 *          reduced fractions having values between 0 and 1 (both inclusive).
 *          The denominators of these fractions are all less than or equal to x
 *          and fractions are also arranged in an ascending order. For example:
 *          
 *          F1 = 0/1 1/1
 *          F2 = 0/1 1/2 1/1
 *          F3 = 0/1 1/3 1/2 2/3 1/1
 *          F4 = 0/1 1/4 1/3 1/2 2/3 3/4 1/1
 *          F5 = 0/1 1/5 1/4 1/3 2/5 1/2 3/5 2/3 3/4 4/5 1/1
 *
 *          Note that this sequence will always start with 0/1. Write a program
 *          for a given x, it prints to screen the xth order in the sequence.
 *      
 */

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;



class Fraction{
public:
  int numerator;
  int denominator; 
  
  Fraction(int num,int den){
  numerator=num;
  denominator=den;
  }
  Fraction(){
  numerator=0;
  denominator=0;
  }
  
  
  void display(){
      cout<<numerator<<"/"<<denominator<<" ";
  }
  
   void reduce(){
     
    if(numerator==0 || numerator==1){
        return;
      }
      
      for(int i=2;i<=numerator;++i){
        if((numerator%i==0) && (denominator%i==0)){
            while((numerator%i==0) && (denominator%i==0)){
                numerator=numerator/i;
                denominator=denominator/i;
            }
        }
     }
        return;
    
    }
   
   
   float getValue(){
       return (float)numerator/denominator;
       }

};

bool contains(Fraction *series, Fraction f, int maxFracs);
bool isLessThan(Fraction f1,Fraction f2);


int main(int argc, char** argv) {
    char *pend;
    long n= std::strtol(argv[1],&pend,10);
    
    int maxFracs=2;
    for(int i=1;i<n;++i){
        maxFracs+=i;
    }
    
    const int size=5000;
    
    Fraction series[size];
    int pos=0;
    
    series[0]=Fraction(0,1);
    pos=1;
    
    for(int den=2;den<=n;++den){
        for(int num=1;num<den;++num){
            Fraction newFraction(num,den);
            newFraction.reduce();
            if(!contains(series,newFraction,maxFracs)){
                series[pos]=newFraction;
                pos++;
            }
        }
    }
    
    
    
    for(int i=1;i<pos;++i){
        for(int j=i+1;j<pos;++j){
            if(isLessThan(series[j],series[i])){
                Fraction temp=series[i];
                series[i]=series[j];
                series[j]=temp;
            }
        }
    }
    
    series[pos]=Fraction(1,1);
    for(int i=0;i<=pos;++i){
        series[i].display();
    }
    
    return 0;
}

bool contains(Fraction *series, Fraction f, int maxFracs){
    for(int i=1;i<maxFracs;++i){
        if(series[i].numerator==f.numerator && series[i].denominator==f.denominator){
            return true;
        }
    }
    return false;
}

bool isLessThan(Fraction f1,Fraction f2){
    if(f1.getValue()<=f2.getValue()){
        return true;
    }
        return false;
    
}
