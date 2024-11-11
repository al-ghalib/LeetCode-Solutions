class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> mp;
        
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int num1 = nums[i];
            int num2 = target - num1;
            
            if(mp.find(num2) != mp.end())
            {
                ans.push_back(i);
                ans.push_back(mp[num2]);
                break;
            }
            
            mp[num1] = i;
        }
        
        return ans;
    }
};