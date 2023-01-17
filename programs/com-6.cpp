while (r - l > 1) {                 // можно закончить поиск, когда l и r стали соседними
    int m = (r + l) / 2;            // вычисляем середину
    (a[m] < x ? l : r) = m;         // тернарным оператором очень удобно двигать границы :)
}
vector<int> p1 = {2, 3, 5, 7, 11};
int p2[] = {2, 3, 5, 7, 7, 11, 13};
upper_bound(p1.begin(), p1.end(), 8) - p1.begin();      // 4, так как 8 < p1[4] = 11
lower_bound(p2, p2 + 7, 7) - p2;                        // 3, так как 7 <= p2[3] = 7
binary_search(p2, p2 + 7, 17);                          // false, так как не нашлось
#include <algorithm>                // содержит lower_bound, upper_bound и binary_search
