from __future__ import annotations
from typing import Any

# Define Node Object
class Node:
    def __init__(self, data: Any, node_next: Node = None):
        self.data = data
        self.next = node_next
        
class LinkedList:
    def __init__(self) -> None:
        self.head = None
        
    # append the node in the last link
    def append(self, data: Any) -> None:
        new_node = Node(data)
        # Append new node in the head
        if self.head == None:
            self.head = new_node
            return
        
        # Append new node in the last
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node

    def insert(self, data: Any) -> None:
        new_node = Node(data)
        # Move head node to the new node
        new_node.next = self.head
        # replace previous head with the new node
        self.head = new_node
        
    def print(self) -> None:
        target_node = self.head
        while target_node:
            print(target_node.data)
            target_node = target_node.next
        return
    
    # Find some data in all nodes, remove the target node only
    def remove(self, data: Any) -> None:
        current_node = self.head
        if current_node and current_node.data == data:
            self.head = current_node.next
            current_node = None
            return
        
        previous_node = None
        while current_node and current_node.data != data:
            previous_node = current_node
            current_node = current_node.next
            
        if current_node is None:
            return
        
        previous_node.next = current_node.next
        current_node = None
    
    def reverse(self) -> LinkedList:
        rev_list = LinkedList()
        head = self.head
        last_node = head.next
        while last_node:
            last_node = last_node.next
        head = last_node.next
        
        return rev_list
    
if __name__ == "__main__":
    ll = LinkedList()
    # ll.append(Node(10))
    # ll.append(Node(20))
    # ll.append(Node(30))
    ll.append(10)
    ll.append(20)
    ll.append(30)    
    ll.insert(0)
    # ll.print()
    # ll.remove(55)
    # ll.print()
    ll.reverse()
    ll.print()
