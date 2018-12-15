#include"datos_entrenamiento.h"
#include"datos_test.h"
float result;

int on=0;
int datostotal=84;
int i=0;
int j=0;
int n=0;
int z=0;
float suma1=0, suma2, suma3,  suma4;
int cont=0;
float prom1,prom2,prom3,prom4;
float distancia;
float norm[84];
float mayor=0;
float v1[84];
float v2[84];
float si[84];
float criterio1 = 0.63;
float criterio2 =1;
float vectorR[84][5];
int a=0;
int cont2=0;
int cont3=0;
int cont4=0;
int b=0;
int cont5=0;
float vectorR2[84][5];
float total;


void setup() {
  Serial.begin(9600);
  
}

void loop() {
if(on==0){
   Serial.println("********RESULDO KNN AUTOMATICO********");
   Serial.println(" ");
      /*
       * Promedio de las filas, con el fin de obtener el centro de cada uno de los 3 grupos
       */
  for(int i;i<datostotal;i++){
      suma1+=matriz[i][0];
      cont++;
  
     } 
    prom1=suma1/cont;
    cont=0;
    i=0;
        //Serial.println(prom1);
   for(int i;i<datostotal;i++){
      suma2+=matriz[i][1];
      cont++;
     }
    prom2=suma2/cont;
    cont=0;
    i=0;
        //Serial.println(prom2);
  for(int i;i<datostotal;i++){
      suma3+=matriz[i][2];
      cont++;
     }
    prom3=suma3/cont;
    cont=0; 
    i=0;
        //Serial.println(prom3);
    for(int i;i<datostotal;i++){
      suma4+=matriz[i][3];
      cont++;
     }
    prom4=suma4/cont;
    i=0;
       //Serial.println(prom4);
    /*
     * Distancia punto y el centro del conjunto(promedio)
     */
    for(int n;n<=cont-1;n++){
      distancia=sqrt(pow((matriz[n][0]-prom1),2)+
               pow((matriz[n][1]-prom2),2)+
               pow((matriz[n][2]-prom3),2)+
               pow((matriz[n][3]-prom4),2));
       v1[n]=distancia; 
           //Serial.println(v2[n]);

      if(mayor<=v1[n]){ //busca el numero mayor entre la distancia antes echa
        mayor=v1[n];
        }
      }
          //Serial.println(':');
          //Serial.print(mayor);

      for(j=0;j<cont;j++){
        norm[j]=v1[j]/mayor; //vector normalizacion
          //Serial.print(':');
          //Serial.println(norm[j]);
        }

      for(j=0;j<datostotal;j++){ //comparacion con criterios para posterior eliminacion  
        if(norm[j]>criterio1 && norm[j]<criterio2){   
            si[j]=1;
            vectorR[j][0]=j;
            cont2++;
     
  if(si[j]==1){
        Serial.println(" ");
    for(int a =0;a<5;a++){
      vectorR2[j][a]=matriz[j][a];
      //Serial.println(matriz[j][a]);
              }} 
    result = knn(cont2, 5, 3, 4, prueba[j]);

      Serial.println(result);
         }}
       //porcentaje();
           
              j=0;
               on=1;
}}

  float knn (int fila, int col,int k, int label,float datos[]){
  int c=0; // movernos en columnas 
  int f=0; // movernos en fila 
  float k_vecinos_dist[k]; // vector de almacenamiento de k distancia menores
  float etiquetas [2][label]; // matriz y conteo de etiquetas
  float dist=0; // variable que almacena cada distancia
  float dist_total=0; // varaible para almacenamiento de distancia
  // llenar vector k_vecinos_dist con valores altos
  float eti_menor[k]; //vector de etiquetas de distancia menor
  int k_cont=0;
  int i=0; 
  int j=0;
  float clase; // retornar etiqueta
  float comparacion; // comparar k-vecino mayor
   for(;c<k;c++){
    k_vecinos_dist[c]=2000.0+c;  // valores altos y ordenados
    }
    c=0; // reiniciar varaible
  // llenar matriz etiquetas
   for(;c<label;c++){
      etiquetas[0][c]=c+1;  // lleno con valores de etiqueta
      etiquetas[1][c]=0;  // lleno con el conteo de etiqueta
    }
    c=0; //renicio variable

// la distacia mas corta del nuevo punto hacia la matriz

   for(;j<fila;j++){
      dist=sqrt(pow((vectorR2[j][0]-prueba[j][0]),2)+
               pow((vectorR2[j][1]-prueba[j][1]),2)+
               pow((vectorR2[j][2]-prueba[j][2]),2)+
               pow((vectorR2[j][3]-prueba[j][3]),2));
        dist_total=sqrt(dist); // raiz de la formula
      // Serial.println(dist_total);
       //Serial.print(" ");
       
 for(;k_cont<k;k_cont++){ // determinar las k distancias menores y ordenarlas
  if(dist_total<k_vecinos_dist[k_cont]){
            k_vecinos_dist[k_cont]=dist_total; // asignar nuevo valor a vector de distancias menores
            eti_menor[k_cont]=vectorR2[j][col-1];  // col =5 , 4
            Serial.print(vectorR2[j][c-1]);
            Serial.print(" ");
            }
        }
       k_cont=0;
       dist=0;
       dist_total=0;
       c=0;            
     } //for fila

// seleccion de los k vecino
    for(;c<=label;c++){
      for(;k_cont<k;k_cont++){  // recorro cada posicion de eti_menor y comparo con etiquetas y cuento si son iguales
         if(etiquetas[0][c]==eti_menor[k_cont]){
            i++;
            etiquetas[1][c]=i;
          }
        }
      k_cont=0;
        i=0;
      }
      c=1; 
      comparacion = etiquetas[1][0];
      clase=etiquetas[0][0];
      for(;c<label;c++){
         if(etiquetas[1][c]>comparacion){ // comparacion entre valores de suma de etiqueta
          clase=etiquetas[0][c];
          comparacion=etiquetas[1][c];
          }
        }
        comparacion=0;
        c=0;    
        return clase;   
  }

  
float porcentaje(){
if(on==0){
    for(;i<=84;i++){
      result=procesoknn(84,5,4,3,prueba[i]);
      Serial.println(result);
      
   if(result==prueba[i][4]){
    a++;
    }
    else{
    b++;
      }
    }
    
    Serial.print("ACIERTOS:   ");
    Serial.println(a);
    Serial.print("ERRORES:   ");
    Serial.println(b);

    total = (a*100)/(a+b);
    Serial.print("PORCENTAJE ACIERTOS:   ");
    Serial.println(total);
    on=1;
}}

      
      
  
     
