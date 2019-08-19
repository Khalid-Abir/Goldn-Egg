#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
#include <MMSystem.h>

#define PI 3.1416

using namespace std;

static float tx	=  0.0;
static float ty	=  -45.0;
static float murgi1	=  0.0;
static float murgi2	=  30.0;
static float murgi3	=  -30.0;
static float dimTimer =  100.0;
static float dimX[3] =  {5000,5000,5000};
static float dimY[3] =  {5000,5000,5000};
static int murgi1direction = 1;
static int murgi2direction = -1;
static int murgi3direction = 1;
static int totaldim = 3;
static int score = 0;
static int life = 3;
static int start = 0;

void circle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);


		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

	glEnd();
}

void dim(float x, float y){
    glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(x,y,0);
	circle(1,1.5);
	glPopMatrix();
	//printf("dim created");
}

void print(int x, int y,int z, string str)
{
    //set the position of the text in the window using the x and y coordinates
    glRasterPos2f(x,y);
    //get the length of the string to display
    int len = str.length();
    //loop to display character by character
    for (int i = 0; i<len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
    }
}

void murgi(){

    /*glPushMatrix();
	glColor3f(0.5, 0.0, 1.0);
	glTranslatef(-2.5,0,0);
	circle(2,2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.5);
	glTranslatef(-2,1,0);
	circle(2,2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.0, 1.0);
	glTranslatef(-1.5,2,0);
	circle(2,2);
	glPopMatrix();*/


    glPushMatrix();
	glColor3f(1.0, 0.25, 0.0);
	glRotatef(5.0,0.0,0.0,1.0);
	//glTranslatef(-1.5,2,0);
	//circle(2,2);
	glBegin(GL_POLYGON);
    glVertex2f(0.0,0.0);
    glVertex2f(5.0,0.0);
    glVertex2f(0.0,3.0);
	glEnd();

	glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 0.5, 0.35);
    glBegin(GL_POLYGON);

    glVertex2f(-2.0,-3.0);
    glVertex2f(-2.75,-3.0);
    glVertex2f(-2.75,-9.0);
    glVertex2f(-2.0,-9.0);
	glEnd();

	glBegin(GL_POLYGON);
    glVertex2f(-4.0,-3.0);
    glVertex2f(-4.75,-3.0);
    glVertex2f(-4.75,-9.0);
    glVertex2f(-4.0,-9.0);
	glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.9, 0.0);
    glVertex2f(-8.0,-1.0);
    glVertex2f(-12.0,2.0);
    glVertex2f(-11.0,-0.5);
    glVertex2f(-12.5,-2.0);
    glVertex2f(-8.0,-2.0);
	glEnd();

    glPushMatrix();
	glColor3f(1.0, 1.2, 0.0);
	glTranslatef(-4,-3,0);
	circle(5,4);
	glPopMatrix();


	glPushMatrix();
	glColor3f(1.0, 0.70, 0.0);
	glTranslatef(0,1,0);
	circle(3,3);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(1,1.75,0);
	circle(.5,.5);
	glPopMatrix();
}


void movingMurgi(){
    if(life){
        float increment = 0.05;
        //printf("%f\n",murgi1);
        int tempmurgi1;
        int tempmurgi2;
        int tempmurgi3;

        if(murgi1direction==1){
            murgi1+=increment;
            tempmurgi1 = murgi1;
            if(tempmurgi1==45) murgi1direction=-1;
        }else{
            murgi1-=increment;
            tempmurgi1 = murgi1;
            if(tempmurgi1==-45) murgi1direction=1;
        }

        if(murgi2direction==1){
            murgi2+=increment;
            tempmurgi2 = murgi2;
            if(tempmurgi2==45) murgi2direction=-1;
        }else{
            murgi2-=increment;
            tempmurgi2 = murgi2;
            if(tempmurgi2==-45) murgi2direction=1;
        }

        if(murgi3direction==1){
            murgi3+=increment;
            tempmurgi3 = murgi3;
            if(tempmurgi3==45) murgi3direction=-1;
        }else{
            murgi3-=increment;
            tempmurgi3 = murgi3;
            if(tempmurgi3==-45) murgi3direction=1;
        }


        dimTimer-=0.075;
        dimY[0]-=0.075;
        dimY[1]-=0.075;
        dimY[2]-=0.075;

        int tempDimY[3];
        int tempDimX[3];
        for(int i=0;i<totaldim;i++){
            tempDimY[i]=dimY[i];
            tempDimX[i]=dimX[i];
            //printf("%d\n",tempDim[i]);
            if(tempDimY[i]==-45){
                int temptx = tx;
                if((temptx-3)<=tempDimX[i] && (temptx+3)>=tempDimX[i]){
                    score+=5;
                    //dimY[i]=5000;
                    //break;
                }else{
                    life--;
                    //dimY[i]=5000;
                    //break;
                }

                dimY[i]=5000;

            }
        }

        int tempdimtimer = dimTimer;
        if(tempdimtimer==0){
            dimTimer=100.0;
            int selector = rand()%3+1;
            //printf("%d\n",selector);
            switch(selector){
            case 1:
                dimX[0]=murgi1;
                dimY[0]=20;
                dimX[1]=murgi2;
                dimY[1]=3000;
                dimX[2]=murgi3;
                dimY[2]=4000;
                break;
            case 2:
                dimX[0]=murgi1;
                dimY[0]=2000;
                dimX[1]=murgi2;
                dimY[1]=30;
                dimX[2]=murgi3;
                dimY[2]=4000;
                break;
            case 3:
                dimX[0]=murgi1;
                dimY[0]=2000;
                dimX[1]=murgi2;
                dimY[1]=3000;
                dimX[2]=murgi3;
                dimY[2]=40;
                break;
            }
        }

        glutPostRedisplay();
    }
    else if(life==0){
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
        string x="Press HOME to start";
        print(-15,0,0,x);

    }

}
void over(){
    ostringstream str01;
    str01 << score;
    if(life==0){
        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(-1000.0,1000.0);
        glVertex2f(1000.0,1000.0);
        glVertex2f(1000.0,-1000.0);
        glVertex2f(-1000.0,-1000.0);
        glEnd();

        string str = "Your Score is: " + str01.str();
        glColor3f(0.0, 1.0, 0.0);
        print(-15,5,0,str);
        string x="Press  'HOME'  to start again";
        glColor3f(1.0, 1.0, 1.0);
        print(-15,0,0,x);
        string y="GAME OVER";
        glColor3f(1.0, 0, 0);
        print(-15,15,0,y);
    }
}

void megh(){
    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
	glTranslatef(0,0,0);
	circle(8,5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
	glTranslatef(0.5,5,0);
	circle(4,3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
	glTranslatef(6,2,0);
	circle(4,4);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
	glTranslatef(-6,2,0);
	circle(4,4);
    glPopMatrix();

}
void tree(){

    glBegin(GL_POLYGON);
    glColor3f(0.7265, 0.20, 0.1);
    glVertex2f(-0.5,0.0);
    glVertex2f(0.5,0.0);
    glVertex2f(0.75,-10.0);
    glVertex2f(-0.75,-10.0);
	glEnd();

    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0);
	glTranslatef(2,0,0);
	circle(3,3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0);
	glTranslatef(0,2.5,0);
	circle(3,3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0);
	glTranslatef(-2,0,0);
	circle(3,3);
    glPopMatrix();


}
void screen(){

    glBegin(GL_POLYGON);
    glColor3f(0.196, 0.75, 0.8927);
    glVertex2f(1000.0,-20.0);
    glVertex2f(1000.0,50.0);
    glVertex2f(-1000.0,50.0);
    glVertex2f(-1000.0,-20.0);
	glEnd();

	glPushMatrix();
    glColor3f(0.0, 0.5, 0.0);
	glTranslatef(-50,-50,0);
	circle(50,50);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 1.0, 0.186);
    glVertex2f(1000.0,-20.0);
    glVertex2f(1000.0,-50.0);
    glVertex2f(-1000.0,-50.0);
    glVertex2f(-1000.0,-20.0);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7265, 0.20, 0.1);
    glVertex2f(1000.0,32.0);
    glVertex2f(1000.0,29.0);
    glVertex2f(-1000.0,29.0);
    glVertex2f(-1000.0,32.0);
	glEnd();

}

void display(void)
{
    //glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //printf("%f %f\n",tx,ty);


    glPushMatrix();
	glTranslatef(0,0,0);
	screen();
	glPopMatrix();

    glPushMatrix();
	glTranslatef(30,20,0);
	megh();
	glPopMatrix();

    glPushMatrix();
	glTranslatef(-30,15,0);
	megh();
	glPopMatrix();

    glPushMatrix();
    //glColor3f(0.0, 0.8, 0.0);
	glTranslatef(-10,-10,0);
	tree();
	glPopMatrix();

    glPushMatrix();
	glTranslatef(40,-15,0);
	tree();
	glPopMatrix();

    glPushMatrix();
	glTranslatef(-40,-15,0);
	tree();
	glPopMatrix();
    //Murgi
    glPushMatrix();
	glTranslatef(murgi1,40,0);
	murgi();
	glPopMatrix();

    glPushMatrix();
	glTranslatef(murgi2,40,0);
	murgi();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(murgi3,40,0);
	murgi();
	glPopMatrix();



	//DIM
	for(int i=0;i<totaldim;i++){
        glPushMatrix();
        glColor3f(1.0, 1.0, 0.75);
        glTranslatef(dimX[i],dimY[i],0);
        circle(1.5,2.5);
        glPopMatrix();
	}


    //Patil
    glPushMatrix();
	glColor3f(0.647, 0.1647, 0.1647);
	glTranslatef(tx,ty-2,0);
	circle(5,3);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.1, 0.1);
	//glColor3f(0.647, 0.1647, 0.1647);
	glTranslatef(tx,ty,0);
	circle(5,2);
	glPopMatrix();

//	if(!start){
//        string x="Press HOME to start";
//        print(-10,0,0,x);
//	}


    ostringstream str01;
    ostringstream str02;
    str01 << score;
    string str = "Score: " + str01.str();
    str02 << life;
    string str2 = "Life: " + str02.str();
    print(35,45,0,str);
    print(-45,45,0,str2);

    over();
	glFlush();
}

void init(void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
}


void spe_key(int key, int x, int y)
{
    //printf("%d %d %d\n",x,y,key);


	switch (key) {


        case GLUT_KEY_HOME:
            life=3;
            score=0;
            glutIdleFunc(movingMurgi);
            break;
		case GLUT_KEY_LEFT:
            if(tx>-45)   tx -=5;
            glutPostRedisplay();
            break;

		case GLUT_KEY_RIGHT:
            if(tx<45)   tx +=5;
            glutPostRedisplay();
            break;

//        case GLUT_KEY_DOWN:
//				ty -=5;
//				glutPostRedisplay();
//				break;
//
//		case GLUT_KEY_UP:
//				//ty +=5;
//				movingMurgi();
//				glutPostRedisplay();
//				break;
	  default:
			break;
	}
}
int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1000, 750);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Catch the egg");
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(spe_key);//up,down,left,right
	//PlaySound(TEXT("2.wav"), NULL, SND_SYNC);
	sndPlaySound("2.wav" , SND_ASYNC);
	glutMainLoop();

	return 0;   /* ANSI C requires main to return int. */
}

