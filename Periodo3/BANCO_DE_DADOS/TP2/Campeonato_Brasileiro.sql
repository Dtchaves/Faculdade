BEGIN;

CREATE TABLE campeonato(
	ano	YEAR NOT NULL,
    data_inicio DATE NOT NULL,
    data_fim DATE,
    codigo_campeonato INT NOT NULL,
    
    PRIMARY KEY (codigo_campeonato)
);

CREATE TABLE clube(
	codigo_time INT NOT NULL,
    nome VARCHAR(100) NOT NULL,
    estado CHAR(2) NOT NULL,
    
    PRIMARY KEY (codigo_time)
);

CREATE TABLE jogo(
	codigo_jogo INT NOT NULL,
    data_jogo DATE NOT NULL,
    horario TIME NOT NULL,
    estadio VARCHAR(100) NOT NULL,
    rodada INT NOT NULL,
    codigo_mandante INT NOT NULL,
    codigo_visitante INT NOT NULL,
    gols_mandante INT NOT NULL,
    gols_visitante INT NOT NULL,
    
    PRIMARY KEY (codigo_jogo),
    FOREIGN KEY (codigo_mandante) REFERENCES
		clube(codigo_time) ON DELETE CASCADE,
    FOREIGN KEY (codigo_visitante) REFERENCES 
		clube(codigo_time) ON DELETE CASCADE
);

CREATE TABLE funcionario(
	codigo_funcionario INT NOT NULL,
    codigo_time INT NOT NULL,
    nome VARCHAR(100) NOT NULL,
    idade INT,
    salario DOUBLE NOT NULL,
    nacionalidade VARCHAR(50),
    data_nascimento DATE NOT NULL,
    altura DOUBLE,
    peso DOUBLE,
    posicao DOUBLE,
    
    PRIMARY KEY(codigo_funcionario),
    FOREIGN KEY (codigo_time) REFERENCES clube(codigo_time)
);

CREATE TABLE jogador(
	codigo_jogador INT NOT NULL,
	altura DOUBLE NOT NULL,
    peso DOUBLE NOT NULL,
    posicao CHAR(2) NOT NULL,
    
    PRIMARY KEY (codigo_jogador),
    FOREIGN KEY (codigo_jogador) REFERENCES funcionario (codigo_funcionario)
);

CREATE TABLE tecnico(
	codigo_tecnico INT NOT NULL,
    
    PRIMARY KEY (codigo_tecnico),
    FOREIGN KEY (codigo_tecnico) REFERENCES funcionario (codigo_funcionario)
);

CREATE TABLE participacao_time_campeonato(
    codigo_time INT NOT NULL,
    codigo_campeonato INT NOT NULL,
    pontos INT NOT NULL,
    vitorias INT NOT NULL,
    derrotas INT NOT NULL,
    empates INT NOT NULL,
    gols_pro INT NOT NULL,
    gols_contra INT NOT NULL,
    cartoes_amarelo INT,
    cartoes_vermelho INT,
    
	PRIMARY KEY (codigo_time, codigo_campeonato),
    FOREIGN KEY (codigo_time) REFERENCES clube(codigo_time),
    FOREIGN KEY (codigo_campeonato) REFERENCES campeonato(codigo_campeonato)
);

CREATE TABLE patrocinador(
	CNPJ VARCHAR(11) NOT NULL,
    nome VARCHAR(50) NOT NULL,
    codigo_time INT NOT NULL,
    valor_patrocinio DOUBLE NOT NULL,
    ano_inicio YEAR NOT NULL,
    ano_fim YEAR NOT NULL,
    
    PRIMARY KEY (CNPJ, codigo_time),
    FOREIGN KEY (codigo_time) REFERENCES clube(codigo_time)
);

INSERT INTO participacao_time_campeonato VALUES (532201593, 2, 0, 0, 38, 0, 0, 0, 0, 0);