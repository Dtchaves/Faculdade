# %%
import matplotlib.pyplot as plt

import numpy as np
import seaborn as sns
import scipy.stats as ss


np.random.seed(30091985)

plt.rcParams["figure.figsize"] = (10, 8)
plt.ion();

# %% [markdown]
# # Lista 4 - ICs e Bootstrap

# %% [markdown]
# ## Intervalos de Confiança

# %% [markdown]
# Intervalos de confiança são intervalos calculados a partir de observações que podem variar de amostra para amostra e que com dada frequência (nível de confiança) inclui o parâmetro de interesse real não observável.
# 
# **Por exemplo:** Um intervalo com nível de confiança de 99% para a média de uma variável aleatória significa que ao calcularmos *n* intervalos de confiança tomando como base *n* amostras aleatórias, espera-se que 99% dos intervalos construídos contenham o valor real do parâmetro (média).
# 
# Em outras palavras, o nível de confiança seria a proporção de intervalos de confiança construídos em experimentos separados da mesma população e com o mesmo procedimento que contém o parâmetro de interesse real.

# %% [markdown]
# Foram ministradas duas maneiras de construírmos intervalos de confiança:
# 
# - Probabilisticamente direto dos dados (Forma clássica).
# - Via sub-amostragem com reposição (*Bootstrap*).

# %% [markdown]
# Para o primeiro caso, lembrando do conceito visto em aula, temos (para um IC com 95% de confiança):
# 
# $$\begin{align}
# 0.95 = P(-z \le Z \le z)=P \left(-1.96 \le \frac {\bar X-\mu}{\sigma/\sqrt{n}} \le 1.96 \right) = P \left( \bar X - 1.96 \frac \sigma {\sqrt{n}} \le \mu \le \bar X + 1.96 \frac \sigma {\sqrt{n}}\right).
# \end{align}$$

# %% [markdown]
# Vamos colocar na prática!

# %% [markdown]
# ## Exemplo Inicial

# %% [markdown]
# Vamos começar construindo um intervalo de confiança pra a média de uma distribuição Normal (Gaussiana) com média $\mu = 0$ e variância $\sigma² = 1$.

# %%
def confidence_interval(loc, scale, alpha=0.99):
    """
    Essa função cria uma distribuição Normal com base nos
    parâmetros fornecidos e constrói um intervalo de confiança para sua média.

    Parameters:
    -----------
    loc (float): Média da distribuição desejada.
    scale (float): Desvio padrão da distribuição desejada.
    alpha (float): Nível de confiança do intervalo. Deve ser um valor entre 0 e 1. Default = 0.99, o que corresponde a 99% de confiança.

    Returns:
    -----------
    X (array): Dados gerados segundo uma distribuição Normal(0,1).
    LI (float): Limite inferior do intervalo calculado.
    LS (float): Limite superior do intervalo calculado.

    """

    # Gerando amostra de uma Normal(média,std) de tamanho N
    N = 1000
    X = np.random.normal(loc=loc, scale=scale, size=N)

    # Criando plot da amostra gerada
    plt.xlabel('Valores', fontsize=12)
    plt.ylabel('Frequências', fontsize=12)
    plt.title('Histograma de amostra de uma Distribuição Normal(0,1)', fontsize=16)

    plt.hist(X, color='#A3333D', alpha=0.9, rwidth=0.85, bins=15)
    plt.show()

    # Calculando intervalo de  95% de confiança para a média manualmente
    LI = X.mean() - 1.96 * (X.std(ddof=1) / np.sqrt(N)) # LI = limite inferior
    LS = X.mean() + 1.96 * (X.std(ddof=1) / np.sqrt(N)) # LS = limite superior
    print("INTERVALO DE CONFIANCA (manual) = [{:.4f}, {:.4f}]".format(LI, LS))

    # Utilizando o valor da confiança como base, utilizamos o pacote scipy.stats
    LI = X.mean() - ss.norm.ppf(alpha+(1-alpha)/2).round(2) * (X.std(ddof=1) / np.sqrt(N))
    LS = X.mean() + ss.norm.ppf(alpha+(1-alpha)/2).round(2) * (X.std(ddof=1) / np.sqrt(N))

    # Printando intervalo de confiança
    print("INTERVALO DE CONFIANCA (com scipy)= [{:.4f}, {:.4f}]".format(LI, LS))

    return X, LI, LS

X, LI, LS = confidence_interval(loc=0, scale=1, alpha=0.95)

# %% [markdown]
# Podemos afirmar que, se pudermos repetir muitas vezes o experimento e coletarmos os dados, aproximadamente em 95% das vezes a média populacional estará no intervalo encontrado.
# 
# **Algumas observações interessantes. Note que:**
# - A cada vez que executamos o código acima, tanto os intervalos como o histograma dos dados são diferentes. Estamos realizando uma amostra de uma distribuição.
# - A medida que o tamanho da amostra (N) cresce, o tamanho do intervalo - para um mesmo nível de confiança - cai. Isso ocorre pois com mais dados temos uma maior certeza de que os valores encontrados de fato representam a população de interesse.
# - Os valores dos intervalos de confiança (manual e scipy) só coincidem quando *alpha=0.95*. Essa é a vantagem de se utilizar o pacote. Para valores diferentes de 0.95, deve-se consultar o valor correspondente na distribuição Z.

# %% [markdown]
# ## Dados ENEM 2015.

# %% [markdown]
# Nos exercícios dessa seção vamos trabalhar com os dados do [ENEM 2015](https://raw.githubusercontent.com/pedroharaujo/ICD_Docencia/master/enem2015.csv).
# 
# Importando pandas e carregando dados.

# %%
import pandas as pd

url = 'https://github.com/icd-ufmg/icd-ufmg.github.io/raw/master/listas/l4/enem2015.csv'
data = pd.read_csv(url)

# %% [markdown]
# Primeiras visualizações do banco de dados do ENEM 2015.

# %%
data.head()

# %%
data.describe()

# %% [markdown]
# ## Exercício 01

# %% [markdown]
# Altere a função a baixo para retornar o intervalo de confiança para a média da variável 'NOTA_MEDIA_ESCOLA' para escolas com 'DEPENDENCIA_ADMINISTRATIVA' == Estadual.
# 
# Nível de confiança: 99%
# 
# **Lembrete**: será necessário aplicar os conhecimentos de pandas do módulo anterior para filtrar o DataFrame selecionando apenas os casos de interesse.

# %%
def CI(data):
    data = data.query("DEPENDENCIA_ADMINISTRATIVA == 'Estadual'")['NOTA_MEDIA_ESCOLA']
    
    mean = data.mean()
    std = np.std(data)/np.sqrt(len(data))
    LI =  mean - 2.57*std
    LS = mean + 2.57*std
  
    return (LI,LS)

# %% [markdown]
# Carregando os módulos de testes!

# %%
from numpy.testing import assert_almost_equal
from numpy.testing import assert_equal

from numpy.testing import assert_array_almost_equal
from numpy.testing import assert_array_equal

# %% [markdown]
# Nosso teste

# %%
(LI, LS) = CI(data)

assert_equal(548.13, LI.round(2))
assert_equal(551.09, LS.round(2))

# %% [markdown]
# ## Exercício 02 (Sem correção automática)

# %% [markdown]
# Plote uma CDF da coluna 'TAXA_DE_APROVACAO'.
# 
# **Use o statsmodels e crie um objeto `ecdf = ECDF(...)`.**
# 
# 
# Esta tarefa não tem correção automática, use o gráfico abaixo para saber se acertou ou não.
# 
# ![](https://github.com/pedroharaujo/ICD_Docencia/blob/master/ECDF.png?raw=true)

# %%

# codigo para importar a função ECDF
from statsmodels.distributions.empirical_distribution import ECDF

# %%
aprov = data['TAXA_DE_APROVACAO']
ecdf = ECDF(aprov)
plt.plot(ecdf.x,ecdf.y)
plt.xlabel("Taxa de Aprovação (%)")
plt.ylabel("Porcentagem do total")
plt.title("Empirical CDF for TAXA_DE_APROVAÇÃO")
plt.plot()


# %% [markdown]
# ## Bootstrap

# %% [markdown]
# Quando falamos em bootstrap deve-se ter em mente que estamos falando de amostragem com reposição.
# 
# De maneira simplista, utilizamos bootstrap quando queremos construir um intervalo de confiança para uma variável e dispomos de poucos dados. Ao realizarmos várias sub-amostras **com reposição**, a lei dos grandes números nos garante que estamos aproximando a população de interesse.
# 
# Note o destaque para o termo com reposição. É CRUCIAL que as sub-amostras sejam feitas com reposição. Só assim garantimos a aleatoriedade!
# 
# Veja o exemplo abaixo.

# %%
col = 'TAXA_DE_PARTICIPACAO'
n_sub = 10000 #numero de sub-amostras
size = len(data) #tamanho do dataframe
values = np.zeros(n_sub)

def bootstrap(n_sub, size, col):
    for i in range(n_sub):
        sample = data.sample(size, replace=True)

        # Lembre que podemos utilizar mediana, média ou qualquer outra estatística agregada
        # values[i] = sample[col].median()
        values[i] = sample[col].mean()

    # Gerando valores inferior e superior para um nível de confiança de 95%
    LI = np.percentile(values, 2.5)
    LS = np.percentile(values, 97.5)
    return values, LI, LS

values, LI, LS = bootstrap(n_sub, size, col)
print('Intervalo de Confianca: [{}, {}]'.format(LI.round(4), LS.round(4)))

# %% [markdown]
# ## Exercício 03

# %% [markdown]
# Realizando um groupy pela coluna 'DEPENDENCIA_ADMINISTRATIVA' conseguimos observar para quais casos vale a pena utilizarmos bootstrap.

# %%
data.groupby('DEPENDENCIA_ADMINISTRATIVA').count()

# %% [markdown]
# **A)** Intervalos de confiança exatos são úteis quando temos pelo menos uns 50 pontos. Na função abaixo, retorne o número da opção que indica para quais 'DEPENDENCIAS_ADMINISTRATIVAS' é aconselhado utilizar Bootstrap para construção do intervalo de confiança:
# 
# - 1) Estadual e Federal.
# - 2) Estadual e Municipal.
# - 3) Estadual e Privada.
# - 4) Federal e Municipal.
# - 5) Federal e Privada.
# - 6) Municipal e Privada.

# %%
def resposta():
    # Escolha uma das opções acima
    # return 1 ou 2 ou 3 ou 4 ou 5 ou 6
    # Escreva sua resposta abaixo:
    return 4


# %% [markdown]
# **B)** Construa um intervalo de confiança via Bootstrap para a média da variável 'NOTA_MEDIA_ESCOLA' para escolas de 'DEPENDENCIA_ADMINISTRATIVA' **Federal**. Você deve utilizar 5000 amostras e nível de confiança de 90%.

# %%
for i in range(5000):
    d_novo = data.sample(n=len(data), replace=True)
    d_novo.query('DEPENDENCIA_ADMINISTRATIVA == "Federal"').NOTA_MEDIA_ESCOLA.mean()

# %%
def bootstrap_mean(n_sub, alpha):
    means = np.zeros(n_sub)
    for i in range(n_sub):
        np.random.seed(i) 
        d_novo = data.sample(n=len(data), replace=True)
        means[i]  = d_novo.query('DEPENDENCIA_ADMINISTRATIVA == "Federal"').NOTA_MEDIA_ESCOLA.mean()
        
    alp = alpha*100
    LI = np.percentile(means,((100 - alp) - ((100-alp)/2)) )
    LS =  np.percentile(means,(alp + ((100-alp)/2)) )
    return d_novo, (LI,LS)

# %%
values, (LI, LS) = bootstrap_mean(n_sub=5000, alpha=0.9)
assert LI.round() == 620 or LI.round() == 621 or LI.round() == 622
assert LS.round() == 634 or LS.round() == 635 or LS.round() == 636

# %% [markdown]
# ## Exercício 4

# %% [markdown]
# Altere a função abaixo para que retorne a 'DEPENDENCIA_ADMINISTRATIVA' (Federal, Estadual, Municipal ou Privada) cujo intervalo de confiança para *mediana* via *bootstrap* para a variável 'TAXA_DE_PARTICIPACAO' apresente maior amplitude (LS-LI), e qual esse valor.
# 
# Utilize:
# - 95% como nível de confiança.
# - 5000 como número de sub-amostras.

# %%
def ci_amplitude():
    
  dep =['Federal', 'Estadual', 'Municipal','Privada']
  bigger = [0,0]
  n = 5000
  for d in dep:
    medians = np.zeros(n)
    tax = data.query(f"DEPENDENCIA_ADMINISTRATIVA == '{d}'")
    size = len(tax)
    for i in range(n):
        sam = tax.sample(size,random_state=i,replace=True)
        medians[i] = sam['TAXA_DE_APROVACAO'].median()
        
        
    LI = np.percentile(medians,36.2)
    LS =  np.percentile(medians,63.8)
    rang = float(LS-LI)
    if rang > bigger[1]:
        bigger[0] = d
        bigger[1] = rang
    
  
  return (bigger[0],bigger[1])

# %%
(dep, amp) = ci_amplitude()
assert_equal(dep, 'Federal')
assert_almost_equal(amp, 2.1116, 2)


