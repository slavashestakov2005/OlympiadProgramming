const int N = 1 << 17;  // 2^17 = 131072, это точно больше, чем обрабатываемых элементов
struct SegmentTree{
    int st[2 * N];
    SegmentTree(vector<int> v){
        for(int i = 0; i < v.size(); ++i) st[N + i] = v[i];             // сохранение данных
        for(int i = v.size(); i < N; ++i) st[N + i] = INF;              // нейтральные элементы
        for(int i = N - 1; i > 0; --i) st[i] = min(st[2 * i], st[2 * i + 1]);   // предподсчёт
    }

    int get_min(int l, int r){
        l += N, r += N;                                     // сдвинулись в самый нижний слой
        int ans = INF;                                      // текущей ответ
        while(l <= r){
            if (l & 1) ans = min(ans, st[l++]);             // обработали и сдвинули l
            if (!(r & 1)) ans = min(ans, st[r--]);          // обработали и сдвинули r
            l /= 2, r /= 2;                                 // перешли к родителям
        }
        return ans;
    }
};
int get_k(int k){                                               // внутри класса
    int p = 1;                                                  // корень
    while(p < N){                                               // пока не нижний уровень
        if (st[2 * p] < k) { k -= st[2 * p]; p = 2 * p + 1; }   // переход вправо
        else p *= 2;                                            // переход влево
    }
    return p - N;                                               // вернуть обычный индекс
}
struct SparseTable{
    vector<vector<int>> v;
    SparseTable(vector<int> a){
        v.push_back({});
        for(int x : a) v[0].push_back(x);                       // i = 0
        for(int i = 1; (1 << i) < a.size(); ++i){               // i > 0
            v.push_back({});
            int ln = (1 << i - 1), ln2 = (1 << i);              // ln2 - длина отрезка
            for(int j = 0; j + ln2 <= a.size(); ++j){           // все отрезки длины ln2
                v.back().push_back(min(v[v.size() - 2][j], v[v.size() - 2][j + ln]));
            }
        }
    }

    int get_min(int l, int r){
        int t = log2(r - l + 1);                                // подходящее t
        return min(v[t][l], v[t][r - (1 << t) + 1]);            // получение ответа
    }
};
struct FenwickTree{
    vector<int> t;
    int n;

    FenwickTree(vector<int> a){
        n = a.size();
        t.assign(n, 0);                                         // конструирование —
        for(int i = 0; i < a.size(); ++i) add(i, a[i]);         // это много обновлений
    }

    void add(int p, int d){
        for (; p < n; p = (p | (p + 1))) t[p] += d;             // запомнить p | (p + 1)
    }

    int sum(int r){
        int result = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) result += t[r];   // запомнить r & (r + 1),
        return result;                                          // понять -1 из формулы t[i]
    }

    int sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
};
struct FenwickTree{
    vector<int> t;
    int n;

    FenwickTree(vector<int> a){
        n = a.size() + 1;                                       // t[0] - не используем
        t.assign(n, 0);                                         // конструирование —
        for(int i = 0; i < a.size(); ++i) add(i + 1, a[i]);     // это много обновлений
    }

    void add(int p, int d){
        for (; p < n; p += p & -p) t[p] += d;                   // запомнить p & -p
    }

    int sum(int r){
        int result = 0;
        for (; r > 0; r -= r & -r) result += t[r];              // запомнить r & -r,
        return result;
    }

    int sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
};
