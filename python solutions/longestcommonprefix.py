class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ""
        idx = 0
        if len(strs) == 0:
            return prefix
        while idx < len(strs[0]):
            for i, string in enumerate(strs[1::]):
                if idx >= len(string) or string[idx] != strs[0][idx]:
                    return prefix
            prefix += strs[0][idx]
            idx += 1
        return prefix