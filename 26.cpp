class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        int slow = 0;
        int fast = 0;
        while(fast <= (nums.size() - 1)){
            int temp = nums[fast];
            if((fast + 1) <= (nums.size() - 1) && nums[fast + 1] == temp){
                while((fast+1) <= (nums.size() - 1) && nums[fast + 1] == temp){
                    fast++;
                } 
                int t = nums[fast];
                nums[fast] = nums[slow];
                nums[slow] = t;
                slow++;
                fast++;
            }
            else{
                nums[slow++] = nums[fast++];
            }
        }
        return slow ;
    }
};
