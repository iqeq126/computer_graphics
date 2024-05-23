#pragma once
#include "Mesh.h"
#include <windows.h>
class Robot {
public:
	// 로봇의 부품
	Mesh Head, Body, RightArm, RightHand, LeftArm, LeftHand;
	Mesh RightLeg, RightFoot, LeftLeg, LeftFoot;
	
	float scale;			// 모델의 스케일

	Robot() { // 로봇 readAse 로딩 구현
		scale = 100;		// 좌표값이 -100 ~ 100 범위
		
		printf("Loading Robot Models....\n");
		Head.readAse("s_Head.ASE");				printf("loading Head..........OK.\n");
		Body.readAse("S_Body.ASE");				printf("loading Body...........OK.\n");
		RightArm.readAse("S_RightArm.ASE");		printf("loading RightArm.......OK.\n");
		RightHand.readAse("S_RightHand.ASE");	printf("loading RightHand......OK.\n");
		LeftArm.readAse("S_LeftArm.ASE");		printf("loading LeftArm........OK.\n");
		LeftHand.readAse("S_LeftHand.ASE");		printf("loading LeftHand.......OK.\n");
		RightLeg.readAse("S_RightLeg.ASE");		printf("loading RightLeg.......OK.\n");
		RightFoot.readAse("S_RightFoot.ASE");	printf("loading RightFoot......OK.\n");
		LeftLeg.readAse("S_LeftLeg.ASE");		printf("loading LeftLeg........OK.\n");
		LeftFoot.readAse("S_LeftFoot.ASE");		printf("loading LeftFoot.......OK.\n");
	}
	void resize(bool flag = true) { // z 구현 : 크기 다시 설정하기
		if (flag) scale *= 1.05f;
		else scale *= 0.95;
	}
	void draw() { // 로봇 조립해서 그리기
		bRun ? animateBody() : myBody();
		Body.draw(0.5, 0.8, 0.8, scale, true);
		
		glPushMatrix(); // 몸통 좌표계 저장
		glTranslated(0.0, 0.45, -0.07);
		glScalef(1.1f, 1.1f, 1.1f);
		bRun ? animateHead() : myHead();
		Head.draw(0.8, 0.7, 0.7, scale);
		glPopMatrix(); // 몸통 좌표계로 돌아가기

		glPushMatrix(); // 몸통 좌표계 저장
		glTranslated(-0.25, 0.32, 0.0);
		glScalef(1.0f, 1.0f, 1.0f);
		bRun ? animateRightArm() : myRightArm();
		RightArm.draw(0.4, 0.4, 0.8, scale);

		glPushMatrix(); // 오른어깨 좌표계 저장
		glTranslated(-0.05, -0.3, 0.0);
		glScalef(1.0f, 1.0f, 1.0f);
		bRun ? animateRightHand() : myRightHand();
		RightHand.draw(0.8, 0.8, 0.8, scale);
		glPopMatrix(); // 오른어깨 좌표계로 돌아가기
		glPopMatrix(); // 몸통 좌표계로 돌아가기

		glPushMatrix();		// 몸통 좌표계 저장하기
		glTranslated(0.25, 0.32, 0.0);
		glScalef(1.0f, 1.0f, 1.0f);
		bRun ? animateLeftArm() : myLeftArm();
		LeftArm.draw(0.4, 0.4, 0.8, scale);

		glPushMatrix();
		glTranslated(0.05, -0.3, 0.0);
		glScalef(1.0f, 1.0f, 1.0f);
		bRun ? animateLeftHand() : myLeftHand();
		LeftHand.draw(0.8, 0.8, 0.8, scale);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.1, -0.05, -0.02);
		glScalef(1.0f, 1.0f, 1.0f);
		bRun ? animateRightLeg() : myRightLeg();
		RightLeg.draw(0.4, 0.4, 0.8, scale);

		glPushMatrix();
		glTranslated(0.0, -0.45, 0.0);
		glScalef(1.0f, 1.0f, 1.0f);
		bRun ? animateRightFoot() : myRightFoot();
		RightFoot.draw(0.8, 0.8, 0.8, scale);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.1, -0.05, -0.02);
		glScalef(1.0f, 1.0f, 1.0f);
		bRun ? animateLeftLeg() : myLeftLeg();
		LeftLeg.draw(0.4, 0.4, 0.8, scale);

		glPushMatrix();
		glTranslated(0.0, -0.45, 0.0);
		glScalef(1.0f, 1.0f, 1.0f);
		bRun ? animateLeftFoot() : myLeftFoot();
		LeftFoot.draw(0.8, 0.8, 0.8, scale);
		glPopMatrix();
		glPopMatrix();
	}
	//==============================================================================================================================
	// 애니메이션을 위한 코드
	double tAngle, sin_t = 0, sin_t2 = 0, cos_t = 0;
	bool bRun = false, bMine = false;
	void reset() {
		bRun = false;
		bMine = false;
		scale = 100;
		sin_t = 0;
		cos_t = 0;
		sin_t2 = 0;
		tAngle = 0;				// 로봇이 달리는 정도를 구하기 위한 각도 : 0~360도
	}

	void stop() { bRun = false; bMine = false;  }
	
	void run() {
		bRun = true;
		bMine = false;
		tAngle += 10;
		if (tAngle >= 360)
			tAngle -= 360;
		sin_t = SIN(tAngle);
		cos_t = COS(tAngle);
		sin_t2 = SIN(2 * tAngle);
	}
	void myRun() {
		bRun = false;
		bMine = true;
		tAngle += 10;
		if (tAngle >= 360)
			tAngle -= 360;
		sin_t = SIN(tAngle);
		cos_t = COS(tAngle);
		sin_t2 = SIN(2 * tAngle);
	}

	// 각 부품에 대한 애니메이션 변환(모델 변환)
	void animateBody() {
		glTranslated(0.0, (sin_t2 * 0.04), 0); // 몸통의 위치 설정
		// glRotatef(-sin_t2 * 15 - 10, 1, 0, 0);	// 몸통의 상하회전 설정
		// glRotatef(- sin_t * 13, 0, 1, 0); // 몸통의 좌우회전 설정
	}
	void animateHead() {
		glRotatef(-cos_t * 30, 0, 1, 0);
	}
	void animateRightArm() {
		glRotatef(-cos_t * 65, 1, 0, 0);
	}
	void animateRightHand() {
		//glRotatef(-cos_t * 45 + 45, 0, 1, 0);
		glRotatef(-sin_t * 20 - 20, 0, 1, 0);
	}
	void animateLeftArm() {
		glRotatef(cos_t * 65, 1, 0, 0);
	}
	void animateLeftHand() {
		glRotatef(cos_t * 45 + 10, 1, 0, 0);
	}
	void animateRightLeg() {
		glRotatef(cos_t * 45 + 35, 1, 0, 0);
	}
	void animateRightFoot() {
		glRotatef(sin_t * 50 - 55, 1, 0, 0);
		glRotatef(tAngle / 20, 0, -1, 0);
	}
	void animateLeftLeg() {
		glRotatef(-cos_t * 45 + 35, 1, 0, 0);
	}
	void animateLeftFoot() {
		glRotatef(-sin_t * 50 - 55, 1, 0, 0);
		glRotatef(-1 * (tAngle / 20), 0, -1, 0);
	}

	// 나만의 동작
	void myBody() {
		glTranslated(0.0, sin_t2 * 0.02, 0); // 몸통의 위치 설정
		// glRotatef(-sin_t2 * 15 - 10, 1, 0, 0);	// 몸통의 상하회전 설정
		// glRotatef(- sin_t * 13, 0, 1, 0); // 몸통의 좌우회전 설정
	}
	void myHead() {
		glRotatef(abs(sin_t * 10), 1, 0, 0);
	}
	void myRightArm() {
		sin_t > 0 ? glRotatef(-2 * abs(sin_t * 80) - 10, 0, 0, 1) : glRotatef(-abs(sin_t * 80) - 10, 0, 0, 1);
	}
	void myRightHand() {
		glRotatef(-abs(cos_t * 25) + 10, 0, 0, 1);
	}
	void myLeftArm() {
		sin_t > 0 ? glRotatef(2 * abs(sin_t * 80) + 10, 0, 0, 1) : glRotatef(abs(sin_t * 80) + 10, 0, 0, 1);
	}
	void myLeftHand() {
		glRotatef(abs(cos_t * 25) - 10, 0, 0, 1);
	}
	void myRightLeg() {
		sin_t > 0 ? glRotatef(-abs(sin_t* 30) - 0, 0, 0, 1): glRotatef(-abs(sin_t * 20) - 0, 0, 0, 1);
	}
	void myRightFoot() {
		sin_t > 0 ? glRotatef(-abs(sin_t * 25), 1, 0, 0) : glRotatef(-abs(sin_t * 25), 0, 1, 0);
	}
	void myLeftLeg() {
		sin_t > 0 ? glRotatef(abs(sin_t * 30) - 0, 0, 0, 1) : glRotatef(abs(sin_t * 20) - 0, 0, 0, 1);
	}
	void myLeftFoot() {
		sin_t > 0 ? glRotatef(-abs(sin_t * 25), 1, 0, 0) : glRotatef(-abs(sin_t * 25), 0, 1, 0);
	}
};