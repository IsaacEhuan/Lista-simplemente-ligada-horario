#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estructuras pre-establecidas
struct Fecha{
	int hora;
	int minuto;
};
typedef struct Fecha Fecha;
typedef struct Asignatura Asignatura;
typedef  Asignatura *ptrAsignatura;
struct Asignatura{
	char *nombreAsignatura;
	int diaSemana;
	Fecha *horarioEntrada;
	Fecha *horarioSalida;
	Asignatura *next;
	
};


void insertarDatos(ptrAsignatura*lista);
void crearNodo(ptrAsignatura*lista, char *nombreAsignatura, Fecha *horarioEntrada,Fecha *horarioSalida,int dia);
void insertarNodo(ptrAsignatura*lista,ptrAsignatura nuevaAsignatura,int dia);
void imprimir(ptrAsignatura lista);
struct Fecha *insertarFecha(int,int);

int main(){
	
	ptrAsignatura lista = NULL;  //Ya que no existen nodos
	insertarDatos(&lista);
	imprimir(lista);
	
	return 0;
	
}
	
	void insertarDatos(ptrAsignatura*lista){
		
		//Nótese que los días se cuentan del 0(lunes)al 5(sábado)
		//En la función "insertarFecha" se toman los datos (hora, minuto) como enteros int
		
		Fecha *entrada,*salida;
		char nomAsig[30] = "POO";
		entrada = insertarFecha (12,0);
		salida = insertarFecha (13,30);
		crearNodo(lista,nomAsig,entrada,salida,4);
		
		entrada = insertarFecha (12,0);
		salida = insertarFecha (13,30);
		crearNodo(lista,nomAsig,entrada,salida,1);
		
		entrada = insertarFecha (11,0);
		salida = insertarFecha (12,30);
		crearNodo(lista,nomAsig,entrada,salida,2);
		
		char nomAsig2[30] = "Cálculo Integral";
		
		entrada = insertarFecha (7,30);
		salida = insertarFecha (9,0);
		crearNodo(lista,nomAsig2,entrada,salida,0);
		
		entrada = insertarFecha (7,30);
		salida = insertarFecha (9,0);
		crearNodo(lista,nomAsig2,entrada,salida,1);
		
		entrada = insertarFecha (7,30);
		salida = insertarFecha (9,0);
		crearNodo(lista,nomAsig2,entrada,salida,3);
		
		char nomAsig3[30] = "Teoría de la Computación";
		
		entrada = insertarFecha (9,0);
		salida = insertarFecha (10,30);
		crearNodo(lista,nomAsig3,entrada,salida,1);
		
		entrada = insertarFecha (7,30);
		salida = insertarFecha (9,0);
		crearNodo(lista,nomAsig3,entrada,salida,4);
		
		entrada = insertarFecha (7,30);
		salida = insertarFecha (9,0);
		crearNodo(lista,nomAsig3,entrada,salida,2);
		
	}
		
		void crearNodo (ptrAsignatura*lista, char *nombreAsignatura, Fecha * horarioEntrada,Fecha *horarioSalida,int dia){
			ptrAsignatura nuevaAsignatura;
			nuevaAsignatura = (Asignatura*)malloc(sizeof(Asignatura)); //Aquí se crea el nodo
			
			//Metemos los datos al nodo
			nuevaAsignatura->nombreAsignatura = (char*)malloc((strlen(nombreAsignatura)+1) *sizeof(char));
			strcpy(nuevaAsignatura->nombreAsignatura,nombreAsignatura);
			nuevaAsignatura->horarioEntrada=horarioEntrada;
			nuevaAsignatura->horarioSalida=horarioSalida;
			nuevaAsignatura->diaSemana=dia;
			
			insertarNodo(lista,nuevaAsignatura,dia);
			
			
		}
			
			void insertarNodo(ptrAsignatura*lista,ptrAsignatura nuevaAsignatura,int dia){
				ptrAsignatura auxiliar,anterior;
				anterior=NULL;
				auxiliar=*lista;
				while ((auxiliar!=NULL&&dia>auxiliar->diaSemana)||(auxiliar!=NULL&&dia==auxiliar->diaSemana&&nuevaAsignatura->horarioEntrada->hora>auxiliar->horarioEntrada->hora)){
					
					anterior=auxiliar;
					auxiliar=auxiliar->next;
					
				}
				if(anterior==NULL){
					nuevaAsignatura->next=*lista;
					*lista=nuevaAsignatura;
				}else{
					anterior->next=nuevaAsignatura;
					nuevaAsignatura->next=auxiliar;
				}
				
				
			}
				
				void imprimir(ptrAsignatura lista){ //Se imprimen datos
					char nombreDia[6][15] ={"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
					puts(" H O R A R I O ");
					while(lista  != NULL){
						puts("------------------------------------------");
						printf("Materia:%s \n ",lista->nombreAsignatura);
						printf("Día: %s\n",nombreDia[lista->diaSemana]);
						
						//Se ponen las condicionales por la estética del horario (00)
						
						if((lista->horarioEntrada->minuto)==0){
							printf(" Entrada: %d:00\n",lista->horarioEntrada->hora);
						}else{
							printf(" Entrada: %d:%d\n",lista->horarioEntrada->hora,lista->horarioEntrada->minuto);
						}
						
						if((lista->horarioSalida->minuto)==0){
							printf(" Salida: %d:00\n",lista->horarioSalida->hora);
						}else{
							printf(" Salida: %d:%d\n",lista->horarioSalida->hora,lista->horarioSalida->minuto);
						}
            
						puts("------------------------------------------");
						lista= lista->next;
					}
				}
					
					struct Fecha *insertarFecha(int hor,int min){ //Devuelve el apuntador de la estructura fecha, para modularizar
						Fecha * a;
						a = (Fecha*)malloc(sizeof(Fecha));
						a -> hora = hor;
						a -> minuto = min;
						return a;
					}
