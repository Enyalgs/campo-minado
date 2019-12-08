/*
          TRABALHO PRATICO
 CURSO: 		       CIÊNCIA DA COMPUTAÇÃO
 OBJETIVO: 		       CAMPO MINADO DESENVOLVIDO NA LINGUAGEM C
 DISCIPLINA:		   INTROCUÇÃO A PROGRAMAÇÃO
 PROFESSORES: 		   TULIO ANGELO MACHADO TOFFOLO E PUCA HUACHI VAZ PENNA
 DESENVOLVIDO POR:     ENYA LUÍSA GOMES DO SANTOS
 PERIODO:              1º PERIODO
*/
#include "campoMinado.h"


void campoMinado()
{
    printf("\n");       
    printf("\t\t   ___oooo______ooo____ooo_____ooo_ooooooo_____oooo_______ooo_____ooo_oooo_ooo____oo____ooo____oooooo_______oooo____\n");
    printf("\t\t   _oo____oo__oo___oo__oooo___oooo_oo____oo__oo____oo_____oooo___oooo__oo__oooo___oo__oo___oo__oo____oo___oo____oo__\n");
    printf("\t\t   oo________oo_____oo_oo_oo_oo_oo_oo____oo_oo______oo____oo_oo_oo_oo__oo__oo_oo__oo_oo_____oo_oo_____oo_oo______oo_\n");
    printf("\t\t   oo________ooooooooo_oo__ooo__oo_oooooo___oo______oo____oo__ooo__oo__oo__oo__oo_oo_ooooooooo_oo_____oo_oo______oo_\n");
    printf("\t\t   _oo____oo_oo_____oo_oo_______oo_oo________oo____oo_____oo_______oo__oo__oo___oooo_oo_____oo_oo____oo___oo____oo__\n");
    printf("\t\t   ___oooo___oo_____oo_oo_______oo_oo__________oooo_______oo_______oo_oooo_oo____ooo_oo_____oo_oooooo_______oooo____\n");
    printf("\t\t   _________________________________________________________________________________________________________________\n");
}

int confereArgumento(int argc, char **argv)
{
    //Se houver apenas um parametro na execução, será verificado se a extensão desse corresponde à .jogo
    if(argc == 2){
        char arquivo[6];
        int n = strlen(argv[1]);                            //Verifica o tamanho da palavra e armasena em n para ser 
        char *nomeArq = malloc(n * sizeof(char));           //feito a alocação dinamica
        strcpy(nomeArq, argv[1]);
        int num = n - 5;
        int j = 0;
        for(int i  = num; i < n; i++){
            arquivo[j] = nomeArq[i];
            j++;
        }
        if(strcmp(arquivo, ".jogo") != 0){                   //Conferindo se a extensão é igual a .jogo
            free(nomeArq);
            return 1;
        }
        free(nomeArq);
    //Se houver dois parametros na execução, será verificado se o segundo parametro corresponde a extesão .txt
    }if(argc == 3){
        char arquivo[6];
        int n = strlen(argv[2]);                           //Verifica o tamanho da palavra e armasena em n para ser
        char *nomeArq = malloc(n * sizeof(char));          //feito a alocação dinamica
        strcpy(nomeArq, argv[2]);
        int num = n - 4;
        int j = 0;
        for(int i  = num; i < n; i++){
            arquivo[j] = nomeArq[i];
            j++;
        }
        if(strcmp(arquivo, ".txt") != 0){                  //Conferindo se a extensão é igual a .txt
            free(nomeArq);
            return 1;
        }
        free(nomeArq);
    }
    return 0;
}

void mensagemInicial()
{
    
    campoMinado();

    printf("\n\n\t\t\t\t\t\t  Desenvolvido por: Enya Luísa Gomes dos Santos\n\n");

    printf("\n\n\t\t\t\t\t\t\t\tBem-Vindo(a) ao jogo.\n");
    printf("\n\n\t\t\t\t\tInstruções:\n");
    printf("\t\t\t\t\t1 -  Você ganha o jogo se você abrir todas as celulas que não são bombas.\n");
    printf("\t\t\t\t\t2 -  Se você descobrir uma mina, o jogo acaba.\n");
    printf("\t\t\t\t\t3 -  Você pode marcar e desmarcar onde acha que há bomba.\n");
    printf("\t\t\t\t\t4 -  O jogo pode ser salvo para retoma-lo posteriormente.\n");
    printf("\t\t\t\t\t5 -  Os comandos devem ser seguidos dos argumentos se houver.\n");
    printf("\n\n\t\t\t\t\t\tPara melhor experiência jogue com a tela maximizada.\n");
    printf("\n\n\t\t\t\t\t\t\t  Pressione ENTER para começar");
    leEnter();
}

void menuJogada()
{   
    campoMinado();

    printf("\n\n");
    printf(BOLD("\t\t\t\t\t   _______________________OPÇÕES PARA JOGAR___________________\n"));
    printf(BOLD("\t\t\t\t\t  |  COMANDOS |ARGUMENTO|               AÇÕES                 |\n"));
    printf(BOLD("\t\t\t\t\t  |___________________________________________________________|\n"));
    printf(BOLD("\t\t\t\t\t  | x         |   AC    |  Marca a célula digitada.           |\n"));
    printf(BOLD("\t\t\t\t\t  | o         |   EC    |  Revela o valor da célula digitada. |\n"));
    printf(BOLD("\t\t\t\t\t  | resolver  |         |  Resolve o jogo.                    |\n"));
    printf(BOLD("\t\t\t\t\t  | salvar    |   out   |  Salva o jogo.                      |\n"));
    printf(BOLD("\t\t\t\t\t  | sair      |         |  Encerra o jogo sem salvar.         |\n"));
    printf(BOLD("\t\t\t\t\t  |___________________________________________________________|\n"));
    printf("\n");
}

void alocaMatrizes(Campo *jogo)
{
    //Alocação dinamica das matrizes 
    jogo->entrada = malloc(jogo->linhas * sizeof(char *));
    jogo->saida = malloc(jogo->linhas * sizeof(char *));
    for(int i = 0; i < jogo->linhas; i++){
        jogo->entrada[i] = malloc(jogo->colunas * sizeof(char));
        jogo->saida[i] = malloc(jogo->colunas * sizeof(char));
    }
}

void desalocaMatrizes(Campo *jogo)
{
    //Liberação das memorias ocupadas pelas matrizes 
    for(int i = 0; i < jogo->linhas; i++){
        free(jogo->entrada[i]);
        free(jogo->saida[i]);
    }
    free(jogo->entrada);
    free(jogo->saida);
}

void abreArquivo(char argv[1], Campo *jogo)
{
    FILE *arq  = fopen(argv, "r");                                           //Abertura do arquivo de texto

    if(arq == NULL){                                                         //Confere se o arquivo existe
        printf(RED("Erro ao abrir o arquivo. Tente novamente")"\a\n");
        exit(1);
    }
   
    fscanf(arq, "%d %d", &jogo->linhas, &jogo->colunas);                     //Armazena os dois primeiros valores como inteiros em variaveis que representam o tamanho da linha e coluna da matriz

    fscanf(arq, "\n");                                                       //Lễ uma quebra de linha
    alocaMatrizes(jogo);
    //Enquanto não for o final do arquivo os caracteres do arquivo de texto será armazenado na matriz de entrada
    while(!feof(arq)){                                                    
        for(int i = 0; i < jogo->linhas; i++){
            for(int j = 0; j < jogo->colunas; j++){
                fscanf(arq, "%c", &jogo->entrada[i][j]);
                fscanf(arq, " ");
            }
        }
    }
    fclose(arq);                                                             //Fecha o arquivo de texto
    contaBombas(jogo);
}

void contaBombas(Campo *jogo)
{
    jogo->bandeiras = 0;                              //Conta bombas inicia com 0
    for(int i = 0; i < jogo->linhas; i++){
        for(int j = 0; j < jogo->colunas; j++){
            if(jogo->entrada[i][j] == 'x')            //Quando encontrar bomba uma bomba adiciona mais na variavel que armazena o número de bandeiras
                jogo->bandeiras += 1;
        }
    }
    jogo->bombas = jogo->bandeiras;                   //Número de bombas será igual ao número de bandeiras
}

void defineDificuldade(Campo *jogo)
{
    campoMinado();

    printf("\n\n");         
    printf(BOLD("\t\t\t\t\t     ______________________DIFICULDADE____________________\n"));
    printf(BOLD("\t\t\t\t\t    |  COMANDOS   |                NIVEIS                 |\n"));
    printf(BOLD("\t\t\t\t\t    |_____________________________________________________|\n"));
    printf(BOLD("\t\t\t\t\t    |     1       |     Facil    - 08 x 08  (09 minas)    |\n"));
    printf(BOLD("\t\t\t\t\t    |     2       |     Médio    - 10 x 14  (20 minas)    |\n"));
    printf(BOLD("\t\t\t\t\t    |     3       |     Díficil  - 16 x 20  (70 minas)    |\n"));
    printf(BOLD("\t\t\t\t\t    |_____________________________________________________|\n"));
    printf(BOLD("\t\t\t\t\t    "));
    int dificuldade;    
   //Valida a resposta do úsuario e imprime uma mensagem de erro caso a resposta não seja aceita
    do{
        scanf("%d", &dificuldade);
        if(dificuldade < 1 || dificuldade > 3){                                                                                           
            printf(RED("\t\t\t\t\t    ERRO - opção digita inválida, tente novamente. [ 1, 2 ou 3]: ")"\a");
            getchar();
        }
    }while(dificuldade < 1 || dificuldade > 3);
    //Altera o número de linhas, colunas e bombas de acordo com a dificuldade escolhida pelo úsuario
    
    switch(dificuldade)
    {   
        case 1:
            jogo->linhas = 8;
            jogo->colunas = 8;
            jogo->bombas = 9;
            break;
        case 2:
            jogo->linhas = 10;
            jogo->colunas = 14;
            jogo->bombas = 20;
            break;
        case 3:
            jogo->linhas = 16;
            jogo->colunas = 20;
            jogo->bombas = 72;
            break;
    }
    jogo->bandeiras = jogo->bombas;                   //O número de bandeiras inicia com o número de bombas
    alocaMatrizes(jogo);
}

void preencheSaida(Campo *jogo)
{
    //Preenche toda a matriz de saida com "-"
    for(int i = 0; i < jogo->linhas; i++)
        for(int j = 0; j < jogo->colunas; j++)
            jogo->saida[i][j] = '-';
}

void preencheAdjacentes(Campo *jogo, int lin, int col)
{
    //Conta o valor de bombas nas casas adjacentes 
    for(int i = lin - 1; i <= lin + 1; i++)
        for(int j = col - 1; j <= col + 1; j++)
            if(i >= 0 && i <  jogo->linhas && j >= 0 && j < jogo->colunas && jogo->entrada[i][j] != 'x')
                jogo->entrada[i][j] += 1;
}

void geraAleatorio(Campo *jogo)
{
    //Preenche toda matriz com '0'
    for(int i = 0; i < jogo->linhas; i++)
        for(int j = 0; j < jogo->colunas; j++)
            jogo->entrada[i][j] = '0';  

    //Gerar bombas do campo minado aleatorio
    srand(time(NULL));
    int lin, col;
    for(int i = 0; i < jogo->bombas; i++){
        lin = rand() % jogo->linhas;
        col = rand() % jogo->colunas;
        while(jogo->entrada[lin][col] == 'x'){
            lin = rand() % jogo->linhas;
            col = rand() % jogo->colunas;
        }
        jogo->entrada[lin][col] = 'x';
        preencheAdjacentes(jogo, lin, col);
    }
}

void imprimeCampo(Campo jogo)
{
    //Imprime a matriz que o úsuario vê usando o sistema de cores ANSI
    center(jogo.colunas);                                               //Função que centraliza as matrizes
    printf(BOLD(BG_MAGENTA(TAB_TL)));
    printf(BOLD(BG_MAGENTA(TAB_HOR TAB_HOR TAB_HOR TAB_TJ)));

    for(int i = 0; i < jogo.colunas; i++){
        if(i != (jogo.colunas -1))
            printf(BOLD(BG_MAGENTA(TAB_HOR TAB_HOR TAB_HOR)));
        else
            printf(BOLD(BG_MAGENTA(TAB_HOR TAB_HOR TAB_HOR TAB_TR)));
        }
    printf("\n");
    center(jogo.colunas);                                                //Função que centraliza as matrizes
    printf(BOLD(BG_MAGENTA(TAB_VER)));
    printf(BOLD(BG_MAGENTA("   "TAB_VER)));

    for(int i = 0; i < jogo.colunas; i++)
        printf(BOLD(BG_MAGENTA(WHITE(" %c "))), 'A' + i);
    

    printf(BOLD(BG_MAGENTA(TAB_VER)));
    printf("\n");
    center(jogo.colunas);                                                //Função que centraliza as matrizes
    printf(BOLD(BG_MAGENTA(TAB_ML)));
    printf(BOLD(BG_MAGENTA(TAB_HOR TAB_HOR TAB_HOR TAB_MJ)));

    for(int i = 0; i < jogo.colunas; i++){
        if(i != (jogo.colunas -1))
            printf(BOLD(BG_MAGENTA(TAB_HOR TAB_HOR TAB_HOR)));
        else
             printf(BOLD(BG_MAGENTA(TAB_HOR TAB_HOR TAB_HOR TAB_MR)));
    }

    printf("\n");

    for(int i = 0; i < jogo.linhas; i++){
        center(jogo.colunas);                                             //Função que centraliza as matrizes
        printf(BOLD(BG_MAGENTA(TAB_VER)));
        printf(BOLD(BG_MAGENTA(WHITE(" %c "))), 'A' + i);
        printf(BOLD(BG_MAGENTA(TAB_VER)));
        for(int j = 0; j < jogo.colunas; j++){
            //Altera as cores dos caracteres de acordo com seu valor
            if(jogo.saida[i][j] == '1')
                printf(BOLD(BG_MAGENTA(BLUE(" %c "))), jogo.saida[i][j]);
            else if(jogo.saida[i][j] == '2')
                printf(BOLD(BG_MAGENTA(YELLOW(" %c "))), jogo.saida[i][j]);
            else if(jogo.saida[i][j] == '3')
                printf(BOLD(BG_MAGENTA(GREEN(" %c "))), jogo.saida[i][j]);
            else if(jogo.saida[i][j] == '4')
                printf(BOLD(BG_MAGENTA(CYAN(" %c "))), jogo.saida[i][j]);
            else if(jogo.saida[i][j] == '5')
                printf(BOLD(BG_MAGENTA(MAGENTA(" %c "))), jogo.saida[i][j]);
            else if(jogo.saida[i][j] == 'x')
                printf(BG_MAGENTA(RED(" %c ")), jogo.saida[i][j]);
            else if(jogo.saida[i][j] == '0')
                printf(BG_MAGENTA(BLACK(" %c ")), jogo.saida[i][j]);
            else
                printf(BOLD(BG_MAGENTA(BOLD(WHITE(" %c ")))), jogo.saida[i][j]);
        }
        printf(BOLD(BG_MAGENTA(TAB_VER))"\n");
    }
    center(jogo.colunas);                                                             //Função que centraliza as matrizes
    printf(BOLD(BG_MAGENTA(TAB_BL)));
    printf(BOLD(BG_MAGENTA(TAB_HOR TAB_HOR TAB_HOR TAB_BJ)));

    for(int i = 0; i < jogo.colunas; i++){
      if(i != (jogo.colunas -1))
        printf(BOLD(BG_MAGENTA(TAB_HOR TAB_HOR TAB_HOR)));
      else
        printf(BOLD(BG_MAGENTA(TAB_HOR TAB_HOR TAB_HOR TAB_BR)));
    }
    printf("\n");
}

void expandeCelulas(Campo *jogo, int linha, int coluna)
{
    //Se o jogador tentar abrir uma celula que já foi descoberta não altera a puntuação
    if(jogo->entrada[linha][coluna] == jogo->saida[linha][coluna])
        jogo->pontos--;
    //Se a coordenada escolhida estiver bomba, revala todas as bombas 
    if(jogo->entrada[linha][coluna] == 'x'){
        for(int i = 0; i < jogo->linhas; i++){
            for(int j = 0; j < jogo->colunas; j++){
                if(jogo->entrada[i][j] == 'x'){
                   jogo->saida[i][j] = jogo->entrada[i][j];
                }
            }
        }
    //Se a coordenada escolhida não tiver bomba e for diferente de 0, apenas abre a celula escolhida
    }else if(jogo->entrada[linha][coluna] != '0') {
        if(jogo->saida[linha][coluna] == '*') //Se o jogador abrir uma celula que esta marcada, o número de bombas disponiveis aumenta mais um
            jogo->bandeiras+=1; 
        jogo->saida[linha][coluna] = jogo->entrada[linha][coluna];
        jogo->pontos++;
    //Se a coordenada escolhida não tiver bomba e for igual 0, abre a celula escolhida e todas as proximas que sejam igual a 0
    }else{
        int i, j; 
        if(jogo->saida[linha][coluna] == '*') //Se o jogador abrir uma celula que esta marcada, o número de bombas disponiveis aumenta mais um
            jogo->bandeiras+=1; 
        jogo->saida[linha][coluna]  = jogo->entrada[linha][coluna];
        jogo->pontos++;
        for(i = linha - 1; i <= linha + 1; i++){
            for(j = coluna - 1; j <= coluna + 1; j++){
                //Verifica se i e j estão no limite da matriz e se a coordenada é igual a - ou igual a *
                if(i >= 0 && i < jogo->linhas && j >= 0 && j < jogo->colunas && (jogo->saida[i][j] == '-' || jogo->saida[i][j] == '*')){
                    expandeCelulas(jogo, i, j);
                }
            }
        }
    }
}

void marcaCelulas(int linha, int coluna, Campo *jogo)
{
    if(jogo->bandeiras == 0 && jogo->saida[linha][coluna] == '*'){
        jogo->bandeiras++;                                          //Adciona +1 no contador de bandeiras 
        jogo->saida[linha][coluna] = '-';
    }else{
        //Marca as celulas escolhida pelo usuario adicionando um * se ainda houver bandeiras 
        if(jogo->bandeiras > 0 && (jogo->saida[linha][coluna] == '*' || jogo->saida[linha][coluna] == '-')){
            if(jogo->saida[linha][coluna] == '*'){                          //Se o úsuario marcar em um lugar que já tem bomba, a bomba é retirada
                jogo->bandeiras++;                                          //Adciona +1 no contador de bandeiras 
                jogo->saida[linha][coluna] = '-';
            }else if(jogo->saida[linha][coluna] != '*'){                    //Se não tiver uma bomba no local é adcionado um *
                jogo->bandeiras--;                                          //Retira -1 no contador de bombas
                jogo->saida[linha][coluna] = '*';
            }
        }
    }
}

void coordenadas(int *linha, int *coluna, Campo *jogo)
{
    char linCol[100];
    //Valida a coordenada digitada e imprime uma mensagem de erro caso a resposta não seja aceita
    do{
        //Valida a coordenada digitada e imprime uma mensagem de erro caso a resposta não seja aceita
        do{
            scanf("%s", linCol);
            if(strlen(linCol) >= 3)
                printf(RED("\t\t\t\t\t    ERRO - coordenada inválida. Digite novamente: "));             
        }while(strlen(linCol) >= 3);
        
        //Converte o valor de char para o valor int equivalente 
        *linha = (int)linCol[0] - 65;
        *coluna = (int)linCol[1] - 65;
        if(*linha < 0  ||  (*linha > jogo->linhas)  ||  *coluna < 0  ||  (*coluna > jogo->colunas)){
            printf(RED("\t\t\t\t\t    ERRO - opção digita inválida, digite novamente. [DENTRO DOS PARAMETROS DA MATRIZ]: "));
        }
    }while(*linha < 0  ||  (*linha > jogo->linhas)  ||  *coluna < 0  ||  (*coluna > jogo->colunas));
}

void resolverJogo(Campo *jogo)
{
    //Todas as celulas da saida receberá as celulas da entrada
    for(int i = 0; i < jogo->linhas; i++){
        for(int j = 0; j < jogo->colunas; j++){
            jogo->saida[i][j] = jogo->entrada[i][j];
        }
    }
}

void salvarArq(Campo jogo, int linha, int coluna)
{
    char nomeArq[100];
    char nomeJogo[100];
    //Trata o nome do arquivo digitado pelo úsuario.
    do{
        scanf("%s", nomeArq);
        if(strlen(nomeArq) > 99)
            printf(RED("\t\t\t\t\t    ERRO - O nome do arquivo digitado é muito longo. Tente novamente: "));
    }while(strlen(nomeArq) > 99);

    strcpy(nomeJogo, nomeArq);
    strcat(nomeArq, ".txt");                                         //Concatena a extensão .txt no nome do arquivo
    
    FILE *save = fopen(nomeArq, "w");                                //Abre um arquivo com o nome escolhido pelo úsuario como escrita
    fprintf(save, "%d %d\n", jogo.linhas, jogo.colunas);             //Imprime na primeira linha do arquivo o tamanho da linha e coluna do arquivo
    fprintf(save, "\n");                                                     //Imprime uma quebra de linha no arquivo
    //Imprime o jogo salvo no arquivo de texto
    for(int i = 0; i < jogo.linhas; i++){
        for(int j = 0; j < jogo.colunas; j++){
            if(jogo.saida[i][j] == '*')                                   //Se a célula estiver marcada, no arquivo será imprimido um x
                fprintf(save, "%c ", 'x');
            else if(jogo.saida[i][j] != '-')                              //Se a célula estiver aberta, no arquivo será imprimido um o
                fprintf(save, "%c ", 'o');
            else if(jogo.saida[i][j] == '-')                              //Se a célula ainda não foi aberta, no arquivo permanece com -
                fprintf(save, "%c ", '-');
        }
        fprintf(save, "\n");                                                 //Imprime uma quebra de linha no arquivo a cada linha da matriz
    }

    strcat(nomeJogo, ".jogo"); 
    FILE *saveJogo = fopen(nomeJogo, "w"); 
    fprintf(saveJogo, "%d %d\n", jogo.linhas, jogo.colunas);                //Imprime na primeira linha do arquivo o tamanho da linha e coluna do arquivo
    fprintf(saveJogo, "\n");      
    for(int i = 0; i < jogo.linhas; i++){
        for(int j = 0; j < jogo.colunas; j++){
            fprintf(saveJogo, "%c ", jogo.entrada[i][j]);                 //Imprime a matriz de entrada no arquivo de texto
        }
        fprintf(saveJogo, "\n");                                                 //Imprime uma quebra de linha no arquivo
    }
    fclose(save);                                                            //Fecha o arquivo
    fclose(saveJogo);  
    printf("\a");
}

void tratararqSalvo(Campo *jogo)
{
    int contBombas = 0;
    //Altera o jogo para retoma-lo 
    for(int i = 0; i < jogo->linhas; i++){
        for(int j = 0; j < jogo->colunas; j++){
            if(jogo->saida[i][j] == 'o'){
                jogo->saida[i][j] = jogo->entrada[i][j];
                jogo->pontos++;                                             //Conta quantos pontos o úsuario tem no arquivo salvo
            }
            if(jogo->saida[i][j] == 'x'){
                jogo->saida[i][j] = '*';
                contBombas++;
            }
        }
    }
    contaBombas(jogo);
    jogo->bandeiras= jogo->bandeiras - contBombas;                          //Atualiza o número de bandeiras
        
}

void abreSalvo(int argc, char **argv, Campo *jogo)
{
    //Abertura do arquivo como leitura
    FILE *abreSalvo = fopen(argv[2], "r");

    //Imprimi uma mensagem de erro caso o arquivo estejá vazio ou não exista
    if(abreSalvo == NULL){
        printf(RED("Erro ao abrir o arquivo. Tente novamente")"\a\n");
    } 
    fscanf(abreSalvo, "%d %d", &jogo->linhas, &jogo->colunas);               //Armazena os dois itens do arquivo texto em variaveis que representam o tamanho da linha e da coluna da matriz
    fscanf(abreSalvo, "\n");                                                               //Lê uma quebra de linha no arquivo de texto
    alocaMatrizes(jogo);
    //Lê cada caractere do arquivo de texto e armazena em uma posição da matriz de entrada
    while(!feof(abreSalvo)){
        for(int i = 0; i < jogo->linhas; i++){
            for(int j = 0; j < jogo->colunas; j++){
                fscanf(abreSalvo, "%c", &jogo->saida[i][j]);
                fscanf(abreSalvo, " ");
            }
        }
    }
    
    //Abertura do arquivo como leitura
    FILE *abreJogo = fopen(argv[1], "r");

    //Imprimi uma mensagem de erro caso o arquivo estejá vazio ou não exista
    if(abreJogo == NULL){
        printf(RED("Erro ao abrir o arquivo. Tente novamente")"\a\n");
    } 
    fscanf(abreJogo, "%d %d", &jogo->linhas, &jogo->colunas);                   //Armazena os dois itens do arquivo texto em variaveis que representam o tamanho da linha e da coluna da matriz
    fscanf(abreJogo, "\n");                                                     //Lê uma quebra de linha no arquivo de texto
    while(!feof(abreJogo)){
        for(int i = 0; i < jogo->linhas; i++){
            for(int j = 0; j < jogo->colunas; j++){
                fscanf(abreJogo, "%c", &jogo->entrada[i][j]);
                fscanf(abreJogo, " ");
            }
        }
    }

    //Fecha os arquivos
    fclose(abreSalvo); 
    fclose(abreJogo);
    tratararqSalvo(jogo);                                       
}

void jogada(char *acao, Campo *jogo, int *linha, int *coluna)
{
    //Valida a resposta do úsuario e imprime uma mensagem de erro caso a resposta não seja aceita
    do{
        printf("\n");
        int larg = jogo->colunas;
        center(larg);
        printf("COMANDO: ");
        scanf("%s", acao);
        if(strcmp(acao, "x") != 0 && strcmp(acao, "o") != 0 && strcmp(acao, "resolver") != 0 && 
        strcmp(acao, "salvar") != 0 && strcmp(acao, "sair") != 0){
            printf(RED("\t\t\t\t\t    ERRO - opção digitada inválida, tente novamente.[COMANDO INVALIDO]") "\n");
        }
    }while(strcmp(acao, "x") != 0 && strcmp(acao, "o") != 0 && strcmp(acao, "resolver") != 0 && 
    strcmp(acao, "salvar") != 0 && strcmp(acao, "sair") != 0);

    //Chama a função de acordo com a opção digitada
    if(strcmp(acao, "resolver") == 0){
        resolverJogo(jogo);
    }
    else if(strcmp(acao, "salvar") == 0){
        salvarArq(*jogo, *linha, *coluna);
    }
    else if(strcmp(acao, "o") == 0){
        do{
            coordenadas(linha, coluna, jogo);
            if(jogo->entrada[*linha][*coluna] == jogo->saida[*linha][*coluna]){
                printf(RED("\t\t\t\t\t    ERRO - Celula já foi descoberta. Digite novamente: "));
            }
        }while (jogo->entrada[*linha][*coluna] == jogo->saida[*linha][*coluna]);
        expandeCelulas(jogo, *linha, *coluna);
    }
    else if(strcmp(acao, "x") == 0){
        coordenadas(linha, coluna, jogo);
        marcaCelulas(*linha, *coluna, jogo);
    }
}

void jogarNovamente(char *jogarNovamente)
{
    //Valida a resposta do úsuario e imprime uma mensagem de erro caso a resposta não seja aceita
    do{
    printf("Deseja jogar novamente S/N? ");
    scanf("%s", jogarNovamente);
    if(*jogarNovamente != 'S' && *jogarNovamente != 'N')
        printf(RED("\t\t\t\t\t    ERRO - opção digita inválida, tente novamente: "));
    }while(*jogarNovamente != 'S' && *jogarNovamente != 'N');
}

void gameover()
{
    //Printf com um intervalo de 200000 microsegundos, ou seja 0.2 segundos    
    usleep(200000);
    printf("\n\n\a");
    printf(RED("\t\t\t\t     oooooo____ooooooo_ooooooo___ooooooo______oooo____oooooooo____ooo____\n"));
    usleep(200000);
    printf(RED("\t\t\t\t     oo____oo__oo______oo____oo__oo____oo___oo____oo_____oo_____oo___oo__\n"));
    usleep(200000);
    printf(RED("\t\t\t\t     oo_____oo_oooo____oo____oo__oo____oo__oo______oo____oo____oo_____oo_\n"));
    usleep(200000);
    printf(RED("\t\t\t\t     oo_____oo_oo______ooooooo___ooooooo___oo______oo____oo____ooooooooo_\n"));
    usleep(200000);
    printf(RED("\t\t\t\t     oo____oo__oo______oo____oo__oo____oo___oo____oo_____oo____oo_____oo_\n"));
    usleep(200000);
    printf(RED("\t\t\t\t     oooooo____ooooooo_oo_____oo_oo_____oo____oooo_______oo____oo_____oo_\n"));
    usleep(200000);
    printf(RED("\t\t\t\t    ____________________________________________________________________\n"));
    usleep(200000);
    printf("\n\n");

    
}

void win()
{   
    //Printf com um intervalo de 200000 microsegundos, ou seja 0.2 segundos  
    usleep(200000);
    printf("\n\n\a");
    printf(YELLOW("\t\t\t\t\t**  oo____oo_oooo_oooooooo____oooo____ooooooo___oooo____ooo____   **\n"));
    usleep(200000);   
    printf(YELLOW("\t\t\t\t\t**  oo____oo__oo_____oo_____oo____oo__oo____oo___oo___oo___oo__   **\n"));
    usleep(200000);   
    printf(YELLOW("\t\t\t\t\t**  oo____oo__oo_____oo____oo______oo_oo____oo___oo__oo_____oo_   **\n"));
    usleep(200000);   
    printf(YELLOW("\t\t\t\t\t**  _oo__oo___oo_____oo____oo______oo_ooooooo____oo__ooooooooo_   **\n"));
    usleep(200000);   
    printf(YELLOW("\t\t\t\t\t**  __oooo____oo_____oo_____oo____oo__oo____oo___oo__oo_____oo_   **\n"));
    usleep(200000);   
    printf(YELLOW("\t\t\t\t\t**  ___oo____oooo____oo_______oooo____oo_____oo_oooo_oo_____oo_   **\n"));
    usleep(200000);   
    printf(YELLOW("\t\t\t\t\t**  ___________________________________________________________   **\n"));
    usleep(200000); 
    printf(YELLOW("\t\t\t\t\t**                                                                **\n"));  
    usleep(200000); 
    printf("\n\n");
}

void center(int larg)
{
    //Calcula a posição da string na tela do terminal 
    int len = (46-larg)/2;
    //um for de n espaços para que seja centralizado
    for (int i=0; i< len; i++)
        printf("   ");

}

void leEnter() {
    int c;
    //Armazena na variavel c o que foi digitado pelo úsuario e
    //Enquanto não for o espaço (corresponde a 10 na bela ASCII) e não conseguir ler nada
    do{
        c = getchar();
    } while (c != 10 && c != EOF);
}

