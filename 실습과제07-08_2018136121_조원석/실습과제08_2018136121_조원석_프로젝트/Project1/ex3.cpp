#define GLUT_DISABLE_ATEXIT_HACK
// glut�� �̿��� OpenGL �ڵ带 �������� �� ��Ŀ ������ �����ϴ� �뵵
#include <windows.h>
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <random>


GLfloat Delta = 0.0;
void MyName() {
	glViewport(10, 10, 300, 300);
	glColor3f(0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	// ��
	glBegin(GL_POLYGON);
	glVertex3f(-0.49, 0.4, 0.0);
	glVertex3f(-0.49, 0.39, 0.0);
	glVertex3f(-0.4, 0.39, 0.0);
	glVertex3f(-0.4, 0.4, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.445, 0.4, 0.0);
	glVertex3f(-0.455, 0.4, 0.0);
	glVertex3f(-0.49, 0.35, 0.0);
	glVertex3f(-0.48, 0.35, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.445, 0.4, 0.0);
	glVertex3f(-0.455, 0.4, 0.0);
	glVertex3f(-0.41, 0.35, 0.0);
	glVertex3f(-0.4, 0.35, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.445, 0.4, 0.0);
	glVertex3f(-0.455, 0.4, 0.0);
	glVertex3f(-0.41, 0.35, 0.0);
	glVertex3f(-0.4, 0.35, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.445, 0.33, 0.0);
	glVertex3f(-0.455, 0.33, 0.0);
	glVertex3f(-0.445, 0.3, 0.0);
	glVertex3f(-0.455, 0.3, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.4, 0.3, 0.0);
	glVertex3f(-0.49, 0.3, 0.0);
	glVertex3f(-0.49, 0.29, 0.0);
	glVertex3f(-0.4, 0.29, 0.0);
	glEnd();

	//��
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; ++i)
	{
		glVertex3f(-0.3 + 0.03 * cos(i * (3.14152 / 180)), 0.39 + 0.03 * sin(i * (3.14152 / 180)), 0.0f);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.35, 0.33, 0.0);
	glVertex3f(-0.25, 0.33, 0.0);
	glVertex3f(-0.25, 0.325, 0.0);
	glVertex3f(-0.35, 0.325, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.305, 0.325, 0.0);
	glVertex3f(-0.3, 0.325, 0.0);
	glVertex3f(-0.3, 0.275, 0.0);
	glVertex3f(-0.305, 0.275, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.305, 0.325, 0.0);
	glVertex3f(-0.3, 0.325, 0.0);
	glVertex3f(-0.3, 0.275, 0.0);
	glVertex3f(-0.305, 0.275, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.29, 0.305, 0.0);
	glVertex3f(-0.25, 0.305, 0.0);
	glVertex3f(-0.25, 0.3, 0.0);
	glVertex3f(-0.29, 0.3, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.25, 0.4, 0.0);
	glVertex3f(-0.245, 0.4, 0.0);
	glVertex3f(-0.245, 0.26, 0.0);
	glVertex3f(-0.25, 0.26, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.28, 0.26, 0.0);
	glVertex3f(-0.285, 0.26, 0.0);
	glVertex3f(-0.285, 0.22, 0.0);
	glVertex3f(-0.28, 0.22, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.285, 0.22, 0.0);
	glVertex3f(-0.255, 0.22, 0.0);
	glVertex3f(-0.255, 0.21, 0.0);
	glVertex3f(-0.285, 0.21, 0.0);
	glEnd();

	//��

	glBegin(GL_POLYGON);
	glVertex3f(-0.16, 0.4, 0.0);
	glVertex3f(-0.17, 0.4, 0.0);
	glVertex3f(-0.2, 0.3, 0.0);
	glVertex3f(-0.19, 0.3, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.17, 0.35, 0.0);
	glVertex3f(-0.18, 0.35, 0.0);
	glVertex3f(-0.11, 0.3, 0.0);
	glVertex3f(-0.12, 0.3, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.12, 0.345, 0.0);
	glVertex3f(-0.08, 0.345, 0.0);
	glVertex3f(-0.08, 0.34, 0.0);
	glVertex3f(-0.12, 0.34, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.08, 0.4, 0.0);
	glVertex3f(-0.075, 0.4, 0.0);
	glVertex3f(-0.075, 0.3, 0.0);
	glVertex3f(-0.08, 0.3, 0.0);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(-0.12, 0.28, 0.0);
	glVertex3f(-0.075, 0.28, 0.0);
	glVertex3f(-0.075, 0.275, 0.0);
	glVertex3f(-0.12, 0.275, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.075, 0.275, 0.0);
	glVertex3f(-0.065, 0.275, 0.0);
	glVertex3f(-0.065, 0.225, 0.0);
	glVertex3f(-0.075, 0.225, 0.0);
	glEnd();

	glFlush();
}
void SierpinskiGasket() {
	GLfloat vx[] = { 1.0, 0.0, 2.0 };
	GLfloat vy[] = { 0.0, 2.0, 2.0 };
	// �� ���� ���� (100, 0), (0, 200), (200, 200)
	GLfloat px = 1;
	GLfloat py = 1;
	// -> �� �ﰢ�� ���ο��� �������� �ʱ� �� px�� py�� ��´�.
	std::random_device rd;		// �õ尪�� ��� ���� random_device ����.
	std::mt19937 gen(rd());		// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.

	// 0 ���� 2 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
	std::uniform_int_distribution<int> dis(0, 2);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);		// ���� ��Ÿ���� ���� ���� R, G, B ����

	glBegin(GL_POINTS);// GL_POINTS �������� ��
	for (GLint i = 0; i < 1000; i++) {
		//-> �蹫������ �� ���� ���� �� �� ���� �����Ѵ�.
		int whichV = dis(gen) % 3;
		//-> �� �������� �������� ���õ� ������ �߰����� ��´�.
		float newPx = (px + vx[whichV]) / 2.0;
		float newPy = (py + vy[whichV]) / 2.0;
		//-> �� �� ��ġ�� ���� �� ���� ǥ���� �����ν� ���ο� ���� ǥ��
		glVertex2f(newPx-1, -newPy+1);
		//-> �� �������� �� ���� ���� �� �� ���� �����Ѵ�.
		px = newPx;
		py = newPy;
		//-> �� �ܰ� 2�� ���ư���. (�� ������ �־��� Ƚ����ŭ �ݺ�)
	}
	glEnd();	// -> ������ ���� �ǹ�
	glFlush();			// -> ������ �׷��� ���� ���۸� ���� �뵵
}
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(10, 10, 300, 300); 
    glColor3f(0, 0, 0); 
    //glRotatef(90, 10, 10, 10);

	if (Delta < 1.0)
		glutWireCube(1.0);
	else if (Delta < 2.0)
		glutWireSphere(1, 100, 100);
	else if (Delta < 3.0)
		glutWireTorus(1, 1, 100, 100);
	else if (Delta < 4.0)
		glutWireCone(1, 1, 100, 100);
	else  if (Delta < 5.0)
		glutWireTeapot(0.5);
	else if (Delta < 6.0)
		MyName();
	else
		SierpinskiGasket();
    glutSwapBuffers();
}

void MyIdle() {
    Delta = Delta + 0.001;
    if (Delta > 7.0) {
        Delta = 0;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
    glutDisplayFunc(MyDisplay);
    glutIdleFunc(MyIdle);
    glutMainLoop();
    return 0;
}
