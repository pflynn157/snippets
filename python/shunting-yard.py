import queue

# Our stack
class Stack:
	def __init__(self):
		self.items = []
		
	def push(self, item):
		self.items.append(item)
		
	def pop(self):
		try:
			return self.items.pop()
		except Exception:
			return None
		
	def peek(self):
		try:
			return self.items[len(self.items)-1]
		except Exception:
			return None
			
	def size(self):
		return len(self.items)

# Breaks up a problem into its parts
def break_up(prob):
	objects = []
	current = ""
	
	for c in prob:
		if c == '+' or c == '-' or c == '*' or c == '/' or c == '(' or c == ')':
			objects.append(current)
			objects.append(str(c))
			current = ""
		else:
			current += c
			
	objects.append(current)
	return objects

# RPN converter
def rpn(objects):
	op_stack = Stack()
	output = queue.Queue(maxsize=50)
	
	for o in objects:
		if o == "+" or o == "-" or o == "*" or o == "/":
			while op_stack.peek() == "*" or op_stack.peek() == "/":
				output.put(op_stack.pop())
			op_stack.push(o)
		elif o == "(":
			op_stack.push(o)
		elif o == ")":
			while op_stack.peek() != "(":
				output.put(op_stack.pop())
			op_stack.pop()
		else:
			output.put(o)
	
	sz = op_stack.size()
	for x in range(0,sz):
		output.put(op_stack.pop())
		
	rpn = ""
	for s in range(0,output.qsize()):
		out = output.get()
		if out == "": continue
		rpn += str(out) + ","
	return rpn

# Main func
def main():
	print("Using this problem:")
	
	#prob = "3+10*7-2"
	prob = "(3+10*2)/2+3"
	objects = break_up(prob)
	output = rpn(objects)
	print(output)
	
main()
