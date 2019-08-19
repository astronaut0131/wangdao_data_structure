#include <iostream>
#include <vector>
using namespace std;
void move_odd_forward(vector<int> &array) {
	int left = 0;
	while (left < array.size() && array[left] % 2 != 0) left++;
	int i = left+1;
	for (;i < array.size(); i++) {
		if (array[i] % 2 != 0) {
			swap(array[i],array[left]);
			while (left < array.size() && array[left] % 2 != 0) left++;
		}
	}
}
void move_odd_forward2(vector<int> &array) {
	int i = 0, j = array.size()-1;
	while (i < j) {
		while (i < array.size() && array[i] % 2 != 0) i++;
		while (j >= 0 && array[j] % 2 == 0) j--;
		swap(array[i],array[j]);
		i++,j--;
	}
}
int main() {
	vector<int> a = {1,2,3,4,5,6,7,8,9};
	auto b = a;
	move_odd_forward(a);
	for (auto i : a) {
		cout << i << " ";
	}
	cout << endl;
	move_odd_forward2(b);
	for (auto i : b) {
		cout << i << " ";
	}
	return 0;
}