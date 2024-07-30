class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int a=sqrt(l);
        int b=sqrt(r);
        int count=0;
        for(int i=a;i<=b;i++){
            if(i*i>=l && i*i<=r && isPrime(i)){
                count++;
            }
        }
        return r-l-count+1;
    }
    bool isPrime(int n)
    {
        // Corner case
        if (n <= 1)
            return false;

        // Check from 2 to square root of n
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;

        return true;
    }

};