#include "gllc.h"
#include <windows.h>
// ������ǥ��� ǥ����
static double P[12] = { 0.3, 0.2, 0.1, 1,	0.7, 0.2, 0.1, 1,	0.5, 0.7, 0.1, 1 };
static double Q[12];

static char objNum = -1;			// ��ü ��ȣ. �޴� �̺�Ʈ�� ���� ����
static int PrevX, PrevY;		// ���콺 X, Y  ��ǥ ��ġ

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glTriangle4d(P);
	glColor3f(0.0, 0.0, 1.0);
	glTriangle4d(Q);
	glCoord();
	glFlush();
}
void transformTri(double* m, double* p, double* q) {
	glTransform(m, p, q);
	glTransform(m, p + 4, q + 4);
	glTransform(m, p + 8, q + 8);
}
void keyboard(unsigned char key, int x, int y) {
	double m1[16], m2[16], m3[16];

	if (key == 'i') {				// �ʱ�ȭ
		printf("��ü �ʱ�ȭ(i)\n");
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	else if (key == 't') {			// �̵�
		printf("��ü �̵�(t)\n");
		glMatTrans(m1, -1, -0.5, 0);
		glMatPrint(m1);
		transformTri(m1, P, Q);
	}
	else if (key == 's') {			// ����
		printf("��ü ����(s)\n");
		glMatScale(m1, 1.5, 1.2, 1.4);
		glMatPrint(m1);
		transformTri(m1, P, Q);
	}
	else if (key == 'x') {			// X�� ȸ��
		printf("��ü X�� ȸ��(x)\n");
		glMatRotateX(m1, 60);
		glMatPrint(m1);
		transformTri(m1, P, Q);
	}
	else if (key == 'y') {				// Y�� ȸ��
		printf("��ü Y�� ȸ��(y)\n");
		glMatRotateY(m1, 60);
		glMatPrint(m1);
		transformTri(m1, P, Q);
	}
	else if (key == 'z') {			// Z�� ȸ��
		printf("��ü Z�� ȸ��(z)\n");
		glMatRotateZ(m1, 60);
		glMatPrint(m1);
		transformTri(m1, P, Q);
	}
	else if (key == 'Z') {			// ���պ�ȯ : ȸ��
		glMatTrans(m1, -P[0], -P[1], -P[2]);
		glMatRotateZ(m2, 60);
		glMatTrans(m3, P[0], P[1], P[2]);

		printf("���պ�ȯ : ȸ��(Z)\n");
		glMatMult(m3, m2);
		glMatMult(m3, m1);
		transformTri(m3, P, Q);
	}
	else if (key == 'c') {			// ���պ�ȯ : ���� 
		glMatTrans(m1, P[0], P[1], P[2]);
		glMatScale(m2, 1.5, 1.2, 1.4);
		glMatTrans(m3, -P[0], -P[1], -P[2]);
		
		printf("���պ�ȯ : ����(c)\n");
		glMatPrint(m1);
		glMatPrint(m2);
		glMatPrint(m3);

		glMatMult(m1, m2);
		glMatMult(m1, m3);
		glMatPrint(m1);
		transformTri(m1, P, Q);
	}
	else if (key == 'h') {			// �и�
		printf("�и�(h)\n");
		glMatShearX(m1, 0.3, 0);
		transformTri(m1, P, Q);
	}
	else if (key == 'j') {		// �ڽŸ��� ���պ�ȯ
		glMatScale(m1, 1, 2.0, 1);
		glMatTrans(m2, 0, 0.3, 0.2);
		glMatRotateX(m3, 180);
		printf("���պ�ȯ : (j)\n");
		glMatPrint(m1);
		
		glMatMult(m1, m2);
		glMatMult(m1, m3);
		printf("����\n");

		glMatPrint(m1);
		transformTri(m1, P, Q);
	}
	else if (key == 'q') exit(0);
	glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		PrevX = x;
		PrevY = y;
	}
	// ������ ���콺 Ŭ�� �� �޴� ���� ( �ڼ��� ���� initMenu, myMenu�� ���� )
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void mouseMotion(GLint x, GLint y) {
	glMatrixMode(GL_MODELVIEW);
	glRotated(x - PrevX, 0, 1, 0);
	glRotated(y - PrevY, 1, 0, 0);
	PrevX = x;
	PrevY = y;
	glutPostRedisplay();
}

void myMenu(int id) { // �޴��� �׸��� �Լ�
	if (id == 0) keyboard('i', 0, 0);
	else if (id == 1) keyboard('t', 0, 0);
	else if (id == 2) keyboard('s', 0, 0);
	else if (id == 3) keyboard('x', 0, 0);
	else if (id == 4) keyboard('y', 0, 0);
	else if (id == 5) keyboard('z', 0, 0);
	else if (id == 6) keyboard('Z', 0, 0);
	else if (id == 7) keyboard('c', 0, 0);
	else if (id == 8) keyboard('h', 0, 0);
	else if (id == 9) keyboard('j', 0, 0);
	else if (id == 10) exit(0);
	glutPostRedisplay();
}
void initMenu(void) {	// ��Ŭ���� �޴� ����
	GLint MyMainMenuID = glutCreateMenu(myMenu);
	glutAddMenuEntry("Initial(i)", 0);
	glutAddMenuEntry("t", 1);
	glutAddMenuEntry("s", 2);
	glutAddMenuEntry("x", 3);
	glutAddMenuEntry("y", 4);
	glutAddMenuEntry("z", 5);
	glutAddMenuEntry("Z", 6);
	glutAddMenuEntry("c", 7);
	glutAddMenuEntry("h", 8);
	glutAddMenuEntry("j", 9);
	glutAddMenuEntry("Exit(q)", 10);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Gemetric Transform");
	glClearColor(1.0, 1.0, 1.0, 1.0);

	initMenu();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMotion);
	glutMainLoop();
	return 0;
}