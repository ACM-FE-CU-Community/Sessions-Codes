# Recursion
## Definition
- a function is said to be recursive if it calls itself.

----------------

## Let us revise some functions basics 

```c++
int print(int b) {
    cout << b << endl;
}

int decrease(int a) {
    // ? what is the difference between the next 2 lines ?
    print(a - 1); // print(4)
    print(--a); // print(4)

    // Any extra code here
}

// function call 
decrease(5);
```
----------------

## Factorial

```c++
factorial(5) = 1 * 2 * 3 * 4 * 5
factorial(4) = 1 * 2 * 3 * 4
factorial(3) = 1 * 2 * 3
factorial(2) = 1 * 2
factorial(1) = 1
```
## relation between factorial(5) and factorial(4) ?
```c++
if we know answer for factorial(4) we can calculate factorial(5) by multiplying it by 5

factorial(5) = factorial(4) * 5
``` 

## iterative solution
```c++
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
```

## let the problem is to calculate factorial(5)

```c++
int f1(){
    return 1;
}
// f1 = 1

int f2(){
    return 2*f1();
}
// f2 = 2 * f1
//    = 2 * 1 = 2  

int f3(){
    return 3*f2();
}
// f3 = 3 * f2
//    = 3 * 2 = 6

int f4(){
    return 4*f3();
}
// f4 = 4 * f3
//    = 4 * 6 = 24

int f5(){
    return 5*f4();
}
// f5 = 5 * f4
//    = 5 * 24 = 120
```

## recursive solution
```c++
int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
```
## trace the recursive solution
```c++
factorial(5) = 5 * factorial(4)
factorial(4) = 4 * factorial(3)
factorial(3) = 3 * factorial(2)
factorial(2) = 2 * factorial(1)
factorial(1) = 1
```

## what is the base case ?
## function parameter (n) are called state the current state of our variables in the recursion calls

----------------

## example 2 print array

```c++
int arr[] = {1, 2, 3, 4};
int n=4;
```

## iterative solution
```c++
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
```

## recursive solution
```c++
void printArray(int i) {
    if (i == n) {
        return;
    }
    cout << arr[i] << " ";
    printArray(i + 1);
}
```
## trace the recursive solution
```c++
printArray(0) -> cout << arr[0] << " ";
                 printArray(1);

printArray(1) -> cout << arr[1] << " ";
                 printArray(2);
...
printArray(3) -> cout << arr[3] << " ";
                 printArray(4);

printArray(4) -> return;

output: 1 2 3 4
```    

## what this code output ?
```c++
void printArray(int i) {
    if (i == n) {
        return;
    }
    printArray(i + 1);
    cout << arr[i] << " ";
    //return;
}
```
## trace
```c++
printArray(0) -> printArray(1);
printArray(1) -> printArray(2);
printArray(2) -> printArray(3);
printArray(3) -> printArray(4);

printArray(4) -> return;

// i = 3
cout << arr[3] << " ";
return;

// i = 2
cout << arr[2] << " ";
return;

// i = 1
cout << arr[1] << " ";
return;

// i = 0
cout << arr[0] << " ";
return;
```

## problem 1
https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/K
## sol : https://www.ideone.com/XDr2Eh

----------------

## problem 2
https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/Q
## sol : https://www.ideone.com/mAP8gE

----------------

## problem 3
https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/R
## sol : https://www.ideone.com/ALaabZ

----------------
----------------
----------------
----------------

# Contest
## Rigster here https://codeforces.com/group/MWSDmqGsZm/contests
## Contest link https://codeforces.com/group/MWSDmqGsZm/contest/223339