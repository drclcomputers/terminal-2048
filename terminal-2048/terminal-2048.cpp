#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>

#ifdef _WIN32
#define CLEARSCREEN "cls"
#else
#define CLEARSCREEN "clear"
#endif

using namespace std;

long long V[4][4];

bool board_full() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (!V[i][j]) return 0;
    return 1;
}

bool valid() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (V[i][j] == 0) return 1;
            if (i < 4 - 1 && V[i][j] == V[i + 1][j]) return 1;
            if (j < 4 - 1 && V[i][j] == V[i][j + 1]) return 1;
        }
    }
    return 0;
}

void get_random(int& i, int& j) {
    if (!board_full())
        do {
            i = rand() % 4;
            j = rand() % 4;
        } while (V[i][j] != 0);
}

int get_random_value() {
    int x = rand() % 5;
    if (x == 0) return 1;
    else if (x == 1) return 1;
    else if (x == 2) return 2;
    else if (x == 3) return 4;
    else if (x == 4) return 4;
    return 1;
}

void play();
void render();

int main() {
    play();
    return 0;
}

void play() {
    system(CLEARSCREEN);
    srand(time(NULL));
    bool quit = 0, key_pressed = 0, okaux;
    int i, j;

    get_random(i, j);
    V[i][j] = get_random_value();

    get_random(i, j);
    V[i][j] = get_random_value();

    int option=0;

    while (!quit) {
        system(CLEARSCREEN);
        render();
        option = 0;
        if (!valid() && board_full()) {
            while (option<0 || option>1) {
                cout << "\nEnter '0' to quit or '1' to restart: ";
                cin >> option;
                if (option == 0) quit = 1;
                else if (option == 1) {
                    for (int i = 0; i < 4; i++)
                        for (int j = 0; j < 4; j++)
                            V[i][j] = 0;
                    get_random(i, j);
                    V[i][j] = get_random_value();

                    get_random(i, j);
                    V[i][j] = get_random_value();
                }
            }
        }
        else {
            cout << "\n0-quit\n1-up\n2-right\n3-down\n4-left\n5-restart\nOption: ";
            cin >> option;
            switch (option) {
            case 0:
                quit = 1;
                break;
            case 1:
                for (int h = 0; h < 4; h++) {
                    int temp[4], l = 0;
                    temp[0] = temp[1] = temp[2] = temp[3] = 0;

                    for (int k = 0; k < 4; k++)
                        if (V[k][h] != 0)
                            temp[l++] = V[k][h];

                    for (int k = 0; k < 3; k++)
                        if (temp[k] == temp[k + 1] && temp[k] != 0) {
                            temp[k] *= 2;
                            temp[k + 1] = 0;
                        }

                    l = 0;

                    for (int k = 0; k < 4; k++)
                        if (temp[k] != 0)
                            V[l++][h] = temp[k];

                    while (l < 4)
                        V[l++][h] = 0;
                }
                break;
            case 3:
                for (int h = 0; h < 4; h++) {
                    okaux = 0;
                    for (int h = 0; h < 4; h++) {
                        for (int k = 0; k < 4; k++) {
                            if (h < 4 - 1 && V[h][k] == V[h + 1][k]) okaux = 1;
                        }
                    }
                    if (okaux) {
                        int temp[4] = { 0 }, l = 0;
                        for (int k = 3; k >= 0; k--)
                            if (V[k][h] != 0)
                                temp[l++] = V[k][h];
                        for (int k = 0; k < 3; k++)
                            if (temp[k] == temp[k + 1] && temp[k] != 0) {
                                temp[k] *= 2;
                                temp[k + 1] = 0;
                            }
                        l = 0;
                        for (int k = 0; k <= 3; k++)
                            if (temp[k] != 0)
                                V[3 - (l++)][h] = temp[k];
                        while (l < 4)
                            V[3 - (l++)][h] = 0;
                    }
                }
                break;
            case 4:
                for (int h = 0; h < 4; h++) {
                    int temp[4], l = 0;
                    temp[0] = temp[1] = temp[2] = temp[3] = 0;

                    for (int k = 0; k < 4; k++)
                        if (V[h][k] != 0)
                            temp[l++] = V[h][k];

                    for (int k = 0; k < 3; k++)
                        if (temp[k] == temp[k + 1] && temp[k] != 0) {
                            temp[k] *= 2;
                            temp[k + 1] = 0;
                        }

                    l = 0;
                    for (int k = 0; k < 4; k++)
                        if (temp[k] != 0)
                            V[h][l++] = temp[k];

                    while (l < 4)
                        V[h][l++] = 0;
                }
                break;
            case 2:
                for (int h = 0; h < 4; h++) {
                    /*okaux = 0;
                    for (int h = 0; h < 4; h++) {
                        for (int k = 0; k < 4; k++) {
                            if (k < 4 - 1 && V[h][k] == V[h][k + 1]) okaux = 1;
                        }
                    }
                    if (okaux) {*/
                    int temp[4], l = 0;
                    temp[0] = temp[1] = temp[2] = temp[3] = 0;

                    for (int k = 3; k >= 0; k--)
                        if (V[h][k] != 0)
                            temp[l++] = V[h][k];

                    for (int k = 0; k < 3; k++)
                        if (temp[k] == temp[k + 1] && temp[k] != 0) {
                            temp[k] *= 2;
                            temp[k + 1] = 0;
                        }

                    //l = 0;
                    //for (int k = 3; k >= 0; k--)
                    //    if (temp[k] != 0)
                    //        V[h][3 - (l++)] = temp[k];

                    l = 0;
                    for (int k = 0; k < 4; k++)
                        if (temp[k] != 0)
                            V[h][3 - (l++)] = temp[k];

                    while (l < 4)
                        V[h][3 - (l++)] = 0;
                    //}
                }
                break;
            case 5:
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        V[i][j] = 0;
                get_random(i, j);
                V[i][j] = get_random_value();
            default:
                while (option < 0 || option>5) {
                    cout << "Incorrect! Enter option: ";
                    cin >> option;
                }
                switch (option) {
                case 0:
                    quit = 1;
                    break;
                case 1:
                    for (int h = 0; h < 4; h++) {
                        int temp[4], l = 0;
                        temp[0] = temp[1] = temp[2] = temp[3] = 0;

                        for (int k = 0; k < 4; k++)
                            if (V[k][h] != 0)
                                temp[l++] = V[k][h];

                        for (int k = 0; k < 3; k++)
                            if (temp[k] == temp[k + 1] && temp[k] != 0) {
                                temp[k] *= 2;
                                temp[k + 1] = 0;
                            }

                        l = 0;

                        for (int k = 0; k < 4; k++)
                            if (temp[k] != 0)
                                V[l++][h] = temp[k];

                        while (l < 4)
                            V[l++][h] = 0;
                    }
                    break;
                case 3:
                    for (int h = 0; h < 4; h++) {
                        okaux = 0;
                        for (int h = 0; h < 4; h++) {
                            for (int k = 0; k < 4; k++) {
                                if (h < 4 - 1 && V[h][k] == V[h + 1][k]) okaux = 1;
                            }
                        }
                        if (okaux) {
                            int temp[4] = { 0 }, l = 0;
                            for (int k = 3; k >= 0; k--)
                                if (V[k][h] != 0)
                                    temp[l++] = V[k][h];
                            for (int k = 0; k < 3; k++)
                                if (temp[k] == temp[k + 1] && temp[k] != 0) {
                                    temp[k] *= 2;
                                    temp[k + 1] = 0;
                                }
                            l = 0;
                            for (int k = 0; k <= 3; k++)
                                if (temp[k] != 0)
                                    V[3 - (l++)][h] = temp[k];
                            while (l < 4)
                                V[3 - (l++)][h] = 0;
                        }
                    }
                    break;
                case 4:
                    for (int h = 0; h < 4; h++) {
                        int temp[4], l = 0;
                        temp[0] = temp[1] = temp[2] = temp[3] = 0;

                        for (int k = 0; k < 4; k++)
                            if (V[h][k] != 0)
                                temp[l++] = V[h][k];

                        for (int k = 0; k < 3; k++)
                            if (temp[k] == temp[k + 1] && temp[k] != 0) {
                                temp[k] *= 2;
                                temp[k + 1] = 0;
                            }

                        l = 0;
                        for (int k = 0; k < 4; k++)
                            if (temp[k] != 0)
                                V[h][l++] = temp[k];

                        while (l < 4)
                            V[h][l++] = 0;
                    }
                    break;
                case 2:
                    for (int h = 0; h < 4; h++) {
                        /*okaux = 0;
                        for (int h = 0; h < 4; h++) {
                            for (int k = 0; k < 4; k++) {
                                if (k < 4 - 1 && V[h][k] == V[h][k + 1]) okaux = 1;
                            }
                        }
                        if (okaux) {*/
                        int temp[4], l = 0;
                        temp[0] = temp[1] = temp[2] = temp[3] = 0;

                        for (int k = 3; k >= 0; k--)
                            if (V[h][k] != 0)
                                temp[l++] = V[h][k];

                        for (int k = 0; k < 3; k++)
                            if (temp[k] == temp[k + 1] && temp[k] != 0) {
                                temp[k] *= 2;
                                temp[k + 1] = 0;
                            }

                        //l = 0;
                        //for (int k = 3; k >= 0; k--)
                        //    if (temp[k] != 0)
                        //        V[h][3 - (l++)] = temp[k];

                        l = 0;
                        for (int k = 0; k < 4; k++)
                            if (temp[k] != 0)
                                V[h][3 - (l++)] = temp[k];

                        while (l < 4)
                            V[h][3 - (l++)] = 0;
                        //}
                    }
                    break;
                }
                break;
            }
            if (!board_full()) {
                get_random(i, j);
                V[i][j] = get_random_value();
            }
        }
    }
}

void render() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << V[i][j] << ' ';
        cout << '\n';
    }
}