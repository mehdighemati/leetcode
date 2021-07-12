class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.queue = [0]*size
        self.curSize = 0
        self.maxSize = size
        self.head = 0
        self.tail = 0


    def avg(self):
      sum = 0;
      if self.curSize == self.maxSize:
        for i in range(0, self.maxSize):
          sum += self.queue[i]
      else:
        for i in range(self.head, self.tail):
          sum += self.queue[i]
      return sum / self.curSize

    def next(self, val: int) -> float:
      if self.curSize == 0:
        self.queue[0] = val
        self.tail += 1
        self.curSize += 1
        return val
      if self.curSize != self.maxSize:
        self.queue[self.tail] = val
        self.tail +=1
        self.curSize +=1
        return self.avg()
      else:
        self.queue[self.head] = val
        self.head = (self.head + 1) % self.maxSize
        self.tail = (self.tail + 1) % self.maxSize
        return self.avg()