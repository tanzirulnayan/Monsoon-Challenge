#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include<string>
#include<cstring>
#include <sstream>
#include<windows.h>
#include<mmsystem.h>

using namespace std;


GLfloat G = 1.0 ;
GLfloat Y = 1.0 ;
GLfloat R = 1.0 ;

GLfloat G1 = 0.0 ;
GLfloat Y1= 0.0 ;
GLfloat R1 = 0.0 ;

GLfloat inc = 0.0 ;
int a=1;
int c=0;
int fi=1,se=1,th=1;


float manXL1=-.45;

float manXR1=-.15;

float speed = 0.05f;

float move= 12.0;

float moveobs= 0.0;
float moveobs1= -10.0;
float moveobs2= 0.0;
float moveobs3= 0.0;
float moveobs4= 0.0;



static int collide= 0;

static float posx=0.0;

int p=0;



void Sprint( float x, float y, char *st)
{
    int l,i;


    l=strlen( st ); /// see how many characters are in text string.
    glColor3f(1.0,1.0,0.0);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); /// location to start printing text
    for( i=0; i < l; i++) /// loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }
}
void stringprint(float x,float y,string str)///converts integer value to character array
{
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    Sprint(x,y,cstr);
}
void intprint(float x,float y,int p)///converts string value to character array
{
    stringstream ss;
    ss << p;
    string str = ss.str();
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    Sprint(x,y,cstr);
}



void human()

    {

       glPushMatrix();

	glTranslatef(0.0,.17,0.0);

        //mouth
       glPushMatrix();


     glTranslatef(.16,-.16, 0.0);
      glColor3f(1.0,0.5,0.02);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.030;
		float x = r * cos(A);
		float y = 1.3*r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();


glPopMatrix();


        //eye
       glPushMatrix();



     glTranslatef(.2,0, 0.0);
      glColor3f(0.0,0.0,0.0);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.035;
		float x = r * cos(A);
		float y = 1.3*r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();


glPopMatrix();


         glPushMatrix();

     //cap

     glTranslatef(-.05,.37, 0.0);
     glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);

	glVertex3f(-.2, -0.0, 0.0);
	glVertex3f(-.2, -0.25, 0.0);
	glVertex3f(.5, -0.25, 0.0);

	glEnd();


glPopMatrix();

//ear
       glPushMatrix();



     glTranslatef(-.05,0, 0.0);
      glColor3f(1.0,0.46,0.22);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.045;
		float x = r * cos(A);
		float y = 1.3*r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();


glPopMatrix();




       glPushMatrix();

     //shoe_L


     glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);

	glVertex3f(-0.9, -1.25, 0.0);
	glVertex3f(-0.75, -1.29, 0.0);
	glVertex3f(-0.75, -1.35, 0.0);
	glVertex3f(-0.9, -1.6, 0.0);

	glEnd();


glPopMatrix();



        //head

    glPushMatrix();
     //glColor3f(1.0,0.66,0.0);
    glColor3f(1.0,0.66,0.22);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.2;
		float x = r * cos(A);
		float y = 1.3*r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

 glPopMatrix();




 //body
    glPushMatrix();

    glColor3f(0.5,0.0,0.0);
    glTranslatef(-0.13, -0.73, 0.0);
    glRotatef(45,-1,-1, 0.0);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.3;
		float x = r * cos(A);
		float y = 1.5*r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

  glPopMatrix();

     //neck
    glPushMatrix();
    glColor3f(1.0,0.66,0.22);
    glBegin(GL_QUADS);

	glVertex3f( .05, -0.25, 0.0);
	glVertex3f(-.05, -0.25, 0.0);
	glVertex3f(-.05, -0.4, 0.0);
	glVertex3f( .05, -0.4, 0.0);

	glEnd();
 glPopMatrix();

    //middle_part
    glPushMatrix();
    glColor3f(0.5,0.0,0.0);
    glBegin(GL_QUADS);

	glVertex3f( -0.4,-0.88, 0.0);
	glVertex3f(  0.00,  -0.88, 0.0);
	glVertex3f(  0.00, -1.17, 0.0);
	glVertex3f( -0.4,-1.17, 0.0);

	glEnd();
 glPopMatrix();
    //hand_l1

     glPushMatrix();

    glColor3f(1.0,0.0,0.0);
    glTranslatef(-0.35, -0.5, 0.0);
    glRotatef(65,3.0,1.0,0.0);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.2;
		float x = 1.5*r * cos(A);
		float y = 1.5*r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

  glPopMatrix();


   //hand_l2

     glPushMatrix();

    glColor3f(1.0,0.0,0.0);
    glTranslatef(-0.52, -0.74, 0.0);
    glRotatef(65,0.5,-1.0,0.0);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.15;
		float x = 1.5*r * cos(A);
		float y = 1.5*r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

  glPopMatrix();



 //hand_R1

     glPushMatrix();

    glColor3f(1.0,0.0,0.0);
    glTranslatef(0.25, -0.65, 0.0);
    glRotatef(65,1.0,-1.0,0.0);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.2;
		float x = 1.5*r * cos(A);
		float y = 1.5*r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

  glPopMatrix();



   //hand_R2

     glPushMatrix();

    glColor3f(1.0,0.0,0.0);
    glTranslatef(0.52, -0.66, 0.0);
    glRotatef(65,-0.5,-0.5,0.0);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.15;
		float x = 0.8*r * cos(A);
		float y = 1.7*r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

  glPopMatrix();


  //hand_L3

   glPushMatrix();

    //glColor3f(1.0,0.66,0.0);
    glColor3f(1.0,0.66,0.22);
    glTranslatef(-0.42, -0.95, 0.0);
    //glRotatef(65,-0.5,-0.5,0.0);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.08;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

  glPopMatrix();


  //hand_R3

   glPushMatrix();

    //glColor3f(1.0,0.66,0.0);
    glColor3f(1.0,0.66,0.22);
    glTranslatef(0.56, -0.5, 0.0);
    //glRotatef(65,-0.5,-0.5,0.0);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.08;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

  glPopMatrix();


    //leg_l1
      glPushMatrix();

     glColor3f(0.9,0.9,0.9);
     glTranslatef(-0.4, -1.25, 0.0);
     glRotatef(60,-1,-1, 0.0);


    glBegin(GL_POLYGON);
	  for(int i=0;i<200;i++)
	   {
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.19;
		float x = r * cos(A);
		float y = 1.5*r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

 glPopMatrix();


    //leg_l2

      glPushMatrix();

     glColor3f(0.9,0.9,0.9);
     glTranslatef(-0.70, -1.37, 0.0);
     glRotatef(60,1,-0.5, 0.0);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.2;
		float x = r * cos(A);
		float y = 0.9*r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

 glPopMatrix();


   //leg_R1

    glPushMatrix();

     glColor3f(0.9,0.9,0.9);
     glTranslatef(-0.1, -1.25, 0.0);
     glRotatef(60,-1,1, 0.0);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.19;
		float x = r * cos(A);
		float y = 1.5*r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

 glPopMatrix();

      //leg_R2

    glPushMatrix();

     glColor3f(0.9,0.9,0.9);
     glTranslatef(0.07, -1.55, 0.0);
     glRotatef(-60,1,-1, 0.0);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.2;
		float x = 0.7 *r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

 glPopMatrix();





      //shoe_R
    glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);

	glVertex3f(0.15, -1.65, 0.0);
	glVertex3f(0.2, -1.65, 0.0);
	glVertex3f(0.45, -1.77, 0.0);
	glVertex3f(0.15, -1.77, 0.0);

	glEnd();


 glPopMatrix();

      glPopMatrix();
    glPopMatrix();

    glPopMatrix();




    }



void solidCircle()
{
        glPushMatrix();
            glTranslatef(0.1,0.1,0.0);
            //glScalef(1.8,0.8,0.0);
            glPushMatrix();
            glColor3f(0.0,0.0,0.0); //wheel color left//
            glBegin(GL_POLYGON);
            for(int i=0;i<100;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/100;
                float r=0.2;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
            glEnd();
        glPopMatrix();

}

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 0);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;




void quads()
{

    glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(.45,2.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();
}



void obstacle1()
{
    glPushMatrix();
    glTranslatef(moveobs-4, 0.0, 0.0);
    glScalef(0.7,0.7,0.0);
    glTranslatef(-0.3, -1.5, -7.0);
    glPushMatrix();
    glTranslatef(0.3,0,0);
    glScalef(2.9,1.5,0.0);
    solidCircle();
    glPopMatrix();

    glPopMatrix();


}

void obstacle2()
{
    glPushMatrix();
    glTranslatef(moveobs-4, 0.0, 0.0);
    glScalef(0.7,0.7,0.0);
    glTranslatef(1.3, -1.5, -7.0);
    glPushMatrix();
    glTranslatef(1.8,-0.9,0);
    glScalef(2.9,1.5,0.0);
    solidCircle();
    glPopMatrix();

    glPopMatrix();



}

void obstacle3()
{
    glPushMatrix();
    glTranslatef(moveobs2-4, 0.0, 0.0);
    glScalef(0.7,0.7,0.0);
    glTranslatef(1.3, -1.5, -7.0);
    glPushMatrix();
    glTranslatef(-4.5,-0.9,0);
    glScalef(2.9,1.5,0.0);
    solidCircle();
    glPopMatrix();

    glPopMatrix();



}

void obstacle4()
{
    glPushMatrix();
    glTranslatef(moveobs4-4, 0.0, 0.0);
    glTranslatef(7, -1.4, 0.0);
    glPushMatrix();



    quads();
    glPopMatrix();
    glPopMatrix();



}


void SmallStripsForRoad()
{
    glPushMatrix();
    glTranslatef(move-4, 0.0, 0.0);
    glTranslatef(2, 0.0, 0.0);

    glBegin(GL_QUADS);
	glVertex3f(-6.0, -1.2, 0.0);
	glVertex3f(-7.0, -1.2, 0.0);
	glVertex3f(-7.0, -1.3, 0.0);
	glVertex3f(-6.0, -1.3, 0.0);
	glEnd();


    glBegin(GL_QUADS);

	glVertex3f(-4.0, -1.2, 0.0);
	glVertex3f(-5.0, -1.2, 0.0);
	glVertex3f(-5.0, -1.3, 0.0);
	glVertex3f(-4.0, -1.3, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-2.0, -1.2, 0.0);
	glVertex3f(-3.0, -1.2, 0.0);
	glVertex3f(-3.0, -1.3, 0.0);
	glVertex3f(-2.0, -1.3, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.0, -1.2, 0.0);
	glVertex3f(-1.0, -1.2, 0.0);
	glVertex3f(-1.0, -1.3, 0.0);
	glVertex3f(0.0, -1.3, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(2.0, -1.2, 0.0);
	glVertex3f(1.0, -1.2, 0.0);
	glVertex3f(1.0, -1.3, 0.0);
	glVertex3f(2.0, -1.3, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(4.0, -1.2, 0.0);
	glVertex3f(3.0, -1.2, 0.0);
	glVertex3f(3.0, -1.3, 0.0);
	glVertex3f(4.0, -1.3, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(6.0, -1.2, 0.0);
	glVertex3f(5.0, -1.2, 0.0);
	glVertex3f(5.0, -1.3, 0.0);
	glVertex3f(6.0, -1.3, 0.0);
	glEnd();
	glPopMatrix();



	glPopMatrix();

}



void road()
{

    //upper white border
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
	glVertex3f(7.0, -0.6, 0.0);
	glVertex3f(-7.0, -0.6, 0.0);
	glVertex3f(-7.0, -0.7, 0.0);
	glVertex3f(7.0, -0.7, 0.0);
	glEnd();

	//lower white border
    glBegin(GL_QUADS);
	glVertex3f(7.0, -1.8, 0.0);
	glVertex3f(-7.0, -1.8, 0.0);
	glVertex3f(-7.0, -1.9, 0.0);
	glVertex3f(7.0, -1.9, 0.0);
	glEnd();

	//small white stripes
    SmallStripsForRoad();

    //road
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);
	glVertex3f(7.0, -2.0, 0.0);
	glVertex3f(-7.0, -2.0, 0.0);
	glVertex3f(-7.0, -0.5, 0.0);
	glVertex3f(7.0, -0.5, 0.0);
	glEnd();
}




void lifeLineSingle()
{
    glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);
	glEnd();


}

void lifeLineTotal()
{
    ///green
    glPushMatrix();
    glColor3f(G1,G,G1);
    glScalef(0.4,0.7,0.0);
    lifeLineSingle();
	glPopMatrix();

    ///yellow
	glPushMatrix();
    glColor3f(Y,Y,Y1);
    glScalef(0.4,0.7,0.0);
	glTranslatef(1.71, 0.0, 1.0); //Move to the center of the triangle
    lifeLineSingle();
	glPopMatrix();


	///red
	glPushMatrix();
    glColor3f(R,R1,R1);
    glScalef(0.4,0.7,0.0);
	glTranslatef(3.42, 0.0, 1.0); //Move to the center of the triangle
    lifeLineSingle();
	glPopMatrix();
}




	void name()
{   glTranslatef(0,3.5,0);

	glPushMatrix();


    ///M
	glPushMatrix();



    glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.5, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-2.46, 0.29, 0.0);

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(0.0, -0.8, 0.0);
	glScalef(0.09,0.3,0); //Move to the center of the trapezoid
    //glRotatef(40 ,1.0, 0.0, 1.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.8, -0.6, 0.0);
	glVertex3f(0.8, -0.2, 0.0);
	glVertex3f(0.0, 0.4, 0.0);

	glEnd();
	glPopMatrix();



	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(0.0, -0.8, 0.0);
	glScalef(0.09,0.3,0); //Move to the center of the trapezoid
    //glRotatef(40 ,1.0, 0.0, 1.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.8, -0.6, 0.0);
	glVertex3f(1.6, 0.0, 0.0);
	glVertex3f(1.6, 0.4, 0.0);
	glVertex3f(0.8, -0.2, 0.0);

	glEnd();
	glPopMatrix();




	glPopMatrix();


	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.32, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();




	glPopMatrix();




	///0
	glPushMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -0.67, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.09, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);



    glEnd();
	glPopMatrix();






	glPopMatrix();




	///N

	glPushMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-1.98, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-1.82, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-2.46, 0.29, 0.0);

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(0.5, -0.8, 0.0);
	glScalef(0.09,0.3,0); //Move to the center of the trapezoid
    //glRotatef(40 ,1.0, 0.0, 1.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.6, -1.0, 0.0);
	glVertex3f(1.6, -0.4, 0.0);
	glVertex3f(0.0, 0.4, 0.0);

	glEnd();
	glPopMatrix();


	glPopMatrix();



	///S

	glPushMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-1.65, -0.7, 0.0);
	glScalef(0.09,0.2,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-1.65, -0.7, 0.0);
	glScalef(0.09,0.2,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-1.65, -0.55, 0.0);
	glScalef(0.09,0.2,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);
	glEnd();
	glPopMatrix();


    glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-1.54, -0.9, 0.0);
	glScalef(0.09,0.2,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-1.65, -0.9, 0.0);
	glScalef(0.09,0.2,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);
	glEnd();
	glPopMatrix();




	glPopMatrix();



	///0
    glPushMatrix();
    glTranslatef(0.8, 0.0, 0.0);
	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -0.67, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.09, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);



    glEnd();
	glPopMatrix();






	glPopMatrix();



	///0
    glPushMatrix();
    glTranslatef(1.05, 0.0, 0.0);
	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -0.67, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.09, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);



    glEnd();
	glPopMatrix();






	glPopMatrix();



	///N
    glPushMatrix();
    glTranslatef(1.03, 0.0, 0.0);
	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-1.94, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-1.75, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-1.9, 0.29, 0.0);

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(0.0, -0.8, 0.0);
	glScalef(0.09,0.3,0); //Move to the center of the trapezoid
    //glRotatef(40 ,1.0, 0.0, 1.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.6, -1.0, 0.0);
	glVertex3f(1.6, -0.4, 0.0);
	glVertex3f(0.0, 0.4, 0.0);

	glEnd();
	glPopMatrix();




	glPopMatrix();
	glPopMatrix();


	///shes

	///CHALLENGE

	///C

	glPushMatrix();

	///-------------c-----------------

	glPushMatrix();
    glTranslatef(1.85, 0.0, 0.0);
	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -0.67, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();








	glPopMatrix();


	///H

	glPushMatrix();
    glTranslatef(2.49, 0.0, 0.0);
    glScalef(1.19,1.0,0);
	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();



	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -0.85, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.09, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);



    glEnd();
	glPopMatrix();






	glPopMatrix();



	///A

    glPushMatrix();
    glTranslatef(2.32, 0.0, 0.0);
	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -0.85, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -0.67, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.09, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);



    glEnd();
	glPopMatrix();






	glPopMatrix();



	///L
	glPushMatrix();
    glTranslatef(2.55, 0.0, 0.0);

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);



	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -0.67, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();





    glEnd();
	glPopMatrix();






	glPopMatrix();


	///L
	glPushMatrix();
    glTranslatef(2.75, 0.0, 0.0);

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);



	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -0.67, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();





    glEnd();
	glPopMatrix();






	glPopMatrix();



	///E

    glPushMatrix();
    glTranslatef(2.95, 0.0, 0.0);
	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -0.67, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -0.84, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();








	glPopMatrix();


	///N
    glPushMatrix();
    glTranslatef(2.94, 0.0, 0.0);
	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-1.947, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-1.80, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-1.93, 0.29, 0.0);

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(0.0, -0.8, 0.0);
	glScalef(0.09,0.3,0); //Move to the center of the trapezoid
    //glRotatef(40 ,1.0, 0.0, 1.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.6, -1.0, 0.0);
	glVertex3f(1.6, -0.4, 0.0);
	glVertex3f(0.0, 0.4, 0.0);

	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	///G

	glPushMatrix();
    glTranslatef(3.45, 0.0, 0.0);
	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -0.67, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.09, -0.9, 0.0);
	glScalef(0.09,0.2,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

    glEnd();
	glPopMatrix();

	glPopMatrix();

	///E

    glPushMatrix();
    glTranslatef(3.65, 0.0, 0.0);
	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -1.0, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -0.67, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.2, -0.84, 0.0);
	glScalef(0.09,0.4,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
	glBegin(GL_QUADS);
	//Triangle
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.7, 0.0);
	glVertex3f(0.0, 0.7, 0.0);

	glEnd();
	glPopMatrix();

	glPopMatrix();

	///challenge shes

	glPopMatrix();

    ///shes2

	glPopMatrix();

}

	void blueSky()
{
    /*glColor3f(0.0,0.1,0.5);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 6.0, 0.0);
	glVertex3f(-7.0, 6.0, 0.0);
	glVertex3f(-7.0, 7.0, 0.0);
	glVertex3f(7.0, 7.0, 0.0);
	glEnd();
	glColor3f(0.0,0.1,0.5);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 5.0, 0.0);
	glVertex3f(-7.0, 5.0, 0.0);
	glVertex3f(-7.0, 6.0, 0.0);
	glVertex3f(7.0, 6.0, 0.0);
	glEnd();
	glColor3f(0.0,0.1,0.5);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 4.0, 0.0);
	glVertex3f(-7.0, 4.0, 0.0);
	glVertex3f(-7.0, 5.0, 0.0);
	glVertex3f(7.0, 5.0, 0.0);
	glEnd();*/
	glColor3f(0.15,0.5,0.6);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 3.0, 0.0);
	glVertex3f(-7.0, 3.0, 0.0);
	glVertex3f(-7.0, 4.0, 0.0);
	glVertex3f(7.0, 4.0, 0.0);
	glEnd();
	glColor3f(0.15,0.50,0.65);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 2.75, 0.0);
	glVertex3f(-7.0, 2.75, 0.0);
	glVertex3f(-7.0, 3.75, 0.0);
	glVertex3f(7.0, 3.75, 0.0);
	glEnd();
	glColor3f(0.15,0.5,0.70);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 2.5, 0.0);
	glVertex3f(-7.0, 2.5, 0.0);
	glVertex3f(-7.0, 3.5, 0.0);
	glVertex3f(7.0, 3.5, 0.0);
	glEnd();
	glColor3f(0.15,0.55,0.75);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 2.25, 0.0);
	glVertex3f(-7.0, 2.25, 0.0);
	glVertex3f(-7.0, 3.25, 0.0);
	glVertex3f(7.0, 3.25, 0.0);
	glEnd();
	glColor3f(0.15,0.60,8.0);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 2.0, 0.0);
	glVertex3f(-7.0, 2.0, 0.0);
	glVertex3f(-7.0, 3.0, 0.0);
	glVertex3f(7.0, 3.0, 0.0);
	glEnd();
	glColor3f(0.20,0.65,8.5);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 1.75, 0.0);
	glVertex3f(-7.0, 1.75, 0.0);
	glVertex3f(-7.0, 2.75, 0.0);
	glVertex3f(7.0, 2.75, 0.0);
	glEnd();
	glColor3f(0.25,0.7,0.9);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 1.5, 0.0);
	glVertex3f(-7.0, 1.5, 0.0);
	glVertex3f(-7.0, 2.5, 0.0);
	glVertex3f(7.0, 2.5, 0.0);
	glEnd();
	glColor3f(0.30,.75,0.95);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 1.25, 0.0);
	glVertex3f(-7.0, 1.25, 0.0);
	glVertex3f(-7.0, 2.25, 0.0);
	glVertex3f(7.0, 2.25, 0.0);
	glEnd();
	glColor3f(0.4,.8,1.0);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 1.0, 0.0);
	glVertex3f(-7.0, 1.0, 0.0);
	glVertex3f(-7.0, 2.0, 0.0);
	glVertex3f(7.0, 2.0, 0.0);
	glEnd();
}
void walkwayGrass()
{
    glColor3f(0.0,0.7,0.1);
    glBegin(GL_QUADS);
    glVertex3f(7.0, -0.5, 0.0);
	glVertex3f(-7.0, -0.5, 0.0);
	glVertex3f(-7.0, 0.0, 0.0);
	glVertex3f(7.0, 0.0, 0.0);
	glEnd();
}
void tree_1()
{
//tree_n1
    glColor3f(0.0,0.7,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(2.8, 0.5,0.0);
	glVertex3f(3.8, 0.5, 0.0);
    glVertex3f(3.3, 1.45, 0.0);
    glEnd();

    glColor3f(0.0,0.8,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(2.8, 0.7,0.0);
	glVertex3f(3.8, 0.7, 0.0);
    glVertex3f(3.3, 1.7, 0.0);
    glEnd();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(2.8, 0.9,0.0);
	glVertex3f(3.8, 0.9, 0.0);
    glVertex3f(3.3, 1.95, 0.0);
    glEnd();

    glColor3f(0.4,0.0,0.0);
    glBegin(GL_QUADS);
	glVertex3f(3.225, 0,0.0);
	glVertex3f(3.375, 0, 0.0);
    glVertex3f(3.375, 1.0, 0.0);
    glVertex3f(3.225, 1.0, 0.0);
    glEnd();
}
void tree_2()
{
    //tree_n2
    glColor3f(0.0,0.8,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(3.2, 0.7,0.0);
	glVertex3f(4.2, 0.7, 0.0);
    glVertex3f(3.7, 1.7, 0.0);
    glEnd();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(3.2, 0.9,0.0);
	glVertex3f(4.2, 0.9, 0.0);
    glVertex3f(3.7, 2.25, 0.0);
    glEnd();

    glColor3f(0.4,0.0,0.0);
    glBegin(GL_QUADS);
	glVertex3f(3.6, 0,0.0);
	glVertex3f(3.8, 0, 0.0);
    glVertex3f(3.8, 1.0, 0.0);
    glVertex3f(3.6, 1.0, 0.0);
    glEnd();
}

void tree_3()
{


     //tree_n3
    glColor3f(0.0,0.7,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(3.6, 0.5,0.0);
	glVertex3f(4.6, 0.5, 0.0);
    glVertex3f(4.1, 1.45, 0.0);
    glEnd();

    glColor3f(0.0,0.8,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(3.6, 0.7,0.0);
	glVertex3f(4.6, 0.7, 0.0);
    glVertex3f(4.1, 1.7, 0.0);
    glEnd();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(3.6, 0.9,0.0);
	glVertex3f(4.6, 0.9, 0.0);
    glVertex3f(4.1, 1.95, 0.0);
    glEnd();

    glColor3f(0.4,0.0,0.0);
    glBegin(GL_QUADS);
	glVertex3f(4.025, 0,0.0);
	glVertex3f(4.175, 0, 0.0);
    glVertex3f(4.175, 1.0, 0.0);
    glVertex3f(4.025, 1.0, 0.0);
    glEnd();


}
void tree_4()
{
     //tree_n4
    glColor3f(0.0,0.7,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(-2.7, 0.5,0.0);
	glVertex3f(-1.8, 0.5, 0.0);
    glVertex3f(-2.2, 1.45, 0.0);
    glEnd();

    glColor3f(0.0,0.8,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(-2.7, 0.7,0.0);
	glVertex3f(-1.8, 0.7, 0.0);
    glVertex3f(-2.2, 1.7, 0.0);
    glEnd();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(-2.7, 0.9,0.0);
	glVertex3f(-1.8, 0.9, 0.0);
    glVertex3f(-2.2, 1.95, 0.0);
    glEnd();

    glColor3f(0.4,0.0,0.0);
    glBegin(GL_QUADS);
	glVertex3f(-2.275, 0,0.0);
	glVertex3f(-2.125, 0, 0.0);
    glVertex3f(-2.155, 1.0, 0.0);
    glVertex3f(-2.275, 1.0, 0.0);
    glEnd();

}
void tree_5()
{





    glColor3f(0.0,0.8,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(-2.3, 0.7,0.0);
	glVertex3f(-1.3, 0.7, 0.0);
    glVertex3f(-1.8, 1.7, 0.0);
    glEnd();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(-2.3, 0.9,0.0);
	glVertex3f(-1.3, 0.9, 0.0);
    glVertex3f(-1.8, 2.25, 0.0);
    glEnd();

    glColor3f(0.4,0.0,0.0);
    glBegin(GL_QUADS);
	glVertex3f(-1.9, 0,0.0);
	glVertex3f(-1.7, 0, 0.0);
    glVertex3f(-1.7, 1.0, 0.0);
    glVertex3f(-1.9, 1.0, 0.0);
    glEnd();



}

void tree_6()
{

 //tree_n6
    glColor3f(0.0,0.7,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(-1.9, 0.5,0.0);
	glVertex3f(-0.9, 0.5, 0.0);
    glVertex3f(-1.4, 1.45, 0.0);
    glEnd();

    glColor3f(0.0,0.8,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(-1.9, 0.7,0.0);
	glVertex3f(-0.9, 0.7, 0.0);
    glVertex3f(-1.4, 1.7, 0.0);
    glEnd();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
	glVertex3f(-1.9, 0.9,0.0);
	glVertex3f(-0.9, 0.9, 0.0);
    glVertex3f(-1.4, 1.95, 0.0);
    glEnd();

    glColor3f(0.4,0.0,0.0);
    glBegin(GL_QUADS);
	glVertex3f(-1.475, 0,0.0);
	glVertex3f(-1.325, 0, 0.0);
    glVertex3f(-1.325, 1.0, 0.0);
    glVertex3f(-1.475, 1.0, 0.0);
    glEnd();
}

void home_blue()
{

 /*   //rooftop
    glColor3f(0.0,0.0,0.5);
    glBegin(GL_QUADS);
	glVertex3f(-0.4, 0.875,0.0);
	glVertex3f(-0.1, 0.875, 0.0);
    glVertex3f(0.75, 1.5, 0.0);
    glVertex3f(0.75, 1.7, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(1.6,0.875, 0.0);
	glVertex3f(1.9, 0.875, 0.0);
	glVertex3f(0.75, 1.7, 0.0);
    glVertex3f(0.75, 1.5, 0.0);
	glEnd();

    //home_roof_s1
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_TRIANGLES);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(1.5, 1.0, 0.0);
	glVertex3f(0.75, 1.5, 0.0);
	glEnd();
*/
    //window
    glColor3f(0.3,0.3,0.3);
    glBegin(GL_QUADS);
	glVertex3f(0.7, 0.35, 0.0);
	glVertex3f(1.36, 0.35, 0.0);
	glVertex3f(1.36, 0.65, 0.0);
	glVertex3f(0.7 ,0.65, 0.0);
	glEnd();

     //door_glass
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
	glVertex3f(0.37, 0.35, 0.0);
	glVertex3f(0.47, 0.35, 0.0);
	glVertex3f(0.47, 0.55, 0.0);
	glVertex3f(0.37 ,0.55, 0.0);
	glEnd();

	//door
    glColor3f(0.0,0.0,0.5);
    glBegin(GL_QUADS);
	glVertex3f(0.3, 0.125, 0.0);
	glVertex3f(0.55, 0.125, 0.0);
	glVertex3f(0.55, 0.6, 0.0);
	glVertex3f(0.3 ,0.6, 0.0);
	glEnd();

    //stairs
    glColor3f(0.5,0.7,0.5);
    glBegin(GL_QUADS);
	glVertex3f(0.3, 0.0, 0.0);
	glVertex3f(0.55, 0.0, 0.0);
	glVertex3f(0.55, 0.064, 0.0);
	glVertex3f(0.3 ,0.064, 0.0);
	glEnd();

    glColor3f(0.5,0.8,0.5);
	glBegin(GL_QUADS);
    glVertex3f(0.3, 0.064, 0.0);
	glVertex3f(0.55 ,0.064, 0.0);
	glVertex3f(0.55, 0.125, 0.0);
	glVertex3f(0.3, 0.125, 0.0);
	glEnd();

    //home_bottom_s1_line
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.5, 0.0, 0.0);
	glVertex3f(1.5, 0.01, 0.0);
	glVertex3f(0.0 ,0.01, 0.0);
	glEnd();

    //home_bottom_s1
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.5, 0.0, 0.0);
	glVertex3f(1.5, 0.125, 0.0);
	glVertex3f(0.0 ,0.125, 0.0);
	glEnd();

    //garage_line
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_QUADS);
	glVertex3f(1.8, 0.0, 0.0);
	glVertex3f(2.7, 0.0, 0.0);
	glVertex3f(2.7, 0.01, 0.0);
	glVertex3f(1.8 ,0.01, 0.0);
	glEnd();

	  //line_straight

    glColor3f(0.0,0.0,0.5);
    glBegin(GL_QUADS);
    glVertex3f(1.49, 0.0, 0.0);
	glVertex3f(1.5 ,0.0, 0.0);
	glVertex3f(1.5, 1.5, 0.0);
	glVertex3f(1.49, 1.5, 0.0);
	glEnd();

    //garage
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
	glVertex3f(1.8, 0.0, 0.0);
	glVertex3f(2.7, 0.0, 0.0);
	glVertex3f(2.7, 0.5, 0.0);
	glVertex3f(1.8 ,0.5, 0.0);
	glEnd();

	//garage street
    glColor3f(0.3,0.3,0.3);
    glBegin(GL_QUADS);
	glVertex3f(1.8, 0.0, 0.0);
	glVertex3f(2.7, 0.0, 0.0);
	glVertex3f(3.1, -0.5, 0.0);
	glVertex3f(2.2 , -0.5, 0.0);
	glEnd();

    //home_s1
    glColor3f(0.0,0.0,0.8);
    glBegin(GL_QUADS);
	glVertex3f(0.0, 1.7, 0.0);
	glVertex3f(1.5, 1.7, 0.0);
	glVertex3f(1.5, 1.5, 0.0);
	glVertex3f(0.0 ,1.5, 0.0);
	glEnd();


    //home_s1
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.5, 0.0, 0.0);
	glVertex3f(1.5, 1.5, 0.0);
	glVertex3f(0.0 ,1.5, 0.0);
	glEnd();



    //home_roof_s2
  /*  glColor3f(0.0,0.0,0.8);
    glBegin(GL_QUADS);
	glVertex3f(1.5, 0.8, 0.0);
	glVertex3f(3.0, 0.8, 0.0);
	glVertex3f(2.5, 1.4, 0.0);
	glVertex3f(1.0 ,1.4, 0.0);
	glEnd();
  */
    //home_line_s2
    glColor3f(0.0,0.0,0.5);
    glBegin(GL_QUADS);
    glVertex3f(3.0, 0.75, 0.0);
	glVertex3f(1.5 ,0.75, 0.0);
	glVertex3f(1.5, 0.8, 0.0);
	glVertex3f(3.0, 0.8, 0.0);
	glEnd();

	//home_line_g

	glColor3f(0.0,0.0,0.8);
    glBegin(GL_QUADS);
    glVertex3f(3.0, 0.95, 0.0);
	glVertex3f(1.5 ,0.95, 0.0);
	glVertex3f(1.5, 0.8, 0.0);
	glVertex3f(3.0, 0.8, 0.0);
	glEnd();


    //home_line_s2_new
    glColor3f(0.0,0.0,0.5);
    glBegin(GL_QUADS);
    glVertex3f(3.0, 0.95, 0.0);
	glVertex3f(1.5 ,0.95, 0.0);
	glVertex3f(1.5, 1.0, 0.0);
	glVertex3f(3.0, 1.0, 0.0);
	glEnd();




   //home_s2
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_QUADS);
	glVertex3f(1.5, 0.0, 0.0);
	glVertex3f(3.0, 0.0, 0.0);
	glVertex3f(3.0, 0.75, 0.0);
	glVertex3f(1.5 ,0.75, 0.0);
	glEnd();
}

void home_red()
{

    //////Home2/////
    //rooftop
    glColor3f(0.7,0.0,0.0);
    glBegin(GL_QUADS);
	glVertex3f(-5.9, 0.875,0.0);
	glVertex3f(-5.6, 0.875, 0.0);
    glVertex3f(-4.75, 1.5, 0.0);
    glVertex3f(-4.75, 1.7, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-3.9,0.875, 0.0);
	glVertex3f(-3.6, 0.875, 0.0);
	glVertex3f(-4.75, 1.7, 0.0);
    glVertex3f(-4.75, 1.5, 0.0);
	glEnd();

    //home_roof_s1
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_TRIANGLES);
	glVertex3f(-5.5, 1.0, 0.0);
	glVertex3f(-4.0, 1.0, 0.0);
	glVertex3f(-4.75, 1.5, 0.0);
	glEnd();

    //window
    glColor3f(0.7,0.0,0.0);
    glBegin(GL_QUADS);
	glVertex3f(-5.1, 0.35, 0.0);
	glVertex3f(-4.9, 0.35, 0.0);
	glVertex3f(-4.9, 0.7, 0.0);
	glVertex3f(-5.1 ,0.7, 0.0);
	glEnd();

    glBegin(GL_QUADS);
	glVertex3f(-5.4, 0.35, 0.0);
	glVertex3f(-5.2, 0.35, 0.0);
	glVertex3f(-5.2, 0.7, 0.0);
	glVertex3f(-5.4 ,0.7, 0.0);
	glEnd();

    //door_glass
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
	glVertex3f(-4.43, 0.35, 0.0);
	glVertex3f(-4.33, 0.35, 0.0);
	glVertex3f(-4.33, 0.55, 0.0);
	glVertex3f(-4.43 ,0.55, 0.0);
	glEnd();

	//door
    glColor3f(0.7,0.0,0.0);
    glBegin(GL_QUADS);
	glVertex3f(-4.5, 0.125, 0.0);
	glVertex3f(-4.25, 0.125, 0.0);
	glVertex3f(-4.25, 0.6, 0.0);
	glVertex3f(-4.5 ,0.6, 0.0);
	glEnd();

    //stairs
    glColor3f(0.5,0.7,0.5);
    glBegin(GL_QUADS);
	glVertex3f(-4.5, 0.0, 0.0);
	glVertex3f(-4.25, 0.0, 0.0);
	glVertex3f(-4.25, 0.064, 0.0);
	glVertex3f(-4.5 ,0.064, 0.0);
	glEnd();

    glColor3f(0.5,0.8,0.5);
	glBegin(GL_QUADS);
    glVertex3f(-4.25, 0.064, 0.0);
	glVertex3f(-4.5 ,0.064, 0.0);
	glVertex3f(-4.5, 0.125, 0.0);
	glVertex3f(-4.25, 0.125, 0.0);
	glEnd();

    //home_bottom_s1_line
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_QUADS);
	glVertex3f(-5.5, 0.0, 0.0);
	glVertex3f(-4.0, 0.0, 0.0);
	glVertex3f(-4.0, 0.01, 0.0);
	glVertex3f(-5.5 ,0.01, 0.0);
	glEnd();

    //home_bottom_s1
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
	glVertex3f(-5.5, 0.0, 0.0);
	glVertex3f(-4.0, 0.0, 0.0);
	glVertex3f(-4.0, 0.125, 0.0);
	glVertex3f(-5.5 ,0.125, 0.0);
	glEnd();

    //garage_line
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_QUADS);
	glVertex3f(-3.7, 0.0, 0.0);
	glVertex3f(-2.8, 0.0, 0.0);
	glVertex3f(-2.8, 0.01, 0.0);
	glVertex3f(-3.7 ,0.01, 0.0);
	glEnd();

    //garage
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
	glVertex3f(-3.7, 0.0, 0.0);
	glVertex3f(-2.8, 0.0, 0.0);
	glVertex3f(-2.8, 0.5, 0.0);
	glVertex3f(-3.7 ,0.5, 0.0);
	glEnd();

	//garage street
    glColor3f(0.3,0.3,0.3);
    glBegin(GL_QUADS);
	glVertex3f(-3.7, 0.0, 0.0);
	glVertex3f(-2.8, 0.0, 0.0);
	glVertex3f(-2.4, -0.5, 0.0);
	glVertex3f(-3.3 ,-0.5, 0.0);
	glEnd();

    //home_s1
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_QUADS);
	glVertex3f(-5.5, 0.0, 0.0);
	glVertex3f(-4.0, 0.0, 0.0);
	glVertex3f(-4.0, 1.0, 0.0);
	glVertex3f(-5.5 ,1.0, 0.0);
	glEnd();

    //home_roof_s2
    glColor3f(0.9,0.0,0.0);
    glBegin(GL_QUADS);
	glVertex3f(-4.0, 0.8, 0.0);
	glVertex3f(-2.5, 0.8, 0.0);
	glVertex3f(-3.0, 1.4, 0.0);
	glVertex3f(-4.5 ,1.4, 0.0);
	glEnd();

    //home_line_s2
    glColor3f(0.7,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex3f(-2.5, 0.75, 0.0);
	glVertex3f(-4.0 ,0.75, 0.0);
	glVertex3f(-4.0, 0.8, 0.0);
	glVertex3f(-2.5, 0.8, 0.0);
	glEnd();

   //home_s2
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_QUADS);
	glVertex3f(-2.5, 0.0, 0.0);
	glVertex3f(-4.0, 0.0, 0.0);
	glVertex3f(-4.0, 0.75, 0.0);
	glVertex3f(-2.5 ,0.75, 0.0);
	glEnd();
}

void buildings()
{


    //extra

     glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(7.0, 0.0, 0.0);
	glVertex3f(7.0,1.5, 0.0);
	glVertex3f(20.0, 1.5, 0.0);
	glVertex3f(20.0, 0, 0.0);
	glEnd();


    glPushMatrix();
    glTranslatef(6,0,0);


	//1st







	glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(1.0, 1.25, 0.0);
	glVertex3f(1.5, 1.25, 0.0);
	glVertex3f(1.5, 0, 0.0);
	glEnd();

	glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(1.0, 2.0, 0.0);
	glVertex3f(0.0, 2.0, 0.0);
	glVertex3f(0.0, 0, 0.0);
	glEnd();



    glPopMatrix();

    // extra

 glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(-20.0, 0.0, 0.0);
	glVertex3f(-20.0,1.5, 0.0);
	glVertex3f(-6.0, 1.5, 0.0);
	glVertex3f(-6.0, 0, 0.0);
	glEnd();


    //1st
     glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(6.0, 0.0, 0.0);
	glVertex3f(6.0,2.0, 0.0);
	glVertex3f(5.0, 2.0, 0.0);
	glVertex3f(5.0, 0, 0.0);
	glEnd();

	//1st
glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(5.0, 0.0, 0.0);
	glVertex3f(5.0, 1.5, 0.0);
	glVertex3f(4.0, 1.5, 0.0);
	glVertex3f(4.0, 0, 0.0);
	glEnd();

    glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(4.0, 0.0, 0.0);
	glVertex3f(4.0, 2.5, 0.0);
	glVertex3f(3.25, 2.5, 0.0);
	glVertex3f(3.25, 0, 0.0);
	glEnd();

	 glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(3.25, 0.0, 0.0);
	glVertex3f(3.25, 1.25, 0.0);
	glVertex3f(2.1, 1.25, 0.0);
	glVertex3f(2.1, 0, 0.0);
	glEnd();

	glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(2.1, 0.0, 0.0);
	glVertex3f(2.1, 2.25, 0.0);
	glVertex3f(1.5, 2.25, 0.0);
	glVertex3f(1.5, 0, 0.0);
	glEnd();

	glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(1.0, 1.25, 0.0);
	glVertex3f(1.5, 1.25, 0.0);
	glVertex3f(1.5, 0, 0.0);
	glEnd();

	glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(1.0, 2.0, 0.0);
	glVertex3f(0.0, 2.0, 0.0);
	glVertex3f(0.0, 0, 0.0);
	glEnd();

	 glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(-6.0, 0.0, 0.0);
	glVertex3f(-6.0,2.0, 0.0);
	glVertex3f(-5.0, 2.0, 0.0);
	glVertex3f(-5.0, 0, 0.0);
	glEnd();

	//1st
glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(-5.0, 0.0, 0.0);
	glVertex3f(-5.0, 1.5, 0.0);
	glVertex3f(-4.0, 1.5, 0.0);
	glVertex3f(-4.0, 0, 0.0);
	glEnd();

    glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(-4.0, 0.0, 0.0);
	glVertex3f(-4.0, 2.5, 0.0);
	glVertex3f(-3.25, 2.5, 0.0);
	glVertex3f(-3.25, 0, 0.0);
	glEnd();

	 glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(-3.0, 0.0, 0.0);
	glVertex3f(-3.0, 1.25, 0.0);
	glVertex3f(-2.1, 1.25, 0.0);
	glVertex3f(-2.1, 0, 0.0);

	glEnd();


	glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(-2.1, 0.0, 0.0);
	glVertex3f(-2.1, 1.55, 0.0);
	glVertex3f(-1.5, 1.55, 0.0);
	glVertex3f(-1.5, 0, 0.0);
	glEnd();


	glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(-1.0, 0.0, 0.0);
	glVertex3f(-1.0, 2.25, 0.0);
	glVertex3f(-1.5, 2.25, 0.0);
	glVertex3f(-1.5, 0, 0.0);
	glEnd();

	glColor3f(0.6,0.6,0.6);
    glBegin(GL_QUADS);
	glVertex3f(-1.0, 0.0, 0.0);
	glVertex3f(-1.0, 1.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0, 0.0);
	glEnd();
}


void buildings2()
{
    //extra


    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
	glVertex3f(25.0, 0.0, 0.0);
	glVertex3f(25.0, 1.75, 0.0);
	glVertex3f(6.15, 1.75, 0.0);
	glVertex3f(6.15, 0, 0.0);
	glEnd();

    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
	glVertex3f(-6.0, 0.0, 0.0);
	glVertex3f(-6.0, 1.75, 0.0);
	glVertex3f(-20.15, 1.75, 0.0);
	glVertex3f(-20.15, 0, 0.0);
	glEnd();



    //1st


	//1st
 glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
	glVertex3f(4.7, 0.0, 0.0);
	glVertex3f(4.7, 1.8, 0.0);
	glVertex3f(4.0, 1.8, 0.0);
	glVertex3f(4.0, 0, 0.0);
	glEnd();

     glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
	glVertex3f(4.0, 0.0, 0.0);
	glVertex3f(4.0, 2.2, 0.0);
	glVertex3f(3.25, 2.2, 0.0);
	glVertex3f(3.25, 0, 0.0);
	glEnd();

	 glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
	glVertex3f(3.25, 0.0, 0.0);
	glVertex3f(3.25, 1.75, 0.0);
	glVertex3f(2.1, 1.75, 0.0);
	glVertex3f(2.1, 0, 0.0);
	glEnd();

	 glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
	glVertex3f(2.3, 0.0, 0.0);
	glVertex3f(2.3, 2.25, 0.0);
	glVertex3f(1.5, 2.25, 0.0);
	glVertex3f(1.5, 0, 0.0);
	glEnd();
 glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(1.0, 1.75, 0.0);
	glVertex3f(1.15, 1.75, 0.0);
	glVertex3f(1.15, 0, 0.0);
	glEnd();

	 glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(1.0, 2.7, 0.0);
	glVertex3f(0.7, 2.7, 0.0);
	glVertex3f(0.7, 0, 0.0);
	glEnd();

	 glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
	glVertex3f(-6.0, 0.0, 0.0);
	glVertex3f(-6.0,2.4, 0.0);
	glVertex3f(-5.30, 2.4, 0.0);
	glVertex3f(-5.30, 0, 0.0);
	glEnd();

	//1st
 glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
	glVertex3f(-5.1, 0.0, 0.0);
	glVertex3f(-5.1, 1.5, 0.0);
	glVertex3f(-4.50, 1.5, 0.0);
	glVertex3f(-4.50, 0, 0.0);
	glEnd();

     glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
	glVertex3f(-4.0, 0.0, 0.0);
	glVertex3f(-4.0, 2.9, 0.0);
	glVertex3f(-3.6, 2.9, 0.0);
	glVertex3f(-3.6, 0, 0.0);
	glEnd();

	  glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
	glVertex3f(-3.1, 0.0, 0.0);
	glVertex3f(-3.1, 2.95, 0.0);
	glVertex3f(-2.4, 2.95, 0.0);
	glVertex3f(-2.4, 0, 0.0);

	glEnd();


	 glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
	glVertex3f(-2.02, 0.0, 0.0);
	glVertex3f(-2.2, 2.75, 0.0);
	glVertex3f(-1.5, 2.75, 0.0);
	glVertex3f(-1.5, 0, 0.0);
	glEnd();


 glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
	glVertex3f(-1.8, 0.0, 0.0);
	glVertex3f(-1.8, 2.65, 0.0);
	glVertex3f(-1.25, 2.65, 0.0);
	glVertex3f(-1.25, 0, 0.0);
	glEnd();

	glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
	glVertex3f(-1.0, 0.0, 0.0);
	glVertex3f(-1.0, 2.4, 0.0);
	glVertex3f(0.5, 2.4, 0.0);
	glVertex3f(0.5, 0, 0.0);
	glEnd();
}



void welcomeScene()
{
  name();


     glPushMatrix();
    glScalef(1.0,1.0,0.0);
    glPushMatrix();
    glTranslatef(0.0, posx, 0.0);
    glScalef(0.5,0.5,0.0);
    glPushMatrix();
    glTranslatef(-3.0,- 0.5, 0.0);
    human();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();

	obstacle1();
	glPopMatrix();


	glPushMatrix();

	obstacle2();
	glPopMatrix();


	glPushMatrix();

	obstacle3();
	glPopMatrix();

    glPushMatrix();
	obstacle4();
	glPopMatrix();








	glPushMatrix();
    road();
    glPopMatrix();


 glPopMatrix();


//////////


  glPushMatrix();

   glTranslatef(inc,0.0,0.0);



    tree_2();
    tree_1();
    tree_3();
    home_blue();

    tree_5();
    tree_4();
    tree_6();
    home_red();


    buildings();
    buildings2();

    glPopMatrix();



    walkwayGrass();
//
//    glPushMatrix();
//    glTranslatef(2.7, 2.7, 0.0);
//	lifeLineTotal();
//	glPopMatrix();

     //cloud1();
    // cloud2();
    //cloud3();
    blueSky();





}












void Bul_inc()
{

    inc = inc - .04*a;
    if(inc<-12)
    {
        inc =12 ;
    }



}





void keyboard(unsigned char key, int x, int y)
{
switch (key) {
case 'w':
if(posx==0){
posx=0.0;
glutPostRedisplay();
break;
}
else
{
posx=0.1;
glutPostRedisplay();
break;
}

case 's':
if(posx==0){
posx=-0.5;
glutPostRedisplay();
break;
}
else
{
    posx=-0.5;
    glutPostRedisplay();
    break;
}

if(posx<.7)
 {
 posx=0;
 posx=0;
 glutPostRedisplay();
 break;
 }



}

}


//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.3, -0.75, -7.0);
	 //Move forward 5 units
	glPushMatrix();


    glPushMatrix();///1st column
    glTranslatef(-3.8,2.5,0);
    intprint(.71,.91,p);
    stringprint(-.91,.91,"Score:");
    glPopMatrix();


    glPushMatrix();
	welcomeScene();
	glPopMatrix();





	glPopMatrix();







	glutSwapBuffers();
}




void inc_spd()
{

    inc = inc - .04*a;
    if(inc<-12)
    {
        inc =12 ;
    }



}

void update(int value) {

inc_spd();
    if(moveobs-.8 > 7.1)
    {

        p=p+1;
    }



    moveobs -= speed*a;


	if (moveobs < -4) {
		moveobs += 12;
	}

	moveobs1 -= speed*a;

	if (moveobs1 < -10) {
		moveobs1 += 12;
	}


	moveobs2 -= speed*a;

	if (moveobs2 < -2) {
		moveobs2 += 12;
	}

	moveobs4 -= speed*a;


	if (moveobs4 < -4) {
		moveobs4 += 12;
	}


	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}

	move -= speed*a;

	if (move < 0) {
		move += 4;
	}


    if(moveobs <= 2.5 && manXL1<=posx-.45f && moveobs >= 2)
    {
        collide=1;

    }

    if(moveobs1 <= -9.5 && manXL1>=posx-.15f)
    {
        collide=1;

    }

    if(moveobs2 <= 4.8 && manXL1>=posx-.15f && moveobs2 >= 4.0)

    {
        collide=1;

    }

    if(moveobs4 <= -2.2 && manXL1<=posx-.45f && moveobs >= -2.9)

    {
        collide=1;

    }



//    if(c<3)
//    {
        if(collide!=1)
        {

        glutTimerFunc(20, update, 0);

        }

//
//

        if(collide==1)
        {
//            c++;
//            collide=0;
//            glutTimerFunc(20, update, 0);
            exit(0);

        }

//
//        if(c>2)
//       {
//           G=0.5;
//       }
//    }




//    if(collide==1 && G1==0.5 && G==0.5 )
//    {
//        Y=0.5;
//        Y1=0.5;
//        glutTimerFunc(10, update, 0);
//    }
//    else
//    {
//        cout<<"score:"<<p<<endl;
//        cout<<"status:"<<"Game Over"<<endl;
//        exit(0);
//    }





	glutPostRedisplay(); //Tell GLUT that the display has changed
	//Tell GLUT to call update again in 25 milliseconds

}

int main(int argc, char** argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1355, 705);
	glutInitWindowPosition(0,60);

	//Create the window
	glutCreateWindow("Monsoon Challenge");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);


    PlaySound("mi.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);

	glutKeyboardFunc(keyboard);

	glutTimerFunc(10, update, 0); //Add a timer

	glutMainLoop();
	//PlaySound(TEXT("mi.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
     //PlaySound(TEXT("!step on stage_2.wav"),NULL,SND_SYNC);


	return 0;
}






