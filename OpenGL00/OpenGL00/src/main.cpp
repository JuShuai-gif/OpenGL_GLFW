#include <GLFW/glfw3.h>
GLdouble ScreenWidth = 1500;
GLdouble ScreenHeight = 800;

//改变窗口大小的回调函数
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void drawPoint()
{
    //绘制点
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
    //设置清除之后颜色
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //清除颜色缓存
    glClear(GL_COLOR_BUFFER_BIT);


    glLineWidth(2);//设置线段宽度
    /*
    //开始画线
    glBegin(GL_LINES);
    //设置线的颜色
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
    //设置线的颜色
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

    //初始化
    if (!glfwInit())
        return -1;

    //创建一个窗口
    window = glfwCreateWindow(ScreenWidth, ScreenHeight, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    //设置上下文
    glfwMakeContextCurrent(window);
    glViewport(0, 0, ScreenWidth, ScreenHeight);
    //glOrtho(0, 500, 0, 500, -500, 500);
    /*
    * 避免缩放产生的拉伸
    * w和h是长和宽
    if (w <= h)
        glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w, 1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-1.5 * (GLfloat)w / (GLfloat)h, 1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    */
    
    glOrtho(-ScreenWidth/2.0, ScreenWidth/2.0, -ScreenHeight/2.0, ScreenHeight/2.0, -500, 500);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //循环渲染
    while (!glfwWindowShouldClose(window))
    {
        //绘制过程
        drawPoint();
        drawLine();

        //交换帧缓冲
        glfwSwapBuffers(window);

        //退出事件
        glfwPollEvents();
    }
    //结束
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}