// -------------------- Ramez -------------------------
// سَأَحمِلُ روحي عَلى راحَتي    وَأُلقي بِها في مَهاوي الرَدى
// فَإِمّـا حَــيــاةٌ تُسِــرُّ الـصَديقَ    وَإِمّــا مَمــاتٌ يُغــيظُ العِــدى
// ----------------------------------------------------
// Contest: $(CONTEST)
// Judge: $(JUDGE)
// URL: $(URL)
// Memory Limit: $(MEMLIM)
// Time Limit: $(TIMELIM)
// Start: $(DATE) 
#include <cmath>
#include <functional>
#ifdef RAMEZ
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif
#include <bits/stdc++.h>
#define ll   long long
#define ull  unsigned ll
#define vi   vector<int>
#define vvi  vector<vi>
#define vll  vector<ll>
#define vvll vector<vll>
#define vs   vector<string>
#define pii  pair<int, int>
#define pll  pair<ll, ll>
using namespace std;
#define all(v)  v.begin(), v.end()
#define makeUnique(v)  v.erase(unique(all(v)), v.end())
vvll prefixSum2D(vvll& a); ll sumOfSquare(ll x1, ll y1, ll x2, ll y2, vvll& a); 
vll getDivisors(ll n); bool isPrime(ll n); vector<pll> getPrimeFactors(ll n); vll linearSeive(ll n);
ll add(ll a, ll b); ll mul(ll a, ll b); ll sub(ll a, ll b); ll divide(ll a, ll b);
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v);
template<typename T> istream& operator>>(istream& is, vector<T>& v);
void FastIO(); void UseFile();
const int MOD = 1000000007;

void solve(){

}

/*
NOTES:

*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}

void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& i : v) os << i << ' ';
    return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& v)
{
    for (auto& i : v) is >> i;
    return is;
}

vvll prefixSum2D(vvll& a) {
    vvll b(a.size(), vll(a[0].size()));
    for (int i = 0; i < a.size(); i++) {
        partial_sum(all(a[i]), b[i].begin());
    }
    for (int i = 0; i < a[0].size(); i++)
    {
        for (int j = 1; j < a.size(); j++)
        {
            b[j][i] += b[j - 1][i];
        }
    }
    return b;
}

ll sumOfSquare(ll x1, ll y1, ll x2, ll y2, vvll& a) {
    return (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1]) + a[x1 - 1][y1 - 1];
}

vll getDivisors(ll n){
  vll divs;
  for (ll i = 1; i*i <= n; i++) {
    if(n%i == 0) {
      divs.push_back(i);
      if(i*i != n) divs.push_back(n/i);
    }
  }
  return divs;
}

bool isPrime(ll n){
  if (n == 2) return true;
  if (n == 1 or n%2 == 0) return false;
  for (ll i = 3; i*i <= n; i += 2) {
    if(n%i == 0) return false;
  }
  return true;
}

vector<pll> getPrimeFactors(ll n){
  vector<pll> primeFactors;
  for (ll i = 2; i*i <= n; i++) {
    if(n%i == 0) {
      int count = 0;
      while(n%i == 0) n /= i, count++;
      primeFactors.push_back({i,count}); 
    } 
  }
  if(n > 1) primeFactors.push_back({n,1});
  return primeFactors;
}

ll add(ll a, ll b) {return ((a%MOD) + (b%MOD))%MOD;}
ll mul(ll a, ll b) {return ((a%MOD) * (b%MOD))%MOD;}
ll sub(ll a, ll b) {return ((((a%MOD) - (b%MOD))%MOD)+MOD)%MOD;}
ll divide(ll a, ll b) { return mul(a, pow(b, MOD-2)); }

vll linearSeive(ll n){
  vll isPr(n, 1); vll primes;
  isPr[0] = isPr[1] = 0;

  for (ll i = 2; i < n; i++) {
    if(isPr[i]) primes.push_back(i);
    for(ll p : primes){
      if(i * p >= n) break;
      isPr[i*p] = 0;
      if(i%p == 0) break;
    }
  }

  return primes;
}


class SegmentTree {
public:
    int size;
    vector<ll> sums, mins, maxs;

    SegmentTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, 0LL);
        mins.assign(2 * size, LLONG_MAX);
        maxs.assign(2 * size, LLONG_MIN);
    }

    void build(const vi& a) {
        build(a, 0, 0, size);
    }

    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }

    ll sumSeg(int l, int r) {
        return sumSeg(l, r, 0, 0, size);
    }

    ll minSeg(int l, int r) {
        return minSeg(l, r, 0, 0, size);
    }

    ll maxSeg(int l, int r) {
        return maxSeg(l, r, 0, 0, size);
    }

    ll firstElementAtLeastX(int x) {
        return firstElementAtLeastX(x, 0, 0, size);
    }

private:
    void build(const vi& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                sums[x] = a[lx];
                mins[x] = a[lx];
                maxs[x] = a[lx];
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
        maxs[x] = max(maxs[2 * x + 1], maxs[2 * x + 2]);
    }

    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = v;
            mins[x] = v;
            maxs[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            update(i, v, 2 * x + 1, lx, mid);
        }
        else {
            update(i, v, 2 * x + 2, mid, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
        maxs[x] = max(maxs[2 * x + 1], maxs[2 * x + 2]);
    }

    ll sumSeg(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return sums[x];
        int mid = (lx + rx) / 2;
        ll left = sumSeg(l, r, 2 * x + 1, lx, mid);
        ll right = sumSeg(l, r, 2 * x + 2, mid, rx);
        return left + right;
    }

    ll minSeg(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return LLONG_MAX;
        if (lx >= l && rx <= r) return mins[x];
        int mid = (lx + rx) / 2;
        ll left = minSeg(l, r, 2 * x + 1, lx, mid);
        ll right = minSeg(l, r, 2 * x + 2, mid, rx);
        return min(left, right);
    }

    ll maxSeg(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return LLONG_MIN;
        if (lx >= l && rx <= r) return maxs[x];
        int mid = (lx + rx) / 2;
        ll left = maxSeg(l, r, 2 * x + 1, lx, mid);
        ll right = maxSeg(l, r, 2 * x + 2, mid, rx);
        return max(left, right);
    }


    ll firstElementAtLeastX(int x, int currentNode, int l, int r) {
        if (maxs[currentNode] < x) {
            return -1;
        }

        if (r - l == 1) { // we're in the bottom of the tree
            return l;
        }

        int mid = (l + r) / 2;
        int res = firstElementAtLeastX(x, 2 * currentNode + 1, l, mid);
        if (res == -1) {
            res = firstElementAtLeastX(x, 2 * currentNode + 2, mid, r);
        }
        return res;
    }
};
