class Solution {
private:
    // Function to find the peak index in the array using Binary Search
    int findPeak(MountainArray &mountainArr, int n){

        int low=0, high=n-1, mid, prev, next, middle, peak=-1;
        while(low<=high){

            mid = (low+(high-low)/2);
            if(mid>0 && mid<n-1){

                prev = mountainArr.get(mid-1);
                middle = mountainArr.get(mid);
                next = mountainArr.get(mid+1);

                if(middle>prev && middle>next){
                    peak = mid;
                    break;
                }
                else if(middle<next)
                    low = mid+1;
                
                else if(middle<prev)
                    high = mid-1;
                
            }
            if(mid==0)
                low++;
            if(mid==n-1)
                high--;
        }
        return peak;
    }

    // Function to find the index of the target element in the arr using Binary Search
    int BinarySearchLeft(MountainArray &mountainArr, int target, int low, int high){
        
        int mid, midElement;
        while(low<=high){

            mid = (low+(high-low)/2);
            midElement = mountainArr.get(mid);

            if(midElement==target)
                return mid;
            
            else if(midElement<target)
                low = mid+1;
            
            else
                high = mid-1;
            
        }

        // Returning INT_MAX, if we are not able to find the target element
        return INT_MAX;
    }
    int BinarySearchRight(MountainArray &mountainArr, int target, int low, int high){
        
        int mid, midElement;
        while(low<=high){

            mid = (low+(high-low)/2);
            midElement = mountainArr.get(mid);

            if(midElement==target)
                return mid;
            
            else if(midElement>target)
                low = mid+1;
            
            else
                high = mid-1;
            
        }

        // Returning INT_MAX, if we are not able to find the target element
        return INT_MAX;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int n = mountainArr.length();
        int peak = findPeak(mountainArr, n);

        // Applying Binary Search in left part of the mountain array
        int ans = BinarySearchLeft(mountainArr, target, 0, peak);
        if(ans!=INT_MAX)
            return ans;
        
        // If we don't get ans in left part, then we check in right part
        ans = BinarySearchRight(mountainArr, target, peak, n-1);
        if(ans!=INT_MAX)
            return ans;
        
        // If target element is not present, then return -1
        return -1;
    }
};