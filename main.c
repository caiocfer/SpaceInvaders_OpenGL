#include <GL/freeglut.h>
#include "ship.h"
#include "alien.h"
#include "texts.h"

int windowWidth = 800;
int windowHeight = 600;
int gameStarted = 0;
int moveAliensToTheRight = 1;

void drawGame();
void drawScreen();
void drawGameOverScreen();
void timer(int t);
void checkAlienHitBox();
void keyboard(unsigned char tecla, int xtela, int ytela);
void resetGame();
void resetAliens();
void aliensMovementRestrictions();
void moveAliens(float posicaoX,float posicaoY);
void checkShipHitBox();
void checkAlienReachedBottom();

int main(int argc, char * argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("Space Invaders");
	startAliens();
	
	glutDisplayFunc(drawScreen);
	glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}


void desenhaTelaInicio(){
	drawGameName();
}

void drawScreen(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(gameStarted == 0){
		desenhaTelaInicio();
	}
	else{
		drawGame();
	}
	glutPostRedisplay();
	glutSwapBuffers();
}

void drawGame(){
	drawShip();
	drawShipShoot();
	glLoadIdentity();
	drawAliens();
	drawAlienShot();
	drawScore();
	drawGameOverScreen();
}


void drawGameOverScreen(){
	if(isShipHit == 0 ){
		drawWonText();
	}else{
		drawLoseText();
	}

	drawResetText();
}

void timer(int t){

	glutPostRedisplay();
	checkAlienHitBox();
	checkShipHitBox();
	checkAlienReachedBottom();
	aliensMovementRestrictions();
	glutTimerFunc(33, timer, 1);
}

void checkAlienHitBox() {
    int i,j;
	moveShot();
    for(i=0;i<aliensLine;i++){
        for(j=0;j<aliensRow;j++){
            if(	posTiroX >= aliens[i][j].alienV2X && 
				posTiroX <= aliens[i][j].alienV1X && 
				posTiroY >= aliens[i][j].alienV3Y &&
				posTiroY <= aliens[i][j].alienV1Y &&
				aliens[i][j].isAlive == 1){
					aliens[i][j].isAlive = 0;
					deadAliens += 1;
					posTiroY = 2; // Tira o tiro da tela
            }
        }
	}
}

void checkAlienReachedBottom(){
	int i,j;
	for(i=0;i<aliensLine;i++){
        for(j=0;j<aliensRow;j++){
			if(aliens[i][j].isAlive == 1 && aliens[i][j].alienV3Y <= shipV3Y){
				isShipHit = 1;
			}
		}
	}
}

void checkShipHitBox(){
	if(isShipHit == 0){
	moveAlienShot();
	if(	posAlienShotX <= shipV2X &&
		posAlienShotX >= shipV1X &&
		posAlienShotY <= shipV3Y &&
		posAlienShotY >= shipV1Y){
			posAlienShotY = -2;
			isShipHit = 1;
		}
	}
}

void keyboard(unsigned char key, int xScreen, int yScreen){
	if(deadAliens<=26 && gameStarted == 1 && isShipHit == 0){
        if(key == 'a'&& shipV1X>-1){
            shipV1X-=0.02f;
            shipV2X-=0.02f;
            shipV3X-=0.02f;
        }
        if(key == 'd' && shipV2X<0.99){
            shipV1X+=0.02f;
            shipV2X+=0.02f;
            shipV3X+=0.02f;
        }

        if(key == SPACEBAR){
            atira();
        }
	}else if(gameStarted == 0){
		if(key == SPACEBAR){
            gameStarted = 1;
        }
	}else{
		if(key == SPACEBAR){
			resetGame();
		}
	}

}

void resetGame(){
	resetAliens();
	resetShipPosition();
	isShipHit = 0;
}

void resetAliens(){
	deadAliens = 0;
	moveAliensToTheRight =1;
	setAliensPosition();
}

void aliensMovementRestrictions(){
	if(isShipHit == 0){
		int i,j;
		float maxX = 1;
		float minX = -1;
		for(i=0;i<aliensLine;i++){
			for(j=0;j<aliensRow;j++){
				if(aliens[i][j].alienV2X > minX){
				minX =  aliens[i][j].alienV2X;
				}
				if(aliens[i][j].alienV1X < maxX){
					maxX = aliens[i][j].alienV1X;
				}

				if(minX >= 0.9){
					moveAliensToTheRight = 0;
					moveAliens(0,-0.001f);
				}
				if(maxX<=-0.9){
					moveAliensToTheRight = 1;
					moveAliens(0,-0.001f);
				}

				if(moveAliensToTheRight == 1){
					moveAliens(0.0003f,0);
				}else{
					moveAliens(-0.0003f,0);
				}
			}
		}
	}
}


