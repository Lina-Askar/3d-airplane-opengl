#include <windows.h>
#include <glut.h>
#include <math.h>

GLfloat planePositionX = 0;
GLfloat planePositionY = 0;
GLfloat planePositionZ = 0;
GLfloat planeSpeed = 1.0;

// Camera variables
GLfloat cameraAngleX = 0.0f;
GLfloat cameraAngleY = 0.0f;
int lastMouseX = 0;
int lastMouseY = 0;

GLfloat cloudsPosition = 0;


// Function to draw the sun
void drawSun(float x, float y, float radius) {

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


    //GLfloat light_position[] = { -0.5, 0.5, 0.0f, 1.0f };
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    //{x,y,w,z}
    GLfloat light_position[] = { 70, 70, 0.0f, 1.0f };
    glLightfv(GL_LIGHT1, GL_POSITION, light_position);

    GLfloat amb[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    GLfloat diff[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    GLfloat spec[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    GLfloat shine = 100.0f;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);

    glColor3f(1.0f, 1.0f, 0.0f);
    glPushMatrix();
    glTranslatef(x, y, 0);
    glutSolidSphere(radius, 32, 32);
    glPopMatrix();
}

// Function to draw clouds
void drawCloud() {


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


    GLfloat amb[] = { 0.9f, 0.9f, 0.9f, 1.0f };
    GLfloat diff[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat spec[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat shine = 20.0f;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);

    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(cloudsPosition, 0, 0);
    glTranslatef(-20, 60, 0);
    glutSolidSphere(10, 32, 32);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(cloudsPosition, 0, 0);
    glTranslatef(-30, 55, 0);
    glutSolidSphere(5, 32, 32);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(cloudsPosition, 0, 0);
    glTranslatef(-10, 55, 0);
    glutSolidSphere(5, 32, 32);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(cloudsPosition, 0, 0);
    glTranslatef(20, 40, 0);
    glutSolidSphere(11, 32, 32);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(cloudsPosition, 0, 0);
    glTranslatef(30, 35, 0);
    glutSolidSphere(8, 32, 32);
    glPopMatrix();


    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(cloudsPosition, 0, 0);
    glTranslatef(10, 35, 0);
    glutSolidSphere(8, 32, 32);
    glPopMatrix();


    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(cloudsPosition, 0, 0);
    glTranslatef(50, 55, 0);
    glutSolidSphere(8, 32, 32);
    glPopMatrix();



    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(cloudsPosition, 0, 0);
    glTranslatef(57, 53, 0);
    glutSolidSphere(6, 32, 32);
    glPopMatrix();


    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(cloudsPosition, 0, 0);
    glTranslatef(43, 53, 0);
    glutSolidSphere(6, 32, 32);
    glPopMatrix();

    cloudsPosition += 0.05;
    if (cloudsPosition > 100) {
        cloudsPosition = -100; // Reset to the initial position
    }

}

// Function to draw the airplane

void drawPlane() {

    glDisable(GL_LIGHTING);

    GLfloat amb[] = { 0.05f, 0.05f, 0.05f, 1.0f };
    GLfloat diff[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat spec[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat shine = 10.0f;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);

    glPushMatrix();
    glTranslatef(planePositionX, planePositionY, planePositionZ);
    glRotatef(90, 0, 1, 0);

    // Body
    glColor3f(0.243f, 0.471f, 0.769f);
    glPushMatrix();
    glTranslatef(0, 0, -25);
    GLUquadricObj* quadratic;
    quadratic = gluNewQuadric();
    gluCylinder(quadratic, 4, 4, 35, 50, 32);
    glPopMatrix();

    // Head cone
    glColor3f(0.2f, 0.6f, 0.8f);
    glPushMatrix();
    glTranslatef(0, 0, 10);
    glutSolidCone(4, 18, 32, 32);
    glPopMatrix();

    // Window
    glColor3f(0.7f, 0.8f, 0.9f);
    glPushMatrix();
    glTranslatef(0, 1, 14);
    glutSolidSphere(3, 32, 32);
    glPopMatrix();

    // Middle wings
    glColor3f(0.2f, 0.6f, 0.8f);
    glPushMatrix();
    glTranslatef(0, 0, -15);
    glRotatef(90, 0, 0, 1);
    glutSolidCone(35, 25, 2, 32);
    glPopMatrix();

    // Upper wings
    glColor3f(0.2f, 0.6f, 0.8f);
    glPushMatrix();
    glTranslatef(-2, 0, -17);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(6, 20, 2, 2);
    glPopMatrix();

    // Tail
    glColor3f(0.2f, 0.6f, 0.8f);
    glPushMatrix();
    glTranslatef(0, 0, -30);
    glutSolidCone(6, 18, 32, 32);
    glPopMatrix();

    // Rockets (right)
    glColor3f(0.243f, 0.471f, 0.769f);
    glPushMatrix();
    glTranslatef(-13, -1.6, -5);
    glutSolidCone(1.5, 8, 32, 32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-13, -1.6, -14);
    gluCylinder(quadratic, 1.5, 1.5, 9, 50, 32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20, -1.6, -10);
    glutSolidCone(1.5, 8, 32, 32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-20, -1.6, -15);
    gluCylinder(quadratic, 1.5, 1.5, 5, 50, 32);
    glPopMatrix();

    // Rockets (left)
    glPushMatrix();
    glTranslatef(13, -1.6, -5);
    glutSolidCone(1.5, 8, 32, 32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(13, -1.6, -14);
    gluCylinder(quadratic, 1.5, 1.5, 9, 50, 32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20, -1.6, -10);
    glutSolidCone(1.5, 8, 32, 32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(20, -1.6, -15);
    gluCylinder(quadratic, 1.5, 1.5, 5, 50, 32);
    glPopMatrix();

    glPopMatrix();

}


// moving airplan using  (f--> forword , b-->. backworf , u--> u , d--. down)
void keyboard(unsigned char key, int x, int y) {
    if (planePositionX < 60 && planePositionY < 60) {

        if (key == 'f' || key == 'F') {
            planePositionX += planeSpeed;
        }
        if (key == 'b' || key == 'B') {
            planePositionX -= planeSpeed;
        }
        if (key == 'u' || key == 'U') {
            planePositionY += planeSpeed;
        }
        if (key == 'd' || key == 'D') {
            planePositionY -= planeSpeed;
        }
        if (key == 27) {
            exit(0);
        }
    }
    else
    {
        planePositionX = -30;
        planePositionY = 0;
    }

    glutPostRedisplay();
}
// moving around the object in 3D space using mouse click

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        lastMouseX = x;
        lastMouseY = y;
    }
}

void motion(int x, int y) {

    int deltaX = x - lastMouseX;
    int deltaY = y - lastMouseY;

    cameraAngleX += deltaX * 0.1f;
    cameraAngleY += deltaY * 0.1f;

    if (cameraAngleY > 90.0f) {
        cameraAngleY = 90.0f;
    }
    else if (cameraAngleY < -90.0f) {
        cameraAngleY = -90.0f;
    }

    lastMouseX = x;
    lastMouseY = y;

    glutPostRedisplay();
}


void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -150.0f);
    glRotatef(cameraAngleY, 1.0f, 0.0f, 0.0f);
    glRotatef(cameraAngleX, 0.0f, 1.0f, 0.0f);


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    drawSun(-60, 50, 15);


    //drawCloud(-20, 60, 10);
    //drawCloud(-30, 55, 5);
    //drawCloud(-10, 55, 5);
    //drawCloud(20, 40, 11);
    //drawCloud(30, 35, 8);
    //drawCloud(10, 35, 8);
    //drawCloud(50, 55, 8);
    //drawCloud(57, 53, 6);
    //drawCloud(43, 53, 6);
    drawCloud();

    drawPlane();

    // Draw the buildings

    // Building 1
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex3f(-60, -25, 0.0f);               // Top-left
    glVertex3f(-60, -125, 0.0f);              // Bottom-left
    glVertex3f(-53, -125, 0.0f);              // Bottom-right
    glVertex3f(-53, -25, 0.0f);               // Top-right
    glEnd();
    // Roof for Building 1
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-60, -25, 0.1f);               // Left corner of the roof
    glVertex3f(-53, -25, 0.1f);               // Right corner of the roof
    glVertex3f(-56.5, -15, 0.1f);             // Top point of the roof
    glEnd();

    // Building 2
    glColor3f(0.2f, 0.3f, 0.4f);
    glBegin(GL_QUADS);
    glVertex3f(-50, -30, 0.0f);               // Top-left
    glVertex3f(-50, -75, 0.0f);               // Bottom-left
    glVertex3f(-41, -75, 0.0f);               // Bottom-right
    glVertex3f(-41, -30, 0.0f);               // Top-right
    glEnd();

    // Building 3
    glColor3f(0.4f, 0.25f, 0.2f);
    glBegin(GL_QUADS);
    glVertex3f(-30, -40, 0.0f);               // Top-left
    glVertex3f(-30, -120, 0.0f);              // Bottom-left
    glVertex3f(-18, -120, 0.0f);              // Bottom-right
    glVertex3f(-18, -40, 0.0f);               // Top-right
    glEnd();

    // Building 4
    glColor3f(0.1f, 0.2f, 0.3f);
    glBegin(GL_QUADS);
    glVertex3f(-10, -28, 0.0f);               // Top-left
    glVertex3f(-10, -98, 0.0f);               // Bottom-left
    glVertex3f(1, -98, 0.0f);                 // Bottom-right
    glVertex3f(1, -28, 0.0f);                 // Top-right
    glEnd();

    // Building 5
    glColor3f(0.1f, 0.3f, 0.2f);
    glBegin(GL_QUADS);
    glVertex3f(10, -30, 0.0f);                // Top-left
    glVertex3f(10, -70, 0.0f);                // Bottom-left
    glVertex3f(23, -70, 0.0f);                // Bottom-right
    glVertex3f(23, -30, 0.0f);                // Top-right
    glEnd();

    // Building 6
    glColor3f(0.35f, 0.2f, 0.15f);
    glBegin(GL_QUADS);
    glVertex3f(30, -30, 0.0f);                // Top-left
    glVertex3f(30, -70, 0.0f);                // Bottom-left
    glVertex3f(38, -70, 0.0f);                // Bottom-right
    glVertex3f(38, -30, 0.0f);                // Top-right
    glEnd();

    // Building 7
    glColor3f(0.4f, 0.35f, 0.3f);
    glBegin(GL_QUADS);
    glVertex3f(40, -50, 0.0f);                // Top-left
    glVertex3f(40, -90, 0.0f);                // Bottom-left
    glVertex3f(48, -90, 0.0f);                // Bottom-right
    glVertex3f(48, -50, 0.0f);                // Top-right
    glEnd();

    // Building 8
    glColor3f(0.2f, 0.25f, 0.4f);
    glBegin(GL_QUADS);
    glVertex3f(50, -25, 0.0f);                // Top-left
    glVertex3f(50, -91, 0.0f);                // Bottom-left
    glVertex3f(64, -91, 0.0f);                // Bottom-right
    glVertex3f(64, -25, 0.0f);                // Top-right
    glEnd();

    // Building 9
    glColor3f(0.15f, 0.15f, 0.15f);
    glBegin(GL_QUADS);
    glVertex3f(-40, -45, 0.0f);               // Top-left
    glVertex3f(-40, -111, 0.0f);              // Bottom-left
    glVertex3f(-33, -111, 0.0f);              // Bottom-right
    glVertex3f(-33, -45, 0.0f);               // Top-right
    glEnd();

    glutSwapBuffers();
}

int main() {
    // glutInit();
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("3D Airplane ");
    glEnable(GL_DEPTH_TEST);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 1, 1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0.68f, 0.85f, 0.9f, 1.0f);

    glutDisplayFunc(draw);
    glutIdleFunc(draw);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();

}
