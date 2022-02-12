// ^ Recursion ^ \\

/*
    & for better comment highlighting
    & https://marketplace.visualstudio.com/items?itemName=ParthR2031.colorful-comments
*/




#include <bits/stdc++.h>

using namespace std;

// & Let us revise some functions basics 

int decrease(int a) {
    // ? what is the difference between the next 2 lines ?
    return a - 1;
    return --a;
}







// ^ Example 1


// ? what is the next 4 functions do?

int f1(int n)
{
	return n * 1;
}

int f2(int n)
{
    // ! calc: n * f1(n - 1) => n * (n - 1)
	return n * f1(n-1);
}

int f3(int n)
{
    // ! calc: n * f2(n-1) => n * (n - 1) * f1(n - 2) => n * (n - 1) * (n - 2)
	return n * f2(n-1);
}






// the above 3 functions are doing the same thing
// ? so, do we need to repeat the same code again in every function ?
// ^ no, let the function just call itself like the following




int f(int n) {
    return n * f(n - 1);
}



/*
    ^ the above function will behave like the following:
    ! calc: n * f(n - 1) 
    !                   => n * (n - 1) * f(n - 2)
    !                                             => n * (n - 1) * (n - 2) * f(n - 3) => ....forever
    ^ so, we need to stop it, hmmmmmm, let's try putting a condition at the start of it
*/



int f(int n) {
    if (n <= 1) 
        return 1;

    return n * f(n - 1);
}


/* 
    ^ with this modification, the function will call itself until reaching 1
    ^ after reaching 1, it will stop calling itself and return 1
    & and this condition is called "base condition": the condition that stops the recursion calls
    & and function parameters (n) are called "state": the current state of our variables in the recursion calls

    & consider each call as a new copy of the function
*/



// ^ Example 2


/*

*
**
***
****
*****

? how can we draw this shape? 
^ we can use some loops to draw it, but we want to use recursion 

*/

void draw_triangle(int depth = 5) {
    // ^ base condition
    if (depth <= 0) {
        return;
    }

    // ! draw_triangle(depth--);
    draw_triangle(depth - 1);

    for (int i = 0; i < depth; i++) {
        cout << "*";
    }
    cout << endl;
}






// * wrong implementation * \\

void draw_triangle(int depth = 5) {
    // ^ base condition
    if (depth == 0) {
        return;
    }

    while(depth--) {
        cout << "*";
    }
    cout << endl;

    draw_triangle(depth - 1);
}



// ^ Example 3



// ^ recursion with more than one call
/*
    & starting from the top left corner, return the path with the max sum reaching the bottom right corner\
    & you can go right and down
        512
        678
        189

    ? base condition?
    ? next calls? 
    ? calcaulate results?
*/









int n, m;
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

// ! we have bug here








// * correct implementation * \\

bool valid(int r, int c) {
    return r < n && r >= 0 && c < m && c >= 0;
}

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






// ^ Example 4: Flood Fill

/*

...x.
..x..
.x...
x....

*/

int floodFill(int r, int c) {
    if (!valid(r, c) || grid[r][c] == 'x')
        return;

    int ans = 0;
    ans += floodFill(r + 1, c); // down
    ans += floodFill(r - 1, c); // up
    ans += floodFill(r, c + 1); // right
    ans += floodFill(r, c - 1); // left

    return 1 + ans;
}

// ! we have bug here








// * correct implementation * \\

bool vis[n][m];

int floodFill(int r, int c) {
    if (!valid(r, c) || grid[r][c] == 'x' || vis[r][c])
        return;

    vis[r][c] = true;

    int ans = 0;
    ans += floodFill(r + 1, c); // down
    ans += floodFill(r - 1, c); // up
    ans += floodFill(r, c + 1); // right
    ans += floodFill(r, c - 1); // left

    return 1 + ans;
}