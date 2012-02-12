#Author: Mark McCulloh
#Mark.McCulloh@gmail.com

from os.path import *

def CC_ShiftLetter(Character, Shift):
    Start = 0
    if Character >= 'a' and Character <= 'z': Start = 97
    elif Character >= 'A' and Character <= 'Z': Start = 65
    else: return Character
    return chr(((ord(Character) - Start) + Shift) % 26 + Start)

#If (File=True), InputString must be a filename (test1.txt)
#Encrypted string is stored in 'CC_' + filename (CC_test1.txt)
def CaesarCipher(InputString, Shift = 13, File = False):
    Name = InputString
    if File and isfile(Name):
        InputFile = open(Name)
        InputString = InputFile.read()
        InputFile.close()
    NewString = ''
    for Character in InputString:
        NewString += CC_ShiftLetter(Character, Shift)
    if File and isfile(Name):
        NewFile = open('CC_' + Name, 'w')
        NewFile.write(NewString)
        NewFile.close()
    return NewString

#'Dumb' Decryption, returns a list of all possible strings
def CC_Decrypt(InputString):
    Possibles = []
    for i in range(26):
        Possibles.append(CaesarCipher(InputString, i))
    return Possibles

def main():
    UserString = raw_input('What is the string you want to encrypt? ')
    Shifts = int(raw_input('How many shifts? '))
    print CaesarCipher(UserString, Shifts)
    raw_input()

if __name__ == '__main__':
    main()
