class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<List<Integer>> res = new ArrayList<>();
        List<int[]> height = new ArrayList<>();    
        
        for (int[] b : buildings) {
            height.add(new int[]{b[0], - b[2]});    // start stored as negtive
            height.add(new int[]{b[1], b[2]});      // end stored as positive
        }
        Collections.sort(height, (a, b) -> (a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));     // sort by x(asc), then height(start to end)
        

        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> (b - a)); // height in des
        pq.offer(0);
        int preMax = 0;
        
        for (int[] h : height) {
            if (h[1] < 0) {     // starting
                pq.offer(-h[1]);
            } else {            // ending, remove from height
                pq.remove(h[1]);
            }
            
            // the current max height in all encountered buildings
            int curMax = pq.peek();
            // if the max height is different from the previous one, that means a critical point is met, add to result list
            if (curMax != preMax) {
                List<Integer> temp = new ArrayList();
                temp.add(h[0]);
                temp.add(curMax);
                res.add(temp);
                preMax = curMax;
            }
        }
        return res;
    }
}
