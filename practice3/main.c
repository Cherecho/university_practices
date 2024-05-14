#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function prototypes
char *leeLineaDinamica();
char *cambiaMayúsculas(char *cadena_leida);
char *encriptaMensaje(char *cadena_mayusculas);
char *encuentraDatos(char * cadena_encriptada);
char *decodificaDatos(char * cadena_encriptada_datos);



char *leeLineaDinamica() {
    char tempBuffer[1024];
    char *linea = NULL;

    printf("Introduce tu mensaje: ");
    if (fgets(tempBuffer, 1024, stdin)) {
        // Remove the newline character
        size_t len = strlen(tempBuffer);
        if (tempBuffer[len - 1] == '\n') {
            tempBuffer[len - 1] = '\0';
        }

        // Allocate memory for the new string and copy the input
        linea = (char *) malloc(strlen(tempBuffer) + 1);
        if (linea) {
            strcpy(linea, tempBuffer);
        } else {
            printf("Error allocating memory\n");
            return NULL;
        }
    } else {
        printf("Error reading input\n");
        return NULL;
    }

    return linea;
}

char *cambiaMayusculas(char *linea) {
    char *cadena_mayusculas = NULL;
    cadena_mayusculas = (char *) malloc(strlen(linea) + 1);

    if (cadena_mayusculas) {
        strcpy(cadena_mayusculas, linea);
        // Change the characters of the first letter of each word to uppercase
        int i = 0;
        while (cadena_mayusculas[i] != '\0') {
            if (i == 0 || cadena_mayusculas[i - 1] == ' ') {
                cadena_mayusculas[i] = toupper(cadena_mayusculas[i]);
            }
            i++;
        }
    } else {
        printf("Error allocating memory\n");
        return NULL;
    }

    return cadena_mayusculas;
}

char *encriptaMensaje(char *cadena_mayusculas) {

    char *cadena_encriptada = NULL;

    cadena_encriptada = (char *) malloc(strlen(cadena_mayusculas) + 1);

    if (cadena_encriptada) {
        strcpy(cadena_encriptada, cadena_mayusculas);
        // Change the characters of the first letter of each word to uppercase
        int i = 0;

        for (int i = 0; i < strlen(cadena_encriptada); i++) {
            if (cadena_encriptada[i] == 'A') {
                cadena_encriptada[i] = 'W';
            } else if (cadena_encriptada[i] == 'B') {
                cadena_encriptada[i] = 'X';
            } else if (cadena_encriptada[i] == 'C') {
                cadena_encriptada[i] = 'A';
            } else if (cadena_encriptada[i] == 'D') {
                cadena_encriptada[i] = 'H';
            } else if (cadena_encriptada[i] == 'E') {
                cadena_encriptada[i] = 'Q';
            } else if (cadena_encriptada[i] == 'F') {
                cadena_encriptada[i] = 'F';
            } else if (cadena_encriptada[i] == 'G') {
                cadena_encriptada[i] = 'P';
            } else if (cadena_encriptada[i] == 'H') {
                cadena_encriptada[i] = 'I';
            } else if (cadena_encriptada[i] == 'I') {
                cadena_encriptada[i] = 'R';
            } else if (cadena_encriptada[i] == 'J') {
                cadena_encriptada[i] = 'V';
            } else if (cadena_encriptada[i] == 'K') {
                cadena_encriptada[i] = 'K';
            } else if (cadena_encriptada[i] == 'L') {
                cadena_encriptada[i] = 'B';
            } else if (cadena_encriptada[i] == 'M') {
                cadena_encriptada[i] = 'J';
            } else if (cadena_encriptada[i] == 'N') {
                cadena_encriptada[i] = 'D';
            } else if (cadena_encriptada[i] == 'O') {
                cadena_encriptada[i] = 'G';
            } else if (cadena_encriptada[i] == 'P') {
                cadena_encriptada[i] = 'M';
            } else if (cadena_encriptada[i] == 'Q') {
                cadena_encriptada[i] = 'E';
            } else if (cadena_encriptada[i] == 'R') {
                cadena_encriptada[i] = 'L';
            } else if (cadena_encriptada[i] == 'S') {
                cadena_encriptada[i] = 'N';
            } else if (cadena_encriptada[i] == 'T') {
                cadena_encriptada[i] = 'O';
            } else if (cadena_encriptada[i] == 'U') {
                cadena_encriptada[i] = 'Y';
            } else if (cadena_encriptada[i] == 'V') {
                cadena_encriptada[i] = 'U';
            } else if (cadena_encriptada[i] == 'W') {
                cadena_encriptada[i] = 'T';
            } else if (cadena_encriptada[i] == 'X') {
                cadena_encriptada[i] = 'C';
            } else if (cadena_encriptada[i] == 'Y') {
                cadena_encriptada[i] = 'Z';
            } else if (cadena_encriptada[i] == 'Z') {
                cadena_encriptada[i] = 'S';
            } else if (cadena_encriptada[i] == 'a') {
                cadena_encriptada[i] = 'w';
            } else if (cadena_encriptada[i] == 'b') {
                cadena_encriptada[i] = 'x';
            } else if (cadena_encriptada[i] == 'c') {
                cadena_encriptada[i] = 'a';
            } else if (cadena_encriptada[i] == 'd') {
                cadena_encriptada[i] = 'h';
            } else if (cadena_encriptada[i] == 'e') {
                cadena_encriptada[i] = 'q';
            } else if (cadena_encriptada[i] == 'f') {
                cadena_encriptada[i] = 'f';
            } else if (cadena_encriptada[i] == 'g') {
                cadena_encriptada[i] = 'p';
            } else if (cadena_encriptada[i] == 'h') {
                cadena_encriptada[i] = 'i';
            } else if (cadena_encriptada[i] == 'i') {
                cadena_encriptada[i] = 'r';
            } else if (cadena_encriptada[i] == 'j') {
                cadena_encriptada[i] = 'v';
            } else if (cadena_encriptada[i] == 'k') {
                cadena_encriptada[i] = 'k';
            } else if (cadena_encriptada[i] == 'l') {
                cadena_encriptada[i] = 'b';
            } else if (cadena_encriptada[i] == 'm') {
                cadena_encriptada[i] = 'j';
            } else if (cadena_encriptada[i] == 'n') {
                cadena_encriptada[i] = 'd';
            } else if (cadena_encriptada[i] == 'o') {
                cadena_encriptada[i] = 'g';
            } else if (cadena_encriptada[i] == 'p') {
                cadena_encriptada[i] = 'm';
            } else if (cadena_encriptada[i] == 'q') {
                cadena_encriptada[i] = 'e';
            } else if (cadena_encriptada[i] == 'r') {
                cadena_encriptada[i] = 'l';
            } else if (cadena_encriptada[i] == 's') {
                cadena_encriptada[i] = 'n';
            } else if (cadena_encriptada[i] == 't') {
                cadena_encriptada[i] = 'o';
            } else if (cadena_encriptada[i] == 'u') {
                cadena_encriptada[i] = 'y';
            } else if (cadena_encriptada[i] == 'v') {
                cadena_encriptada[i] = 'u';
            } else if (cadena_encriptada[i] == 'w') {
                cadena_encriptada[i] = 't';
            } else if (cadena_encriptada[i] == 'x') {
                cadena_encriptada[i] = 'c';
            } else if (cadena_encriptada[i] == 'y') {
                cadena_encriptada[i] = 'z';
            } else if (cadena_encriptada[i] == 'z') {
                cadena_encriptada[i] = 's';
            } else if (cadena_encriptada[i] == '0') {
                cadena_encriptada[i] = '7';
            } else if (cadena_encriptada[i] == '1') {
                cadena_encriptada[i] = '8';
            } else if (cadena_encriptada[i] == '2') {
                cadena_encriptada[i] = '3';
            } else if (cadena_encriptada[i] == '3') {
                cadena_encriptada[i] = '5';
            } else if (cadena_encriptada[i] == '4') {
                cadena_encriptada[i] = '4';
            } else if (cadena_encriptada[i] == '5') {
                cadena_encriptada[i] = '6';
            } else if (cadena_encriptada[i] == '6') {
                cadena_encriptada[i] = '2';
            } else if (cadena_encriptada[i] == '7') {
                cadena_encriptada[i] = '9';
            } else if (cadena_encriptada[i] == '8') {
                cadena_encriptada[i] = '1';
            } else if (cadena_encriptada[i] == '9') {
                cadena_encriptada[i] = '0';
            }
        }
    }

    return cadena_encriptada;
}

char *encuentraDatos(char *cadena_encriptada) {
    char *inicio = strchr(cadena_encriptada, '(');
    char *fin = strchr(cadena_encriptada, ')');

    if (inicio != NULL && fin != NULL && fin > inicio) {
        size_t longitudDatos = fin - inicio - 1;
        char *cadena_encriptada_datos = malloc(longitudDatos + 1);

        if (!cadena_encriptada_datos) {
            perror("Error al reservar memoria");
            exit(EXIT_FAILURE);
        }

        strncpy(cadena_encriptada_datos, inicio + 1, longitudDatos);
        cadena_encriptada_datos[longitudDatos] = '\0';  // Asegurar el terminador nulo

        return cadena_encriptada_datos;
    } else {
        return NULL;  // No se encontraron paréntesis bien formados
    }
}

char *decodificaDatos(char *cadena_encriptada_datos) {
    char *cadena_decodificada = NULL;

    cadena_decodificada = (char *) malloc(strlen(cadena_encriptada_datos) + 1);

    if (cadena_decodificada) {
        strcpy(cadena_decodificada, cadena_encriptada_datos);
        // Change the characters of the first letter of each word to uppercase
        int i = 0;

        for (int i = 0; i < strlen(cadena_decodificada); i++) {
            if (cadena_decodificada[i] == 'W') {
                cadena_decodificada[i] = 'A';
            } else if (cadena_decodificada[i] == 'X') {
                cadena_decodificada[i] = 'B';
            } else if (cadena_decodificada[i] == 'A') {
                cadena_decodificada[i] = 'C';
            } else if (cadena_decodificada[i] == 'H') {
                cadena_decodificada[i] = 'D';
            } else if (cadena_decodificada[i] == 'Q') {
                cadena_decodificada[i] = 'E';
            } else if (cadena_decodificada[i] == 'F') {
                cadena_decodificada[i] = 'F';
            } else if (cadena_decodificada[i] == 'P') {
                cadena_decodificada[i] = 'G';
            } else if (cadena_decodificada[i] == 'I') {
                cadena_decodificada[i] = 'H';
            } else if (cadena_decodificada[i] == 'R') {
                cadena_decodificada[i] = 'I';
            } else if (cadena_decodificada[i] == 'V') {
                cadena_decodificada[i] = 'J';
            } else if (cadena_decodificada[i] == 'K') {
                cadena_decodificada[i] = 'K';
            } else if (cadena_decodificada[i] == 'B') {
                cadena_decodificada[i] = 'L';
            } else if (cadena_decodificada[i] == 'J') {
                cadena_decodificada[i] = 'M';
            } else if (cadena_decodificada[i] == 'D') {
                cadena_decodificada[i] = 'N';
            } else if (cadena_decodificada[i] == 'G') {
                cadena_decodificada[i] = 'O';
            } else if (cadena_decodificada[i] == 'M') {
                cadena_decodificada[i] = 'P';
            } else if (cadena_decodificada[i] == 'E') {
                cadena_decodificada[i] = 'Q';
            } else if (cadena_decodificada[i] == 'L') {
                cadena_decodificada[i] = 'R';
            } else if (cadena_decodificada[i] == 'N') {
                cadena_decodificada[i] = 'S';
            } else if (cadena_decodificada[i] == 'O') {
                cadena_decodificada[i] = 'T';
            } else if (cadena_decodificada[i] == 'Y') {
                cadena_decodificada[i] = 'U';
            } else if (cadena_decodificada[i] == 'U') {
                cadena_decodificada[i] = 'V';
            } else if (cadena_decodificada[i] == 'T') {
                cadena_decodificada[i] = 'W';
            } else if (cadena_decodificada[i] == 'C') {
                cadena_decodificada[i] = 'X';
            } else if (cadena_decodificada[i] == 'Z') {
                cadena_decodificada[i] = 'Y';
            } else if (cadena_decodificada[i] == 'S') {
                cadena_decodificada[i] = 'Z';
            } else if (cadena_decodificada[i] == 'w') {
                cadena_decodificada[i] = 'a';
            } else if (cadena_decodificada[i] == 'x') {
                cadena_decodificada[i] = 'b';
            } else if (cadena_decodificada[i] == 'a') {
                cadena_decodificada[i] = 'c';
            } else if (cadena_decodificada[i] == 'h') {
                cadena_decodificada[i] = 'd';
            } else if (cadena_decodificada[i] == 'q') {
                cadena_decodificada[i] = 'e';
            } else if (cadena_decodificada[i] == 'f') {
                cadena_decodificada[i] = 'f';
            } else if (cadena_decodificada[i] == 'p') {
                cadena_decodificada[i] = 'g';
            } else if (cadena_decodificada[i] == 'i') {
                cadena_decodificada[i] = 'h';
            } else if (cadena_decodificada[i] == 'r') {
                cadena_decodificada[i] = 'i';
            } else if (cadena_decodificada[i] == 'v') {
                cadena_decodificada[i] = 'j';
            } else if (cadena_decodificada[i] == 'k') {
                cadena_decodificada[i] = 'k';
            } else if (cadena_decodificada[i] == 'b') {
                cadena_decodificada[i] = 'l';
            } else if (cadena_decodificada[i] == 'j') {
                cadena_decodificada[i] = 'm';
            } else if (cadena_decodificada[i] == 'd') {
                cadena_decodificada[i] = 'n';
            } else if (cadena_decodificada[i] == 'g') {
                cadena_decodificada[i] = 'o';
            } else if (cadena_decodificada[i] == 'm') {
                cadena_decodificada[i] = 'p';
            } else if (cadena_decodificada[i] == 'e') {
                cadena_decodificada[i] = 'q';
            } else if (cadena_decodificada[i] == 'l') {
                cadena_decodificada[i] = 'r';
            } else if (cadena_decodificada[i] == 'n') {
                cadena_decodificada[i] = 's';
            } else if (cadena_decodificada[i] == 'o') {
                cadena_decodificada[i] = 't';
            } else if (cadena_decodificada[i] == 'y') {
                cadena_decodificada[i] = 'u';
            } else if (cadena_decodificada[i] == 'u') {
                cadena_decodificada[i] = 'v';
            } else if (cadena_decodificada[i] == 't') {
                cadena_decodificada[i] = 'w';
            } else if (cadena_decodificada[i] == 'c') {
                cadena_decodificada[i] = 'x';
            } else if (cadena_decodificada[i] == 'z') {
                cadena_decodificada[i] = 'y';
            } else if (cadena_decodificada[i] == 's') {
                cadena_decodificada[i] = 'z';
            } else if (cadena_decodificada[i] == '0') {
                cadena_decodificada[i] = '7';
            } else if (cadena_decodificada[i] == '1') {
                cadena_decodificada[i] = '8';
            } else if (cadena_decodificada[i] == '2') {
                cadena_decodificada[i] = '3';
            } else if (cadena_decodificada[i] == '3') {
                cadena_decodificada[i] = '5';
            } else if (cadena_decodificada[i] == '4') {
                cadena_decodificada[i] = '4';
            } else if (cadena_decodificada[i] == '5') {
                cadena_decodificada[i] = '6';
            } else if (cadena_decodificada[i] == '6') {
                cadena_decodificada[i] = '2';
            } else if (cadena_decodificada[i] == '7') {
                cadena_decodificada[i] = '9';
            } else if (cadena_decodificada[i] == '8') {
                cadena_decodificada[i] = '1';
            } else if (cadena_decodificada[i] == '9') {
                cadena_decodificada[i] = '0';
            }
        }
    }

    return cadena_decodificada;
}


int main() {
    char *cadena_leida = leeLineaDinamica();
    printf("Tu mensaje es: %s\n", cadena_leida);
    char *cadena_mayusculas = cambiaMayusculas(cadena_leida);
    free(cadena_leida);
    printf("Tu mensaje en mayusculas es: %s\n", cadena_mayusculas);
    char *cadena_encriptada = encriptaMensaje(cadena_mayusculas);
    free(cadena_mayusculas);
    printf("Tu mensaje encriptado es: %s\n", cadena_encriptada);
    char *cadena_encriptada_datos = encuentraDatos(cadena_encriptada);
    free(cadena_encriptada);
    printf("Los datos encriptados son: %s\n", cadena_encriptada_datos);


    char *datosCopiados = strdup(cadena_encriptada_datos);
    if (!datosCopiados) {
        perror("Error al reservar memoria");
        exit(EXIT_FAILURE);
    }

    printf("Datos encriptados separados:\n");
    char *token = strtok(datosCopiados, "-");
    int contador = 1;
    while (token != NULL) {
        printf("Dato encriptado %d: %s\n", contador, token);
        printf("Dato desencriptado %d: %s\n", contador++, decodificaDatos(token));
        token = strtok(NULL, "-");
    }

    free(cadena_encriptada_datos);
    return 0;
}