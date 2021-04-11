# 🔎 Binary search

## <font color='08FAFA'>Introduction</font>

- Find a specific page in a book
- Guessing game

``` txt
    0 1 2 3 4  5  6  => indexes
    2 3 5 7 11 13 17 => array
```

- Complexity **O(?)**

- **Monotonic behavior**

![image](https://user-images.githubusercontent.com/40351413/113416819-5beb0700-93c2-11eb-91af-1181472a1deb.png)
![image](https://user-images.githubusercontent.com/40351413/113416752-3f4ecf00-93c2-11eb-81b7-f2e244a28698.png)
![image](https://user-images.githubusercontent.com/40351413/113416770-4675dd00-93c2-11eb-99bd-2112e9e0701c.png)

## <font color='08FAFA'>Two types of problems</font>

### 1. Searching for a specific item

#### Example

- Guessing game

#### Implementation

```cpp
    int n = 7, target = 11;
    vector<int> arr = {2, 3, 5, 7, 11, 13, 17};

    int index = -1;
    int left = 0, right = n - 1;

    while (left <= right) {
        // int mid = (left + right) / 2;
        int mid = left + (right - left) / 2; // Prevent overflow

        if (arr[mid] < target)
            left = mid + 1;
        else if (arr[mid] > target)
            right = mid - 1;
        else if (arr[mid] == target) {
            index = mid;
            break;
        }
    }

    cout << "Index: " << index << " - Element: " << arr[index] << endl;
 
```

```cpp
/**
  Output:
  Index: 4 - Element: 11
 */ 

```

### 2. Minimization and maximization problems

#### Example

- Get the minimum number that is greater than 8
  
``` txt
    2 3 5 7 11 13 17 => array
    0 0 0 0 1  1  1  => valid
```

#### Implementation

```cpp
    int n = 7, target = 8;
    vector<int> arr = {2, 3, 5, 7, 11, 13, 17};

    int index = -1;
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] <= target)
            left = mid + 1;
        else if (arr[mid] > target) // upper-bound
            right = mid - 1, index = mid;
//        else if (arr[mid] >= target) // lower-bound
//            right = mid - 1, index = mid;
    }

    cout << "Index: " << index << " - Element: " << arr[index] << endl;

```

```cpp
/**
   Output:
   Index: 4 - Element: 11
 */ 

```

## <font color='08FAFA'>Built-in functions (STL)</font>

> CPP provides a built in function in STL (Standard template library)

### binary_search
  
- Return whether a vector has element x or not
- Your array should be **sorted**

```cpp
    int x;
    cin >> x;

    if (binary_search(b.begin(), b.end(), x)) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

```

### lower_bound
  
- returns an iterator pointing to the first element greater than or equal **‘x’**
- Your array should be **sorted**

```cpp
    int x;
    cin >> x;
    auto it = lower_bound(b.begin(), b.end(), x);
    auto index = it - b.begin();

    if (it != b.end()) {
        cout << *it << endl;
    } else {
        cout << "Not found\n";
    }

```

### upper_bound
  
- Returns an iterator pointing to the first element greater than **‘x’**
- Your array should be **sorted**

```cpp
    int x;
    cin >> x;

    auto it = upper_bound(b.begin(), b.end(), x);
    if (it != b.end()) {
        cout << *it << endl;
    } else {
        cout << "Not found\n";
    }

```

## <font color='08FAFA'>Problems</font>

- Magic powder - 1 (brute force) - [Solution](https://github.com/ACM-FE-CU-Community/Sessions-Codes/blob/main/Binary%20search/Problems/magic-powder%201%20-%20BF.cpp)
- [Magic powder - 1](https://codeforces.com/contest/670/problem/D1) (binary search) - [Solution](https://github.com/ACM-FE-CU-Community/Sessions-Codes/blob/main/Binary%20search/Problems/magic-powder%201%20-%20BS.cpp)
- [Magic powder - 2](https://codeforces.com/contest/670/problem/D2) (binary search) - [Solution](https://github.com/ACM-FE-CU-Community/Sessions-Codes/blob/main/Binary%20search/Problems/magic-powder%202.cpp)
