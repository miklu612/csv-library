#include"csv.h"





int main(void) {

    char* cities[] = {
        "Berlin",
        "London", 
        "Paris", 
        "Barcelona",
        "Helsinki",
        "Stockholm",
    };
    const size_t cities_size = sizeof(cities) / sizeof(cities[0]);

    char* countries[] = {
        "Germany",
        "Great Britain", 
        "France", 
        "Spain",
        "Finland",
        "Sweden",
    };
    const size_t countries_size = sizeof(cities) / sizeof(cities[0]);

    if(cities_size != countries_size) {
        printf("Value sizes don't match\n");
        return -1;
    }

    Csv csv;
    if(Csv_init(&csv) == false) {
        return -1;
    }

    for(size_t i = 0 ; i < cities_size ; i++) {
        CsvRow row;

        if(!CsvRow_init(&row))
            goto exit_program_fail;

        bool status = true;
        status = status && CsvRow_push(&row, cities[i]);
        status = status && CsvRow_push(&row, countries[i]);
        Csv_push(&csv, row);
        //CsvRow_free(&row);

        if(status == false)
            goto exit_program_fail;


    }


    Csv_free(&csv);

    return 0;

exit_program_fail:
    Csv_free(&csv);
    return -1;

}
