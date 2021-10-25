#include <cstdio>
#include <cstring>

int deadAliens = 0;
int isShipHit = 0;

void drawText(char string[], float posX, float posY) {
  glRasterPos2f(posX, posY);
  int i;
  for (i = 0; i < (int)strlen(string); i++) {
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
  }
}

void drawScore()
{
	glColor3f(0,1,0);
	char string[25];
	snprintf(string, 25, "Aliens eliminated: %d",deadAliens);
	drawText(string, -1, -1);
}

void drawWonText(){
  if(deadAliens>=27){
    glColor3f(1,1,1); 
    char string[15];
    snprintf(string, 15, "You Won!");
    drawText(string, -0.1, 0);
  }
}

void drawLoseText(){
  if(isShipHit == 1){
    glColor3f(1,1,1); 
    char string[15];
    snprintf(string, 15, "You Lose!");
    drawText(string, -0.1, 0);
  }
}


void drawResetText(){
    if(deadAliens>=27 || isShipHit == 1){
    glColor3f(1,1,1); 
    char string[30];
    snprintf(string, 30, "Press Space to play again!");
    drawText(string, -0.28, -0.1);
  }
}

void drawGameName()
{
	glColor3f(1,1,1); 
	char string[25];
	snprintf(string, 25, "Space Invaders");
	drawText(string, -0.2, 0);

	snprintf(string, 50, "Press Spacebar to start");
	drawText(string, -0.28, -0.1);

}


