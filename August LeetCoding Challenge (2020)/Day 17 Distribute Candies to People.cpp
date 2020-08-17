class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        int count = 1, index = 0;
        while(candies > 0){
            res[index % num_people] += min(candies, count);
            index++, candies-=count, count++;
        }
        return res;
    }
};
