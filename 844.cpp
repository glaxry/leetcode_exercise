class Solution {
public:
    bool backspaceCompare(string s, string t) {
            int i = 0;
            for(int j = 0 ; j < s.length() ; j++){
                    if(s[j] != '#'){
                            s[i++] = s[j];
                    }
                    else{
                            if(i > 0){
                            					i--;
                            }
                    }
            }
            int k = 0;
            for(int j = 0 ; j < t.length() ; j++){
                    if(t[j] != '#'){
                            t[k++] =t[j];
                    }
                    else{
                            if(k>0){
                            					k--;
                            }
                    }
            }
            if(i != k){
                    return false;
            }
            for(int j = 0; j < k ;j++){
                    if(s[j] != t[j]){
                            return false;
                    }
            }
            return true;
            
    }
};
