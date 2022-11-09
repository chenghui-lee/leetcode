class StockSpanner {
public:
	stack<vector<int>> s; 
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1; // default value
        while (!s.empty() && price >= s.top()[0]){
        	span += s.top()[1];
        	s.pop();
        }
        vector<int> temp = {price,span};
        s.push(temp);
        return span;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
