class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int jumpIndx = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > jumpIndx) return false;
            
            jumpIndx = max(jumpIndx, i + nums[i]);
        }
        
        return true;
    }
};
