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
 
inline bool isIn(Coordinate a, Coordinate b, Coordinate x) {
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
 
bool operator<(const Point& P, const Point& Q) {
    if (sign(P.y - Q.y) != 0) { return P.y < Q.y; }
    return (sign(P.x - Q.x) == -1);
}
 
bool operator==(const Point& P, const Point& Q) { return !(P < Q) && !(Q < P); }
 
Point operator*(const Point &P, const double k) {
    return Point(P.x * k, P.y * k);
}
 
inline double cross(const Point &P, const Point &Q) {
    return P.x * Q.y - P.y * Q.x;
}
 
/// returns true if P belongs in segment AB
inline bool isIn(Point A, Point B, Point P) {
    if (sign(cross(B - A, P - A)) != 0) { return false; }
    return (isIn(A.x, B.x, P.x) && isIn(A.y, B.y, P.y));
}
 
vector<Point> convexHull(vector<Point> pts) {
    if (pts.size() <= 2) { return pts; }
    sort(pts.begin(), pts.end());
    int n = pts.size(), t = 0;
    vector<Point> ch(2 * n);
    for (int i = 0; i < n; i++) {
        while (t > 1 &&
               sign(cross(ch[t - 1] - ch[t - 2], pts[i] - ch[t - 2])) <= 0) {
            t--;
        }
        ch[t++] = pts[i];
    }
    int pt = t;
    for (int i = n - 2; i >= 0; i--) {
        while (t > pt &&
               sign(cross(ch[t - 1] - ch[t - 2], pts[i] - ch[t - 2])) <= 0) {
            t--;
        }
        ch[t++] = pts[i];
    }
    if (ch[0] == ch[t - 1]) t--;
    ch.resize(t);
    return ch;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
 
    vector<Point> g(n);
    for (auto &po: g) {
        cin >> po.x >> po.y;
    }
 
    const auto hull = convexHull(g);
    cout << hull.size() << "\n";
    for (const auto& p: hull) {
        cout << p.x << " " << p.y << "\n";
    }
 
}
