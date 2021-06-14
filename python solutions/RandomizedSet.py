class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.hm = {}
        self.arr = []
        
        
        

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if self.hm.get(val):
            return False
        else:
            self.arr.append(val)
            self.hm[val] = len(self.arr) - 1 
            return True

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if self.hm.get(val):
            index = self.hm.get(val)
            del self.hm[val]
            
            #swap last element with curr
            temp = self.arr[-1]
            self.arr[-1] = self.arr[index]
            self.arr[index] = temp
            
            self.arr.pop()
            print(self.arr)
            return True
        else:
            return False
        
            
        

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        print(self.arr)
        index = random.randint(0, len(self.arr) - 1)
        print(self.arr[index])
        return self.arr[index]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()