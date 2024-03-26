
#include <iostream>
int moveRobots(int *, int *, int, int );
int getNew(int, int);

int main()
{
  int x[4], y[4], i, j, myX = 25, myY = 25, move, status = 1;

  // initialize positions of four robots
  x[0] = 0; y[0] = 0;
  x[1] = 0; y[1] = 50;
  x[2] = 50; y[2] = 0;
  x[3] = 50; y[3] = 50;

  std::cout << "Your coordinates: 25 25\n";

  while (status == 1) {
      std::cout << "Enter move (1 for +x, -1 for -x, 2 for + y, -2 for -y):";
      std::cin >> move;

    // process user's move
    if (move == 1)
      myX++;
    else if (move == -1)
      myX--;
    else if (move == 2)
      myY++;
    else if (move == -2)
      myY--;

    // update robot positions
    status = moveRobots(&x[0],&y[0],myX,myY);

      std::cout << "Your coordinates: " << myX << " " << myY <<std:: endl;

    for (i=0;i<4;i++)
        std::cout << "Robot at " << x[i] << " " << y[i] << std::endl;

  }
    std::cout << "AAAARRRRGHHHHH... Game over\n";
}


int moveRobots(int *arg0, int *arg1, int arg2, int arg3)
{
  int i, *ptrX, *ptrY, alive = 1;

  ptrX = arg0;
  ptrY = arg1;

  for (i=0;i<4;i++) {
    *ptrX = getNew(*ptrX,arg2);  // update x-coordinate of robot i
    *ptrY = getNew(*ptrY,arg3);  // update y-coordinate of robot i

    // check if robot caught user
    if ((*ptrX == arg2) && (*ptrY == arg3)) {
      alive = 0;
      break;
    }
    ptrX++;
    ptrY++;
  }
  return alive;
}

// move coordinate of robot closer to coordinate of user
int getNew(int arg0, int arg1)
{
  int temp, result;

  temp = arg0 - arg1;
  if (temp >= 10)
    result = arg0 - 10;
  else if (temp > 0)
    result = arg0 - 1;
  else if (temp == 0)
    result = arg0;
  else if (temp > -10)
    result = arg0 + 1;
  else if (temp <= -10)
    result = arg0 + 10;

  return result;
}
