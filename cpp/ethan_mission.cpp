/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main2.cpp
 * Author: baba
 *
 * Problem: Ethan and Impossible Mission
 *          Ethan on his new mission has to crack a safe to get intel on 
 *          "cobalt". The lock is programmed such that it displays N numbers and
 *          generates Q queries when someone tries to open it. The safe opens 
 *          when each query is answered correctly.For each query the lock 
 *          displays an index I, the numbers at the Ith index disappears, the 
 *          answer to the query is the product of remaining numbers on the 
 *          screen modulo M. There is not much time left so Ethan needs your 
 *          help to crack the safe open.
 *          Note:
 *          - After each query, the number reappears at the Ith index.
 *          - Faster I/O expected.
 * 
 * Input:   First line of input contains three integers N, Q and M , the number 
 *          of elements, number of queries and the value of Modulo M.
 *          Next line contains N integers. Next Q lines contain an integer I, 
 *          denoting the index of the number that disappears after the query.
 * 
 * Output:  For each query print the required answer in a separate line.
 * 
 * Constraints: 1 <= N <= 10^6
 *              1 <= Q <= 10^6
 *              1 <= M <= 10^9
 *              1 <= Ai <= 10^9
 *              1 <= I <= N
 * 
 *Sample Input:
    5 3 100
    1 2 3 4 5
    1
    2
    4
 *Sample Output
    20
    60
    30
*/

#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    int N,Q,M;
    cin>>N>>Q>>M;
    
    int A[N];
    for(int i=0;i<N;++i){
        cin>>A[i];
    }
    
    
    return 0;
}

