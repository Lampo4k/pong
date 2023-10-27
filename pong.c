#include <stdio.h>

int arena(int x, int y, int racket1y, int racket2y, int score_1, int score_2);
int game();

int main() { game(); }

int arena(int ball_x, int ball_y, int racket1y, int racket2y, int score_1, int score_2) {
    char up = '-';
    for (int height = 0; height < 25; height++) {
        for (int width = 0; width < 80; width++) {
            if (height == 0 || height == 24) {
                printf("%c", up);
            } else if ((width == 0) || (width == 79)) {
                printf("|");
            } else {
                if (height == ball_y && width == ball_x) {
                    printf("%c", 'o');
                } else if (width == 2 &&
                           ((racket1y == height) || (racket1y + 1 == height) || (racket1y - 1 == height))) {
                    printf("|");
                } else if (width == 77 &&
                           ((racket2y == height) || (racket2y + 1 == height) || (racket2y - 1 == height))) {
                    printf("|");
                } else if (width == 39 || width == 41) {
                    printf("|");
                } else if (height == 5 && width == 65) {
                    if (score_2 >= 10) {
                        printf("%d", score_2);
                    } else {
                        printf("0%d", score_2);
                    }
                } else if (height == 5 && width == 15) {
                    if (score_1 >= 10) {
                        printf("%d", score_1);
                    } else {
                        printf("0%d", score_1);
                    }
                } else {
                    if (height == 5 && (width == 16 || width == 66)) {
                    } else {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
int game() {
    char first_command;
    int ball_x = 40, ball_y = 12, ball_x_start = 40, ball_y_start = 12, side_x_ball = 1, side_y_ball = 1;
    int racket1y = 12, racket2y = 12, score_1 = 0, score_2 = 0, point = 1;
    while (1) {
        arena(ball_x, ball_y, racket1y, racket2y, score_1, score_2);
        scanf("%c", &first_command);
        if (first_command == 'a' || first_command == 'z' || first_command == 'k' || first_command == 'm' ||
            first_command == ' ') {
            if (ball_x <= 1 || ball_x >= 78) {
                ball_x = ball_x_start;
                ball_y = ball_y_start;
                side_x_ball = -side_x_ball;
            }
            ball_y = ball_y - side_y_ball;

            if (ball_y == 1 || ball_y == 23) {
                side_y_ball = -side_y_ball;
            }
            ball_x = ball_x + side_x_ball;
            if (ball_x <= 1) {
                score_2 = score_2 + point;
            }
            if (ball_x >= 78) {
                score_1 = score_1 + point;
            }

            if (getchar() == '\n')
                while (1) {
                    if (first_command == 'a' && racket1y != 2) {
                        racket1y = racket1y - 1;
                    }
                    if (first_command == 'z' && racket1y != 22) {
                        racket1y = racket1y + 1;
                    }
                    if (first_command == 'k' && racket2y != 2) {
                        racket2y = racket2y - 1;
                    }
                    if (first_command == 'm' && racket2y != 22) {
                        racket2y = racket2y + 1;
                    }
                    break;
                }
            if (ball_x == 76 && (ball_y == racket2y || ball_y == racket2y + 1 || ball_y == racket2y - 1)) {
                side_x_ball = -side_x_ball;
            } else if (ball_x == 3 &&
                       (ball_y == racket1y || ball_y == racket1y + 1 || ball_y == racket1y - 1)) {
                side_x_ball = -side_x_ball;
            }
        }
        if (score_1 == 21) {
            printf("Поздравляем игрока №1!");
            return 0;
        } else if (score_2 == 21) {
            printf("Поздровляем игрока №2!");
            return 0;
        }
    }
}