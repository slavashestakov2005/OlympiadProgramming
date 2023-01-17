ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
// И ещё много-много ...
#define FOR_(i, s, n) for(int i = s; i < n; ++i)
#define FOR(i, n) FOR_(i, 0, n)
#define FORR(x, a) for(auto &x : a)
#define IN(x) FORR(y, x) cin >> y;
#define OUT(a) FORR(x, a) cout << x << " "; cout << "\n";
#define OUTM(m) FORR(x, m) cout << x.first << " : " << x.second << "\n";
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int, int>;
std::sort
std::cin
std::cout
std::min
// И ещё много-много ...
using namespace std;
cout << 1 / 3 + 1 / 3 + 1 / 3;
cout << 1. / 3 + 1. / 3 + 1. / 3;
const int INF = 2e9 + 1024;                 // где-то в верху файла, чтобы везде пользоваться
#include <fstream>                          // для ifstream и ofstream
ifstream fin("in.txt");                     // чтение из файла
ofstream fout("out.txt");                   // запись в файл
int n;
fin >> n;                                   // считали число
fout << n;                                  // записали число
freopen("in.txt", "r", stdin);              // перенаправили cin
freopen("out.txt", "w", stdout);            // перенаправили cout
int n;
cin >> n;                                   // считали число
cout << n;                                  // записали число
