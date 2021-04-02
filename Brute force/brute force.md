# 🔨 Brute force
> What we have seen is a technique called brute force, in which we try all the combinations

## General Checks:
  - Check the constraints of the problem that trying all the combination will not get you TLE
  - Check corner cases of the problem (n = 0, n = 1, n = MAXN)

# PowerSet (All subsets of S)
> PowerSet of set `S` is the set of all subsets of `S`.

> If set `S` has n element, So P(S) = 2 ^ n

```cpp
for example:
S = {a, b, c}

P(S) = {{}, {a}, {b}, {c}, {a,b}, {a, c}, {b, c}, {a, b, c}}.
```

## Bad implementation

```cpp
/**
 * ! 1. Not extendable
 * * 2. More handling
*/

set<string> st;
vector<char> s = {'a', 'b', 'c'};
// vector<char> s = {'a', 'b', 'c', 'd'};


for (int i = 0; i <= 1 ; i++) { // a
  for (int j =0; j <= 1 ; j++) { // b
    for (int k =0; k <= 1 ; k++) { // c
      string t;
      if (i) t += s[0];
      if (j) t += s[1];
      if (k) t += s[2];

      st.insert(t);
    }
  }
}
```

## Better implementation


```
0 => 000
1 => 001
2 => 010
3 => 011
4 => 100
5 => 101
6 => 110
7 => 111

```
### Check if bit is setted or not

```
1 << i = pow(2, i)

if number of elements  = 3

(i = 0) => So => 001
(i = 1) => So => 010
(i = 2) => So => 100
```

```cpp
ll n = 3;
string s = "abc";

for (ll mask = 0; mask < (1 << n); mask++) {
  string t;
  for (ll i = 0; i < n; i++) {
    if ((1 << i) & mask) {
      t += s[i];
    }
  }

  st.insert(t);
}
```

### Let's see a real problem on power-set
> Check heavy coins https://codeforces.com/gym/100712/




### All arrangements

S = {a, b, c}

S1 = {a, b, c}
S2 = {a, c, b}
S3 = {b, c, a}
S4 = {b, a, c}
S5 = {c, a, b}
S6 = {c, b, a}


```cpp
  for(int i = 0; i < n ; i++) {
    for(int j = 0; j < n ; j++)  {
      for(int k = 0; k < n ; k++) {
        if (i != j && i != k) {

        }
      }
    }
  }
```


```cpp
 /**
  * * A permutation is each one of the N! possible arrangements O(N!)
  * 
  * * 1! = 1
  * * 2! = 2
  * * 3! = 6
  * * 4! = 24
  * * 5! = 120
  * * 6! = 720
  * * 7! = 5040
  * * 8! = 40320
  * * 9! = 362880
  * * 10! = 3628800
  * ! 11! = 39916800
 */
```
```cpp
/**
* ~ CPP provides a built in function in STL (Standard template library)
* ^ next_permutation(array_boundaries)
*
*  * next_permutation(arr, arr + size) => array
*  * next_permutation(vec.begin(), vec.end()) => vector
*/


vector<char> s = {'a', 'b', 'c'};

do {
  cout << s[0] << " " << s[1] << " " << s[2] << endl;
} while (next_permutation(s.begin(), s.end()));


/**
  * ! Output
  * 
  * a b c
  * a c b
  * b a c
  * b c a
  * c a b
  * c b a
 */ 

```


