import sys
from todo import *

"""
ATENÇÃO: VOCÊ NÃO DEVE ALTERAR ESSA PARTE DO CÓDIGO!
"""

case = int(sys.stdin.readline())
a, b = list(map(float, sys.stdin.readline().split()))

if case == 0:
    print(int(somar(a, b)))
elif case == 1:
    print(int(somar(a, b)))
elif case == 2:
    print(int(somar(a, b)))
elif case == 3:
    print(int(somar(a, b)))
elif case == 4:
    print(int(subtrair(a, b)))
elif case == 5:
    print(int(subtrair(a, b)))
elif case == 6:
    print(int(subtrair(a, b)))
elif case == 7:
    print(int(subtrair(a, b)))
else:
    print("Unknown case: ", case)