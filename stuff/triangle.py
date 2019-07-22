def triangle_area(base,height):
	area = (1.0/2)*base * height
	return area

def rectangle_perimeter(base,height):
	return 2*(base+height)

print int(triangle_area(5,6))
print rectangle_perimeter(5,6)

def factorial(n):
	if n == 0:
		return 1
	return n* factorial(n-1)

for x in xrange(1,10):
	print factorial(x)