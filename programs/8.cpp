struct Point{
    int x, y;
};
Point p{3, 4};                          // Создаём точку, используются фигурные (!) скобки
cout << p.x << "; " << p.y << "\n";     // 3; 4
vector<Point> v;
Point(int x, int y){
    this -> x = x;
    this -> y = y;
}
double rho(){                           // Метод, его нужно писать внутри Point
    return sqrt(x * x + y * y);         // sqrt - математическая функция, о ней чуть позже
                                        // программа сама поймёт, какие x и y брать
}
cout << p.rho() << "\n";                // 5
double dist(Point a, Point b){          // обычная функция, она пишется вне структур
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
Point q(4, 5);                          // т.к. у нас определён конструктор,
                                        // то можно использовать круглые скобки
cout << dist(p, q) << "\n";             // 1.41421, так как это корень из 2
Point operator-(Point a){               // тоже функция, пишем вне структур
    return Point(-a.x, -a.y);           // сама операция отрицания должна создавать новую точку
}
Point(int x = 0, int y = 0){ /* такое же тело, как и раньше */ }
Point(int x = 0, int y = 0) : x(x), y(y) {}
Point r(7), s;
cout << r.x << "; " << r.y << "\n";      // 7; 0
cout << s.x << "; " << s.y << "\n";      // 0; 0
#include <cmath>
cout << pow(10, 6) << "\n";             // 1e+006
#include <iomanip>
cout << fixed << setprecision(9);       // fixed запрещает выводить число через e
                                        // setprecision устанавливает число знаков после запятой
#include <cstdlib>                      // для rand() и srand()
#include <ctime>                        // для time()
srand(time(0));                         // начальное значение, задаётся 1 раз в начале программы
// если не написать, то будет srand(0) — всегда одна и та же последовательность
int r = rand();                         // получение случайного числа
#include <random>                       // для mt19937
#include <chrono>                       // для chrono
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());    // начальное значение
uniform_int_distribution<> dist(1, 100);// диапазон рандома
int r1 = dist(rnd);                     // r1 из [1; 100]
int r2 = rnd();                         // r2 - любой int
// для 64-битных чисел нужно использовать mt19937_64
#include <algorithm>
// swap меняет значения местами
int a = 3, b = 4;
swap(a, b);                             // a = 4, b = 3
// sort сортирует значения контейнера, reverse — разворачивает контейнер
// next_permutation и prev_permutation — следующая и предыдущая перестановки контейнера
int p[3] = {2, 1, 3};
bool is_n = next_permutation(p, p + 3); // p = {2, 3, 1}, is_n = true
sort(p, p + 3);                         // p = {1, 2, 3}
bool is_p = prev_permutation(p, p + 3); // p = {3, 2, 1}, is_p = false
reverse(p, p + 3);                      // p = {1, 2, 3}
vector<int> v = {2, 1, 3};
sort(v.begin(), v.end());               // v = {1, 2, 3}
bool cmp(int a, int b){                 // наша функция для сортировки
    return a > b;                       // по умолчанию a < b
}
sort(v.begin(), v.end(), cmp);          // v = {3, 2, 1}
struct Cmp{                             // наша структура для сортировки
    bool operator()(int a, int b) const{// нужно переопределить оператор круглые скобки
        return a > b;                   // по умолчанию a < b
    }
};
set<int, Cmp> s = {2, 1, 3};            // s = {3, 2, 1}
a ^= b ^= a ^= b;                       // a = 3, b = 4
stack<int> st;                          // st = {}
st.push(3);                             // st = {3}
st.push(2);                             // st = {3, 2}
int x = st.top();                       // x = 2
st.pop();                               // st = {3}
x = st.top();                           // x = 3
queue<int> q;                           // q = {}
q.push(3);                              // q = {3}
q.push(2);                              // q = {3, 2}
int x = q.back();                       // x = 2
x = q.front();                          // x = 3
q.pop();                                // q = {2}
x = q.back();                           // x = 2
deque<int> d;                           // d = {}
d.push_back(2);                         // d = {2}
d.push_back(4);                         // d = {2, 4}
d.push_front(1);                        // d = {1, 2, 4}
int x = d.back();                       // 4
x = d.front();                          // 1
x = d[1];                               // 2
x = d.at(4);                            // ошибка
d.insert(d.begin() + 2, 3);             // d = {1, 2, 3, 4}
for(int x : d) cout << x << " ";        // 1 2 3 4
d.erase(d.begin() + 1);                 // d = {1, 3, 4}
d.pop_back();                           // d = {1, 3}
reverse(d.begin(), d.end());            // есть итераторы, d = {3, 1}
d.pop_front();                          // d = {1}
#include <stack>                        // содержит stack
#include <queue>                        // содержит queue
#include <deque>                        // содержит deque
#define INF 2e9
const int INF = 2e9;
#define ll long long
using ll = long long;
#define PRINT(a) for(auto x : a) cout << x << " "; cout << "\n";
int a[] = {1, 2, 3, 4, 5};
PRINT(a)                                // 1 2 3 4 5
vector<int> b = {5, 4, 3, 2, 1};
PRINT(b)                                // 5 4 3 2 1
template<typename T>
T func(T x){
    return x > 0 ? x : -x;
}
func(-5);                               // тип int
func(-5ll);                             // тип long long
func(-5.5);                             // тип double
func(-5.5f);                            // тип float
template<int N>
struct Fact{                            // определяем шаблонный класс Fact
    static int const value = Fact<N - 1>::value * N;    // рекурсивно определяем факториал
};
template<>
struct Fact<0>{                         // «специализация» для факториала нуля
    static int const value = 1;
};
cout << Fact<5>::value << "\n";         // 120
constexpr int fact(int n) {
    return n == 0 ? 1 : n * fact(n - 1);
}
int n;
cin >> n;
cout << fact(5) << " " << fact(n);      // 120 <n!>
template<typename F, typename ... Args, int ... Indices>
auto apply_f(F f, std::tuple<Args...> t, IntList<Indices...>)
    -> decltype( f(std::get<Indices>(t)...) ){
        return f(std::get<Indices>(t)...);
}
