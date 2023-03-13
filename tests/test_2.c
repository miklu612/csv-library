#include"csv_row.h"


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
    
    const size_t column_count = row.column_count;
    CsvRow_free(&row);


    if(column_count != 4)
        return -1;
    else
        return 0;

}
