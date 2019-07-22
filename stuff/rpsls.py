import random

def name_to_number(name):
	if name == "Rock":
		return 0
	elif name == "Spock":
		return 1
	elif name == "Paper":
		return 2
	elif name == "Lizard":
		return 3
	elif name == "Scissors":
		return 4
	else:
		print "There is an invalid input:",name

def number_to_name(number):
	if number == 0:
		return "Rock"
	elif number == 1:
		return "Spock"
	elif number == 2:
		return "Paper"
	elif number == 3:
		return "Lizard"
	elif number == 4:
		return "Scissors"
	else:
		print "wrong input number to convert:",number

def rpsls(name):
	print "Player choose",name
	player = name_to_number(name)
	computer = random.randrange(0,5)
	print "Computer choose",number_to_name(computer)
	difference = (player-computer) % 5
	if difference == 0:
		print "Player and Computer choose the same"
	elif difference <= 2:
		print "Player wins"
	else:
		print "Computer wins"
	return

rpsls("Rock")
rpsls("Spock")
rpsls("Paper")
rpsls("Lizard")
rpsls("Scissors")