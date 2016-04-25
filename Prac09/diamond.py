# definicion de la funcion print_diamond
def print_diamond(size):
    upper_half = int((size + 1) / 2)
    lower_half = int(upper_half - 1)
    
    # print upper half diamond
    for i in range(upper_half+1):
        spaces = upper_half - i
        for j in range(spaces, 0, -1):
            print(" ", end="")
        
        asterisc = size - (2 * spaces)
        for j in range(asterisc):
            print("*", end="")
        
        print()
        
    #print lower half diamod
    for i in range(lower_half):
        spaces = i + 1;
        
        for j in range(spaces, 0, -1):
            print(" ", end="")
        
        asterisc = size - (2 * spaces)
        for j in range(asterisc):
            print("*", end="")
            
        print()
    
    print()
    
    
# ejecuta la funcion print_diamond()    
print_diamond(15)