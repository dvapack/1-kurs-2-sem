#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int cars;
    cin >> cars;
    vector <int> speeds(cars);
    for (int i = 0; i < cars; ++i)
    {
        cin >> speeds[i];
        if (i && speeds[i] > speeds[i - 1])
            speeds[i] = speeds[i-1];
    }
    for (int i = 0; i < cars; ++i)
    {
        cout << speeds[i] << ' ';
    }
}