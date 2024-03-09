struct FenwickTree2D {
    vector<vector<int>> t;
    int n, m;

    FenwickTree2D(int _n, int _m) : n(_n + 1), m(_m + 1) {
        t.assign(n, vector<int>(m, 0));
    }

    void add(int x, int y, int d) {
        for (int i = x; i < n; i += i & -i) {
            for (int j = y; j < m; j += j & -j) {
                t[i][j] += d;
            }
        }
    }

    int sum(int x, int y) {
        int result = 0;
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                result += t[i][j];
            }
        }
        return result;
    }

    int sum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) + sum(x1 - 1, y1 - 1) - sum(x1 - 1, y2) - sum(x2, y1 - 1);
    }
};
#define FOR(i, n) for (int i = 0; i < n; ++i)
struct SparseTable2D {
    vector<vector<vector<vector<int>>>> v;          //  размер n × m × log_n × log_m
    int n, m, log_n, log_m;

    SparseTable2D(int _n, int _m) : n(_n), m(_m) {
        log_n = __lg(n) + 1;
        log_m = __lg(m) + 1;
        v.assign(n, vector<vector<vector<int>>>(m,
                        vector<vector<int>>(log_n, vector<int>(log_m))));
    }

    void build(vector<vector<int>> a){
        FOR(i, n) FOR(j, m) {
            v[i][j][0][0] = a[i][j];
        }
        FOR(i, n) FOR(lnj, log_m - 1) FOR(j, m - (1 << lnj)) {
            v[i][j][0][lnj + 1] = min(v[i][j][0][lnj], v[i][j + (1 << lnj)][0][lnj]);
        }
        FOR(lni, log_n - 1) FOR(i, n - (1 << lni)) FOR(lnj, log_m) FOR(j, m) {
            v[i][j][lni + 1][lnj] = min(v[i][j][lni][lnj], v[i + (1 << lni)][j][lni][lnj]);
        }
    }

    int get_min(int x1, int y1, int x2, int y2) {
        int lgx = __lg(x2 - x1 + 1);
        int lgy = __lg(y2 - y1 + 1);
        int ans1 = v[x1][y1][lgx][lgy];
        int ans2 = v[x2 - (1 << lgx) + 1][y1][lgx][lgy];
        int ans3 = v[x1][y2 - (1 << lgy) + 1][lgx][lgy];
        int ans4 = v[x2 - (1 << lgx) + 1][y2 - (1 << lgy) + 1][lgx][lgy];
        return min(min(ans1, ans2), min(ans3, ans4));
    }
};
