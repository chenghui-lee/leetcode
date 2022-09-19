class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        m = {} # content , path
        res = []
        for i in range(len(paths)):
            temp = paths[i].split()
            path = temp[0] + '/'
            for j in range(1, len(temp)):
                open_col_index = temp[j].rindex('(')
                content = temp[j][open_col_index+1:-1]
                file = temp[j][:open_col_index]
                if content not in m:
                    m[content] = set()
                m[content].add(path+file)
        for k, v in m.items():
            if len(v) > 1:
                res.append(list(v))
        return res
