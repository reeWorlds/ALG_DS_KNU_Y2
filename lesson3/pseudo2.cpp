#include <math.h>


void line(float, float, float, float){/*draw line*/}
float radians(float degrees) {return 0; /*TODO convert degrees to radians*/} 

float angleL = radians(30);
float angleR = radians(25);
float lengthRatio = 0.67;
int maxDepth = 5;

void drawBranch(float x1, float y1, float angle, float len, int depth)
{
  if (depth >= maxDepth || len < 1) return;

  float x2 = x1 + cos(angle) * len;
  float y2 = y1 + sin(angle) * len;

  line(x1, y1, x2, y2);

  drawBranch(x2, y2, angle - angleL, len * lengthRatio, depth + 1);
  drawBranch(x2, y2, angle + angleR, len * lengthRatio, depth + 1);
}


int main()
{
    drawBranch(0, 0, radians(90), 100, 0);

    return 0;
}