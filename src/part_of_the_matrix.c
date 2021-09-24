#include "../inc/header.h"

int main(int argc, char *argv[]) {

    if (argc != 5) {
        mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]");
        return 0;
    }
    
    char *operand1 = mx_strtrim(argv[1]);
    char *operation = mx_strtrim(argv[2]);
    char *operand2 = mx_strtrim(argv[3]);
    char *result = mx_strtrim(argv[4]);

    errors(argv, operand1, operation, operand2, result);
    search_matrix(operand1, operation, operand2, result);

    free(operand1); 
    operand1 = NULL;

    free(operation); 
    operation = NULL;

    free(operand2); 
    operand2 = NULL;

    free(result); 
    result = NULL;

    return 0;
}

