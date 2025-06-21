#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<int>> Subsets(std::vector<int> &arr) {
    int n = arr.size(),
    maxValue = pow(2, n) - 1;
    std::vector<std::vector<int>> subsets;
    for(int i = 1; i <= maxValue; i++) {
        std::vector<int> subset;
        for(int j = 0; j < n; j++) {
            if( (i >> (n - 1 - j)) & 1 == 1) {
                subset.push_back(arr[j]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}

void print(std::vector<int> arr) {
    if (arr.size() == 0) return;
    std::cout << "(";
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[n-1] << ")";
}

int main() {
    std::vector<int> arr = {1,2};
    std::vector<std::vector<int>> subsets = Subsets(arr);
    std::cout << "[";
    for(int i = 0; i < subsets.size()-1; i++) {
        print(subsets[i]);
        std::cout <<", ";
    }
    print(subsets[subsets.size() - 1]);
    std::cout << "]\n";
    return 0;
}
