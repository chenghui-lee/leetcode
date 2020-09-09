class Solution {
    public int compareVersion(String version1, String version2) {
        String v1[] = version1.split("\\.");
        String v2[] = version2.split("\\.");
        
        int i=0;
        for(; i< Math.min(v1.length, v2.length); i++){
            int one = Integer.parseInt(v1[i]);
            int two = Integer.parseInt(v2[i]);
            
            if(one > two) return 1;
            else if (two > one) return -1;
        }
        
        if(v1.length == v2.length) return 0;
        while(i < v1.length){
            int temp = Integer.parseInt(v1[i]);
            if(temp > 0) return 1;
            i++;
        }
        while(i < v2.length){
            int temp = Integer.parseInt(v2[i]);
            System.out.println(temp);
            if(temp > 0) return -1;
            i++;
        }
        return 0;
    }
}
