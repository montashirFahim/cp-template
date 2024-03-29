#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

const ll MX = 2e6;

ll fac[MX + 5];

void pre() {
	fac[0] = 1;
	for (ll i = 1; i <= MX; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
	}
}

ll bixpo(ll base, ll p) {
	ll ans = 1LL;
	while (p) {
		if (p & 1) {
			ans *= base;
			ans %= mod;
			p--;
		} else {
			base *= base;
			base %= mod;
			p /= 2;
		}
	}
	return ans % mod;
}

ll inv(ll v) {
	return bixpo(v, mod - 2);
}

ll nCr(ll N, ll R) {

	if (R == 0)return 1;
	if (R > N)return 0;

	ll a = fac[N];
	ll b = inv(fac[R]);
	ll c = inv(fac[N - R]);

	// cout << a << " " << b << " " << c << endl;
	ll ans = (a * b) % mod;
	ans = (ans * c) % mod;

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	pre();

	ll n, m;
	cin >> n >> m;

	cout << nCr(n + m - 1, n - 1) << '\n';


}
