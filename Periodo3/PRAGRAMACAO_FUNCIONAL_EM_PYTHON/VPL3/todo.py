from functools import reduce

def firstChars(L):
    """ Maps strings in L to a list with the first character of each string.
    For instance:
    firstChars(['python', 'is', 'pythy']) == ['p', 'i', 'p']
    """
    return None

def sum(L):
    """ Sums the elements in L """
    return int(reduce(lambda acc, it: acc + it,L,0))

def avg(L):
    """ Returns the average of the elements in L """
    return sum(L)/len(L)

def maxString(L):
    """ Retorna a maior string dentre as strings em L.
    Por exemplo: maxString(['python', 'is', 'pythy']) == 'python'
    Se houver empate, retorna a primeira string encontrada.
    """
    return str(reduce(lambda acc,it: acc if len(it)<len(acc) else it,L,""))

def add2Dict(D, N, S):
    """ Insere a string S na lista associada ao inteiro N dentro
    do dicionario D.
    Por exemplo, se D = {1: ['b'], 2: ['xd'], 3: ['abc']}, entao,
    add2Dict(D, 2, 'ww') produz o novo dicionario:
    {1: ['b'], 2: ['xd', 'ww'], 3: ['abc']}
    Voce pode usar essa funcao para completar buildLenFreq
    """
    D[N] = D[N] + [S] if N in D else [S]
    return D

def buildLenFreq(L):
    """ Esta funcao constroi um dicionario que associa inteiros a listas com
    palavras daquele tamanho. Por exemplo:
    ins(['abc', 'xd', 'b', 'xxx']) = {1: ['b'], 2: ['xd'], 3: ['abc', 'xxx']}
    """    
    return reduce (lambda dic, it: add2Dict(dic, len(it), it) ,L,{})

def incValue(D, N):
    """Esta funcao incrementa o valor associado a chave N dentro do dicionario
    D. Por exemplo, se D = {1: 2, 2: 4, 3: 11}, entao
    Voce pode usar essa funcao para completar countFirsts
    """
    D[N] = D[N] + 1 if N in D else 1
    return D

def countFirsts(L):
    """ Conta o numero de ocorrencias do primeiro caracter de cada string em L.
    Por exemplo, countFirsts(['python', 'is', 'pythy']) === {'i': 1, 'p': 2}
    Note que essa funcao retorna um dicionario com cada caracter associada ao
    numero de strings que comecam com aquele caracter.
    """
    return reduce(lambda dic,it: incValue(dic,it[0]), L,{})
print(countFirsts(['python', 'is', 'pythy']))

def mostCommonFirstChar(L):
    """ Retorna a letra mais comum entre as primeiras letras de strings em L.
    Por exemplo:
    mostCommonFirstChar(['python', 'is', 'pythy']) === 'p'
    """
    return reduce(lambda tup,it: tup if tup[1] > it [1] else it, countFirsts(L).items(),('',0))[0]

print(mostCommonFirstChar(['python', 'is', 'pythy']))