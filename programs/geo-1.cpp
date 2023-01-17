template<typename T>
struct Point{
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    
    Point<T> operator+(Vector<T> v){ return Point<T>(x + v.x, y + v.y); }
    Point<T> operator-(Vector<T> v){ return Point<T>(x - v.x, y - v.y); }
    
    friend istream& operator>>(istream& is, Point<T>& p){ return is >> p.x >> p.y; }
    friend ostream& operator<<(ostream& os, Point<T>& p){ return os << p.x << ' ' << p.y; }
};
template<typename T>
struct Vector{
    T x, y;
    Vector(T x = 0, T y = 0) : x(x), y(y) {}
    template<typename Q, typename R>
    Vector(Point<Q> a, Point<R> b) : x(b.x - a.x), y(b.y - a.y) {}
    
    Vector<T> operator+() const { return Vector<T>(x, y); }
    Vector<T> operator-() const { return Vector<T>(-x, -y); }
    Vector<T> operator+(Vector<T> const& o) const { return Vector<T>(x + o.x, y + o.y); }
    Vector<T> operator-(Vector<T> const& o) const { return Vector<T>(x - o.x, y - o.y); }
    
    Vector<T> operator*(T d){ return Vector<T>(x * d, y * d); }
    Vector<T> operator/(T d){ return Vector<T>(x / d, y / d); }
    
    T operator*(Vector<T> const& o) const{ return x * o.x + y * o.y; }
    T operator%(Vector<T> const& o) const{ return x * o.y - o.x * y; }
    double operator^(Vector<T> const& o) const{ return atan2((*this) % o, (*this) * o); }
    
    double len() const{ return sqrt(x * x + y * y); }
    T sqlen() const{ return x * x + y * y; }
    double alpha() const{ return atan2(y, x); }
    Vector<double> norm(){ double a = alpha(); return Vector<double>(cos(a), sin(a)); }
    Vector<T> pd(){ return Vector<T>(-y, x); }
    
    friend istream& operator>>(istream& is, Vector<T>& v){ return is >> v.x >> v.y; }
    friend ostream& operator<<(ostream& os, Vector<T>& v){ return os << v.x << ' ' << v.y; }
};
template<typename T>
struct Line{
    T a, b, c;
    Line(T a = 0, T b = 0, T c = 0) : a(a), b(b), c(c) {}
    Line(Point<T> p, Point<T> q) : a(q.y - p.y), b(p.x - q.x) { c = -a * p.x - b * p.y; }
    
    pair<Point<double>, Point<double>> points(){
        if (!b) return {{-1. * c / a, 0}, {-1. * c / a, 1}};
        return {{0, -1. * c / b}, {1, -1. * (c + a) / b}};
    }
    
    template<typename Q>
    double ro(Point<Q> p){
        auto [q, r] = points();                                         // синтаксис C++17
        Vector<double> pq(p, q), pr(p, r), qr(q, r);
        return abs(pq % pr) / qr.len();
    }
    
    pair<Line<double>, Line<double>> parallel(double r){
        r *= sqrt(a * a + b * b);
        return {{a, b, c - r}, {a, b, c + r}};
    }
    
    pair<bool, Point<double>> operator^(Line<T> o){
        T ab = a * o.b - o.a * b, ac = o.a * c - a * o.c, bc = o.c * b - c * o.b;
        if (abs(ab) < EPS){
            if (abs(ac) < EPS && abs(bc) < EPS)
                return {false, Point<double>(0, 0)};                        // совпадение
            else return {false, Point<double>(1, 1)};                       // параллельность
        }
        return {true, Point<double>(1. * bc / ab, 1. * ac / ab)};           // пересечение
    }
    
    friend istream& operator>>(istream& is, Line<T>& l){ return is >> l.a >> l.b >> l.c; }
    friend ostream& operator<<(ostream& os, Line<T>& l)
        { return os << l.a << ' ' << l.b << ' ' << l.c; }
};
const double EPS = 1e-9;
const double PI = acos(-1);
cout << fixed << setprecision(9);
template<typename T>
struct Vector;
template<typename T>
T area2(Point<T> a, Point<T> b, Point<T> c){ return Vector<T>(a, b) % Vector<T>(a, c); }
template<typename T>
bool cw(Point<T> a, Point<T> b, Point<T> c){ return area2(a, b, c) < 0; }
template<typename T>
bool ccw(Point<T> a, Point<T> b, Point<T> c){ return area2(a, b, c) > 0; }
template<typename T>
bool collinear(Point<T> a, Point<T> b, Point<T> c){ return abs(area2(a, b, c)) < EPS; }
