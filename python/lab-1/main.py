from Functions import *

while True:

	option = input('(L)ab 1, (T)aller 2: ')

	if option == 'L':

		num = input('Numeral: ')
	
		if num == '1':
			func = 'np.exp(x) - 3*x'
			x0 = input('Ingrese límite inferior: ')
			x1 = input('Ingrese límite superior: ')
			par = input('¿Realizar 6 iteraciones? (S/N): ')
			if par == 'S': par = True
			else: par = False
			bolzano(func, float(x0), float(x1), par, 0.0001)

		elif num == '3':
			func = 'x**3 + x - 6'
			x0 = input('Ingrese límite inferior: ')
			x1 = input('Ingrese límite superior: ')
			mode = input('Algoritmo (1=Bolzano, 2=Pos. Falsa): ')
			if mode == '1': bolzano(func, float(x0), float(x1), False, 0.001)
			elif mode == '2': regula(func, float(x0), float(x1), 0.001)
	
		elif num == '5':
			func = '(4*x - 7) / (x - 2)'
			dfunc = '(-1) / ((x - 2)**2)'
			x0 = input('Ingrese punto de inicio: ')
			nwtn(func,dfunc,float(x0),0.0001)
	
		elif num == '7':
			func = 'np.sin(x) + np.cos(x) - 1.1'
			dfunc = 'np.cos(x) - np.sin(x)'
			x0 = input('Ingrese límite inferior: ')
			x1 = input('Ingrese límite superior: ')
			mode = input('Algoritmo (1=Bolzano, 2=Pos. Falsa, 3=Newton, 4=Secante): ')
			if mode == '1': bolzano(func, float(x0), float(x1), False, 0.0001)
			elif mode == '2': regula(func, float(x0), float(x1), 0.0001)
			elif mode == '3': nwtn(func, dfunc, (float(x0)+float(x1))/2, 0.0001)
			elif mode == '4': secante(func, float(x0), float(x1), 0.0001)

	elif option == 'T':

		check = False
		print('Interpolación por Método de Lagrange')
		while (check == False):
			xi = input('Datos X (separados por espacios): ')
			yi = input('Datos Y (separados por espacios): ')	
			X = [float(i) for i in xi.split()]
			Y = [float(j) for j in yi.split()]
			if (len(X) == len(Y)): check = True
			else: print("\t#X ≠ #Y, intente de nuevo.")
		lagrange(X,Y)
	
