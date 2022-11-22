#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
void display();
void obj1();//declaration of ﬂÊ— Ï «·»⁄»⁄ function
void cylinder();//declaration of cylinder function
void reshape(int w,int h);
void timer(int);//a function used in Animation
void init(){
glClearColor(0.0,0.0,0.0,0.1);
}
int main(int argc,char**argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB);
glutInitWindowPosition(200,0);
glutInitWindowSize(1200,800);
glutCreateWindow("20100638");
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutTimerFunc(0,timer,0);
init();
glutMainLoop();

}
float y_position=0.0;//a variable used in animation applied on cylinder function
float x_position=0.0;//a variable used in animation applied on ﬂÊ— Ï «·»⁄»⁄
int state=1;//a variable used in animation applied on cylinder function
//The function of ﬂÊ— Ï «·»⁄»⁄ begins

void obj1(){
glPushMatrix();
glLineWidth(5.0);
glTranslated(x_position,0,0);
//head begins
glBegin(GL_POLYGON);
glColor3f(0,1,0);
double radius = 3;
for(int c =0;c<360;c++){
    double angle = c *3.14/180;
    glVertex2d(radius*cos(angle),radius*sin(angle));

}
glEnd();

//eye begins
//the outer white circle
glBegin(GL_POLYGON);
glColor3f(1,1,1);
 double rad = 1;
for(int c =0;c<360;c++){
    double angle = c *3.14/180;
    glVertex2d(rad*cos(angle),rad*sin(angle));
}
glEnd();

//continue eye
//The Middle blue circle
glBegin(GL_POLYGON);
glColor3f(0,1,1);
 double r = 0.5;
for(int c =0;c<360;c++){
    double angle = c *3.14/180;
    glVertex2d(r*cos(angle),r*sin(angle));
}
glEnd();

//continue eye
//The Inner Black Circle
glBegin(GL_POLYGON);
glColor3f(0,0,0);
 double rd = 0.2;
for(int c =0;c<360;c++){
    double angle = c *3.14/180;
    glVertex2d(rd*cos(angle),rd*sin(angle));
}
glEnd();


//right ear begins
glBegin(GL_TRIANGLES);
glColor3f(0,1,0);
glVertex2f(2.0,2.0);
glVertex2f(0.5,2.3);
glColor3f(1,1,1);//to color the following vertex in white to give a shadow to the ear
glVertex2f(2.0,3.5);
glEnd();


//left ears begins
glBegin(GL_TRIANGLES);
glColor3f(0,1,0);
glVertex2f(-2.0,2.0);
glVertex2f(-0.5,2.3);
glColor3f(1,1,1);//to color the following vertex in white to give a shadow to the ear
glVertex2f(-2.0,3.5);
glEnd();


//mouth begins
glBegin(GL_POLYGON);
glColor3f(0,0,0);
glVertex2f(1.5,-1.5);
glVertex2f(-1.5,-1.5);
glVertex2f(-1.0,-2.0);
glVertex2f(0.0,-2.2);
glVertex2f(1.0,-2.0);
glEnd();


//right arm begins
glLineWidth(20.0);
glBegin(GL_LINES);
glColor3f(0,1,0);
glVertex2f(2.9,0.0);
glVertex2f(4.0,2.0);
glEnd();
//ends to elbow

//from elbow and the rest of arm begins
glLineWidth(15.0);
glBegin(GL_LINES);
glColor3f(0,1,0);
glVertex2f(4,2.0);
glVertex2f(4,4.0);
glEnd();

//right hand begin
glLineWidth(5.0);
glBegin(GL_POLYGON);
glVertex2f(3.8,4.0);
glVertex2f(3.8,4.8);
glVertex2f(4.4,4.8);
glVertex2f(4.4,4.0);
glEnd();

//continue right hand fingers
glLineWidth(8.0);
glBegin(GL_LINES);
//finger no.1
glColor3f(0,1,0);
glVertex2f(3.8,4.5);
glColor3f(1,1,1);
glVertex2f(3.5,5.0);
//finger no.2
glColor3f(0,1,0);
glVertex2f(3.9,4.8);
glColor3f(1,1,1);
glVertex2f(3.9,5.5);
//finger no.3
glColor3f(0,1,0);
glVertex2f(4.1,4.8);
glColor3f(1,1,1);
glVertex2f(4.1,5.6);
//finger no.4
glColor3f(0,1,0);
glVertex2f(4.3,4.8);
glColor3f(1,1,1);
glVertex2f(4.3,5.4);
glEnd();


//left arm begins
glLineWidth(20.0);
glBegin(GL_LINES);
glColor3f(0,1,0);
glVertex2f(-2.9,0.0);
glVertex2f(-4.0,-2.0);
glEnd();

//ends to elbow
//from elbow and the rest of left arm
glLineWidth(15.0);
glBegin(GL_LINES);
glColor3f(0,1,0);
glVertex2f(-4.0,-2.0);
glVertex2f(-4.0,-4.0);
glEnd();

//left hand
glLineWidth(5.0);
glBegin(GL_POLYGON);
glVertex2f(-3.8,-4.0);
glVertex2f(-3.8,-4.8);
glVertex2f(-4.2,-4.8);
glVertex2f(-4.2,-4.0);
glEnd();

//continue left hand
//left hand fingers begins
glLineWidth(8.0);
glBegin(GL_LINES);
//finger no.1
glColor3f(0,1,0);
glVertex2f(-3.8,-4.5);
glColor3f(1,1,1);
glVertex2f(-3.5,-5.0);
//finger no.2
glColor3f(0,1,0);
glVertex2f(-3.9,-4.8);
glColor3f(1,1,1);
glVertex2f(-3.9,-5.5);
//finger no.3
glColor3f(0,1,0);
glVertex2f(-4.1,-4.8);
glColor3f(1,1,1);
glVertex2f(-4.1,-5.6);
glEnd();


//right leg begins
glLineWidth(18.0);
glBegin(GL_LINES);
glColor3f(0,1,0);
glVertex2f(1.5,-1.0);
glVertex2f(2.2,-4.0);
//to right knee
//from knee rest of leg
glVertex2f(2.2,-4.0);
glVertex2f(2.2,-6.0);
glEnd();

//right foot Begins
glBegin(GL_POLYGON);
glColor3f(0,1,0);
glVertex2f(2.02,-5.8);
glVertex2f(2.0,-6.5);
glColor3f(1,1,1);
glVertex2f(3.2,-6.5);
glVertex2f(3.0,-6.3);
glEnd();


//left leg begins
glLineWidth(18.0);
glBegin(GL_LINES);
glColor3f(0,1,0);
glVertex2f(-1.5,-1.0);
glVertex2f(-2.2,-4.0);//To knee
//from knee rest of leg
glVertex2f(-2.2,-4.0);
glVertex2f(-2.2,-6.0);
glEnd();

//left foot Begins
glBegin(GL_POLYGON);
glColor3f(0,1,0);
glVertex2f(-2.02,-5.8);
glVertex2f(-2.0,-6.5);
glColor3f(1,1,1);
glVertex2f(-3.2,-6.5);
glVertex2f(-3.0,-6.3);
glEnd();
glPopMatrix();//The end of ﬂÊ— Ï «·»⁄»⁄ body
}
//The function of cylinder begins
void cylinder(){
glPushMatrix();
glRotatef(180.0,1.0,1.0,0.0);//used to rotate the cylinder
glTranslated(-4,0,0);//The top of cylinder begins
glBegin(GL_POLYGON);
glColor3f(1,1,0);
double rcy1=1;
for(int c =0;c<180;c++){
    double angle = c *3.14/180;
    glVertex2d(rcy1*cos(angle),rcy1*sin(angle));
}
glEnd();


glBegin(GL_POLYGON);//The cylinder body begins
glColor3f(1,1,0);
glVertex2f(-1.0,0.0);
glVertex2f(1.0,0.0);
glVertex2f(1.0,-6.0);
glVertex2f(-1.0,-6.0);
glEnd();


glPushMatrix();
glTranslated(0,-6,0);//The cylinder bottom begins
glBegin(GL_POLYGON);
glColor3f(1,1,0);
double rcy2=-1;
for(int c =0;c<180;c++){
    double angle = c *3.14/180;
    glVertex2d(rcy2*cos(angle),rcy2*sin(angle));
}glEnd();
glPopMatrix();


glBegin(GL_POLYGON);//The black rectangle in cylinder
glColor3f(0,0,0);
glVertex2f(-0.2,-0.5);
glVertex2f(0.2,-0.5);
glVertex2f(0.2,-5.5);
glVertex2f(-0.2,-5.5);
glEnd();


glLineWidth(3.0);
glBegin(GL_LINES);//the yellow lines in cylinder
glColor3f(1,1,0);
glVertex2f(0.2,-5.0);
glVertex2f(-0.2,-5.0);
glEnd();

glBegin(GL_LINES);//the yellow lines in cylinder
glColor3f(1,1,0);
glVertex2f(0.2,-3.0);
glVertex2f(-0.2,-3.0);
glEnd();

glBegin(GL_LINES);//the yellow lines in cylinder
glColor3f(1,1,0);
glVertex2f(0.2,-1.0);
glVertex2f(-0.2,-1.0);
glEnd();


glPushMatrix();
glTranslated(0,y_position,0);//used to animate the cylinder according to y-axis
glBegin(GL_POLYGON);//the animated part in cylinder
glColor3f(1,0,0);
glVertex2f(-0.2,-4.5);
glVertex2f(0.2,-4.5);
glVertex2f(0.2,-5.5);
glVertex2f(-0.2,-5.5);
glEnd();
glPopMatrix();

glPopMatrix();
glEnd();
glFlush();
}

void display(){
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
obj1();//ﬂÊ— Ï «·»⁄»⁄function
cylinder();//the cylinder function
glutSwapBuffers();

}


void reshape(int w,int h ){

glViewport(0,0,(GLsizei)w,(GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-10,10,-10,10);
glMatrixMode(GL_MODELVIEW);
}


void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);

       if(x_position<5.5)//used to animate ﬂÊ— Ï «·»⁄»⁄ to the right of the window
            x_position+=0.30;

   switch(state)//used to animate the cylinder
    {
    case 1:
        if(y_position<4.5)
            y_position+=0.10;
        else
            state=-1;
        break;
    case -1:
        if(y_position>0)
            y_position-=0.10;
        else
            state=1;
        break;
    }
}



