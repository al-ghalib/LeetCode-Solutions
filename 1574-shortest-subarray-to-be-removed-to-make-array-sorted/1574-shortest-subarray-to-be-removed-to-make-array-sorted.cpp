class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        int r = n - 1;
        
        while(r > 0 and arr[r] >= arr[r-1])
        {
            r--;
        }
        
        int l = 0;
        int ans = r; // determine prefix size
        
        while(l < r)
        {   
            while(r < n and arr[l] > arr[r])
            {
                r++;
            }
            
            ans = min(ans, r - l - 1);
            
            if(arr[l] > arr[l+1]) break;
            
            l++;
        }
        
        return ans;
    }
};