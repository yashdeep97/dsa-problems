// Very very Important
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	int right;
	int down;
	int left;
	int up;
	int visited;
};

int main(int argc, char const *argv[])
{
	struct node maze[10][10];
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			scanf("%d",&(maze[i][j].data));
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (j == 9 || maze[i][j+1].data == 0)
			{
				maze[i][j].right = 0;
			}
			else{
				maze[i][j].right = 1;
			}

			if (i == 9 || maze[i+1][j].data == 0)
			{
				maze[i][j].down = 0;
			}
			else{
				maze[i][j].down = 1;
			}

			if (j == 0 || maze[i][j-1].data == 0)
			{
				maze[i][j].left = 0;
			}
			else{
				maze[i][j].left = 1;
			}

			if (i == 0 || maze[i-1][j].data == 0)
			{
				maze[i][j].up = 0;
			}
			else{
				maze[i][j].up = 1;
			}

			maze[i][j].visited = 0;
		}
	}
	int currentX = 0, currentY = 0;
	maze[currentX][currentY].visited = 1;
	int stack[100][2];
	int tos = 0;
	while(currentX != 9 || currentY != 9){		
		stack[tos][0] = currentX;
		stack[tos][1] = currentY;
		if (maze[currentX][currentY].right == 1 && maze[currentX][currentY+1].visited == 0){
			tos++;
			currentY++;
			maze[currentX][currentY].visited = 1;
		}
		else if(maze[currentX][currentY].down == 1 && maze[currentX+1][currentY].visited == 0){
			tos++;
			currentX++;
			maze[currentX][currentY].visited = 1;
		}
		else if(maze[currentX][currentY].left == 1 && maze[currentX][currentY-1].visited == 0){
			tos++;
			currentY--;
			maze[currentX][currentY].visited = 1;
		}
		else if(maze[currentX][currentY].up == 1 && maze[currentX-1][currentY].visited == 0){
			tos++;
			currentX--;
			maze[currentX][currentY].visited = 1;
		}
		else{
			if (tos == 0)
			{
				printf("Path is not possible\n");
				return 0;
			}
			tos--;
			currentX = stack[tos][0];
			currentY = stack[tos][1];
		}
	}
	for (int i = 0; i <= tos; ++i)
	{
		printf("(%d, %d)\n", stack[i][0],stack[i][1]);
	}
	printf("\n");
	return 0;
}