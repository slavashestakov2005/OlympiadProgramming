vector<int> zf(string s){
    int n = s.size(), l = 0, r = 0;
    vector<int> z(n);
    z[0] = 0;
    for(int i = 1; i < n; ++i){
        z[i] = 0;
        if (l <= i && i <= r) z[i] = z[i - l];
        if (z[i] + i > r) z[i] = r - i - 1;
        if (z[i] < 0) z[i] = 0;
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
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
