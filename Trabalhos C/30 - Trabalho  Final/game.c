#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

#define COR_PRETO 		printf("\33[30m");
#define COR_VERMELHO 	printf("\33[31m");
#define COR_VERDE 		printf("\33[32m");
#define COR_LARANJA 	printf("\33[33m");
#define COR_AZUL 		printf("\33[34m");
#define COR_ROXO		printf("\33[35m");
#define COR_AGUA		printf("\33[36m");
#define COR_BRANCO 		printf("\33[37m");


// FUNÇÃO PARA CAPTURA DE TECLA
int getch(void) {

    struct termios oldattr, newattr;
    int ch;

    tcgetattr( STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO);
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr);

    return ch;
}

#define LAR 		62
#define ALT 		18
#define CAMINHO 	0
#define PAREDE 		1
#define INICIO 		2
#define ANIMAL		3
#define TRILHA      4
#define MOVIMENTO   5

typedef struct{
    int map[ALT][LAR];
} save_Map;

int main() {

    save_Map save;
	FILE *fp_bin, *fp_txt;
    // VAR OP
    int menu, final, flag_final, fim, erro, controle, op_mapa, op_modoJogo, op_fim;
    // VAR TIMER
    unsigned int timeIni, timeFim, seg, min, timeTotal;
    //
    int mapa[ALT][LAR], mapaEspelho[ALT][LAR];
    int a, lin, linha, col, px, py, flag_controle, flag_animal, flag_inicio, flag_init, cont, animation;
    char jogada, *nome_mapa = malloc(99 * sizeof(char));

    // INICIANDO VARIAVEIS
    final = fim = 0;
    px = py = 1;
    erro = flag_controle = 0;
    linha = 1;
    min = 0;
    flag_init = 0;

    while(fim == 0){

        // PRINTA MENU
        system("clear");
        COR_LARANJA
        printf("\n\t     RESCUE GAME");
        COR_BRANCO
        printf("\n\t====================\n\t||");
        COR_VERDE
        printf("(1) - Criar Mapa");
        COR_BRANCO
        printf("||\n\t====================\n\t||");
        COR_VERMELHO
        printf("(2) - Jogar Mapa");
        COR_BRANCO
        printf("||\n\t====================\n");
        printf("\t> ");
        scanf("%i", &menu);

        // MENU
        switch(menu) {

            // EDITOR DE MAPAS
            case 1:

                // INICIALIZA O MAPA COM PAREDES
	            for(lin=0; lin<ALT; lin++) {
		            for(col=0; col<LAR; col++) {
			            mapa[lin][col] = PAREDE;
		            }
	            }
                
                final = 0;

                // INICIO DO MODO DE EDIÇÃO
                while(final == 0){

                    COR_LARANJA
                    system("clear");
                    printf("\t\t  EDITOR DE MAPAS - GAME RESGATE\n");
                    COR_BRANCO
                    for(lin=0; lin<ALT; lin++) {
                        for(col=0; col<LAR; col++) {

                            if(lin == px && col == py) {
                                COR_VERMELHO					
                                printf("_");
                            }
                            else if(mapa[lin][col] == CAMINHO) {
                                COR_BRANCO
                                printf(" ");
                            }
                            else if(mapa[lin][col] == PAREDE) {
                                COR_BRANCO
                                printf("#");
                            }
                            else if(mapa[lin][col] == INICIO) {
                                COR_AZUL
                                printf("☻");
                            }
                            else if(mapa[lin][col] == ANIMAL) {
                                COR_LARANJA
                                printf("♞");
                            } 
                        }
                        printf("\n");
                    }

                    // CASO NÃO TENHA UM ANIMAL E UM INICIO
                    if(erro == 1){
                        COR_VERMELHO
                        printf("\n\t[ERRO] É necessário um inicio e um animal!!!");
                        erro = 0;
                    }

                    // CASO NÃO EXISTA UM CAMINHO POSSIVEL
                    else if(erro == 2){
                        COR_VERMELHO
                        printf("\n\t[ERRO] Não há caminho para efetuar o resgate!");
                        erro = 0;
                    }

                    else if(erro == 0 && flag_controle == 1){
                        COR_LARANJA
                        printf("    (C: Caminho)(P: Parede)(I: Início)(A: Animal)(O: OK)");
                    }

                    // CAPTURA TECLA
                    jogada = getch();

                    // TECLA ESPECIAL
                    if(jogada == 27) {
                        jogada = getch(); 

                        if(jogada == 91) {      
                            jogada = getch();
                            
                            // CIMA
                            if(jogada == 65) {
                                if(px > 0) { // NÃO DEIXA O CURSOR SAIR DA MATRIZ
                                    px--;
                                }
                            }		
                            // BAIXO
                            else if(jogada == 66) {
                                    if(px < ALT-1) { 
                                    px++;
                                }
                            }
                            // DIREITA
                            else if(jogada == 67) {
                                if(py < LAR-1) { 
                                    py++;
                                }
                            }
                            // ESQUERDA
                            else if(jogada == 68) {
                                if(py > 0) { 
                                    py--;
                                }
                            }
                        }
                    }

                    // PAREDE 
                    else if(jogada == 'P' || jogada == 'p') {		
                        if(px != 0 && px != ALT-1 && py != 0 && py != LAR-1){ // NÃO DEIXA COLOCAR NAS BORDAS
                            if(mapa[px][py] == INICIO) { flag_inicio = 0; } // REINICIA A VARIAVEL 
                            else if(mapa[px][py] == ANIMAL) { flag_animal = 0; } // REINICIA A VARIAVEL 
                            mapa[px][py] = PAREDE;
                        }
                    }

                    // CAMINHO
                    else if(jogada == 'C' || jogada == 'c') {
                        if(px != 0 && px != ALT-1 && py != 0 && py != LAR-1){ 
                            if(mapa[px][py] == INICIO) { flag_inicio = 0; } 
                            else if(mapa[px][py] == ANIMAL) { flag_animal = 0; }  
                            mapa[px][py] = CAMINHO;
                        }			
                    }

                    // INICIO 
                    else if(jogada == 'I' || jogada == 'i' && flag_inicio == 0) {
                        if(px != 0 && px != ALT-1 && py != 0 && py != LAR-1){ 
                            if(mapa[px][py] == ANIMAL) { flag_animal = 0; } 
                            mapa[px][py] = INICIO; // INICIO COLOCADO NO MAPA
                            flag_inicio = 1; // INCREMENTA VARIAVEL PARA VERIFICAÇÃO
                        }
                    }

                    // ANIMAL 
                    else if(jogada == 'A' || jogada == 'a' && flag_animal == 0) {		
                        if(px != 0 && px != ALT-1 && py != 0 && py != LAR-1){ 
                            if(mapa[px][py] == INICIO) { flag_inicio = 0; } 
                            mapa[px][py] = ANIMAL; // ANIMAL COLOCADO NO MAPA
                            flag_animal = 1; // INCREMENTA VARIAVEL PARA VERIFICAÇÃO 
                        }	
                    }

                    // OK - SAIR
                    else if(jogada == 'O' || jogada == 'o') {

                        if(flag_animal != 1 || flag_inicio != 1) { erro = 1; } // VERIFICA SE EXISTE INICIO E ANIMAL

                        else{

                            final = 1;
                            flag_final = 1;
                            
                            // COPIANDO MAPA PARA MATRIZ ESPELHO
                            for(lin=0; lin<ALT; lin++){
                                for(col=0; col<LAR; col++){
                                    mapaEspelho[lin][col] = mapa[lin][col];
                                }
                            }

                            // VERIFICAÇÃO DE CAMINHO POSSÍVEL
                            while(flag_final == 1){

                                controle = 0;

                                for(lin=0; lin<ALT; lin++){
                                    for(col=0; col<LAR; col++){
                                        
                                        // VERIFICANDO POSIÇÃO DO INICIO
                                        if(mapaEspelho[lin][col] == INICIO){
                                            
                                            // VERIFICANDO SE ENCONTROU ANIMAL
                                            if(mapaEspelho[lin][col-1]==ANIMAL || mapaEspelho[lin][col+1]==ANIMAL || mapaEspelho[lin-1][col]==ANIMAL || mapaEspelho[lin+1][col]==ANIMAL){

                                                lin = ALT; // SAINDO DO FOR
                                                col = LAR; // SAINDO DO FOR
                                                controle = 2; // EXISTE CAMINHO POSSIVEL 
                                            }

                                            //BAIXO
                                            if(mapaEspelho[lin+1][col] == CAMINHO){ 
                                                mapaEspelho[lin+1][col] = INICIO; 
                                                controle = 1; 

                                            }

                                            //CIMA
                                            if(mapaEspelho[lin-1][col] == CAMINHO){ 
                                                mapaEspelho[lin-1][col] = INICIO; 
                                                controle = 1;
                                            }

                                            //DIREITA
                                            if(mapaEspelho[lin][col+1] == CAMINHO){ 
                                                mapaEspelho[lin][col+1] = INICIO; 
                                                controle = 1;
                                            }

                                            //ESQUERDA
                                            if(mapaEspelho[lin][col-1] == CAMINHO){ 
                                                mapaEspelho[lin][col-1] = INICIO;
                                                controle = 1;
                                            }
                                            
                                            mapaEspelho[lin][col] = TRILHA; // MARCA POR ONDE JA FOI PASSADO

                                        }
                                    }
                                }

                                // NÃO EXISTE CAMINHO POSSIVEL
                                if(controle == 0){
                                    erro = 2;
                                    final = 0;
                                    flag_final = 0;
                                }

                                // EXISTE CAMINHO POSSIVEL
                                else if(controle == 2){
                                    flag_final = 0;
                                }
                            }
                        }
                    }

                    flag_controle = 1; // INCREMENTA VARIAVEL PARA NÃO MOSTRAR MENU BUGADO EM CIMA DA MATRIZ

                }

                // SALVANDO O MAPA
                fp_bin = fopen("mapas.bin", "a+");
                fp_txt = fopen("mapas.txt", "a+");

                if(fp_bin != NULL){

                    system("clear");
                    COR_BRANCO
                    printf("\n\t=============================");
                    COR_VERDE
                    printf("\n\t\t  MAP SAVE");
                    COR_BRANCO
                    printf("\n\t=============================");
                    printf("\n\n\t- Digite um nome para salvar o mapa: ");
                    gets(nome_mapa);

                    // SALVANDO NOME DO MAPA EM UM ARQUIVO TXT
                    fputs(nome_mapa, fp_txt);
                    fputs("\n", fp_txt);

                    // SALVANDO O MAPA EM UM ARQUIVO BINÁRIO
                    for(lin=0; lin<ALT; lin++){
                        for(col=0; col<LAR; col++){
                            save.map[lin][col] = mapa[lin][col]; 
                        }
                    }
                    fwrite(save.map, sizeof(save_Map), 1, fp_bin);

                    COR_VERDE
                    printf("\n\t- [OK] O cenário [%s] foi salvo com sucesso", nome_mapa);
                    COR_BRANCO
                    __fpurge(stdin);
                    getchar();
                }

                fclose(fp_bin);
                fclose(fp_txt);

            break;

            // RESCUE GAME
            case 2:

                // ABRINDO ARQUIVOS DOS MAPAS
                fp_bin = fopen("mapas.bin", "a+");
                fp_txt = fopen("mapas.txt", "a+");

                // SELEÇÃO DE MAPA
                system("clear");
                COR_LARANJA
                printf("\t\t\tGAME RESCUE\n");
                COR_BRANCO
                printf("\n\t- Escolha um dos cenários a seguir:\n");

                // MOSTRANDO OS NOMES DOS MAPAS
                COR_VERDE
                while(fgets(nome_mapa, 100, fp_txt) != NULL){
                    printf("\t|| (%i) --> %s", linha, nome_mapa);
                    linha++;
                }

                linha = 1;

                COR_BRANCO
                printf("\t> ");
                scanf("%i", &op_mapa);

                // SELECIONA MAPA ESCOLHIDO PELO USUÁRIO
                for(cont = 0; cont < op_mapa; cont++){
                    fread(mapa, sizeof(save_Map), 1, fp_bin);
                }
                    
                fclose(fp_bin);
                fclose(fp_txt);

                COR_VERDE
                printf("\n\t[OK] Cenário carregado!");
                COR_BRANCO
                __fpurge(stdin);
                getchar();

                // SELEÇÃO MODO DE JOGO
                system("clear");
                COR_LARANJA
                printf("\t\t\tGAME RESCUE\n");
                COR_BRANCO
                printf("\n\t- Escolha uma das opções de jogo:");
                COR_VERDE
                printf("\n\t|| (1) --> Manual");
                COR_AZUL
                printf("\n\t|| (2) --> Automático");
                COR_BRANCO
                printf("\n\t> ");
                scanf("%i", &op_modoJogo);
                system("clear");

                timeIni = time(NULL); // INICIA CONTADOR

                switch(op_modoJogo) {

                    // MODO MANUAL
                    case 1:

                        // INICIA VARIAVEIS 
                        final = 0;
                        flag_controle = 0;
                        animation = 0;

                        while(final==0){

                            COR_LARANJA
                            system("clear");
                            printf("\t\t\tGAME RESCUE\n");
                            COR_BRANCO
                            for(lin=0; lin<ALT; lin++) {
                            //printf("");
                                for(col=0; col<LAR; col++) {

                                    if(mapa[lin][col] == INICIO && flag_init == 0){
                                        px = lin;
                                        py = col;
                                        flag_init = 1;
                                    }
                                    else if(lin == px && col == py) {
                                        COR_AZUL
                                        printf("☻");
                                    }
                                    else if(mapa[lin][col] == CAMINHO ) {
                                        COR_BRANCO
                                        printf(" ");
                                    }
                                    else if(mapa[lin][col] == PAREDE) {
                                        COR_BRANCO
                                        printf("#");
                                    }
                                    else if(mapa[lin][col] == INICIO) {
                                        COR_AZUL
                                        printf(" ");
                                    }
                                    else if(mapa[lin][col] == ANIMAL) {
                                        COR_LARANJA
                                        printf("♞");
                                    } 
                                }
                                printf("\n");
                            }

                            COR_BRANCO

                            // TIMER
                            if(flag_controle == 1){

                                timeTotal = timeFim - timeIni;
                                min = timeTotal/60;
                                seg = timeTotal%60;

                                if(seg < 10){
                                    if(min < 10){
                                        printf("[Tempo de Jogo: 0%i:0%i]", min, seg);
                                    }
                                    else{
                                        printf("[Tempo de Jogo: %i:0%i]", min, seg);
                                    }
                                }
                                else{
                                    if(min < 10){
                                        printf("[Tempo de Jogo: 0%i:%i]", min, seg);
                                    }
                                    else{
                                        printf("[Tempo de Jogo: %i:%i]", min, seg);
                                    }
                                }
                            }

                            // CAPTURA TECLA
                            jogada = getch();

                            // TECLA ESPECIAL
                            if(jogada == 27) {
                                jogada = getch(); 

                                if(jogada == 91) {      
                                    jogada = getch();
                            
                                    // CIMA
                                    if(jogada == 65) {
                                        if(px > 0 && mapa[px-1][py] != PAREDE) { // NÃO PERMITE ATRAVESSAR PAREDES
                                            px--;
                                        }
                                    }		
                                    // BAIXO
                                    else if(jogada == 66) {
                                            if(px < ALT-1 && mapa[px+1][py] != PAREDE) { // NÃO PERMITE ATRAVESSAR PAREDES
                                            px++;
                                        }
                                    }
                                    // DIREITA
                                    else if(jogada == 67) {
                                        if(py < LAR-1 && mapa[px][py+1] != PAREDE) { // NÃO PERMITE ATRAVESSAR PAREDES
                                            py++;
                                        }
                                    }
                                    // ESQUERDA
                                    else if(jogada == 68) {
                                        if(py > 0 && mapa[px][py-1] != PAREDE) { // NÃO PERMITE ATRAVESSAR PAREDES
                                            py--;
                                        }
                                    }
                                }
                            }

                            // VERIFICA SE ANIMAL FOI ALCANÇADO
                            if(mapa[px][py] == ANIMAL){
                                final = 1;
                                animation = 1;
                                flag_init = 0;
                            }

                            timeFim = time(NULL); // ATUALIZA CONTADOR
                            flag_controle = 1;
                            
                        }
                        
                    break;

                    // MODO AUTOMÁTICO
                    case 2:

                        timeIni = time(NULL); // INICIA CONTADOR

                        // INICIA VARIAVEIS
                        animation = 0;
                        final = 0;

                        while(final == 0){

                            fflush(stdout); 
                            usleep(250000); // TEMPO DE ANIMAÇÃO - SUSPENDE A EXECUÇÃO POR MICROSEGUNDOS
                            fflush(stdout); 

                            COR_LARANJA
                            system("clear"); 
                            printf("\t\t\tRESGATE AUTOMÁTICO\n");
                            COR_BRANCO

                            //IMPRIME O MAPA
                            for(lin=0; lin<ALT; lin++) {
                                for(col=0; col<LAR; col++) {

                                    if(mapa[lin][col] == CAMINHO || mapa[lin][col] == TRILHA ) {
                                        COR_BRANCO
                                        printf(" "); 
                                    }

                                    else if(mapa[lin][col] == PAREDE) {
                                        COR_BRANCO 
                                        printf("#"); 
                                    }
                                                        
                                    else if(mapa[lin][col] == ANIMAL) {
                                        COR_LARANJA 
                                        printf("♞"); 
                                    }

                                    else if (mapa[lin][col] == INICIO) {
                                        COR_AZUL 
                                        printf("☻"); 
                                    }
                                }
                                printf("\n");
                            }

                            // TIMER
                            timeTotal = timeFim - timeIni;
                            min = timeTotal/60;
                            seg = timeTotal%60;

                            if(seg < 10){
                                if(min < 10){
                                    printf("[Tempo de Jogo: 0%i:0%i]", min, seg);
                                }
                                else{
                                    printf("[Tempo de Jogo: %i:0%i]", min, seg);
                                }
                            }
                            else{
                                if(min < 10){
                                    printf("[Tempo de Jogo: 0%i:%i]", min, seg);
                                }
                                else{
                                    printf("[Tempo de Jogo: %i:%i]", min, seg);
                                }
                            }

                            // MOVIMENTANDO O PERSONAGEM
                            for(lin=0; lin<ALT; lin++){
                                for(col=0; col<LAR; col++){

                                    // VERIFICANDO POSIÇÃO DO INICIO
                                    if(mapa[lin][col] == INICIO){

                                        // BAIXO
                                        if(mapa[lin+1][col] == CAMINHO){ // COLOCA MOVIMENTO ONDE HÁ CAMINHO
                                            mapa[lin+1][col] = MOVIMENTO; 
                                            mapa[lin][col] = TRILHA; // COLOCA TRILHA NO LUGAR DO INÍCIO
                                        
                                        }
                                        else if (mapa[lin+1][col] == ANIMAL){
                                            mapa[lin][col] = TRILHA; 
                                            lin = ALT; // SAI DO LAÇO  FOR                        
                                            col = LAR; // SAI DO LAÇO FOR
                                            final = 1; // ACHOU O ANIMAL - SAI DO LAÇO WHILE
                                        }

                                        // CIMA
                                        if(mapa[lin-1][col] == CAMINHO){
                                            mapa[lin-1][col] = MOVIMENTO; 
                                            mapa[lin][col] = TRILHA; 
                                    
                                        }
                                        else if (mapa[lin-1][col] == ANIMAL){
                                            mapa[lin][col] = TRILHA; 
                                            lin = ALT;          
                                            col = LAR; 
                                            final = 1; 
                                        }

                                        // DIREITA
                                        if(mapa[lin][col+1] == CAMINHO){
                                            mapa[lin][col+1] = MOVIMENTO; 
                                            mapa[lin][col] = TRILHA;
                                    
                                        }
                                        else if (mapa[lin][col+1] == ANIMAL){
                                            mapa[lin][col] = TRILHA; 
                                            lin = ALT;              
                                            col = LAR; 
                                            final = 1; 
                                        }

                                        // ESQUERDA
                                        if(mapa[lin][col-1] == CAMINHO){
                                            mapa[lin][col-1] = MOVIMENTO; 
                                            mapa[lin][col] = TRILHA; 
                            
                                        }
                                        else if (mapa[lin][col-1] == ANIMAL){
                                            mapa[lin][col] = TRILHA; 
                                            lin = ALT;                        
                                            col = LAR; 
                                            final = 1; 
                                        }
                                    }
                                }
                            }

                            // TRANSFORMA O MOVIMENTO EM INICIO
                            for(lin=0; lin<ALT; lin++) {
                                for(col=0; col<LAR; col++) {
                                    if(mapa[lin][col]==MOVIMENTO){
                                        mapa[lin][col]=INICIO;
                                    }
                                }
                            }

                            animation = 1;
                            timeFim = time(NULL); // ATUALIZA CONTADOR
                        }

                    break;

                    // OPÇÃO INVALIDA
                    default:
                        COR_VERMELHO
                        printf("\n\t[ERRO]: Opção invalida!");
                        __fpurge(stdin);
                        getchar();
                        COR_BRANCO
                    break;
                }

            break;

            // OPÇÃO INVALIDA 
            default:
                COR_VERMELHO
                printf("\n\t[ERRO]: Opção invalida!");
                __fpurge(stdin);
                getchar();
                COR_BRANCO
            break;
        }

        // ANIMAÇÃO FINAL
        if(animation == 1){

            animation = 0;

            for(a=0; a<10; a++){

                fflush(stdout); 
		        usleep(500000); // TEMPO DE ANIMAÇÃO - SUSPENDE A EXECUÇÃO POR MICROSEGUNDOS
		        fflush(stdout);

                system("clear");
                //IMPRIME O MAPA
                for(lin=0; lin<ALT; lin++) {
                    for(col=0; col<LAR; col++) {

                        if(mapa[lin][col] == CAMINHO || mapa[lin][col] == TRILHA ) {
                            COR_BRANCO
                            printf(" "); 
                        }

                        else if(mapa[lin][col] == PAREDE) {
                            if(a % 2 == 0){ // MUDA A COR DAS PAREDES
                                COR_LARANJA
                                printf("#"); 
                            }
                            else{
                                COR_AGUA
                                printf("#");
                            }
                        }
                                                            
                        else if(mapa[lin][col] == ANIMAL) {
                            if(a % 2 == 0){ // ALTERNA ENTRE ANIMAL E INICIO 
                                COR_AZUL 
                                printf("♞");
                            }
                            else{
                                COR_LARANJA
                                printf("☻"); 
                            }
                            
                        }

                        else if (mapa[lin][col] == INICIO) {
                            COR_AZUL 
                            printf(" "); 
                        }
                    }
                    printf("\n");
                }

                COR_VERDE
                printf("\n\nPARABENS! RESGATE CONCLUÍDO COM SUCESSO ");
                COR_VERMELHO

                // IMPRIME TIMER
                if(seg < 10){
                    if(min < 10){
                        printf("[Tempo de Jogo: 0%i:0%i]", min, seg);
                    }
                    else{
                        printf("[Tempo de Jogo: %i:0%i]", min, seg);
                    }
                }
                else{
                    if(min < 10){
                        printf("[Tempo de Jogo: 0%i:%i]", min, seg);
                    }
                    else{
                        printf("[Tempo de Jogo: %i:%i]", min, seg);
                    }
                }  
            }

            __fpurge(stdin);
            getchar();

            flag_controle = 0;

            // MENU FINAL
            while(flag_controle == 0){

                system("clear");
                COR_BRANCO
                printf("\n\tDeseja continuar jogando? ");
                COR_VERDE
                printf("\n\t(1) - Sim");
                COR_VERMELHO
                printf("\n\t(2) - Não");
                COR_BRANCO
                printf("\n\t> ");
                scanf("%i", &op_fim);

                switch(op_fim) {

                // SIM
                case 1:
                    fim = 0;
                    flag_controle = 1;
                break;

                // NÃO
                case 2:
                    fim = 1;
                    flag_controle = 1;
                break;

                // OPÇÃO INVALIDA 
                default:
                    COR_VERMELHO
                    printf("\n\t[ERRO]: Opção invalida!");
                    __fpurge(stdin);
                    getchar();
                    COR_BRANCO
                break;
                }
            }
        }
    }

    printf("\n\n");
    return 0;

}
