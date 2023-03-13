#ifndef csv_h
#define csv_h

#include"csv_row.h"

#include<stdio.h>



typedef struct {
    CsvRow* rows;
    size_t row_count;
} Csv;

/*
 
    Description:
        Csv_init initializes the Csv struct for usage for 
        the rest of the functions.

    Arguments:
        Csv* csv:
            The Csv struct that you want to initialize.

    Returns:
        False:
            The Csv struct couldn't be initialized. Don't
            use the Csv struct if this returns false, since
            the memory that is needed for it couldn't be 
            allocated

        True:
            The Csv struct was initialized and is ready 
            for use

*/
bool Csv_init(Csv* csv);

/*

    Description:
        Csv_push pushes a new CsvRow struct into the 
        Csv.rows variable, and increments the Csv.row_count
        variable.

    Arguments:
        Csv* csv:
            The Csv struct that the value is added to.

        CsvRow value:
            The CsvRow that you want to add to the Csv 
            struct.

    Returns:
        True:
            The CsvRow value was added to the Csv.rows 
            variable

        False:
            The CsvRow value couldn't be added to the 
            Csv.rows variable


*/
bool Csv_push(Csv* csv, CsvRow value);

/*

    Decsription:
        Csv_new_row adds a new row into the Csv.rows 
        variable and returns a variable to it. This
        is primarely used to add new things to already
        existing csv tables. Remember that the Csv struct
        owns the memory, so don't free it

    Arguments:
        Csv* csv:
            The Csv struct that the new CsvRow will be 
            added to

    Returns:
        CsvRow*:
            The row has been added to the Csv.rows 
            variable and is ready for usage.
        NULL:
            The row couldn't be added to the CSv.rows
            variable

*/
CsvRow* Csv_new_row(Csv* csv);

/*
    Description:
        Csv_free just frees the memory allocated for the 
        rows

    Arguments:
        Csv* csv:
            The Csv struct that you want to free
*/
void Csv_free(Csv* csv);

#endif
