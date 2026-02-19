#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    int rows;
    char empty;
    char obstacle;
    char full;
    char **grid;
    int cols;
} Map;

typedef struct {
    int row, col, size;
} Square;

int ft_strlen(char *str) {
    int i = 0;
    while (str[i])
        i++;
    return i;
}

char *ft_strdup(char *src) {
    int len = ft_strlen(src);
    char *dup = malloc(len + 1);
    if (!dup)
        return NULL;
    int i = 0;
    while (src[i]) {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}

void print_error() {
    write(2, "map error\n", 10);
}

int parse_header(FILE *fp, Map *map) {
    if (fscanf(fp, "%d %c %c %c\n", &map->rows, &map->empty, 
               &map->obstacle, &map->full) != 4)
        return 0;
    
    if (map->rows <= 0 || map->empty == map->obstacle || 
        map->empty == map->full || map->obstacle == map->full)
        return 0;
    
    return 1;
}

int read_map(FILE *fp, Map *map) {
    char *line = NULL;
    size_t len = 0;
    
    // Read and parse header
    if (!parse_header(fp, map)) {
        return 0;
    }
    
    // Allocate grid
    map->grid = malloc(sizeof(char*) * map->rows);
    if (!map->grid)
        return 0;
    
    map->cols = 0;
    
    // Read all rows
    for (int i = 0; i < map->rows; i++) {
        ssize_t read = getline(&line, &len, fp);
        if (read == -1) {
            free(line);
            return 0;
        }
        
        // Remove newline
        if (read > 0 && line[read-1] == '\n')
            line[read-1] = '\0';
        else {
            free(line);
            return 0;
        }
        
        int curr_len = ft_strlen(line);
        
        // Check column consistency
        if (i == 0) {
            map->cols = curr_len;
            if (map->cols == 0) {
                free(line);
                return 0;
            }
        } else if (curr_len != map->cols) {
            free(line);
            return 0;
        }
        
        // Validate characters
        for (int j = 0; j < map->cols; j++) {
            if (line[j] != map->empty && line[j] != map->obstacle) {
                free(line);
                return 0;
            }
        }
        
        map->grid[i] = ft_strdup(line);
    }
    
    free(line);
    return 1;
}

int can_place_square(Map *map, int row, int col, int size) {
    if (row + size > map->rows || col + size > map->cols)
        return 0;
    
    for (int i = row; i < row + size; i++) {
        for (int j = col; j < col + size; j++) {
            if (map->grid[i][j] == map->obstacle)
                return 0;
        }
    }
    return 1;
}

Square find_biggest_square(Map *map) {
    Square best = {0, 0, 0};
    
    // Try all positions, prioritizing top-left
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            // Try increasing square sizes from this position
            int max_size = (map->rows - i < map->cols - j) ? 
                           map->rows - i : map->cols - j;
            
            for (int size = best.size + 1; size <= max_size; size++) {
                if (can_place_square(map, i, j, size)) {
                    best.row = i;
                    best.col = j;
                    best.size = size;
                }
            }
        }
    }
    
    return best;
}

void fill_square(Map *map, Square sq) {
    for (int i = sq.row; i < sq.row + sq.size; i++) {
        for (int j = sq.col; j < sq.col + sq.size; j++) {
            map->grid[i][j] = map->full;
        }
    }
}

void print_map(Map *map) {
    for (int i = 0; i < map->rows; i++) {
        fprintf(stdout, "%s\n", map->grid[i]);
    }
}

void free_map(Map *map) {
    if (map->grid) {
        for (int i = 0; i < map->rows; i++) {
            if (map->grid[i])
                free(map->grid[i]);
        }
        free(map->grid);
    }
}

void process_file(FILE *fp) {
    Map map = {0};
    
    if (!read_map(fp, &map)) {
        print_error();
        free_map(&map);
        return;
    }
    
    Square best = find_biggest_square(&map);
    fill_square(&map, best);
    print_map(&map);
    
    free_map(&map);
}

int main(int argc, char **argv) {
    if (argc == 1) {
        // Read from stdin
        process_file(stdin);
    } else {
        // Process each file
        for (int i = 1; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r");
            if (!fp) {
                print_error();
                continue;
            }
            process_file(fp);
            fclose(fp);
        }
    }
    
    return 0;
}