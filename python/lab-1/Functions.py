import numpy as np

def f(f,x):
	fx = eval(f)
	return fx
	

def func(x):
	if num == '2':
	 	return np.exp(x) - 3*x
 
def bolzano(func, x0, x1, par, error):
	if par == True:
		i = 1
		fx0 = f(func,x0)
		fx1 = f(func,x1)
		x2 = (x0+x1)/2
		fx2 = f(func,x2)
		print('| Iteración |    Raíz    |    Error    |')
		print('----------------------------------------')
		if i<10:
			if fx2 > 0: print('|     %i     |  %f  |   %f  |' % (i,x2,fx2))
			else: print('|     %i     |  %f  |  %f  |' % (i,x2,fx2))
		else:
			if fx2 > 0: print('|    %i     |  %f  |   %f  |' % (i,x2,fx2))
			else: print('|    %i    |  %f  |  %f  |' % (i,x2,fx2))
		for x in range(2, 7):
			if (fx0 > 0):
				if (fx2 > 0):
					x0 = x2
					fx0 = f(func,x0)
					x2 = (x0+x1)/2
					fx2 = f(func,x2) 
				else:
					x1 = x2
					fx1 = f(func,x1)
					x2 = (x0+x1)/2
					fx2 = f(func,x2)
			else:
				if (fx2 > 0):
					x1 = x2
					fx1 = f(func,x1)
					x2 = (x0+x1)/2
					fx2 = f(func,x2) 
				else:
					x0 = x2
					fx0 = f(func,x0)
					x2 = (x0+x1)/2
					fx2 = f(func,x2)

			if i<10:
				if fx2 > 0: print('|     %i     |  %f  |   %f  |' % (x,x2,fx2))
				else: print('|     %i     |  %f  |  %f  |' % (x,x2,fx2))
			else:
				if fx2 > 0: print('|    %i     |  %f  |   %f  |' % (x,x2,fx2))
				else: print('|    %i    |  %f  |  %f  |' % (x,x2,fx2))

	else:
		i = 1
		fx0 = f(func,x0)
		fx1 = f(func,x1)
		x2 = (x0+x1)/2
		fx2 = f(func,x2)
		print('| Iteración |    Raíz    |    Error    |')
		print('----------------------------------------')
		if i<10:
			if fx2 > 0: print('|     %i     |  %f  |   %f  |' % (i,x2,fx2))
			else: print('|     %i     |  %f  |  %f  |' % (i,x2,fx2))
		else:
			if fx2 > 0: print('|    %i     |  %f  |   %f  |' % (i,x2,fx2))
			else: print('|     %i    |  %f  |  %f  |' % (i,x2,fx2))
		i = i+1
		while (fx2 > error) | (fx2 < -error):
			if (fx0 > 0):
				if (fx2 > 0):
					x0 = x2
					fx0 = f(func,x0)
					x2 = (x0+x1)/2
					fx2 = f(func,x2) 
				else:
					x1 = x2
					fx1 = f(func,x1)
					x2 = (x0+x1)/2
					fx2 = f(func,x2)
			else:
				if (fx2 > 0):
					x1 = x2
					fx1 = f(func,x1)
					x2 = (x0+x1)/2
					fx2 = f(func,x2) 
				else:
					x0 = x2
					fx0 = f(func,x0)
					x2 = (x0+x1)/2
					fx2 = f(func,x2)			

			if i<10:
				if fx2 > 0: print('|     %i     |  %f  |   %f  |' % (i,x2,fx2))
				else: print('|     %i     |  %f  |  %f  |' % (i,x2,fx2))
			else:
				if fx2 > 0: print('|    %i     |  %f  |   %f  |' % (i,x2,fx2))
				else: print('|     %i    |  %f  |  %f  |' % (i,x2,fx2))
			i = i+1
			
def secante(func,x0,x1,error):
	i = 1
	fx0 = f(func,x0)
	fx1 = f(func,x1)
	x2 = x0 - ((x1 - x0)/(fx1 - fx0))*fx0
	fx2 = f(func,x2)
	print('| Iteración |    Raíz    |    Error    |')
	print('----------------------------------------')
	if x2>0:
		if i<10:
			if fx2 > 0: print('|     %i     |  %f  |   %f  |' % (i,x2,fx2))
			else: print('|     %i     |  %f  |  %f  |' % (i,x2,fx2))
		else:
			if fx2 > 0: print('|    %i     |  %f  |   %f  |' % (i,x2,fx2))
			else: print('|     %i    |  %f  |  %f  |' % (i,x2,fx2))
	else:
		if i<10:
			if fx2 > 0: print('|     %i     | %f  |   %f  |' % (i,x2,fx2))
			else: print('|     %i     | %f  |  %f  |' % (i,x2,fx2))
		else:
			if fx2 > 0: print('|    %i     | %f  |   %f  |' % (i,x2,fx2))
			else: print('|     %i    | %f  |  %f  |' % (i,x2,fx2))
	i = i+1
	while (fx2 > error) | (fx2 < -error):
		x0 = x1
		x1 = x2
		fx0 = f(func,x0)
		fx1 = f(func,x1)
		x2 = x0 - ((x1 - x0)/(fx1 - fx0))*fx0
		fx2 = f(func,x2)
		if x2>0:
			if i<10:
				if fx2 > 0: print('|     %i     |  %f  |   %f  |' % (i,x2,fx2))
				else: print('|     %i     |  %f  |  %f  |' % (i,x2,fx2))
			else:
				if fx2 > 0: print('|    %i     |  %f  |   %f  |' % (i,x2,fx2))
				else: print('|     %i    |  %f  |  %f  |' % (i,x2,fx2))
		else:
			if i<10:
				if fx2 > 0: print('|     %i     | %f  |   %f  |' % (i,x2,fx2))
				else: print('|     %i     | %f  |  %f  |' % (i,x2,fx2))
			else:
				if fx2 > 0: print('|    %i     | %f  |   %f  |' % (i,x2,fx2))
				else: print('|     %i    | %f  |  %f  |' % (i,x2,fx2))
		i = i+1
		
def nwtn(func,dfunc,x0,error):
	i = 1
	fx0 = f(func,x0)
	dfx0 = f(dfunc,x0)
	x1 = x0 - (fx0/dfx0)
	fx1 = f(func,x1)
	dfx1 = f(dfunc,x1)
	print('| Iteración |    Raíz    |    Error    |')
	print('----------------------------------------')
	if i<10:
		if fx1 > 0: print('|     %i     |  %f  |   %f  |' % (i,x1,fx1))
		else: print('|     %i     |  %f  |  %f  |' % (i,x1,fx1))
	else:
		if fx1 > 0: print('|    %i     |  %f  |   %f  |' % (i,x1,fx1))
		else: print('|     %i    |  %f  |  %f  |' % (i,x1,fx1))
	i = i+1
	while (fx1 > error) | (fx1 < -error):
		x0 = x1
		fx0 = f(func,x0)
		dfx0 = f(dfunc,x0)
		x1 = x0 - (fx0/dfx0)
		fx1 = f(func,x1)
		dfx1 = f(dfunc,x1)
		if i<10:
			if fx1 > 0: print('|     %i     |  %f  |   %f  |' % (i,x1,fx1))
			else: print('|     %i     |  %f  |  %f  |' % (i,x1,fx1))
		else:
			if fx1 > 0: print('|    %i     |  %f  |   %f  |' % (i,x1,fx1))
			else: print('|     %i    |  %f  |  %f  |' % (i,x1,fx1))
		i = i+1
		
def regula(func, x0, x1, error):
	i = 1
	fx0 = f(func,x0)
	fx1 = f(func,x1)
	x2 = x0 - ((x1 - x0)/(fx1 - fx0))*fx0
	fx2 = f(func,x2)
	print('| Iteración |    Raíz    |    Error    |')
	print('----------------------------------------')
	if i<10:
		if fx2 > 0: print('|     %i     |  %f  |   %f  |' % (i,x2,fx2))
		else: print('|      %i    |  %f  |  %f  |' % (i,x2,fx2))
	else:
		if fx2 > 0: print('|     %i    |  %f  |   %f  |' % (i,x2,fx2))
		else: print('|      %i   |  %f  |  %f  |' % (i,x2,fx2))
	i = i+1
	while (fx2 > error) | (fx2 < -error):
		if (fx0 > 0):
			if (fx2 > 0):
				x0 = x2
				fx0 = f(func,x0)
				x2 = x0 - ((x1 - x0)/(fx1 - fx0))*fx0
				fx2 = f(func,x2) 
			else:
				x1 = x2
				fx1 = f(func,x1)
				x2 = x0 - ((x1 - x0)/(fx1 - fx0))*fx0
				fx2 = f(func,x2)
		else:
			if (fx2 > 0):
				x1 = x2
				fx1 = f(func,x1)
				x2 = x0 - ((x1 - x0)/(fx1 - fx0))*fx0
				fx2 = f(func,x2) 
			else:
				x0 = x2
				fx0 = f(func,x0)
				x2 = x0 - ((x1 - x0)/(fx1 - fx0))*fx0
				fx2 = f(func,x2)			
			if i<10:
				if fx2 > 0: print('|     %i     |  %f  |   %f  |' % (i,x2,fx2))
				else: print('|      %i    |  %f  |  %f  |' % (i,x2,fx2))
			else:
				if fx2 > 0: print('|    %i     |  %f  |   %f  |' % (i,x2,fx2))
				else: print('|     %i    |  %f  |  %f  |' % (i,x2,fx2))
		i = i+1
		
def lagrange(X,Y):
	Pol = []
	Coef = []
	Fac = []	
	for i in range(0,len(X)):
		num = []
		den = 1
		for j in range(0,len(X)):			
			if j != i:				
				den = den * (X[i]-X[j])
				print(den)
		Coef.append(Y[i] / den)
		if X[i] >= 0: num = '(x - {})'.format(X[i])
		else: num = '(x + {})'.format(abs(X[i]))
		Fac.append(num)
	print('Factores:')
	for i in range(0,len(X)): print(Fac[i])
	print('Coeficientes ( Yk*den(Lk) ):')
	for i in range(0,len(X)): print("%.4f" % Coef[i])
	x = float(input('Punto a interpolar: '))
	Interp = 0
	for i in range(0,len(X)):
		temp = 1
		for j in range(0,len(X)):
			if j != i:
				temp = temp * eval(Fac[j])			
		temp = temp * Coef[i]		
		Interp = Interp + temp
	print('Resultado: y = ',"%.4f" % Interp)
