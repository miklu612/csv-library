#ifndef csv_row_h
#define csv_row_h

#include<stdio.h>
#include<stdbool.h>

typedef struct {
    char** columns;
    size_t column_count;
} CsvRow;

/*
    CsvRow_init is used to initialize the CsvRow struct, so 
    it can be used in the rest of the CsvRow functions. **So
    use this before doing anything with the CsvRow struct**

    Arguments:
        CsvRow* csv_row:
            The CsvRow struct that is to be initialized

    Returns:

        False: 
            The CsvRow struct failed to initialize. So don't
            try to use it, if this function returned false

        True:
            The CsvRow struct initialized correctly and is 
            ready for use

*/
bool CsvRow_init(CsvRow* csv_row);

/*
    CsvRow_push pushes a value into the CsvRow.columns value, and 
    increments the CsvRow.column_count value. So basically this
    is a way to add new elements into the CsvRow struct

    Remember to use CsvRow_init before using this function

    Arguments:
        CsvRow* csv_row:
            The CsvRow struct that the value will be added
            to

        char* value:
            The value that will be added to the CsvRow 
            struct

    Returns:
        False:
            The value was failed to be added into the 
            CsvRow struct. You can still continue using
            the CsvRow if this happens.

        True:
            The value was added to the CsvRow struct

*/
bool CsvRow_push(CsvRow* csv_row, char* value);

/*
    CsvRow_free frees the allocated memory that was given to the 
    CsvRow. So use this when you don't need the row anymore

    Arguments:
        CsvRow* csv_row:
            The CsvRow struct that you want to free

*/
void CsvRow_free(CsvRow* csv_row);

/*

    CsvRow_clone creates a clone of the row and returns it.
    This is mainly used in the library, but nothing stops 
    you from using it. 

    This creates a full clone of the row, aka, it also 
    allocates more memory for the cloned row to store the
    cloned values

    Remember to free the cloned row, since you have 
    ownership over it.

    Arguments:
        CsvRow* csv_row:
            The CsvRow that you want to be cloned

    Returns:
        CsvRow:
            The cloned row


*/
CsvRow CsvRow_clone(CsvRow* csv_row);

#endif
