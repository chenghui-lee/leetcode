// Regex solution is kinda slow,
// can use another solution at here
// https://leetcode.com/problems/validate-ip-address/discuss/689845/0-ms-or-c%2B%2B-1ms-or-java-20-ms-or-python-or-2-line-REGEX-code-easy-detailed-solution
class Solution {
public:
    string validIPAddress(string IP) {
        regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        regex ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}");
        if (regex_match(IP, ipv4)) return "IPv4";
        else if (regex_match(IP, ipv6)) return "IPv6";
        else return "Neither";
    }
};
