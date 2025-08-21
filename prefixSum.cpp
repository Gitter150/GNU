#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {1,8,2,6,2,9,4,2,9,5,2,9,6};
    int prefixSum[arr.size()];
    int sum = 0;
    for(int i=0;i<arr.size();i++) {
        sum += arr[i];
        prefixSum[i] = sum;
    }
    int l,r, res;
    l = 0;
    r = 4;
    if(l == 0) res = prefixSum[r];
    else res = prefixSum[r] - prefixSum[l-1];
    std::cout << "The sum is: "<< res <<std::endl;
    return 0;
}