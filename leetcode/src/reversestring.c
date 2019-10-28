class Solution:
    def reverseString(self, s: List[str]) -> None:
        for i in s[::-1]:
            s.remove(i)
            s.append(i)
            
            
