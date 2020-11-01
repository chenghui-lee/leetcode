class Solution {
    public int largestComponentSize(int[] A) {
        Map<Integer, Integer> parent = new HashMap<>();
        
        for (int num : A) {
            for (int fact = 2; fact * fact <= num; fact++) {
                if (num % fact == 0) {
                    union(num, fact, parent);
                    union(num, num/fact, parent);   
                }
            }
        }
        
        int maxValue = 1;
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        
        for (int num : A) {
            int findNum = find(num, parent);
            
            frequencyMap.put(findNum, frequencyMap.getOrDefault(findNum, 0) + 1);
            
            maxValue = Math.max(maxValue, frequencyMap.get(findNum));
        }
        
        return maxValue;
    }
    
    private void union(int n, int m, Map<Integer, Integer> parent) {
        int findN = find(n, parent);
        int findM = find(m, parent);
        
        if (findN < findM) parent.put(findM, findN);
        else parent.put(findN, findM);
    }
    
    private int find(int num, Map<Integer, Integer> parent) {
        if (parent.get(num) == null) parent.put(num, num);
        
        while (num != parent.get(num)) num = parent.get(num);
        
        return num;
    }
}
