#define GLUT_DISABLE_ATEXIT_HACK
// glut�� �̿��� OpenGL �ڵ带 �������� �� ��Ŀ ������ �����ϴ� �뵵
#include <gl/GLUT.h>
#include <math.h>
#include <windows.h>
#include <iostream>
#include <random>
static int objNum = -1;			// ��ü ��ȣ. 0���� �����ϹǷ� �ʱⰪ -1�� ����
static bool bAuto = true;		// �ڵ� ���� ��� ���� ����
static int PrevX, PrevY;		// ���콺 X, Y  ��ǥ ��ġ

// �̸� ���
void MyName() {
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
}
// SierpinskiGasket ���
void SierpinskiGasket() {
	GLint vx[] = { 100, 0, 200 };
	GLint vy[] = { 0, 200, 200 };
	// �� ���� ���� (100, 0), (0, 200), (200, 200)
	GLint px = 100;
	GLint py = 100;
	// -> �� �ﰢ�� ���ο��� �������� �ʱ� �� px�� py�� ��´�.
	std::random_device rd;		// �õ尪�� ��� ���� random_device ����.
	std::mt19937 gen(rd());		// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.

	// 0 ���� 2 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
	std::uniform_int_distribution<int> dis(0, 2);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);		// ���� ��Ÿ���� ���� ���� R, G, B ����
	glBegin(GL_POINTS);// GL_POINTS �������� ��
	for (GLint i = 0; i < 10000; i++) {
		//-> �蹫������ �� ���� ���� �� �� ���� �����Ѵ�.
		int whichV = dis(gen) % 3;
		//-> �� �������� �������� ���õ� ������ �߰����� ��´�.
		int newPx = (px + vx[whichV]) / 2;
		int newPy = (py + vy[whichV]) / 2;
		//-> �� �� ��ġ�� ���� �� ���� ǥ���� �����ν� ���ο� ���� ǥ��
		glVertex3d(1 + newPx / (-100.0), 1 - newPy/(100.0), 0);
		//-> �� �������� �� ���� ���� �� �� ���� �����Ѵ�.
		px = newPx;
		py = newPy;
		//-> �� �ܰ� 2�� ���ư���. (�� ������ �־��� Ƚ����ŭ �ݺ�)
	}
	glEnd();	// -> ������ ���� �ǹ�
}
// ���� ��ü�� �����ϴ� �κ�
void display() {
	glClear(GL_COLOR_BUFFER_BIT);	// ���� ���� �ʱ�ȭ
	glColor3f(1.0, 0.0, 0.0);	// ��ü �� Red
	switch (objNum) {	// ��ü ���� : 0_ť��, ~ 7_�̸�, 8_�ﰢ��
	case 0: glutWireCube(1);	break;
	case 1: glutWireSphere(0.8, 16, 10);	break;
	case 2: glutWireCone(0.8, 1, 20, 10);	break;
	case 3: glutWireTorus(0.1, 0.8, 10, 20);	break;
	case 4: glutWireTetrahedron();	break;
	case 5: glutWireIcosahedron();	break;
	case 6: glutWireTeapot(0.6);	break;
	case 7: MyName();	break;
	case 8: SierpinskiGasket();	break;
	}
	glFlush();	// ������ �׷��� ���� ���۸� ���� �뵵
}

// �ð��� �����ϴ� �κ�
void myTimer(int Value) {
	glutPostRedisplay();
	if (bAuto) {			// �ڵ����� ���� ��ü�� ����ϴ� ���
		objNum = (objNum + 1) % 9;		// 0 ~ 8 ���� ����
	}
	glutTimerFunc(500, myTimer, 1);
}

// Ű���� �̺�Ʈ
void keyboard(unsigned char key, int x, int y) {
	// 0 ~ 8 ������ ��ü ����, �ڵ� ���� OFF
	if (key >= '0' && key <= '8') {
		bAuto = false;
		objNum = key - '0';
	}
	// A ��ư. �ڵ� ���� toggle 
	else if (key == 'a' || key == 'A') {
		bAuto = !bAuto;
	}
	// I ��ư. ��ü ȸ�� �ʱ�ȭ
	else if (key == 'i' || key == 'I') {
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	// Q ��ư or ESC ��ư. ������ Ż��
	else if (key == 'q' || key == 'Q' || key == 27)
		exit(0);
	glutPostRedisplay();		// ȭ�� �ٽ� ���
}

// ��������. ������ ũ�Ⱑ ���ϴ��� ��ü�� ���� ���� ���� ����.
void reshape(int width, int height) {
	// ���� ������ �ʺ�, ���� ����
	glViewport(0, 0, width, height);
	double wScale = (double)width / 500;
	double hScale = (double)height / 500;

	// ó�� ȸ�� ���·� �ǵ����� ���
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-wScale, wScale, -hScale, hScale, -1, 1);
}

// ���콺 Ŭ��.
void mouseClick(int button, int state, int x, int y) {
	// ���� ���콺 Ŭ�� ��. Prev ������ x, y �� ����
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		PrevX = x;
		PrevY = y;
	}
	// ������ ���콺 Ŭ�� �� �޴� ���� ( �ڼ��� ���� initMenu, myMenu�� ���� )
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
// ���콺 ������
void mouseMotion(GLint x, GLint y) {
	// 
	glMatrixMode(GL_MODELVIEW);
	glRotated(x - PrevX, 0, 1, 0);
	glRotated(y - PrevY, 1, 0, 0);
	PrevX = x;
	PrevY = y;
	glutPostRedisplay();
}


void myMenu(int id) { // �޴��� �׸��� �Լ�
	if (id >= 0 && id <= 8)
		keyboard(id + '0', 0, 0);
	else if (id == 9) exit(0);
	glutPostRedisplay();
}
void initMenu(void) {	// ��Ŭ���� �޴� ����
	GLint MyMainMenuID = glutCreateMenu(myMenu);
	glutAddMenuEntry("Draw Cube", 0);
	glutAddMenuEntry("Draw Sphere", 1);
	glutAddMenuEntry("Draw Cone", 2);
	glutAddMenuEntry("Draw Torus", 3);
	glutAddMenuEntry("Draw Tetrahedron", 4);
	glutAddMenuEntry("Draw Icosahedron", 5);
	glutAddMenuEntry("Draw Teapot", 6);
	glutAddMenuEntry("Draw MyName", 7);
	glutAddMenuEntry("Draw  SierpinskiGasket", 8);
	glutAddMenuEntry("Exit", 9);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);			// glut �ʱ�ȭ
	initMenu();						// ��Ŭ���� �޴� ����
	glutInitWindowSize(500, 500);	// ������ ũ��
	glutInitWindowPosition(0, 0);	// ������ ó�� ��ġ
	glutCreateWindow("GLUT Callback Test");		// ������ ����
	glClearColor(1.0, 1.0, 1.0, 1.0);	// ��� ���
	glutDisplayFunc(display);

	glutReshapeFunc(reshape);		// ��������
	glutKeyboardFunc(keyboard);		// Ű���� �̺�Ʈ
	glutMouseFunc(mouseClick);		// ���콺 Ŭ�� �̺�Ʈ
	glutMotionFunc(mouseMotion);	// ���콺 ��� �̺�Ʈ
	glutTimerFunc(500, myTimer, 1);	// Ÿ�̸� �̺�Ʈ
	glutMainLoop();					// glut ���� ����
	return 0;
}