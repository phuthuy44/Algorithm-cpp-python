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
          if self.head is not None: #Check if list is not empty
               #If head node itself holds the key to be deleted
               if temp.data == position:
                    self.head = temp.nextval
                    temp = None
                    return
          #Search for the node to be deleted,keep track of the previous node as we need to change
          while temp is not None :
               if temp.data == position:
                    break          
               prev = temp 
               temp = temp.nextval
          #If key was not present in linked list
          if temp is None :
               return 
          #Unlink the previous node from the linked list
          prev.nextval = temp.nextval
          temp = None
     def swapNodes(self,x,y):
          if x == y :
               return
          prevX = None
          currentX = self.head
          while currentX is not None and currentX.data!= x:
               prevX = currentX
               currentX = currentX.nextval
          prevY = None
          currentY = self.head
          while currentY is not None and currentY.data!= y:
               prevY = currentY
               currentY = currentY.nextval
          if currentX is None or currentY is None:
               return 
          if prevX is not None:
               prevX.nextval = currentY
          else :
               self.head = currentY
          if prevY is not None:
               prevY.nextval = currentX
          else :
               self.head = currentX
          
          temp = currentX.nextval
          currentX.nextval = currentY.nextval
          currentY.nextval = temp 
     def find_lengthOfLinkedList(self):
          temp = self.head #Initialize temp 
          count = 1 #Initialize count

          #Loop while end of linked list is not reached
          while temp is not None:
               count += 1
               temp = temp.nextval
          return count
     def Search_element(self,data):
          current = self.head #Initialize current to head 
          #lopp till current not equal to None
          while current is not None:
               if current.data == data:
                    return True #data is founded 
               current = current.nextval
          return False #data is not founded
     def reverse_LinkedList(self):
          prev = None 
          current = self.head
          while current is not None:
               nextval = current.nextval
               current.nextval = prev
               prev = current
               current = nextval
          self.head = prev
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
     print("List after swapping nodes:")
     list1.swapNodes("Mon","Fri")
     list1.listprint() 
     print("Length of the linked list is : ", list1.find_lengthOfLinkedList())
     if list1.Search_element("Sat") == True:
          print("Element is present in the linked list")
     else :
          print("Element is not present in the linked list")
     list1.reverse_LinkedList()
     print("List after reversing the linked list:")
     list1.listprint() 




     