void visitRooms(int key, int** rooms, int roomsSize, int* roomsColSize, int* visitedRooms){
    if (visitedRooms[key] == 1){
        return;
    }

    visitedRooms[key] = 1;
    for (int i = 0; i < roomsColSize[key]; i++){
        visitRooms(rooms[key][i], rooms, roomsSize, roomsColSize, visitedRooms);
    }
}

// Depth-first search
// Runtime: O(n)
// Space: O(n)
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    int* visitedRooms = calloc(roomsSize, sizeof(int));
    visitRooms(0, rooms, roomsSize, roomsColSize, visitedRooms);

    int visitedRoomsNumber = 0;
    for (int i = 0; i < roomsSize; i++){
        if (visitedRooms[i] == 1){
            visitedRoomsNumber++;
        }
    }

    return visitedRoomsNumber == roomsSize;
}
