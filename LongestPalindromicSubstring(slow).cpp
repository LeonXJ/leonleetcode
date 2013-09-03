    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int slen = s.length();
        if(slen == 0){
            return 0;
        }
        // init
        vector<vector<bool> > ispar;
        for(int i=0; i<slen; ++i){
            vector<bool> curv;
            for(int j=0; j<slen; ++j){
                curv.push_back(false);   
            }
            ispar.push_back(curv);
        }
        // do
        int res = 1;
        string ress = s.substr(0,1);
        for(int right=1; right<slen; ++right){
            ispar[right][right] = true;
            for(int left=right-1; left>=0; --left){
                if(left == right-1){
                    if(s[left] == s[right]){
                        ispar[left][right] = true;
                        if(res < 2){
                            res = 2;
                            ress = s.substr(left,2);
                        }
                    }
                    else{
                        ispar[left][right] = false;
                    }
                }
                else{
                    if(ispar[left+1][right-1] && s[left] == s[right]){
                        ispar[left][right] = true;
                        int len = right - left + 1;
                        if(res < len){
                            res = len;
                            ress = s.substr(left, len);
                        }
                    }
                    else{
                        ispar[left][right] = false;
                    }
                }
            }
        }
        return ress;
    }