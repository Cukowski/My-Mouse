#include "my_mouse.h"

bool is_safe(const Maze *maze, int row, int col) 
{
    return row >= 0 && row < maze->rows && col >= 0 && col < maze->cols && maze->maze[row][col] != maze->full_char;
}

void explore_neighbors(Maze *maze, Point curr, Point *queue, bool visited[MAX_ROWS][MAX_COLS], Point parent[maze->rows][maze->cols], int *rear) 
{
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    for (int i = 0; i < 4; ++i) 
    {
        int new_row = curr.row + dx[i];
        int new_col = curr.col + dy[i];
        if (is_safe(maze, new_row, new_col) && !visited[new_row][new_col]) 
        {
            queue[(*rear)++] = (Point){new_row, new_col, curr.distance + 1};
            visited[new_row][new_col] = true;
            parent[new_row][new_col] = curr;
        }
    }
}

void backtrack_path(Maze maze, Point start, Point curr, Point *path, int *path_size, Point parent[maze.rows][maze.cols]) 
{
    int idx = 0;
    while (!(curr.row == start.row && curr.col == start.col)) 
    {
        path[idx++] = curr;
        curr = parent[curr.row][curr.col];
    }
    path[idx++] = start;
    *path_size = idx;
}

int find_shortest_path(Maze *maze, Point start, Point end, Point *path, int *path_size) 
{
    // Create a queue for BFS
    Point queue[maze->rows * maze->cols];
    bool visited[MAX_ROWS][MAX_COLS] = {false};
    Point parent[maze->rows][maze->cols];
    
    // Initialize queue
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start.row][start.col] = true;
    
    while (front < rear) {
        Point curr = queue[front++];
        if (curr.row == end.row && curr.col == end.col) // Destination reached, Backtrack to find the shortest path
        {
            backtrack_path(*maze, start, curr, path, path_size, parent);
            return parent[end.row][end.col].distance; // Return the distance from the start to the end
        }
        explore_neighbors(maze, curr, queue, visited, parent, &rear);
    }
    return -1; // No path found
}
