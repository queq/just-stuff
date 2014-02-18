#include <iostream>
#include <curses.h>

using namespace std;

char tablero[12][14]={
	{' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' '}
	,{'#','#','#','#','#','@',' ','#','#','#','#',' ',' ',' '}
	,{'#',' ',' ',' ','#','#',' ',' ',' ',' ','#',' ',' ',' '}
	,{'#',' ','$','#','#','#',' ',' ','$',' ','#','#','#','#'}
	,{'#',' ',' ',' ',' ','#','#','#','$','$',' ',' ',' ','#'}
	,{'#','#','.','.',' ',' ',' ',' ',' ',' ','$',' ',' ','#'}
	,{' ','#','.','.','#',' ',' ',' ',' ','#','#','#',' ','#'}
	,{' ','#','#','#','#','#','#',' ',' ',' ','#',' ',' ','#'}
	,{' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','#'}
	,{' ',' ',' ',' ',' ',' ','#','#',' ',' ','.',' ','#','#'}
	,{' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ','#',' '}
	,{' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' '}
	};
/*
 Nombre: menu
 Argumento: entero
 Descripción: Es un procedimiento que imprime el menu principal,
              al querer volver a el, y mediante un parametro por
              referencia, cambia el valor de la opcion, si se quiere
              acceder a otra, al salir de una.
 */
void menu (int &opc){
cout << "MENU PRINCIPAL" << endl << endl;
cout << "(1) JUGAR" << endl;
cout << "(2) INSTRUCCIONES DE JUEGO" << endl;
cout << "(3) MOSTRAR SOLUCION" << endl;
cout << "(4) SALIR" << endl << endl;
cout << "INGRESE UNA OPCION VALIDA";
cin >> opc;
}
/*
 Nombre: reinicio
 Argumento:dos enteros
 descripción: Es una función que se llama repetidas veces en un for,
              esta cambia cada celda de la matriz de juego [x][y], devolviendo
              el valor de la matriz original [x][y]
 */
char reinicio (int x, int y){
	char arr;
	arr=tablero[x][y];
	return arr;
}
/*
 Nombre: reinicio2
 Argumento:dos enteros
 descripción: es un procedimiento que mediante parametros por referencia
              devuelve el valor original de la posición del jugador.
              el jugador (@) originalmente esta en la posicion [2][6], por
              eso se devuelve al valor de fila (f) el número 2, y al valor de
              columna (c) 6.
 */
void reinicio2(int &f, int &c){
	f=1;
	c=5;
}
void arriba (char &jugador, char &arriba1, char &arriba2, int &ff, int &cont){
	cont+=1;
	if (jugador=='@'){
		if (arriba1=='$'){
			if (arriba2=='.'){
				arriba2='*';
				arriba1='@';
				jugador=' ';
			}
			else if (arriba2=='*'){
				arriba2=arriba2;
				arriba1=arriba1;
				jugador=jugador;
			}
			else if (arriba2=='$'){
				arriba2=arriba2;
				arriba1=arriba1;
				jugador=jugador;
			}
			else if (arriba2=='#'){
				arriba2=arriba2;
				arriba1=arriba1;
				jugador=jugador;
			}
			else if (arriba2==' '){
				arriba2='$';
				arriba1='@';
				jugador=' ';
				ff=ff-1;
			}
		}
		else if (arriba1=='.'){
			if (arriba2=='.'){
				arriba2=arriba2;
				arriba1='+';
				jugador=' ';
				ff=ff-1;
			}
			else if (arriba2=='*'){
				arriba2=arriba2;
				arriba1='+';
				jugador=' ';
				ff=ff-1;
			}
			else if (arriba2=='$'){
				arriba2=arriba2;
				arriba1='+';
				jugador=' ';
				ff=ff-1;
			}
			else if (arriba2=='#'){
				arriba2=arriba2;
				arriba1='+';
				jugador=' ';
				ff=ff-1;
			}
			else if (arriba2==' '){
				arriba2=arriba2;
				arriba1='+';
				jugador=' ';
				ff=ff-1;
			}
		}
		else if (arriba1=='*'){
			if (arriba2=='.'){
				arriba2='*';
				arriba1='+';
				jugador=' ';
				ff=ff-1;
			}
			else if (arriba2=='*'){
				arriba2=arriba2;
				arriba1=arriba1;
				jugador=jugador;
			}
			else if (arriba2=='$'){
				arriba2=arriba2;
				arriba1=arriba1;
				jugador=jugador;
			}
			else if (arriba2=='#'){
				arriba2=arriba2;
				arriba1=arriba1;
				jugador=jugador;
			}
			else if (arriba2==' '){
				arriba2='$';
				arriba1='+';
				jugador=' ';
				ff=ff-1;
			}
		}
		else if (arriba1==' '){
			arriba1='@';
			jugador=' ';
			ff=ff-1;
		}
		else if (arriba1=='#'){
			arriba1=arriba1;
			jugador=jugador;
		}
	}
	else if (jugador=='+'){
		if (arriba1=='$'){
			if (arriba2=='$'){
				arriba1=arriba1;
				arriba2=arriba2;
				jugador=jugador;
			}
			else if (arriba2=='.'){
				arriba2='*';
				arriba1='@';
				jugador='.';
				ff=ff-1;
			}
			else if (arriba2=='*'){
				arriba1=arriba1;
				arriba2=arriba2;
				jugador=jugador;
			}
			else if (arriba2=='#'){
				arriba1=arriba1;
				arriba2=arriba2;
				jugador=jugador;
			}
			else if (arriba2==' '){
				arriba2='$';
				arriba1='@';
				jugador='.';
				ff=ff-1;
			}
		}
		else if (arriba1=='.'){
			if (arriba2=='$'){
				arriba1='+';
				jugador='.';
				ff=ff-1;
			}
			else if (arriba2=='.'){
				arriba1='+';
				jugador='.';
				ff=ff-1;
			}
			else if (arriba2=='*'){
				arriba1='+';
				jugador='.';
				ff=ff-1;
			}
			else if (arriba2=='#'){
				arriba1='+';
				jugador='.';
				ff=ff-1;
			}
			else if (arriba2==' '){
				arriba1='+';
				jugador='.';
				ff=ff-1;
			}
		}
		else if (arriba1=='*'){
			if (arriba2=='$'){
				arriba2=arriba2;
				arriba1=arriba1;
				jugador=jugador;
			}
			else if (arriba2=='.'){
				arriba2='*';
				arriba1='.';
				jugador='.';
				ff=ff-1;
			}
			else if (arriba2=='*'){
				arriba2=arriba2;
				arriba1=arriba1;
				jugador=jugador;
			}
			else if (arriba2=='#'){
				arriba2=arriba2;
				arriba1=arriba1;
				jugador=jugador;
			}
			else if (arriba2==' '){
				arriba2='$';
				arriba1='+';
				jugador='.';
				ff=ff-1;
			}
		}
		else if (arriba1=='#'){
			if (arriba2=='$'){
				arriba2=arriba2;
				arriba1=arriba1;
				jugador=jugador;
			}
			else if (arriba2=='.'){
				arriba2=arriba2;
				arriba1=arriba1;
				jugador=jugador;
			}
			else if (arriba2=='*'){
				arriba2=arriba2;
				arriba1=arriba1;
				jugador=jugador;
			}
			else if (arriba2=='#'){
				arriba2=arriba2;
				arriba1=arriba1;
				jugador=jugador;
			}
			else if (arriba2==' '){
				arriba2=arriba2;
				arriba1=arriba1;
				jugador=jugador;
			}
		}
		else if (arriba1==' '){
			if (arriba2=='$'){
				arriba2=arriba2;
				arriba1='@';
				jugador='.';
				ff=ff-1;
			}
			else if (arriba2=='.'){
				arriba2=arriba2;
				arriba1='@';
				jugador='.';
				ff=ff-1;
			}
			else if (arriba2=='*'){
				arriba2=arriba2;
				arriba1='@';
				jugador='.';
				ff=ff-1;
			}
			else if (arriba2=='#'){
				arriba2=arriba2;
				arriba1='@';
				jugador='.';
				ff=ff-1;
			}
			else if (arriba2==' '){
				arriba2=arriba2;
				arriba1='@';
				jugador='.';
				ff=ff-1;
			}
		}
	}
}
void abajo (char &jug, char &abajo1, char &abajo2, int &fi, int &cont){
	cont+=1;
	if (jug=='@'){
		if (abajo1=='$'){
			if (abajo2=='.'){
				abajo2='*';
				abajo1='@';
				jug=' ';
				fi=fi+1;
			}
			else if (abajo2=='*'){
				abajo2=abajo2;
				abajo1=abajo1;
				jug=jug;
			}
			else if (abajo2=='$'){
				abajo2=abajo2;
				abajo1=abajo1;
				jug=jug;
			}
			else if (abajo2=='#'){
				abajo2=abajo2;
				abajo1=abajo1;
				jug=jug;
			}
			else if (abajo2==' '){
				abajo2='$';
				abajo1='@';
				jug=' ';
				fi=fi+1;
			}
		}
		else if (abajo1=='.'){
			if (abajo2=='.'){
				abajo2=abajo2;
				abajo1='+';
				jug=' ';
				fi=fi+1;
			}
			else if (abajo2=='*'){
				abajo2=abajo2;
				abajo1='+';
				jug=' ';
				fi=fi+1;
			}
			else if (abajo2=='$'){
				abajo2=abajo2;
				abajo1='+';
				jug=' ';
				fi=fi+1;
			}
			else if (abajo2=='#'){
				abajo2=abajo2;
				abajo1='+';
				jug=' ';
				fi=fi+1;
			}
			else if (abajo2==' '){
				abajo2=abajo2;
				abajo1='+';
				jug=' ';
				fi=fi+1;
			}
		}
		else if (abajo1=='*'){
			if (abajo2=='.'){
				abajo2='*';
				abajo1='+';
				jug=' ';
				fi=fi+1;
			}
			else if (abajo2=='*'){
				abajo2=abajo2;
				abajo1=abajo1;
				jug=jug;
			}
			else if (abajo2=='$'){
				abajo2=abajo2;
				abajo1=abajo1;
				jug=jug;
			}
			else if (abajo2=='#'){
				abajo2=abajo2;
				abajo1=abajo1;
				jug=jug;
			}
			else if (abajo2==' '){
				abajo2='$';
				abajo1='+';
				jug=' ';
				fi=fi+1;
			}
		}
		else if (abajo1==' '){
			abajo1='@';
			jug=' ';
			fi=fi+1;
		}
		else if (abajo1=='#'){
			abajo1=abajo1;
			jug=jug;
		}
	}
	else if (jug=='+'){
		if (abajo1=='$'){
			if (abajo2=='$'){
				abajo1=abajo1;
				abajo2=abajo2;
				jug=jug;
			}
			else if (abajo2=='.'){
				abajo2='*';
				abajo1='@';
				jug='.';
				fi=fi+1;
			}
			else if (abajo2=='*'){
				abajo1=abajo1;
				abajo2=abajo2;
				jug=jug;
			}
			else if (abajo2=='#'){
				abajo1=abajo1;
				abajo2=abajo2;
				jug=jug;
			}
			else if (abajo2==' '){
				abajo2='$';
				abajo1='@';
				jug='.';
				fi=fi+1;
			}
		}
		else if (abajo1=='.'){
			if (abajo2=='$'){
				abajo1='+';
				jug='.';
				fi=fi+1;
			}
			else if (abajo2=='.'){
				abajo1='+';
				jug='.';
				fi=fi+1;
			}
			else if (abajo2=='*'){
				abajo1='+';
				jug='.';
				fi=fi+1;
			}
			else if (abajo2=='#'){
				abajo1='+';
				jug='.';
				fi=fi+1;
			}
			else if (abajo2==' '){
				abajo1='+';
				jug='.';
				fi=fi+1;

			}
		}
		else if (abajo1=='*'){
			if (abajo2=='$'){
				abajo2=abajo2;
				abajo1=abajo1;
				jug=jug;
			}
			else if (abajo2=='.'){
				abajo2='*';
				abajo1='.';
				jug='.';
				fi=fi+1;
			}
			else if (abajo2=='*'){
				abajo2=abajo2;
				abajo1=abajo1;
				jug=jug;
			}
			else if (abajo2=='#'){
				abajo2=abajo2;
				abajo1=abajo1;
				jug=jug;
			}
			else if (abajo2==' '){
				abajo2='$';
				abajo1='+';
				jug='.';
				fi=fi+1;
			}
		}
		else if (abajo1=='#'){
			if (abajo2=='$'){
				abajo2=abajo2;
				abajo1=abajo1;
				jug=jug;
			}
			else if (abajo2=='.'){
				abajo2=abajo2;
				abajo1=abajo1;
				jug=jug;
			}
			else if (abajo2=='*'){
				abajo2=abajo2;
				abajo1=abajo1;
				jug=jug;
			}
			else if (abajo2=='#'){
				abajo2=abajo2;
				abajo1=abajo1;
				jug=jug;
			}
			else if (abajo2==' '){
				abajo2=abajo2;
				abajo1=abajo1;
				jug=jug;
			}
		}
		else if (abajo1==' '){
			if (abajo2=='$'){
				abajo2=abajo2;
				abajo1='@';
				jug='.';
				fi=fi+1;
			}
			else if (abajo2=='.'){
				abajo2=abajo2;
				abajo1='@';
				jug='.';
				fi=fi+1;
			}
			else if (abajo2=='*'){
				abajo2=abajo2;
				abajo1='@';
				jug='.';
				fi=fi+1;
			}
			else if (abajo2=='#'){
				abajo2=abajo2;
				abajo1='@';
				jug='.';
				fi=fi+1;
			}
			else if (abajo2==' '){
				abajo2=abajo2;
				abajo1='@';
				jug='.';
				fi=fi+1;
			}
		}
	}
}
void izquierda (char &juga, char &izquierda1, char &izquierda2, int &cc, int &cont){
	cont+=1;
	if (juga=='@'){
		if (izquierda1=='$'){
			if (izquierda2=='.'){
				izquierda2='*';
				izquierda1='@';
				juga=' ';
				cc=cc-1;
			}
			else if (izquierda2=='*'){
				izquierda2=izquierda2;
				izquierda1=izquierda1;
				juga=juga;
			}
			else if (izquierda2=='$'){
				izquierda2=izquierda2;
				izquierda1=izquierda1;
				juga=juga;
			}
			else if (izquierda2=='#'){
				izquierda2=izquierda2;
				izquierda1=izquierda1;
				juga=juga;
			}
			else if (izquierda2==' '){
				izquierda2='$';
				izquierda1='@';
				juga=' ';
				cc=cc-1;
			}
		}
		else if (izquierda1=='.'){
			if (izquierda2=='.'){
				izquierda2=izquierda2;
				izquierda1='+';
				juga=' ';
				cc=cc-1;
			}
			else if (izquierda2=='*'){
				izquierda2=izquierda2;
				izquierda1='+';
				juga=' ';
				cc=cc-1;
			}
			else if (izquierda2=='$'){
				izquierda2=izquierda2;
				izquierda1='+';
				juga=' ';
				cc=cc-1;
			}
			else if (izquierda2=='#'){
				izquierda2=izquierda2;
				izquierda1='+';
				juga=' ';
				cc=cc-1;
			}
			else if (izquierda2==' '){
				izquierda2=izquierda2;
				izquierda1='+';
				juga=' ';
				cc=cc-1;
			}
		}
		else if (izquierda1=='*'){
			if (izquierda2=='.'){
				izquierda2='*';
				izquierda1='+';
				juga=' ';
				cc=cc-1;
			}
			else if (izquierda2=='*'){
				izquierda2=izquierda2;
				izquierda1=izquierda1;
				juga=juga;
			}
			else if (izquierda2=='$'){
				izquierda2=izquierda2;
				izquierda1=izquierda1;
				juga=juga;
			}
			else if (izquierda2=='#'){
				izquierda2=izquierda2;
				izquierda1=izquierda1;
				juga=juga;
			}
			else if (izquierda2==' '){
				izquierda2='$';
				izquierda1='+';
				juga=' ';
				cc=cc-1;
			}
		}
		else if (izquierda1==' '){
			izquierda1='@';
			juga=' ';
			cc=cc-1;
		}
		else if (izquierda1=='#'){
			izquierda1=izquierda1;
			juga=juga;
		}
	}
	else if (juga=='+'){
		if (izquierda1=='$'){
			if (izquierda2=='$'){
				izquierda1=izquierda1;
				izquierda2=izquierda2;
				juga=juga;
			}
			else if (izquierda2=='.'){
				izquierda2='*';
				izquierda1='@';
				juga='.';
				cc=cc-1;
			}
			else if (izquierda2=='*'){
				izquierda1=izquierda1;
				izquierda2=izquierda2;
				juga=juga;
			}
			else if (izquierda2=='#'){
				izquierda1=izquierda1;
				izquierda2=izquierda2;
				juga=juga;
			}
			else if (izquierda2==' '){
				izquierda2='$';
				izquierda1='@';
				juga='.';
				cc=cc-1;
			}
		}
		else if (izquierda1=='.'){
			if (izquierda2=='$'){
				izquierda1='+';
				juga='.';
				cc=cc-1;
			}
			else if (izquierda2=='.'){
				izquierda1='+';
				juga='.';
				cc=cc-1;
			}
			else if (izquierda2=='*'){
				izquierda1='+';
				juga='.';
				cc=cc-1;
			}
			else if (izquierda2=='#'){
				izquierda1='+';
				juga='.';
				cc=cc-1;
			}
			else if (izquierda2==' '){
				izquierda1='+';
				juga='.';
				cc=cc-1;
			}
		}
		else if (izquierda1=='*'){
			if (izquierda2=='$'){
				izquierda2=izquierda2;
				izquierda1=izquierda1;
				juga=juga;
			}
			else if (izquierda2=='.'){
				izquierda2='*';
				izquierda1='.';
				juga='.';
				cc=cc-1;
			}
			else if (izquierda2=='*'){
				izquierda2=izquierda2;
				izquierda1=izquierda1;
				juga=juga;
			}
			else if (izquierda2=='#'){
				izquierda2=izquierda2;
				izquierda1=izquierda1;
				juga=juga;
			}
			else if (izquierda2==' '){
				izquierda2='$';
				izquierda1='+';
				juga='.';
				cc=cc-1;
			}
		}
		else if (izquierda1=='#'){
			if (izquierda2=='$'){
				izquierda2=izquierda2;
				izquierda1=izquierda1;
				juga=juga;
			}
			else if (izquierda2=='.'){
				izquierda2=izquierda2;
				izquierda1=izquierda1;
				juga=juga;
			}
			else if (izquierda2=='*'){
				izquierda2=izquierda2;
				izquierda1=izquierda1;
				juga=juga;
			}
			else if (izquierda2=='#'){
				izquierda2=izquierda2;
				izquierda1=izquierda1;
				juga=juga;
			}
			else if (izquierda2==' '){
				izquierda2=izquierda2;
				izquierda1=izquierda1;
				juga=juga;
			}
		}
		else if (izquierda1==' '){
			if (izquierda2=='$'){
				izquierda2=izquierda2;
				izquierda1='@';
				juga='.';
				cc=cc-1;
			}
			else if (izquierda2=='.'){
				izquierda2=izquierda2;
				izquierda1='@';
				juga='.';
				cc=cc-1;
			}
			else if (izquierda2=='*'){
				izquierda2=izquierda2;
				izquierda1='@';
				juga='.';
				cc=cc-1;
			}
			else if (izquierda2=='#'){
				izquierda2=izquierda2;
				izquierda1='@';
				juga='.';
				cc=cc-1;
			}
			else if (izquierda2==' '){
				izquierda2=izquierda2;
				izquierda1='@';
				juga='.';
				cc=cc-1;
			}
		}
	}
}
void derecha (char &jugd, char &derecha1, char &derecha2, int &co, int &cont){
	cont+=1;
	if (jugd=='@'){
		if (derecha1=='$'){
			if (derecha2=='.'){
				derecha2='*';
				derecha1='@';
				jugd=' ';
				co=co+1;
			}
			else if (derecha2=='*'){
				derecha2=derecha2;
				derecha1=derecha1;
				jugd=jugd;
			}
			else if (derecha2=='$'){
				derecha2=derecha2;
				derecha1=derecha1;
				jugd=jugd;
			}
			else if (derecha2=='#'){
				derecha2=derecha2;
				derecha1=derecha1;
				jugd=jugd;
			}
			else if (derecha2==' '){
				derecha2='$';
				derecha1='@';
				jugd=' ';
				co=co+1;
			}
		}
		else if (derecha1=='.'){
			if (derecha2=='.'){
				derecha2=derecha2;
				derecha1='+';
				jugd=' ';
				co=co+1;
			}
			else if (derecha2=='*'){
				derecha2=derecha2;
				derecha1='+';
				jugd=' ';
				co=co+1;
			}
			else if (derecha2=='$'){
				derecha2=derecha2;
				derecha1='+';
				jugd=' ';
				co=co+1;
			}
			else if (derecha2=='#'){
				derecha2=derecha2;
				derecha1='+';
				jugd=' ';
				co=co+1;
			}
			else if (derecha2==' '){
				derecha2=derecha2;
				derecha1='+';
				jugd=' ';
				co=co+1;
			}
		}
		else if (derecha1=='*'){
			if (derecha2=='.'){
				derecha2='*';
				derecha1='+';
				jugd=' ';
				co=co+1;
			}
			else if (derecha2=='*'){
				derecha2=derecha2;
				derecha1=derecha1;
				jugd=jugd;
			}
			else if (derecha2=='$'){
				derecha2=derecha2;
				derecha1=derecha1;
				jugd=jugd;
			}
			else if (derecha2=='#'){
				derecha2=derecha2;
				derecha1=derecha1;
				jugd=jugd;
			}
			else if (derecha2==' '){
				derecha2='$';
				derecha1='+';
				jugd=' ';
				co=co+1;
			}
		}
		else if (derecha1==' '){
			derecha1='@';
			jugd=' ';
			co=co+1;
		}
		else if (derecha1=='#'){
			derecha1=derecha1;
			jugd=jugd;
		}
	}
	else if (jugd=='+'){
		if (derecha1=='$'){
			if (derecha2=='$'){
				derecha1=derecha1;
				derecha2=derecha2;
				jugd=jugd;
			}
			else if (derecha2=='.'){
				derecha2='*';
				derecha1='@';
				jugd='.';
				co=co+1;
			}
			else if (derecha2=='*'){
				derecha1=derecha1;
				derecha2=derecha2;
				jugd=jugd;
			}
			else if (derecha2=='#'){
				derecha1=derecha1;
				derecha2=derecha2;
				jugd=jugd;
			}
			else if (derecha2==' '){
				derecha2='$';
				derecha1='@';
				jugd='.';
				co=co+1;
			}
		}
		else if (derecha1=='.'){
			if (derecha2=='$'){
				derecha1='+';
				jugd='.';
				co=co+1;
			}
			else if (derecha2=='.'){
				derecha1='+';
				jugd='.';
				co=co+1;
			}
			else if (derecha2=='*'){
				derecha1='+';
				jugd='.';
				co=co+1;
			}
			else if (derecha2=='#'){
				derecha1='+';
				jugd='.';
				co=co+1;
			}
			else if (derecha2==' '){
				derecha1='+';
				jugd='.';
				co=co+1;

			}
		}
		else if (derecha1=='*'){
			if (derecha2=='$'){
				derecha2=derecha2;
				derecha1=derecha1;
				jugd=jugd;
			}
			else if (derecha2=='.'){
				derecha2='*';
				derecha1='.';
				jugd='.';
				co=co+1;
			}
			else if (derecha2=='*'){
				derecha2=derecha2;
				derecha1=derecha1;
				jugd=jugd;
			}
			else if (derecha2=='#'){
				derecha2=derecha2;
				derecha1=derecha1;
				jugd=jugd;
			}
			else if (derecha2==' '){
				derecha2='$';
				derecha1='+';
				jugd='.';
				co=co+1;
			}
		}
		else if (derecha1=='#'){
			if (derecha2=='$'){
				derecha2=derecha2;
				derecha1=derecha1;
				jugd=jugd;
			}
			else if (derecha2=='.'){
				derecha2=derecha2;
				derecha1=derecha1;
				jugd=jugd;
			}
			else if (derecha2=='*'){
				derecha2=derecha2;
				derecha1=derecha1;
				jugd=jugd;
			}
			else if (derecha2=='#'){
				derecha2=derecha2;
				derecha1=derecha1;
				jugd=jugd;
			}
			else if (derecha2==' '){
				derecha2=derecha2;
				derecha1=derecha1;
				jugd=jugd;
			}
		}
		else if (derecha1==' '){
			if (derecha2=='$'){
				derecha2=derecha2;
				derecha1='@';
				jugd='.';
				co=co+1;
			}
			else if (derecha2=='.'){
				derecha2=derecha2;
				derecha1='@';
				jugd='.';
				co=co+1;
			}
			else if (derecha2=='*'){
				derecha2=derecha2;
				derecha1='@';
				jugd='.';
				co=co+1;
			}
			else if (derecha2=='#'){
				derecha2=derecha2;
				derecha1='@';
				jugd='.';
				co=co+1;
			}
			else if (derecha2==' '){
				derecha2=derecha2;
				derecha1='@';
				jugd='.';
				co=co+1;
			}
		}
	}
}
int main() {
	int opcion, fila=1, columna=5, contador=0;
	char devolver, movimiento;
	bool j=true, k=true, l=true;
	char tablero_jugar[12][14]={
		{' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' '}
		,{'#','#','#','#','#','@',' ','#','#','#','#',' ',' ',' '}
		,{'#',' ',' ',' ','#','#',' ',' ',' ',' ','#',' ',' ',' '}
		,{'#',' ','$','#','#','#',' ',' ','$',' ','#','#','#','#'}
		,{'#',' ',' ',' ',' ','#','#','#','$','$',' ',' ',' ','#'}
		,{'#','#','.','.',' ',' ',' ',' ',' ',' ','$',' ',' ','#'}
		,{' ','#','.','.','#',' ',' ',' ',' ','#','#','#',' ','#'}
		,{' ','#','#','#','#','#','#',' ',' ',' ','#',' ',' ','#'}
		,{' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','#'}
		,{' ',' ',' ',' ',' ',' ','#','#',' ',' ','.',' ','#','#'}
		,{' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ','#',' '}
		,{' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' '}
		};
	menu(opcion);
	while(opcion!=4){
		switch(opcion){
		case 1:
			cout << "Utilice las Flechas del Teclado Para desplazarse dentro del Tablero" << endl
			     << "Para Reiniciar el Nivel Ingrese la Tecla R unicamente" << endl
			     << "Para retornar al Menu Principal Ingrese la Tecla M unicamente " << endl
			     << "Para salir del juego presione ESC" << endl;
			cout << "Para contar movimientos presione C unicamente" << endl;
			l=true;
			while(l==true){
		        do
		        {
					for(int cont=0; cont<12; cont++){
						cout<<"\n";
						for(int cont2=0; cont2<14; cont2++){
							cout << tablero_jugar[cont][cont2];
						}
					}
		            movimiento=getch();
		            if (movimiento == 72){
		            	arriba(tablero_jugar[fila][columna], tablero_jugar[fila-1][columna], tablero_jugar[fila-2][columna], fila, contador);
		            }
		            if (movimiento == 75){
		            	izquierda(tablero_jugar[fila][columna], tablero_jugar[fila][columna-1], tablero_jugar[fila][columna-2], columna, contador);
		            }
		            if (movimiento == 80){
		            	abajo(tablero_jugar[fila][columna], tablero_jugar[fila+1][columna], tablero_jugar[fila+2][columna], fila, contador);
		            }
		            if (movimiento == 77){
		            	derecha(tablero_jugar[fila][columna], tablero_jugar[fila][columna+1], tablero_jugar[fila][columna+2], columna, contador);
		            }
		            if (movimiento == 27){
		            	l=false;
		            	opcion=4;
		            	cin.ignore(1024, '\n');
            			cout << "Press enter to continue...";
           				cin.get();
		            }
		            if (movimiento == 109){
		            	menu(opcion);
		            	l=false;
		            	break;
		            }
		            if (movimiento == 114){
		            	reinicio2(fila,columna);
		            	for (int c=0;c<12;c++){
		            		for(int d=0;d<14;d++){
		            			tablero_jugar[c][d]=reinicio(c,d);
		            		}
		            	}
		            }
		            if (movimiento==67){
		            	cout << endl << "Usted lleva " << contador << "movimientos";
		            }
		        }
		        while (movimiento!=27);
			}
			break;
		case 2:
			cout << "Sokoban  significa en japones empujador, y  suele traducirse al ingles como" << endl
			     << "warehouse  keeper (algo parecido a  encargado de almacen).  Pero ante todo," << endl
			     << "Sokoban es el nombre de un juego de computadora, creado en los años 80, y que" << endl
			     << "gano un concurso de  programacion. La idea del juego es  sencilla y genial, y" << endl
			     << "se trata en realidad  de un genero nuevo (entonces) de rompecabezas. Consiste" << endl
			     << "en manejar a un hombrecillo a traves de la pantalla, haciendo que empuje unas" << endl
			     << "cajas  hasta  situarlas en ciertos  puntos  de destino. Las  reglas  son bien" << endl
			     << "simples:" << endl << endl;
			cout << "          * Para empujar, el personaje debe estar detras de la caja. No se puede" << endl
			     << "            empujar de lado ni tirar." << endl;
			cout << "          * No se puede empujar dos cajas a la vez (pesan demasiado)." << endl;
			cout << "          * El hombrecillo no puede subirse a las cajas para abrirse camino," << endl
			     << "            debe pasar limpiamente entre ellas y las paredes." << endl << endl;
			while (j==true){
				cout << "Para volver al menu principal presione 'r'";
				cin >> devolver;
				if(devolver=='r'||devolver=='R'){
					j=false;
				}
			}
			j=true;
			menu(opcion);
			break;
		case 3:
			cout << "Los siguientes Movimientos son una de las posibles Soluciones al Tablero" << endl
			     << "Existen mas opciones posibles" << endl << endl;
			cout << "CAJA 1:" << endl
			     << "Derecha, Abajo, Derecha(3), Abajo, Izquierda. Abajo(4), Izquierda, Abajo," << endl
			     << "Derecha, Arriba, Derecha, Abajo, Izquierda, Abajo, Derecha" << endl << endl
			     << "CAJA 2:" << endl
			     << "Arriba, Izquierda(2), Arriba(3),Izquierda(5), Arriba, Izquierda, Arriba(2)," << endl
			     << "Derecha, Abajo(3)" << endl << endl
			     << "CAJA 3:" << endl
			     << "Derecha(8), Arriba, Derecha(2), Abajo, Izquierda(9)"<< endl << endl
			     << "CAJA 4:" << endl
			     << "Derecha(5), Arriba(2), Derecha, Abajo, Derecha, Abajo, Izquierda(6), Arriba," << endl
			     << "Izquierda, Abajo" << endl << endl
			     << "CAJA 5:" << endl
			     << "Derecha(5), Arriba(3), Izquierda(2), Abajo, Derecha, Arriba, Derecha, Abajo(2)," << endl
			     << "Derecha, Abajo, Izquierda(5)" << endl << endl;
			while (k==true){
				cout << "Para volver al menu principal presione 'r'";
				cin >> devolver;
				if(devolver=='r'||devolver=='R'){
					k=false;
				}
			}
			k=true;
			menu(opcion);
			break;
		default:
			cin.ignore(1024, '\n');
            cout << "Press enter to continue...";
            cin.get();
			break;
		}
	}
    cin.ignore(1024, '\n');
    cout << "Press enter to continue...";
    cin.get();
	return 0;
}
