class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        int lo = 0, hi = n - 1;
        
        if(n == 1) return nums[0];
        
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            
            if(mid == 0 && nums[0] != nums[1]) return nums[0];
            if(mid == n - 1 && nums[n-1] != nums[n-2]) return nums[n-1];
            
            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];
            
            if(mid % 2 == 0) // even
            {
                if(nums[mid-1] == nums[mid]) hi = mid - 1;
                else lo = mid + 1;
            }
            else // odd
            {
                if(nums[mid-1] == nums[mid]) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        
        return -1;
    }
};