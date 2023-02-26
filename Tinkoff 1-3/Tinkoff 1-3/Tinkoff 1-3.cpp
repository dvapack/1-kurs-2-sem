#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	// бинарный поиск
	int s = 1;
	int e = n + 1;
	int m = 0; // просто элемент опорный
	string answer;
	while (s + 1 < e)
	{
		m = (s + e) / 2;
		cout << m << endl;
		fflush(stdout);
		cin >> answer;
		if (answer == "<")
			e = m;
		if (answer == ">=")
			s = m;
	}
	if (n == 1)
		cout << "! 1" << endl;
	if (answer == ">=")
	{
		cout << "! " << m << endl;
	}
	if (answer == "<")
	{
		cout << "! " << m - 1  << endl;
	}
}
