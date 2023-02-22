class Solution {
public:
	int binarysearch(vector<int>& nums, int target, int left, int right, int flag) {
		int result = -1;
		int middle;
		while (left <= right) {
			middle = left + (right - left) / 2;
			if (target < nums[middle]) {
				right = middle - 1;
			}
			else if (target > nums[middle]) {
				left = middle + 1;
			}
			else {
				result = middle;
                break;
			}
		}
		if (result != -1) {
			if (flag == 0) {
				int result1 = binarysearch(nums, target, left, middle - 1, 0);
				return result1 != -1 ? result1 : result;
			}
			else {
				int result1 = binarysearch(nums, target, middle + 1, right, 1);
				return result1 != -1 ? result1 : result;
			}
		}
		return result;
	}
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result{ -1,-1 };
		if (!nums.size()) {
			return result;
		}
		int left = 0;
		int right = nums.size() - 1;
		int middle;
		while (left <= right) {
			middle = left + (right - left) / 2;
			if (target < nums[middle]) {
				right = middle - 1;
			}
			else if (target > nums[middle]) {
				left = middle + 1;
			}
			else {
				result[0] = middle;
				result[1] = middle;
				break;
			}
		}
		if (result[0] == -1) {
			return result;
		}
		//middle对应存在      调用不存在的话返回－1，否则返回相应值
		int left_tar = binarysearch(nums, target, left, middle - 1, 0);
		int right_tar = binarysearch(nums, target, middle + 1, right, 1);
		result[0] = left_tar != -1 ? min(result[0], left_tar) : result[0];
		result[1] = right_tar != -1 ? max(result[1], right_tar) : result[1];
		return result;
	}
};
