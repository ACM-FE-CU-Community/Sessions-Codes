#include <bits\stdc++.h>
// #include <cmath>

/**
 * for better comment highlighting
 * https://marketplace.visualstudio.com/items?itemName=ParthR2031.colorful-comments
*/

using namespace std;
using ll = long long int;
using ld = long double;

void builtin_functions() {
  /**
   * C++ offers for us some ready-made functions like:
   *
   * floor, ceil, round, fabs, abs, sqrt, log, log2,
   * log10, pow, cos, cosh, acosh
   * 
   * to use them you need to include <cmath> lib
   * 
   * ? https://www.cplusplus.com/reference/cmath/
   */

  /**
   * 
   * * Rounding functions
   * 
   * &  double ceil(double x)
   *    returns the smallest integer as double not less than the argument provided
   * 
   * &  double floor(double x)
   *    returns the integer value lesser or equal to argument passed in the function.
   * 
   * &  double round(double x)
   *    returns the integral value that is nearest to x
   * 
   * &  double trunc(double x)
   *    return x rounded towards zero(remove fraction)
   * 
   * 
   * 
   * 
   * * Geometric functions
   *
   * &  double sin(double x)
   *    takes angle (in radians) and return its sine
   * 
   * &  double cos(double x)
   *    takes angle (in radians) and return its cosine
   * 
   * &  double tan(double x)
   *    takes angle (in radians) and return its tangent
   * 
   * &  double asin(double x)
   *    returns the arc sine of argument. The argument to asin() must be in the range -1 to 1 ; otherwise, a domain error occurs.
   * 
   * &  double acos(double x) 
   *    returns the arc cosine, The argument to acos() must be in the range -1 to 1;
   * 
   * &  double atan(double x)
   *    returns the arc tangent of arg
   * 
   * 
   * * Misc functions
   * 
   * & double fabs(double x)
   *   returns the absolute value of any number.
   * 
   * & int abs(int x)
   *  return its absolute value
   * 
   * & double pow(double x, double y)
   *  return x (base) power y (exp)
   * 
   * & double sqrt(double)
   *  return its square root value. Number can not be negative value.
   * 
   * & double cbrt (double)
   *  return its cubic root value. Number can be negative value.
   * 
   * & double hypot (double x, double y)
   *  return hypotenuse of a right-angled triangle whose legs are x and y
   *  sqrt(x * x + y * y)
   * 
   * & double log(double)
   *  returns the natural log of that number (base e)
   * 
   * & double log10(double)
   *  returns the 10 log of that number (base 10)
   * 
   * & double log2(double)
   *  returns the 2 log of that number (base 2)
   */
  
}

void ceil_replacement() {
  /**
   * * replacement for ceil (double) to interger domain
   * 
   * ? ceil(x, y) = (x+y-1) / y
   * ceil(x / y)
   * 
  */

  int x = 5, y = 2;
  int z = (x + y - 1) / y; // (6 / 2) => 3
  
}

/**
 * ^  EPS => will be mentioned in the problem
 * 
 * *  0  => Equal
 * *  1  => First larger
 * *  -1 => Second larger
*/

const double EPS = 1e-6;
int comp_double(double a, double b) {
  if (fabs(a - b) <= EPS) return 0;
  return a < b ? -1 : 1;
}

void double_comparision() {
  /**
   * * Double Comparsion
   * 
   * (1)
   * ! do not use float in competitive programming cuz it have some precision errors
   * ! Sometimes if you make float comparsion it'll fails (Only 7 decimal places)
  */

 /**
  *  * DON'T USE FLOAT
   * ! Output: Fails
  */

  float x = 4.7;
  if (x == float(4.7)) cout << "Equal" << endl;
  else cout << "Fails" << endl;

  /**
   * ! 15 decimal digits of precision.
   * ^ NOT exactly 4.70000000000000000000000000
   * * IT's better to use comp_double
  */
  double a = 4.7;
  double b = 4.7;

  if(comp_double(a, b)) {
    cout << "Equal" << endl;
  }else {
    cout << "Not Equal" << endl;
  }

  
}


ll fastpow(ll b, ll e) {
  if (!e) {
    return 1;
  }

  if (e % 2) {
    return b * fastpow(b, e - 1);
  }

  ll x = fastpow(b, e / 2);
  return x * x;
}

ll PowMod(ll b, ll e, ll M) {
  if (!e) {
     return 1;
  }

  ll p = PowMod((b * b) % M, e / 2, M);

  return (e % 2) ? (p * b) % M : p;
}

void modular_arithematic() {
  /**
   * * Modular Arithmetic
   * 
   * Suppose we are now (9) in (12 time system)
   * ? what'll be the time after 4 hours
   * 
   * 
   * ~ 9 + 4 = 13 = 1 + 12 = 1
   * 
   * &    n = r (rem) + m * c(cycles)
   * 
   * 5 + 0 * 12
   * 10 + 0 * 12
   * 1 + 1 * 12
   * 
   * * So % used to remove the cycles from our number
   * 
   * 13 % 12 = 1
   * 7 % 12 = 7
   * 
   * 
   * 
   * 
   * 
   * 
   * ? what if I ask you before 12 hours ?
   * * 9 => 9 - 12 = -3 % 12 => -3 hmm 🤔
   * 
   * -3 % 12 = -3 + 12 = 9
   * 
   * So we have to fix it (Fixing -ve) Rule
   * 
   * ~ (a % n + n) % n
   * ~ (-3 % 12 + 12) % 12 => 9
   *   (12 % 12 + 12) % 12 => 0
   * 
   */


  /**
   * * List of facts about modulus
   * 
   * ^ (1)
   * (a%n = 0) => a divisible by n
   * 
   * 
   * ^ (2)
   * If a%n == b%n => (a - b) % n = 0

   * a = 13
   * b = 34
   * n = 21
   * 
   * a - b = 21
   * 
   * 
   * ^ (3)
   * largest n such that a%n = b%n is n = b - a
   * 
   * 
   * ^ (4)
   * (a % n) % n = a % n
   * 
   * ^ (5)
   * (n ^ x) % n = 0 => for any x >= 0
   * (n * n * n * ... * n) % n = ((n % n) * (n % n) * ...(n % n))
   * 
   * ^ (6)
   * -a%n != a%n = > (3 % 12 = 3 vs -3 % 12 = 9)
   * 
   * ^ (7)
   * ((-a%n) + (a%n)) % n = 0
   *  -a + a
   * 
   * (x + (n - x) = n % n = 0)
   * 
   * ^ (8)
   * (a + b) % n = (a%n + b%n) % n
   * 
   * 
   * (a + b + c + d) % n ?
   * n = 10
   * 
   * 
   * ^ (9)
   * ((((a%n + (b%n) ) % n + (c%n)) % n + (d%n)) % n
   * 
   * 
   * ^ (10)
   * x % (a + b) != x % a + x%b
   * a / (x + y) != a / x + a / y
   * 
   * ^ (11)
   * x % 10 [get the last digit]
   * 
  */
}




void Basics() {
  builtin_functions();
  ceil_replacement();
  double_comparision();

  /**
   * * Simple Trick: to get no of digits
   * 
   * ^ #of digits = floor(log10(n))
  */
  int x = 123456;
  int noOfDigits = floor(log10(x)) + 1; // 6

  /**
   * * Built in pow function is slower O(n)
   * * 10 ^ 5 => 10*10*10*10*10
   * 
   * 
   * * Fast Power
   * ^ O(log(n))
  */
  
  ll a = 5, b = 12;
  ll pw = fastpow(a, b); 
  cout << pw << endl;



 /**
  *  * power mod (a ^ b) % MOD
  *  * Use fast power
 */
  ll e = 5, c = 10000, mod = 1e9 + 7;
  ll ans = PowMod(e, c, mod);



  modular_arithematic();

  // Problems
  // 1.
  // https://codeforces.com/contest/742/problem/A
  // given a number n, find the last digit in pow(1378,n)
  Problem_1();

  // 2.
  // https://codeforces.com/contest/732/problem/A
  // each shavel cost k egy-pound and we have unlimited number of coins of cost
  // 10 egy-pound and only one coin of cost r-egy-pound find the minimum number
  // of coins we need to pay to buy shavels without any coin-back
  Problem_2();

  // 3.
  // TODO: https://codeforces.com/contest/602/problem/A
  // Given 2 numbers in different bases, compare between them = | > | <
  Problem_3();

  // 4.
  // TODO: https://codeforces.com/contest/579/problem/A
  // you can put any number of bacteria into the box. And each night, every
  // bacterium in the box will split into two bacteria. You hope to see exactly
  // x bacteria in the box at some moment. What is the minimum number of
  // bacteria you need to put into the box across those days ?
  Problem_4();
}



void Problem_1() {
  ll n;
  cin >> n;
  ll ans = PowMod(8, n, 10);
  cout << ans << endl;
  4 % 4 
  1
  /**
   * Anyone has a recommendation
  */
  
  //  8, 64, 512, 4096, 32768, 262144, ..
  //  8, 4, 2, 6, 8, 4, 2, 6, ....

  int k, r; cin >> k >> r;
}


void Problem_2() {
  ll k, r;
  cin >> k >> r;
  ll noOfCoins = 1;
  
  while (true) {
    if ((k * noOfCoins) % 10 == 0 || (k * noOfCoins - r) % 10 == 0) break;
    noOfCoins++;
  }

  cout << noOfCoins << endl;
}

void Problem_3() {
  ll A = 0, B = 0;
  ll n, ba;
  cin >> n >> ba;
  vll a(n);
  for (ll& i : a) cin >> i;
  reverse(all(a));
  for (int i = 0; i < n; i++) A += a[i] * pow(ba, i);

  ll m, bb;
  cin >> m >> bb;
  vll b(m);
  for (ll& i : b) cin >> i;
  reverse(all(b));
  for (int i = 0; i < m; i++) B += b[i] * pow(bb, i);

  if (A < B)
    puts("<");
  else if (A > B)
    puts(">");
  else
    puts("=");
}

void Problem_4() {
  ll n;
  cin >> n;
  ll cnt = 0;
  while (n) {
    cnt += (n & 1);
    n >>= 1;
  }
  cout << cnt << endl;

  // Cool !!
  // cout << __builtin_popcountll(n)) << endl;
}

int main() {
  IO;
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
#else
  // freopen("input.in","r",stdin);
  // freopen("output.out","w",stdout);
#endif
  Basics();
}
