class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        int len=words.length;
        int arr[]=new int[len];
        for(int i=0;i<len;i++){
            int c=0;
            if(words[i].charAt(0)=='a' ||words[i].charAt(0)=='e' ||words[i].charAt(0)=='i' ||words[i].charAt(0)=='o' ||words[i].charAt(0)=='u' )
            c++;
            if(words[i].charAt(words[i].length()-1)=='a' ||words[i].charAt(words[i].length()-1)=='e' ||words[i].charAt(words[i].length()-1)=='i' ||words[i].charAt(words[i].length()-1)=='o' ||words[i].charAt(words[i].length()-1)=='u' )
            c++;
            if(c==2){
                arr[i]=1;
            }
        }
        int count[]=new int[len];
        count[0]=arr[0];
        for(int i=1;i<len;i++){
            count[i]=count[i-1]+arr[i];
        }
        len=queries.length;
        int ans[]=new int[len];
        for(int i=0;i<len;i++){
            if(queries[i][0]!=0)
            ans[i]=count[queries[i][1]]-count[queries[i][0]-1];
            else
            ans[i]=count[queries[i][1]];
        }
        return ans;

    }
}