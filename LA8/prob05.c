// Very very Important
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

struct queue{
	int x;
	int y;
	int monster;
	struct queue* next;
};

struct queue* head;
struct queue* tail;

void push(int x, int y, int monster){
	struct queue* temp = (struct queue*)malloc(sizeof(struct queue*));
	temp->x = x;
	temp->y = y;
	temp->monster = monster;
	temp->next = NULL;
	tail->next = temp;
	tail = temp;
	if (head == NULL) {
		head = tail;
	}
}

int bfs(int r, int c, int R, int C, char maze[R][C], int d[R][C][3]){
	if (r==R-1 || r==0 || c==0 || c==C-1) {
		return 0;
	}
	int i,rr,cc,state,newState;
	head = (struct queue*)malloc(sizeof(struct queue*));
	head->x = r;
	head->y = c;
	head->monster = 0;
	head->next = NULL;
	tail = head;
	d[r][c][0] = 0;
	while (head!=NULL) {
		r = head->x;
		c = head->y;
		state = head->monster;
		head = head->next;

		for (size_t i = 0; i < 4; i++) {
			rr = r + dr[i];
			cc = c + dc[i];
			if ((0<=rr && rr<=R-1)&&(0<=cc && cc<=C-1) && maze[rr][cc] != 'W') {
				if (state != 1 && maze[rr][cc] == 'M') {
					continue;
				}
				if (rr == 0 ||rr == R-1 || cc == 0 || cc == C-1) {
					return d[r][c][state] + 1;
				}
				if (maze[rr][cc] == 'D') {
					newState = 1;
				}
				else if (maze[rr][cc] == 'A') {
					newState = 2;
				}
				else{
					newState = state;
				}
				if (d[rr][cc][newState] > d[r][c][state] + 1) {
					push(rr,cc,newState);
					d[rr][cc][newState] = d[r][c][state] + 1;
				}
			}
		}
	}
	return -2;
}

int main(int argc, char const *argv[])
{
    int rows, cols;
    scanf("%d %d", &rows, &cols);
	char maze[rows][cols];
	for (int i = 0; i < rows; ++i)
	{
        scanf("%s", maze[i]);
	}
	int x,y;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
			if (maze[i][j] == 'H') {
				x = i;
				y = j;
			}
        }
    }
	int distance[rows][cols][3];
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			for (size_t k = 0; k < 3; k++) {
				distance[i][j][k] = INT_MAX;
			}
		}
	}
	int steps = bfs(x,y,rows,cols,maze,distance) + 1;
	printf("%d\n", steps);
	return 0;
}
