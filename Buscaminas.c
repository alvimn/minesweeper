#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
funcion que muestra la pantalla si le damos la matriz que describe el estado de juego como numericos
sabiendo donde estan las bombas (elementos que son mas grandes o igual a 9 ) y como de grande es la matriz
*/
void mostrarestadoR(int resultados[],int x,int y){
    int i,j;
     printf("    ") ;
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
funcion que muestra la pantalla que veria el jugador indicando con '#' las casillas 
de incognita , con 'x'las bombas marcadas por el jugador y con 'B' bombas si se revelaran
y como de grande es la matriz
*/
void mostrarpantalla(char resultados[],int x,int y){
    int i,j;
     printf("    ") ;
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
o en el centro para saber que bloques tiene al posicion
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
funcion genera un mapa aleatoriamente dandole unas cordenadas iniciales las cuales hara que sean
0 para que no tocar la bomba en el primer triaje
*/
void crearmapa(int resultados[],int x, int y , int p1,int p2 ,int b){
    int i,pos,lug;

    for(i=0;i<x*y;i++){
    resultados[i]=0;
    
    }
    i=0;
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
    int ultrev,lug,pos,temp,cantidad_bombas;
    temp=resultados[p2+p1*y];
    /*printf("\n%i\n",p2+p1*y);
    mostrarpantalla(vis,x,y);*/
    if(temp==0){
        pos=p1*y+p2;            
        vis[pos]=' ';
        numreal[pos]=-99;    
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
    ultrev=0;
    }
    else if(temp<9){
        vis[p2+p1*y]=resultados[p2+p1*y]+48;   
    }
    else if(temp>=9){
            vis[p2+p1*y]='B';
            ultrev=1;
            printf("Has tocado una bomba\n");
    }
    return(ultrev);
}
void cont( int p1,int p2,int x,int y ,char vis[],int resultados[],int cantinc[], int numreal[] ){
    int lug,pos,cantidad_bombas,temp,minas_encotradas;
    pos=p1*y+p2;
    temp=resultados[pos];
    /*printf("\n%i\n",p2+p1*y);
    mostrarpantalla(vis,x,y);*/
    
    if(temp<9&&temp!=0&&temp==vis[pos]-48){
        

        
        lug=calcularpos(pos,x,y);
        cantidad_bombas=0;
        minas_encotradas=resultados[pos];         
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
        }
           
        cantinc[pos]=cantidad_bombas;
        numreal[pos]=minas_encotradas;
    }
   
    
}

int main(){
    time_t t;
    int b,x,y,i,j,p1,p2,ultrev=0,op,bombasacertadas,pos;
    
   /*Preguntamos como de grande es el mapa y cuantas bombas queremos*/
    printf("Como de alto es el mapa \n");
    scanf("%d", &x);
    printf("Como de ancho es el mapa \n");
    scanf("%d", &y);
    printf("Cuantas bombas tiene el mapa \n");
    scanf("%d", &b);
    srand((unsigned) time(&t));  
    int resultados[x*y-1],calculos[x*y-1],cantinc[x*y-1],numreal[x*y-1];  
    bombasacertadas=b;   
    char vis[x*y-1];
    printf("Cordenada x de lo que quieres revelar\n");
        scanf("%d", &p1);
        printf("Cordenada y de lo que quieres revelar \n");
        scanf("%d", &p2);
    crearmapa(resultados,x,y,p1,p2,b);
    mostrarestadoR(resultados,x,y);
    for(i=0;i<x*y;i++){
        vis[i]='#';
        cantinc[i]=0;
        numreal[i]=99;   
         
    }
    ultrev=revelar(p1,p2,x,y,vis,resultados,numreal);
    mostrarpantalla(vis,x,y);
    while(ultrev==0&&bombasacertadas!=0){
        printf("Quieres revelar , marcar una bomba o pista donde esta la bomba?\n");
        printf("Revelar=0 \nMarcar=1\nPista=2\n");
        scanf("%d", &op);
        if(op==0){
            printf("Cordenada x de lo que quieres revelar\n");
            scanf("%d", &p1);
            printf("Cordenada y de lo que quieres revelar \n");
            scanf("%d", &p2);        
            ultrev=revelar(p1,p2,x,y,vis,resultados,numreal);
        }        
        else if(op==1){
            printf("Cordenada x donde cres que hay la bomba\n");
            scanf("%d", &p1);
            printf("Cordenada y donde cres que hay la bomba\n");
            scanf("%d", &p2);
            pos=p1*y+p2; 
            if(vis[pos]=='x'){
                vis[pos]='#';
                if(resultados[pos]>=9){
                    bombasacertadas++;
                }
            }
            else if( vis[pos]=='#'){
                vis[pos]='x';
                if(resultados[pos]>=9){
                    bombasacertadas--;
                }
            }
            else{
               printf("La posicion x= %3i y= %3i ya esta reveleada \n",p1,p2); 
            }       
            
        } 
        int lug,max;
        for(p1=0;p1<x;p1++){
            for(p2=0;p2<y;p2++){
                cont(p1,p2,x,y,vis,resultados,cantinc,numreal);
            }
        }
        mostrarpantalla(vis,x,y);
        mostrarestadoR(cantinc,x,y);
        mostrarestadoR(numreal,x,y);
    }
    if(bombasacertadas==0){
        printf("Has acertado donde estan todas las bombas\n");
    }

   
   

return 0;
}