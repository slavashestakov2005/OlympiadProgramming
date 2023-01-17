struct DSU{                 // класс для удобства работы
    vector<int> p;          // здесь и далее может понадобится short, если мы близки к MLE
    
    DSU(int n = 0){         // конструктор от размера DSU
        p.assign(n, 0);     // задаём для p нужный размер
        build();            // строим DSU
    }
    
    void make(int x){ p[x] = x; }
    
    void build(){ for(int i = 0; i < p.size(); ++i) p[i] = i; }
    
    int find(int x){
        if (p[x] == x) return x;            // корень
        else return find(p[x]);             // поднялись выше
    }
    
    void merge(int a, int b){
        a = find(a), b = find(b);           // нашли корни
        p[a] = b;                           // подвесили
    }
};
int find(int x){
    if (p[x] != x) p[x] = find(p[x]);       // подняли всё, что не корень
    return p[x];
}
int find(int x){ return p[x] == x ? p[x] : p[x] = find(p[x]); }
void merge(int a, int b){
    a = find(a), b = find(b);
    if (rand() & 1) swap(a, b);             // делаем swap, если rand() % 2 == 1
    p[a] = b;
}
void merge(int a, int b){
    a = find(a), b = find(b);
    if (a != b) {                           // чтобы rank менялся правильно
        if (rank[a] < rank[b]) swap(a, b);
        p[b] = a;
        rank[a] += rank[b];                 // добавили дерево к размеру
    }
}
void merge(int a, int b){
    a = find(a), b = find(b);
    if (a != b) {                           // чтобы rank менялся правильно
        if (rank[a] < rank[b]) swap(a, b);
        p[b] = a;
        if (rank[a] == rank[b]) ++rank[a];  // или rank[a] = max(rank[a], rank[b] + 1);
    }
}
struct DSU{
    vector<int> p, rank;
    
    DSU(int n = 0){
        p.assign(n, 0);
        rank.assign(n, 1);
        build();
    }
    
    void make(int x){ p[x] = x; rank[x] = 1; }
    
    void build(){ for(int i = 0; i < p.size(); ++i) p[i] = i; }
    
    int find(int x){
        return p[x] == x ? p[x] : p[x] = find(p[x]);    // сжатие путей
    }
    
    void merge(int a, int b){
        a = find(a), b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) swap(a, b);
        p[b] = a;
        rank[a] += rank[b];                             // ранг = размер поддерева
    }
};
struct Sqrt{
    int n, m;                                           // всего элементов n, по m в блоке
    vector<int> a, b;                                   // a — сами элементы, b - блоки

    Sqrt(){}
    Sqrt(vector<int> v){ build(v); }

    void build(vector<int> v){                          // предподсчёт
        n = v.size(); m = sqrt(n); a = v;
        for(int i = 0; i < n; i += m){
            int now = INF;
            for(int j = i; j < min(n, i + m); ++j) now = min(now, a[j]);
            b.push_back(now);
        }
    }

    int get_min(int l, int r){                          // поиск минимума
        int lb = l / m, rb = r / m, ans = INF;          // блоки, в которых лежат границы
        if (lb == rb){                                  // границы в одном блоке
            for(int i = l; i <= r; ++i) ans = min(ans, a[i]);
        } else{                                         // границы в разных блоках
            for(int i = l; i < (lb + 1) * m; ++i) ans = min(ans, a[i]);
            for(int i = lb + 1; i < rb; ++i) ans = min(ans, b[i]);
            for(int i = rb * m; i <= r; ++i) ans = min(ans, a[i]);
        }
        return ans;
    }
};
void update(int pos, int value){                        // метод внутри класса
    a[pos] = value;
    int bpos = pos / m;                                 // блок, который нужно обновить
    int apos = bpos * m;                                // первый элемент блока
    b[bpos] = INF;
    for(int i = apos; i < min(apos + m, n); ++i) b[bpos] = min(b[bpos], a[i]);
}
