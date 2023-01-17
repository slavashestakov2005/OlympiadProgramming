#include <iostream>     // нам понадобится ввод-вывод
using namespace std;
int main(){
    double a, b, c;
    cin >> a >> b >> c;
    double d = b * b - 4 * a * c;
    // а как дальше, там же разное количество действительных корней в зависимости от знака d?
    return 0;
}
if (x){
    // сделать что-то, если x приводится к true
} else if (y){
    // сделать что-то, если x не верно, но верно y
} else {
    // сделать что-то, если и x, и y оба не верны.
}
if (d > 0){
    double x1 = (-b - sqrt(d)) / (2 * a), x2 = (-b + sqrt(d)) / (2 * a);
    cout << "d > 0: " << x1 << ", " << x2;
} else if (d == 0) cout << "d = 0: " << (-b) / (2 * a); 
// блок из одного выражения может быть без {}
else {
    cout << "d < 0: ";
    cout << "x1 and x2 is not Real :(";
    // так вполне можно выводить, всё выведется в одну строку
}
#include <cmath>        // здесь у C++ "прячется" вся математика
#include <iostream>
using namespace std;
int main(){
    int x;
    cin >> x;
    switch(x){
        case 0:
        case 1:
            // выполнится при x == 0 || x == 1
            cout << "zero or one";
            break;
        case 2:
            // выполнится при x == 2
            cout << "two";
            break;
        case 3:
            // выполнится при x == 3
            cout << "three";
        default:
            // не выполнится при x == 0 || x == 1 || x == 2
            // потому что в тех case блоках был оператор break
            cout << "default";
    }
    return 0;
}
for (x; y; z) {
    // тело цикла
}
while (x) {
    // тело цикла
}
do {
    // тело цикла
} while(x);
// ввод n, проверка, что n > 1
int a = 0, b = 1;   // потому что мы начнём вычисления со второго числа,
                    // а для него предыдущие — 0 и 1
// здесь будет тело цикла
cout << b;          // напишем циклы так, чтобы ответ оказался в b
for(int i = 2; i <= n; ++i){
    int c = a + b;
    a = b;
    b = c;
}
int i = 2;
while(i <= n){
    int c = a + b;
    a = b;
    b = c;
    ++i;
}
int i = 2;
do {
    int c = a + b;
    a = b;
    b = c;
    ++i;
} while(i <= n);
cout << c;  // error: 'c' was not declared in this scope
            // (ошибка: 'c' не был объявлен в этой области видимости)
double get_d(double a, double b, double c){
    double value = b * b - 4 * a * c;
    return value;
}
double d = b * b - 4 * a * c;
double d = get_d(a, b, c);
