class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        hm = {}
        count = 0
        
        for i, song in enumerate(time):
            if hm.get(song % 60):
                hm[song % 60] = hm[song % 60] + 1
            else:
                hm[song % 60] = 1
        print(hm)
        for key in hm:
            if key == 0 or key == 30:
                count += ((hm[key]- 1)*hm[key])/2
            elif key < 30 and hm.get(60-key):
                count += hm[key] * hm[60-key]
        return int(count)
                