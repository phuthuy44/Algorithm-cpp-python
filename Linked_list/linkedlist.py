from typing import Optional
'''Create linked list'''
class Node :
     def __init__(self,data = None):
          self.data = data #Assign data
          self.nextval = None #Initialize
          #nextval is null
class SLinkedList :
     def __init__(self): #Function to initialize linked list
          self.head = None
     #starting from head
     def listprint(self):
          if self.head is None:
               print("List is empty!")
               return
          else:
               printval = self.head
               while printval is not None:
                    print(printval.data, " ")
                    printval = printval.nextval
     def Insertion_at_beginning(self,newdata):
          Newnode = Node(newdata) #create new node
          Newnode.nextval = self.head
          self.head = Newnode
     def Insertion_at_end(self,data):
          Newnode = Node(data)
          if self.head is None:
               self.head = Newnode
               return
          last = self.head#create last node
          while last.nextval is not None:
               last = last.nextval
          last.nextval = Newnode #Change the nextval of last node
     def Insertion_at_position(self,position,data):
          if position is None:
               print("The given position node is not found!")
               return
          Newnode = Node(data)
          Newnode.nextval = position.nextval
          position.nextval = Newnode #make next of position node as new node
     def deletion(self,position):
          temp = self.head #store header
          if self.head is not None: #Check if list is empty
               if temp.data == position:
                    self.head = temp.nextval
                    temp = None
                    return
          while temp is not None :
               if temp.data == position:
                    break          
               prev = temp 
               temp = temp.nextval
          if temp is None :
               return 
          prev.nextval = temp.nextval
          temp = None
class SwapNode :
     '''This is a Python code for a function called "swapPairs" which takes a singly-linked list as input and swaps every two adjacent nodes and returns the modified linked-list.

In the beginning, it checks for the base cases in which the head is None or there is only one node in the linked list.

The swapping takes place by using three variables tmp1, tmp2, and tmpx. initially, tmp1 and tmp2 point to the first two nodes of the linked list. Then, it swaps their values and updates the tmp1 and tmp2 to the next two nodes. It keeps doing this until reaching the end of the linked list. Finally, it returns the head of the modified linked list.

Note: This function uses an external Python class ListNode to define the structure of a node in the linked list'''
     def swapPair(self,head : Optional[Node]) -> Optional[Node]:
          if head is None :
               return None
          if head.nextval is None :
               return head
          temp1 = head
          temp2 = head.nextval
          while temp1.nextval is not None :
               if temp1 is not None and temp2 is not None :
                    print(temp1.data)
                    print(temp2.data)

                    tempval = temp1.data
                    tempval = temp1 
                    temp1.val = temp2.data
                    temp2.data = tempval

                    temp1 = temp2.nextval
                    if temp2.nextval is not None :
                         temp2 = temp2.nextval.nextval
                    else :
                         temp2 = None
               else :
                    break 
          return head
if __name__ == "__main__":
     list1 = SLinkedList()
     list1.head = Node("Mon")
     e2 = Node("Tue")
     e3 = Node("Wed")
     #link first Node to second Node
     list1.head.nextval = e2
     #link second Node to third Node
     e2.nextval = e3
     #Traversing the linked list
     #list1.listprint()# Mon Tue Wed
     '''Insert in a linked list'''
     #Insertion at the beginning
     list1.Insertion_at_beginning("Sun")
     #list1.listprint() # Sun Mon Tue Wed
     #Insertion at the end
     list1.Insertion_at_end("Thu")
     #list1.listprint() # Sun Mon Tue Wed Thu
     #Inserting in between two Data Nodes 
     list1.Insertion_at_position(list1.head.nextval, "Fri") #Sun Mon Fri Tue Wed Thu
     list1.Insertion_at_position(list1.head.nextval.nextval.nextval,"Sat") #Sun Mon Fri Tue Sat Wed Thu
     list1.listprint() 
     list1.deletion("Tue")
     print("List after deletion:")
     list1.listprint() 
     list1.deletion()
     list1.listprint() 






     