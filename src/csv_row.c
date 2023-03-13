#include "csv_row.h"

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool CsvRow_init(CsvRow* csv_row) {

    if(csv_row == NULL)
        return false;

    csv_row->column_count = 0;

    csv_row->columns = malloc(1 * sizeof(char*));

    if(csv_row == NULL)
        return false;
    return true;

}


bool CsvRow_push(CsvRow* csv_row, char* value) {

    if(csv_row == NULL)
        return false;
    if(value == NULL)
        return false;



    csv_row->column_count += 1;
    const size_t column_size = csv_row->column_count * sizeof(char*);
    csv_row->columns = realloc(csv_row->columns, column_size);

    if(csv_row == NULL)
        return false;

    const size_t index = csv_row->column_count - 1;
    const size_t size = (strlen(value) + 1) * sizeof(char);

    csv_row->columns[index] = malloc(size);
    memset(csv_row->columns[index], '\0', size);
    memcpy(csv_row->columns[index], value, size);


    return true;

}


void CsvRow_free(CsvRow* csv_row) {

    if(csv_row == NULL)
        return;

    for(size_t i = 0 ; i < csv_row->column_count ; i++) {
        free(csv_row->columns[i]);
    }
    free(csv_row->columns);

    csv_row->columns = NULL;
    csv_row->column_count = 0;

}

CsvRow CsvRow_clone(CsvRow* csv_row) {
   
    CsvRow output;
    
    output.column_count = csv_row->column_count;
    output.columns = malloc(csv_row->column_count * sizeof(char*));
    
    for(size_t i = 0 ; i < csv_row->column_count ; i++) {
        
        const size_t size = (strlen(csv_row->columns[i]));
        output.columns[i] = malloc(size+1);
        memset(output.columns[i], '\0', size+1);
        memcpy(output.columns[i], csv_row->columns[i], size);

    }

    return output;

}
