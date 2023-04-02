//最后一个样例会超出时间限制，目前没有比较好的解决方法。
string minWindow(string s, string t) {
    if (s.length() < t.length()) {
        return "";
    }
    unordered_map<char, int> cnt;
    for (int i = 0; i < t.length(); i++) {
        ++cnt[t[i]];
    }
    int left = 0;
    int num = 0;
    int result_length = INT_MAX;
    string result = "";
    int flag = 0;
    for (int right = 0; right < s.length(); right++) {
        auto it = cnt.find(s[right]);
        if (it != cnt.end()) {
            if ((--it->second) >= 0) {
                num++;
            }
            if (flag == 0) {
                left = right;
                flag = 1;
            }
        }
        while (num == t.length()) {
            if (result_length > (right - left + 1)) {
                result_length = right - left + 1;
                result = s.substr(left, result_length);
            }
            auto it = cnt.find(s[left]);
            if (it != cnt.end()) {
                if ((++it->second) > 0) {
                    num--;
                }
                
            }
            left++;
        }
        
    }
    return result;
}


