class NumArray {
private:
struct SegmentTreeNode{
	int start;
	int end;
	int sum;
	SegmentTreeNode* left;
	SegmentTreeNode* right;
	SegmentTreeNode(int s, int e, int sum_, SegmentTreeNode* left_ = nullptr, SegmentTreeNode* right_ = nullptr){
		start = s;
		end = e;
		sum = sum_;
		left = left_;
		right = right_;
	}
};

SegmentTreeNode* buildTree(int start, int end, vector<int>& nums){
	if (start == end) return new SegmentTreeNode(start, end, nums[start]);
	int mid = start + (end - start) / 2;
	auto left = buildTree(start, mid, nums);
	auto right = buildTree(mid+1, end, nums);
	return new SegmentTreeNode(start, end, left->sum + right->sum, left, right);
}

void updateTree(SegmentTreeNode* root, int idx, int val){
	if (root->start == idx && root->end == idx){
		root->sum = val;
		return;
	}
	int mid = root->start + (root->end - root->start) / 2;
	if (idx <= mid){
		updateTree(root->left, idx, val);
	}else{
		updateTree(root->right, idx, val);
	}
	root->sum = root->left->sum + root->right->sum;
}

int sumRange(SegmentTreeNode* root, int i, int j){
	if (i == root->start && j == root->end){
		return root->sum;
	}
	int mid = root->start + (root->end - root->start) / 2;
	if (j <= mid){
		return sumRange(root->left, i, j);
	}else if (i > mid){
		return sumRange(root->right, i, j);
	}else{
		return sumRange(root->left, i, mid) + sumRange(root->right, mid+1, j);
	}
}
public:
    SegmentTreeNode* root;
    NumArray(vector<int>& nums) {
        root = buildTree(0, nums.size() - 1, nums);
    }
    
    void update(int index, int val) {
        updateTree(root, index, val);
    }
    
    int sumRange(int left, int right) {
        return sumRange(root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
