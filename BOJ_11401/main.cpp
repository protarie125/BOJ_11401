#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

constexpr auto MOD = ll{ 1'000'000'007 };

ll N, K;

ll fact(ll n) {
	auto ans = ll{ 1 };
	for (auto i = 2LL; i <= n; ++i) {
		ans *= i;
		ans %= MOD;
	}

	return ans;
}

ll pow(ll a, ll b) {
	if (0 == b) {
		return 1LL;
	}

	if (1 == a) {
		return 1LL;
	}

	if (0 == b % 2) {
		const auto q = pow(a, b / 2);
		return (q * q) % MOD;
	}

	const auto q = pow(a, (b - 1) / 2);
	const auto qq = (q * q) % MOD;
	return (a * qq) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> N >> K;
	const auto Nf = fact(N);
	const auto Kf = fact(K);
	const auto Bf = fact(N - K);
	const auto d1 = (Kf * Bf) % MOD;
	const auto denom = pow(d1, MOD - 2);

	cout << (Nf * denom) % MOD;

	return 0;
}