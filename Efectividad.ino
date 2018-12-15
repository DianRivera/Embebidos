
#include <knn.h>

float prueba[10][5]={
{5.7,4.4,1.5,0.4,1},
{4.5,2.3,1.3,0.3,1},
{5,2,3.5,1,2},
{6.7,3,5,1.7,2},
{5,2.3,3.3,1,2},
{5.1,2.5,3,1.1,2},
{7.7,3.8,6.7,2.2,3},
{7.7,2.6,6.9,2.3,3},
{7.7,2.8,6.7,2,3},
{7.9,3.8,6.4,2,3}};

int on = 0;
float result;
int i=0;
int aciertos=0;
int errores=0;
int total=0;

void setup() {
 Serial.begin(9600);
}

void loop() {
  if(on==0){
    for(;i<=16;i++){
    result=knn(17,5,3,3,prueba[i]);
     Serial.println(result);
  if(result==prueba[i][4]){
    aciertos++;
    }else{
    errores++;
    }
  }
    Serial.println("ACIERTOS: " );
    Serial.println(aciertos);
    Serial.println("ERRORES: ");
    Serial.println(errores);
    
    total=(aciertos*100)/10;
    Serial.println("PORCENTAJE");
    Serial.println(total);

    on=1;
    }
   
}
