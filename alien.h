void drawAliens();
void startAliens();
void moveAlienShot();

float distX = 0;
float distY = 0;

float alienV1X = -0.8+distX;
float alienV1Y = 0.95+distY;

float alienV2X = -0.9+distX;
float alienV2Y = 0.95+distY;

float alienV3X = -0.85+distX;
float alienV3Y = 0.85+distY;

int aliensRow = 9;
int aliensLine = 3;

float posAlienShotY = -2; // bullet started out of screen
float posAlienShotX = alienV3X;

struct alien {

    float alienV1X;
    float alienV1Y;

    float alienV2X;
    float alienV2Y;

    float alienV3X;
    float alienV3Y;

    int isAlive;
};

struct alien aliens[3][9]; // Array Aliens -> [Nlines][Nrows]


void startAliens(){
    int i,j;
    float tempX = distX;
    for(i=0;i<aliensLine;i++){
        for(j=0;j<aliensRow;j++){

            aliens[i][j].alienV1X = alienV1X + distX;
            aliens[i][j].alienV2X = alienV2X + distX;
            aliens[i][j].alienV3X = alienV3X + distX;           

            aliens[i][j].alienV1Y = alienV1Y + distY;
            aliens[i][j].alienV2Y = alienV2Y + distY;
            aliens[i][j].alienV3Y = alienV3Y + distY; 
            distX = distX + 0.2;
            aliens[i][j].isAlive = 1; 

           }
            distX = tempX;
            distY = distY - 0.2;
        } 
}

void drawAliens(){
    int i,j;
    for(i=0;i<aliensLine;i++){
        for(j=0;j<aliensRow;j++){
            if(aliens[i][j].isAlive == 1){
                glColor3f(0.0f,1.0f,0.0f);
                glBegin(GL_TRIANGLES);
                        glVertex2f(aliens[i][j].alienV1X , aliens[i][j].alienV1Y);
                        glVertex2f(aliens[i][j].alienV2X , aliens[i][j].alienV2Y);
                        glVertex2f(aliens[i][j].alienV3X , aliens[i][j].alienV3Y);
                glEnd();
            }

        }
    }

}

void drawAlienShot(){
    glLoadIdentity();
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);            
        glVertex2f(-0.005+posAlienShotX, 0.1f+posAlienShotY);
        glVertex2f(-0.005+posAlienShotX, 0.0f+posAlienShotY);
        glVertex2f(0.005f+posAlienShotX, 0.0f+posAlienShotY);
        glVertex2f(0.005f+posAlienShotX, 0.1f+posAlienShotY);
    glEnd();
    
}

void moveAlienShot() {
    int randonLine = rand() % aliensLine;
    int randonRow = rand() % aliensRow;    

    if(aliens[randonLine][randonRow].isAlive == 1 && posAlienShotY<=-0.9){
        posAlienShotX = aliens[randonLine][randonRow].alienV3X;
        posAlienShotY = aliens[randonLine][randonRow].alienV3Y - 0.09f;
    }else{
        posAlienShotY -= 0.03f;
    }
}

void moveAliens(float posX,float posY){
  int i, j;
  for(i=0; i<aliensLine; i++) {
    for(j=0; j<aliensRow; j++) {
		aliens[i][j].alienV1X +=  posX;
		aliens[i][j].alienV2X +=  posX;
		aliens[i][j].alienV3X +=  posX;           

		aliens[i][j].alienV1Y +=  posY;
		aliens[i][j].alienV2Y +=  posY;
		aliens[i][j].alienV3Y +=  posY; 
    }
  }
}

void setAliensPosition(){
	distX = 0;
	distY = 0;

	alienV1X = -0.8+distX;
	alienV1Y = 0.95+distY;

	alienV2X = -0.9+distX;
	alienV2Y = 0.95+distY;

	alienV3X = -0.85+distX;
	alienV3Y = 0.85+distY;
    int i,j;
    float tempX = distX;
    for(i=0;i<aliensLine;i++){
        for(j=0;j<aliensRow;j++){

            aliens[i][j].alienV1X = alienV1X + distX;
            aliens[i][j].alienV2X = alienV2X + distX;
            aliens[i][j].alienV3X = alienV3X + distX;           

            aliens[i][j].alienV1Y = alienV1Y + distY;
            aliens[i][j].alienV2Y = alienV2Y + distY;
            aliens[i][j].alienV3Y = alienV3Y + distY; 
            distX = distX + 0.2;
            aliens[i][j].isAlive = 1; 

        }
        distX = tempX;
        distY = distY - 0.2;
    } 
}