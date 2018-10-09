#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMC 20 /* Define quantas pessoas terao no arquivo de carga*/

int main(int argc, char** argv){
    if(argc!=2){
        printf("Erro na inicializacao. Eh necessario escrever o nome do arquivo executavel seguido do nome arquivo de carga");
    }
    else{
        int i, tempo_inicio=1, tempo_adicional, servico, idade, condicao; 
        FILE* arquivo;

        arquivo = fopen(argv[1],"w");
        srand(time(NULL));

        for(i=0; i<NUMC; i++){
            /*Esse if e else eh uma maneira bem simples de gerar um pico de chegada de cliente*/
            if(i>(NUMC/3) && i<(2*NUMC/3)) tempo_adicional = rand()%3;
            else tempo_adicional = rand()%5;
            tempo_inicio += tempo_adicional;
            idade = (15 + rand()%75);
            condicao = rand()%3;
            servico = rand()%5;

            fprintf(arquivo,"%d %d %d %d\n", tempo_inicio, idade, servico, condicao);
        }
        
        fclose(arquivo);
    }
    return 0;
}