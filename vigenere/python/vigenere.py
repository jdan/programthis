#!/usr/bin/python

from sys import argv, exit

def main():
    if len(argv) < 3:
        print 'Usage: ./vigenere.py <string> <key>'
        exit(1)
        
    string = argv[1].lower()
    key = argv[2].lower()
    
    s = ''
    for i, c in enumerate(string):
        if ord(c) < ord('a') or ord(c) > ord('z'):
            s += c
            continue
        index = ord(c) - ord('a')
        shift = ord(key[i % len(key)]) - ord('a')
        s += chr((index + shift) % 26 + ord('a'))
    
    print s
    
if __name__ == '__main__':
    main()