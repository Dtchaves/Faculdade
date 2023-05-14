import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

df1 = pd.read_csv('posfixa.csv')
df2 = pd.read_csv('infixa.csv')


sns.set(style='ticks', font_scale=1.0, rc={'axes.facecolor': 'white', 'figure.facecolor': 'white'})

fig, ax = plt.subplots(figsize=(10, 6))
sns.lineplot(data=df1, x='Tamanho da Entrada', y='Tempo em ms', label = "Pós-fixas", color='blue', linewidth=2.5)
sns.lineplot(data=df2, x='Tamanho da Entrada', y='Tempo em ms', label = "Infixas", color='green', linewidth=2.5)


ax.set_xlabel('Tamanho da Entrada', fontsize=12, fontweight='bold')
ax.set_ylabel('Tempo em ms', fontsize=12, fontweight='bold')
ax.tick_params(axis='both', which='major', labelsize=10)

plt.legend(title='Análise de tempo para expressões:', title_fontsize=12, loc='upper left', fontsize=10)

plt.savefig('Posfixa.png', dpi=300, bbox_inches='tight')

plt.show()
