#include <stdio.h>

void addContent(char *dest, char *src)
{
    FILE *srcFile, *destFile;
    char ctr;
    srcFile=fopen(src, "r");
    destFile=fopen(dest, "a");
    while((ctr=fgetc(srcFile))!=EOF)
    {
        fprintf(destFile,"%c",ctr);
    }
    fclose(srcFile);
    fclose(destFile);

}

int main()
{
    addContent("cel.txt", "zrodlo.txt");
    return 0;
}