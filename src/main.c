#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

void menu(){
    printf("Aqui estao as funcionalidades disponiveis:\n");
    printf("1 Adicionar muscia ao fim da playlist\n");
    printf("2 Adicionar musica ao inicio da playlist\n");
    printf("3 Remover musica do fim da playlist\n");
    printf("4 Remover musica do inicio da playlist\n");
    printf("5 Visualizar playlist\n");
    printf("6 Tocando agora\n");
    printf("7 Passar para proxima musica\n");
    printf("8 Voltar para musica anterior\n");
}

int main(){
    printf("VOCE ESTA NO PLAYER DE MUSICAS\n");
    printf("PARA SAIR DIGITE 0\n");
    int opcao;
    Playlist *playlist = criarPlaylist();
    if(playlist == NULL){
        return 1;
    } 
    do{
        menu();
        printf("opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao){
        case 0:
            break;
        case 1:
            if(playlist->tamanho == 0){
                adicionaMusicaFim(playlist);
                printf("------------------\n");
                printf("tocando %s de %s...\n", playlist->cabeca->proximo->titulo, playlist->cabeca->proximo->artista);
                printf("------------------\n");
                break;
            }else{
                adicionaMusicaFim(playlist);
                break;
            }
        case 2:
            if(playlist->tamanho==0){
                adicionaMusicaInicio(playlist);
                tocandoAgora(playlist);
                break;
            }else{
                adicionaMusicaInicio(playlist);
                break;
            }
        case 3:
            if(removerMusicaFim(playlist)){
                printf("Ultima musica removida da fila\n");
                if(playlist->tamanho==0){
                    printf("------------------\n");
                    printf("Nada tocando...\n");
                    printf("------------------\n");
                    break;
                }else{
                    break;
                }
            }else{
                break;
            }
        case 4:
            if(removerMusicaInicio(playlist)){
                printf("Proxima musica removida da fila\n");
                if(playlist->tamanho == 0){
                    printf("------------------\n");
                    printf("Nada tocando...\n");
                    printf("------------------\n");
                    break;
                }else{
                    break;
                }
            }else{
                break;
            }
        case 5:
            visualizarPlaylist(playlist);
            break;
        case 6:
            if(playlist->tamanho > 0){
                tocandoAgora(playlist);
                break;
            }
        case 7:
            if(playlist->tamanho > 0){
                tocarProximaMusica(playlist);
                tocandoAgora(playlist);
                break;
            }
        case 8:
            if(playlist->tamanho > 0){
                tocarMusicaAnterior(playlist);
                tocandoAgora(playlist);
                break;
            }
        default:
            printf("Opcao Invalida!\n");
            break;
        }
    }while(opcao != 0);
    return 0;
}
