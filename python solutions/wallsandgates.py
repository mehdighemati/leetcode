class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        inf = 2147483647
        rows = len(rooms)
        cols = len(rooms[0])
        
        if rows == 1 and cols == 0:
            if rooms[0][0] == inf or rooms[0][0] == -1 or rooms[0][0] == 0:
                return
        

        # queue up all the gates
        queue = collections.deque()
        for row in range(rows):
            for col in range(cols):
                if rooms[row][col] == 0:
                    queue.append((row,col))
        
        #do bfs on the queue ish


        dirs = [(-1,0), (1, 0), (0,-1), (0, 1)]
        while queue:
            row, col = queue.popleft()
            for x,y in dirs:
            #check immediate neighbours, check  
                if rows > row+x >= 0 and cols > col+y >= 0 and rooms[row+x][col+y] > rooms[row][col]:
                    rooms[row+x][col+y] = rooms[row][col] + 1
                    queue.append(((row+x),(col+y)))