class Solution:
    regex = re.compile('^[+-]?(\.\d+|\d+\.?\d*)([Ee][+-]?\d+)?$')
    def isNumber(self, s: str) -> bool:
        return bool(self.regex.match(s.strip()))
        
