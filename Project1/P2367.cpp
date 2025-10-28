#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class p2367
{
public:
	vector<int> v;
	vector<int> diff;
	vector<int> ans;
	int n;
	int p;

	void set()
	{
		cin >> n >> p;
		v.resize(n + 1, 0);
		diff.resize(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
		}

		for (int i = 1; i <= n; i++)
		{
			diff[i] = v[i] - v[i - 1];		//差分
		}
	}

	void add()
	{
		for (int i = 1; i <= p; i++)
		{
			int x = 0;
			int y = 0;
			int z = 0;
			cin >> x >> y >> z;
			diff[x] += z;
			if (y != n)
			{
				diff[y + 1] -= z;
			}
			else
			{
				continue;
			}
		}
	}

	void total()
	{
		int temp = 0;
		for (int i = 1; i <= n; i++)
		{
			temp += diff[i];
			ans.push_back(temp);
		}
	}

	void output()
	{
		sort(ans.begin(), ans.end());
		cout << ans[0] << endl;
	}

};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	p2367 p;
	p.set();
	p.add();
	p.total();
	p.output();

	return 0;
}