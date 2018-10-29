
/*Universidad Tecnica del Norte
        FICA-CIERCOM
        Diana Rivera
         Optativa II
         
Realice una calculadora mediante un teclado matricial y una lcd. Las funciones de la calculadora son: suma, resta, multiplicación y división.*/

#include <LiquidCrystal.h>
#include <Keypad.h> // Librería del keypad

LiquidCrystal lcd (13,12,11,10,9,8); //inicializacion y configuracion de pines
const byte filas = 4; // número de filas
const byte columnas = 4; // número de columanas

char teclas [filas][columnas]={   //configuracion de la variable teclado
{'1','2','3','+'},
{'4','5','6','-'},
{'7','8','9','x'},
{'*','0','=','/'}
}; 

byte filaP[filas]={0,1,2,3}; //configuración de filas
byte columnaP[columnas]={4,5,6,70}; // configuración de columnas

Keypad calcular = Keypad (makeKeymap(teclas),filaP, columnaP, filas, columnas);

boolean inicio = false; 
boolean final = false; // variables BOOLEANAS de control

String num1, num2;
int resp;
char op;

void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
 
}

void loop()
{
  char key = calcular.getKey();
  
  if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
    if(inicio == false)
      {num1 = num1 + key;
      int numTam = num1.length();
      lcd.setCursor(15-numTam,0);
      lcd.print(num1); 
  }
     else
     {num2 = num2 + key;
      int numTam = num2.length();
      lcd.setCursor(15-numTam,1);
      lcd.print(num2);
      final = true;
  }
}
if (inicio == false && key != NO_KEY && (key == '+' || key == '-' || key == 'x' || key == '/'))

{inicio = true;
 op = key;
 lcd.setCursor(15,0);
 lcd.print (op); 

}
if (final == true && key !=NO_KEY && key == '=')  // comparacion para realizar las operaciones
{
    if (op == '+')  //SUMA
    {resp= num1.toInt() + num2.toInt();}
    if (op == '-')   //RESTA
    {resp= num1.toInt() - num2.toInt();}
    if (op == 'x')    //MULTIPLICACION
    {resp= num1.toInt() * num2.toInt();}
    if (op == '/')    //DIVISION
    {resp= num1.toInt() / num2.toInt();}
    
    lcd.clear();
    lcd.setCursor(15,0);
    lcd.autoscroll();
    lcd.print(resp);
    lcd.noAutoscroll();    
}
if(key !=NO_KEY && key == '*')  // ciclo para qu no se realice ninguna operacion cuando esta vacio

{
  lcd.clear();
  inicio = false;
  final = false;
  num1 = "";
  num2 = "";
  resp = 0;
  op = ' ';
}
}
