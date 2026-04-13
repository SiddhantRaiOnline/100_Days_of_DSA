#include <stdbool.h>

void dfs(int** rooms, int* roomsColSize, int room, bool* visited) {
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(rooms, roomsColSize, key, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];

    for (int i = 0; i < roomsSize; i++)
        visited[i] = false;

    dfs(rooms, roomsColSize, 0, visited);

    // Check if all rooms visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i])
            return false;
    }

    return true;
}