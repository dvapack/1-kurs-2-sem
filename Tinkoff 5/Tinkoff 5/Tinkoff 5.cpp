#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

long long San(long long number) {
	long long sum;
	sum = (number * (number + 1)) / 2;
	return sum;
}

vector<long long> number_split(long long number) {
	vector<long long> splitted_number;
	for (long long i = number; i > 0; --i) {
		splitted_number.push_back(i);
	}
	return splitted_number;
}



int main() {
	vector<long long> splitted_number;
	long long number;
	long long sum;
	cin >> number;
	if (((number + 1) % 3 == 0) && (number >= 5)) {/// !!!!!!!!!!!!!!!!!!!!!!!
		sum = San(number);
		splitted_number = number_split(number);
		sum /= 3; // 12
		long long k = 0;
		vector<long long> used_elements;
		while (number > 0) {	//ПОка не уберем все элементы
			vector<long long> plenty;
			long long element_sum = 0;	//Сумма для элементов
			while ((k + 1 < splitted_number.size()) && (element_sum + splitted_number[k + 1]) < sum) {
				if (find(used_elements.begin(), used_elements.end(), splitted_number[k]) == used_elements.end()) {
					element_sum += splitted_number[k];
					plenty.push_back(splitted_number[k]);
					used_elements.push_back(splitted_number[k]);
				}
				--number;
				++k;
			}
		long long difference = sum - element_sum;
			if ((element_sum != sum) && find(used_elements.begin(), used_elements.end(), difference) == used_elements.end()) {
				plenty.push_back(difference);
				used_elements.push_back(difference);
				--number;
			}
			cout << plenty.size() << endl;
			for (long long i = 0; i < plenty.size(); i++) {
				cout << plenty[i] << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "-1" << endl;
	}
}