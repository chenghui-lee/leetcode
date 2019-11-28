public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        double median = 0;
        List<Integer> list = new ArrayList<Integer>();
        for (int i =0; i<nums1.length;i++){
            list.add(nums1[i]);
        }
        for (int i =0; i<nums2.length;i++){
            list.add(nums2[i]);
        }
        
        Collections.sort(list);
        
        if (list.size() % 2 != 0) {
            median = (double) list.get((list.size() / 2 + 1)-1);
        } else {
            median = ((double) list.get((list.size() / 2 )-1)+ (double) list.get((list.size() / 2 + 1)-1))/2;
        }

        return median;
    }
