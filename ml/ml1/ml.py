#!/usr/bin/python3
import random

print("Welcome to ML!")
print("Function: y = x + 10")
print("")

def f(x):
    y = x + 10
    return y

class Perceptron():
    # x, y, bias
    weights = [ random.random(), random.random() ]
    learningRate = 0.00001
    
    def __init__(self):
        print(self.weights)
        
    def activate(self, x, y):
        s = (x * self.weights[0]) + (y * self.weights[1])
        if s > 0:
            return 1
        return 0
        
    def train(self, x, y, correct):
        guess = self.activate(x, y)
        error = correct - guess
        for i in range(0, len(self.weights)):
            if i == 0:
                inp = x
            else:
                inp = y
            self.weights[i] += self.learningRate * error * inp
        
# Create a perceptron
p = Perceptron()

##
## Create some training data
##
data_count = 500
x_data = list()
y_data = list()
correct = list()
for i in range(0, data_count):
    x = int(random.uniform(0, data_count))
    y = int(random.uniform(0, data_count))
    x_data.append(x)
    y_data.append(y)
    if y > f(x):
        correct.append(1)
    else:
        correct.append(0)
    
##
## Train
##
for n in range(0, 10):
    for i in range(0, data_count):
        p.train(x_data[i], y_data[i], correct[i])
print(p.weights)

##
## Run the program and calculate the percentage wrong
##
wrong = 0
list_guess = list()
list_correct = list()
for i in range(0, data_count):
    x = int(random.uniform(0, data_count))
    y = int(random.uniform(0, data_count))
    guess = p.activate(x, y)
    c = 0
    if y > f(x):
        c = 1
    if guess != c:
        wrong += 1
    if i < 10:
        list_guess.append(guess)
        list_correct.append(c)
percentage = float(wrong / data_count * 100)
print("Percentage wrong: " + str(percentage))
print("")
print("Correct: " + str(list_correct))
print("Guesses: " + str(list_guess))
    
    
