#include <vector>
#include <unordered_map>
#include <iostream>


std::vector<int> twoSum(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> mp;
	for(size_t i = 0; i < nums.size(); i++) {
		mp[nums[i]] = i;
	}
	for(size_t i = 0; i < nums.size(); i++) {
		if (mp.find(target - nums[i]) != mp.end() && mp[target - nums[i]] != i) {
			int small_index = i < mp[target - nums[i]] ? i:mp[target - nums[i]],
			large_index = small_index == i? mp[target - nums[i]]:i;
			return {small_index, large_index};
		}
	}
	return {-1};
}


int main() {
	std::vector<int> nums = {6, 0, 3, 3};
	int target = 6;
	std::vector<int> res = twoSum(nums, target);
	for(int num: res) {
		std::cout << num << " ";
	}
	std::cout<<"\n";
	return 0;
}