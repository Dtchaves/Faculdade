import numpy as np

# Parâmetros da distribuição normal
mu = 1.65
sigma = 0.10

# Gerar amostra de 1000 valores independentes
amostra = np.random.normal(mu, sigma, 100000)

# Calcular desvios absolutos em relação à média aritmética
desvios_absolutos = np.abs(amostra - np.mean(amostra))

# Calcular a média dos desvios absolutos
media_desvios_absolutos = np.mean(desvios_absolutos)

# Exibir resultados
print("Média dos desvios:", media_desvios_absolutos)
