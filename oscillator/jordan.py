#!/usr/bin/python

from math import sin, pi
from time import sleep
from sys import stdout

def main():
    t = 0
    while 1:
        t += 1
        width = 60
        
        display = ['-'] * width
        
        for speed in range(1, 10):
            pos = int((sin(speed * t * pi / 180) + 1) * (width - 1)/2)
            display[pos] = 'O'
            
        stdout.write('\r%s' % ''.join(display))
        stdout.flush()
        sleep(0.1)
    
if __name__ == '__main__':
    main()