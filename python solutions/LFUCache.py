class Node:
    def __init__(self, key: int,  val: int, count: int):
        self.val = val
        self.key = key
        self.count = count
 
class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.hm = {}
        self.freq = defaultdict(OrderedDict)
        self.lowestfreq = None
        

    def get(self, key: int) -> int:
        if not self.hm.get(key):
            return -1
        
        foundNode = self.hm[key]
        del self.freq[foundNode.count][key]
        
        foundNode.count += 1
        self.freq[foundNode.count][key] = foundNode
        
        if not self.freq[self.lowestfreq]:
            self.lowestfreq +=1
        
        return foundNode.val

    def put(self, key: int, value: int) -> None:
        if not self.capacity:
            return
        
        #Exists
        if self.hm.get(key):
            self.hm[key].val = value
            self.get(key)
            return
        
        if len(self.hm) == self.capacity:
            #Remove LFU
            lfukey, _ = self.freq[self.lowestfreq].popitem(last=False)
            del self.hm[lfukey]
            
        #Put in the new node
        newNode = Node(key, value, 1)
        self.hm[key] = newNode
        self.freq[1][key] = newNode
        self.lowestfreq = 1
        
        
                
        


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)