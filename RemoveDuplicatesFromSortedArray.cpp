int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!A || n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        
        int iFirst = 0;
        int iSecond = 1;
        for(iSecond = 1; iSecond<n; ++iSecond){
            if(A[iFirst] != A[iSecond]){
                ++iFirst;
                A[iFirst] = A[iSecond];
            }
        }
        return iFirst+1;
    }
