#include"csv_row.h"



int main(void) {

    CsvRow row;
    CsvRow_init(&row);

    const size_t previous = row.column_count;
    CsvRow_push(&row, "Hello, World!\0");
    const size_t now = row.column_count;

    CsvRow_free(&row);

    if(previous != now)
        return 0;
    else 
        return -1;

}
