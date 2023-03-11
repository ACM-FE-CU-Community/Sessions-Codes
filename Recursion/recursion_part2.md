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

## Exmaple 1: print numbers up to n bits in binary
    
```c++
int n=3
```

```c++
void printBinary(int bit,string num){
    if(bit == n){
        cout << num << endl;
        return;
    }
    printBinary(bit+1,num+"0");
    printBinary(bit+1,num+"1");
}
```
```c++
printBinary(0,"");
```
## Trace the recursive solution
```c++
      ""
    /    \
    "0"    "1"
    /  \    /  \
"00" "01" "10" "11"

```

## Use only one string
```c++
string num="";
void printBinary(int bit){
    if(bit == n){
        cout << num << endl;
        return;
    }
    num+="0";
    printBinary(bit+1);
    num.pop_back();

    num+="1";
    printBinary(bit+1);
    num.pop_back();
}
```
## The second solution is more efficient in terms of memory usage


--------------------
--------------------


## Example 2: Knapsack
```c++
There are N items, each has a weight w and a value v
You have a knapsack with capacity W
What is the maximum value you can put in the knapsack?
for example:
N = 3
W = 4
w = {2, 1, 3}
v = {4, 2, 3}
the Answer is 6 -> take first and second items
```
## N is small N<=20!
.
## brute force?
.
## try all subsets!
.

```
100 ->take first item
010 ->take second item
110 ->take first and second items
001 ->take third item
101 ->take first and third items
and so on
```
## How many subsets?
```c++
2^N
```
## we can use First code 
```c++
int n = 3, W = 4;
int w[] = {2, 1, 3};
int v[] = {4, 2, 3};
int mx=0

void genAllSubsets(int bit,string num){
    if(bit == n){
        int sumW=0,sumV=0;
        for(int i=0;i<n;i++){
            if(num[i]=='1'){
                sumW+=w[i];
                sumV+=v[i];
            }
        }
        if(sumW<=W)
            mx=max(mx,sumV);
        return;
    }
    genAllSubsets(bit+1,num+"0");
    genAllSubsets(bit+1,num+"1");
}
```
## Another solution
```c++
int n = 3, W = 4;
int w[] = {2, 1, 3};
int v[] = {4, 2, 3};

int slv(int i, int remWight) {
    if (i == n) 
        return 0;
    // leave the item
    int leave = slv(i+1, remWight);
    // take the item
    int take = 0;
    if (remWight >= w[i])
       take = v[i] + slv(i+1, remWight - w[i]);
    return max(leave, take);
}
```
--------------------
--------------------

## Example 3:
```c++
starting from the top left corner, return the path with the max sum reaching the bottom right corner & you can go right and down
        5 1 2
        6 7 8
        1 8 9
the answer is 5+6+7+8+9 = 35
```
* base condition?
* next calls? 
* calcaulate results?


```c++
const int n = 3, m = 3;
int grid[n][m];
int maxPathSum(int r, int c)
{
    // ^ Base condition
	if (r == n-1 && c == m-1)
		return grid[r][c];

    // ^ Next calls
	int path1 = maxPathSum(r, c+1);	// right
	int path2 = maxPathSum(r+1, c);	// down

    // ^ Calculate results
	return grid[r][c] + max(path1, path2);
}
```

## ! we have bug here

## .
## .
## .



## Correct implementation

```c++
bool valid(int r, int c) {
    return r < n && r >= 0 && c < m && c >= 0;
}
```
```c++
int maxPathSum(int r, int c)
{
    // ^ inside or outside the grid
	if (!valid(r, c))
		return 0;

	if (r == n-1 && c == m-1)
		return grid[r][c];	// base

	int path1 = maxPathSum(r, c+1);	// right
	int path2 = maxPathSum(r+1, c);	// down

	return grid[r][c] + max(path1, path2);
}
```

## problem 1
https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/W
## sol
https://www.ideone.com/QTbE43

----------------

## problem 2
https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/V
## sol
sol 1: https://www.ideone.com/QTbE43

sol 2: https://www.ideone.com/aG2jrA

----------------

## problem 3
https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/Y
## sol
https://www.ideone.com/HP92qB

----------------
----------------
----------------
----------------

# Contest
https://codeforces.com/group/gA8A93jony/contests
