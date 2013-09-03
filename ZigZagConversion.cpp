    string getschar(const string &s, int index){
        string res;
        if(index < 0 || index >= s.length()){
            return res;
        }
        res.push_back(s[index]);
        return res;
    }
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len = s.length();
        if(nRows == 1){
            return s;
        }
        // basic calculation
        int segSize = 2*nRows - 2;
        int segn = (len + segSize - 1) / segSize;
        
        string res = "";
        for(int row=0; row<nRows; ++row){
            for(int seg=0; seg<segn; ++seg){
                int ifirst = row;
                int isecond = segSize - row;
                res += getschar(s, seg*segSize+ifirst);
                if(isecond > ifirst && isecond < segSize){
                    res += getschar(s, seg*segSize+isecond);
                }
            }
        }
        return res;
    }