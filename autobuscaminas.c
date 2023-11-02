/*
Usaremos vectores para representar matrices porque si entiendes bien el tamaño de un vector y no vas a hacer operaciones de matrizes no hay mucha diferencia
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Returns value of Binomial Coefficient C(n, k)
double binomialCoeff(int n, int k)
{
    // Base Cases
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
 
    // Recur
    return binomialCoeff(n - 1, k - 1)
           + binomialCoeff(n - 1, k);
}

/*
funcion que muestra la pantalla si le damos la matriz que describe el estado de juego al completo como numericos
(las bombas elementos que son mas grandes o igual a 9 ), tambien nos da una cuandricula para saber en que cordenada esta cada elemento
*/
void mostrarestadoR(int resultados[],int x,int y){
    int i,j;
    printf("    ") ;
    /*    mostramos el numero de columnas que hay luego ponemos una linia para separar el mapa  del numero de columnas, hacemos lo mismo con el de filas, forzamos a que 
    todos los numeros tengan la misma largada para que quede bien cuadrado tambien ponemos el numero de que nos viene en la matriz en la cordenada concreta  */
    for(i=0;i<y;i++){
       printf("%3i",i) ;
    }
    printf("\n") ;
    for(i=-1;i<=3*y;i++){
       printf("_") ;
    }
    printf("\n") ;
    for(i=0;i<x;i++){
        printf("%3i|",i); 
        for(j=0;j<y;j++){
           printf("%3i",resultados[i*(y)+j]);

        }
        printf("\n");
    }

}
/*
funcion que muestra la probabilidad de que un cuadrado sea bomba
*/
void mostrarprob(double resultados[],int x,int y){
    int i,j;
    printf("    ") ;
    /*    mostramos el numero de columnas que hay luego ponemos una linia para separar el mapa  del numero de columnas, hacemos lo mismo con el de filas, forzamos a que 
    todos los numeros tengan la misma largada para que quede bien cuadrado tambien ponemos el numero de que nos viene en la matriz en la cordenada concreta  */
    for(i=0;i<y;i++){
       printf("%3i",i) ;
    }
    printf("\n") ;
    for(i=-1;i<=3*y;i++){
       printf("_") ;
    }
    printf("\n") ;
    for(i=0;i<x;i++){
        printf("%3i|",i); 
        for(j=0;j<y;j++){
           printf("%f",resultados[i*(y)+j]);

        }
        printf("\n");
    }

}

/*
funcion que muestra la pantalla que veria el jugador indicando con '#' las casillas 
de incognita , con 'x'las bombas marcadas por el jugador y con 'B' bombas si se revelaran
y como de grande es la matriz
*/
void mostrarpantalla(char resultados[],int x,int y){
    int i,j;
     printf("    ") ;
     /*    mostramos el numero de columnas que hay luego ponemos una linia para separar el mapa  del numero de columnas, hacemos lo mismo con el de filas, forzamos a que 
    todos los numeros tengan la misma largada para que quede bien cuadrado tambien ponemos el caracter de que nos viene en la matriz en la cordenada concreta  */
    for(i=0;i<y;i++){
       printf("%3i",i) ;
    }
    printf("\n") ;
    for(i=-1;i<=3*y;i++){
       printf("_") ;
    }
    printf("\n") ;
    for(i=0;i<x;i++){
        printf("%3i|",i); 
        for(j=0;j<y;j++){
           printf("%3c",resultados[i*(y)+j]);

        }
        printf("\n");
    }

}
/*
funcion que calcula en que parte de la matriz esta una posicion, si esta en una esquina o en un borde
o en el centro para saber donde tiene elementos contiguos
*/
int calcularpos(int pos,int x,int y){
    int lug;
    if(pos==0){
            lug=0;
        }
        else if(pos==(y-1)){
            lug=1;
        }
        else if(pos==(y*(x-1))){
            lug=2;
        }
        else if(pos==((y*x)-1)){
            lug=3;
        }
        else if (pos<y){
            lug=4;
        }
        else if((pos%y)==0){
            lug=5;
        }
        else if(((pos+1)%y)==0){
           lug=6;
        }
        else if (pos>y*(x-1)){
           lug=7;
        }
        else{
            lug=8;
        }
    return(lug);
}
/*
funcion genera un mapa aleatoriamente y lo pone en el vector resultados, para ello le damos x el numero de columnas, y el numero de filas 
unas cordenadas p1 , p2 que seran las primeras que revelaremos por lo que no pondremos una bomba en este o en su alrededor para tener 
espacio al principio y b que sera el numero de bombas que pondremos

*/
void crearmapa(int resultados[],int x, int y , int p1,int p2 ,int b){
    int i,pos,lug;
    /*inicializamos el vector como 0*/
    for(i=0;i<x*y;i++){
    resultados[i]=0;
    
    }
    i=0;
    /*añadimos bombas en una posicion aleatoria en la cual no haya una bomba ni sea la posicion inicial
     hasta que lleguemos al numero deseado y sumamos 1 a los puntos de alrededor para saber cuantas bombas tiene */
   while(i<b){
        pos=rand() % ((x)*(y));
        if(resultados[pos]<9&&pos!=(p1*y+p2)&&pos!=(p1*y+p2+1)&&pos!=(p1*y+p2-1)&&pos!=((p1+1)*y+p2)&&pos!=((p1-1)*y+p2)&&pos!=((p1+1)*y+p2+1)&&pos!=((p1+1)*y+p2-1)&&pos!=((p1-1)*y+p2+1)&&pos!=((p1-1)*y+p2-1)){
            resultados[pos]=9;
            i=i+1;
            lug=calcularpos(pos,x,y);
            if(lug==0){
                resultados[pos+1]=resultados[pos+1]+1 ;
                resultados[pos+y]=resultados[pos+y]+1 ;
                resultados[pos+1+y]=resultados[pos+1+y]+1;
            }
            else if(lug==1){
                resultados[pos-1]=resultados[pos-1]+1 ;
                resultados[pos+y]=resultados[pos+y]+1 ;
                resultados[pos+y-1]=resultados[pos+y-1]+1 ;
            }
            else if(lug==2){
                resultados[pos+1]=resultados[pos+1]+1 ;
                resultados[pos-y]=resultados[pos-y]+1 ;
                resultados[pos-y+1]=resultados[pos-y+1]+1 ;
            }
            else if(lug==3){
                resultados[pos-1]=resultados[pos-1]+1 ;
                resultados[pos-y]=resultados[pos-y]+1 ;
                resultados[pos-y-1]=resultados[pos-y-1]+1 ;
            }
            else if (lug==4){
                resultados[pos+1]=resultados[pos+1]+1 ;
                resultados[pos-1]=resultados[pos-1]+1 ;
                resultados[pos+y]=resultados[pos+y]+1 ;
                resultados[pos+y+1]=resultados[pos+y+1]+1 ;
                resultados[pos+y-1]=resultados[pos+y-1]+1 ;
            }
            else if(lug==5){
                resultados[pos+1]=resultados[pos+1]+1 ;
                resultados[pos+y]=resultados[pos+y]+1 ;
                resultados[pos-y]=resultados[pos-y]+1 ;
                resultados[pos+y+1]=resultados[pos+y+1]+1 ;
                resultados[pos-y+1]=resultados[pos-y+1]+1 ;
            }
            else if(lug==6){
                resultados[pos-1]=resultados[pos-1]+1 ;
                resultados[pos+y]=resultados[pos+y]+1 ;
                resultados[pos-y]=resultados[pos-y]+1 ;
                resultados[pos+y-1]=resultados[pos+y-1]+1 ;
                resultados[pos-y-1]=resultados[pos-y-1]+1 ;
            }
            else if (lug==7){
                resultados[pos+1]=resultados[pos+1]+1 ;
                resultados[pos-1]=resultados[pos-1]+1 ;
                resultados[pos-y]=resultados[pos-y]+1 ;
                resultados[pos-y+1]=resultados[pos-y+1]+1 ;
                resultados[pos-y-1]=resultados[pos-y-1]+1 ;
            }
            else{
                resultados[pos+1]=resultados[pos+1]+1 ;
                resultados[pos-1]=resultados[pos-1]+1 ;
                resultados[pos-y]=resultados[pos-y]+1 ;
                resultados[pos-y+1]=resultados[pos-y+1]+1 ;
                resultados[pos-y-1]=resultados[pos-y-1]+1 ;
                resultados[pos+y]=resultados[pos+y]+1 ;
                resultados[pos+y+1]=resultados[pos+y+1]+1 ;
                resultados[pos+y-1]=resultados[pos+y-1]+1 ;
            }
        }
        
         
        
    }
}
/*
funcion que revela que habia en la matriz resultados a la matriz visualizacion
*/
int revelar(int p1,int p2, int x,int y ,char vis[],int resultados[], int numreal[] ){

    int lug,pos,temp,cantidad_bombas;
    pos=p1*y+p2;
    temp=resultados[pos];
    /*si ya esta revelada ya estamos*/
    if(vis[pos]!='#'){

        return(0);
    }
    /*si lo que revelamos es un 0 revelamos tambien los del alrededor ya que seguro que no son bombas                                                        */
    if(temp==0){ 
        vis[pos]=' ';
        numreal[pos]=0;    
        lug=calcularpos(pos,x,y);           
        if(lug==0){
            if(vis[p2+1+p1*y]!=' '){
                revelar(p1,p2+1,x,y,vis,resultados,numreal);
            }
            if(vis[p2+(p1+1)*y]!=' '){
                revelar(p1+1,p2,x,y,vis,resultados,numreal);
            }
            if(vis[p2+1+(p1+1)*y]!=' '){
                revelar(p1+1,p2+1,x,y,vis,resultados,numreal);
            } 
        }
        else if(lug==1){
            if(vis[p2-1+p1*y]!=' '){
                revelar(p1,p2-1,x,y,vis,resultados,numreal);
            }
            if(vis[p2+(p1+1)*y]!=' '){
                revelar(p1+1,p2,x,y,vis,resultados,numreal);
            }
            if(vis[p2-1+(p1+1)*y]!=' '){
               revelar(p1+1,p2-1,x,y,vis,resultados,numreal);
            } 
        }
        else if(lug==2){
            if(vis[p2+1+p1*y]!=' '){
                revelar(p1,p2+1,x,y,vis,resultados,numreal);
            }
            if(vis[p2+(p1-1)*y]!=' '){
                revelar(p1-1,p2,x,y,vis,resultados,numreal);
            }
            if(vis[p2+1+(p1-1)*y]!=' '){
                revelar(p1-1,p2+1,x,y,vis,resultados,numreal);
            }
        }
        else if(lug==3){
            if(vis[p2-1+p1*y]!=' '){
                revelar(p1,p2-1,x,y,vis,resultados,numreal);
            }
            if(vis[p2+(p1-1)*y]!=' '){
                revelar(p1-1,p2,x,y,vis,resultados,numreal);
            }
            if(vis[p2-1+(p1-1)*y]!=' '){
                revelar(p1-1,p2-1,x,y,vis,resultados,numreal);
            }
        }
        else if (lug==4){
            if(vis[p2+1+p1*y]!=' '){
                revelar(p1,p2+1,x,y,vis,resultados,numreal);
            }
            if(vis[p2-1+p1*y]!=' '){
                revelar(p1,p2-1,x,y,vis,resultados,numreal);
            }
            if(vis[p2+(p1+1)*y]!=' '){
                revelar(p1+1,p2,x,y,vis,resultados,numreal);
            }
            if(vis[p2-1+(p1+1)*y]!=' '){
                revelar(p1+1,p2-1,x,y,vis,resultados,numreal);
            }
            if(vis[p2+1+(p1+1)*y]!=' '){
                revelar(p1+1,p2+1,x,y,vis,resultados,numreal);
            }
        }
        else if(lug==5){
            if(vis[p2+1+p1*y]!=' '){
                revelar(p1,p2+1,x,y,vis,resultados,numreal);
            }
            if(vis[p2+(p1+1)*y]!=' '){
                revelar(p1+1,p2,x,y,vis,resultados,numreal);
            }
            if(vis[p2+(p1-1)*y]!=' '){
                revelar(p1-1,p2,x,y,vis,resultados,numreal);
            }
            if(vis[p2+1+(p1+1)*y]!=' '){
               revelar(p1+1,p2+1,x,y,vis,resultados,numreal);
            } 
            if(vis[p2+1+(p1-1)*y]!=' '){
                revelar(p1-1,p2+1,x,y,vis,resultados,numreal);
            }
        }
        else if(lug==6){
            if(vis[p2-1+p1*y]!=' '){
                revelar(p1,p2-1,x,y,vis,resultados,numreal);
            }
            if(vis[p2+(p1+1)*y]!=' '){
                revelar(p1+1,p2,x,y,vis,resultados,numreal);
            }
            if(vis[p2+(p1-1)*y]!=' '){
                revelar(p1-1,p2,x,y,vis,resultados,numreal);
            }
            if(vis[p2-1+(p1+1)*y]!=' '){
                revelar(p1+1,p2-1,x,y,vis,resultados,numreal);
            }
            if(vis[p2-1+(p1-1)*y]!=' '){
                revelar(p1-1,p2-1,x,y,vis,resultados,numreal);
            }
        }
        else if (lug==7){
            if(vis[p2-1+p1*y]!=' '){
                revelar(p1,p2-1,x,y,vis,resultados,numreal);
            }
            if(vis[p2+1+p1*y]!=' '){
                revelar(p1,p2+1,x,y,vis,resultados,numreal);
            }
            if(vis[p2+(p1-1)*y]!=' '){
                revelar(p1-1,p2,x,y,vis,resultados,numreal);
            }
            if(vis[p2+1+(p1-1)*y]!=' '){
                revelar(p1-1,p2+1,x,y,vis,resultados,numreal);
            }
            if(vis[p2-1+(p1-1)*y]!=' '){
                revelar(p1-1,p2-1,x,y,vis,resultados,numreal);
            } 
        }
        else{
            if(vis[p2-1+p1*y]!=' '){
                revelar(p1,p2-1,x,y,vis,resultados,numreal);
            }
            if(vis[p2+1+p1*y]!=' '){
                revelar(p1,p2+1,x,y,vis,resultados,numreal);
            }
            if(vis[p2+(p1+1)*y]!=' '){
                revelar(p1+1,p2,x,y,vis,resultados,numreal);
            }
            if(vis[p2+1+(p1+1)*y]!=' '){
               revelar(p1+1,p2+1,x,y,vis,resultados,numreal);
            }
            if(vis[p2-1+(p1+1)*y]!=' '){
                revelar(p1+1,p2-1,x,y,vis,resultados,numreal);
            }
            if(vis[p2+(p1-1)*y]!=' '){
            revelar(p1-1,p2,x,y,vis,resultados,numreal);
            }
            if(vis[p2+1+(p1-1)*y]!=' '){
                revelar(p1-1,p2+1,x,y,vis,resultados,numreal);
            }
             if(vis[p2-1+(p1-1)*y]!=' '){
                revelar(p1-1,p2-1,x,y,vis,resultados,numreal);
            }
        }
    return(0);
    }
    else if(temp<9){
        vis[p2+p1*y]=resultados[p2+p1*y]+48;
        return(0);   
    }
    else if(temp>=9){
            vis[p2+p1*y]='B';
            
            printf("Has tocado una bomba\n");
            return(1);
    }
   return(0); 
}
/*
calcula un mapa de el numero que real que hay en una posiccion despues de restar las bombas marcadas
y otro que calcula cuantas incognitas tiene un elemento alrededor
*/
void cont( int x,int y ,char vis[],int cantinc[], int numreal[] ){
    int p1,p2,lug,pos,cantidad_bombas,temp,minas_encotradas;
	for(p1=0;p1<x;p1++){
        for(p2=0;p2<y;p2++){
			
			pos=p1*y+p2;
			temp=vis[pos]-48;
			/*printf("\n%i\n",p2+p1*y);
			mostrarpantalla(vis,x,y);*/
			
			if(temp<9&&temp>0){
				
		
				
				lug=calcularpos(pos,x,y);
				cantidad_bombas=0;
				minas_encotradas=temp;         
				if(lug==0){
					if(vis[p2+1+p1*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+(p1+1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+1+(p1+1)*y]=='#'){
						cantidad_bombas++;
					} 
					if(vis[p2+1+p1*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+(p1+1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+1+(p1+1)*y]=='x'){
						minas_encotradas--;
					}
                    if(vis[p2+1+p1*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+(p1+1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+1+(p1+1)*y]=='X'){
						minas_encotradas--;
					}
				}
				else if(lug==1){
					if(vis[p2-1+p1*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+(p1+1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2-1+(p1+1)*y]=='#'){
						cantidad_bombas++;
					} 
					if(vis[p2-1+p1*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+(p1+1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2-1+(p1+1)*y]=='x'){
						minas_encotradas--;
					} 
                    if(vis[p2-1+p1*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+(p1+1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2-1+(p1+1)*y]=='X'){
						minas_encotradas--;
					} 
				}
				else if(lug==2){
					if(vis[p2+1+p1*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+(p1-1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+1+(p1-1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+1+p1*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+(p1-1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+1+(p1-1)*y]=='x'){
						minas_encotradas--;
					}
                    if(vis[p2+1+p1*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+(p1-1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+1+(p1-1)*y]=='X'){
						minas_encotradas--;
					}
				}
				else if(lug==3){
					if(vis[p2-1+p1*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+(p1-1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2-1+(p1-1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2-1+p1*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+(p1-1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2-1+(p1-1)*y]=='x'){
						minas_encotradas--;
					}
				}
				else if (lug==4){
					if(vis[p2+1+p1*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2-1+p1*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+(p1+1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2-1+(p1+1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+1+(p1+1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+1+p1*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2-1+p1*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+(p1+1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2-1+(p1+1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+1+(p1+1)*y]=='x'){
						minas_encotradas--;
					}
                    if(vis[p2+1+p1*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2-1+p1*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+(p1+1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2-1+(p1+1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+1+(p1+1)*y]=='X'){
						minas_encotradas--;
					}
				}
				else if(lug==5){
					if(vis[p2+1+p1*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+(p1+1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+(p1-1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+1+(p1+1)*y]=='#'){
						cantidad_bombas++;
					} 
					if(vis[p2+1+(p1-1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+1+p1*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+(p1+1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+(p1-1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+1+(p1+1)*y]=='x'){
						minas_encotradas--;
					} 
					if(vis[p2+1+(p1-1)*y]=='x'){
						minas_encotradas--;
					}
                    if(vis[p2+1+p1*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+(p1+1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+(p1-1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+1+(p1+1)*y]=='X'){
						minas_encotradas--;
					} 
					if(vis[p2+1+(p1-1)*y]=='X'){
						minas_encotradas--;
                    }
					
				}
				else if(lug==6){
					if(vis[p2-1+p1*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+(p1+1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+(p1-1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2-1+(p1+1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2-1+(p1-1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2-1+p1*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+(p1+1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+(p1-1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2-1+(p1+1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2-1+(p1-1)*y]=='x'){
						minas_encotradas--;
					}
                    if(vis[p2-1+p1*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+(p1+1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+(p1-1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2-1+(p1+1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2-1+(p1-1)*y]=='X'){
						minas_encotradas--;
					}
				}
				else if (lug==7){
					if(vis[p2-1+p1*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+1+p1*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+(p1-1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+1+(p1-1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2-1+(p1-1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2-1+p1*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+1+p1*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+(p1-1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+1+(p1-1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2-1+(p1-1)*y]=='x'){
						minas_encotradas--;
					}
                    if(vis[p2-1+p1*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+1+p1*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+(p1-1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+1+(p1-1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2-1+(p1-1)*y]=='X'){
						minas_encotradas--;
					}
				}
				else{
					if(vis[p2-1+p1*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+1+p1*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+(p1+1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+1+(p1+1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2-1+(p1+1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+(p1-1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2+1+(p1-1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2-1+(p1-1)*y]=='#'){
						cantidad_bombas++;
					}
					if(vis[p2-1+p1*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+1+p1*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+(p1+1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+1+(p1+1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2-1+(p1+1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+(p1-1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2+1+(p1-1)*y]=='x'){
						minas_encotradas--;
					}
					if(vis[p2-1+(p1-1)*y]=='x'){
						minas_encotradas--;
					}
                    if(vis[p2-1+p1*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+1+p1*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+(p1+1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+1+(p1+1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2-1+(p1+1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+(p1-1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2+1+(p1-1)*y]=='X'){
						minas_encotradas--;
					}
					if(vis[p2-1+(p1-1)*y]=='X'){
						minas_encotradas--;
					}                    
				}
				if(cantidad_bombas==0){
					cantidad_bombas=-1;
				}
                

				cantinc[pos]=cantidad_bombas;
				numreal[pos]=minas_encotradas;
			}
		}
	}
    for(p1=0;p1<x*y;p1++){
        if(vis[p1]==' '){  
                            
            numreal[p1]=0;
            cantinc[p1]=-1;
        }

    }
    
    
}
/*
funcion que calcula donde es mas probable que este la bomba
*/
int donde_no_bomba_prob(int x,int y ,char vis[],int cantinc[], int numreal[] ){
    int lug,pos,temp2=0,p1,p2;   
    double temp=0,max=99999999999999;
    for(p1=0;p1<x;p1++){
        for(p2=0;p2<y;p2++){
            temp=0;
            pos=p1*y+p2;
            if(vis[pos]=='#'){
                
        
                lug=calcularpos(pos,x,y);
        		if(lug==0){
                    temp=temp+(numreal[p2+1+p1*y]*840./cantinc[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]*840./cantinc[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]*840./cantinc[p2+1+(p1+1)*y]);
				}
				else if(lug==1){
                    temp=temp+(numreal[p2-1+p1*y]*840./cantinc[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]*840./cantinc[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2-1+(p1+1)*y]*840./cantinc[p2-1+(p1+1)*y]);
                }
				else if(lug==2){
                    temp=temp+(numreal[p2+1+p1*y]*840./cantinc[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]*840./cantinc[p2+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1-1)*y]*840./cantinc[p2+1+(p1-1)*y]);
				}
				else if(lug==3){
                    temp=temp+(numreal[p2-1+p1*y]*840./cantinc[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]*840./cantinc[p2+(p1-1)*y]);
                    temp=temp+(numreal[p2-1+(p1-1)*y]*840./cantinc[p2-1+(p1-1)*y]);
					
				
				}
				else if (lug==4){
					temp=temp+(numreal[p2+1+p1*y]*840./cantinc[p2+1+p1*y]);
                    temp=temp+(numreal[p2-1+p1*y]*840./cantinc[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]*840./cantinc[p2+(p1+1)*y]);
					temp=temp+(numreal[p2-1+(p1+1)*y]*840./cantinc[p2-1+(p1+1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]*840./cantinc[p2+1+(p1+1)*y]);
				}
				else if(lug==5){
					temp=temp+(numreal[p2+1+p1*y]*840./cantinc[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]*840./cantinc[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]*840./cantinc[p2+(p1-1)*y]);
					temp=temp+(numreal[p2+1+(p1-1)*y]*840./cantinc[p2+1+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]*840./cantinc[p2+1+(p1+1)*y]);
				}
				else if(lug==6){
					temp=temp+(numreal[p2-1+p1*y]*840./cantinc[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]*840./cantinc[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]*840./cantinc[p2+(p1-1)*y]);
					temp=temp+(numreal[p2-1+(p1-1)*y]*840./cantinc[p2-1+(p1-1)*y]);
                    temp=temp+(numreal[p2-1+(p1+1)*y]*840./cantinc[p2-1+(p1+1)*y]);
				}
				else if (lug==7){
					temp=temp+(numreal[p2-1+p1*y]*840./cantinc[p2-1+p1*y]);
                    temp=temp+(numreal[p2+1+p1*y]*840./cantinc[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]*840./cantinc[p2+(p1-1)*y]);
					temp=temp+(numreal[p2-1+(p1-1)*y]*840./cantinc[p2-1+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1-1)*y]*840./cantinc[p2+1+(p1-1)*y]);
				}
				else{
					temp=temp+(numreal[p2-1+p1*y]*840./cantinc[p2-1+p1*y]);
                    temp=temp+(numreal[p2+1+p1*y]*840./cantinc[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]*840./cantinc[p2+(p1-1)*y]);
					temp=temp+(numreal[p2+(p1+1)*y]*840./cantinc[p2+(p1+1)*y]);
					temp=temp+(numreal[p2-1+(p1-1)*y]*840./cantinc[p2-1+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1-1)*y]*840./cantinc[p2+1+(p1-1)*y]);
					temp=temp+(numreal[p2-1+(p1+1)*y]*840./cantinc[p2-1+(p1+1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]*840./cantinc[p2+1+(p1+1)*y]);                   
				}
				
                if(temp>0&&temp<max){
                    max=temp;
                    temp2=pos;
                }
            }
       }
    }
    return(temp2);
    

}
int espacio_libre(int x,int y ,char vis[], int numreal[] ){
    int lug,pos,p1,p2;   
    double temp=0,max=0;
    /*mostrarestadoR(numreal,x,y);*/
    for(p1=0;p1<x;p1++){
        for(p2=0;p2<y;p2++){
            
            /*mostrarpantalla(vis,x,y);*/
            pos=p1*y+p2;
            if(numreal[pos]==0&&vis[pos]!='#'&&vis[pos]!='x'&&vis[pos]!='?'){
                lug=calcularpos(pos,x,y);
        		if(lug==0){
                    if(vis[p2+1+p1*y]=='#'){
                        return(p2+1+p1*y);
                    }
                    if(vis[p2+(p1+1)*y]=='#'){
                        return(p2+(p1+1)*y);
                    }
                    if(vis[p2+1+(p1+1)*y]=='#'){
                        return(p2+1+(p1+1)*y);
                    }
                }
				else if(lug==1){
                    if(vis[p2-1+p1*y]=='#'){
                        return(p2-1+p1*y);
                    }
                    if(vis[p2+(p1+1)*y]=='#'){
                        return(p2+(p1+1)*y);
                    }
                    if(vis[p2-1+(p1+1)*y]=='#'){
                        return(p2-1+(p1+1)*y);
                    }
                }
				else if(lug==2){
                    if(vis[p2+1+p1*y]=='#'){
                        return(p2+1+p1*y);
                    }
                    if(vis[p2+(p1-1)*y]=='#'){
                        return(p2+(p1-1)*y);
                    }
                    if(vis[p2+1+(p1-1)*y]=='#'){
                        return(p2+1+(p1-1)*y);
                    }
                }
				else if(lug==3){
                    if(vis[p2-1+p1*y]=='#'){
                        return(p2-1+p1*y);
                    }
                    if(vis[p2+(p1-1)*y]=='#'){
                        return(p2+(p1-1)*y);
                    }
                    if(vis[p2-1+(p1-1)*y]=='#'){
                        return(p2-1+(p1-1)*y);
                    }
				}
				else if (lug==4){
                    if(vis[p2+1+p1*y]=='#'){
                        return(p2+1+p1*y);
                    }
                    if(vis[p2-1+p1*y]=='#'){
                        return(p2-1+p1*y);
                    }
                    if(vis[p2+(p1+1)*y]=='#'){
                        return(p2+(p1+1)*y);
                    }
                    if(vis[p2-1+(p1+1)*y]=='#'){
                        return(p2-1+(p1+1)*y);
                    }
                    if(vis[p2+1+(p1+1)*y]=='#'){
                        return(p2+1+(p1+1)*y);
                    }
				}
				else if(lug==5){
                    if(vis[p2+1+p1*y]=='#'){
                        return(p2+1+p1*y);
                    }
                    if(vis[p2+(p1-1)*y]=='#'){
                        return(p2+(p1-1)*y);
                    }
                    if(vis[p2+(p1+1)*y]=='#'){
                        return(p2+(p1+1)*y);
                    }
                    if(vis[p2+1+(p1-1)*y]=='#'){
                        return(p2+1+(p1-1)*y);
                    }
                    if(vis[p2+1+(p1+1)*y]=='#'){
                        return(p2+1+(p1+1)*y);
                    }
				}
				else if(lug==6){
                    if(vis[p2-1+p1*y]=='#'){
                        return(p2-1+p1*y);
                    }
                    if(vis[p2+(p1-1)*y]=='#'){
                        return(p2+(p1-1)*y);
                    }
                    if(vis[p2+(p1+1)*y]=='#'){
                        return(p2+(p1+1)*y);
                    }
                    if(vis[p2-1+(p1-1)*y]=='#'){
                        return(p2-1+(p1-1)*y);
                    }
                    if(vis[p2-1+(p1+1)*y]=='#'){
                        return(p2-1+(p1+1)*y);
                    }
				}
				else if (lug==7){
                    if(vis[p2-1+p1*y]=='#'){
                        return(p2-1+p1*y);
                    }
                    if(vis[p2+(p1-1)*y]=='#'){
                        return(p2+(p1-1)*y);
                    }
                    if(vis[p2+1+p1*y]=='#'){
                        return(p2+1+p1*y);
                    }
                    if(vis[p2-1+(p1-1)*y]=='#'){
                        return(p2-1+(p1-1)*y);
                    }
                    if(vis[p2+1+(p1-1)*y]=='#'){
                        return(p2+1+(p1-1)*y);
                    }
				}
				else{
                    if(vis[p2-1+p1*y]=='#'){
                        return(p2-1+p1*y);
                    }
                    if(vis[p2+(p1-1)*y]=='#'){
                        return(p2+(p1-1)*y);
                    }
                    if(vis[p2+1+p1*y]=='#'){
                        return(p2+1+p1*y);
                    }
                    if(vis[p2-1+(p1-1)*y]=='#'){
                        return(p2-1+(p1-1)*y);
                    }
                    if(vis[p2+1+(p1-1)*y]=='#'){
                        return(p2+1+(p1-1)*y);
                    }
                    if(vis[p2+(p1+1)*y]=='#'){
                        return(p2+(p1+1)*y);
                    }
                    if(vis[p2-1+(p1+1)*y]=='#'){
                        return(p2-1+(p1+1)*y);
                    }
                    if(vis[p2+1+(p1+1)*y]=='#'){
                        return(p2+1+(p1+1)*y);
                    }
				}

            }
       }
    }
    return(-1);
    

}

/*
funcion si en una posicion seguro que no es bomba
*/
int donde_no_bomba_seguro(int x,int y ,char vis[],int cantinc[], int numreal[] ){
    int lug,pos,temp2=-1,p1,p2,a,p1t,p2t,temp;
    for(p1=0;p1<x;p1++){
        for(p2=0;p2<y;p2++){
            temp=0;
            pos=p1*y+p2;
            if(vis[pos]=='#'){
                lug=calcularpos(pos,x,y);
        		if(lug==0){
                    temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]);
				}
				else if(lug==1){
                    temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2-1+(p1+1)*y]);
                }
				else if(lug==2){
                    temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1-1)*y]);
				}
				else if(lug==3){
                    temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
                    temp=temp+(numreal[p2-1+(p1-1)*y]);
					
				
				}
				else if (lug==4){
					temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]);
					temp=temp+(numreal[p2-1+(p1+1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]);
				}
				else if(lug==5){
					temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
					temp=temp+(numreal[p2+1+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]);
				}
				else if(lug==6){
					temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
					temp=temp+(numreal[p2-1+(p1-1)*y]);
                    temp=temp+(numreal[p2-1+(p1+1)*y]);
				}
				else if (lug==7){
					temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
					temp=temp+(numreal[p2-1+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1-1)*y]);
				}
				else{
					temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
					temp=temp+(numreal[p2+(p1+1)*y]);
					temp=temp+(numreal[p2-1+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1-1)*y]);
					temp=temp+(numreal[p2-1+(p1+1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]);                   
				}

                if(temp>0){
                    //printf("cccccc%i\n",pos);
                    vis[pos]='x';
                    cont(x,y,vis,cantinc,numreal);
                    a=0;
                    while (a!=-1){
                        a=espacio_libre(x,y,vis,numreal);
                        p1t=a/y;
                        p2t=a%y;
                        vis[p1t*y+p2t]='?';
                    }
                    //mostrarpantalla(vis,x,y);
                    //mostrarestadoR(numreal,x,y);
                    //mostrarestadoR(cantinc,x,y);
                    cont(x,y,vis,cantinc,numreal);
                    for(a=0;a<x*y;a++){
                        if(cantinc[a]<numreal[a]&&numreal[a]>0){
                            temp2=pos;
                        }
                        if(vis[a]=='?'){
                            vis[a]='#';
                        }
                    }
                    vis[pos]='#';
                    cont(x,y,vis,cantinc,numreal); 
                }
                
            }
       }
    }
    return(temp2);
    

}
/*
funcion que calcula si en una posicion puede ser  bomba 
*/
int es_bomba(int x, int y,int pos,char vis[],int cantinc[], int numreal[]){
    int a,temp2=1,p1t,p2t;
    
    vis[pos]='X';
    cont(x,y,vis,cantinc,numreal);
    a=0;
    while (a!=-1){
        a=espacio_libre(x,y,vis,numreal);
        p1t=a/y;
        p2t=a%y;
        vis[p1t*y+p2t]='?';
    }
    cont(x,y,vis,cantinc,numreal);
    //mostrarpantalla(vis,x,y);
    //mostrarestadoR(numreal,x,y);
    //mostrarestadoR(cantinc,x,y);
    
    for(a=0;a<x*y;a++){
        if((cantinc[a]<numreal[a]&&numreal[a]>0)||numreal[a]<0){
            temp2=0;
        }
        if(vis[a]=='?'){
            vis[a]='#';
        }
        
    }
    
    cont(x,y,vis,cantinc,numreal); 
    return(temp2);

}
/*
funcion que calcula si en una posicion puede ser no bomba 
*/
int es_no_bomba(int x, int y,int pos,char vis[],int cantinc[], int numreal[]){
    int a,temp2=1,p1t,p2t;
    
    vis[pos]='?';
    cont(x,y,vis,cantinc,numreal);
    for(a=0;a<x*y;a++){
        if((cantinc[a]<numreal[a]&&numreal[a]>0)){
            temp2=0;
        }
    }
    vis[pos]='#';
    cont(x,y,vis,cantinc,numreal); 
    return(temp2);

}
/*
funcion que calcula donde es mas probable que este la bomba
*/
void calculadoraprob(int x,int y ,char vis[],int cantinc[], int numreal[], double prob[], int bombasacertadas,int num ,int posiciones[], int p,int temp2){
    int i,temp=0;
    double t;
    //mostrarestadoR(numreal,x,y);
    //mostrarestadoR(cantinc,x,y);
    
    //printf("aaaaaaa%i\n",p);
    if(es_bomba(x, y,posiciones[p],vis, cantinc,  numreal)==1){
        if(num-1>p){
            //printf("t0%i\n",p);
            //mostrarpantalla(vis,x,y);
            calculadoraprob(x,y,vis,cantinc,numreal,prob,bombasacertadas,num,posiciones,p+1,temp2);
            vis[posiciones[p]]='#';
            cont(x,y,vis,cantinc,numreal);
        }
        else{
            //printf("t1%i\n",p);
            //mostrarpantalla(vis,x,y);
            for(i=0;i<x*y;i++){
                if(vis[i]=='X'){
                    //printf("tttt\n",p);
                    temp++;          
                }
            }
            t=binomialCoeff(temp2,bombasacertadas);
            //printf("a1%i\n",t);
            for(i=0;i<x*y;i++){                
                if(vis[i]=='X'){
                    prob[i]=prob[i]+t;
                    //printf("t3%f\n",t);
                }
            }
            prob[4*y+5]=prob[4*y+5]+t;
            vis[posiciones[p]]='#';
            cont(x,y,vis,cantinc,numreal);
            //mostrarprob(prob,x,y);
        }
    }
    temp=0;
    if(es_no_bomba(x, y,posiciones[p],vis, cantinc,  numreal)==1){
        if(num-1>p){
            //printf("t2%i\n",p);
           
           // mostrarpantalla(vis,x,y);
            calculadoraprob(x,y,vis,cantinc,numreal,prob,bombasacertadas,num,posiciones,p+1,temp2);
        }
        else{
            //printf("t3%i\n",p);
            //mostrarpantalla(vis,x,y);
            for(i=0;i<x*y;i++){
                if(vis[i]=='X'){
                    //printf("tttt\n",p);
                    temp++;                  
                }
            }
            t=binomialCoeff(temp2,bombasacertadas);
            for(i=0;i<x*y;i++){                
                if(vis[i]=='X'){
                    //printf("t3%f\n",t);
                    prob[i]=prob[i]+t;
                }              
            }
            prob[4*y+5]=prob[4*y+5]+t;
            vis[posiciones[p]]='#';
            //mostrarprob(prob,x,y);
            }
    }
}
/*
funcion que calcula donde es mas probable que este la bomba
*/
int donde_no_bomba_prob2(int x,int y ,char vis[],int cantinc[], int numreal[], double prob[], int bombasacertadas ){
    
    int lug,pos,temp2=-1,p1,p2,a,p1t,p2t,temp,c=6,bomba_esperada=0,num=0,p=0,i;  
    char tempvec[x*y-1];
    for(p1=0;p1<x*y;p1++){
        tempvec[p1]=vis[p1];
        prob[i]=0;
    }
   
    for(p1=0;p1<x;p1++){
        for(p2=0;p2<y;p2++){
            temp=0;
            pos=p1*y+p2;
            if(tempvec[pos]=='#'){
                lug=calcularpos(pos,x,y);
        		if(lug==0){
                    temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]);
				}
				else if(lug==1){
                    temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2-1+(p1+1)*y]);
                }
				else if(lug==2){
                    temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1-1)*y]);
				}
				else if(lug==3){
                    temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
                    temp=temp+(numreal[p2-1+(p1-1)*y]);
					
				
				}
				else if (lug==4){
					temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]);
					temp=temp+(numreal[p2-1+(p1+1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]);
				}
				else if(lug==5){
					temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
					temp=temp+(numreal[p2+1+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]);
				}
				else if(lug==6){
					temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
					temp=temp+(numreal[p2-1+(p1-1)*y]);
                    temp=temp+(numreal[p2-1+(p1+1)*y]);
				}
				else if (lug==7){
					temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
					temp=temp+(numreal[p2-1+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1-1)*y]);
				}
				else{
					temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
					temp=temp+(numreal[p2+(p1+1)*y]);
					temp=temp+(numreal[p2-1+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1-1)*y]);
					temp=temp+(numreal[p2-1+(p1+1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]);                   
				}
                if(temp>0){
                    num++;                     
                }                
            }
       }
    }
    //printf("num:%i\n",num);
    int posiciones[num];       
   
    for(p1=0;p1<x;p1++){
        for(p2=0;p2<y;p2++){
            temp=0;
            pos=p1*y+p2;
            if(tempvec[pos]=='#'){
                lug=calcularpos(pos,x,y);
        		if(lug==0){
                    temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]);
				}
				else if(lug==1){
                    temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2-1+(p1+1)*y]);
                }
				else if(lug==2){
                    temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1-1)*y]);
				}
				else if(lug==3){
                    temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
                    temp=temp+(numreal[p2-1+(p1-1)*y]);
					
				
				}
				else if (lug==4){
					temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]);
					temp=temp+(numreal[p2-1+(p1+1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]);
				}
				else if(lug==5){
					temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
					temp=temp+(numreal[p2+1+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]);
				}
				else if(lug==6){
					temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+(p1+1)*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
					temp=temp+(numreal[p2-1+(p1-1)*y]);
                    temp=temp+(numreal[p2-1+(p1+1)*y]);
				}
				else if (lug==7){
					temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
					temp=temp+(numreal[p2-1+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1-1)*y]);
				}
				else{
					temp=temp+(numreal[p2-1+p1*y]);
                    temp=temp+(numreal[p2+1+p1*y]);
                    temp=temp+(numreal[p2+(p1-1)*y]);
					temp=temp+(numreal[p2+(p1+1)*y]);
					temp=temp+(numreal[p2-1+(p1-1)*y]);
                    temp=temp+(numreal[p2+1+(p1-1)*y]);
					temp=temp+(numreal[p2-1+(p1+1)*y]);
                    temp=temp+(numreal[p2+1+(p1+1)*y]);                   
				}
                if(temp>0){                    
                   posiciones[p]=pos;
                    p++;                   
                }                
            }
        }
    }
    cont(x,y,vis,cantinc,numreal); 
    for(i=0;i<x*y;i++){
        if(vis[i]=='#'){
            temp2++;
        }        
    }
    calculadoraprob(x,y,tempvec,cantinc,numreal,prob,bombasacertadas,num,posiciones,0,temp2);
    //printf("123\n");
    temp2=100;
    for(i=0;i<x*y;i++){
        
        prob[i]=prob[i]*100./prob[4*y+5];
        if(temp2>prob[i]&&prob[i]>0.){
            temp2=prob[i];
            temp=i;
        }      
    }
    return(temp); 
}



/*
funcion si hay una posocopm que es bomba seguro
*/

int donde_bomba(int x,int y ,char vis[],int cantinc[], int numreal[] ){
    int lug,pos,p1,p2;   
    double temp=0,max=0;
    for(p1=0;p1<x;p1++){
        for(p2=0;p2<y;p2++){
            temp=0;
            pos=p1*y+p2;
            if(cantinc[pos]==numreal[pos]){           
        
                lug=calcularpos(pos,x,y);
        		if(lug==0){
                    if(vis[p2+1+p1*y]=='#'){
                        return(p2+1+p1*y);
                    }
                    if(vis[p2+(p1+1)*y]=='#'){
                        return(p2+(p1+1)*y);
                    }
                    if(vis[p2+1+(p1+1)*y]=='#'){
                        return(p2+1+(p1+1)*y);
                    }
                }
				else if(lug==1){
                    if(vis[p2-1+p1*y]=='#'){
                        return(p2-1+p1*y);
                    }
                    if(vis[p2+(p1+1)*y]=='#'){
                        return(p2+(p1+1)*y);
                    }
                    if(vis[p2-1+(p1+1)*y]=='#'){
                        return(p2-1+(p1+1)*y);
                    }
                    
                }
				else if(lug==2){
                    if(vis[p2+1+p1*y]=='#'){
                        return(p2+1+p1*y);
                    }
                    if(vis[p2+(p1-1)*y]=='#'){
                        return(p2+(p1-1)*y);
                    }
                    if(vis[p2+1+(p1-1)*y]=='#'){
                        return(p2+1+(p1-1)*y);
                    }
				}
				else if(lug==3){
                    if(vis[p2-1+p1*y]=='#'){
                        return(p2-1+p1*y);
                    }
                    if(vis[p2+(p1-1)*y]=='#'){
                        return(p2+(p1-1)*y);
                    }
                    if(vis[p2-1+(p1-1)*y]=='#'){
                        return(p2-1+(p1-1)*y);
                    }
                }
				else if (lug==4){
                    if(vis[p2-1+p1*y]=='#'){
                        return(p2-1+p1*y);
                    }
                    if(vis[p2+1+p1*y]=='#'){
                        return(p2+1+p1*y);
                    }
                    if(vis[p2+(p1+1)*y]=='#'){
                        return(p2+(p1+1)*y);
                    }
                    if(vis[p2-1+(p1+1)*y]=='#'){
                        return(p2-1+(p1+1)*y);
                    }
                    if(vis[p2+1+(p1+1)*y]=='#'){
                        return(p2+1+(p1+1)*y);
                    }
				}
				else if(lug==5){
                    if(vis[p2+(p1-1)*y]=='#'){
                        return(p2+(p1-1)*y);
                    }
                    if(vis[p2+1+p1*y]=='#'){
                        return(p2+1+p1*y);
                    }
                    if(vis[p2+(p1+1)*y]=='#'){
                        return(p2+(p1+1)*y);
                    }
                    if(vis[p2+1+(p1-1)*y]=='#'){
                        return(p2+1+(p1-1)*y);
                    }
                    if(vis[p2+1+(p1+1)*y]=='#'){
                        return(p2+1+(p1+1)*y);
                    }
				}
				else if(lug==6){
                    if(vis[p2+(p1-1)*y]=='#'){
                        return(p2+(p1-1)*y);
                    }
                    if(vis[p2-1+p1*y]=='#'){
                        return(p2-1+p1*y);
                    }
                    if(vis[p2+(p1+1)*y]=='#'){
                        return(p2+(p1+1)*y);
                    }
                    if(vis[p2-1+(p1-1)*y]=='#'){
                        return(p2-1+(p1-1)*y);
                    }
                    if(vis[p2-1+(p1+1)*y]=='#'){
                        return(p2-1+(p1+1)*y);
                    }
				}
				else if (lug==7){
                    if(vis[p2+(p1-1)*y]=='#'){
                        return(p2+(p1-1)*y);
                    }
                    if(vis[p2-1+p1*y]=='#'){
                        return(p2-1+p1*y);
                    }
                    if(vis[p2+1+p1*y]=='#'){
                        return(p2+1+p1*y);
                    }
                    if(vis[p2-1+(p1-1)*y]=='#'){
                        return(p2-1+(p1-1)*y);
                    }
                    if(vis[p2+1+(p1-1)*y]=='#'){
                        return(p2+1+(p1-1)*y);
                    }
				}
				else{
                    if(vis[p2+(p1-1)*y]=='#'){
                        return(p2+(p1-1)*y);
                    }
                    if(vis[p2-1+p1*y]=='#'){
                        return(p2-1+p1*y);
                    }
                    if(vis[p2+1+p1*y]=='#'){
                        return(p2+1+p1*y);
                    }
                    if(vis[p2-1+(p1-1)*y]=='#'){
                        return(p2-1+(p1-1)*y);
                    }
                    if(vis[p2+1+(p1-1)*y]=='#'){
                        return(p2+1+(p1-1)*y);
                    }                    
                    if(vis[p2+1+(p1+1)*y]=='#'){
                        return(p2+1+(p1+1)*y);
                    }
                    if(vis[p2-1+(p1+1)*y]=='#'){
                        return(p2-1+(p1+1)*y);
                    }
                    if(vis[p2+(p1+1)*y]=='#'){
                        return(p2+(p1+1)*y);
                    }
				}
				
            }
       }
    }
    return(-1);
    

}

 
int main(){
    time_t t;
    int b,x,y,i,j,p1,p2,ultrev=0,op,bombasacertadas,pos,bomba_esperada=0,m,total,aciertos=0,a=0,c=0;
   /*Preguntamos como de grande es el mapa y cuantas bombas queremo y cuantas repeticiones vamoos ha hacer*/
    total=3;
    x=36;
    y=18;
    b=99;
    srand((unsigned) time(&t));  
    int resultados[x*y-1],calculos[x*y-1],cantinc[x*y-1],numreal[x*y-1];
    double prob[x*y-1];  
     
    char vis[x*y-1];
    for(m=0;m<total;m++){
        a=0;
        p1=4;
        p2=5;
        crearmapa(resultados,x,y,p1,p2,b);
        //limpiamos las variables para cada repeticion
        for(i=0;i<x*y;i++){
            vis[i]='#';
            cantinc[i]=-1;
            numreal[i]=0; 
            prob[i]=0.;          
        }
        ultrev=revelar(p1,p2,x,y,vis,resultados,numreal);
       
        ultrev=0;
        bombasacertadas=b;  
        while((ultrev==0&&bombasacertadas!=0&&a<100)){
            bomba_esperada=0;
            c=0;
            a++;
            //mostrarpantalla(vis,x,y);
            cont(x,y,vis,cantinc,numreal);
           
            while (bomba_esperada!=-1){
                c++;
                if(vis[p1*y+p2]=='#'){
                    vis[p1*y+p2]='x';
                    if(resultados[p1*y+p2]>8)
                    {
                        bombasacertadas--;
                    }
                }
                cont(x,y,vis,cantinc,numreal);
                bomba_esperada=donde_bomba(x,y,vis,cantinc,numreal);
                p1=bomba_esperada/y;
                p2=bomba_esperada%y;
                //printf("0%i\n",bomba_esperada);
                
            }
            //mostrarpantalla(vis,x,y);
            p1=4;
            p2=5;
            bomba_esperada=0; 
            while (bomba_esperada!=-1){
                c++;
                ultrev=revelar(p1,p2,x,y,vis,resultados,numreal);
                cont(x,y,vis,cantinc,numreal);
                bomba_esperada=espacio_libre(x,y,vis,numreal);
                p1=bomba_esperada/y;
                p2=bomba_esperada%y;
                //printf("1%i\n",bomba_esperada);
                
            }
            p1=4;
            p2=5;
            bomba_esperada=0;
            while (bomba_esperada!=-1){
                c++;
                ultrev=revelar(p1,p2,x,y,vis,resultados,numreal);
                cont(x,y,vis,cantinc,numreal);
                bomba_esperada=donde_no_bomba_seguro(x,y,vis,cantinc,numreal);
                p1=bomba_esperada/y;
                p2=bomba_esperada%y;
                //printf("2%i\n",bomba_esperada);
                
            }
            
                      
            if(c==3){
                cont(x,y,vis,cantinc,numreal);
                bomba_esperada=donde_no_bomba_prob2(x,y,vis,cantinc,numreal, prob, bombasacertadas);
                //mostrarprob(prob,x,y);
                cont(x,y,vis,cantinc,numreal);
                //mostrarestadoR(numreal,x,y);
                //mostrarestadoR(cantinc,x,y);
                //printf("3aaa%i\n",bomba_esperada);
                p1=bomba_esperada/y;
                p2=bomba_esperada%y;
                ultrev=revelar(p1,p2,x,y,vis,resultados,numreal);
            }
                             
                
        }
        
        if(bombasacertadas==0){
            aciertos++;
        }
        mostrarpantalla(vis,x,y);
    }
printf("%f",aciertos*1./total);

   
   

return 0;
}