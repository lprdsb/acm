#程序加载
def loadProgram(file, mem, address):
    ########## Begin ##########
    txt=open(file,'r')
    n=0
    while True:
        line=txt.readline()
        
        a=line[4:len(line)-1]
        t=len(a)
        A=[]
        while n<t:
            if a[0]==' ' and a[1]==' ':
                a=a[1:]
                n=n+1
            else:
                A.append(a[0])
                a=a[1:]
                n=n+1
        m=''.join(A)
        while len(m) and m[0]==' ':
            m=m[1:]
        while len(m) and (m[-1]==' ' or m[-1]=='\n'):
            m=m[:-1]
        
       
        if line=='':
            break
        mem[address]=m
        address=address+1
    
    ########## End ##########
    print(mem)