#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <iostream>
 
using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::ios;
 
using Coordinate = long long;
 
inline int sign(const Coordinate x) { return (x < 0) ? -1 : (x > 0); }
 
inline bool is_in(Coordinate a, Coordinate b, Coordinate x) {
    if (a > b) { swap(a, b); }
    return (a <= x && x <= b);
}
 
struct Point {
    Coordinate x, y;
 
    Point(Coordinate _x = 0, Coordinate _y = 0) : x(_x), y(_y) {}
};
 
Point operator-(const Point &P, const Point &Q) {
    return Point(P.x - Q.x, P.y - Q.y);
}
 
Point operator*(const Point &P, const double k) {
    return Point(P.x * k, P.y * k);
}
 
inline double cross(const Point &P, const Point &Q) {
    return P.x * Q.y - P.y * Q.x;
}
 
/// returns true if P belongs in segment AB
inline bool is_in(Point A, Point B, Point P) {
    if (sign(cross(B - A, P - A)) != 0) { return false; }
    return (is_in(A.x, B.x, P.x) && is_in(A.y, B.y, P.y));
}
 
const int OUT = 0, ON = 1, IN = 2;
 
int inside_polygon(Point P, const vector<Point> &G) {
    size_t n = G.size(), cnt = 0;
    for (size_t i = 0; i < n; i++) {
        Point A = G[i], B = G[(i + 1) == n ? 0 : i + 1];
        if (is_in(P, A, B)) { return ON; }
        if (B.y < A.y) { swap(A, B); }
        if (P.y < A.y || B.y <= P.y || A.y == B.y) { continue; }
        if (sign(cross(B - A, P - A)) > 0) { cnt++; }
    }
    return ((cnt & 1) ? IN : OUT);
}
 
inline bool is_convex(const vector<Point>& G) {
    int n = G.size();
    assert(n >= 3);
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int k = (i + 2) % n;
        if (sign(cross(G[j] - G[i], G[k] - G[i])) < 0) { return false; }
    }
    return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    Point p;
    cin >> n >> p.x >> p.y;
 
    vector<Point> g(n);
    for (auto &po: g) {
        cin >> po.x >> po.y;
    }
 
    cout << ((inside_polygon(p, g))  ? "YES" : "NO");
}
