class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
            int boundary = 0;
            vector<int> ans;
            for(int i = 0 ; i < nums.size() ;i++){
                    if(nums[i] < 0){
                         boundary ++;   
                    }
            }
            if(boundary == 0){
                    for(auto & e: nums){
                            ans.push_back(e*e);
                    }
            }
            else if(boundary == nums.size()){
                    for(int j = nums.size() - 1; j >=0; j--){
                            ans.push_back(nums[j] * nums[j]);
                    }
            }
            else{
                    int i = boundary - 1;
                    int j = boundary ;
                    while(i >= 0 && j < nums.size()){
                            if(abs(nums[i]) < nums[j]){
                                    ans.push_back(nums[i] * nums[i]);
                                    i--;
                            }
                            else{
                                  ans.push_back(nums[j]*nums[j]);
                                    
                                    j++;
                            }
                    }
                    while(i>=0){
                            ans.push_back(nums[i] * nums[i]);
                            i--;
                    }
                    while(j < nums.size()){
                            ans.push_back(nums[j] * nums[j]);
                            j++;
                    }
            }
            return ans;
    }
};
