while(True):
    print("1: Assignment 2: Arithmetic 3: Relational 4: exit")
    code = int(input())
    if code == 1:
        print("Enter Assignment Equation")
        str = input()
        str_ls = str.split('=')
        a = str_ls[0]
        b = str_ls[1]
        print(f"temp = {a}")
        print(f"{b} = temp")
    elif code ==2:
        print("Enter Arithmetic Equation")
        str = input()
        first = str[:3]
        second = str[3:]
        print(f"temp = {first}")
        print(f"temp1 = temp{second}")
    elif code == 3:
        print("Enter Relational Equation")
        str = input()
        str_ls = str.split(' ')
        a = str[:1]
        op = str[1:3]
        b = str[3:]
        address = 100
        print(f"{address} if {a}{op}{b} goto {address+3}")
        address = address+1
        print(f"{address} t=0")
        address = address+1
        print(f"{address} goto {address+2}")
        address = address+1
        print(f"{address} t=1")
    else:
        break  

