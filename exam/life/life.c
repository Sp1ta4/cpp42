#include "life.h"

int main(int argc, char **argv){
	if (argc != 4)
		return 1;

	t_game game;

	if (init_game(&game, argv))
		return 2;
	fill_board(&game);
	for (int i = 0; i < game.iterations; ++i)
		play(&game);
	print_board(&game);
	free_board(&game);
	
	return 0;
}

void play(t_game* game) {
	char **new_board = (char **)malloc(sizeof(char*) * game->height);
	for (int i = 0; i < game->height; ++i)
		new_board[i] = (char *) malloc(sizeof(char) * game->width);
	
	for (int y = 0; y < game->height; ++y) {
		for (int x = 0; x < game->width; ++x) {
		int nbc = count_nb(game, y, x);
			if (game->board[y][x] == '0')
			{
				if (nbc == 2 || nbc == 3)
					new_board[y][x] = '0';
				else
					new_board[y][x] = ' ';
			}
			else
			{
				if (nbc == 3)
					new_board[y][x] = '0';
				else
					new_board[y][x] = ' ';
			}
		}
	}	
	free_board(game);
	game->board = new_board;
}

int init_game(t_game* game, char *argv[]) {
	game->width = atoi(argv[1]);
	game->height = atoi(argv[2]);
	game->iterations = atoi(argv[3]);

	if (game->width <= 0 || game->height <= 0 || game->iterations < 0)
    	return 1;
	game->board = (char **)malloc(sizeof(char *) * game->height);
	if (!game->board)
		return 2;
	for (int i = 0; i < game->height; i++)
    {
		game->board[i] = malloc((game->width) * sizeof(char));
		if (!game->board[i])
    	{
        	while (--i >= 0)
            	free(game->board[i]);
        	free(game->board);
        	game->board = NULL;
			return 3;
    	}
		for (int x = 0; x < game->width; ++x)
			game->board[i][x] = ' ';
	}	 

	return 0;
}

void free_board(t_game *game) {
	if (!game->board)
		return ;
	for (int i = 0; i < game->height; i++)
    {
		if(game->board[i])
			free(game->board[i]);
	}
	free(game->board);
	game->board = NULL;
}

void print_board(t_game* game) {
	for (int i = 0; i < game->height; i++)
	{
		for (int j = 0; j < game->width; j++)
		{
			putchar(game->board[i][j]);
		}
		putchar('\n');
	}
}

void fill_board(t_game *game) {
	char buffer;
	int x = 0;
	int y = 0;
	bool draw = false;

	while (read(0, &buffer, 1) == 1)
	{
		switch(buffer)
		{	
			case('w'): if (y > 0) {--y;}; break;
			case('a'): if (x > 0) {--x;}; break;
			case('s'): if (y < game->height - 1) {++y;}; break;
			case('d'): if (x < game->width - 1) {++x;}; break;
			case('x'): draw = !draw; break;
			default: continue;
		}
		
		if (draw && x >= 0 && x < game->width && y >= 0 && y < game->height)
			game->board[y][x] = '0';
	}
}

int count_nb(t_game *game, int y, int x) {
	int count = 0;

	for(int dy = -1; dy < 2; ++dy) {
		for(int dx = -1; dx < 2; ++dx){
			if (dx == 0 && dy == 0)
				continue;
			int ny = y + dy;
			int nx = x + dx;
			if (ny >= 0 && ny < game->height && nx >= 0 && nx < game->width && game->board[ny][nx] == '0')
				count++;
		}

	}

	return count;

}

