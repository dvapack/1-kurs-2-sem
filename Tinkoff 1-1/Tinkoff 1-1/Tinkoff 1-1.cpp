#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long n_size, k_size;
	cin >> n_size;
	cin >> k_size;
	vector <long long> n(n_size);
	vector <long long> k(k_size);
	for (long long i = 0; i < n_size; ++i)
	{
		cin >> n[i];
	}
	for (long long i = 0; i < k_size; ++i)
	{
		cin >> k[i];
	}
	// бинарный поиск
	long long s = 0;
	long long e = n_size;
	long long m; // просто элемент опорный
	bool flag = false;
	for (long long i = 0; i < k_size; ++i)
	{
		flag = false;
		s = 0;
		e = n_size;
		while (s + 1 <= e)
		{
			m = (s + e) / 2;
			if (k[i] == n[m])
			{
				cout << "YES" << endl;
				flag = true;
				break;
			}
			if ((k[i] < n[m + 1]) && (k[i] >= n[s]))
				e = m;
			if ((k[i] > n[m]) && (k[i] <= n[n_size - 1]))
				s = m;
			if (!s && e != m)
				break;
		}
		if (!flag)
			cout << "NO" << endl;
	}
}

