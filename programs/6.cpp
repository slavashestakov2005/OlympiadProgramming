#include <utility>
pair<int, int> x, y = {3, 7};
x.first = 4;
x.second = 5;
cout << "(" << x.first << "; " << x.second << ")\n";             // (4; 5)
cout << "(" << y.first << "; " << y.second << ")\n";             // (3; 7)
#include <tuple>
tuple<int, char, string> t = {5, 'C', "text"};
cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";      // 5 C text
get<0>(t) = 512;
get<1>(t) = 'a';
get<2>(t) = "new text";
cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";      // 512 a new text
int n;
cin >> n;
int arr[n];
for (int i = 0; i < n; ++i) cin >> arr[i];
for (int i = n - 1; i >= 0; --i) cout << arr[i] << " ";
int arr[] = {5, 4, 3, 2, 1};
#include <vector>
vector<int> vec;
vector<int> prime = {2, 3, 5, 7};
cout << prime.size() << "\n";           // 4
cout << prime.empty() << "\n";          // 0, т.к. так выводится false
cout << prime[2] << "\n";               // 5
prime.push_back(13);                    // {2, 3, 5, 7, 13}
prime.insert(prime.begin() + 4, 11);    // {2, 3, 5, 7, 11, 13}
prime.erase(prime.begin() + 3);         // {2, 3, 5, 11, 13}
prime.pop_back();                       // {2, 3, 5, 11}
cout << prime.front() << "\n";          // 2
cout << prime.back() << "\n";           // 11
prime.begin();                          // итератор, указывающий на 2
prime.end();                            // итератор, указывающий на место после конца prime
cout << prime[5] << "\n";               // неопределённое поведение
cout << prime.at(2) << "\n";            // 5
cout << prime.at(5) << "\n";            // ошибка
vector<double> get_roots(double a, double b, double c){
    vector<double> ans;
    double d = b * b - 4 * a * c;
    if (d > 0){
        ans.push_back((-b - sqrt(d)) / (2 * a));
        ans.push_back((-b + sqrt(d)) / (2 * a));
    } else if (d == 0) ans = {(-b) / (2 * a)};
    return ans;
}
double a, b, c;
cin >> a >> b >> c;
vector<double> v = get_roots(a, b, c);
for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";
for (double x : v) cout << x << " ";
for (vector<double>::iterator it = v.begin(); it != v.end(); ++it) cout << *it << " ";
auto pi = 3.1415926535f;                // float
for (auto x : v) cout << x << " ";      // double
for (auto it = v.begin(); it != v.end(); ++it) cout << *it << " "; // vector<double>::iterator
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int x : a) cin >> x;
    for(int x : a) cout << x << " ";
    return 0;
}
for(int & x : a) cin >> x;
