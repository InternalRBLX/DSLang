#include "../include/util.h"

char* read_ascii_file(const char* path) {
    // Create A File
    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Could not open file '%s'\n", path);
        return NULL;
    };

    // Get File Size
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Read File
    char* buf = (char*) malloc(sizeof(char) * (size + 1));
    if (!buf) {
        printf("Could not allocate memory for file!\n");
        return NULL;
    };

    fread(buf, 1, size, file);
    buf[size] = '\0';
    fclose(file);

    // Return Buffer
    return buf;
}