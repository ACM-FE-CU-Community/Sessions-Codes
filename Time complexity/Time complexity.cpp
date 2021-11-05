#include <bits/stdc++.h>
using namespace std;

/**
 *
 * * Problem
 * [1] Our main problem is to measure the algorithm performance => Space + Time.
 * [2] We need to compare these algorithms to get the best algorithm.
 *
 */

/** 
 * * Solution
 * [1] Complexity analysis using Exact time.
 *   • It depends on the machine performance.
 *   • IPC (Instructions per cycle) is machine dependent.
 *   • CPU frequency varies even with same IPC.
 * 
 * 
 * [2] Complexity analysis using no. of steps and no. of operations.
 *   • It is not practical in calculations.
 * 
 * 
 * [3] Complexity analysis using Worst, Average, Best case.
 *   • We are interested in the worst case scenario
 *   • e.g. Search for a number in an array of size n.
 *   • 5 9 3 4 2 98 7 81 62 10
 * 
 * 
 *   • Best case => 5 | 9
 *   • Average case => 98 | 7 | 2
 *   • Worst case => 62 | 10
 **/


/**
 * * Note
 *   1s takes 10^8 operations
 **/


// * General Rule
// Worst Case = The highest degree if we have a polynomial equation.
// Time = 3 * N^2 + 5 * N + 10 -> O(N^2)


// Constant Order
// O(1)
int checkSign(int a)
{
    if (a > 0) {
        return 1;
    }
    if (a < 0) {
        return -1;
    }

    return 0;
}

// Logarithmic Order
/*
    Ex.:
        16 -> 8 -> 4 -> 2 -> 1      Okay
        20 -> 10 -> 5 (Ops..!)
    x <= 2^(20)
    O(log n)
*/
bool checkIfPowerOfTwo(int n)
{
    while (n > 1) {
        if (n % 2 != 0) {
            return 0;
        }

        n /= 2; // Here is the magic
    }
    return 1;
}

// Linear Order
// O(n)
bool checkIfNumberExists(int arr[], int N, int num)
{
    for (int i = 0; i < N; ++i) {
        if (arr[i] == num) {
            return 1;
        }
    }

    return 0;
}

// Quadratic order
/*
    For the equation: y = mx + c
    Check if (m,c) exist in the array for such (x,y)
*/
bool checkLineEquation(vector<int> arr, int x, int y)
{
    int N = arr.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i] * x + arr[j] == y) {
                return 1;
            }
        }
    }
    return 0;
}

// Cubic order
/*
    Check if there are three numbers which their sum is d (i.e. a + b + c = d)
*/
bool checkThreeNumbersEquation(vector<int> arr, int d)
{
    int N = arr.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                if (arr[i] + arr[j] + arr[k] == d) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Factorial Order
bool getNumberofPermutations(vector<int> arr, int lower, int upper)
{
    int counter = 0;
    do {
        counter++;
    } while (next_permutation(arr.begin(), arr.end()));

    return counter;
}

// Exponential Order
/*
    Generates all binary sequences of size N (Recursively)
    Ex.: N = 2           =>      {00,01,10,11}
*/
void generateBinary(string s, int N)
{
    if (s.size() == N) {
        cout << s << endl;
        return;
    }

    generateBinary(s + '0', N);
    generateBinary(s + '1', N);
}

// Examples
// Arithmetic Sequence
// 1 + 2 + 3 + ... + N = N*(N+1)/2 = N^2 / 2  + N / 2
// O(N^2)
void Ex1(int N)
{
    for (int i = 1; i <= N; ++i) {
        // N
        for (int j = 1; j <= i; ++j) {
            // Do something
        }
    }
}

// Geometic Sequence
/*
    1 + x + x^2 + x^3 + .... + x^(N-1)
    = (x^N - 1) / (x - 1)
    O(x^N)
*/
void Ex2(int N, int x)
{
    for (int i = 0; i < N; ++i) {
        int M = pow(x, i);
        for (int j = 1; j <= M; ++j) {
            // Do something
        }
    }
}

// Fractional Geometic Sequence
// O(N)
void Ex3(int N)
{
    // N = 16
    for (int i = 1; i <= N; i *= 2) {
        // i = 1, 2, 4, 8, ... 16
        for (int j = 1; j <= N; j += i) {
            // Do something
        }
        /*
            N + N/2 + N/4 + N/8 + N/16
            = N * (1/1 + 1/2 + 1/4 + 1/8 + 1/16)
            
            (1 + 1/2 + 1/4 + 1/8 + 1/16)(decimal) -> 1.11111111 (binary) <= 2 
            so Time = 2*N -> O(N)
        */
    }
}

// Harmonic Sequence
void Ex4(int N)
{
    for (int i = 1; i < N; ++i) {
        // i = 1, 2, 3, ..., N
        for (int j = 1; j <= N; j += i) {
            // Do something
        }
        /*
            N + N/2 + N/3 + ....
            N * (1/1 + 1/2 + 1/3 + ... ) = O(N log(N)) [Best estimate so far]
        */
    }
}

// O(N)
void Ex5(int N)
{
    int i = 0;
    while (i < N) {
        int j = i;
        while (j < N) {
            // Do something
            ++j;
            ++i;
        }
        ++i;
    }
}

// infinity!! -> i=0
void Ex6(int N)
{
    int i = 0;
    while (i < N) {
        // Do something
        i *= 2;
    }
}

RecEx7(x, N, 0);
// O(x^N)
void RecEx7(int x, int N, int i)
{
    if (i == N) {
        return;
    }
    // Do something

    for (int j = 0; j < x; ++j)
        RecEx7(x, N, i + 1);
}

// O(N^2)
void Ex(vector<int> s, int N)
{
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // Do something
        }
    }
}

// O((N^2) * (N^2)) -> O(N^4)
void Ex10(int N)
{
    vector<int> a;
    // Fill a
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // O(N^2)
            Ex(a, N);
            // A line of code doesn't mean O(1)
        }
    }
}

// Memory Analysis
// Check if any number is repeated:    arr[i] < N

// Memory O(1) & Time O(N^2)
bool Ex8(vector<int>& arr)
{
    int N = arr.size();
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (arr[i] == arr[j]) {
                return 1;
            }
        }
    }
    return 0;
}

// Another Solution: Shows Memory & Time compromising
// Memory O(N) & Time O(N)
bool Ex8(vector<int>& arr)
{
    int N = arr.size();

    vector<bool> exist(N, 0); // Allocate N location

    for (int i = 0; i < N; ++i) {
        if (exist[arr[i]] == 1) {
            return 1;
        }
        exist[arr[i]] = 1;
    }
    return 0;
}
