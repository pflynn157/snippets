#!/usr/bin/python3

## TODO: This should go in a separate file
# English language data
pronouns = [ "i", "you", "he", "she", "it", "we", "they" ]
nouns = [ "person", "man", "woman", "boy", "girl" ]
articles = ["a", "an", "the" ]
conjunctions = [ "and", "but", "or" ]
verbs = [ "am", "are", "is" ]
adverbs = [ "not", "here" ]
adjectives = [ "big", "small" ]
marks = [ ".", "!", "," ]

## Classification Symbols
PN = "PN"
N = "N"
V = "V"
A = "A"
AV = "AV"
MK = "MK"
CJ = "CJ"
AT = "AT"
U = "U"

##
## Tokenizes the sentence
##
def tokenize(text):
    tokens = list()
    sentence = list()
    word = ""
    for c in text:
        if c == ' ':
            if len(word) > 0:
                sentence.append(word.lower())
            word = ""
        elif c == '.' or c == '!' or c == '?':
            if len(word) > 0:
                sentence.append(word.lower())
            sentence.append(str(c))
            tokens.append(sentence)
            sentence = list()
            word = ""
        elif c == ',':
            sentence.append(word.lower())
            sentence.append(",")
            word = ""
        else:
            word += c
    if len(word) > 0:
        sentence.append(word.lower())
    if len(sentence) > 0:
        tokens.append(sentence)
    return tokens
   
##
## Classify the sentence based on word and symbol types.
## 
def classify_sentence(sentence):
    classified = list()
    for word in sentence:
        if word in pronouns:
            classified.append((PN, word))
        elif word in nouns:
            classified.append((N, word))
        elif word in articles:
            classified.append((AT, word))
        elif word in conjunctions:
            classified.append((CJ, word))
        elif word in marks:
            classified.append((MK, word))
        elif word in verbs:
            classified.append((V, word))
        elif word in adverbs:
            classified.append((AV, word))
        elif word in adjectives:
            classified.append((A, word))
        else:
            classified.append((U, word))
    return classified
    
def classify(tokens):
    tokens2 = list()
    for s in tokens:
        cld = classify_sentence(s)
        tokens2.append(cld)
    return tokens2

##
## The main controller
##

print("Enter a sentence:")
sentence = str(input())

tokens = tokenize(sentence)
print("")
print(tokens)


classified = classify(tokens)
print("")
print(classified)

##
## Print to a file
##
with open("output.txt", "w") as writer:
    for sentence in classified:
        for word in sentence:
            writer.write(word[0] + ":" + word[1] + "|")
        writer.write("\n")

