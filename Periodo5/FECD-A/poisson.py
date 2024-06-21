import numpy as np

print('QUESTÃO 7')
# Parâmetro da distribuição de Poisson
lambda_param = 3

# Número de amostras e tamanho de cada amostra
num_amostras = 10
tamanho_amostra = 100

# Gerar as amostras e calcular as médias
medias = []
for i in range(num_amostras):
    amostra = np.random.poisson(lambda_param, tamanho_amostra)
    media_amostra = np.mean(amostra)
    medias.append(media_amostra)
    print(f"Média da amostra {i+1}: {media_amostra}")

# Calculando a média das médias das amostras
media_das_medias = np.mean(medias)
print(f"\nEsperança estimada pelas amostras (Média das médias): {media_das_medias}")

# A expectativa teórica da distribuição de Poisson é igual ao parâmetro lambda
print(f"Esperança teórica (E[X] = λ): {lambda_param}")

print('QUESTAO 8')

import numpy as np

# Parâmetros da distribuição normal
mu = 1.65
sigma = 0.10

# Gerar a amostra
amostra = np.random.normal(mu, sigma, 1000)

# Calcular os desvios absolutos entre cada valor e a média da amostra
desvios_absolutos = np.abs(amostra - np.mean(amostra))

# Calcular a média dos desvios absolutos
media_desvios_absolutos = np.mean(desvios_absolutos)

# Comparar com o valor de sigma
print(f"Média dos desvios absolutos: {media_desvios_absolutos}")
print(f"Valor de sigma: {sigma}")
