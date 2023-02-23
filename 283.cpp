class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        //指向0
        int slow = 0;
        int fast = 0;
        while(fast <= (nums.size() - 1) && slow <= (nums.size() - 1)){
            if(fast > slow && slow != fast){
                int temp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = temp;
            }
            if(nums[slow] != 0){
                slow++;
            }
            else{
                if(fast < slow){
                    fast = slow;
                }
                while(fast <= (nums.size() - 1) && nums[fast] == 0){
                    fast++;
                }
            }
        }
    }
};
