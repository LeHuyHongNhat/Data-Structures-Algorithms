#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        memset(dp, 0, sizeof(dp));
        int ans = 1;
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if (i < n - 1 && s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                ans = 2;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = 1;
                    ans = max(ans, len);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

