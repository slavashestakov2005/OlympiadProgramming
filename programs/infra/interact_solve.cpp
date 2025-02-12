#include <bits/stdc++.h>
using namespace std;
int main() {
    int l = -1, r = 1001;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        cerr << "Solve: ask=" << m << endl;
	cout << m << endl;
        char ans;
        cin >> ans;
	cerr << "Solve: got=" << ans << endl;
        if (ans == '=') break;
        else if (ans == '<') r = m;
        else l = m;
    }
    return 0;
}
