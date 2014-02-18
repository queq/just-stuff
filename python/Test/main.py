import numpy as np
from pylab import *
from sympy import *

x = np.array([8, 7, 6, 5, 4, 3, 2, 1])
y = np.array([2, 5, 1, 1, 1, 5, 4, 6])

#p1, = plot(x,y,'ko')

#show()

x = Symbol('x')

eq1 = (x - 7) * (x - 6) * (x - 5) * (x - 4) * (x - 3) * (x - 2) * (x - 1)
coeff1 = 1 / (2 / 5040)
coeff2 = 1 / (5 / 240)
eq2 = (x - 8) * (x - 6) * (x - 5) * (x - 4) * (x - 3) * (x - 2) * (x - 1)
eq3 = (x - 7) * (x - 8) * (x - 5) * (x - 4) * (x - 3) * (x - 2) * (x - 1)
coeff3 = (6 - 7) * (6 - 8) * (6 - 5) * (6 - 4) * (6 - 3) * (6 - 2) * (6 - 1)
eq4 = (x - 7) * (x - 6) * (x - 8) * (x - 4) * (x - 3) * (x - 2) * (x - 1)
coeff4 = (5 - 7) * (5 - 6) * (5 - 8) * (5 - 4) * (5 - 3) * (5 - 2) * (5 - 1)
eq5 = (x - 7) * (x - 6) * (x - 5) * (x - 8) * (x - 3) * (x - 2) * (x - 1)
coeff5 = (4 - 7) * (4 - 6) * (4 - 5) * (4 - 8) * (4 - 3) * (4 - 2) * (4 - 1)
eq6 = (x - 7) * (x - 6) * (x - 5) * (x - 4) * (x - 8) * (x - 2) * (x - 1)
coeff6 = (3 - 7) * (3 - 6) * (3 - 5) * (3 - 4) * (3 - 8) * (3 - 2) * (3 - 1) / 5
eq7 = (4*(x-7)*(x-6)*(x-5)*(x-4)*(x-3)*(x-8)*(x-1))/((2-7)*(2-6)*(2-5)*(2-4)*(2-3)*(2-8)*(2-1))
eq8 = (6*(x-7)*(x-6)*(x-5)*(x-4)*(x-3)*(x-2)*(x-8))/((1-7)*(1-6)*(1-5)*(1-4)*(1-3)*(1-2)*(1-8))
eq = eq1 + eq2 + eq3 + eq4 + eq5 + eq6 + eq7 + eq8
expand(eq)
