// L - R DP

#include <bits/stdc++.h>

using namespace std;

int n;
int x[10010];
int dp[1001][1001];

int rec(int l, int r) {
  // pruning 

  // basecase
  if (r - l == 1) {
    return 0;
  }
  // cache check 
  if (dp[l][r] != -1) {
    return dp[l[r]];
  }
  // compute
  int ans = 1e9;
  for (int p = l + 1, p < r; p++) {
    ans = min(ans, x[r] - x[l] + rec(l, p) + rec(p, r));
  }
  // save and 
  return dp[l][r] = ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  x[0] = 0;
  memset(dp, -1, sizeof(dp));
  cout << rec(0, n) << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
