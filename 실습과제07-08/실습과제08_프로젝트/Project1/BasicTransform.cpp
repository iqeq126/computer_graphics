#include "gllc.h"
#include <windows.h>
// 동차좌표계로 표시함
static double P[12] = { 0.3, 0.2, 0.1, 1,	0.7, 0.2, 0.1, 1,	0.5, 0.7, 0.1, 1 };
static double Q[12];

static char objNum = -1;			// 객체 번호. 메뉴 이벤트로 선택 예정
static int PrevX, PrevY;		// 마우스 X, Y  좌표 위치

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

	if (key == 'i') {				// 초기화
		printf("객체 초기화(i)\n");
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	else if (key == 't') {			// 이동
		printf("객체 이동(t)\n");
		glMatTrans(m1, -1, -0.5, 0);
		glMatPrint(m1);
		transformTri(m1, P, Q);
	}
	else if (key == 's') {			// 신축
		printf("객체 신축(s)\n");
		glMatScale(m1, 1.5, 1.2, 1.4);
		glMatPrint(m1);
		transformTri(m1, P, Q);
	}
	else if (key == 'x') {			// X축 회전
		printf("객체 X축 회전(x)\n");
		glMatRotateX(m1, 60);
		glMatPrint(m1);
		transformTri(m1, P, Q);
	}
	else if (key == 'y') {				// Y축 회전
		printf("객체 Y축 회전(y)\n");
		glMatRotateY(m1, 60);
		glMatPrint(m1);
		transformTri(m1, P, Q);
	}
	else if (key == 'z') {			// Z축 회전
		printf("객체 Z축 회전(z)\n");
		glMatRotateZ(m1, 60);
		glMatPrint(m1);
		transformTri(m1, P, Q);
	}
	else if (key == 'Z') {			// 복합변환 : 회전
		glMatTrans(m1, -P[0], -P[1], -P[2]);
		glMatRotateZ(m2, 60);
		glMatTrans(m3, P[0], P[1], P[2]);

		printf("복합변환 : 회전(Z)\n");
		glMatMult(m3, m2);
		glMatMult(m3, m1);
		transformTri(m3, P, Q);
	}
	else if (key == 'c') {			// 복합변환 : 신축 
		glMatTrans(m1, P[0], P[1], P[2]);
		glMatScale(m2, 1.5, 1.2, 1.4);
		glMatTrans(m3, -P[0], -P[1], -P[2]);
		
		printf("복합변환 : 신축(c)\n");
		glMatPrint(m1);
		glMatPrint(m2);
		glMatPrint(m3);

		glMatMult(m1, m2);
		glMatMult(m1, m3);
		glMatPrint(m1);
		transformTri(m1, P, Q);
	}
	else if (key == 'h') {			// 밀림
		printf("밀림(h)\n");
		glMatShearX(m1, 0.3, 0);
		transformTri(m1, P, Q);
	}
	else if (key == 'j') {		// 자신만의 복합변환
		glMatScale(m1, 1, 2.0, 1);
		glMatTrans(m2, 0, 0.3, 0.2);
		glMatRotateX(m3, 180);
		printf("복합변환 : (j)\n");
		glMatPrint(m1);
		
		glMatMult(m1, m2);
		glMatMult(m1, m3);
		printf("다음\n");

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
	// 오른쪽 마우스 클릭 시 메뉴 접근 ( 자세한 사항 initMenu, myMenu에 구현 )
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

void myMenu(int id) { // 메뉴를 그리는 함수
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
void initMenu(void) {	// 우클릭시 메뉴 접근
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