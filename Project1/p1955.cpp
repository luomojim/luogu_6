#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class union_tree
{
public:
	vector <long long> parent;
	vector <long long> level;
	long long count;

	//初始化并查集树
	union_tree(long long n) : count(n)
	{
		parent.resize(n, 0);
		level.resize(n, 0);
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
		}
	}

	//查找父节点
	long long union_find(long long x)
	{
		if (parent[x] != x)
		{
			parent[x] = union_find(parent[x]);
		}
		return parent[x];
	}

	//合并并查集
	void merge_uniontree(long long x ,long long y)
	{
		long long root_x = union_find(x);
		long long root_y = union_find(y);

		if (root_x == root_y)
		{
			return;
		}

		if (level[root_x] > level[root_y])
		{
			parent[root_x] = root_y;
		}
		else if (level[root_x] < level[root_y])
		{
			parent[root_y] = root_x;
		}
		else
		{
			parent[root_x] = root_y;
			level[root_x]++;
		}
		count--;
	}

	//查找回环
	bool find_connect(long long x,long long y)
	{
		return union_find(x) == union_find(y);
	}
};

class p1955
{
public:
	long long n = 0;
	long long check_num = 0;  //要查找的数量
	long long i, j, e;	//xi, xj , 是否相等
	long long length = 0;	//相等数组的长度
	bool legal = true;
	vector <long long> arr;
	vector <long long> check;
	union_tree* un = nullptr;

	void hash_map(vector <long long>& arr , vector <long long>& check)
	{
		vector <long long> temp(arr);
		for (int i = 0; i < check.size(); i++)
		{
			temp.push_back(check[i]);
		}
		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()), temp.end());
		for (long long& a : arr)
		{
			a = lower_bound(temp.begin(), temp.end(), a) - temp.begin();
		}

		for (long long& a : check)
		{
			a = lower_bound(temp.begin(), temp.end(), a) - temp.begin();
		}
	}
	
	void set()
	{
		cin >> n;
		while (n--)
		{
			cin >> i >> j >> e;
			//把i和j映射到新的空间里面
			if (e == 1)
			{
				arr.push_back(i);
				arr.push_back(j);
			}
			else if (e == 0)
			{
				check_num++;
				check.push_back(i);
				check.push_back(j);
			}
		}

		length = arr.size();
		hash_map(arr,check);		//离散化坐标点
		
		long long max_index = 0;
		for (long long a : arr) max_index = max(max_index, a);
		for (long long c : check) max_index = max(max_index, c);
		un = new union_tree(max_index * 2 + 2);


		for (int i = 0; i < length - 1;)
		{
			if (!un->find_connect(arr[i], arr[i + 1]))
			{
				un->merge_uniontree(arr[i], arr[i + 1]);
			}
			i += 2;
		}
	}

	void process()
	{
		if (check.size() == 0)
		{
			return;
		}
		for (int i = 0; i < check.size() - 1;)
		{
			if (un->find_connect(check[i], check[i + 1]))
			{
				legal = false;
				break;
			}
			i += 2;
		}
	}

	void output()
	{
		cout << ((legal == true) ? "YES" : "NO") << endl;
	}

	void clear_all()
	{
		n = 0;
		check_num = 0;  //要查找的数量
		i = 0;
		j = 0;
		e = 0;	//xi, xj , 是否相等
		length = 0;	//相等数组的长度
		legal = true;
		arr.clear();
		check.clear();

		//un->parent.clear();
		//un->level.clear();
		//un->count = 0;
		if (un != nullptr)
		{
			delete un;
			un = nullptr;
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	p1955 p;
	int t = 0;
	cin >> t;
	while (t--)
	{
		p.set();
		p.process();
		p.output();
		p.clear_all();
	}
	
	return 0;
}