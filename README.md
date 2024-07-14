## Leitura de Arquivo
Este projeto de Leitura de Arquivos em Linguagem C foi proposto pela disciplina de programação para gerenciar dados de heróis e vilões.

## Funcionalidades
- **Leitura de Dados**: O sistema importa informações de países, heróis e vilões a partir de arquivos de texto, possibilitando atualizações fáceis sem necessidade de alterar o código-fonte.
- **Exibição de Dados**: Os dados são impressos de forma organizada, facilitando a visualização e análise das informações dos personagens.
- **Cálculo do IMC**: O Índice de Massa Corporal (IMC) dos vilões é calculado, oferecendo uma visão sobre a saúde dos personagens.
- **Análises Estatísticas**: O programa identifica países com mais heróis do que vilões e determina quais heróis possuem a maior classificação em cada país.
- **Filtragem por Individualidade**: É possível filtrar e listar heróis cuja individualidade contém a letra "M", permitindo uma análise mais específica.

Estrutura do Projeto
O projeto é composto por um arquivo principal main.c, que contém a lógica do sistema, e arquivos de entrada como paises.txt, herois.txt e viloes.txt, que devem ser criados para alimentar o sistema.

## Estruturas de dados
```c
  typedef struct Heroi {
      char nome[MAX_TAM];
      char individualidade[MAX_TAM];
      float peso;
      float altura;
      int rank;
  } Heroi;

  typedef struct Vilao {
    char nome[MAX_TAM];
    char individualidade[MAX_TAM];
    float peso;
    float altura;
    int nivel;
  } Vilao;
  
  typedef struct Pais {
    char nome[MAX_TAM];
    char arquivo_herois[MAX_TAM];
    char arquivo_viloes[MAX_TAM];
    int num_herois;
    Heroi herois[MAX_TAM];
    int num_viloes;
    Vilao viloes[MAX_TAM];
  } Pais;
```

## Exemplo de arquivo
`paises.txt`
```c
Pais1    herois_pais1.txt    viloes_pais1.txt
Pais2    herois_pais2.txt    viloes_pais2.txt
```

`herois.txt`
```c
Heroi1    Poder1    70.5    1.75    1
Heroi2    Poder2    80.0    1.80    2
```

`viloes.txt`
```c
Vilao1    Poder1    90.0    1.85    5
Vilao2    Poder2    85.0    1.80    4
```

## Como usar
- **Clone o repositório:**
git clone https://github.com/seuusuario/seurepositorio.git

- **Navegue até o diretório do projeto:**
cd seurepositorio

- **Compile o programa:**
gcc main.c -o leitura_arquivos

- **Execute o programa:**
./leitura_arquivos

- **Observação:**
Certifique-se de que os arquivos paises.txt, herois.txt e viloes.txt estejam no mesmo diretório que o executável.

Sinta-se à vontade para ajustar qualquer parte conforme necessário! Se precisar de mais alguma coisa, é só avisar.

