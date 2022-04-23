#include<time.h>

class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string, string> m;
    string lib = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
    string encode(string longUrl) {
        string hash = "";
        for(int i=0; i<8; i++){
            hash += lib[rand() % lib.size()];
        }    
        m[hash] = longUrl;
        return hash;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
