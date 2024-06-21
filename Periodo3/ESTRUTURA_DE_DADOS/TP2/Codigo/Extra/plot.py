import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

Time_buck = pd.read_csv('gr_bucket.csv')
Time_Insert = pd.read_csv('gr_insert.csv')
Time_merge = pd.read_csv('gr_merge.csv')
Time_jarvs = pd.read_csv('jarvs.csv')


sns.set(style='ticks', font_scale=1.0, rc={'axes.facecolor': 'white', 'figure.facecolor': 'white'})

fig, ax = plt.subplots(figsize=(10, 6))
sns.lineplot(data=Time_buck, x='Tamanho do Vetor', y='Tempo', label = "Grahamscan com BucketSort", color='black', linewidth=2)
sns.lineplot(data=Time_Insert, x='Tamanho do Vetor', y='Tempo', label = "Grahamscan com InsertionSort", color='purple', linewidth=2)
sns.lineplot(data=Time_merge, x='Tamanho do Vetor', y='Tempo', label = "Grahamscan com MergeSort", color='gray', linewidth=2)
sns.lineplot(data=Time_jarvs, x='Tamanho do Vetor', y='Tempo', label = "Jarvismarch" , color='blue', linewidth=2)


ax.set_xlabel('Tamanho da Entrada', fontsize=10, fontweight='bold')
ax.set_ylabel('Tempo em s', fontsize=10, fontweight='bold')
ax.tick_params(axis='both', which='major', labelsize=10)

plt.legend(title='Análise de tempo: ', title_fontsize=10, loc='upper left', fontsize=8)

plt.savefig('Tempo.png', dpi=300, bbox_inches='tight')

plt.show()
