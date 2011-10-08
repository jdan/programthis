from sys import argv

def main():
    if len(argv) > 1:
        radius = int(argv[1])
        char = 'X'
        if len(argv) > 2:
            char = argv[2]
        
        for a in range(radius * 2 + 1):
            line = ''
            for b in range(radius * 2 + 1):
                if abs((a-radius)**2 + (b-radius)**2 - radius**2) < 0.75*radius: 
                    line += char + ' '
                else:
                    line += '  '
            print line
    else:
        print 'Usage: python circle.py [RADIUS] [CHARACTER=X]'

if __name__ == '__main__':
    main()