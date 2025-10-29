#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class p1496
{
public:
	int n = 0;
	long long ans = 0;
	vector <long long> v1;
	vector <long long> v2;

	void set()
	{
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a;
			cin >> b;
			v1.push_back(a);
			v2.push_back(b);
		}
	}

	void find()
	{
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		for (int i = 0; i < n; i++)
		{
			ans += v2[i] - v1[i];
			if (i + 1 < n)
			{
				if (v2[i] > v1[i + 1])
				{
					ans -= v2[i] - v1[i + 1];
				}
			}
		}
	}

	void output()
	{
		cout << ans << endl;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	p1496 p;

	p.set();
	p.find();
	p.output();

	return 0;
}