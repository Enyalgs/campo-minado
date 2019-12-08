/*
          TRABALHO PRATICO
 CURSO: 		       CIÊNCIA DA COMPUTAÇÃO
 OBJETIVO: 		       CAMPO MINADO DESENVOLVIDO NA LINGUAGEM C
 DISCIPLINA:		   INTROCUÇÃO A PROGRAMAÇÃO
 PROFESSORES: 		   TULIO ANGELO MACHADO TOFFOLO E PUCA HUACHI VAZ PENNA
 DESENVOLVIDO POR:     ENYA LUÍSA GOMES DO SANTOS
 PERIODO:              1º PERIODO
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>                     //Função para usar usleep()

// cores e formato de texto
#define ANSI_RESET            "\x1b[0m"  // desativa os efeitos anteriores
#define ANSI_BOLD             "\x1b[1m"  // coloca o texto em negrito
#define ANSI_COLOR_BLACK      "\x1b[30m"
#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_CYAN       "\x1b[36m"
#define ANSI_COLOR_WHITE      "\x1b[37m"
#define ANSI_BG_COLOR_BLACK   "\x1b[40m"
#define ANSI_BG_COLOR_RED     "\x1b[41m"
#define ANSI_BG_COLOR_GREEN   "\x1b[42m"
#define ANSI_BG_COLOR_YELLOW  "\x1b[43m"
#define ANSI_BG_COLOR_BLUE    "\x1b[44m"
#define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
#define ANSI_BG_COLOR_CYAN    "\x1b[46m"
#define ANSI_BG_COLOR_WHITE   "\x1b[47m"

// macros para facilitar o uso
#define BOLD(string)       ANSI_BOLD             string ANSI_RESET
#define BLACK(string)      ANSI_COLOR_BLACK      string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define RED(string)        ANSI_COLOR_RED        string ANSI_RESET
#define GREEN(string)      ANSI_COLOR_GREEN      string ANSI_RESET
#define YELLOW(string)     ANSI_COLOR_YELLOW     string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define MAGENTA(string)    ANSI_COLOR_MAGENTA    string ANSI_RESET
#define CYAN(string)       ANSI_COLOR_CYAN       string ANSI_RESET
#define WHITE(string)      ANSI_COLOR_WHITE      string ANSI_RESET
#define BG_BLACK(string)   ANSI_BG_COLOR_BLACK   string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_RED(string)     ANSI_BG_COLOR_RED     string ANSI_RESET
#define BG_GREEN(string)   ANSI_BG_COLOR_GREEN   string ANSI_RESET
#define BG_YELLOW(string)  ANSI_BG_COLOR_YELLOW  string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_MAGENTA(string) ANSI_BG_COLOR_MAGENTA string ANSI_RESET
#define BG_CYAN(string)    ANSI_BG_COLOR_CYAN    string ANSI_RESET
#define BG_WHITE(string)   ANSI_BG_COLOR_WHITE   string ANSI_RESET

// caracteres uteis para tabelas
#define TAB_HOR "\u2501" // ━ (horizontal)
#define TAB_VER "\u2503" // ┃ (vertical)
#define TAB_TL  "\u250F" // ┏ (top-left)
#define TAB_ML  "\u2523" // ┣ (middle-left)
#define TAB_BL  "\u2517" // ┗ (bottom-left)
#define TAB_TJ  "\u2533" // ┳ (top-join)
#define TAB_MJ  "\u254B" // ╋ (middle-join)
#define TAB_BJ  "\u253B" // ┻ (bottom-join)
#define TAB_TR  "\u2513" // ┓ (top-right)
#define TAB_MR  "\u252B" // ┫ (middle-right)
#define TAB_BR  "\u251B" // ┛ (bottom-right)

/*
ESTRUTURA CAMPO
OBJETIVO: Estrutura para as matrizes do jogo.
PARAMETRO: 	
   int linhas;
   int colunas;
   int bombas;
   int bandeiras;
   char saida[27][27];
   char entrada[27][27];
*/

typedef struct{
    int linhas;                             //Recebe o tamanho das linhas das matrizes
    int colunas;                            //Recebe o tamanho das colunas das matrizes
    int bombas;                             //Recebe a quatidade de bombas no jogo
    int pontos;                             //Recebe os pontos do jogo
    int bandeiras;                          //Recebe a quatidade de bandeiras que o jogador pode usar
    char **entrada;                         //Matriz que recebe o jogo raiz
    char **saida;                           //Matriz que o úsuario visualiza e onde é feita as alterações
} Campo;

/*
FUNÇÃO: campoMinado
OBJETIVO: Imprimir a palavra CAMPO MINADO.
PARAMETROS:
   
TIPO DE RETORNO: void
*/
void campoMinado();

/*
FUNÇÃO: mensagemInicial
OBJETIVO: Imprimir a mensagem inicial do jogo.
PARAMETROS:
   
TIPO DE RETORNO: void
*/
void mensagemInicial();

/*
FUNÇÃO: confereArgumento
OBJETIVO: Conferir as extensões dos arquivos passados por argumentos correspondem 
          a .jogo ou .txt returna 1 caso não seja e 0 caso seja.
PARAMETROS:
   int argc
   char **argv
TIPO DE RETORNO: int
*/
int confereArgumento(int argc, char **argv);

/*
FUNÇÃO: menuJogada
OBJETIVO: Imprimir as opções de jogada para o úsuario.
PARAMETROS:
   
TIPO DE RETORNO: void
*/
void menuJogada();

/*
FUNÇÃO: alocaMatrizes
OBJETIVO: Alocar mameroria para as duas matrizes presente na struct.
PARAMETROS:
   Campo *jogo
TIPO DE RETORNO: void
*/
void alocaMatrizes(Campo *jogo);

/*
FUNÇÃO: desalocaMatrizes
OBJETIVO: Desalocar mameroria das duas matrizes presente na struct.
PARAMETROS:
   Campo *jogo
TIPO DE RETORNO: void
*/
void desalocaMatrizes(Campo *jogo);

/*
FUNÇÃO: abreArquivo
OBJETIVO: Abrir o arquivo de texto informado pelo úsuario e armazenar seus dados na matriz de entrada.
PARAMETROS:
   char argv[1]
   Campo *jogo
TIPO DE RETORNO: void
*/
void abreArquivo(char argv[1], Campo *jogo);

/*
FUNÇÃO: tratararqSalvo
OBJETIVO: Tratar o aquivo salvo para que seja formatado da forma correta.
PARAMETROS:
   Campo *jogo
TIPO DE RETORNO: void
*/
void tratararqSalvo(Campo *jogo);

/*
FUNÇÃO: abreSalvo
OBJETIVO: Abrir um jogo em andamento quando o úsuario solicitar.
PARAMETROS:
   int argc
   char **argv
   Campo *jogo
TIPO DE RETORNO: void
*/
void abreSalvo(int argc, char **argv, Campo *jogo);

/*
FUNÇÃO:contaBombas
OBJETIVO: Contar o número de bombas que há em um jogo carregado de um arquivo de texto.
PARAMETROS:
   Campo *jogo
TIPO DE RETORNO: void
*/
void contaBombas(Campo *jogo);

/*
FUNÇÃO:defineDificuldade
OBJETIVO: Fazer as alterações de tamanho da linha, coluna e quantidade de bombas de acordo
          com a opção do úsuario.
PARAMETROS:
   Campo *jogo
TIPO DE RETORNO: void
*/
void defineDificuldade(Campo *jogo);

/*
FUNÇÃO:preencheSaida
OBJETIVO: Preencher toda a matriz de saida com traços "-".
PARAMETROS:
   Campo *jogo
TIPO DE RETORNO: void
*/
void preencheSaida(Campo *jogo);

/*
FUNÇÃO:preencheAdjacentes
OBJETIVO: Preencher as células com o valor de bombas proximas.
PARAMETROS:
   Campo *jogo
   int lin
   int col
TIPO DE RETORNO: void
*/
void preencheAdjacentes(Campo *jogo, int lin, int col);

/*
FUNÇÃO:geraAleatorio
OBJETIVO: Iniciar toda matriz de saída do modo aleatorio com 0 e depois colocar as bombas 
          em lugares aleatorios e chamar a função preencheAdjacentes.
PARAMETROS:
   Campo *jogo
TIPO DE RETORNO: void
*/
void geraAleatorio(Campo *jogo);

/*
FUNÇÃO:imprimeCampo
OBJETIVO: Imprimir o campo minado na tela para o úsuario.
PARAMETROS:
   Campo jogo
TIPO DE RETORNO: void
*/
void imprimeCampo(Campo jogo);

/*
FUNÇÃO:expandeCelulas
OBJETIVO: Expandir ou abrir a(as) célula(s) escolhida pelo úsuario.
PARAMETROS:
   Campo *jogo
   int linha
   int coluna
TIPO DE RETORNO: void
*/
void expandeCelulas(Campo *jogo, int linha, int coluna);

/*
FUNÇÃO:marcaCelulas
OBJETIVO: Marcar a célula escolida pelo úsuario.
PARAMETROS:
   int linha
   int coluna
   Campo *jogo
TIPO DE RETORNO: void
*/
void marcaCelulas(int linha, int coluna, Campo *jogo);

/*
FUNÇÃO:coordenadas
OBJETIVO: Receber do úsuario a coordenada que ele quer revelar ou marcar.
PARAMETROS:
   int linha
   int coluna
   Campo *jogo
TIPO DE RETORNO: void
*/
void coordenadas(int *linha, int *coluna, Campo *jogo);

/*
FUNÇÃO:resolverJogo
OBJETIVO: Resolver o jogo, exibindo o jogo completo.
PARAMETROS:
   Campo *jogo
TIPO DE RETORNO: void
*/
void resolverJogo(Campo *jogo);

/*
FUNÇÃO:salvarArq
OBJETIVO: Salvar o jogo em andamento quando o úsuario solicitar
PARAMETROS:
   Campo jogo
   int linha
   int coluna
TIPO DE RETORNO: void
*/
void salvarArq(Campo jogo, int linha, int coluna);

/*
FUNÇÃO:jogada
OBJETIVO: Recebe a opção de jogada do úsuario e chamar a função equivalente a escolha.
PARAMETROS:
   char *acao
   Campo *jogo
   int *linha
   int *coluna
TIPO DE RETORNO: void
*/
void jogada(char *acao, Campo *jogo, int *linha, int *coluna);

/*
FUNÇÃO:jogarNovamente
OBJETIVO: Receber do úsuario a informação se ele deseja jogar novamente e validar.
PARAMETROS:
   char *jogarNovamente
TIPO DE RETORNO: void
*/
void jogarNovamente(char *jogarNovamente);

/*
FUNÇÃO: win
OBJETIVO: Imprimir a mensagem quando o úsuario ganho.
PARAMETROS:
   
TIPO DE RETORNO: void
*/
void win();

/*
FUNÇÃO: gameover
OBJETIVO: Imprimir a mensagem quando o úsuario vence.
PARAMETROS:
   
TIPO DE RETORNO: void
*/
void gameover();

/*
FUNÇÃO: center
OBJETIVO: Ajustar o espaço para que os elementos fiquem sentralizados no terminal.
PARAMETROS:
   int larg
TIPO DE RETORNO: void
*/
void center(int larg);

/*
FUNÇÃO: leEnter
OBJETIVO: Coferir se o que o úsuario digitou foi enter.
PARAMETROS:
   
TIPO DE RETORNO: void
*/
void leEnter();