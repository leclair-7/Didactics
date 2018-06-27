'''
Made a small part of a small part of the MDP example here:
http://www0.cs.ucl.ac.uk/staff/d.silver/web/Teaching_files/MDP.pdf

'''
class State:

	def __init__(self, title):

		'''
		self.outNodes
		States we can transition to :
							probability of getting there 
		'''
		self.id = title
		self.outNodes = {}

	def addOutNode(self, to_node, probability):
		if not (to_node.getid() in self.outNodes):
			self.outNodes[to_node.getid()] = probability
		else:
			print("You already have this node in the MDP")

	def getid(self):
		return self.id

	def getprobLandingOnState(self,destination):
		if not (destination.getid() in self.outNodes):
			return False
		else:
			return self.outNodes[destination.getid()]



facebook = State("facebook")
class1   = State("class 1")

facebook.addOutNode(facebook,.9 )
facebook.addOutNode(class1,.1 )
class1.addOutNode(facebook, .5)

print(class1.getprobLandingOnState(facebook))