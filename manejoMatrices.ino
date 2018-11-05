/*UNIVERSIDAD TECNICA DEL NORTE
      FICA-CIERCOM
      OPTATIVA II
  Diana Rivera
1. Encuentre el promedio de cada fila. 
2. Encuentre el promedio de cada columna. 
3. Encuentre el número más alto de cada fila 
4. Ecnuentre el número más bajo de cada columna 
5. Encuentre el número más alto de toda la matriz. 
6. Encuentre el número más bajo de toda la matriz. 
Se debe subir un solo programa en la actividad creada 
con métodos de cada ítem. 
En clases un estudiante aleatoriamente expondrá sus programas. 
  **********************************/
int matrizDatos [10][4]={ 
  {3,5,-6,1}, 
  {3,8,6,17}, 
  {2,-4,4,27}, 
  {2,4,8,10}, 
  {2,4,-2,5}, 
  {4,5,6,7}, 
  {5,-8,6,-7}, 
  {1,5,16,8}, 
  {0,5,12,7}, 
  {4,5,16,7}};
  int i=0;
  int j=0;

  int promF;
  int promC;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // habilita ccomunicacion serial
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Promedio Fila");promFila();
  Serial.print("Promedio Columna");promColum();
  Serial.print("Numero Mayor de Fila");highFila();
}
void promFila(){   //metodo promedio fila
    int sumaF=0;
  for(;i<10;i++){
    for(;j<4;j++){
      sumaF = sumaF + matrizDatos[i][j];
       promF= sumaF/4;
      }
    
    }
   
    Serial.println(promF);
     delay (500);
 i=0;
 j=0;
}
void promColum(){ //metodo promedio Columna
  int sumaC=0;
  for(;j<4;j++){
     for(;i<10;i++){
          sumaC = sumaC + matrizDatos[i][j];
       promC= sumaC/10;
      }
     
    }
 
    Serial.println(promC);
     delay (500);
  j=0;
  i=0;
  }
void highFila(){  //metodo para sacar el num mayor de cada fila
  int numA;
   int numMayor;
  for(;i<10;i++){
    for(;j<4;j++){
      numMayor = matrizDatos[i][j];
      if(numMayor>numA)
      {
         numMayor=numA;
         Serial.println(numA); 
         delay(500);   }
}
  
  
}}
void lowColum(){}
void highMatriz(){}
void lowMatriz(){}

