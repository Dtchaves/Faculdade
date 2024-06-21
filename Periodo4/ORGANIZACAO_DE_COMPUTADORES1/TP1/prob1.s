.data
vetor: .word 2 7 3 123 12 126 34 30
.text
##### START MODIFIQUE AQUI START #####
addi x10,x0,0 # Variável para armazenar a contagem dos números pares
addi x11,x0,0 # Variável para armazenar a contagem dos números ímpares
addi x4,x0,0 # Variável para armazenar a vaga do vetor que estamos analizando
addi x13,x0,2 # Variável para armazenar o número 2 para a função rem
la t2,vetor # Variável para armazenar a vaga inicial do vetor
addi t3,x0,8 # Variável para armazenar o tamanho do vetor

##### END MODIFIQUE AQUI END #####
.text
jal x1, contador
addi x14, x0, 3 # utilizado para correção
beq x14, x10, FIM # Verifica # de pares
beq x14, x11, FIM # Verifica # de ímpares
##### START MODIFIQUE AQUI START #####

contador: 
loop:
beq t3,x4,return # Para confirmar que a vaga atual é diferente do tamanho, muito útil caso o vetor não tenha elementos por exemplo
slli x12,x4,2 # Vaga atual vezes 4 pois é 32 bits 
add x6,x12,t2 # Vaga do vetor que queremos acessar é a vaga atual mais a vaga incial
lw x8,0(x6) # Carregamos o elemento da vaga do vetor que queremos acessar
rem x9,x8,x13 # Pegamos o resto da divisão do elemento que carregamos do vetor com 2
beq x9,x0,par # Se o resto for 0 o elemento é par
addi x11,x11,1 # Se não o elemento é ímpar e incrementamos x6
beq x0,x0,exit # Usamos um 0 == 0 para pularmos a instrução do caso par caso o número seja ímpar 
par:addi x10,x10,1 # O elemento é par e incrementamos x5
exit:
addi x4,x4,1 # Somamos 1 a vaga que queremos analisar 
bne t3,x4,loop # Caso a vaga seja diferente do tamanho voltamos no loop
return:jalr x0, 0(x1) # Retornamos a onde a função foi chamada

##### END MODIFIQUE AQUI END #####
FIM: addi x0, x0, 1
