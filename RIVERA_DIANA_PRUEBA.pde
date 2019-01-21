int i=0;
int x=0;
int y=0;
int xr=0;
int yr=0;
void setup(){
size(1000,600);
}

void draw(){
figura();  
line(0,95,1000,95);
if(xr<980){
fill(0);
rect(900-xr,200,15,40);
xr=xr+2;
}else
x=0;

}
void figura(){
  
 beginShape();
 // noStroke();
  fill(0,100,250);
  vertex(50, 110);
  vertex(50, 130);
  vertex(60, 130);
  vertex(60, 140);
  vertex(70, 140);
  vertex(70, 150);
  vertex(90, 150);
  vertex(90, 140);
  vertex(100, 140);
  vertex(100, 130);
  vertex(120, 130);
  vertex(120, 120);
  vertex(140, 120);
  vertex(140, 110);
  vertex(150, 110); 
  vertex(150, 50);
   vertex(150, 60); //CABEZA
   vertex(160, 60);
   vertex(160, 50);
   vertex(160, 40);
  vertex(150, 40); 
  vertex(240, 40);
  vertex(240, 50);
  vertex(250, 50);
  vertex(250, 90);
  vertex(190, 90);
  vertex(190, 100);
  vertex(230, 100);
  vertex(230, 110);
  vertex(180, 110);
  vertex(180, 130);
  vertex(200, 130);
  vertex(200, 130);
  vertex(190, 150);
  vertex(190, 140);
  vertex(180, 140);
  vertex(180, 180);
  vertex(170, 180);
  vertex(170, 200);
  vertex(160, 200);
  vertex(160, 210);
  vertex(150, 210);
  vertex(150, 250);
  vertex(160, 250);
  vertex(160, 260);
  vertex(140, 260);
  vertex(140, 230);
  vertex(130, 230);
  vertex(130, 220);
  vertex(120, 220);
  vertex(120, 230);
  vertex(110, 230);
  vertex(110, 240);
  vertex(100, 240);
  vertex(100, 250);
  vertex(110, 250);
  vertex(110, 260);
  vertex(90, 260);
  vertex(90, 210);
  vertex(70, 210);
  vertex(70, 200);
  vertex(60, 200);
  vertex(60, 190);
  vertex(50, 190);
  vertex(50, 180);
  vertex(40, 180);
  vertex(40, 110);
  vertex(50, 110);    
  endShape();
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