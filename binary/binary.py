#!/usr/bin/python

def to_binary(i):
    exponent = 0
    total = 0
    while i > 0:
        total += (i % 2) * (10 ** exponent)
        i /= 2
        exponent += 1
    return total

def main():
    input_string = raw_input()
    print ' '.join([str(to_binary(ord(char))).rjust(8, '0') for char in input_string])
    
if __name__ == '__main__':
    main()