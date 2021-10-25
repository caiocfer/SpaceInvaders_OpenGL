#define SPACEBAR 32

float v1X = -0.05f;
float v1Y = 0.0f;

float v2X = 0.05f;
float v2Y = 0.0f;

float v3X = 0.0f;
float v3Y = 0.15f;

float shipV1X = v1X;
float shipV1Y = v1Y-0.95;

float shipV2X = v2X;
float shipV2Y = v2Y-0.95;

float shipV3X = v3X;
float shipV3Y = v3Y-0.95;

float posTiroY = 2; // Instanciar o tiro fora da tela
float posTiroX = shipV3X;

void drawShipShoot();
void checkAlienHitBox();
void atira();

void drawShip(){
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_TRIANGLES);
		glVertex2f(shipV1X, shipV1Y);
		glVertex2f(shipV2X, shipV2Y);
		glVertex2f(shipV3X , shipV3Y);
	glEnd();

}

void drawShipShoot(){
	glLoadIdentity();
	glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);            
		glVertex2f(-0.005+posTiroX, 0.1f+posTiroY);
		glVertex2f(-0.005+posTiroX, 0.0f+posTiroY);
		glVertex2f(0.005f+posTiroX, 0.0f+posTiroY);
		glVertex2f(0.005f+posTiroX, 0.1f+posTiroY);
	glEnd();

}

void moveShot() {
    posTiroY += 0.050f;// Velocidade do tiro
}

void atira(){
    if(posTiroY>1){
        posTiroY = shipV3Y;
        posTiroX = shipV3X;
    }
}

void resetShipPosition(){
	shipV1X = v1X;
	shipV2X = v2X;
	shipV3X = v3X;
}




