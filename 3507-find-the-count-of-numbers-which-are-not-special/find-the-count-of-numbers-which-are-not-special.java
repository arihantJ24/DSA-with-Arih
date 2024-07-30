class Solution {
    boolean isPrime(int n)
    {
        // Corner case
        if (n <= 1)
            return false;

        // Check from 2 to square root of n
        for (int i = 2; i <= Math.sqrt(n); i++)
            if (n % i == 0)
                return false;

        return true;
    }

    public int nonSpecialCount(int l, int r) {
        int a=(int)Math.sqrt(l);
        int b=(int)Math.sqrt(r);
        // System.out.println(a+ " " + b);
        int count=0;
        // if(a*a<l) count=count-1;
        for(int i=a;i<=b;i++){
            if(i*i>=l && i*i<=r && isPrime(i)){
                count++;
            }
        }
        return r-l-count+1;
    }
}