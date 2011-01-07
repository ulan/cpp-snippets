// begin-snippet epsilon
template <typename T> inline T eps() {return 0;}
template <> inline double eps<double>() {return 1e-11;}
template <> inline long double eps<long double>() {return 1e-15;}
template <typename T> inline bool eq(T a, T b) {return abs(a - b) <= eps<T>();}
template <typename T> inline bool lt(T a, T b) {return a + eps<T>() < b;}
template <typename T> inline bool gt(T a, T b) {return a - eps<T>() > b;}
template <typename T> inline bool pos(T a) {return a > eps<T>();}
template <typename T> inline bool neg(T a) {return a < -eps<T>();}
template <typename T> inline bool zero(T a) {return abs(a) <= eps<T>();}
template <typename T> inline bool between(T x, T a, T b)
{
    if (a < b) return !lt(x, a) && !gt(x, b);
    else return !lt(x, b) && !gt(x, a);
}
// end-snippet

// begin-snippet gcd
template <typename T>
T gcd(T a, T b)
{
    return b == 0 ? a : gcd(b, a % b);
}

template <>
double gcd(double a, double b)
{
    return zero(a) ? b : a;
}

template <>
long double gcd(long double a, long double b)
{
    return zero(a) ? b : a;
}
// end-snippet
