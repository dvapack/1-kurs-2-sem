#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void input(int& n)
{
	cin >> n;
}

void not_fast(int& n, vector<int>& vec)
{
	if (n < 5)
		for (int i = 0; i < n; ++i)
			vec[i] = i + 1;
	if (n >= 5)
	{
		for (int i = 0; i < n; ++i)
			vec[i] = i + 1;
		for (int i = 5; i <= n; ++i)
		{
			if (i % 2 == 0)
				swap(vec[i / 2 - 1], vec[i - 1]);
			if (i % 2 != 0)
				swap(vec[i / 2], vec[i - 1]);
		}
	}
}


int main()
{
	int n;
	input(n);
	vector <int> vec(n);
	not_fast(n, vec);
	for (auto& s : vec)
		cout << s << ' ';
}
