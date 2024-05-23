#include<gl/glut.h>
#include<gl/gl.h>
#include<gl/glu.h>

void MyDisplay()

{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300); // (2! SACs, 7+, MB) - AM 1DZ0] SALE S|Al2} 37]
	glColor3f(1, 1, 1); // HAS -4S AM AlSol we +] Tech
	glRotatef(30, 1, 1, 1); // AAMAS

	glutSolidCube(1.0);
	glutWireCube(1.0);

	glutSolidSphere(1, 100, 100);
	glutWireSphere(1, 100, 100);

	// PABtAll
	glutSolidTorus(1, 1, 100, 100);
	glutWireTorus(1, 1, 100, 100);
	glutSolidCone(1, 1, 100, 100);
	glutWireCone(1, 1, 100, 100);

	// 848M
	glutSolidTetrahedron();
	glutWireTetrahedron();

	glutSolidTeapot(0.5);

	glutWireTeapot(0.5);

	glFlush();

}

int main(int argc, char** argv)

{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB); // RGB Bet SPAS APSorach
	glutInitWindowSize(300, 300); // 2) 47) - Hele Ae
	glutInitWindowPosition(0, 0); // LSS SARS Ml SE Al
	glutCreateWindow("OpenGL Drawing Example"); // 1222! AlS
	glClearColor(0.0, 0.0, 0.0, 1.0); // HA4%S HAS (RGBN) NZ FSH?)
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // S22! Be] HE
	glutDisplayFunc(MyDisplay); // 2lZt2 S/2| Br S
	glutMainLoop();

	return 0;
}