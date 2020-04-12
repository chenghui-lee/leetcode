class Solution {
public:
int lastStoneWeight(vector<int>& stones){
  make_heap(stones.begin(), stones.end());
  while (stones.size() > 1){
    //sort_heap(stones.begin(), stones.end());
    int a = stones.front();
    pop_heap(stones.begin(), stones.end());
    stones.pop_back();
    int b = stones.front();
    pop_heap(stones.begin(), stones.end());
    stones.pop_back();
    if (a-b > 0){
    	stones.push_back((a-b));
        push_heap(stones.begin(), stones.end());
    }

  }
   // cout << "size is " << stones.size();
  if (stones.size() > 0){
	  return stones[0];
  }
  return 0;

}
};
