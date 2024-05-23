#define GLUT_DISABLE_ATEXIT_HACK
// glut을 이용한 OpenGL 코드를 컴파일할 때 링커 에러가 방지하는 용도
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

	glFlush();
}
void SierpinskiGasket() {
	GLfloat vx[] = { 1.0, 0.0, 2.0 };
	GLfloat vy[] = { 0.0, 2.0, 2.0 };
	// 세 개의 정점 (100, 0), (0, 200), (200, 200)
	GLfloat px = 1;
	GLfloat py = 1;
	// -> ① 삼각형 내부에서 무작위로 초기 값 px와 py를 잡는다.
	std::random_device rd;		// 시드값을 얻기 위한 random_device 생성.
	std::mt19937 gen(rd());		// random_device 를 통해 난수 생성 엔진을 초기화 한다.

	// 0 부터 2 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	std::uniform_int_distribution<int> dis(0, 2);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);		// 색을 나타내기 위함 각각 R, G, B 순서

	glBegin(GL_POINTS);// GL_POINTS 독립적인 점
	for (GLint i = 0; i < 1000; i++) {
		//-> ②무작위로 세 개의 정점 중 한 개를 선택한다.
		int whichV = dis(gen) % 3;
		//-> ③ 시작점과 무작위로 선택된 정점의 중간점을 잡는다.
		float newPx = (px + vx[whichV]) / 2.0;
		float newPy = (py + vy[whichV]) / 2.0;
		//-> ④ 그 위치에 작은 원 같은 표지를 함으로써 새로운 점을 표시
		glVertex2f(newPx-1, -newPy+1);
		//-> ⑤ 무작위로 세 개의 정점 중 한 개를 선택한다.
		px = newPx;
		py = newPy;
		//-> ⑥ 단계 2로 돌아간다. (이 과정을 주어진 횟수만큼 반복)
	}
	glEnd();	// -> 정점의 끝을 의미
	glFlush();			// -> 정점이 그려진 곳의 버퍼를 비우는 용도
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
