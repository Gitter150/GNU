#include <iostream>
#include <vector>

void insertInSortedOrder(std::vector<int>& arr, int n) {
	if(arr.size() == 0) {
		arr.push_back(n);
		return;
	}
	int low = 0, high = arr.size()-1, mid;

	while(low <= high) {
		mid = (low+high)/2;
		if(n < arr[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	arr.insert(arr.begin()+low,n);
}

int main() {
	std::vector<int> arr = {1,2,3,4,5,5,6,7,8,9};
	insertInSortedOrder(arr, 5);
	for(int& num: arr) {
		std::cout << num << " ";
	}
	std::cout <<"\n";
	return 0;
}

