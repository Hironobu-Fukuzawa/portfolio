#!/bin/python3

import math
import os
import random
import re
import sys

def isAlphabet(char):
    ascii = ord(char)
    min, max = 65, 97
    return (min <= ascii < min + 26) or (max <= ascii < max + 26)
    
def encrypt(char, k):
    if(char.isupper()):
        ascii_num = 65
    else:
        ascii_num = 97
    return chr((ord(char) + k - ascii_num) % 26 + ascii_num)
        
def caesarCipher(s, k):
    enc = ""
    # Write your code here
    for char in s:
        if isAlphabet(char):
            enc += encrypt(char, k)
        else:
            enc += char
    return enc
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = input()

    k = int(input().strip())

    result = caesarCipher(s, k)

    fptr.write(result + '\n')

    fptr.close()
