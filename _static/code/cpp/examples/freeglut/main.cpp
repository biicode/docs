#include "sphere.h"

//Functions declarations
void Init();
void OnDraw();

void Init(){
	//Initialize GLUT windows manager
	//Create the window
	int argc=1;
    char* argv[1]={"Glut Application"};
    glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("My World");
	
	//enable lights and define perspective
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);
}

void OnDraw(void){
	//cleaning the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//Define view
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// eye position -> (0.0, 10, 20)
	// target -> (0,0,0)
	// define positive Y axis  -> (0.0, 1.0, 0.0)		
	gluLookAt(0.0, 10, 20,
	0.0, 0, 0.0,
	0.0, 1.0, 0.0);
	
	//Put your code here to draw objects
	Sphere sphere1;
	sphere1.draw();
	
	//no delete this line
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	Init();	
	//Enter the callbacks
	glutDisplayFunc(OnDraw);

	glutMainLoop(); // begin the loop
	return 0;    
}
