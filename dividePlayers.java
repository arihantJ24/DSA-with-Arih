class Solution {
    public long dividePlayers(int[] skill) {
        int n = skill.length;
        Arrays.sort(skill);
        int a = skill[0]+skill[n-1];
        for(int i=1;i<n/2;i++){
            int b = skill[i]+skill[n-i-1];
            if(a!=b){
                return -1;
            }
        }
        long ans=0;
        for(int i=0;i<n/2;i++){
            ans+=(long)(skill[i]*skill[n-i-1]);
        }
        return ans;
    }
}
