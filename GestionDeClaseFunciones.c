#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CLASE 30
#define LON_NOMBRE 200
#define LON_DNI 10
#define NUM_TOTAL_CLASES 2000

typedef char TDni[LON_DNI];

typedef char TNombre[LON_NOMBRE];//En el printf colocar %s pq es la asignacion de un string 

typedef struct{
    TNombre nombre;
    TDni dni;
    int edad;
    double altura;
    int faltas;
    int asistencia;
}TPersona;

typedef struct{
    TPersona datos;
    int ocupado;
}TUnaPersona;

typedef TUnaPersona TClase[MAX_CLASE];

//Funciones para gestion del array
void inicializar(TUnaPersona tabla[]);
void mostrarPersona(TPersona persona);
int buscarDni(TUnaPersona tabla[], TDni dni, int * posicion);
//Funcion para el programa principal
int menu(void);

int main(void)
{
    
    TClase miClase;//Usar TClase es equivalente a TUnaPersona otraClase[MAX_CLASE];
    int i ;
    int posicionHueco;
    int opcion;
    int encontrado;
    TDni dniBuscar;
    int pos;
    char c;
    
    
    //Se hace este paso para que tenga valor 0 y no aleatorio 
    /*for(i=0;i<MAX_CLASE;i++)
    {
        miClase[i].ocupado=0;
    }
    */
    //Inicializar el array a todo vacio
    inicializar(miClase);
    do
    {
        /*printf(" ******************************************************\n");
        printf("*\t\tPrograma de Gestion                    *\n");
        printf("*\tSergio Lopez                                   *\n");       
        printf(" ******************************************************\n\n");

        printf("1. Dar de alta\n");
        printf("2. Dar de baja\n");
        printf("3. Modificar una persona \n");
        printf("4. Mostrar una persona\n");
        printf("5. Mostrar todas las personas\n");
        printf("6. Salir\n\n\n");
        printf("Introduzca una opcion: ");
        scanf("%d",&opcion);
        fflush(stdin);*/
        opcion=menu();
        
        switch(opcion)
        {
            case 1:
            //Buscar un hueco
            i=0;
            encontrado=0;
            while(i<MAX_CLASE && encontrado==0)
            {
                if(miClase[i].ocupado==0)//Si el if solo tiene una sentencia no hacen falta las llaves 
                   encontrado=1;
                else
                  i++;                    
                
            }
            if(encontrado==1)
            {
                //Salvar la posicion del hueco en una variable
                posicionHueco=i;
                printf("Hueco encontrado en: %d\n",i);
                //Leer el dni
                printf("Introduzca el DNI: ");
                gets(dniBuscar);
                //Buscar el dni en la tabla
                
                
                if(buscarDni(miClase, dniBuscar, &pos)==0)
                {
                    //Copiar dni, pedir resto de datos, poner el ocupado a 1
                    strcpy(miClase[posicionHueco].datos.dni,dniBuscar);
                    // Leer por teclado Nomobre,altura,edad,asistencia,faltas
                   
                    printf("Introduzca nombre: ");
                    gets(miClase[posicionHueco].datos.nombre);
                    printf("Introduzca su altura: ");
                    scanf("%lf",&miClase[posicionHueco].datos.altura);
                    fflush(stdin);
                    printf("Introduzca su edad: ");
                    scanf("%d",&miClase[posicionHueco].datos.edad);
                    fflush(stdin);
                    miClase[posicionHueco].datos.asistencia=NUM_TOTAL_CLASES;//Inicializa asistencias a 2000
                    miClase[posicionHueco].datos.faltas=0;
                    
                    miClase[posicionHueco].ocupado=1;
                    printf("Nombre: %s\n Altura: %.2f\n Edad: %d\n Asistencia: %d/2000\n Faltas: %d\n",miClase[posicionHueco].datos.nombre, miClase[posicionHueco].datos.altura, miClase[posicionHueco].datos.edad, miClase[posicionHueco].datos.asistencia, miClase[posicionHueco].datos.faltas);
                    
                    //miClase[posicionHueco].ocupado=1;
                    printf("Alta de %s en la posicion %d\n",dniBuscar,posicionHueco);    
                }
                else
                {
                    printf("Error DNI: %s repetido!!\n",dniBuscar);
                }
                
            }
            else
            {
                printf("La tabla esta llena\n");
            }
            break;
            
            case 2:
            //Leer el dni
            printf("Introduzca el DNI para eliminar: ");
            gets(dniBuscar);
            //Buscar el dni en la tabla
                buscarDni(miClase, dniBuscar, &pos);
                
                if(encontrado==1)
                {
                    miClase[i].ocupado=0;
                    printf("El usuario con nombre %s y DNI %s ha sido eliminado\n",miClase[posicionHueco].datos.nombre,dniBuscar);
                }
                else
                {
                    printf("Error DNI %s no localizado\n",dniBuscar);
                }
            
            break;
            
            case 3:
            //Leer el dni
            printf("Introduzca el DNI de usuario para modificar: ");
            gets(dniBuscar);
            //Buscar el dni en la tabla
            buscarDni(miClase, dniBuscar, &pos);
            
                if(encontrado==1)
                {
                    // Leer por teclado Nomobre,altura,edad
                    printf("Introduzca nombre: ");
                    gets(miClase[i].datos.nombre);
                    printf("Introduzca su altura: ");
                    scanf("%lf",&miClase[i].datos.altura);
                    fflush(stdin);
                    printf("Introduzca su edad: ");
                    scanf("%d",&miClase[i].datos.edad);
                    fflush(stdin);
                    /*printf("Introduzca su asistencia sobre 2000: ");
                    scanf("%d",&miClase[i].datos.asistencia);
                    fflush(stdin);
                    printf("Introduzca sus faltas: ");
                    scanf("%d",&miClase[i].datos.faltas);
                    fflush(stdin);  */
                    }
            break;
            
            case 4:
            //Leer el dni
            printf("Introduzca el DNI para mostrar: ");
            gets(dniBuscar);
                if(buscarDni(miClase,dniBuscar,&pos)==1)
                {
                    mostrarPersona(miClase[pos].datos);
                    /*printf("Nombre: %s\n",miClase[i].datos.nombre);
                    printf("DNI: %s\n",miClase[i].datos.dni);
                    printf("Edad: %d\n",miClase[i].datos.edad);
                    printf("Altura: %.2f\n",miClase[i].datos.altura);
                    printf("Faltas: %d\n",miClase[i].datos.faltas);
                    printf("Asistencia: %d/1000\n\n",miClase[i].datos.asistencia);*/
                }
                else
                {
                    printf("Error DNI %s no localizado\n",dniBuscar);
                }

            break;
            
            case 5:
            for(i=0; i<MAX_CLASE; i++)
            {
                if(miClase[i].ocupado==1)
                {
                    mostrarPersona(miClase[i].datos);
                    /*printf("Nombre: %s\n",miClase[i].datos.nombre);
                    printf("DNI: %s\n",miClase[i].datos.dni);
                    printf("Edad: %d\n",miClase[i].datos.edad);
                    printf("Altura: %.2f\n",miClase[i].datos.altura);
                    printf("Faltas: %d\n",miClase[i].datos.faltas);
                    printf("Asistencia: %d/2000\n\n",miClase[i].datos.asistencia);*/
                    
                }
            }
            break;
            
            case 6:
            c=getchar();
            for(i=0;i<MAX_CLASE;i++)
            {
                if(miClase[i].ocupado==1)
                {
                    printf("Pregunta: Ha venido %s, con DNI %s a clase\n",miClase[i].datos.nombre, miClase[i].datos.dni);
                    printf("S o N\n");
                    do
                    {
                        scanf("%c",&c);
                        fflush(stdin);
                        if(c!='s' && c!='n')
                        {
                            printf("Tecla pulsada no es la correcta");
                        }
                    }
                    while(c!='s' && c!='n');
                    {
                        if(c=='n')
                        {
                            miClase[i].datos.faltas++;
                            miClase[i].datos.asistencia--;
                        }
                    }
                }
            }
            break;
            
            case 7:
            //Leer el dni
            printf("Introduzca el DNI para modificar sus faltas y asistencia: \n");
            gets(dniBuscar);
                if(buscarDni(miClase,dniBuscar,&pos)==1)
                {
                    printf("Introduzca sus faltas: ");
                    scanf("%d",&miClase[i].datos.faltas);
                    fflush(stdin);
                    miClase[i].datos.asistencia = miClase[i].datos.asistencia - miClase[i].datos.faltas;
                   
                }
                else
                {
                    printf("Error DNI %s no localizado\n",dniBuscar);
                }
            break;
            
            case 8:
            break;
            
            default:
            printf("opcion no valida\n\n");
            break;
            
        }
        
        system("pause");
        system("cls");  
            
    }
    while(opcion!=8);
    
    getchar();
    return 0;
}

int menu(void)
{
    int res;
        printf(" ******************************************************\n");
        printf("*\t\tPrograma de Gestion                    *\n");
        printf("*\tSergio Lopez                                   *\n");       
        printf(" ******************************************************\n\n");

        printf("1. Dar de alta\n");
        printf("2. Dar de baja\n");
        printf("3. Modificar una persona \n");
        printf("4. Mostrar una persona\n");
        printf("5. Mostrar todas las personas\n");
        printf("6. Pasar lista\n");
        printf("7. Modificar faltas y asistencia\n");
        printf("8. Salir\n\n\n");
        printf("Introduzca una opcion: ");
        scanf("%d",&res);
        fflush(stdin);
        return res;
        
}

//Gestion array
void inicializar(TUnaPersona tabla[])
{
    int i;
    for(i=0;i<MAX_CLASE;i++)
    {
        tabla[i].ocupado=0;
    }
}

void mostrarPersona(TPersona persona)
{
                    printf("Nombre: %s\n",persona.nombre);
                    printf("DNI: %s\n",persona.dni);
                    printf("Edad: %d\n",persona.edad);
                    printf("Altura: %.2f\n",persona.altura);
                    printf("Faltas: %d\n",persona.faltas);
                    printf("Asistencia: %d/2000\n\n",persona.asistencia);
}

int buscarDni(TUnaPersona tabla[], TDni dni, int * posicion)
{
    int i;
    int encontrado;
    //Buscar el dni en la tabla
                i=0;
                encontrado=0;
                while(i<MAX_CLASE && encontrado==0)
                {
                    if(tabla[i].ocupado==1 &&  strcmp(tabla[i].datos.dni,dni)==0)
                    {
                        encontrado=1;
                    }
                    else 
                    {
                        i++;
                    }
                }
                if(encontrado==1)
                {
                    *posicion=i;
                }
                return encontrado;
}