#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

long long n = 0;		//矿石个数
long long m = 0;		//区间个数
long long s = 0;		//标准值
long long ret = 0;
vector<long long> v;
vector<long long> w;
vector<long long> l;
vector<long long> r;

bool check(long long mid)
{
	vector<long long> qz1(n + 1, 0);	//布尔前缀和
	vector<long long> qz2(n + 1, 0);	//价值前缀和
	ret = 0;

	for (int i = 1; i <= n; i++)
	{
		if (w[i] >= mid)
		{
			qz1[i] = qz1[i - 1] + 1;
			qz2[i] = qz2[i - 1] + v[i];
		}
		else
		{
			qz1[i] = qz1[i - 1];
			qz2[i] = qz2[i - 1];
		}
	}

	for (int i = 1; i <= m; i++)
	{
		long long lll = l[i];
		long long rrr = r[i];
		ret += (qz2[rrr] - qz2[lll - 1]) * (qz1[rrr] - qz1[lll - 1]);
	}

	if (ret > s)
	{
		return true;
	}
	else
	{
		return false;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> s;
	v.resize(n + 1, 0);
	w.resize(n + 1, 0);
	l.resize(m + 1, 0);
	r.resize(m + 1, 0);
	long long count = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
		cin >> v[i];
	}

	count = 1;
	for (int i = 1; i <= m; i++)
	{
		cin >> l[i];
		cin >> r[i];
	}

	long long left = 0;
	long long right = LLONG_MAX;
	long long ans = LLONG_MAX;
	while (left <= right)
	{
		long long mid = left + (right - left) / 2;
		if (check(mid))
		{
			left = mid + 1;
			ans = min(ans, llabs(s - ret));
		}
		else
		{
			right = mid - 1;
			ans = min(ans, llabs(s - ret));
		}
	}

	cout << ans << endl;
	return 0;
}