/*
=======================================
consteval

Similar to constexpr functions, but functions
with a consteval specifier must produce a constant.

These are called immediate functions.
=======================================
*/

consteval int sqr(int n)
{
  return n * n;
}

constexpr int r = sqr(100); // OK
int x = 100;
int r2 = sqr(x);			// ERROR: the value of 'x' is not usable in a constant expression
							// OK if `sqr` were a `constexpr` function
				 

/*
=======================================
constinit
=======================================
*/
const char *g() { return "dynamic initialization"; }
constexpr const char *f(bool p) { return p ? "constant initializer" : g(); }
 
constinit const char *c = f(true); // OK
constinit const char *d = f(false); // error
