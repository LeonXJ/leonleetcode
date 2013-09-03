    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool neg = (x < 0);
        long long absx = x >= 0 ? x : -x;
        long long absres = 0;
        while(absx != 0){
            absres *= 10;
            int bit = absx%10;
            absres += bit;
            absx/=10;
        }
        if(neg){
            return (int)(-absres);
        }
        else{
            return (int)(absres);
        }
    }