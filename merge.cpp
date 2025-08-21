#include <iostream>
#include <vector>

class MyVector {
    private:
        std::vector<int> list;
    public:
        MyVector(std::vector<int>& arr) : list(arr) {}
        std::vector<int> operator+(const std::vector<int>& arr) {
            int len1 = this->list.size();
            int len2 = arr.size();
            std::vector<int> res;
            for(int i=0;i<len1+len2;i++) {
                res.push_back((i<len1? this->list[i] : arr[i-len1]));
            }
            return res;
        }
};

int main() {
    std::vector<int> arr = {1,2,3};
    std::vector<int> v2 = {4,5,6,7};
    MyVector v1(arr);
    std::vector<int> v3 = v1 + v2;
    std::cout << "The result is..\n";
    std::cout << "{";
    for(int i=0;i<v3.size();i++) std::cout << v3[i] << ", ";
    std::cout <<"\n";
    return 0;
}