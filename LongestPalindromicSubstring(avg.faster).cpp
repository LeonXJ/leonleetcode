    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int slen = s.length();
        if(slen == 0){
            return 0;
        }
        // init
        vector<int> *pRead = new vector<int>();
        vector<int> *pWrite = new vector<int>();
        // do
        string res = s.substr(0,1);
        for(int right=1; right<slen; ++right){
            pWrite->clear();
            pWrite->push_back(1);
            // only two
            if(s[right] == s[right-1]){
                pWrite->push_back(2);
                if(res.length() < 2){
                    res = s.substr(right-1,2);
                }
            }
            // other
            for(int i=0; i<pRead->size(); ++i){
                int oldlen = pRead->at(i);
                int leftIndex = right - oldlen - 1;
                if(leftIndex >=0 && s[right] == s[leftIndex]){
                    int newlen = oldlen + 2;
                    pWrite->push_back(newlen);
                    if(newlen > res.length()){
                        res = s.substr(right-newlen+1, newlen);
                    }
                }
            }
            // swap
            vector<int> *pTemp = pRead;
            pRead = pWrite;
            pWrite = pTemp;
        }
        delete pRead;
        delete pWrite;
        return res;
    }