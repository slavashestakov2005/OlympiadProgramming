#include <iostream>
#include <random>                                              // для mt19937
#include <chrono>                                              // для chrono

using namespace std;
const int n = 1000000, D = 10000;

int main(){
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> dist(0, D);                     // рандомные числа из [0; D]
    int n0 = 0;
    for(int i = 0; i < n; ++i){
        double x = 1. * dist(rnd) / D, y = 1. * dist(rnd) / D; // обе координаты в [0; 1]
        n0 += (x + y < 1);                                     // внутри треугольника?
    }
    cout << 1. * n0 / n;
    return 0;
}
