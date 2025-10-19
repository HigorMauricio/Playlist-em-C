#ifndef PLAYLIST_H
#define PLAYLIST_H
#define MAX_CARACTER 100
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct Musica {
    char titulo[MAX_CARACTER];
    char artista[MAX_CARACTER];

    struct Musica *proximo;
    struct Musica *anterior;
} Musica;

typedef struct {
    int tamanho;
    Musica *musicaAtual;
    Musica *cabeca;
} Playlist;

Playlist *criarPlaylist();
void apagaPlaylist(Playlist *playlist);
void visualizarPlaylist(Playlist *playlist);
Musica *criarMusica();
void adicionaMusicaFim(Playlist *playlist);
void adicionaMusicaInicio(Playlist *playlist);
int tamanhoPlaylist(Playlist *playlist);
BOOL removerMusicaFim(Playlist *playlist);
BOOL removerMusicaInicio(Playlist *playlist);
void tocarProximaMusica(Playlist *playlist);
void tocarMusicaAnterior(Playlist *playlist);
void tocandoAgora(Playlist *playlist);
#endif