#include <stdio.h>
int main(){
FILE *file = fopen("example.txt", "a");
if (file== NULL) {
printf("Error opening file for writing.\n");
return 1; }
//fseek(file,0,SEEK_SET);
fprintf(file, "===Hello World Appended=== \n");
fclose(file);
printf("Data written to file successfully!\n");
return 0; }
