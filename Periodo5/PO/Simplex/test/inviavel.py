import numpy as np

file = open('/home/diogo/Documents/Simplex/data/example08.txt', 'r')
# print(file.read())
n = 0
m = 0
matriz_a = np.array([])
vetor_b = np.array([])
vetor_c = np.array([])

idx = 0
for line in file:
    line = line.replace('\n', '')
    if idx == 0:
        n, m = line.split(' ')
        n = int(n)
        m = int(m)
    else:
        line = line.split(' ')
        for i in range(len(line)):
            line[i] = float(line[i])
        if idx == 1:
            vetor_c = np.array(line)
        else:
            matriz_a = np.append(matriz_a, line[:m])
            vetor_b = np.append(vetor_b, line[m])
    idx += 1

matriz_a = matriz_a.reshape((n, m))
vetor_b = vetor_b.reshape((n, 1))

print(matriz_a)

vetor_y = np.array([])
file = open('inviavel.txt', 'r')
for line in file:
    line = line.replace('\n', '')
    line = line.split(' ')
    line = [float(x) for x in line]
    vetor_y = np.append(vetor_y, line)

print(vetor_y)

print('eu')
print(np.dot(vetor_y.T, matriz_a))
print(np.dot(vetor_y.T, vetor_b))

# vetor_y = np.array([])
# marcim = np.array([])
# idx = 0
# file = open('ilimitados.txt', 'r')
# for line in file:
#     line = line.replace('\n', '')
#     line = line.split(' ')
#     line = [float(x) for x in line]
#     if idx == 0:
#         vetor_y = np.append(vetor_y, line)
#     else:
#         marcim = np.append(marcim, line)
#     idx += 1

# print(vetor_y)
# print(marcim)

# print('eu')
# print(np.dot(matriz_a, vetor_y.T))
# print(np.dot(vetor_c, vetor_y.T))
# print('marcio')
# print(np.dot(matriz_a, marcim.T))
# print(np.dot(vetor_c, marcim.T))