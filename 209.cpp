int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    int right = -1;
    int sum = 0;
    int min_length = nums.size() + 1;
    while (right < (int)(nums.size() - 1)) {
        while (right < (int)(nums.size() - 1) && sum < target) {
            right++;
            sum += nums[right];
                
            
        }
        if (sum >= target) {

            while (left <= right && sum >= target) {
                if ((right - left + 1) < min_length) {
                    min_length = right - left + 1;
                }
                sum -= nums[left];
                left++;
            }
        }

    }
    if (min_length == (nums.size() + 1)) {
        return 0;
    }
    return min_length;
}
