# digital.py
# Jordan Scales 
# http://programthis.net

# Synopsis: display numbers and letters on a 7-panel LED (like an alarm clock)
#     ____
#   _|__0_|_
#  | |    | |
#  |1|____|2|
#   _|__3_|_
#  | |    | |
#  |4|____|5|
#    |__6_|
#   
#   6 x 7 grid


# Example: The number 2

#    XXXX 
#        X
#        X
#    XXXX
#   X
#   X
#    XXXX
#
#   cells 0, 2, 3, 4, and 6 filled in

numbers = { '0' : '012456',
            '1' : '25',
            '2' : '02346',
            '3' : '02356',
            '4' : '1325',
            '5' : '01356',
            '6' : '013456',
            '7' : '025',
            '8' : '0123456',
            '9' : '01235' }
            
def main():
    my_input = raw_input()
    panels = []
    
    for char in my_input:
        if char in numbers:
            panels.append(numbers[char])
            
    # generate a 2D array for output
    output = []
    for row in range(7):
        output.append([' '] * len(panels) * 7)
        
    for i in range(len(panels)):
        for cell in panels[i]:
            if cell == '0':
                output[0][7 * i + 1] = 'X'
                output[0][7 * i + 2] = 'X'
                output[0][7 * i + 3] = 'X'
                output[0][7 * i + 4] = 'X'
            elif cell == '1':
                output[1][7 * i] = 'X'
                output[2][7 * i] = 'X'
            elif cell == '2':
                output[1][7 * i + 5] = 'X'
                output[2][7 * i + 5] = 'X'
            elif cell == '3':
                output[3][7 * i + 1] = 'X'
                output[3][7 * i + 2] = 'X'
                output[3][7 * i + 3] = 'X'
                output[3][7 * i + 4] = 'X'
            elif cell == '4':
                output[4][7 * i] = 'X'
                output[5][7 * i] = 'X'
            elif cell == '5':
                output[4][7 * i + 5] = 'X'
                output[5][7 * i + 5] = 'X'
            elif cell == '6':
                output[6][7 * i + 1] = 'X'
                output[6][7 * i + 2] = 'X'
                output[6][7 * i + 3] = 'X'
                output[6][7 * i + 4] = 'X'
              
    print
    for row in output:
        print ''.join(row)
    print
        
if __name__ == '__main__':
    main()
    
    
    
    
    
    
    
   