pair<int, int> sqr(int a){
    int x = sqrt(a) - 5;                        // погрешности 5 вполне хватает
    while(x * x < a) ++x;                       // зажимаем корень сверху
    if (x * x == a) return {x, x};              // целочисленный корень
    return {x - 1, x};                          // дробный корень
}
