    int getBits(long long n){
        int res=0;
        while(n!=0){
            ++res;
            n >>= 1;
        }
        return res;
    }
    
int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(dividend == 0){
            return 0;
        }
        long long absDividend = dividend;
        absDividend = absDividend > 0 ? absDividend : -absDividend;
        long long absDivisor = divisor;
        absDivisor =  absDivisor> 0 ? absDivisor : -absDivisor;
        if(absDividend < absDivisor){
            return 0;
        }
        bool isNeg = (dividend>0 && divisor<0) || (dividend<0 && divisor>0);
        if(absDivisor == 1){
            return isNeg? (int)(-absDividend) : (int)(absDividend);
        }
        // real thing
        int dividendBits = getBits(absDividend);
        int divisorBits = getBits(absDivisor);
        int deltaBits = dividendBits - divisorBits;
        long long tmpDivisor = absDivisor << deltaBits;
        long long res = 0;
        for(;deltaBits>=0;--deltaBits){
            res <<= 1;
            if(absDividend >= tmpDivisor){
                res |= 0x1;
                absDividend -= tmpDivisor;
            }
            tmpDivisor >>= 1;
        }
        // return
        return isNeg? (int)(-res) : (int)(res); 
    }

