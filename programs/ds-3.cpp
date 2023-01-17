template<typename T>
struct Heap{
    vector<T> data;

    Heap(){
        data.push_back({});                                 // 0-вой элемент
    }
    
    Heap(vector<T> d){
        data.push_back({});
        for(T v : d) data.push_back(v);
        size_t n = data.size();
        for(int i = n / 2; i > 0; --i) sift_down(i);
    }
    
    void sift_up(size_t pos){                               // просеивание вверх
        while(pos > 1 && data[pos] < data[pos / 2]){
            swap(data[pos], data[pos / 2]);
            pos /= 2;
        }
    }
    
    void sift_down(size_t pos){                             // просеивание вниз
        size_t n = data.size();
        while(true){
            size_t l = 2 * pos, r = 2 * pos + 1, good;
            if (l < n && data[l] < data[pos] || r < n && data[r] < data[pos]){
                good = l;
                if (r < n && data[l] > data[r]) good = r;
                swap(data[pos], data[good]);
                pos = good;
            }
            else break;
        }
    }
    
    void insert(T v){
        data.push_back(v);
        sift_up(data.size() - 1);
    }
    
    void pop(){
        swap(data.back(), data[1]);
        data.pop_back();
        sift_down(1);
    }
    
    T get(){ return data[1]; }

    T extract(){
        T ans = get();
        pop();
        return ans;
    }
};
priority_queue<int> q;
q.push(2);
q.push(5);
q.push(3);
cout << q.size() << "\n";                                   // 3
cout << q.empty() << "\n";                                  // 0 (false)
cout << q.top() << "\n";                                    // 5
q.pop();
cout << q.top() << "\n";                                    // 3
q.push(0);
q.push(4);
cout << q.top() << "\n";                                    // 4
struct Treap;
using PTreap = Treap*;

struct Treap{
    int key, pr;
    PTreap l, r;
    Treap() {}
    Treap(int key, int pr = random()) : key(key), pr(pr), l(nullptr), r(nullptr) {}
};

pair<PTreap, PTreap> split(PTreap t, int key){              // key попадает в правое дерево!
    if (!t) return {nullptr, nullptr};
    if (key <= t -> key){                                   // корень пойдёт направо
        auto [l, r] = split(t -> l, key);                   // поэтому разбиваем левое ДД
        t -> l = r;
        return {l, t};
    } else {                                                // корень пойдёт налево
        auto [l, r] = split(t -> r, key);                   // поэтому разбиваем правое ДД
        t -> r = l;
        return {t, r};
    }
}

PTreap merge(PTreap l, PTreap r){
    if (!l) return r;
    if (!r) return l;
    if (l -> pr > r -> pr){                                 // у первого ДД приоритет больше
        l -> r = merge(l -> r, r);                          // его левого сына не трогаем
        return l;
    } else {                                                // у второго ДД приоритет больше
        r -> l = merge(l, r -> l);                          // его правого сына не трогаем
        return r;
    }
}

PTreap find(PTreap t, int key){
    if (!t) return nullptr;
    if (t -> key == key) return t;
    if (t -> key < key) return find(t -> r, key);
    else return find(t -> l, key);
}

PTreap erase(PTreap t, int key){
    auto [l, m1] = split(t, key);
    auto [m2, r] = split(m1, key + 1);
    delete m2;
    return merge(l, r);
}

PTreap insert(PTreap t, PTreap val){
    if (find(t, val -> key)) return t;
    auto [l, r] = split(t, val -> key);
    return merge(merge(l, val), r);
}
PTreap treap = nullptr;                                     // создали пустое ДД
treap = insert(treap, new Treap(3));                        // добавили 3, имеем {3}
treap = insert(treap, new Treap(7));                        // добавили 7, имеем {3, 7}
treap = insert(treap, new Treap(5));                        // добавили 5, имеем {3, 5, 7} 
treap = insert(treap, new Treap(7));                        // 7 уже было, имеем {3, 5, 7}
treap = erase(treap, 7);                                    // удалили 7, имеем {3, 5}
