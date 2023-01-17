#include <set>
set<int> s;
set<int> prime = {7, 3, 5, 2, 7};
cout << prime.size() << "\n";                   // 4
cout << prime.empty() << "\n";                  // 0, т.к. так выводится false
prime.insert(13);                               // {2, 3, 5, 7, 13}
prime.insert(11);                               // {2, 3, 5, 7, 11, 13}
prime.erase(7);                                 // {2, 3, 5, 11, 13}
prime.begin();                                  // итератор на 2
prime.end();                                    // итератор на место после конца prime
cout << prime.count(1) << "\n";                 // 0, так как нет
cout << (prime.find(1) == prime.end()) << "\n"; // 1, 1 не найден, поэтому find вернул end
cout << prime.count(2) << "\n";                 // 1, так как есть
cout << *prime.find(2) << "\n";                 // 2, так как find вернул итератор на 2
cout << *prime.lower_bound(4) << "\n";          // 5, так как первый элемент >= 4
cout << *prime.upper_bound(4) << "\n";          // 5, так как первый элемент > 4
cout << *prime.lower_bound(11) << "\n";         // 11, так как первый элемент >= 11
cout << *prime.upper_bound(11) << "\n";         // 13, так как первый элемент > 11
cout << (prime.upper_bound(15) == prime.end()) << "\n";     // 1 (true), так как не найдено
for (int i = 0; i < prime.size(); ++i) cout << prime[i] << " ";
for (set<int>::iterator it = prime.begin(); it != prime.end(); ++it) cout << *it << " ";
for (auto it = prime.begin(); it != prime.end(); ++it) cout << *it << " ";
for (int x : prime) cout << x << " ";
for (auto x : prime) cout << x << " ";
#include <map>
map<int, string> phones;
map<int, string> ph = {{3, "Alice"}, {1, "Bob"}, {2, "Eva"}};
cout << ph.size() << "\n";              // 3
cout << ph.empty() << "\n";             // 0, т.к. так выводится false
ph[5] = "Anna";                         // {{1, "Bob"}, {2, "Eva"}, {3, "Alice"}, {5, "Anna"}}
ph[3] = "Peter";                        // {{1, "Bob"}, {2, "Eva"}, {3, "Peter"}, {5, "Anna"}}
ph.erase(2);                            // {{1, "Bob"}, {3, "Peter"}, {5, "Anna"}}
ph.insert({7, "Bob"});                  // {{1, "Bob"}, {3, "Peter"}, {5, "Anna"}, {7, "Bob"}}
ph.begin();                             // итератор на {1, "Bob"}
ph.end();                               // итератор на место после {7, "Bob"}
cout << ph.count(1) << "\n";            // 1 (true), так как есть ключ 1
cout << ph.find(1) -> first << " " << ph.find(1) -> second << "\n";     // 1 Bob
cout << ph.count(2) << "\n";                    // 0 (false), так как нет ключа 2
cout << (ph.find(2) == ph.end()) << "\n";       // 1, ключ 2 не найден, поэтому find вернул end
cout << ph.lower_bound(4) -> second << "\n";    // Anna, так как первый элемент с ключом >= 4
cout << ph.upper_bound(4) -> second << "\n";    // Anna, так как первый элемент с ключом > 4
cout << ph.lower_bound(3) -> second << "\n";    // Peter, так как первый элемент с ключом >= 3
cout << ph.upper_bound(3) -> second << "\n";    // Anna, так как первый элемент с ключом > 3
cout << (ph.upper_bound(8) == ph.end()) << "\n";// 1 (true), так как не найдено
for (map<int, string>::iterator it = ph.begin(); it != ph.end(); ++it)
    cout << it -> first << " " << it -> second << "\n";
for (auto it = ph.begin(); it != ph.end(); ++it)
     cout << it -> first << " " << it -> second << "\n";
for (pair<int, string> x : ph) cout << x.first << " " << x.second << "\n";
for (auto x : ph) cout << x.first << " " << x.second << "\n";
for (auto [key, value] : ph) cout << key << " " << value << "\n";       // C++17
pair<int, int> p = {1, 2};
auto& [x, y] = p;                               // без & будет копирование!
x = 5, y = -1;
cout << p.first << " " << p.second << "\n";     // 5 -1
multiset<int> prime = {7, 3, 5, 2, 7, 2};       // {2, 2, 3, 5, 7, 7}
prime.erase(7);                                 // {2, 2, 3, 5}
prime.erase(prime.find(2));                     // {2, 3, 5}
multimap<int, int> data = {{1, 2}, {1, 3}, {2, 4}, {2, 2}, {3, 1}};
data.erase(1);                                  // {{2, 4}, {2, 2}, {3, 1}}
data.erase(data.find(2));                       // {{2, 2}, {3, 1}}
