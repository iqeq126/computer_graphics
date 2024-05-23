#include <iostream>
using namespace std;
struct Point2D { double x, y; };

// ����-�������� �˰���

// LEFT, RIGHT, BOTTOM, TOP�� ���� 0001 0010 0100 1000�� �̿���
// ��Ʈ �������� ���� �� �ֵ��� ������ ���� Encode �޼��带 ��������.
enum Boundary { LEFT = 0x01, RIGHT = 0x02, BOTTOM = 0x04, TOP = 0x08};
char Encode(Point2D p, Point2D min, Point2D max) {
	unsigned char code = 0x00;
	if (p.x < min.x) code |= LEFT;
	if (p.x > max.x) code |= RIGHT;
	if (p.y < min.y) code |= BOTTOM;
	if (p.y > max.y) code |= TOP;
	return (code);
}

// Swap_If_Nedded x1, y1�� �ܺο� �ֵ��� �ٲ��ִ� �Լ�
// p1�� p2�� ������ ����� �̲���� ���� ������ ���� ������ �����ߴ�.
void Swap_If_Nedded(Point2D& p1, Point2D& p2, char& c1, char& c2) {
	if (c1 == 0) {
		Point2D r = p1; 
		p1 = p2;
		p2 = r;
		
		char tmp = c1; 
		c1 = c2; 
		c2 = tmp;
	}
}

// Accept ���� : (c1 OR c2) == 0
bool Accept(char c1, char c2) {
	return (c1 | c2) == 0;
}
// Reject ���� : (c1 AND c2) �� 0
bool Reject(char c1, char c2) { 
	return (c1 & c2) != 0; 
}
// drawLine : ����-��������� ����-�ٽ�Ű �˰����� ����� ����ϴ� �޼����̴�.
void drawLine(Point2D p1, Point2D p2) {
	printf("\t\t������: (%4.2lf, %4.2lf)--(%4.2lf, %4.2lf)\n", p1.x, p1.y, p2.x, p2.y);
}


// ����-�������� �˰��� ����
void clipLine_CS(Point2D min, Point2D max, Point2D p1, Point2D p2) {
	char code1, code2;
	int done = false, display = false;
	int i = 0;
	while (!done) {
		code1 = Encode(p1, min, max);
		code2 = Encode(p2, min, max);
		//printf("code1 : %d\tcode2 : %d\n", code1, code2);
		if (Accept(code1, code2)) {
			done = display = true;
		}
		else if (Reject(code1, code2)) {
			done = display = false;
			return;
		}
		else {
			Swap_If_Nedded(p1, p2, code1, code2);		// ���� ��ġ�� �ٲ���.
			double m = (p2.y - p1.y) / (p2.x - p1.x);	// ����
			if (code1 & LEFT) {
				p1.y = p1.y + (min.x - p1.x) * m;	// ���� ������ ����
				p1.x = min.x;
				code1 -= LEFT;
			}
			else if (code1 & RIGHT) {
				p1.y = p1.y + (max.x - p1.x) * m;	// ���� ������ ����
				p1.x = max.x;
				code1 -= RIGHT;
			}
			else if (code1 & BOTTOM) {
				p1.x = p1.x + (min.y - p1.y) / m;	// ���� ������ ����
				p1.y = min.y;
				code1 -= BOTTOM;
			}
			else if (code1 & TOP) {
				p1.x = p1.x + (max.y - p1.y) / m;	// ���� ������ ����
				p1.y = max.y;
				code1 -= TOP;
			}
		}
	}
	drawLine(p1, p2);
}
// ����-�ٽ�Ű �˰���
bool clipTest(double p, double q, double* u1, double* u2) {
	double r = 0.0;
	bool result = true;
	if (p < 0.0) {	// �ܺο��� ���η� �� 
		r = (double)q / p;
		if (r > *u2) result = false;
		else if (r > *u1) {
			*u1 = r;
			return true;
		}
	}
	else if (p > 0.0 ) {	// ���ο��� �ܺη� ����
		r = (double) q / p;
		if (r < *u1) result = false;
		else if (r < *u2) {
			*u2 = r;
			return true;
		}
	}
	else {				// ���� �Ǵ� ����(���༱)
		if (q < 0) result = false;
	}
	return result;
}

void clipLine_LB(Point2D min, Point2D max, Point2D p1, Point2D p2) {
	double U1 = 0, U2 = 1;
	double *u1 = &U1, *u2 = &U2;
	double dx = p2.x - p1.x;
	double dy = p2.y - p1.y;
	// printf("dx, dy : %lf %lf\n", dx, dy);
	if (clipTest(-dx, p1.x - min.x, u1, u2)) {						//left
		if (clipTest(dx, max.x - p1.x, u1, u2)) {					//right
			if (clipTest(-dy, p1.y - min.y, u1, u2)) {				//lower
				if (clipTest(dy, max.y - p1.y, u1, u2)) {			//upper
					if (*u2 < 1.0) {
						p2.x = p1.x + (*u2) * dx;
						p2.y = p1.y + (*u2) * dy;
					}
					if (*u1 > 0.0) {
						p1.x = p1.x + (*u1) * dx;
						p1.y = p1.y + (*u1) * dy;
					}
					drawLine(p1, p2);
				}
			}
		}
	}
}
void lineClipTest(Point2D min, Point2D max, Point2D p, Point2D q) {
	printf("\n������ : (%4.2lf, %4.2lf), (%4.2lf, %4.2lf)\n"
		, p.x, p.y, q.x, q.y);
	printf("���1: ");
	clipLine_CS(min, max, p, q);		
	printf("���2: ");
	clipLine_LB(min, max, p, q);
}
int main(int argc, char** argv) {
	Point2D min = { -1, -1 };
	Point2D max = { 1,1 };
	Point2D p[8] = {
		{ -2, 0 }, { 2, 0 },
		{ -0.3, 0 }, { 2, 1.5 },
		{ -2, 0 }, { 0.5, -0.2 },
		{ -1.3, 0 }, { -2, 1.5 }
	};

	lineClipTest(min, max, p[0], p[1]);
	lineClipTest(min, max, p[2], p[3]);
	lineClipTest(min, max, p[4], p[5]);
	lineClipTest(min, max, p[6], p[7]);
	getchar();
	return 0;
}