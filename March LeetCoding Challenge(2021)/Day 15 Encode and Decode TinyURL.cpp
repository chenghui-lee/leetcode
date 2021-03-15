class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string, string> m;
    string lib = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
    string encode(string longUrl) {
        string res = "";
        for(int i=0; i<8; i++){
            res += lib[rand() % lib.size()];
        }    
        m[res] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
