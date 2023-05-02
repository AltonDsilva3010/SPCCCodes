n = int(input('Enter the no. of statements : '))
inpt = [input() for i in range(n)]
reg = [-1 for i in range(2)]
result =[inpt[i][0] for i in range(n)]
arg1 =[inpt[i][2] for i in range(n)]
op = [inpt[i][3] for i in range(n) if len(inpt[i])==5]
arg2=[inpt[i][4] for i in range(n) if len(inpt[i])==5]

def findReg(operand):
    return -1 if operand not in reg else f'R{reg.index(operand)}'
   
def getReg(operand):
    i = reg.index(-1)
    reg[i]=operand
    return f'R{i}'
   
def getInstr(operator):
    match operator:
        case '+' :
            return 'ADD'
        case '-':
            return 'SUB'
        case '*':
            return 'MUL'
        case '/':
            return 'DIV'

for i in range(n):
    if arg1[i] not in reg and arg2[i] not in reg: 
        temp1 = getReg(arg1[i])
        print(f'MOV {arg1[i]},{temp1}')
        instr = getInstr(op[i]) if len(op) > i else None
        if instr : 
            print(f'{instr} {arg2[i]},{temp1}')
            reg[int(temp1[-1])] = result[i] 
    else :        
        instr = getInstr(op[i]) if len(op) > i else None
        if instr :
            print(f'{instr} R{reg.index(arg1[i])},R{reg.index(arg2[i])}')
            reg[reg.index(arg2[i])] = result[i]
        else :
            print(f'MOV R{reg.index(arg1[i])},{result[i]}')
    
