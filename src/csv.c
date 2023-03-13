#include"csv.h"
#include"csv_row.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool Csv_init(Csv* csv) {

    if(csv == NULL)
        return false;

    csv->row_count = 0;

    csv->rows = malloc(1 * sizeof(CsvRow));
    if(csv->rows == NULL)
        return false;

    return true;

}


bool Csv_push(Csv* csv, CsvRow value) {

    if(csv == NULL)
        return false;


    csv->row_count += 1;

    const size_t size = csv->row_count * sizeof(CsvRow);
    csv->rows = realloc(csv->rows, size);

    if(csv->rows == NULL)
        return false;

    const size_t index = csv->row_count - 1;
    csv->rows[index] = value;


    return true;

}

void Csv_free(Csv* csv) {

    if(csv == NULL)
        return;

    for(size_t i = 0 ; i < csv->row_count ; i++) {
        CsvRow_free(&csv->rows[i]);
    }
    free(csv->rows);
}
