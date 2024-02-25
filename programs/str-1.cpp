vector<int> zf(string s) {
    int n = s.size(), l = 0, r = 0;
    vector<int> z(n);
    z[0] = 0;
    for(int i = 1; i < n; ++i) {
        if (i > r) z[i] = 0;
        else {
            int j = i - l;
            z[i] = min(z[j], r - i);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) l = i, r = i + z[i];
    }
    return z;
}
vector<int> pf(string s){
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for(int i = 1; i < n; ++i){
        int j = p[i - 1];
        while(j > 0 && s[j] != s[i]) j = p[j - 1];
        if (s[i] == s[j]) ++j;
        p[i] = j;
    }
    return p;
}
