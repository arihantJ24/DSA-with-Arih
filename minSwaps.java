class Solution {
    public int minSwaps(String s) {
        int size = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '[') 
                size++;
            else if (size > 0) 
                size--;
            // System.out.println(size);
        }
        return (size + 1) / 2;
        //one swap can fix 2 unbalanced brackets
    }
}
