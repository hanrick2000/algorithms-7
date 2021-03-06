
/*
    Remove Duplicate Numbers in Array

    Given an array of integers, remove the duplicate numbers in it.
    You should:
    1. Do it in place in the array.
    2. Move the unique numbers to the front of the array.
    3. Return the total number of the unique numbers.
    You don't need to keep the original order of the integers.

    Example
    Given nums = [1,3,1,4,4,2], you should:
    Move duplicate integers to the tail of nums => nums = [1,3,4,2,?,?].
    Return the number of unique integers in nums => 4.
    Actually we don't care about what you place in ?, we only care about the part which has no duplicate integers.

*/

class Solution {
public:
    /**
     * @param nums an array of integers
     * @return the number of unique integers
     */
    int deduplication(vector<int>& nums) {

        // state variables
        int left = 0, right = nums.size()-1;
        set<int> collection;

        while (left <= right) {
            if (collection.find(nums[left]) == collection.end()) {
                collection.insert(nums[left++]);
            } else {
                swap(nums[left],nums[right--]);
            }

        }
        return left;
    }
};
