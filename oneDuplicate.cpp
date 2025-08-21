#include <iostream>
#include <vector>

typedef std::vector<int> intVec;
int oneDuplicate(intVec& arr) {
	// my thinking:
	/*  so question is, if theres an array of size n where all elements range
	    from 1 to n - 1, in which only one element is duplicated ONCE,
	    find, in O(n) time and O(1) space, that duplicate element.
		supposed to be O(n) in time complexity and O(1) in extra space. 
		hmm so i definitely cant use hash maps here, which take up O(n) space.
		apparently GfG puts this algorithm under the two-pointers technique
		...and yeah thats the only hint i have, currently i have NO idea.. (5: 05 PM, 4/20/2025)
		let's see how i push my limits - without any help from any LLM, without peeking at the 
		solution, without even a proper hint - i WILL solve it. YES. I will.
		this is supposed to be an easy problem. 
		sublime text gives such nice vibes to code - i love it
		probably why it costs around 8000 rupees 
		i have no regret in using the UNREGISTERED version, LOL
		HAHA LOL I FIGURED IT OUT (5: 10 PM, 4/20/2025)
		YOU KNOW MY APPROACH? LEMME EXPLAIN
		so, consider {1,2,3,4,4,5,6,7}.
		since there must be n-1 unique elements with 1 duplicate element (which itself can range from 1 to n - 1)
		so, the sum of those n-1 unique elements must be (n-1)*(n-1+1)/2 = n*(n-1)/2
		but the sum of entire array - duplicate element = sum of remaining array = sum of unique elements
		hence, duplicate element = sum of entire array (O(n) time for summing) - sum of unique elements
		but sum of unique elements itself is n*(n-1)/2
		hence duplicate element = sum(arr) - n.size()*(n.size()-1)/2;
	*/
    int sum = 0;
    int n = arr.size();
    for(int& num: arr) 
    	sum += num;
    return sum - n*(n-1)/2;
}

int main() {
	intVec arr = {1,2,3,4,4,5,6,7}; // n = 8, n MUST be max element + 1 !!!!!
	int dup = oneDuplicate(arr);
	std::cout<<"Duplicate is: "<<dup<<std::endl;
	return 0;
}