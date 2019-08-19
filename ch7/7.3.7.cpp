#include <iostream>
#include <vector>
using namespace std;
void arrage_flag(vector<int> &v) {
	int low = 0, high = v.size()-1;
	int j = 0;
	while (j <= high) {
		if (v[j] == 0) {
			swap(v[j],v[low++]);
			j++;
		} else if (v[j] == 2) {
			swap(v[j],v[high--]);
		} else {
			j++;
		}
	}
}
int main() {
	vector<int> v{0,1,1,2,2,0,1,1,2,2,0,0,1,1};
	arrage_flag(v);
	for (auto i:v) cout << i << " "; 
	return 0;
}