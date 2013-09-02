
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> num2ind;
        for(int i=0; i<numbers.size(); ++i){
            int wanted = target - numbers[i];
            map<int, int>::iterator it = num2ind.find(wanted);
            if(it != num2ind.end()){
                // find
                vector<int> res;
                res.push_back(num2ind[wanted]+1);
                res.push_back(i+1);
                return res;
            }
            else{
                num2ind[numbers[i]] = i;
            }
        }
        vector<int> res;
        return res;
    }
