from sys import argv

def main():
    if len(argv) > 3:
        try:
            content = open(argv[1]).read()
        except IOError:
            print 'File not found.'
            
        width = int(argv[2])
        height = int(argv[3])
        pos = 0
        
        line = ''
        
        for char in content:
            if char not in '" \'':
                line += char
                pos += 1
            
                if pos % width == 0:
                    if pos % (width * height) == 0:
                        line += '\n' 
                    print line
                    line = ''
                    
        print line
    else:
        print 'Usage: python block_text.py [FILE] [BLOCK WIDTH] [BLOCK HEIGHT]'
        
if __name__ == '__main__':
    main()