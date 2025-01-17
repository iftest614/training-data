#include<bits/stdc++.h>
#define ll long long
#define N 10000005
#define mod 1000000007
int n, l, r, fac[N], inv[N], tot, ans;
bool vis[N];

int A[] = {
682498929,491101308,76479948,723816384,67347853,27368307,625544428,199888908,888050723,927880474,281863274,
661224977,623534362,970055531,261384175,195888993,66404266,547665832,109838563,933245637,724691727,368925948,
268838846,136026497,112390913,135498044,217544623,419363534,500780548,668123525,128487469,30977140,522049725,
309058615,386027524,189239124,148528617,940567523,917084264,429277690,996164327,358655417,568392357,780072518,
462639908,275105629,909210595,99199382,703397904,733333339,97830135,608823837,256141983,141827977,696628828,
637939935,811575797,848924691,131772368,724464507,272814771,326159309,456152084,903466878,92255682,769795511,
373745190,606241871,825871994,957939114,435887178,852304035,663307737,375297772,217598709,624148346,671734977,
624500515,748510389,203191898,423951674,629786193,672850561,814362881,823845496,116667533,256473217,627655552,
245795606,586445753,172114298,193781724,778983779,83868974,315103615,965785236,492741665,377329025,847549272,698611116 };
#define M 10000000
int FAC (int n)
{
	if (n <= M) return fac[n];
	int res = A[n / M - 1];
	for (int i = (n / M) * M + 1; i <= n; i++) res = 1ll * res * i % mod;
	return res;
}

ll Pow (ll x, ll k)
{
	ll t = 1;
	for (; k; k >>= 1, x = x * x % mod) if (k & 1) t = t * x % mod;
	return t;
}

int C (int a, int b)
{
	if (a <= M) return 1ll * fac[a] * inv[b] % mod * inv[a - b] % mod;
	else return 1ll * FAC (a) * Pow (FAC (b), mod - 2) % mod * Pow (FAC (a - b), mod - 2) % mod;
}


int main ()
{
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	scanf ("%d%d", &l, &r), n = r - l + 1;
	if (n > 1e7)
	{
		std::cout << 1ll * n * (n - 1) / 2 % mod * FAC (n - 1) % mod;		
		return 0;
	}
	for (int i = l; i <= r; i++) if (!vis[i - l])
	{
		tot++;
		for (int j = i + i; j <= r; j += i) vis[j - l] = 1;
	}
	fac[0] = inv[0] = inv[1] = 1;
	for (int i = 1; i <= M; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	for (int i = 2; i <= M; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 2; i <= M; i++) inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
	for (int i = tot; i <= n; i++) ans = (ans + 1ll * C (i - 1, tot - 1) * i % mod);
	std::cout << 1ll * ans *fac[tot] % mod * fac[n - tot] % mod << "\n";
}
/*
1000000000 1000000018
*/