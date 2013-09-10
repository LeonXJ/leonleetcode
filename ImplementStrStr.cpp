char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!haystack || !needle){
            return NULL;
        }
        
        // build next
        int lenNeedle = strlen(needle);
        if(lenNeedle == 0){
            return haystack;
        }
        int *pNext = new int[lenNeedle];
        pNext[0] = -1;
        int j=-1;
        int i=1;
        for(i=1; i<lenNeedle; ++i){
            while(j>=0 && needle[j+1] != needle[i]){
                j = pNext[j];
            }
            if(needle[j+1] == needle[i]){
                ++j;
            }
            pNext[i] = j;
        }
        
        // do it
        int lenHaystack = strlen(haystack);
        j=-1;
        i=0;
        for(int i=0; i<lenHaystack; ++i){
            while(j>=0 && needle[j+1] != haystack[i]){
                j = pNext[j];
            }
            if(needle[j+1] == haystack[i]){
                ++j;
                if(j == lenNeedle-1){
                    // success
                    delete []pNext;
                    pNext = NULL;
                    return haystack + i - lenNeedle + 1;
                }
            }
        }
        
        // release
        delete []pNext;
        pNext = NULL;
        return NULL;
        
    }
