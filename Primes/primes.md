# Primes section

## Content

1. [Primes definition and test](#1)
2. [Counting primes in range](#2)
3. [Prime divisors](#3)
4. [Problems](#4)

## Primes definition and test<div id="1"></div>

### Definition

- N is a primes IFF it divides only by 1 and N

### Primality test

```cpp
// slow version
bool isPrime(int n) // O(n)
{
    if (n < 2) return false;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}
```

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
bool isPrime_sqrt(int n) // O(sqrt(n))
{
    if (n < 2) return false;

    // i <= sqrt(n) -> it's a bad practice cuz of double
    // so to get rid of it -> power 2 sides
    // i <= sqrt(n) -> i *i <= n
    for (int i = 2; i* i <= n; i++)
    {
        if (n % i == 0)
        return false;
    }
    return true;
}
```

### Small optimization

- **Any even number isn't a prime except *2***

```cpp
bool isPrime_sqrt2(int n) // O(sqrt(n))
{
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        return false;
    }
    return true;
}
```

## Counting primes in a range<div id='2'></div>

```cpp
// brute force
int Count_Primes(int n) // O(n * sqrt(n) )
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (isPrime_sqrt2(i))
            cnt++;

    return cnt;
}
```

### Backward thinking 🔙

```cpp
2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ....

Let 2 removes 4, 6, 8, 10 ... n
Let 3 removes 6, 9, 12, 15 ... n
4 is removed
Let 5 remove 10, 15, 20 ... n
6 is removed
Could 7 be removed? NEVER, no one before it could divides it!
Let 7 removes 14, 21 ... n

```

```cpp  
int CountPrimesSeive(int n) // O(n log(log(n)))
{
    vector<bool> primes(n + 1, 1);

    int cnt = 0;

    primes[0] = primes[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            cnt++;
            for (int j = i + i; j <= n; j += i)
                primes[j] = 0;
        }
    }

    return cnt;
}
```

## Prime divisors <div id='3'></div>

### Fact

- Any number can be represented by products of some primes

### Ways

1. Use sieve to gen. primes then count how many of them divides n
2. Loop to **sqrt(n)** and get rid of primes as much as U can **(more efficient)**

```cpp
200 / 2 = 100
100 / 2 = 50
50  / 2 = 25

25 % 8 != 0 but 200 % 8 == 0
```

```cpp
vector<int> Prime_Divisors(int n) // sqrt(n) or less
{
    vector<int> divisors;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            divisors.push_back(i);
        }
    }
    // let n = 12
    // n / 2 = 6
    // 6 / 2 = 3 ==> get out from the loop with n = 3

    // if n != 1 -> it must be a prime
    // think in n as a sub-problem, we will begin from 2 and try to divide it
    // but we already get rid of all 2's and 3's ... so it must be a prime
    if (n != 1) divisors.push_back(n);

    return divisors;
}
```

- - -

## Problems <div id='4'></div>

1. [Almost Prime](https://codeforces.com/contest/26/problem/A)
   - Count numbers that has exactly two distinct prime divisors from 1 to n

```cpp
int Almost_Prime() // Forward Thinking
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int Pdivs = 0, tempi = i;

        for (int j = 2; j * j <= tempi; j++)
        {
            if (tempi % j == 0) Pdivs++;

            while (tempi % j == 0)
            {
                tempi /= j;
            }
        }
        if (tempi != 1) Pdivs++;

        ans += (Pdivs == 2);
    }
    return ans;
}
```

- If n was big (1 <= n <= 1000000)
- We can use sieve with small modification but HOW ?

```cpp
int AlmostPrime_Seive(int n) // Backward Thinking
{
    vector<bool> primes(n + 1, 1);
    vector<int> no_primes(n + 1);

    primes[0] = primes[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            for (int j = i + i; j <= n; j += i)
                primes[j] = 0,
                no_primes[j]++;
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
        if (no_primes[i] == 2)
            ans++;

    return ans;
}
```

2. [Duff in Love](https://codeforces.com/problemset/problem/588/B)

   - Find max divisor of ***n*** that hasn't (perfect square number - 1, 4, 9, 16, 25) divisor

```cpp
bool isPerfectSquare(long double x)
{
    long double sr = sqrt(x);
    return ((sr - floor(sr)) == 0);
}

void Duff_In_Love_1()
{
    vector<ll> Divs;
    void GetDivisors(ll n)
    {
        ll i;
        for (i = 1; i*i <= n; i++)
        {
            if (n%i == 0)
            {
                Divs.push_back(i);
                Divs.push_back(n / i);
            }
        }

        if (i*i == n)
            Divs.push_back(i);
        sort(Divs.rbegin(), Divs.rend());
    }
    bool Ok(ll n)
    {
        ll i;
        if (isPerfectSquare(n)) return 0;
        for (i = 1; i*i <= n; i++)
        {
            if (n%i == 0) // if (i) is a divisor
            if (((i != 1) && isPerfectSquare(i)) || ((i != 1) && isPerfectSquare(n / i)))
            return 0;
        }
        return 1;
    }
}
```

```cpp
void Duff_In_Love_2()
{
    ll n; cin >> n;
    ll ans = 1;
    set<ll> d;

    while (n % 2 == 0) n /= 2, d.insert(2);

    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0) d.insert(i);
        while (n % i == 0) n /= i;
    }

    if (n > 1)  // means the remainder of n is prime
        d.insert(n);
    for (auto i : d)
        ans *= i;

    cout << ans << '\n';
}
```
