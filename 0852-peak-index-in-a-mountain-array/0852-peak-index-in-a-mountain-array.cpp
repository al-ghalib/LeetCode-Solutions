class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int lo = 1, hi = arr.size()-2;
        
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            
            if(arr[mid-1] <  arr[mid] && arr[mid] > arr[mid+1]) return mid;
            
            else if(arr[mid-1] < arr[mid]) lo = mid + 1; // right
            
            else hi = mid - 1; // left
        }
        
        return -1;
    }
};