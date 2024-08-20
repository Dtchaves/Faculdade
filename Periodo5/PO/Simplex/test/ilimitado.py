import numpy as np

# Função para imprimir arrays sem notação científica
def print_decimal(array):
    print(np.array2string(array, formatter={'float_kind': lambda x: "%.8f" % x}))

file_path = '/home/diogo/Documents/Simplex/data/example12.txt'

with open(file_path, 'r') as file:
    n = 0
    m = 0
    matriz_a = np.array([])
    vetor_b = np.array([])
    vetor_c = np.array([])

    idx = 0
    for line in file:
        line = line.strip()  # Removes leading/trailing whitespace including newlines
        if idx == 0:
            n, m = line.split()
            n = int(n)
            m = int(m)
        else:
            line = [float(x) for x in line.split() if x]  # Filter out empty strings
            if idx == 1:
                vetor_c = np.array(line)
            else:
                matriz_a = np.append(matriz_a, line[:m])
                vetor_b = np.append(vetor_b, line[m])
        idx += 1

    matriz_a = matriz_a.reshape((n, m))
    vetor_b = vetor_b.reshape((n, 1))

    print("Matriz A:")
    print_decimal(matriz_a)
    print("Vetor b:")
    print_decimal(vetor_b)
    print("Vetor c:")
    print_decimal(vetor_c)

vetor_y = np.array([])

with open('ilimitados.txt', 'r') as file:
    for line in file:
        line = line.strip()  # Removes leading/trailing whitespace including newlines
        line = [float(x) for x in line.split() if x]  # Filter out empty strings
        vetor_y = np.append(vetor_y, line)

print("Vetor y:")
print_decimal(vetor_y)

print('Eu')

print("Produto de Matriz A e Vetor y:")
print_decimal(np.dot(matriz_a, vetor_y.T))
print("Produto de Vetor c e Vetor y:")
print_decimal(np.dot(vetor_c, vetor_y.T))
