#include <iostream>
#include <vector>

using namespace std;


void input(long long& size, vector<long long>& vec)
{
	cin >> size;
	vec.resize(size);
	for (long long i = 0; i < size; ++i)
	{
		cin >> vec[i];
	}
}

vector<long long> merge(long long& size, long long& counter, vector<long long> vec_a, vector<long long> vec_b)
{
	long long left_a = 0;
	long long left_b = 0;
	vector <long long> sorted;
	if (!vec_a.size())
		return vec_b;
	if (!vec_b.size())
		return vec_a;
	while (left_a + left_b < vec_a.size() + vec_b.size())
	{
		if (left_b == vec_b.size() && left_a != vec_a.size())
		{
			sorted.push_back(vec_a[left_a]);
			++left_a;
			counter += left_b;
		}
		if (left_a == vec_a.size() && left_b != vec_b.size())
		{
			sorted.push_back(vec_b[left_b]);
			++left_b;
		}
		if (left_b != vec_b.size() && left_a != vec_a.size() && vec_a[left_a] <= vec_b[left_b])
		{
			sorted.push_back(vec_a[left_a]);
			++left_a;
			counter += left_b;
		}
		if (left_b != vec_b.size() && left_a != vec_a.size() && vec_a[left_a] > vec_b[left_b])
		{
			sorted.push_back(vec_b[left_b]);
			++left_b;
			
		}
	}
	return sorted;
}

vector<long long> sorting(long long& size, long long& counter, vector<long long> vec)
{
	auto first = vector<long long>(vec.begin(), vec.begin() + (long long)(vec.size() / 2));
	auto second = vector<long long>(vec.begin() + (long long)(vec.size() / 2), vec.end());
	if (first.size() > 0 && second.size() > 0)
		return merge(size, counter, sorting(size, counter, first), sorting(size, counter, second));
	else
		return vec;
}



void output(long long& counter, vector<long long> sorted)
{
	cout << counter << endl;
	for (long long i = 0; i < sorted.size(); ++i)
	{
		cout << sorted[i] << ' ';
	}
}

int main()
{
	long long size;
	long long counter = 0;
	vector <long long> vec;
	vector <long long> sorted;
	input(size, vec);
	output(counter, sorting(size, counter, vec));
}