from sys import argv

def main():
    gradient = '#X&1; '
    ease = 1.4
    
    if len(argv) > 1:
        radius = int(argv[1]) - 1
        char = 'X'
        
        for a in range(radius * 2 + 1):
            line = ''
            for b in range(radius * 2 + 1):
                offset = abs((a-radius)**2 + (b-radius)**2 - radius**2) / float(radius) * len(gradient)
                offset /= ease
                if offset >= len(gradient):
                    offset = len(gradient) - 1
                    
                line += gradient[int(offset)] + ' '
            print line
    else:
        print 'Usage: python circle.py [RADIUS]'

if __name__ == '__main__':
    main()