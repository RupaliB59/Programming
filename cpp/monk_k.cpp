
/* 
 * File:   monk_k.cpp
 * Author: baba
 *
 * Problem: Monk and K-Operations
 *          Given an array A having N integers, you have to perform exactly K 
 *          operations on it. In each operation you have to delete either the 
 *          first or the last element of the array. Monk defines power of an 
 *          array as the product of first and last element of the array. Help 
 *          Monk find out the maximum power he can achieve after performing 
 *          exactly K operations.
 * 
 * Input:   First line consists of a single integer T, denoting the number of 
 *          test cases.First line of each test case consists of two space 
 *          separated integers denoting N and K.Second line of each test case 
 *          consists of N space separated integers denoting the array A.
 * 
 * Output:  Print the required answer for each test case in a new line.
 * Sample Input
    2
    3 1
    4 2 1
    5 2
    3 5 1 5 1
 * Sample Output
    8
    25
 * Explanation: In first case, Monk can delete either 4 or 1. If he deletes 4, 
 *              resulting array will have power equal to 2. If he deletes 1, 
 *              power of resulting array will be 8. So maximum power he can 
 *              achieve is 8.
 */

#include <iostream>

using namespace std;

unsigned long long k_ops(unsigned long long* A, long beg, long end, long k);

int main(int argc, char** argv) {
    int T;
    cin>>T;
    for (int i = 0; i < T; ++i) {
        long N, K;
        cin >> N>>K;

        unsigned long long A[N];
        for (long j = 0; j < N; ++j) {
            cin >> A[j];
        }

        cout << k_ops(A, 0, N - 1, K) << "\n";
    }
    return 0;
}

unsigned long long k_ops(unsigned long long* A, long beg, long end, long k) {
    if (k < 1) {
        for (long i = beg; i <= end; ++i) {
            cout << A[i] << " ";
        }
        cout << "\n";
        return A[beg] * A[end];
    } else {
        if ((A[beg + 1] * A[end])>(A[beg] * A[end - 1])) {
            cout << "Beg+1 ";
            return k_ops(A, beg + 1, end, k - 1);
        } else {

            if ((A[beg + 1] * A[end]) == (A[beg] * A[end - 1])) {

                cout << "equal";
                unsigned long long val1 = k_ops(A, beg + 1, end, k - 1);
                unsigned long long val2 = k_ops(A, beg, end - 1, k - 1);
                if (val1 > val2) {
                    return val1;
                }
                return val2;
            } else {
                cout << "end-1";
                return k_ops(A, beg, end - 1, k - 1);
            }
        }
    }
}
