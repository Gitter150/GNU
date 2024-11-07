#include<iostream>
#include<vector>
#include<algorithm>

class Sorting{
private:
    std::vector<int>nums;
public: 
    Sorting(std::vector<int> &vec): nums(vec){ insertionSort(nums); }      
    void insertionSort(std::vector<int> &nums){
    if (nums.size()==0){
        std::cout<<"The list is empty!"<<std::endl;
        return;
    }
    else{
        for(int i = 1; i< nums.size(); i++)
            {
            int j = i;
            while(j>0 && nums[j] < nums[j-1])
                {   
                    std::swap(nums[j],nums[j-1]);
                    j-=1;
                }
            }
        }
    }
    void print() const{
        for(int num: nums){
        std::cout<<num<<(num!=nums[nums.size()-1] ? ",":"");
        }
        std::cout<<std::endl;
    } 
};

int main(){
    std::vector<int> nums;
    nums = {9,8,7,6,5,4,3,2,1};
    Sorting array(nums);
    array.print();
    return 0;
}


