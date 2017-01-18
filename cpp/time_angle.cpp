/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main3.cpp
 * Author: baba
 *
 * Problem: Time Angle
 *          Little Ravi in his shopping bought a 24hr clock. As we know, our 
 *          Little Ravi keeps thinking of a new problem and solves them in his 
 *          free time. This time, the clock has been the subject of his problem.
 *          Little Ravi notes down the reading of the clock, each time he has 
 *          seen time on the clock over a period of time. In his free time, he 
 *          calculates the least angle by which hours, minutes and seconds hands
 *          rotated to get the current time from it's preceding time.The clock 
 *          hours hand completes a circle once every 24 hours, minutes hand 
 *          completes once every hour and seconds hand completes once every minute.
 * 
 * Input Format:    First line has and integer N. N lines follows each having a 
 *                  time in 24hr format as "HH:MM:SS".
 * 
 * Output Format:   Print N-1 lines with three real numbers in each line, each 
 *                  number with exactly 6 decimal digits. Every line I has 3 
 *                  numbers in order, angle rotated by hours hand, minutes hand 
 *                  and seconds hand from time I-1 to time I.
 * Constraints:
    1 <= N ≤ 500000
    00 ≤ HH < 24
    00 ≤ MM < 60
    00 ≤ SS < 60
 * 
 * Sample Input
    4
    21:15:00
    21:15:30
    10:10:00
    10:10:10
 * 
 * Sample Output
    0.125000 3.000000 180.000000
    193.625000 4647.000000 278820.000000
    0.041667 1.000000 60.000000

 * Time Limit: 1.0 sec(s) for each input file
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    return 0;
}

