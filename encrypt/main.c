#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    char buff[1024];
    char filename[256];
    char command[1024];
    
    char *key;
    int n, i, key_len;
    int fd, fd2;
    
    if (argc < 2) {
        printf("Please list a file to encrypt.\n");
        exit(0);
    }
    
    strncpy(filename, argv[1], 256 - strlen(".encrypt"));
    strcat(filename, ".encrypt");
    
    if (argc < 3) {
        write(1, "Enter an encryption key: ", 25);
        while((n = read(0, buff, 257)) == 0)
            printf("Try again.\n");
        
        buff[n-1] = '\0';
        key = strdup(buff);
    } else
        key = strdup(argv[2]);
        
    key_len = strlen(key);

    if ((fd = open(argv[1], O_RDONLY)) < 0)
        printf("Error: file not found.\n");
        
    fd2 = open(filename, O_WRONLY | O_CREAT);
    
    while ((n = read(fd, buff, 1024)) > 0) {
        for (i = 0; i < n; i++)
            buff[i] ^= key[i % key_len];
            
        write(fd2, buff, n);
    }
    
    close(fd);
    close(fd2);
    
    // chmod the file
    chmod(filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    
    // now move the encypted file to the original
    strcpy(command, "mv ");
    strcat(command, filename);
    strcat(command, " ");
    strcat(command, argv[1]);
    
    system(command);
}