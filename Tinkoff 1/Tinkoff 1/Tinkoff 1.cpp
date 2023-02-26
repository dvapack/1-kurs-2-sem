#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int length;
	cin >> length;
	if (length % 3)
		cout << 0;
	else
		cout << (int)pow(2, length/3);
}