// caching across the queries and printing (target sum subset)

#include <bits/stdc++.h>

using namespace std;

int rec(int level, int left) {
	// pruning 
	if (left < 0) {
		return 0;
	}
	// basecase
	if (level == n + 1) {
		if (left == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	// cache check
	if (dp[level][left] != -1) {
		return dp[level][left];
	}
	// compute
	int ans = 0;
	if (rec(level + 1, left) == 1) {
		ans = 1;
	}
	else if (rec(level + 1, left - x[level])) {
		ans = 1;
	}
	// save and return
	return dp[level][left] = ans;
}

void printset(int level, int left) {
	if (level == n + 1) {
		return;
	}
	if (rec(level + 1, left) == 1) {
		printset(level + 1, left);
	}
	else if (rec(level + 1, left - x[level])) {
		cout << x[level] << " ";
		printset(level + 1, left - x[level]); 
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	int q;
	cin >> q;
	while (q--) {
		cin >> t;
		if (rec(1, t)) {
			printset(1, t);
		}
		else {
			cout << "no solution";
		}
		cout << "\n";
	}
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
