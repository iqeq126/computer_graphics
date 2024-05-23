#include "Robot.h"
#include <gl/glut.h>

static Mesh obj3D;	// Mesh ��ü
static Robot robot; // Robot ��ü
// static bool bRobotRun = false; // �κ� ���� ����

void display() {
	glClearColor(0.99, 0.97, 0.97, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	robot.draw();
	obj3D.draw(80.0f, true);
	glutSwapBuffers();
	glFlush();
}

static int PrevX, PrevY; // ���� X, Y ��ǥ
void mouseClick(int button, int state, int x, int y) {
	printf("mouseClick : (%d, %d)\n",x, y);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		PrevX = x;
		PrevY = y;
	}
}
void mouseMotion(GLint x, GLint y) {
	printf("mouseMotion : (%d, %d)\n", x, y);
	glMatrixMode(GL_MODELVIEW);
	glRotated(x - PrevX, 0, 1, 0);
	glRotated(y - PrevY, 1, 0, 0);
	PrevX = x;
	PrevY = y;
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y) {
	/*
	if (key == 'l') {
		printf("���� ����(��)\n");
		char* filename = glFileDlg(FILTER_ASE);
		if (filename != NULL)
			obj3D.readAse(filename);
//			obj3D.readAse("S_body.ase");
	}
	else*/if (key == 'i') {				// �ʱ�ȭ
		printf("��ü �ʱ�ȭ(i)\n");
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	else if (key == 'w') {				// ����ȭ
		printf("����ȭ(w)\n");
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_POINT);
	}
	else if (key == 's') {				// ����ȭ �ǵ�����
		printf("����ȭ �ǵ�����(s)\n");
		glPolygonMode(GL_FRONT, GL_FILL);
		glPolygonMode(GL_BACK, GL_LINE);
	}
	else if (key == 'z' || key == 'Z') {	// z : �۾�����, Z : Ŀ����
		printf("ũ�� �����ϱ�(z)\n");
		robot.resize(key == 'z');
	}
	else if (key == 'q') exit(0); // ������
	glutPostRedisplay();
}

void initRendering() {
	// ���� ó��
	GLfloat light_specular[] = { 0.8, 0.5, 0.8, 1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.5, 0.8, 1.0 };
	GLfloat light_ambient[] = { 0.8, 0.5, 0.8, 1.0 };
	GLfloat light_position[] = { 0.8, 0.5, 0.8, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

	// Mesh�� ����
	GLfloat mat_specular[] = { 0.5, 1.0, 0.5, 1.0 };
	GLfloat mat_shininess[] = { 70.0 };
	GLfloat mat_color[] = { 0.5, 0.5, 0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_shininess);

	glEnable(GL_LIGHTING);			// ���� ��� ����
	glEnable(GL_LIGHT0);			// ���� ��� ����
	glEnable(GL_NORMALIZE);			// ����ȭ

	glEnable(GL_DEPTH_TEST);		// depth �˻� (z-���� ���)
	glShadeModel(GL_SMOOTH); 
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);  // GLUT �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutCreateWindow("RobotWorld");

	// �ݹ� ����
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMotion);

	initRendering();			// ���� ����
	//keyboard('s', 0, 0);
	//keyboard('l', 0, 0);		
	
	glutMainLoop(); // GLUT ����
	return 0;
}