#Author: Mark McCulloh
#Mark.McCulloh@gmail.com

def StringToBinary(InputString):
    NewString = ''
    for Character in InputString:
        Number = ord(Character)
        Exponent = 7
        while Exponent > -1:
            if 2 ** Exponent <= Number:
                NewString += '1'
                Number -= 2 ** Exponent
            else:
                NewString += '0'
            Exponent -= 1
        NewString += ' '
    return NewString.rstrip()

def main():
    print StringToBinary(raw_input())

if __name__ == '__main__':
    main()
