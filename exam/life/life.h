#ifndef LIFE_H
#define LIFE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct s_game {
	int width;
	int height;
	int iterations;

	char** board;
} t_game;

int init_game(t_game* game, char* argv[]);
void fill_board(t_game* game);
void play(t_game* game);
void print_board(t_game* game);
void free_board(t_game* game);
int count_nb(t_game *game, int y, int x);

#endif
