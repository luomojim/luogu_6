#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class p3397
{
public:
	int n;
	int m;
	vector <vector<int>> diff;
	vector <vector<int>> ans;

	void set()
	{
		cin >> n >> m;
		diff.resize(n + 1, vector<int>(n + 1, 0));
		ans.resize(n + 1, vector<int>(n + 1, 0));
	}

	void caculate()
	{
		int x1, x2, y1, y2;
		for (int i = 1; i <= m; i++)
		{
			cin >> y1 >> x1 >> y2 >> x2;
			for (int y = y1; y <= y2; y++)
			{
				diff[y][x1]++;
				if (x2 != n)
				{
					diff[y][x2 + 1]--;
				}
				else
				{
					continue;
				}
			}
		}
	}

	void add()
	{
		int temp = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				temp += diff[i][j];
				ans[i][j] = temp;
			}
			temp = 0;
		}
	}

	void output()
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << ans[i][j] << ' ';
			}
			cout << endl;
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	p3397 p;

	p.set();
	p.caculate();
	p.add();
	p.output();

	return 0;
}