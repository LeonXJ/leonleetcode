int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!A || n==0){
            return 0;
        }
        
        int iNextWrite = 0;
        int iRead = 0;
        for(iRead = 0; iRead<n; ++iRead){
            if(A[iRead] != elem){
                A[iNextWrite] = A[iRead];
                ++iNextWrite;
            }
        }
        return iNextWrite;
    }
