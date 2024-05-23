#define GLUT_DISABLE_ATEXIT_HACK
// glut을 이용한 OpenGL 코드를 컴파일할 때 링커 에러가 방지하는 용도
#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <random>

void MyDisplay(void) {
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
	glColor3f(0.0, 0.0, 0.0);		// 색을 나타내기 위함 각각 R, G, B 순서

	glBegin(GL_POINTS);// GL_POINTS 독립적인 점
	for (GLint i = 0; i < 10000; i++) {
		//-> ②무작위로 세 개의 정점 중 한 개를 선택한다.
		int whichV = dis(gen) % 3;
		//-> ③ 시작점과 무작위로 선택된 정점의 중간점을 잡는다.
		int newPx = (px + vx[whichV]) / 2;
		int newPy = (py + vy[whichV]) / 2;
		//-> ④ 그 위치에 작은 원 같은 표지를 함으로써 새로운 점을 표시
		glVertex2i(newPx, newPy);
		//-> ⑤ 무작위로 세 개의 정점 중 한 개를 선택한다.
		px = newPx;
		py = newPy;
		//-> ⑥ 단계 2로 돌아간다. (이 과정을 주어진 횟수만큼 반복)
	}
	glEnd();	// -> 정점의 끝을 의미
	glFlush();			// -> 정점이 그려진 곳의 버퍼를 비우는 용도
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);		// 배경색을 나타내기 위함. 흰색
	gluOrtho2D(0, 250, 250, 0);
	// left, right, top, bottom으로 클리핑 평면의 좌표를 나타낸다.
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