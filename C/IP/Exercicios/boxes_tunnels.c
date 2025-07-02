// Explicacao do exercicio: https://www.hackerrank.com/contests/monitoria-ip/challenges/too-high-boxes/problem

struct box
{
    int length;
    int height;
    int width;
};

typedef struct box box;

int get_volume(box b) {
    return (b.length)*(b.height)*(b.width);
}

int is_lower_than_max_height(box b) {
    if (b.height >= 41)
        return 0;
    return 1;
}