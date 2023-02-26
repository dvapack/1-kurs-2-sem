#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double C;
	cin >> C;
	// бинарный поиск
	double s = 0.;
	double e = C;
	double m = 0.; // просто элемент опорный
	while (e - s > 0.0000001)
	{
		m = (s + e) / 2.;
		if ((pow(m, 2.) + sqrt(m + 1.)) - C >= 0.000000001)
			e = m;
		if (pow(m, 2.) + sqrt(m + 1.) - C < 0.000000001)
			s = m;
	}
	cout << fixed << setprecision(9) << m << endl;
}
