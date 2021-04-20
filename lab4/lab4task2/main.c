/* В текстовом файле находится произвольный текст. Разработать программу проверки
   правильности расстановки скобок (круглых, квадратных, фигурных). Критерий проверки:
   если встречается одна из закрывающих скобок, то последняя открывающая должна быть
   такого же типа; количество скобок каждого типа должно совпадать. Между скобками
   допустима запись любых символов.
   */

#include "main.h"

int length(const char string[N]) {
    int l = 0;
    while(string[l] != '\0') {
        l++;
    }
    return l;
}

int bracket(char text[N], int begin_num) { /*проверка ( */
    int end_num = -1, i;
    for(i = length(text); i >= 0; i--) {
        switch (text[i]) {
            case ')':
                end_num++;
                if(end_num == begin_num) return 1;
                break;

            case '}':
                end_num++;
                if(end_num == begin_num) return 0;
                break;

            case ']':
                end_num++;
                if(end_num == begin_num) return 0;
                break;

            default:
                if(end_num == begin_num) return 0;
                break;
        }
    }
    return 0;
}

int brace(char text[N], int begin_num) { /*проверка { */
    int end_num = -1, i;
    for(i = length(text); i >= 0; i--) {
        switch (text[i]) {
            case ')':
                end_num++;
                if(end_num == begin_num) return 0;
                break;

            case '}':
                end_num++;
                if(end_num == begin_num) return 1;
                break;

            case ']':
                end_num++;
                if(end_num == begin_num) return 0;
                break;

            default:
                if(end_num == begin_num) return 0;
                break;
        }
    }
    return 0;
}

int sq_bracket(char text[N], int begin_num) { /*проверка [ */
    int end_num = -1, i;
    for(i = length(text); i >= 0; i--) {
        switch (text[i]) {
            case ')':
                end_num++;
                if(end_num == begin_num) return 0;
                break;

            case '}':
                end_num++;
                if(end_num == begin_num) return 0;
                break;

            case ']':
                end_num++;
                if(end_num == begin_num) return 1;
                break;

            default:
                if(end_num == begin_num) return 0;
                break;
        }
    }
    return 0;
}

int bracket_check(char text[N]) {
    int i, begin_num = 0;

    for(i = 0; i < length(text); i++) {
        switch (text[i]) {
            case '(':
                if(!bracket(text, begin_num)) {
                    return 0;
                }

                begin_num++;
                break;

            case '{':
                if(!brace(text, begin_num)) {
                    return 0;
                }

                begin_num++;
                break;

            case '[':
                if(!sq_bracket(text, begin_num)) {
                    return 0;
                }

                begin_num++;
                break;
        }
    }
    return 1;
}

#ifndef TESTING

int main() {
    char text[N];
    FILE *file;

    file = fopen("/Users/vadinamo/Documents/программирование/lab4/lab4task2/text123.txt", "r");
    if(!file) {
        printf("File open error!");
        exit(0);
    }
    fgets(text, N, file);
    fclose(file);

    bracket_check(text) ? printf("Brackets are placed correctly") : printf("Brackets are placed incorrectly");
}

#endif
