#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

Playlist *criarPlaylist(){
    Musica *cabeca = (Musica *)malloc(sizeof(Musica));
    if(cabeca == NULL){
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    cabeca->proximo = cabeca;
    cabeca->anterior = cabeca;

    Playlist *playlist = (Playlist *)malloc(sizeof(Playlist));
    if(playlist == NULL){
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    playlist->tamanho = 0;
    playlist->cabeca = cabeca;
    playlist->musicaAtual = cabeca;

    return playlist;
}

void apagaPlaylist(Playlist *playlist){
    Musica *temp = playlist->cabeca->proximo;
    Musica *excluir = temp;
    while(temp != playlist->cabeca){
        temp = temp->proximo;
        free(excluir);
        excluir = temp;
    }
    free(playlist->cabeca);
    free(playlist);
}

void visualizarPlaylist(Playlist *playlist){
    printf("------------------\n");
    printf("Playlist:\n");
    Musica *p;
    for(p=playlist->cabeca->proximo; p != playlist->cabeca; p=p->proximo){
        printf("%s, %s\n", p->titulo, p->artista);
    }
    printf("------------------\n");
}

int tamanhoPlaylist(Playlist *playlist){
    return playlist->tamanho;
}

Musica *criarMusica(){
    Musica *musica = (Musica *)malloc(sizeof(Musica));
    if(musica == NULL){
        printf("Erro ao alocar memoria\n");
        return NULL;
    }

    printf("Digite o titulo da musica: ");
    fgets(musica->titulo, MAX_CARACTER, stdin);
    musica->titulo[strcspn(musica->titulo, "\n")] = '\0'; 

    printf("Digite o nome do artista: ");
    fgets(musica->artista, MAX_CARACTER, stdin);
    musica->artista[strcspn(musica->artista, "\n")] = '\0'; 

    return musica;
}

void adicionaMusicaFim(Playlist *playlist){
    Musica* novaMusica = criarMusica();
    if(novaMusica == NULL){
        printf("Erro ao alocar memoria\n");
        return;
    }

    Musica* musicaAntiga = playlist->cabeca->anterior;

    novaMusica->proximo = musicaAntiga->proximo; //mesma coisa de apontar diretamente pra cabeça
    novaMusica->anterior = musicaAntiga;

    musicaAntiga->proximo = novaMusica;

    playlist->cabeca->anterior = novaMusica;
    if(playlist->tamanho == 0){
        playlist->musicaAtual = playlist->cabeca->proximo;
    }
    playlist->tamanho++;
}

void adicionaMusicaInicio(Playlist *playlist){
    Musica *novaMusica = criarMusica();

    Musica* musicaAntiga = playlist->cabeca->proximo;

    novaMusica->anterior = musicaAntiga->anterior;
    novaMusica->proximo = musicaAntiga;

    musicaAntiga ->anterior = novaMusica;

    playlist->cabeca->proximo = novaMusica;
    if(playlist->tamanho == 0){
        playlist->musicaAtual = playlist->cabeca->proximo;
    }
    playlist->tamanho++;
}

BOOL removerMusicaFim(Playlist *playlist){
    if(playlist->tamanho > 0){
        Musica *novoFim = playlist->cabeca->anterior->anterior;
        novoFim->proximo = playlist->cabeca;

        if(playlist->cabeca->anterior == playlist->musicaAtual){
            tocarProximaMusica(playlist);
        }
        
        free(playlist->cabeca->anterior);
        playlist->cabeca->anterior = novoFim;
        playlist->tamanho--;
        return TRUE;
    } else{
        printf("Playlist ja esta vazia\n");
        return FALSE;
    }
}


BOOL removerMusicaInicio(Playlist *playlist){
    if(playlist->tamanho > 0){
        Musica *novoInicio = playlist->cabeca->proximo->proximo;
        novoInicio->anterior = playlist->cabeca;

        if(playlist->cabeca->proximo == playlist->musicaAtual){
            tocarProximaMusica(playlist);
        }

        free(playlist->cabeca->proximo);
        playlist->cabeca->proximo = novoInicio;
        playlist->tamanho--;
        return TRUE;
    }else{
        printf("Playlist ja esta vazia\n");
        return FALSE;
    }
}

void tocarProximaMusica(Playlist *playlist){
    if(playlist->tamanho>0){
        playlist->musicaAtual = playlist->musicaAtual->proximo;
        if(playlist->musicaAtual == playlist->cabeca){
            playlist->musicaAtual = playlist->musicaAtual->proximo;
        }
    }else{
        return;
    }
}

void tocarMusicaAnterior(Playlist *playlist){
    if(playlist->tamanho>1){
        playlist->musicaAtual = playlist->musicaAtual->anterior;
        if(playlist->musicaAtual == playlist->cabeca){
            playlist->musicaAtual = playlist->musicaAtual->anterior;
        }
    }else{
        return;
    }
}

void tocandoAgora(Playlist *playlist){
    printf("------------------\n");
    printf("tocando %s de %s...\n", playlist->musicaAtual->titulo,playlist->musicaAtual->artista);
    printf("------------------\n");
}