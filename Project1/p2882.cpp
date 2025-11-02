#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	std::cout.tie(nullptr);
	long long n = 0;
	long long k = INT_MAX;
	cin >> n;
	vector <char> front(n+1, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> front[i];
	}

	long long count = 0;
	for (int i = 0; i < n;)
	{
		long long temp_k = 0;
		while (front[i] == 'B')
		{
			front[i] = 'F';
			temp_k++;
			if (front[i + 1] == 'F')
			{
				front[i + 1] = 'B';
				temp_k++;
				break;
			}
			i++;
		}
		k = min(k, temp_k);
		count++;
		while (front[i] == 'F')
		{
			i++;
		}

	}

	std::cout << k << ' ' << count << endl;

	return 0;
}