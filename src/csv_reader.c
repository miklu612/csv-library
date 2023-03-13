#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "csv_reader.h"
#include "csv.h"
#include "csv_row.h"


char* read_file(char* path) {

    FILE* fp = fopen(path, "r");
    if(fp == NULL) return NULL;


    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    char* text = malloc((size+1)*sizeof(char));
    if(text == NULL) {
        fclose(fp);
        return NULL;
    }

    memset(text, '\0', (size+1)*sizeof(char));
    fread(text, size, sizeof(char), fp);


    fclose(fp);
    return text;

}


bool CsvReader_load(Csv* csv, char* path) {

    (void) csv;
    (void) path;


    char* text = read_file(path);
    if(text == NULL) return false;

    //printf("%s\n", text);

    // TODO: Make this dynamic
#define size 1024
    char current_value[size] = { 0 };
    size_t v_index = 0;
    memset(current_value, '\0', size);

    CsvRow row;
    CsvRow_init(&row);

    for(size_t i = 0 ; i < strlen(text) ; i++) {
        if(text[i] == ';' || text[i] == '\n' || i + 1 >= strlen(text)) { 

            CsvRow_push(&row, current_value);
            v_index = 0;
            memset(current_value, '\0', size);


            if(text[i] == '\n') {
                Csv_push(csv, CsvRow_clone(&row));
                CsvRow_free(&row);
                CsvRow_init(&row);
            }
        }
        else {
            current_value[v_index] = text[i];
            v_index++;
        }
    }

 
    CsvRow_free(&row);

    free(text);

    return true;


}




