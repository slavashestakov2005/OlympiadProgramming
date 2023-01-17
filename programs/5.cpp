cout << "Hello\nworld!";
cout << char(tolower('a')) << " " << char(tolower('A')) << "\n";        // a a
cout << char(toupper('a')) << " " << char(toupper('A')) << "\n";        // A A
#include <string>
#include <iostream>                 // ввод-вывод
#include <string>                   // строки
using namespace std;
int main(){
    string s = "Hello,", name;
    cin >> name;
    cout << s << " " << name;
    return 0;
}
string s = "Hello ";
s = s + "world";                    // s = "Hello world"
s += "!";                           // s = "Hello world!"
cout << s.size() << "\n";           // 12
cout << s.empty() << "\n";          // 0, т.к. так выводится false
cout << s[6] << "\n";               // 'w', т.к. индексация с 0
cout << s.substr(3, 5) << "\n";     // "lo wo"
s.push_back('!');                   // s = "Hello world!!"
s.insert(5, ',');                   // s = "Hello, world!!"
s.erase(5, 2);                      // s = "Helloworld!!"
s.pop_back();                       // s = "Helloworld!"
cout << s.front() << "\n";          // 'H', т.к. это первый символ.
cout << s.back() << "\n";           // '!', т.к. это последний символ.
s.begin();                          // итератор, указывающий на 'H'
s.end();                            // итератор, указывающий на символ сразу после строки
#include <iostream>
using namespace std;
int main(){
    int h, m;
    char c;
    cin >> h >> c >> m;
    cout << h << ":" << m;
    return 0;
}
#include <iostream>
using namespace std;
int main(){
    int h, m;
    scanf("%d:%d", &h, &m);         // вводим два целых через ":"
    printf("%d:%d", h, m);          // выводим два целых через ":"
    return 0;
}
string s;
getline(cin, s);
#include <iostream>
using namespace std;
int main(){
    int x, sum = 0;
    while(cin >> x){                // вся магия в этой строке
        sum += x;
    }
    cout << sum;
    return 0;
}
