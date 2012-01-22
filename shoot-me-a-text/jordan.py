#!/usr/bin/python
def main():
    message = raw_input()
    output  = ''
    
    kb = { 2 : 'abc', 3 : 'def', 4 : 'ghi', 5 : 'jkl', 6 : 'mno', 7 : 'pqrs', 8 : 'tyv' , 9 : 'wxyz' }
    
    for char in message:
        if char == ' ':
            if len(output) > 0 and output[-1] == '0':
                output += ' '
            output += '0'
            continue
            
        for key in kb:
            if char <= kb[key][-1]:
                i = kb[key].find(char)
                if i == -1:
                    break
                else:
                    if len(output) > 0 and output[-1] == str(key):
                        output += ' '
                    output += str(key) * (i + 1)
                    break
                    
    print output
    
if __name__ == '__main__':
    main()