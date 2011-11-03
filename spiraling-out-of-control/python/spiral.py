def main():
    length = int(raw_input('Enter an odd side length: '))
    while length % 2 == 0:
        length = int(raw_input('Enter an odd side length: '))
    
    spiral = []*length
    for a in range(length):
        spiral.append([-1]*length)
    
    r, c = length / 2, length / 2
    dr, dc = -1, 0
    v = 0
    for i in range(length**2):
        spiral[r][c] = chr(v + ord('a'))
        
        if dr == 0:
            look_r = dc
            look_c = 0
        else:
            look_r = 0
            look_c = -dr
        
        if spiral[r+look_r][c+look_c] == -1:
            dr = look_r
            dc = look_c
            
        r += dr
        c += dc
        
        v += 1
        v %= 26
        
    for line in spiral:
        print ' '.join(map(str, line))
    
if __name__ == '__main__':
    main()