# import hashlib
import hashlib

class HashTable(object):
    
    def __init__(self, size=10) -> None:
        self.size = size
        self.table = [[] for _ in range(self.size)]
        
    def hash(self, key) -> int:
        return int(hashlib.md5(key.encode()).hexdigest(), base=16) % self.size
    
    def add(self, key, value) -> None:
        index = self.hash(key)
        for data in self.table[index]:
            # If there is an existing key
            if data[0] == key:
                # overwrite the value
                data[1] == value
        else:
            self.table[index].append([key, value])
            
    def remove(self, key) -> None:
        index = self.hash(key)
        for data in self.table[index]:
            if data[0] == key:
                self.table[index].remove(data)

# class HashTable(object):

#     def __init__(self, size=10):
#         self.size = size
#         self.table = [[] for _ in range(self.size)]

#     def hash(self, key) -> int:
#         # hash_val = hashlib.md5(key.encode()).hexdigest()
#         # hash_val_int = int(hash_val, base=16) % self.size
#         # return hash_val_int
#         return int(hashlib.md5(key.encode()).hexdigest(), base=16) % self.size

#     def add(self, key, value) -> None:
#         index = self.hash(key)
#         # If there is an existing key, then overwrite the value
#         for data in self.table[index]:
#             if data[0] == key:
#                 data[1] = value
#                 break
#         else:
#             self.table[index].append([key, value])

if __name__ == "__main__":
    hash_table = HashTable()
    print(hash_table.table)
    print(hash_table.hash("car"))
    print(hash_table.hash("pc"))
    hash_table.add("car", "Tesla")
    print(hash_table.table)
    hash_table.add("car", "Toyota")
    hash_table.remove("car")
    hash_table.remove("car")
    hash_table.remove("car")
    print(hash_table.table)
