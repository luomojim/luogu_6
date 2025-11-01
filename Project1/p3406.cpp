#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct price
{
	long long pricea = 0;
	long long priceb = 0;
	long long pricec = 0;
};

int main()
{
	int n = 0;
	int m = 0;
	long long total = 0;
	cin >> n >> m;		//9 10
	vector<long long> p(m+1,0);			//旅行地点
	vector<long long> diff(n + 2, 0);	//差分数组，计算次数
	vector<long long> times(n + 1, 0);	//计算次数
	//vector<long long> add(m + 1, 0);	//前缀和
	vector<price> v;					//价格
	for (int i = 1; i <= m; i++)
	{
		cin >> p[i];
	}

	for (int i = 1; i <= n - 1; i++)
	{
		price temp;
		cin >> temp.pricea >> temp.priceb >> temp.pricec;
		v.push_back(temp);
	}

	
	bool change = false;
	for (int i = 1; i < m; i++)		//m-1 = 9
	{
		int start = min(p[i + 1], p[i]);
		int end = max(p[i + 1], p[i]);

		diff[start]++;
		diff[end]--;
	}

	for (int i = 1; i <= n; i++)
	{
		times[i] = times[i - 1] + diff[i];
	}

	for (int i = 1; i <= n - 1; i++)
	{
		long long with_ic = v[i - 1].priceb * times[i] + v[i - 1].pricec;
		long long no_ic = v[i - 1].pricea * times[i];

		total += min(with_ic, no_ic);
	}

	cout << total << endl;

	return 0;
}