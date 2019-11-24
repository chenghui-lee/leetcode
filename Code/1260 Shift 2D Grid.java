class Solution {
    public List<List<Integer>> shiftGrid(int[][] a, int k) {
        int[][] copy = Arrays.copyOf(a, a.length);
        int[][] result = new int[a.length][a[0].length];
        List<List<Integer>> lists = new ArrayList<>();
        if (k==0)
            result = a;

        for (int pass = 1; pass <= k; pass++) {
            result = new int[a.length][a[0].length];
            for (int row = 0; row < a.length; row++) {
                for (int col = 0; col < a[row].length - 1; col++) {
                    result[row][col + 1] = copy[row][col];
                }
            }
            result[0][0] = copy[a.length - 1][a[0].length - 1];
            for (int row = 0; row < a.length - 1; row++) {
                result[row + 1][0] = copy[row][a[0].length - 1];
            }
            copy = result;
        }
        for (int[] ints : result) {
            List<Integer> list = new ArrayList<>();
            for (int i : ints) {
                list.add(i);
            }
            lists.add(list);
        }
        return lists;
    }
}
