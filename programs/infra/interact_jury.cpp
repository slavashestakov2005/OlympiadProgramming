#include <bits/stdc++.h>
using namespace std;
int main() {
    int secret = 123;
    while (true) {
        int n;
        cin >> n;
	cerr << "Jury: got=" << n << endl;
	char ans;
        if (n == secret) ans = '=';
        else if (n > secret) ans = '<';
        else ans = '>';
	cerr << "Jury: ans=" << ans << endl;
	cout << ans << endl;
	if (ans == '=') break;
    }
    return 0;
}
