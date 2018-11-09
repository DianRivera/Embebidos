/**************************************
 * UNIVERSIDAD TECNICA DEL NORTE
      FICA-CIERCOM
      OPTATIVA II
      DIANA RIVERA
  *************************************/
#include "datos_entrenamiento.h"
#include "datos_test.h" 
int i;
int col=0;  //leer columnas
int row=0;  //leer filas
float distancia;
float dist1;
float dist2;
float dist_menor=100;  //variables con distancias referenciales
float dist_menor1=150;
float dist_menor2=200;
float resp1;
float resp2;
float resp3;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
for (;row<120;row++){   //ciclo for lento
     distancia = sqrt(pow((matriz[row][0]-prueba[row][0]),2)+
                    pow((matriz[row][1]-prueba[row][1]),2)+
                    pow((matriz[row][2]-prueba[row][2]),2)+
                    pow((matriz[row][3]-prueba[row][3]),2));
        if(distancia<dist_menor){
          dist_menor=distancia;
          resp1= matriz[row][4];
          resp1=resp1;
        }
       dist1 = sqrt(pow((matriz[row][0]-prueba[row][0]),2)+
                    pow((matriz[row][1]-prueba[row][1]),2)+
                    pow((matriz[row][2]-prueba[row][2]),2)+
                    pow((matriz[row][3]-prueba[row][3]),2));
          if(dist1<dist_menor1&&dist1>dist_menor){
            dist_menor1=dist1;
            resp2=matriz[row][4];
            resp2=resp2;
            }
       dist2 = sqrt(pow((matriz[row][0]-prueba[row][0]),2)+
                    pow((matriz[row][1]-prueba[row][1]),2)+
                    pow((matriz[row][2]-prueba[row][2]),2)+
                    pow((matriz[row][3]-prueba[row][3]),2));
           if(dist2<dist_menor2&&dist2>dist_menor1){
            dist_menor2= dist2;
            resp3= matriz[row][4];
            resp3= resp3;
            }
        }
 Serial.print("Grupo: ");
 Serial.println(resp1);
 Serial.println(dist_menor);
 delay(1000);
 Serial.print("Grupo: ");
 Serial.println(resp2);
 Serial.println(dist_menor1);
 delay(1000);
 Serial.print("Grupo: ");
 Serial.println(resp3);
 Serial.println(dist_menor2);
delay(1000);
    }
  

