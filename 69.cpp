//同向双指针
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

//相向双指针
//更快解法，不需要交换，直接覆盖就可
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //双指针
        if(nums.size() == 0){
            return 0;
        }
        int left = 0;
        int right = nums.size() - 1;
        int flag = 0;
        while(left <= right){
            if(flag != 0)
            {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
            while(left <= (nums.size() - 1) &&nums[left] != val ){
                left++;
            }
            while( right >= 0&&nums[right] == val ){
                right--;
            }
            if(flag == 0){
                flag = 1;
            }
        }
        return left;
    }
};
