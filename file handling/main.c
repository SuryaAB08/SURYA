#include <stdio.h>
int main(){
FILE *file = fopen("example.txt", "w");

if (file== NULL) {
        printf("Error opening file for writing.\n");
return 1;
}
fprintf(file, "Hello, world!\n");
fprintf(file, "This is a simple file handling example in C.\n");


fclose(file);

printf("Data written to file successfully!\n");

return 0;
}

