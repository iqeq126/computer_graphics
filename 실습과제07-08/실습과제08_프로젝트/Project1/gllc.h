#pragma once
#include <stdio.h>
#include <memory.h> // memcpy 사용하기 위함
#include <gl/glut.h> //  glut를 사용하기 위함

#define _USE_MATH_DEFINES // M_PI 등을 사용하기 위함.
#include <math.h>
#define SIN(x) sin(x*M_PI / 180.) // degree 각을 이용한 sin
#define COS(x) cos(x*M_PI / 180.) // degree 각을 이용한 cos

// 변환 행렬 생성//
inline void glMatSet(double* m,
	double m00, double m01, double m02, double m03,
	double m10, double m11, double m12, double m13,
	double m20, double m21, double m22, double m23,
	double m30, double m31, double m32, double m33)
{
	double mat[16] = { m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33 };
	memcpy(m, mat, sizeof(double) * 16); // 메모리 복사 함수. strncpy와 유사하게 사용. 
}

// 변환 행렬 곱하기 //
inline void glMatMult(double* m1, double* m2) {
	double n[16];
	for (int k = 0; k < 16; k++) {
		n[k] = 0;
		double* p = m1 + (k / 4) * 4;
		double* q = m2 + (k % 4);
		for (int i = 0; i < 4; i++)
			n[k] += p[i] * q[i * 4];
	}
	memcpy(m1, n, sizeof(double) * 16);
}

// 행렬을 화면에 출력 //
inline void glMatPrint(double* m) {
	for (int i = 0; i < 4; i++) {
		printf("\t[");
		for (int j = 0; j < 4; j++)
			printf("%6.2f", m[i * 4 + j]);
		printf("]\n");
	}
	printf("\n");
}

// 항등행렬(i)
inline void glMatIdentity(double* m) {
	glMatSet(m, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

// 이동(t)
inline void glMatTrans(double* m, double tx, double ty, double tz) {
	glMatSet(m, 1, 0, 0, tx, 0, 1, 0, ty, 0, 0, 1, tz, 0, 0, 0, 1);
}

// 신축(s)
inline void glMatScale(double* m, double sx, double sy, double sz) {
	glMatSet(m, sx, 0, 0, 0, 0, sy, 0, 0, 0, 0, sz, 0, 0, 0, 0, 1);
}

// 회전(Z축 중심)
inline void glMatRotateZ(double* m, double a) {
	glMatSet(m, COS(a), -SIN(a), 0, 0, SIN(a), COS(a), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

// 회전(X축 중심)
inline void glMatRotateX(double* m, double a) {
	glMatSet(m, 1, 0, 0, 0, 0, COS(a), -SIN(a), 0, 0, SIN(a), COS(a), 0, 0, 0, 0, 1);
}
// 회전(Y축 중심)
inline void glMatRotateY(double* m, double a) {
	glMatSet(m, COS(a), 0, SIN(a), 0, 0, 1, 0, 0, -SIN(a), 0, COS(a), 0, 0, 0, 0, 1);

}

// X축 밀림
inline void glMatShearX(double* m, double dy, double dz) {
	glMatSet(m, 1, dy, dz, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

// Y축 밀림
inline void glMatShearY(double* m, double dx, double dz) {
	glMatSet(m, 1, 0, 0, 0, dx, 1, dz, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

// Z축 밀림
inline void glMatShearZ(double* m, double dx, double dy) {
	glMatSet(m, 1, 0, 0, 0, 0, 1, 0, 0, dx, dy, 1, 0, 0, 0, 0, 1);
}

// 정점의 변환함수 [q] = [M] [p]
inline void glTransform(double* m, double* p, double* q) {
	q[0] = q[1] = q[2] = q[3] = 0;
	for (int i = 0; i < 4; i++) {
		q[0] += m[i] * p[i];
		q[1] += m[i + 4] * p[i];
		q[2] += m[i + 8] * p[i];
		q[3] += m[i + 12] * p[i];
	}
}
// 간단한 그리기 함수들 : 선분
inline void glLine(double x1, double y1, double z1, double x2, double y2, double z2) {
	glBegin(GL_LINES);
	glVertex3d(x1, y1, z1);
	glVertex3d(x2, y2, z2);
	glEnd();
}

// 간단한 그리기 함수들 : 삼각형
inline void glTriangle4d(double* p) {
	glBegin(GL_TRIANGLES);
	glVertex4dv(p);
	glVertex4dv(p + 4);
	glVertex4dv(p + 8);
	glEnd();
}
// 간단한 그리기 함수들 : 좌표축
inline void glCoord() {			// 축의 색 표현
	glBegin(GL_LINES);
	glColor3d(1, 0, 0);	glVertex3d(-0.1, 0, 0);	glVertex3d(1, 0, 0);
	glColor3d(0, 1, 0);	glVertex3d(0, -0.1, 0); glVertex3d(0, 1, 0);
	glColor3d(0, 0, 1);	glVertex3d(0, 0, -0.1);	glVertex3d(0, 0, 1);
	glEnd();
}
// 문자열을 화면에 그림
extern void glString(const char* s); 
// 재질의 색상 설정 : 객체에 따라 결정
extern void glSetColor(float r, float g, float b, float a);
// 좌표계 그리기 : 원점에서 +x(red), +y(blue), +z(gray)로 길이 len인 선분
extern void glDrawCoord(double len); 

// extern void glMessage(int line_no, const char* message);
// extern void glGridPlaneChess();

#define FILTER_ASE "ASE 3D data (*.ase)\0*.ase\0All(*.*)\0*.*\0"
#define FILTER_BVH "BVH Motion Data (*.bvh)\0.bvh\0All (*.*)\0*.*\0"
#ifdef WIN32
// 
extern char* glFileDlg(const char*);
#endif
