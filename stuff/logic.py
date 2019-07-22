a = True
print a
print not a

def assess(v):
	"""
	This is a documentation string
	"""
	if v>20:
		print "high"
	elif v>10:
		print "medium"
	else:
		print "low"
	return

assess(5)
assess(10)
assess(15)
assess(20)
assess(25)
print type(assess(25))