#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n = 0;
	int m = 0;
	int c = 0;
	cin >> n >> m >> c;
	vector <vector<long long>> v(n+1, vector<long long>(m+1, 0));
	vector <vector<long long>> add(n + 1, vector<long long>(m + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> v[i][j];
			add[i][j] += add[i][j - 1] + v[i][j] + add[i - 1][j] - add[i - 1][j - 1];		//从00到ij的面积和
		}
	}
	
	long long ans = -1e9;
	long long x = 0;
	long long y = 0;
	for (int i = 1; i + c - 1<= n; i++)
	{
		for (int j = 1; j + c - 1<= m; j++)
		{
			long long x1, y1, x2, y2;
			x1 = j - 1;
			y1 = i - 1;
			x2 = j + c - 1;
			y2 = i + c - 1;
			long long temp = add[y2][x2] + add[y1][x1] - add[y1][x2] - add[y2][x1];
			ans = max(temp, ans);
			if (ans == temp)
			{
				x = i;
				y = j;
			}
		}
	}

	cout << x << ' ' << y << endl;
	return 0;
}