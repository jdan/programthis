#!/usr/bin/python
def main():
    my_in = raw_input()
    my_out = ''
    
    for word in my_in.split():
        if word[0] in 'aeiou':
            front = word
            back = 'w'
        else:
            first = min([word.find(c) for c in 'aeiou' if word.find(c) > -1])
            front = word[:first]
            back = word[first:]
            if front[0] >= 'A' and front[0] <= 'Z':
                front = front.lower()
                back = back[0].upper() + back[1:]
            
        my_out += '%s%say ' % (back, front)
        
    print my_out
    
if __name__ == '__main__':
    main()