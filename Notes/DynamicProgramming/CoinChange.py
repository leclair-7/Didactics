



denominations = [6,5,1]

quantity = 9


def coinChange(quantity_, denominations_):

	#makes a array [0.. quantity]
	upto = [i for i in range(quantity_+1) ]

	for i in range(len(upto)):

		for j in denominations_:

			if i - j >= 0:

				if i - j + 1 < upto[i]:
					upto[i] = i - j + 1
	
	return upto[-1]

result = coinChange(quantity,denominations)  

print(result)




