#include <iostream>
#include<vector>
#include"header.h"
using namespace std;

int main()
{
	vector<vector<int> > test = {
		{1,2,3,2,1,3},
		{3,4,3,1,2,3},
		{5,6,5,7,9,6},
		{6,5,9,8,8,9},
		{8,7,9,6,1,3}
	};
	two_dimension_fenvick_tree fenvick2(test);
	cout << fenvick2;

	cout << "\n Two dimension prefix sum : " << fenvick2.prefix_sum(2, 2);

	cout << "\n Two dimension sum on the interval: " << fenvick2.interval_sum(1, 1, 3, 3);

	cout << "\n-------------------------------\n";

	vector<int> array = { 5,6,3,1,2 };


	one_dimensional_fenvick_tree my_fenvick(array);

	cout << my_fenvick;

	cout << "\nPrefix sum: " << my_fenvick.prefix_sum(2) << endl;

	cout << "\nSum on the interval: " << my_fenvick.interval_sum(2, 4) << endl;

	cout << "\n-------------------------------\n";


	vector<int> array1 = { 5,6,3,1,2 };
	pending_one_dimensional_fenvick_tree my_fenvick1(array1);

	cout << my_fenvick1;

	cout << "\nPrefix sum: " << my_fenvick1.prefix_sum(2) << endl;

	cout << "\nSum on the interval: " << my_fenvick1.interval_sum(2, 4) << endl;

	system("pause");
	return 0;
}