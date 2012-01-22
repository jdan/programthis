#!/usr/bin/python
import sys
import random

def main():
    if len(sys.argv) < 2:
        print 'Usage: ./wordfind.py word1 [word2] [word3] ...'
        print 'ie: ./wordfind.py `cat words.txt`'
        sys.exit(1)
        
    if sys.argv[1] == 'debug':
        words = sys.argv[2:]
    else:
        words = sys.argv[1:]
        
    r = c = 22
    
    # create the grid
    grid = []
    for a in range(r):
        row = []
        for b in range(c):
            row.append(' ')
        grid.append(row)
        
    # place the words
    for word in words:
        while 1:
            # choose random orientation
            if random.random() > 0.5:  # horizontal
                row = random.randint(0, r-1)
                col = random.randint(0, c - len(word) - 1)
                
                fits = True
                for i, ch in enumerate(word):
                    if (grid[row][col + i] == ' ') or (grid[row][col + i] == ch):
                        pass
                    else:
                        fits = False
                        break
                
                if fits:
                    for i, ch in enumerate(word):
                        grid[row][col + i] = ch
                    break
                    
            else: # vertical
                row = random.randint(0, r - len(word) - 1)
                col = random.randint(0, c - 1)
                
                fits = True
                for i, ch in enumerate(word):
                    if (grid[row + i][col] == ' ') or (grid[row + i][col] == ch):
                        pass
                    else:
                        fits = False
                        break
                
                if fits:
                    for i, ch in enumerate(word):
                        grid[row + i][col] = ch
                    break
                    
    if sys.argv[1] != 'debug':
        letters = 'abcdefghijklmnopqrstuvwxyz'
        for a in range(r):
            for b in range(c):
                if grid[a][b] == ' ':
                    grid[a][b] = letters[random.randint(0, 25)]
                   
    for row in grid:
        print ' '.join(row)   
        
    print ' '
    print '\n'.join(words)
    
if __name__ == '__main__':
    main()