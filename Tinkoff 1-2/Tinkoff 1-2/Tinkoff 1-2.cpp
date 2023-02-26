#include <iostream>
#include <vector>

using namespace std;

//found = false;
//s = 0;
//e = n_size;
//diff = 0;
//prev_diff = 0;
//prev_min = 0;
//do
//{
//	prev_diff = diff;
//	prev_min_diff = min_diff;
//	m = (s + e) / 2;
//	diff = abs(k[i] - n[m]);
//	diff < prev_diff ? min_diff = diff : min_diff = prev_min_diff;
//	if (!diff)
//	{
//		cout << n[m] << endl;
//		found = true;
//		break;
//	}
//	if (k[i] < n[m])
//	{
//		e = m;
//	}
//	if (k[i] > n[m])
//	{
//		s = m;
//	}
//	/*if (prev_diff == min_diff && prev_min >= n[m] && s + 1 >= e)
//	{
//		cout << prev_min << endl;
//		found = true;
//	}*/
//	if (prev_diff == min_diff && prev_min >= n[m])
//	{
//		cout << prev_min << endl;
//		found = true;
//	}
//	prev_min = n[m];
//} while (!found);

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
	long long e = n_size - 1;
	long long m; // просто элемент опорный
	bool found = false;
	for (long long i = 0; i < k_size; ++i)
	{
		found = false;
		s = 0;
		e = n_size - 1;
		while(s + 1 < e)
		{
			m = (s + e) / 2;
			if (k[i] == n[m])
			{
				cout << n[m] << endl;
				found = true;
				break;
			}
			if (k[i] < n[m])
			{
				e = m;
			}
			if (k[i] > n[m])
			{
				s = m;
			}
		}
		if (!found)
		{
			if (abs(k[i] - n[s]) <= abs(k[i] - n[e]))
				cout << n[s] << endl;
			else
				cout << n[e] << endl;
		}
	}
}