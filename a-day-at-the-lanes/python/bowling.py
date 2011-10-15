from sys import argv

def main():
    score = 0
    if len(argv) < 2:
        print 'Usage: python bowling.py MARKS'
        print '(i.e. python bowling.py XXXXXXXXXXXX)'
        return
        
    c = argv[1]
    
    for i in range(len(c)):
        # see if we're in the tenth frame
        tenth_frame = False
        if c[-3] == 'X' or c[-2] == '/':
            # then we have 3 shots in the 10th frame
            if i >= len(c) - 3:
                tenth_frame = True
        else:
            # we have 2 shots in the 10th frame
            if i >= len(c) - 2:
                tenth_frame = True
                
        if tenth_frame:
            # we're in the tenth frame
            if c[i] == 'X':
                score += 10
            elif c[i] == '/':
                prev = c[i-1]
                if prev == '-':
                    prev = 0
                else:
                    prev = int(prev)
                    
                score += 10 - prev
            elif c[i] == '-':
                pass
            else:
                score += int(c[i])
        else:
            # we're not
            if c[i] == 'X':
                # strike!
                score += 10
                # calculate the next two shots, and add those as well
                shot1 = c[i+1]
                shot2 = c[i+2]
                if shot1 == 'X':
                    shot1 = 10
                elif shot1 == '-':
                    shot1 = 0
                else:
                    shot1 = int(shot1)
                
                if shot2 == 'X':
                    shot2 = 10
                elif shot2 == '/':
                    shot2 = 10 - shot1
                elif shot2 == '-':
                    shot2 = 0
                else:
                    shot2 = int(shot2)
                    
                score += shot1 + shot2
            
            elif c[i] == '/':
                # spare!
                # if it's a spare, the previous character HAS to be a number (or a dash)
                prev = c[i-1]
                if prev == '-':
                    prev = 0
                else:
                    prev = int(prev)
                
                score += 10 - prev
                
                # find the next shot, and add that as well
                shot1 = c[i+1]
                # it can be a strike, dash, or number
                if shot1 == 'X':
                    shot1 = 10
                elif shot1 == '-':
                    shot1 = 0
                else:
                    shot1 = int(shot1)
                    
                score += shot1
                
            elif c[i] == '-':
                # gutter ball :(
                pass 
                
            else:
                # just a number
                score += int(c[i])
                
    print score
    
if __name__ == '__main__':
    main()