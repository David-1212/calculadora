#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int suma( int $a, int $b ) //funci�n para hacer una suma con instrucciones de ensamblador
{
int $result; //variable en donde se guardara el resultado
__asm__ __volatile__(
            "movl %1, %%eax;" //equivalente a MOV EAX, a
            "movl %2, %%ebx;" //equivalente a MOV EBX, b
            "addl %%ebx,%%eax;" //equivalente a ADD EAX, EBX
            "movl %%eax, %0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b ) //equivalente a MOV result, EAX
    );
    return $result ; //regresamos el resultado de la suma guardado en la variable result
}

int resta( int $a, int $b )  //funci�n para hacer una resta con instrucciones de ensamblador
{
    int $result; //variable en donde se guardara el resultado
    __asm__ __volatile__(
            "movl %1, %%eax;" //equivalente a MOV EAX, a
            "movl %2, %%ebx;" //equivalente a MOV EBX, b
            "subl %%ebx,%%eax;"//equivalente a SUB EAX, EBX
            "movl %%eax, %0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b ) //equivalente a MOV result, EAX
    );
    return $result ;//regresamos el resultado de la suma guardado en la variable result
}

int multiplicacion( int $a, int $b ) //funci�n para hacer una multiplicaci�n con instrucciones de ensamblador
{
    int $result; //variable en donde se guardara el resultado
    __asm__ __volatile__(
            "movl %1, %%eax;"//equivalente a MOV EAX, a
            "movl %2, %%ebx;"//equivalente a MOV EBX, b
            "imull %%ebx;"//equivalente a IMUL EBX
            "movl %%eax, %0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b )//equivalente a MOV result, EAX
    );
    return $result ;//regresamos el resultado de la suma guardado en la variable result
}

int division( int $a, int $b ) //funci�n para hacer una division con instrucciones de ensamblador
{
int $result;//variable en donde se guardara el resultado
__asm__ __volatile__(
		"movl %1, %%eax;"//equivalente a MOV EAX, a
		"movl %2, %%ebx;"//equivalente a MOV EBX, b
		"cltd;"
		"idivl %%ebx;"//equivalente a IDIV EBX
        "movl %%eax, %0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b )//equivalente a MOV result, EAX
);
return $result ;//regresamos el resultado de la suma guardado en la variable result
}


int main(int argc, char** argv) {
	float a,b,c;//variables para que el usuario ingrese los n�meros
	int op;//variable para la opci�n del menu
	bool band=false;
	cout<<"\t\t\t\t____________________________________________"<<endl;
    cout<<"\t\t\t\t| Calculadora escrita en ensamblador y C++ |"<<endl;
    cout<<"\t\t\t\t|__________________________________________|"<<endl;
	cout<<"\t\t\t\t| Rodriguez Amezquita Luis Daniel          |"<<endl;
	cout<<"\t\t\t\t| Andrade Alfaro Roberto Ozmar             |"<<endl;
	cout<<"\t\t\t\t| Vargas Lopez David Guadalupe             |"<<endl;
	cout<<"\t\t\t\t|__________________________________________|"<<endl;
	system ("color 1f");//color Fondo: Aqua Texto:Blanco brillante
	system("pause");//hacer una pausa
	system("cls");//limpiar pantalla
	do{//repetira el menu hasta que el usuario oprima salir
        system ("color 2f");//color Fondo: Aqua Texto:Blanco brillante
        a=0;//iniciar variables en 0
        b=0;//iniciar variables en 0
        c=0;//iniciar variables en 0
        cout<<"\n\n\n"<<endl;
        cout<<"\t\t\t\t|----------------------------|"<<endl;
        cout<<"\t\t\t\t|calculadora ensamblador y c |"<<endl;
        cout<<"\t\t\t\t|----------------------------|"<<endl;
        cout<<"\t\t\t\t|     [1]-SUMA(+)            |"<<endl;
        cout<<"\t\t\t\t|     [2]-RESTA (-)          |"<<endl;
        cout<<"\t\t\t\t|     [3]-MULTIPLICACION (*) |"<<endl;
        cout<<"\t\t\t\t|     [4]-DIVISON(/)         |"<<endl;
        cout<<"\t\t\t\t|     [5]-POTENCIA (^)       |"<<endl;
        cout<<"\t\t\t\t|     [6]-SALIR              |"<<endl;
        cout<<"\t\t\t\t|----------------------------|"<<endl;
        cout<<"Eliga una opcion: ";
        cin>>op;
        switch(op)
        {
            case 1://suma
                system ("color 65");//color Fondo: rojo Texto:blanco
                cout<<"Digite el primer numero: ";
                cin>>a;
                cout<<"Digite el segundo numero: ";
                cin>>b;
                //c=suma(a,b);//funcion suma en ensamblador
                c=a+b;
                printf("La Suma es: ");
                printf("%.2f + %.2f = %.2f \t\n",a,b,c);
                system("pause");//hacer una pausa
                system("cls");//limpiar pantalla
                break;
            case 2:
                system ("color A0");//color Fondo: Verde brillante Texto: negro
                cout<<"Digite el primer numero: ";
                cin>>a;
                cout<<"Digite el segundo numero: ";
                cin>>b;
                //c=resta(a,b);//funci�n resta en ensamblador
                c=a-b;
                printf("La Resta es: ");
                printf("%.2f - %.2f = %.2f \t\n",a,b,c);
                system("pause");//hacer una pausa
                system("cls");//limpiar pantalla
                break;
            case 3:
                system ("color 60");//color Fondo: Purpura Texto: negro
                cout<<"Digite el primer numero: ";
                cin>>a;
                cout<<"Digite el segundo numero: ";
                cin>>b;
                //c=multiplicacion(a,b);//funci�n multiplicacion en ensamblador
                c=a*b;
                printf("La Multiplicacion es: ");
                printf("%.2f * %.2f = %.2f \t\n",a,b,c);
                system("pause");//hacer una pausa
                system("cls");//limpiar pantalla
                break;
            case 4:
                system ("color 70");//color Fondo: negro Texto: verde
                cout<<"Digite el numerador: ";
                cin>>a;
                cout<<"Digite el denominador: ";
                cin>>b;
                //c=division(a,b);//funci�n division en ensamblador
                c=a/b;
                printf("La Division es: ");
                printf("%.2f / %.2f = %.2f \t\n",a,b,c);
                system("pause");//hacer una pausa
                system("cls");//limpiar pantalla
                break;
            case 5:
                system ("color 80");//color Fondo: amarillo brillante Texto: negro
                cout<<"Digite el numero: ";
                cin>>a;
                cout<<"Digite la potencia: ";
                cin>>b;
                if(b==0)//si la potencia es 0 el resultado es 1
                    c=1;
                else
                    if(b==1)//si la potencia es 1 el resultado es el mismo numero
                        c=a;
                else{
                    c=multiplicacion(a,a);
                    for(int i=2;i<b;i++)//ciclo que lo repetira la multiplicaci�n dependiendo de la potencia
                    {
                        c=multiplicacion(a,c);//funci�n multiplicacion en ensamblador
                    }
                }

                printf("El numero elevado es: ");
                printf("%.0f ^ %.0f = %.0f \t\n",a,b,c);
                system("pause");//hacer una pausa
                system("cls");//limpiar pantalla
                break;
            case 6:
                cout<<"\n\n\n\t\t\t\tGRACIAS POR UTILIZAR EL PROGRAMA !\n\n"<<endl;//mensaje de salida
                band=true;//activar bandera
                break;
            default:
                cout<<"opcion invalida,pruebe con las opciones del menu(del 1-6)!"<<endl;//mensaje si la opcion no es la esperada

        }
    }while(band!=true);

	return 0;
}

