#!/usr/bin/python3
import math

##
## Our node
##
class Node:
	weights = []
	
	def __init__(self, weights):
		self.weights = weights
		
	def calc(self, inputs):
		result = float(0)
		for i in range(0, len(self.weights)):
			result += self.weights[i] * inputs[i]
		result = float(1 / (1 + math.pow(math.e, -result)))
		return result

##
## Test function
##
def simple_calc(weights, inputs):
	answer = list()
	for i in range(0, len(weights)):
		row = weights[i]
		result = float(0)
		for j in range(0, len(row)):
			result += row[j] * inputs[j]
		result = float(1 / (1 + math.pow(math.e, -result)))
		answer.append(result)
	return answer

# Example layout:
# W11, W21
# W12, W22
weights = [
	[ 0.9,		0.3],
	[ 0.2,		0.8]
]

inputs = [ 1.0, 0.5 ]

##
## A network
##
network = [
	Node(weights[0]), Node(weights[1])
]

# Expected (unweigh): 1.05, 0.6
# Expected: 0.7408, 0.6457
answer1 = simple_calc(weights, inputs)
print(answer1)

# Calculate based on the network
answer2 = [ network[0].calc(inputs), network[1].calc(inputs) ]
print(answer2)

