# Factorization section

## Content

- [Factorization section](#factorization-section)
  - [Content](#content)
  - [Brute force approach](#brute-force-approach)
  - [Optimized version](#optimized-version)
  - [Count divisors](#count-divisors)
    - [Count divisors for one number](#count-divisors-for-one-number)
    - [Count divisors for all numbers from 1 to n](#count-divisors-for-all-numbers-from-1-to-n)
      - [Backward thinking](#backward-thinking)
  - [Problems](#problems)
    - [Multiplication Table](#multiplication-table)
      - [Brute force solution](#brute-force-solution)
      - [Optimized solution](#optimized-solution)
    - [Bear and Poker](#bear-and-poker)

## Brute force approach

```cpp
vector<int> generateDivisorsBruteForce(int n) // O(n)
{ 
    vector<int> divisors;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            divisors.push_back(i);
    return divisors;
}
```

## Optimized version

- **<font color="ff8882">Do we need to loop until n</font>**

```cpp
    16 = 1 * 16
    16 = 2 * 8
    16 = 4 * 4 => mirror
    16 = 8 * 2
    16 = 16 * 1
```

```txt
    IF n = x * y && x <= y

    THEN x <= sqrt(n) and y >= sqrt(n)
```

```cpp
vector<int> generateDivisorsSqrt(int n) // O(sqrt(n))
{ 
    vector<int> divisors;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0) {
            divisors.push_back(i);
            divisors.push_back(n / i);
            
            if (i * i == n)
                divisors.pop_back();
        }
    }

    sort(divisors.begin(), divisors.end()); // O(nLog(n))
    return divisors;
}
```

## Count divisors

### Count divisors for one number

```cpp
int countDivisors(int n) // O(sqrt(n))
{ 
    int cnt = 0, i;
    for (i = 1; i * i <= n; i++)
        if (n % i == 0)
            cnt += 2;
    
    // 25 => 5 * 5, 36 = 6 * 6, ...etc
    if (isPerfectSquare(n)) cnt--;
    return cnt;
}
```

### Count divisors for all numbers from 1 to n

```cpp
void divCountAllBruteForce(int n) // O(n * Sqrt(n))
{
    vector<int> divisors(n + 1);
    for (int i = 1; i <= n; i++)
    {
        divisors[i] = countDivisors(i); // O(sqrt(n))
    }
}
```

#### Backward thinking
```cpp
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ....

1 divides 1, 2, 3, 4, 5 ... n
2 divides 2, 4, 6, 8, 10 ... n
3 divides 3, 6, 9, 12, 15 ... n
4 divides 4, 8, 12, 16, 20 ... n
5 divides 5, 10, 15, 20, 25 ... n

Complexity = n/1 + n/2 + n/3 + .... n/n
=> Harmonic series => n log(n)

```

```cpp
void divCountAllOptimized(int n)
{
    vector<int> divisors(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
            divisors[j]++;
    }
}
```

- - -

## Problems

### Multiplication Table

Link: <https://codeforces.com/problemset/problem/577/A>

#### Brute force solution

```cpp
void MultiplicationTableBruteForce()
{
    ll n, x;
    cin >> n >> x;
    int cnt = 0;
    for (int i = 1; i <= n; i++)      // iterate over all the rows
        if (x % i == 0 && x / i <= n) // check if this row is multiple of x, check the other multiple exists
            cnt++;
}
```

- If n was big (1 <= n <= 1e9)
- We can use sieve with small modification but HOW ?

#### Optimized solution

```cpp
void MultiplicationTableOptimized()
{
    ll n, x;
    cin >> n >> x;
    vector<int> divisors = generateDivisorsSqrt(x);
    int cnt = 0;

    for(auto divisor : divisors) {
        if (divisor <= n && (x / divisor) <= n)
            cnt++;
    }

    cout << cnt << endl;
}
```

### Bear and Poker

Link: <https://codeforces.com/contest/573/problem/A>

```cpp
void bearAndPoker() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        while (arr[i] % 2 == 0) arr[i] /= 2;
        while (arr[i] % 3 == 0) arr[i] /= 3;
        
        if (arr[i] != arr[0]) 
        {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";
}
```
