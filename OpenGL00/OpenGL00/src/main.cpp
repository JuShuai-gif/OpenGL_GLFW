#include <GLFW/glfw3.h>
GLdouble ScreenWidth = 1500;
GLdouble ScreenHeight = 800;

//�ı䴰�ڴ�С�Ļص�����
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void drawPoint()
{
    //���Ƶ�
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(15.0f);


    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);    // Red
    glVertex2f(10.0f, 10.0f);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0.0, 1.0, 0.0);    // Red
    glVertex2f(0.0f, 0.0f);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 1.0);    // Red
    glVertex2f(250.0f, 250.0f);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);    // Red
    glVertex2f(-250.0f, -250.0f);
    glEnd();

    /*
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);    // Red
    glVertex2f(1.0f, 1.0f);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);    // Red
    glVertex2f(0.0f, 0.0f);
    glEnd();
    */
}
void drawLine()
{
    //�������֮����ɫ
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //�����ɫ����
    glClear(GL_COLOR_BUFFER_BIT);


    glLineWidth(2);//�����߶ο��
    /*
    //��ʼ����
    glBegin(GL_LINES);
    //�����ߵ���ɫ
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, 250.0);
    glVertex2f(0.0, -250.0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-250.0, 0.0);
    glVertex2f(250.0, 0.0);
    
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-250.0, -750.0);
    glVertex2f(250.0, 750.0);
    glEnd();
    */

    glBegin(GL_LINES);
    //�����ߵ���ɫ
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-200.0, 200.0);
    glVertex2f(200.0, 200.0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(200.0, 200.0);
    glVertex2f(200.0, -200.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(200.0, -200.0);
    glVertex2f(-200.0, -200.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-200.0, -200.0);
    glVertex2f(-200.0, 200.0);
    glEnd();

}
int main(void)
{
    GLFWwindow* window;

    //��ʼ��
    if (!glfwInit())
        return -1;

    //����һ������
    window = glfwCreateWindow(ScreenWidth, ScreenHeight, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    //����������
    glfwMakeContextCurrent(window);
    glViewport(0, 0, ScreenWidth, ScreenHeight);
    //glOrtho(0, 500, 0, 500, -500, 500);
    /*
    * �������Ų���������
    * w��h�ǳ��Ϳ�
    if (w <= h)
        glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w, 1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-1.5 * (GLfloat)w / (GLfloat)h, 1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    */
    
    glOrtho(-ScreenWidth/2.0, ScreenWidth/2.0, -ScreenHeight/2.0, ScreenHeight/2.0, -500, 500);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //ѭ����Ⱦ
    while (!glfwWindowShouldClose(window))
    {
        //���ƹ���
        drawPoint();
        drawLine();

        //����֡����
        glfwSwapBuffers(window);

        //�˳��¼�
        glfwPollEvents();
    }
    //����
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}