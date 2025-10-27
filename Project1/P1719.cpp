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
	cin >> n;
	vector <vector<int>> v(n + 1, vector<int>(n + 1, 0));		//m*n矩阵
	vector <vector<int>> sum(n + 1, vector<int>(n + 1, 0));
	vector <vector<int>> sub(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> v[i][j];
			sub[i][j] = sub[i][j-1] + v[i][j];
			sum[i][j] = sub[i][j] + sum[i - 1][j];
		}
	}

	long long area = -99999999;
	for (int x1 = 1; x1 <= n; x1++)
	{
		for (int y1 = 1; y1 <= n; y1++)
		{
			for (int x2 = 1; x2 <= n; x2++)
			{
				for (int y2 = 1; y2 <= n; y2++)
				{
					if (x2 < x1 || y2 < y1)
					{
						continue;
					}
					else
					{
						long long temp = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
						area = max(area, temp);
					}
				}
			}
		}
	}

	cout << area << endl;
	return 0;
}