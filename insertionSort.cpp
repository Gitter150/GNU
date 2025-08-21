#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
	int j;
	for(int i=0; i < arr.size()-1; i++) {
		j = i;
		while(j>-1 && arr[j+1]<arr[j]) {
			std::swap(arr[j+1],arr[j]);
			j--;
		}
	}
}

void printList(std::vector<int> arr) {
	for(int& num: arr) std::cout<<num<<" ";
}

int main() {
	std::vector<int> arr = {1,6,2,9,4,12,4,6,9,1,-3,2};
	insertionSort(arr);
	printList(arr);
}