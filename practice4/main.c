#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura para almacenar los registros.
typedef struct {
    int registro;
    int dia;
    int mes;
    int anio;
    int hora;
    float velocidad;
} RegistroDatos;

// Function prototypes
int countLines(char *filename);
void readDataIntoStruct(char *filename, RegistroDatos *records, int numLines);
void saveDataToBinary(char *binaryFilename, RegistroDatos *records, int numLines);
void readBinaryRecord(char *binaryFilename, int recordNum);

// Function to count the number of lines in the file.
int countLines(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    int lines = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file)) {
        lines++;
    }

    fclose(file);
    return lines - 1; // Subtract 1 for the header line.
}

// Function to read data from the file and store it in the array of structures.
void readDataIntoStruct(char *filename, RegistroDatos *records, int numLines) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[256];
    // Remove the first line (header).
    fgets(buffer, sizeof(buffer), file);

    for (int i = 0; i < numLines; i++) {
        fgets(buffer, sizeof(buffer), file);
        sscanf(buffer, "%d/%d/%d,%d,%f",
               &records[i].dia,
               &records[i].mes,
               &records[i].anio,
               &records[i].hora,
               &records[i].velocidad);
        records[i].registro = i + 1;
    }

    fclose(file);
}

// Function to save data to a binary file.
void saveDataToBinary(char *binaryFilename, RegistroDatos *records, int numLines) {
    FILE *file = fopen(binaryFilename, "wb");
    if (file == NULL) {
        perror("Error opening binary file");
        return;
    }

    fwrite(records, sizeof(RegistroDatos), numLines, file);

    fclose(file);
}

// Function to read a specific record from the binary file.
void readBinaryRecord(char *binaryFilename, int recordNum) {
    FILE *file = fopen(binaryFilename, "rb");
    if (file == NULL) {
        perror("Error opening binary file");
        return;
    }

    if (recordNum < 1) {
        printf("Invalid record number\n");
        return;
    }

    RegistroDatos record;
    fseek(file, (recordNum - 1) * sizeof(RegistroDatos), SEEK_SET); // Move the file pointer to the desired record.
    fread(&record, sizeof(RegistroDatos), 1, file); // Read the record.

    printf("Record %d:\n", recordNum);
    printf("Date: %02d/%02d/%d\n", record.dia, record.mes, record.anio);
    printf("Hour: %d\n", record.hora);
    printf("Speed: %.4f\n", record.velocidad);

    fclose(file);
}

int main() {
    char filename[] = "datos.txt";
    char binaryFilename[] = "datos.bin";

    int numLines = countLines(filename);
    if (numLines < 0) {
        return 1;
    }

    RegistroDatos *records = (RegistroDatos *)malloc(numLines * sizeof(RegistroDatos));
    if (records == NULL) {
        perror("Error allocating memory");
        return 1;
    }

    readDataIntoStruct(filename, records, numLines);
    saveDataToBinary(binaryFilename, records, numLines);

    int recordNum;
    printf("Enter the record number to read: ");
    scanf("%d", &recordNum);

    readBinaryRecord(binaryFilename, recordNum);

    free(records);

    return 0;
}
