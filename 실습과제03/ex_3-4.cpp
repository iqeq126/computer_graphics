#include <stdio.h>
#include <math.h>
#include <gl/Glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	// Á¶
	glBegin(GL_POLYGON);
	glVertex3f(-0.99, 0.9, 0.0);
	glVertex3f(-0.99, 0.89, 0.0);
	glVertex3f(-0.9, 0.89, 0.0);
	glVertex3f(-0.9, 0.9, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.945, 0.9, 0.0);
	glVertex3f(-0.955, 0.9, 0.0);
	glVertex3f(-0.99, 0.85, 0.0);
	glVertex3f(-0.98, 0.85, 0.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(-0.945, 0.9, 0.0);
	glVertex3f(-0.955, 0.9, 0.0);
	glVertex3f(-0.91, 0.85, 0.0);
	glVertex3f(-0.9, 0.85, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.945, 0.9, 0.0);
	glVertex3f(-0.955, 0.9, 0.0);
	glVertex3f(-0.91, 0.85, 0.0);
	glVertex3f(-0.9, 0.85, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.945, 0.83, 0.0);
	glVertex3f(-0.955, 0.83, 0.0);
	glVertex3f(-0.945, 0.8, 0.0);
	glVertex3f(-0.955, 0.8, 0.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(-0.9, 0.8, 0.0);
	glVertex3f(-0.99, 0.8, 0.0);
	glVertex3f(-0.99, 0.79, 0.0);
	glVertex3f(-0.9, 0.79, 0.0);
	glEnd();

	//¿ø
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; ++i)
	{
		glVertex3f(-0.8 + 0.03 * cos(i * (3.14152 / 180)), 0.89 + 0.03 * sin(i * (3.14152 / 180)), 0.0f);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.85, 0.83, 0.0);
	glVertex3f(-0.75, 0.83, 0.0);
	glVertex3f(-0.75, 0.825, 0.0);
	glVertex3f(-0.85, 0.825, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.805, 0.825, 0.0);
	glVertex3f(-0.8, 0.825, 0.0);
	glVertex3f(-0.8, 0.775, 0.0);
	glVertex3f(-0.805, 0.775, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.805, 0.825, 0.0);
	glVertex3f(-0.8, 0.825, 0.0);
	glVertex3f(-0.8, 0.775, 0.0);
	glVertex3f(-0.805, 0.775, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.79, 0.805, 0.0);
	glVertex3f(-0.75, 0.805, 0.0);
	glVertex3f(-0.75, 0.8, 0.0);
	glVertex3f(-0.79, 0.8, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.75, 0.9, 0.0);
	glVertex3f(-0.745, 0.9, 0.0);
	glVertex3f(-0.745, 0.76, 0.0);
	glVertex3f(-0.75, 0.76, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.78, 0.76, 0.0);
	glVertex3f(-0.785, 0.76, 0.0);
	glVertex3f(-0.785, 0.72, 0.0);
	glVertex3f(-0.78, 0.72, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.785, 0.72, 0.0);
	glVertex3f(-0.755, 0.72, 0.0);
	glVertex3f(-0.755, 0.71, 0.0);
	glVertex3f(-0.785, 0.71, 0.0);
	glEnd();

	//¼®

	glBegin(GL_POLYGON);
	glVertex3f(-0.66, 0.9, 0.0);
	glVertex3f(-0.67, 0.9, 0.0);
	glVertex3f(-0.7, 0.8, 0.0);
	glVertex3f(-0.69, 0.8, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.67, 0.85, 0.0);
	glVertex3f(-0.68, 0.85, 0.0);
	glVertex3f(-0.61, 0.8, 0.0);
	glVertex3f(-0.62, 0.8, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.62, 0.845, 0.0);
	glVertex3f(-0.58, 0.845, 0.0);
	glVertex3f(-0.58, 0.84, 0.0);
	glVertex3f(-0.62, 0.84, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.58, 0.9, 0.0);
	glVertex3f(-0.575, 0.9, 0.0);
	glVertex3f(-0.575, 0.8, 0.0);
	glVertex3f(-0.58, 0.8, 0.0);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(-0.62, 0.78, 0.0);
	glVertex3f(-0.575, 0.78, 0.0);
	glVertex3f(-0.575, 0.775, 0.0);
	glVertex3f(-0.62, 0.775, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.575, 0.775, 0.0);
	glVertex3f(-0.565, 0.775, 0.0);
	glVertex3f(-0.565, 0.725, 0.0);
	glVertex3f(-0.575, 0.725, 0.0);
	glEnd();

	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Drawing Example");
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}