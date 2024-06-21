import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

Time_Heap = pd.read_csv('Time_Heap.csv')
Time_Insert = pd.read_csv('Time_Insert.csv')
Time_Shell_H1 = pd.read_csv('Time_Shell_H1.csv')
Time_Shell_H2 = pd.read_csv('Time_Shell_H2.csv')


sns.set(style='ticks', font_scale=1.0, rc={'axes.facecolor': 'white', 'figure.facecolor': 'white'})

fig, ax = plt.subplots(figsize=(10, 6))
sns.lineplot(data=Time_Heap, x='Tamanho do Vetor', y='Tempo do Heap em ms ', label = "Heapsort", color='black', linewidth=2)
#sns.lineplot(data=Time_Insert, x='Tamanho do Vetor', y='Tempo do Insertsort em ms ', label = "Insertsort", color='purple', linewidth=2)
sns.lineplot(data=Time_Shell_H1, x='Tamanho do Vetor', y='Tempo do Shellsort_1 em ms ', label = "Shellsort 1", color='gray', linewidth=2)
sns.lineplot(data=Time_Shell_H2, x='Tamanho do Vetor', y='Tempo do Shellsort_2 em ms ', label = "Shellsort 2", color='blue', linewidth=2)


ax.set_xlabel('Tamanho do Vetor', fontsize=10, fontweight='bold')
ax.set_ylabel('Tempo em ms', fontsize=10, fontweight='bold')
ax.tick_params(axis='both', which='major', labelsize=10)

plt.legend(title='Análise de tempo para as ordenações:', title_fontsize=10, loc='upper left', fontsize=8)

plt.savefig('Tempo.png', dpi=300, bbox_inches='tight')

plt.show()
