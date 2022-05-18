#!/usr/bin/python3
import random

vowels = ["a", "aa", "e", "ee", "o", "oo", "oi", "i", "ii", "u", "ww" ]
consonants = [ "b", "c", "d", "k", "f", "h", "j", "l", "m", "n", "p", "r", "ss", "s", "t", "v", "z", "zs", "sh", "y" ]
lengths = [3, 4, 5, 6, 7]

words = []
current = ""

length = lengths[random.randint(0, 4)]
for i in range(0, length + 1):
    if (i + 1) % 2 == 0:
        current += vowels[random.randint(0, len(vowels)-1)]
    else: 
        current += consonants[random.randint(0, len(consonants)-1)]
      
print(current)

