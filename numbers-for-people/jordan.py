#!/usr/bin/python
from sys import argv

def number_to_human(n):
    biggest = ['', '', 'thousand', 'million', 'billion', 'trillion', 
               'quadrillion', 'quintillion', 'sextillion', 
               'septillion', 'octillion', 'nonillion', 'decillion']
               
    tens = ['', '', 'twenty', 'thirty', 'forty', 'fifty', 'sixty',
            'seventy', 'eighty', 'ninety']

    teens = ['ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 
             'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
             
    digits = ['', 'one', 'two', 'three', 'four', 'five',
              'six', 'seven', 'eight', 'nine']
              
    out = ''
              
    # isolate the digits of n into groups of three
    digit_groups = []
    while n > 0:
        digit_groups.append(n % 1000)
        n /= 1000
    digit_groups.reverse()
        
    for i, k in enumerate(digit_groups):
        if k != 0:
            if k > 99:
                out += digits[k / 100] + ' hundred '
                k %= 100
            
            if k > 19:
                out += tens[k / 10]
                k %= 10
            
                if k > 0:
                    out += '-' + digits[k]  
            elif k > 9:
                out += teens[k - 10]
            else:
                out += digits[k]
                
            if i != len(digit_groups) - 1:
                out += ' ' + biggest[len(digit_groups) - i] + ' '
            
    return out
    
if __name__ == '__main__':
    if len(argv) < 2:
        print 'Please include a number to translate'
    else:
        print number_to_human(int(argv[1]))
        
    