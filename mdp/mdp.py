'''
Made a small part of a small part of the MDP example here:
http://www0.cs.ucl.ac.uk/staff/d.silver/web/Teaching_files/MDP.pdf


Sooo A MRP --> Markov Reward Process 
		has states <S,P,R,gamma>
				state, probab of getting to next state?, reward (of state), gamma discount

v(s) = expected discouted reward you'll get at S
v(s) = E(Gt | St = s )

v(s) is expected long term value of discounted sum

discount value is the value of future rewards


'''

gamma = .5

class State:
	gamma = gamma
	def __init__(self, title, reward):

		'''
		self.outNodes
		States we can transition to :
							probability of getting there 
		'''
		self.id = title
		self.outNodes = {}
		self.reward = reward
	def getVS(self):
		value = self.reward
		for k,v in self.outNodes:

	def getReward(self):
		return self.reward

	def addOutNode(self, to_node, probability):
		if not (to_node in self.outNodes):
			self.outNodes[to_node] = probability
		else:
			print("You already have this node in the MDP")

	def getid(self):
		return self.id

	def getprobLandingOnState(self,destination):
		if not (destination in self.outNodes):
			return False
		else:
			return self.outNodes[destination]



facebook = State("facebook", -1)
class1   = State("class 1", -2)

sleep = State("sleep", 0)
class2   = State("class 2", -2)
pub = State("pub", -1)
class3 = State("class 3", -2)

epass=  State("pass", 10)

facebook.addOutNode(facebook,.9 )
facebook.addOutNode(class1,.1 )

class1.addOutNode(facebook, .5)
class1.addOutNode(class2, .5)

pub.addOutNode(class1,.2)
pub.addOutNode(class2,.4)
pub.addOutNode(class3,.4)

class2.addOutNode(sleep, .2)
class2.addOutNode(class3, .8)

class3.addOutNode(pub,.4)
class3.addOutNode(epass,.6)

print(class1.getprobLandingOnState(facebook))


temp = class1
G_temp = temp.getReward()

for i, v in enumerate([class1,class2,class3,epass,sleep]):
	if i ==0:
		continue
	else:
		G_temp += ( gamma**i ) * v.getReward()

print("G_temp",G_temp)



