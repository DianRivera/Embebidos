#include "datos_entrenamiento.h"
// definicion de matricez de CNN
int r=0;
int ver=1000;
int etiq1;
int etiq2;
int etiq3;
float matriz_s [10][5];  
float matriz_d [75][5]; 
int col=0; 
int fil;  
int col_s=0; 
int fil_s=0; 
int fil_s1=3; 
int fil_d=0;  
int col_d=0; 
float promedio; 
float sumatoria=0; 
int etiqueta=1;
int i=0;
float dist=0; 
float dist_total; 
float dist_mayor=2000; 
float label; 
void setup() {
Serial.begin(9600);

   for (r; r < 75; r++) {
      if(matriz[r][4]==1){
        etiq1++;}        }
      if(matriz[r][4]==2){
        etiq2++;  }
    if(matriz[r][4]==3){
        etiq3++;}
   }
 Serial.println(etiq1);
 Serial.println(etiq2);
 Serial.println(etiq3);
}

void loop() {
  // put your main code here, to run repeatedly:
  
Serial.println(matriz[0][4]);
  for(;fil<90;fil++){ // ciclo que recorre por cada fila de matriz de mayor volumen
          for(;fil_s<3;fil_s++){ // recorre por filas de la matriz s
              for(;col_s<4;col_s++){ // recorre por filas de ambas matrices
                dist=dist+ pow(matriz[fil][col_s]-matriz_s[fil_s][col_s],2); // distancia entre dos puntos
                }
                dist_total=sqrt(dist); // distancia entre dos puntos               
                if(dist_total<dist_mayor){ // comparacion para encontrar distancia menor
                    dist_mayor=dist_total;
                    label=matriz_s[fil_s][4]; // 
                  }// endif
                dist=0; // por cada lectura de fila se encera distancia 
                col_s=0;  //vuelve a cero para leer nuevamente columnas
            }//end for fil_S
            fil_s=0;
            dist_mayor=2000;
            // si el algoritmo knn clasifico correctamente, almacena en matriz d
           // caso contrario en matriz s
            if(label==matriz[fil][4]){
              // almacena los datos en matriz d
                for(;col_d<5;col_d++){
                   matriz_d[fil_d][col_d]=matriz[fil][col_d];
                  }
                col_d=0;
                fil_d++;
              }
              else{
                // almancena los datos en matriz s
                  for(;col_s<5;col_s++){
                   matriz_s[fil_s1][col_s]=matriz[fil][col_d];
                  }
                  col_s=0;
                  fil_s1++;
               }
   }
  }
  // imprime los valores almacenados en matriz s
fil_s=0;
for(;fil_s<fil_s1;fil_s++){
     for(;col_s<5;col_s++){
        Serial.print(matriz_s[fil_s][col_s]);
        Serial.print(',');
      }
      col_s=0;
      Serial.println(' ');
  }
//////////////////////////////////////////////////
// una vez realizado el proceso en matriz de alto volumen
// se realiza el mismo proceso con matriz d
fil=0;
fil_s=0;
col_s=0;
 for(;fil<fil_d;fil++){ // recorre los datos filas de matriz d
          for(;fil_s<3;fil_s++){ // recorre los datos de filas de matriz s
              for(;col_s<4;col_s++){ // recorre las columnas de ambas matrices
                dist=dist+ pow(matriz_d[fil][col_s]-matriz_s[fil_s][col_s],2); //distancia entre dos puntos
                }
                dist_total=sqrt(dist);  // distancia entre dos puntos               
                if(dist_total<dist_mayor){ // compara con distancia menor
                    dist_mayor=dist_total;
                    label=matriz_s[fil_s][4]; // almacena etiqueta de distancia menor
                  }// endif
                dist=0;
                col_s=0;  
            }//end for fil_S
            fil_s=0;
            dist_mayor=2000;
            // si clasifica correctamente el sistema no realiza ninguna accion
            if(label==matriz_d[fil][4]){
                    }
              // si clasifica de forma erronea, almacena en matriz s
              else{
               for(;col_s<5;col_s++){
                   matriz_s[fil_s1][col_s]=matriz[fil][col_d];
                  }
                  col_s=0;
                  fil_s1++;
               }
  }
   // imprime los valores almacenados en matriz s
fil_s=0;
for(;fil_s<fil_s1;fil_s++){
     for(;col_s<5;col_s++){
        Serial.print(matriz_s[fil_s][col_s]);
        Serial.print(',');
      }
      col_s=0;
      Serial.println(' ');
  }
 fil_s1=-1; 
 

}


}
