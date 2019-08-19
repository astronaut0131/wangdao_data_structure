#include <iostream>
#include <vector>
using namespace std;
template <class T>
void bubble_sort(vector<T>& array) {
	bool has_swap = true;
	int low = 0, high = array.size()-1;
	while (low < high && has_swap) {
		has_swap = false;
		for (int j = low; j < high; j++) {
			if (array[j] > array[j+1]) {
				swap(array[j],array[j+1]);
				has_swap = true;
			}
		}
		high--;
		for (int j = high; j > low; j--) {
			if (array[j] < array[j-1]) {
				swap(array[j],array[j-1]);
				has_swap = true;
			}
		}
		low++;
	}
}

int main() {
	vector<int> a = {1,2,3,7,6,5,9,8,0};
	bubble_sort(a);
	for (auto i : a) 
		cout << i << " ";
	return 0;
}