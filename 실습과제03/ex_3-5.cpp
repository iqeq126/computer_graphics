#define GLUT_DISABLE_ATEXIT_HACK
// glut�� �̿��� OpenGL �ڵ带 �������� �� ��Ŀ ������ �����ϴ� �뵵
#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <random>

void MyDisplay(void) {
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
	glColor3f(0.0, 0.0, 0.0);		// ���� ��Ÿ���� ���� ���� R, G, B ����

	glBegin(GL_POINTS);// GL_POINTS �������� ��
	for (GLint i = 0; i < 10000; i++) {
		//-> �蹫������ �� ���� ���� �� �� ���� �����Ѵ�.
		int whichV = dis(gen) % 3;
		//-> �� �������� �������� ���õ� ������ �߰����� ��´�.
		int newPx = (px + vx[whichV]) / 2;
		int newPy = (py + vy[whichV]) / 2;
		//-> �� �� ��ġ�� ���� �� ���� ǥ���� �����ν� ���ο� ���� ǥ��
		glVertex2i(newPx, newPy);
		//-> �� �������� �� ���� ���� �� �� ���� �����Ѵ�.
		px = newPx;
		py = newPy;
		//-> �� �ܰ� 2�� ���ư���. (�� ������ �־��� Ƚ����ŭ �ݺ�)
	}
	glEnd();	// -> ������ ���� �ǹ�
	glFlush();			// -> ������ �׷��� ���� ���۸� ���� �뵵
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);		// ������ ��Ÿ���� ����. ���
	gluOrtho2D(0, 250, 250, 0);
	// left, right, top, bottom���� Ŭ���� ����� ��ǥ�� ��Ÿ����.
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Sierpinski Gasket");

	glutDisplayFunc(MyDisplay);

	init();

	glutMainLoop();

	return 0;
}