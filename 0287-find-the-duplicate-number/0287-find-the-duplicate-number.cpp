// Slow Fast Pointer (for not modifying array)
// slow = +1 ... fast = +2 untill slow == fast

// TC ~ O(n) ... SC ~ O(1)   
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int slow = nums[0], fast = nums[0];
        
        do 
        {
            slow = nums[slow]; // +1
            fast = nums[nums[fast]]; // +2
        } while(slow != fast);
        
        slow = nums[0];
        
        while(slow != fast)
        {
            slow = nums[slow]; // +1
            fast = nums[fast]; // +1
        }
        
        return slow;
    }
};

