#include "../inc/header.h"

void search_matrix(char *operand1, char *operation, char *operand2, char *result) {
    if (*operation == '?') {
        search_matrix(operand1, "+", operand2, result);
        search_matrix(operand1, "-", operand2, result);
        search_matrix(operand1, "*", operand2, result);
        search_matrix(operand1, "/", operand2, result);
        return;
    }

    int operand1_size = mx_strlen(operand1);
    int operand2_size = mx_strlen(operand2);
    int result_size = mx_strlen(result);
    bool operand1_is_negative = false;
    bool operand2_is_negative = false;
    bool result_is_negative = false;

    if (operand1[0] == '-') {
        operand1_is_negative = true;
        operand1_size--;
        operand1++;
    } 

    if (operand2[0] == '-') {
        operand2_is_negative = true;
        operand2_size--; 
        operand2++;
    }

    if (result[0] == '-') {
        result_is_negative = true;
        result_size--;
        result++;
    }

    int operand1_integer = mx_atoi(operand1);
    int operand2_integer = mx_atoi(operand2);
    int result_integer = mx_atoi(result);

    long long min_operand1 = 0;
    if (operand1_size > 1) {
        min_operand1 = mx_pow(10, operand1_size - 1);
    }

    long long min_operand2 = 0;
    if (operand2_size > 1) {
        min_operand2 = mx_pow(10, operand2_size - 1);
    }

    long long min_result = 0;
    if (result_size > 1) {
        min_result = mx_pow(10, result_size - 1);
    }

    long long max_operand1 = mx_pow(10, operand1_size);
    long long max_operand2 = mx_pow(10, operand2_size);
    long long max_result = mx_pow(10, result_size);

    for (long long i = min_operand1; i < max_operand1; i++) {
        if (operand1_integer > 0) {
            i = operand1_integer;
        }

        char *operand1_array_char = mx_itoa(i);
        int operand1_array_char_size = mx_strlen(operand1_array_char);
        bool operand1_IsTrue = true;

        for (int j = 0; j < operand1_size - operand1_array_char_size; j++) {
            if (mx_isdigit(operand1[j]) 
            && operand1[j] != '0') {
                operand1_IsTrue = false;
                break;
            }
        }

        int w = 0;
        for (int j = operand1_size - operand1_array_char_size; j < operand1_size; j++) {
            if (operand1[j] != '?' 
            && operand1[j] != operand1_array_char[w]) {
                operand1_IsTrue = false;
                break;
            }
            w++;
        }

        free(operand1_array_char); 
        operand1_array_char = NULL;

        if (!operand1_IsTrue) {
            continue;
        }
           
        for (long long j = min_operand2; j < max_operand2; j++) {  
            if (operand2_integer > 0) {
                j = operand2_integer;
            }

            char *operand2_array_char = mx_itoa(j);
            int operand2_array_char_size = mx_strlen(operand2_array_char);
            bool operand2_IsTrue = true;

            for (int p = 0; p < operand2_size - operand2_array_char_size; p++) {
                if (mx_isdigit(operand2[p]) 
                && operand2[p] != '0') {
                    operand2_IsTrue = false;
                    break;
                }
            }

            int m = 0;
            for (int p = operand2_size - operand2_array_char_size; p < operand2_size; p++) {
                if (operand2[p] != '?' 
                && operand2[p] != operand2_array_char[m]) {
                    operand2_IsTrue = false;
                    break;
                }
                m++;
            }

            free(operand2_array_char); 
            operand2_array_char = NULL;

            if (!operand2_IsTrue)
                continue;
            
            for (long long k = min_result; k < max_result; k++) {
                if (result_integer > 0) {
                    k = result_integer;
                }

                char *result_array_char = mx_itoa(k);
                int result_array_char_size = mx_strlen(result_array_char);
                bool result_IsTrue = true;

                for (int n = 0; n < result_size - result_array_char_size; n++) {
                    if (mx_isdigit(result[n]) 
                    && result[n] != '0') {
                        result_IsTrue = false;
                        break;
                    }
                }

                int g = 0;
                for (int n = result_size - result_array_char_size; n < result_size; n++) {
                    if (result[n] != '?' 
                    && result[n] != result_array_char[g]) {
                        result_IsTrue = false;
                        break;
                    }
                    g++;
                }

                free(result_array_char); 
                result_array_char = NULL;

                if (!result_IsTrue) {
                    continue;
                }

                if (operand1_is_negative) {
                    i *= -1;
                }
                   
                if (operand2_is_negative) {
                    j *= -1;
                }
                    
                if (result_is_negative) {
                    k *= -1;
                }
                    

                if (*operation == '+') {
                    if (i + j == k) {
                        mx_printint(i);
                        mx_printstr(" + ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '-') {
                        if (i - j == k) {
                        mx_printint(i);
                        mx_printstr(" - ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '*') {
                        if (i * j == k) {
                        mx_printint(i);
                        mx_printstr(" * ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '/') {
                    if (j != 0 && i / j == k) {
                        mx_printint(i);
                        mx_printstr(" / ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }

                if (operand1_is_negative) {
                    i *= -1;
                } 

                if (operand2_is_negative) {
                    j *= -1;
                }
                    
                if (result_is_negative) {
                    k *= -1;
                }

                if (result_integer > 0) {
                    break;
                }
                   
            }
            if (operand2_integer > 0) {
                break;
            }
                
        }
        if (operand1_integer > 0) {
            break;
        }  
    }

    if (operand1_is_negative) {
        operand1--;
    }
        
    if (operand2_is_negative) {
        operand2--;
    }
        
    if (result_is_negative) {
        result--;
    }
}

