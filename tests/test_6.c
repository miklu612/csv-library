#include"csv.h"
#include"csv_reader.h"



int main(void) {


    Csv csv;
    Csv_init(&csv);

    if(!CsvReader_load(&csv, "csvs/test_csv_1.csv")) {
        Csv_free(&csv);
        return -1;
    }

    printf("Amount of rows %zu\n", csv.row_count);
    for(size_t i = 0 ; i < csv.row_count ; i++) {
        const CsvRow* row = &csv.rows[i];
        for(size_t j = 0 ; j < row->column_count ; j++) {
            printf("%s;", row->columns[j]);
        }
        printf("\n");
    }

    Csv_free(&csv);
    

    return 0;

}

