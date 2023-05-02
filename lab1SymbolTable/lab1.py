import pandas as pd
import random

charlist = list()
running = 1
while(running):
   print("1.Create Table 2.Search Table 3.Enter Symbol 4.Remove Symbol 5.View Table 6.Exit")
   option = int(input("Enter your Choice:"))
   if option == 1:
     exp = input()
     inputlist = [ord(i) for i in exp]
     for i in inputlist:
       if i not in charlist:
          charlist.append(i)
   if option == 2:
     sym = ord(input("Enter symbol:"))
     if sym in charlist:
        typeofchar = "identifier"
        if(33<= sym <= 47 or 60 <= sym <= 64):
          typeofchar = "operator"
        print(f"Symbol :{chr(sym)}  Address: {random.randrange(1000, 3000)} Type: {typeofchar}")
     else:
        print("Symbol's not in the table") 
   if option == 3:
     sym = ord(input("Enter symbol:"))
     if sym in charlist:
       print("Symbol already exists")
     else:      
       charlist.append(sym)
       typeofchar = "identifier"
       if(33<= sym <= 47 or 60 <= sym <= 64):
          typeofchar = "operator"
       print(f"Symbol :{chr(sym)}  Address: {random.randrange(1000, 3000)} Type: {typeofchar}")
   if option == 4:
     sym = ord(input("Enter symbol:"))
     if sym in charlist:
        charlist.remove(sym)
        print(f"{chr(sym)} removed from the Table")
     else:
        print("Symbol's not in the table")
   if option == 5:
     if charlist:
        for i in charlist:
          typeofchar = "identifier"
          if(33<= i <= 47 or 60 <= i <= 64):
            typeofchar = "operator"
          print(f"Symbol :{chr(i)}  Address: {random.randrange(1000, 3000)} Type: {typeofchar}")
     else:
       print("Table is Empty")
   if option == 6:
     running = 0