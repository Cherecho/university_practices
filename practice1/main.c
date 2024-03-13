#include <stdio.h>
#include <string.h>

// Constants
#define MAX_USERS 3
#define MAX_BOOKS 3
#define MAX_ORDERS 3

// Structs
struct Usuario
{
    char nombre[50];
    char apellido[50];
    int idUsuario;
    char email[100];
    char telefono[20];
};

struct Libro
{
    char titulo[100];
    char autor[50];
    char ISBN[20];
    float precio;
    int cantidadStock;
};

struct Pedidos
{
    int idUsuario;
    char ISBN[20];
    int cantidadSolicitada;
    float precioTotal;
    char estadoEnvio[20];
};

// Function prototypes
void showMenu();
void printUsuario(struct Usuario *usuario);
void printLibro(struct Libro *libro);
void printPedido(struct Pedidos *pedido);
void generateUsuario(struct Usuario *usuario);
void generateLibro(struct Libro *libro);
void generatePedido(struct Pedidos *pedido);

void main(int argc, char* argv[])
{
    struct Usuario usuarios[MAX_USERS];
    struct Libro libros[MAX_BOOKS];
    struct Pedidos pedidos[MAX_ORDERS];

    int option;
    int usuarios_count = 0, libros_count = 0, pedidos_count = 0;

    do {
        showMenu();
        scanf("%d", &option);

        switch(option) {
            case 1:
                if(usuarios_count < MAX_USERS) {
                    generateUsuario(&usuarios[usuarios_count++]);
                } else {
                    printf("No se pueden crear m" "\xA0" "s usuarios.\n");
                }
                break;
            case 2:
                for(int i = 0; i < usuarios_count; i++) {
                    printf("\nUsuario %d\n", i + 1);
                    printUsuario(&usuarios[i]);
                }
                break;
            case 3:
                if(libros_count < MAX_BOOKS) {
                    generateLibro(&libros[libros_count++]);
                } else {
                    printf("No se pueden crear m" "\xA0" "s libros.\n");
                }
                break;
            case 4:
                for(int i = 0; i < libros_count; i++) {
                    printf("\nLibro %d\n", i + 1);
                    printLibro(&libros[i]);
                }
                break;
            case 5:
                if(pedidos_count < MAX_ORDERS) {
                    generatePedido(&pedidos[pedidos_count++]);
                } else {
                    printf("No se pueden crear m" "\xA0" "s pedidos.\n");
                }
                break;
            case 6:
                for(int i = 0; i < pedidos_count; i++) {
                    printf("\nPedido %d\n", i + 1);
                    printPedido(&pedidos[i]);
                }
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opci" "\xA2" "n inv" "\xA0" "lida.\n");
        }
    } while(option != 7);

}

// Function implementations
// Menu
void showMenu()
{
    printf("\nLibrer" "\xA1" "a virtual\n");
    printf("\nMenu de opciones:\n");
    printf("1. Crear un nuevo usuario\n");
    printf("2. Imprimir todos los usuarios\n");
    printf("3. Crear un nuevo libro\n");
    printf("4. Imprimir todos los libros\n");
    printf("5. Crear un nuevo pedido\n");
    printf("6. Imprimir todos los pedidos\n");
    printf("7. Salir\n");
    printf("Ingrese una opci" "\xA2" "n: ");
}

// Prints
void printUsuario(struct Usuario *usuario)
{
    printf("Usuario nombre: %s\n", usuario->nombre);
    printf("Usuario apellido: %s\n", usuario->apellido);
    printf("Usuario idUsuario: %d\n", usuario->idUsuario);
    printf("Usuario email: %s\n", usuario->email);
    printf("Usuario telefono: %s\n", usuario->telefono);
}

void printLibro(struct Libro *libro)
{
    printf("Libro titulo: %s\n", libro->titulo);
    printf("Libro autor: %s\n", libro->autor);
    printf("Libro ISBN: %s\n", libro->ISBN);
    printf("Libro precio: %f\n", libro->precio);
    printf("Libro cantidadStock: %d\n", libro->cantidadStock);
}

void printPedido(struct Pedidos *pedido)
{
    printf("Pedido idUsuario: %d\n", pedido->idUsuario);
    printf("Pedido ISBN: %s\n", pedido->ISBN);
    printf("Pedido cantidadSolicitada: %d\n", pedido->cantidadSolicitada);
    printf("Pedido precioTotal: %f\n", pedido->precioTotal);
    printf("Pedido estadoEnvio: %s\n", pedido->estadoEnvio);
}

// Generators
void generateUsuario(struct Usuario *usuario)
{
    printf("Ingrese el nombre del usuario: ");
    scanf("%49s", usuario->nombre); // Usamos %49s para prevenir desbordamiento de buffer
    printf("Ingrese el apellido del usuario: ");
    scanf("%49s", usuario->apellido);
    printf("Ingrese el ID de usuario: ");
    scanf("%d", &usuario->idUsuario);
    printf("Ingrese el correo electr" "\xA2" "nico: ");
    scanf("%99s", usuario->email);
    printf("Ingrese el n" "\xA3" "mero de tel" "\x82" "fono: ");
    scanf("%19s", usuario->telefono);
}

void generateLibro(struct Libro *libro)
{
    printf("Ingrese el t" "\xA1" "tulo del libro: ");
    scanf("%99s", libro->titulo);
    printf("Ingrese el autor del libro: ");
    scanf("%49s", libro->autor);
    printf("Ingrese el ISBN del libro: ");
    scanf("%19s", libro->ISBN);
    printf("Ingrese el precio del libro: ");
    scanf("%f", &libro->precio);
    printf("Ingrese la cantidad en stock: ");
    scanf("%d", &libro->cantidadStock);
}

void generatePedido(struct Pedidos *pedido)
{
    printf("Ingrese el ID del usuario: ");
    scanf("%d", &pedido->idUsuario);
    printf("Ingrese el ISBN del libro: ");
    scanf("%19s", pedido->ISBN);
    printf("Ingrese la cantidad solicitada: ");
    scanf("%d", &pedido->cantidadSolicitada);
    printf("Ingrese el precio total: ");
    scanf("%f", &pedido->precioTotal);
    printf("Ingrese el estado de env" "\xA1" "o: ");
    scanf("%19s", pedido->estadoEnvio);
}

