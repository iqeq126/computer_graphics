#define GLUT_DISABLE_ATEXIT_HACK
// glut을 이용한 OpenGL 코드를 컴파일할 때 링커 에러가 방지하는 용도
#include <gl/GLUT.h>
#include <math.h>
#include <windows.h>
#include <iostream>
#include <random>
static int objNum = -1;			// 객체 번호. 0부터 시작하므로 초기값 -1로 설정
static bool bAuto = true;		// 자동 갱신 모드 설정 변수
static int PrevX, PrevY;		// 마우스 X, Y  좌표 위치

// 이름 출력
void MyName() {
	// 조
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

	//원
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

	//석

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
// SierpinskiGasket 출력
void SierpinskiGasket() {
	GLint vx[] = { 100, 0, 200 };
	GLint vy[] = { 0, 200, 200 };
	// 세 개의 정점 (100, 0), (0, 200), (200, 200)
	GLint px = 100;
	GLint py = 100;
	// -> ① 삼각형 내부에서 무작위로 초기 값 px와 py를 잡는다.
	std::random_device rd;		// 시드값을 얻기 위한 random_device 생성.
	std::mt19937 gen(rd());		// random_device 를 통해 난수 생성 엔진을 초기화 한다.

	// 0 부터 2 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	std::uniform_int_distribution<int> dis(0, 2);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);		// 색을 나타내기 위함 각각 R, G, B 순서
	glBegin(GL_POINTS);// GL_POINTS 독립적인 점
	for (GLint i = 0; i < 10000; i++) {
		//-> ②무작위로 세 개의 정점 중 한 개를 선택한다.
		int whichV = dis(gen) % 3;
		//-> ③ 시작점과 무작위로 선택된 정점의 중간점을 잡는다.
		int newPx = (px + vx[whichV]) / 2;
		int newPy = (py + vy[whichV]) / 2;
		//-> ④ 그 위치에 작은 원 같은 표지를 함으로써 새로운 점을 표시
		glVertex3d(1 + newPx / (-100.0), 1 - newPy/(100.0), 0);
		//-> ⑤ 무작위로 세 개의 정점 중 한 개를 선택한다.
		px = newPx;
		py = newPy;
		//-> ⑥ 단계 2로 돌아간다. (이 과정을 주어진 횟수만큼 반복)
	}
	glEnd();	// -> 정점의 끝을 의미
}
// 도형 객체를 선택하는 부분
void display() {
	glClear(GL_COLOR_BUFFER_BIT);	// 색깔 버퍼 초기화
	glColor3f(1.0, 0.0, 0.0);	// 객체 색 Red
	switch (objNum) {	// 객체 선택 : 0_큐브, ~ 7_이름, 8_삼각형
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
	glFlush();	// 정점이 그려진 곳의 버퍼를 비우는 용도
}

// 시간을 측정하는 부분
void myTimer(int Value) {
	glutPostRedisplay();
	if (bAuto) {			// 자동으로 다음 객체를 출력하는 모드
		objNum = (objNum + 1) % 9;		// 0 ~ 8 범위 선택
	}
	glutTimerFunc(500, myTimer, 1);
}

// 키보드 이벤트
void keyboard(unsigned char key, int x, int y) {
	// 0 ~ 8 범위의 객체 선택, 자동 갱신 OFF
	if (key >= '0' && key <= '8') {
		bAuto = false;
		objNum = key - '0';
	}
	// A 버튼. 자동 갱신 toggle 
	else if (key == 'a' || key == 'A') {
		bAuto = !bAuto;
	}
	// I 버튼. 객체 회전 초기화
	else if (key == 'i' || key == 'I') {
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	// Q 버튼 or ESC 버튼. 윈도우 탈출
	else if (key == 'q' || key == 'Q' || key == 27)
		exit(0);
	glutPostRedisplay();		// 화면 다시 출력
}

// 리쉐이프. 윈도우 크기가 변하더라도 객체의 가로 세로 비율 유지.
void reshape(int width, int height) {
	// 현재 윈도우 너비, 높이 정보
	glViewport(0, 0, width, height);
	double wScale = (double)width / 500;
	double hScale = (double)height / 500;

	// 처음 회전 상태로 되돌리는 기능
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-wScale, wScale, -hScale, hScale, -1, 1);
}

// 마우스 클릭.
void mouseClick(int button, int state, int x, int y) {
	// 왼쪽 마우스 클릭 시. Prev 변수에 x, y 값 전달
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		PrevX = x;
		PrevY = y;
	}
	// 오른쪽 마우스 클릭 시 메뉴 접근 ( 자세한 사항 initMenu, myMenu에 구현 )
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
// 마우스 움직임
void mouseMotion(GLint x, GLint y) {
	// 
	glMatrixMode(GL_MODELVIEW);
	glRotated(x - PrevX, 0, 1, 0);
	glRotated(y - PrevY, 1, 0, 0);
	PrevX = x;
	PrevY = y;
	glutPostRedisplay();
}


void myMenu(int id) { // 메뉴를 그리는 함수
	if (id >= 0 && id <= 8)
		keyboard(id + '0', 0, 0);
	else if (id == 9) exit(0);
	glutPostRedisplay();
}
void initMenu(void) {	// 우클릭시 메뉴 접근
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
	glutInit(&argc, argv);			// glut 초기화
	initMenu();						// 우클릭시 메뉴 접근
	glutInitWindowSize(500, 500);	// 윈도우 크기
	glutInitWindowPosition(0, 0);	// 윈도우 처음 위치
	glutCreateWindow("GLUT Callback Test");		// 윈도우 제목
	glClearColor(1.0, 1.0, 1.0, 1.0);	// 배경 흰색
	glutDisplayFunc(display);

	glutReshapeFunc(reshape);		// 리쉐이프
	glutKeyboardFunc(keyboard);		// 키보드 이벤트
	glutMouseFunc(mouseClick);		// 마우스 클릭 이벤트
	glutMotionFunc(mouseMotion);	// 마우스 모션 이벤트
	glutTimerFunc(500, myTimer, 1);	// 타이머 이벤트
	glutMainLoop();					// glut 루프 실행
	return 0;
}