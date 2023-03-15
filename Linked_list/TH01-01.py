class Node:
     def __init__(self, data= None, next= None):
          self.data = data
          self.next = next
def printList(self):
     if head == None:
          return "List is empty!"
     printval = self
     while printval is not None:
          print(printval.data, end ="->")
          printval = printval.next
     print("End")
#remove duplicates from a sorted list
def remove_duplicates(head):
     #do nothing if the list is empty
     if head is None:
          return "List is empty!"
     current = head #store head 
     #compare current node with the next node
     while current.next is not None:
          if current.data == current.next.data:
               temp = current.next.next 
               current.next = temp
          else :
               current = current.next #only advance if no deletion
     return head
#to Reverse every group of k nodes in given linked list
def reverse_k_group(head, k):
     if head is None:
          return "List is empty!"
     #start with current node
     current = head
     #reverse next k nodes
     prev = None
     count = 0
     while current is not None and count < k:
          count += 1
          #tricky: note the next node is not the current node
          next = current.next
          #move the current node onto the result 
          current.next = prev
          #update the previous to current node 
          prev = current
          #remove to the next node
          current = next
     head.next = reverse_k_group(current, k) #recursive call for remaining nodes
     return prev # return the previous node( to link every group of k nodes)
if __name__ == "__main__":
     #input list elements
     list = [1,2,2,2,3,4,4,5]
     #construct linked list 
     head = None
     head1 = None
     for i in reversed(range(len(list))):
          head = Node(list[i],head)
     head = remove_duplicates(head)
     printList(head)
     for i in reversed(range(8)):
          head1 = Node(i+1,head)
     head1 = reverse_k_group(head,3)
     printList(head1)