#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool search(double& end, int& a, int& b, int& c, int& d)
{
	if ((a * end * end * end + b * end * end + c * end + d) > 0)
		return true;
	if ((a * end * end * end + b * end * end + c * end + d) == 0)
		return true;
	if ((a * end * end * end + b * end * end + c * end + d) < 0)
		return false;
}

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	double left = -1.;
	double right = 1.25;
	double m = 0;
	while (search(left, a, b, c, d) == search(right, a, b, c, d))
	{
		left *= 2.;
		right *= 2;
	}
	if (a > 0)
	{
		while (right - left > 0.00009)
		{
			m = (left + right) / 2.;
			if (a * m * m * m + b * m * m + c * m + d > 0.)
				right = m;
			if (a * m * m * m + b * m * m + c * m + d < 0.)
				left = m;
		}
	}
	if (a < 0)
	{
		while (right - left > 0.00009)
		{
			m = (left + right) / 2.;
			if (a * m * m * m + b * m * m + c * m + d > 0.)
				left = m;
			if (a * m * m * m + b * m * m + c * m + d < 0.)
				right = m;
		}
	}
	cout << fixed << setprecision(15) << m << endl;
}