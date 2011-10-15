def main():
    string = raw_input('Enter a string: ')
    shift  = int(raw_input('How much do you want to shift? '))

    return_string = ''
    for char in string:
    # get the number of characters from 'a' (adjust for the correct case)
        if char >= 'a' and char <= 'z':
            base = ord('a')
        elif char >= 'A' and char <= 'Z':
            base = ord('A')
        else:
            return_string += char
            continue

        code = ord(char) - base

        # add the shift, mod 26 to reduce overflow, then add it back to a
        #    to get a legitimate ASCII value
        new_code = (code + shift) % 26 + base

        # append it to our return string
        return_string += chr(new_code)

    print 'Cipher: %s' % return_string

if __name__ == '__main__':
    main()
