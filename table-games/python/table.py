def main():
    my_input = raw_input("Enter some words, separated by spaces: ")
    a = my_input.split()
    
    title = raw_input("Enter a title: ")
    
    max_length = len(title)
    for elem in a:
        if len(elem) > max_length:
            max_length = len(elem)
            
    max_length += 3
    output = '+' + '-' * max_length + '+\n'
    ws = max_length - len(title)
    output += '|' + ' ' * (ws / 2) + title + ' ' * (ws - ws/ 2) + '|\n'
    output += '+' + '-' * max_length + '+\n'
    
    for elem in a:
        output += '| ' + elem.ljust(max_length - 1) + '|\n'
    
    output += '+' + '-' * max_length + '+\n'
    
    print output
    
if __name__ == '__main__':
    main()
    