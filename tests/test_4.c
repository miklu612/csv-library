#include"csv.h"


int main(void) {

    Csv csv;
    if(Csv_init(&csv) == false)
        return -1;
    Csv_free(&csv);

    return 0;

}
