#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

long long sim(vector<long long> &a, int s, int d) {
  long long ans = 0, acc = 0;
  for (int i = 0; i < a.size(); ++i) {
    acc += a[s];
    if (acc != 0) ans++;
    s += d;
    if (s < 0) s += a.size();
    s %= a.size();
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  srand(time(0));
  int n;
  while (cin >> n) {
    vector<long long> a(n);
    int start = 0, seen = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] != 0 && !seen) {
        start = i;
        seen = true;
      }
    }
    long long best = min(sim(a, start, 1), sim(a, start, -1));
    int mp = 555;
    while (mp--) {
      best = min(best, sim(a, rand() % n, -1));
      best = min(best, sim(a, rand() % n, 1));
    }
    cout << best << endl;
  }
  return 0;
}
