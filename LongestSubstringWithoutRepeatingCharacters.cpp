int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.length() == 0){
            return 0;
        }
        bool hasch[256];
        for(int i=0; i<256; ++i){
            hasch[i] = false;
        }
        int maxlength = 0;
        int left = 0;
        int right = 0;
        for(right = 0; right<s.length(); ++right){
            char cur = s[right];
            // has this char?
            while(hasch[cur]){
                char old = s[left];
                hasch[old] = false;
                ++left;
            }
            hasch[cur] = true;
            int length = right - left + 1;
            if(length > maxlength){
                maxlength = length;
            }
        }
        return maxlength;
    }