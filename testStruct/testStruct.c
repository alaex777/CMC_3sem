#include <math.h>
#include <stdio.h>

struct Point{
	double x;
	double y;
	double z;
};

double distance(struct Point p1, struct Point p2){
	return sqrt((p2.x - p1.x) * (p2.x - p1.x) + 
		(p2.y - p1.y) * (p2.y - p1.y) + (p2.z - p1.z) * (p2.z - p1.z));
}

void strcpy(char* dst, const char* src){
	while(src[0] != '\0'){
		dst[0] = src[0];
		dst++;
		src++;
	}
	dst[0] = '\0';
}

int main(){
	struct Point p1;
	p1.x = 1.0;
	p1.y = 2.0;
	p1.z = 3.0;
	struct Point p2 = {1.0, 2.0, 3.0};
	printf("%f\n", distance(p1, p2));
	return 0;
}