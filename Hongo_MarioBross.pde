/******************************************************
       UNIVERSIDAD TECNICA DEL NORTE
              FICA-CIERCOM
            SISTEMAS EMBEBIDOS
-******************************************************/
       
int i=0;
int x=0;
int y=0;

void setup(){
size(1200,600);
}

void draw(){
  background(250);
  figura();
  fill (0,225,10);
  smooth ();
  fill (((2)),( (600)),((256)));
rect(100,100,50,450);
rect(200,300,600,50);
rect(300,150,200,50);
rect(600,200,200,50);
rect(650,600,200,50);
rect(550,300,50,200);
rect(525,600,50,200);
rect(300,600,50,200);
rect(200,850,800,50);
rect(1000,100,50,450);


}

void figura(){
beginShape();
fill(247,98,67);
vertex(10+x,20+y);
vertex(15+x,20+y);
vertex(15+x,15+y);
vertex(20+x,15+y);
vertex(20+x,10+y);
vertex(45+x,10+y);
vertex(45+x,15+y);
vertex(50+x,15+y);
vertex(50+x,20+y);
vertex(55+x,20+y);
vertex(55+x,30+y);
vertex(45+x,30+y);
vertex(45+x,25+y);
vertex(20+x,25+y);
vertex(20+x,30+y);
vertex(10+x,30+y);
vertex(10+x,20+y);
endShape();

beginShape();
fill(255,204,153);
vertex(15+x,30+y);
vertex(15+x,40+y);
vertex(20+x,40+y);
vertex(20+x,45+y);
vertex(45+x,45+y);
vertex(45+x,40+y);
vertex(50+x,40+y);
vertex(50+x,30+y);
vertex(45+x,30+y);
vertex(45+x,25+y);
vertex(20+x,25+y);
vertex(20+x,30+y);
vertex(15+x,30+y);
endShape();
fill(0);
rect(25+x,25+y,5,7);
rect(35+x,25+y,5,7);
}
  
  void keyPressed(){
    background(250); 
   //println(keyCode); //key convierte de hex a letra y keyCode solo recibe el hex
   //text(keyCode,100,50);
  switch(keyCode){
  case 38:
  y=y-5;
  break;
  case 40:
  y=y+5;
  break;
  case 39:
  if (x<1170);
  x=x+5;
  break;
  case 37:
  if(x>-5)
  x=x-5;
  else x=1170;
  break;
}
  }
  
