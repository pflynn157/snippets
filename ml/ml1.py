#!/usr/bin/python3

class Node:
	A = float(1)
	L = float(0.1)
	
	def calc(self, x):
		return x * self.A
	
	def train(self, data):
		x = data[0]
		y = data[1]
		guess = self.A * x
		error = y - guess
		if error != 0:
			A2 = self.L * (error / x)
			self.A += A2
			
	def train_all(self, data):
		for d in data:
			self.train(d)
			
	def print_a(self):
		print(self.A)

# Formula: y = 1.5x

training = [(0,0)]
for i in range(1, 10000):
	y = float(1.5) * float(i)
	training.append((i,y))
	
#print("")
#print("Training data:")
#print(training)
#print("")

node = Node()
node.train_all(training)

print("A: ")
node.print_a()
print("===================")
print("Enter values (0 = exit)")

enter = float(input("> "))
while enter != 0:
	expected = float(enter*1.5)
	guess = node.calc(enter)
	print("Guess: " + str(guess) + " | Expected: " + str(expected))
	print("")
	enter = float(input("> "))


