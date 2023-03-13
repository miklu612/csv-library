#include"csv_row.h"

#include<string.h>


int main(void) {

    char* names[4] = {
        "Mikael", 
        "Mike",
        "Micheal",
        "Michelangelo"
    };

    CsvRow row;
    if(CsvRow_init(&row) == false)
        return -1;

    for(size_t i = 0 ; i < 4 ; i++) {

        const bool status = CsvRow_push(&row, names[i]);

        if(status == false) {
            CsvRow_free(&row);
            return -1;
        }

    }

    if(row.column_count != 4) {
        CsvRow_free(&row);
        return -1;
    }

    for(size_t i = 0 ; i < 4 ; i++) {
        if(strcmp(row.columns[i], names[i]) != 0) {
            CsvRow_free(&row);
            return -1;
        }
    }


    CsvRow_free(&row);
    

    return 0;

}
