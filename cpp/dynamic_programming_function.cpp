/*
*	Title:		Dynamic Programming for fibonacci like function
* 	Author:		rupali bhatnagar
*	Problem:	Daulat Ram's income
*				Daulat Ram is an affluent business man. After demonetization, IT raid
*				was held at his accommodation in which all his money was seized. He is 
*				very eager to gain his money back, he started investing in certain 
*				ventures and earned out of them. On the first day, his income was Rs. X,
*				followed by Rs. Y on the second day. Daulat Ram observed his growth as 
*				a function and wanted to calculate his income on the Nth day.
*				The function he found out was FN = FN-1 + FN-2 + FN-1×FN-2
*
*				Given his income on day 0 and day 1, calculate his income on the Nth day.
*
*	Input:		The first line of input consists of a single integer T denoting number 
*				of test cases.Each of the next T lines consists of three integers F0, F1
*				and N respectively.
*
*	Output:		For each test case, print a single integer FN, as the output can be large,
*				calculate the answer modulo 109+7.
*
*	Constraints:
	1 <= T <= 10^5
	0 <= F0, F1, N <= 10^9
*
*	Sample Input:
	2
	0 1 2
	1 2 4
	
	Sample Output:
	1
	107
*/

#include <iostream>
using namespace std;
 
long long func(long long* array, long N);
long const M =1000000007;
 
int main() {
	int T;
	cin>>T;
	for(int i=0;i<T;++i){
		long F0,F1,N;
		cin>>F0>>F1>>N;
		long long array[N+1];
		
		for(long j=0;j<N+1;++j){
			array[j]=-1;
		}
		array[0]=F0;
		array[1]=F1;
		cout<<(func(array,N)%M);
		for(long j=0;j<N+1;++j){
			cout<<array[j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
 
long long func(long long * array, long N){
	if(N==0 || N==1){
		return array[N];
	}else{
		if(array[N]<0){
			long val1=func(array,N-1)%M;
			
			long val2=func(array,N-2)%M;
		
			array[N]=val1+val2+(val1*val2)%M;
			
		}
		return array[N];
	}
}
 
