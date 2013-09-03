int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long res = 0;
        if(!str){
            return 0;
        }
        // eat head space
        while(*str != '\0' && *str == ' '){
            ++str;
        }
        // sign
        bool neg = false;
        if(*str == '-'){
            neg = true;
            ++str;
        }
        else if(*str == '+'){
            ++str;
        }
        // numbers
        while(*str >= '0' && *str <= '9'){
            int bit = *str - '0';
            res *= 10;
            res += bit;
            ++str;
            // overflow
            if(!neg && res >= INT_MAX){
                return INT_MAX;
            }
            else if(neg && -res <= INT_MIN){
                return INT_MIN;
            }
        }
        
        if(neg){
            return (int)(-res);
        }
        return (int)(res);
    }