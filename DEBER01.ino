/*Universidad Tecnica del Norte
        FICA-CIERCOM
        Diana Rivera
         Optativa II
Realizar un sistema que ingrese por comunicación serial una palabra 
se visualice en una LCD. Además, realice un rotación de letras dentro la LCD.*/
#include<LiquidCrystal.h> //se incluye la libreria para el uso del LCD

//inicializar LCD

LiquidCrystal lcd (13,12,11,10,9,8); //conexxion de puertos LCD RS,E, D4,D5,D6,D7
int i=0;
String palabra;  //variable para almacenar la palabra que ingresa por cx serial

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);  //configura el puerto serie y su velocidad de ingreso de datos
  lcd.begin(16,2); //se define como trabaja la matriz
}
 
void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0) // se comprueba si existen datos ingresados
  {
    palabra =Serial.readString();  //se almacena en la variable la palabra o dato leido
 
     for(;i<10;i++){    //ciclo for para que exista movimiento en el LCD
         lcd.setCursor(i,0); // se ubica donda va a iniciar a salir la palabra
         lcd.print(palabra);   // imprime la palabra
         delay(200);
         lcd.clear();
  }
  i=0;
  }
  
}
