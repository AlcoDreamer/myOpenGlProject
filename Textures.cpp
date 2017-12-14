
#include <Windows.h>
#include <GL/glut.h>
#include <gl\gl.h>		// Заголовочный файл для OpenGL32 библиотеки
#include <gl\glu.h>		// Заголовочный файл для GLu32 библиотеки
#include <gl\GLAUX.h>		// Заголовочный файл для GLaux библиотеки



GLuint	texture[1];		// Место для одной текстуры
GLfloat rtri;           // Угол для треугольник

GLvoid LoadGLTextures()
{
	// Загрузка картинки
	AUX_RGBImageRec *tex;
	tex = auxDIBImageLoad("1.bmp");
	// Создание текстуры
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, tex->sizeX, tex->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, tex->data);
}


void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	glClearDepth(1.0f);              // Разрешить очистку буфера глубины
	glEnable(GL_DEPTH_TEST);            // Разрешить тест глубины
	glDepthFunc(GL_LEQUAL);            // Тип теста глубины
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);      // Улучшение в вычислении перспективы
	LoadGLTextures();			// Загрузка текстур
	glEnable(GL_TEXTURE_2D);		// Разрешение наложение текстуры

	glTranslatef(0.0f, 0.0f, -6.0f);

	glRotatef(9, 1.0f, 0.0f, 0.0f);		// Вращение по оси X
	glRotatef(-14, 0.0f, 1.0f, 0.0f);		// Вращение по оси Y
	glRotatef(-7, 0.0f, 0.0f, 1.0f);		// Вращение по оси Z
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	glBegin(GL_QUADS);
	// Передняя грань
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Низ лево
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// Низ право
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// Верх право
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Верх лево

																// Задняя грань
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Низ право
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// Верх право
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// Верх лево
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// Низ лево

																// Верхняя грань
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// Верх лево
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Низ лево
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// Низ право
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// Верх право

																// Нижняя грань
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Верх право
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// Верх лево
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// Низ лево
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Низ право

																// Правая грань
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// Низ право
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// Верх право
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// Верх лево
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// Низ лево

																// Левая грань
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Низ лево
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Низ право
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Верх право
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// Верх лево

	glEnd();
	glutSwapBuffers();

	          // Прорисовка прошла успешно
}


void changeSize(int w, int h)
{
	if (h == 0)
		h = 1;
	float ratio = w*1.0 / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);
	gluPerspective(42, ratio, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1024, 1024);
	glutInitWindowPosition(42, 42);
	glutCreateWindow("one");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	glutMainLoop();

	return 0;

}
