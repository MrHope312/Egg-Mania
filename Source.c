#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<GL/freeglut.h>
#include<stdbool.h>

double PI = 3.14;
double a = 400;
bool col1 = false, col2 = false, col3 = false, col4 = false;
int time = 0, p1 = 0;
double oy1 = 550, oy2 = 550, oy3 = 550, oy4 = 550, oy5 = 550;
double basket_x, basket_y;
int eggcaught = 0;
int f = 0;

void bitmap_output(double x, double y, char* string, void* font, double r, double g, double b)
{
	int len, i;
	glColor3d(r, g, b);
	glRasterPos2d(x, y);
	len = (int)strlen(string);
	for (i = 0;i<len;i++)
	{
		glutBitmapCharacter(font, string[i]);
	}
}
void resize(int width, int height)
{
	glutReshapeWindow(400, 600);
}
void splash_screen()
{


	glColor3d(0.929, 0.965, 0.976);
	glBegin(GL_QUADS);
	glVertex2i(0, 400);
	glVertex2i(0, 600);
	glVertex2i(400, 600);
	glVertex2i(400, 400);
	glEnd();


	glColor3d(0.855, 0.914, 0.937);
	glBegin(GL_QUADS);
	glVertex2i(0, 200);
	glVertex2i(0, 400);
	glVertex2i(400, 400);
	glVertex2i(400, 200);
	glEnd();


	glColor3d(0.808, 0.906, 0.937);
	glBegin(GL_QUADS);
	glVertex2i(0, 0);
	glVertex2i(0, 200);
	glVertex2i(400, 200);
	glVertex2i(400, 0);
	glEnd();


	glColor3f(0.71, 0.396, 0.114);
	glBegin(GL_POLYGON);
	glVertex2f(45, 45);
	glVertex2f(70, 20);
	glVertex2f(95, 20);
	glVertex2f(120, 45);
	glVertex2f(95, 70);
	glVertex2f(70, 70);
	//neck
	glVertex2f(95, 95);
	glVertex2f(82.5, 107.5);
	glVertex2f(32.5, 57.5);
	glEnd();

	//beak
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(82.5, 107.5);
	glVertex2f(65, 107.5);
	glVertex2f(50, 95);
	glVertex2f(70, 95);
	glEnd();
	//eye
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(76, 101);
	glEnd();

	//tree
	glColor3f(.3, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(125, 225);
	glVertex2f(75, 225);
	glVertex2f(100, 250);
	glVertex2f(113, 275);
	glVertex2f(113, 300);
	glVertex2f(100, 325);
	glVertex2f(125, 313);
	glVertex2f(150, 325);
	glVertex2f(138, 300);
	glVertex2f(138, 275);
	glVertex2f(150, 250);
	glVertex2f(175, 225);
	glFlush();
	glEnd();


	glColor3f(0.78, 0.886, 0.322);
	glBegin(GL_POLYGON);
	glVertex2f(88, 300);
	glVertex2f(63, 325);
	glVertex2f(50, 350);
	glVertex2f(50, 400);
	glVertex2f(63, 425);
	glVertex2f(88, 450);
	glVertex2f(125, 463);
	glVertex2f(163, 450);
	glVertex2f(188, 425);
	glVertex2f(200, 400);
	glVertex2f(200, 350);
	glVertex2f(188, 325);
	glVertex2f(163, 300);
	glFlush();
	glEnd();

	//tree2
	glColor3f(0.3, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(300, 225);
	glVertex2f(250, 225);
	glVertex2f(275, 250);
	glVertex2f(288, 275);
	glVertex2f(288, 300);
	glVertex2f(275, 325);
	glVertex2f(300, 313);
	glVertex2f(325, 325);
	glVertex2f(313, 300);
	glVertex2f(313, 275);
	glVertex2f(325, 250);
	glVertex2f(350, 225);
	glEnd();

	glColor3f(0.82, 0.976, 0.157);
	glBegin(GL_POLYGON);
	glVertex2f(263, 300);
	glVertex2f(238, 325);
	glVertex2f(225, 350);
	glVertex2f(225, 400);
	glVertex2f(238, 425);
	glVertex2f(263, 450);
	glVertex2f(300, 463);
	glVertex2f(338, 450);
	glVertex2f(363, 425);
	glVertex2f(375, 400);
	glVertex2f(375, 350);
	glVertex2f(363, 325); //10,12,18
	glVertex2f(338, 300);
	glEnd();

	bitmap_output(135, 500, "EGG MANIA", GLUT_BITMAP_TIMES_ROMAN_24, 0, 0, 0);
	bitmap_output(100, 400, "M SHREYAS ", GLUT_BITMAP_TIMES_ROMAN_10, 0, 0, 0);
	bitmap_output(100, 380, "1CD15CS082 ", GLUT_BITMAP_TIMES_ROMAN_10, 0, 0, 0);
	bitmap_output(280, 400, "FELICITA A ", GLUT_BITMAP_TIMES_ROMAN_10, 0, 0, 0);
	bitmap_output(280, 380, "1CD15CS050 ", GLUT_BITMAP_TIMES_ROMAN_10, 0, 0, 0);

	bitmap_output(50, 180, "How to Play..?", GLUT_BITMAP_HELVETICA_18, 1, 0.2, 0.7);
	bitmap_output(50, 150, "The objective of the game is to catch the eggs in the basket.", GLUT_BITMAP_HELVETICA_12, 0, 0, 0);
	bitmap_output(50, 135, "To move Basket use arrow keys", GLUT_BITMAP_HELVETICA_12, 0, 0, 0);



	bitmap_output(100, 100, "Press ENTER to PLAY", GLUT_BITMAP_HELVETICA_18, 1, 0, 0);



}

void basket(double i, double j)
{
	j = 10;
	if (i >= a - 60)i = a - 60;
	glColor3d(0.42, 0.259, 0.125);
	glBegin(GL_QUADS);
	glVertex2d(0 + i, 30 + j);
	glVertex2d(10 + i, 10 + j);
	glVertex2d(50 + i, 10 + j);
	glVertex2d(60 + i, 30 + j);
	glEnd();
}

void game_over() {

	glColor3d(0.8, 0.2, 0.4);
	glBegin(GL_QUADS);
	glVertex2d(0, 0);
	glVertex2d(0, 600);
	glVertex2d(400, 600);
	glVertex2d(400, 0);
	glEnd();
	bitmap_output(130, 300, "GAME OVER", GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1);
	bitmap_output(10, 250, "******CONGRATULATIONS****** ", GLUT_BITMAP_TIMES_ROMAN_24, 0, 1, 1);
	bitmap_output(70, 200, "YOU CAUGHT 15 EGGS ", GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1);

}

void circle(double x, double y, double radius, double r, double g, double b)
{
	int i;
	int triangleAmount = 20;
	double twicePi = 2.0f * PI;
	glColor3d(r, g, b);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2d(x, y);
	for (i = 0; i <= triangleAmount;i++) {
		glVertex2d(
			x + (radius * cos(i *  twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
}



void day()
{


	//sky
	glColor3d(0.929, 0.965, 0.976);
	glBegin(GL_QUADS);
	glVertex2i(0, 500);
	glVertex2i(0, 600);
	glVertex2i(400, 600);
	glVertex2i(400, 500);
	glEnd();


	glColor3d(0.855, 0.914, 0.937);
	glBegin(GL_QUADS);
	glVertex2i(0, 400);
	glVertex2i(0, 500);
	glVertex2i(400, 500);
	glVertex2i(400, 400);
	glEnd();


	glColor3d(0.808, 0.906, 0.937);
	glBegin(GL_QUADS);
	glVertex2i(0, 300);
	glVertex2i(0, 400);
	glVertex2i(400, 400);
	glVertex2i(400, 300);
	glEnd();



	glColor3d(0.643, 0.847, 0.918);
	glBegin(GL_QUADS);
	glVertex2i(0, 200);
	glVertex2i(0, 300);
	glVertex2i(400, 300);
	glVertex2i(400, 200);
	glEnd();


	glColor3d(0.561, 0.824, 0.918);
	glBegin(GL_QUADS);
	glVertex2i(0, 100);
	glVertex2i(0, 200);
	glVertex2i(400, 200);
	glVertex2i(400, 100);
	glEnd();


	glColor3d(0.314, 0.765, 0.886);
	glBegin(GL_QUADS);
	glVertex2i(0, 0);
	glVertex2i(0, 100);
	glVertex2i(400, 100);
	glVertex2i(400, 0);
	glEnd();


	//sun
	circle(40.13, 480.74, 30, 1, 0.902, 0.482);
	//constant clouds
	circle(96.56, 449.59, 20, 1, 1, 1);
	circle(77.97, 444.20, 20, 1, 1, 1);
	circle(53.25, 443.25, 20, 1, 1, 1);
	circle(35.25, 447.75, 20, 1, 1, 1);
	circle(53.29, 465.17, 20, 1, 1, 1);
	circle(77.97, 459.33, 20, 1, 1, 1);

	circle(287.94, 510.16, 25, 1, 1, 1);
	circle(321.17, 511.34, 25, 1, 1, 1);
	circle(346.19, 518.60, 25, 1, 1, 1);
	circle(321.17, 531.71, 25, 1, 1, 1);
	circle(287.94, 539.57, 25, 1, 1, 1);
	circle(263.37, 514.40, 25, 1, 1, 1);

	circle(332.15, 202.15, 15, 1, 1, 1);
	circle(318.22, 187.72, 15, 1, 1, 1);
	circle(332.15, 185.48, 15, 1, 1, 1);
	circle(350.99, 186.15, 15, 1, 1, 1);
	circle(365.94, 190.18, 15, 1, 1, 1);
	circle(350.99, 197.78, 15, 1, 1, 1);

	//left land
	glColor3d(0.78, 0.886, 0.322);
	glBegin(GL_POLYGON);
	glVertex2d(0, 169.25);
	glVertex2d(52.314, 163.812);
	glVertex2d(177.458, 135.848);
	glVertex2d(121.089, 121.089);
	glVertex2d(306.246, 103.999);
	glVertex2d(400, 72.56);
	glVertex2d(400, 0);
	glVertex2d(0, 0);
	glVertex2d(0, 169.25);

	glEnd();


	//right land
	glColor3d(0.82, 0.976, 0.157);
	glBegin(GL_POLYGON);
	glVertex2d(36.75, 0);
	glVertex2d(71.497, 21.195);
	glVertex2d(131.261, 41.726);
	glVertex2d(332.793, 83.202);
	glVertex2d(400, 100);
	glVertex2d(400, 0);
	glVertex2d(36.75, 0);
	glEnd();

	//poultry farm
	glColor3d(0.898, 0.353, 0.353);
	glBegin(GL_POLYGON);
	glVertex2d(8.269, 103.334);
	glVertex2d(1.091, 174.71);
	glVertex2d(0, 194.673);
	glVertex2d(15.781, 222.816);
	glVertex2d(62.424, 249.577);
	glVertex2d(105.18, 219.921);
	glVertex2d(133.252, 158.969);
	glVertex2d(114.083, 159.25);
	glVertex2d(101.87, 94.53);
	glVertex2d(8.269, 103.334);


	glEnd();

	glColor3d(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2d(35.04, 100);
	glVertex2d(36.75, 150.5);
	glVertex2d(72.75, 147.25);
	glVertex2d(68.86, 97.63);
	glVertex2d(35.04, 100);
	glEnd();


	circle(58.61, 203.72, 15, 1, 1, 1);



}



void egg(double x, double y)
{
	glColor3d(1, 0.745, 0.443);
	double i;
	double triangleAmount = 20;
	double twicePi = 2 * PI;
	double j = 0;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2d(x, y);
	for (i = 0; i <= triangleAmount;i++) {
		glVertex2d(
			x + (8 * cos(i *  twicePi / triangleAmount)),
			y + (14 * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
}


void egg_start()
{
{
		switch (p1)
		{
		case 0:  if (time > 100) { if (!col1) { egg(270 , oy1);oy1 -= 0.6; } } if (oy1 == 0 || col1) { oy1 = 550; col1 = false; }
				 if (time > 1000) { if (!col2) { egg(170 , oy2);oy2 -= 0.5; } } if (oy2 == 0 || col2) { oy2 = 550; col2 = false; }
				 if (time > 2000) { if (!col3) { egg(120 , oy3);oy3 -= 0.2; } } if (oy3 == 0 || col3) { oy3 = 550; col3 = false; }
				 if (time > 5000) { if (!col4) { egg(80, oy4);oy4 -= 0.5; } } if (oy4 == 0 || col4) { oy4 = 550; col4 = false; }
				 if (time > 5000) { if (!col4) { egg(80, oy4);oy4 -= 0.7; } } if (oy4 == 0 || col4) { oy4 = 550; col4 = false; }
				 break;
		case 1: break;
		}

		if ((basket_x <= 260) && (basket_x >= 200) && (oy1 < 40))
		{
			col1 = true;
			eggcaught++;

		}

		if ((basket_x <= 160) && (basket_x >= 100) && (oy2 < 40))
		{
			col2 = true;
			eggcaught++;


		}
		if ((basket_x <= 110) && (basket_x >= 50) && (oy3 < 40))
		{
			col3 = true;
			eggcaught++;


		}
		if ((basket_x <= 60) && (basket_x >= 0) && (oy4 < 40))
		{
			col4 = true;
			eggcaught++;

		}
		if (eggcaught == 5)
			game_over();
		glutPostRedisplay();
	}
}


void game() {
	day();
	basket(basket_x, basket_y);
	time += 1;
	egg_start();
}

void render(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	splash_screen();
	if (f == 13)
	{
		game();
	}
	if (f == 4)
	{
		exit(0);
	}


	glutSwapBuffers();
}
void keys(unsigned char key, int x, int y)
{
	if (f == 13 && key == '1')
	{
		f = 1;
	}
	else if (f == 13 && key == '2')
		f = 2;
	else if (f == 13 && key == '3')
		f = 3;
	else if (key == 13)  // Back Key ---------if key==13 (Enter Key word)
		f = 13;
	else if (key == 'q' || key == 'Q' || key == '4')//quit the game
		f = 4;
	else if (f == 0 && key == 13)
	{
		f = 13;
	}
	else if (f == 13 && key == 27) //esc back
	{
		f = 0;
	}
	glutPostRedisplay();
}

void specialkey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		if (basket_x>0)
			basket_x -= 10.0;

		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		if (basket_x<335)
			basket_x += 10.0;

		glutPostRedisplay();
		break;

	}
}





int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 600);
	glutInitWindowPosition(300, -10);
	glutCreateWindow("EggMania");
	gluOrtho2D(0.0, 400.0, 0.0, 600.0);
	glutDisplayFunc(render);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keys);
	glutSpecialFunc(specialkey);
	glutMainLoop();
	return 0;
}
