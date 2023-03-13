#ifndef csv_reader_h
#define csv_reader_h

#include "csv.h"

/*

    CsvReader_load reads a csv file, and parses it into a 
    Csv struct.

    Arguments:
        Csv* csv:
            The Csv struct that the file contents will be 
            loaded in

        char* path:
            The path to the file that you want to read

    Returns:
        False:
            The function failed to load the file.

        True:
            The function loaded the file into the Csv struct

*/
bool CsvReader_load(Csv* csv, char* path);

#endif
