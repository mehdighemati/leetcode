class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        start = [0, 0]
        cur = start
        direction = 0
        directionName = "N"
        hm = ["N", "E", "S", "W"]
        
        #N = 0, E = 1, S = 2, W = 3
        dirs = [(0,1), (1,0), (0,-1), (-1,0)]
        
        for i in instructions:
            if i in {"L","R"}:
                if i == "L":
                    direction = ((direction - 1 )+4)%4
                    directionName = hm[direction]
                else:
                    direction = (direction +1 ) % 4
                    directionName = hm[direction]
            else:
                vector = dirs[direction]
                cur = [cur[0] + vector[0], cur[1] + vector[1]]
        print(cur)
        print(start)
        if start == cur or (directionName != "N"):
            return True
        else:
            return False
                