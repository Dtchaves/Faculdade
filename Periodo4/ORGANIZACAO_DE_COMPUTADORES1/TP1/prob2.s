.data
vetor: .word 200, 190, 340, 100 # exemplo

.text
##### START MODIFIQUE AQUI START #####
addi t0,x0,0 #Variável para armazenar a contagem dos salários acima do limiar
addi x4,x0,0 #Variável para armazenar a vaga do vetor que estamos analizando
addi a2,x0,200 #Variável para armazenar o limiar
la a0,vetor #Variável para armazenar a vaga inicial do vetor
addi a1,x0,4 #Variável para armazenar o tamanho do vetor
##### END MODIFIQUE AQUI END #####

.text
jal ra, main
# Ao final do reajuste (aplica_reajuste) você deve retornar o programa para a próxima instrução abaixo, que consiste na correção/verificação.

##### START INSTRUÇÃO DE CORREÇÃO/VERIFICAÇÃO #####
# utilizado para correção (considerando um limiar de 200 para o vetor de exemplo após a aplicação do reajuste.
addi a4, x0, 3 # configurando a quantidade de salários acima do limiar de 200.
beq a4, t0, FIM # Verifica a quantidade de salários acima do limiar.
##### END INSTRUÇÃO DE CORREÇÃO/VERIFICAÇÃO #####

 main:
##### START MODIFIQUE AQUI START #####
addi sp, sp, -8 # Alocamos duas vagas na pilha para guardar os valores de retorno das funções
sw x1, 4(sp) # Empilhamos o primeiro valor de retorno
jal ra, aplica_reajuste # Chamamos a função para aplicar o reajuste e analisar quantos salários ficaram acima do limiar
lw x1, 0(sp)  # Desempilhamos a vaga de retorno
addi sp, sp, 4 # Desaloca pilha
jalr x0, 0(x1) # Retornamos ao local onde a função foi chamada
##### END MODIFIQUE AQUI END #####

 aplica_reajuste:
##### START MODIFIQUE AQUI START #####
sw x1, 0(sp)
loop:
beq a1,x4,return # Para confirmar que a vaga atual é diferente do tamanho, muito útil caso o vetor não tenha elementos por exemplo
slli x15,x4,2 # Vaga atual vezes 4 pois é 32 bits 
add x16,x15,a0 # Vaga do vetor que queremos acessar é a vaga atual mais a vaga incial
lw x8,0(x16) # Carregamos o elemento da vaga do vetor que queremos acessar
srli x9,x8,1 # Pegamos 50% do salário
add x9,x8,x9 # Adicionamos o 50% ao salário 
# Conferimos dentro da função quais ficaram maiores que o limiar pois fazer o loop na main ia acatar em loads desnecessários que deixariam o código mais lento e menos otimizados
blt x9,a2,menor # Se o elemento for menor que o limiar pulamos a próxima instrução
addi t0,t0,1 # Se o novo salário for maior que o limiar incrementamos o seu contador
menor:
sw x9,0(x16)# Guardamos o novo valor na vaga do vetor
addi x4,x4,1 # Somamos 1 a vaga que queremos analisar 
bne a1,x4,loop # Caso a vaga seja diferente do tamanho voltamos no loop

lw x1, 0(sp) # Caso estejamos na última vaga desempilhamos a vaga de retorno
addi sp, sp, 4 # Desaloca pilha
return:jalr x0, 0(x1) # Retornamos a main

##### END MODIFIQUE AQUI END #####
FIM: addi x0, x0, 1
