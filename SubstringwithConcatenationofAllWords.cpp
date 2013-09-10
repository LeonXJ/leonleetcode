vector<int> findSubstring(string S, vector<string> &L) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int aimN = L.size();
    int slen = S.length();
    int wordlen = L[0].length();
    // construct aim
    map<string, int> aimDetail;
    for(int i=0; i<L.size(); ++i){
        if(aimDetail.find(L[i]) == aimDetail.end()){
            aimDetail[L[i]] = 0;
        }
        aimDetail[L[i]] += 1;
    }
    // outer try, wordlen
    vector<int> res;
    for(int i=0; i<wordlen; ++i){
        int remN = aimN;
        int iBeg = i;
        map<string, int> remDetail(aimDetail);

        for(int j=i; j<=slen-wordlen; j+=wordlen){
            string word = S.substr(j, wordlen);
            if(remDetail.find(word) != remDetail.end()){
                // remove addtion words
                if(remDetail[word] <= 0){
                    string cur;
                    do{
                        cur = S.substr(iBeg, wordlen);
                        remDetail[cur] += 1;
                        ++remN;
                        iBeg += wordlen;
                    }while(cur != word);
                }
                // append word
                remDetail[word] -= 1;
                remN -= 1;
                if(remN == 0){
                    // got one
                    res.push_back(iBeg);
                }
            }
            else{
                // not find
                remN = aimN;
                remDetail = aimDetail;
                iBeg = j + wordlen;
            }
        }

    }
    return res;
}
