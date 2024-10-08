class Solution {
    public int[] arrayRankTransform(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int n = arr.length;
        int[] sor = new int[n];
        for (int i = 0; i < n; i++) {
            sor[i] = arr[i];
        }
        Arrays.sort(sor);
        int a=0;
        for (int i = 0; i < n; i++) {
            if (!map.containsKey(sor[i])) {
                map.put(sor[i], a++);

            }
        }
        for (int i = 0; i < n; i++) {
            arr[i] = map.get(arr[i]) + 1;
        }
        return arr;
    }
}
