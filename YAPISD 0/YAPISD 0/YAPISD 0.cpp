#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    int a;
    int b;
    fstream fin("Input.txt");
    fin >> a >> b;
    fin.close();
    fstream fout("Output.txt", ios::out);
    fout << a + b;
    fout.close();
}
