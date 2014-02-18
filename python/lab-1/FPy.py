import scipy.optimize as optimize
import numpy as np

num = input('Numeral: ')

def func(x):
	if num == '2': return np.exp(x) - 3*x
	elif num == '4': return x**3 + x - 6
	elif num == '6': return (4*x - 7)/(x - 2)
	elif num == '8': return np.sin(x) + np.cos(x) - 1.1 
		
def dfunc(x):
	if num == '6': return (-1) / ((x - 2)**2)
	elif num == '8': return np.cos(x) - np.sin(x)
	 	
if num == '2':
	print('Bolzano: ',optimize.bisect(func,0,1))
elif num == '4':
	print('Bolzano: ',optimize.bisect(func,1.55,1.75))
elif num == '6': 
	print('Newton (x0 = 1.6): ',optimize.newton(func, 3, dfunc, maxiter=500))
	#print('\nNewton (x0 = 1.5): ',optimize.newton(func, 1.5, dfunc, maxiter=500))
	#print('\nNewton (x0 = 3.0): ',optimize.newton(func, 3, dfunc, maxiter=500))
elif num == '8':
	print('Bolzano: ',optimize.bisect(func,0,1))
	print('Newton (x0 = 0.5): ',optimize.newton(func, 0.5, dfunc, maxiter=500))
