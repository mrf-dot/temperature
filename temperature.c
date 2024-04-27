#include "temperature.h"

int
main(int argc, char **argv)
{
    float ivals[MAX];
    char ounits[MAX];
    int nvals = 0;
    int nunits = 0;
    if (argc == 1) {
        fputs(HELP, stderr);
        return 1;
    }
    if (argc > MAX) {
        fputs("Too many arguments.\n", stderr);
        return 1;
    }
    int c;
    while ((c = getopt(argc, argv, "c:f:k:r:CFKRvh")) != -1)
        switch(c) {
            case 'c':
                ivals[nvals++] = strtof(optarg, NULL);
                break;
            case 'f':
                ivals[nvals++] = F2C(strtof(optarg, NULL));
                break;
            case 'k':
                ivals[nvals++] = K2C(strtof(optarg, NULL));
                break;
            case 'r':
                ivals[nvals++] = R2C(strtof(optarg, NULL));
                break;
            case 'C':
                ounits[nunits++] = 'c';
                break;
            case 'F':
                ounits[nunits++] = 'f';
                break;
            case 'K':
                ounits[nunits++] = 'k';
                break;
            case 'R':
                ounits[nunits++] = 'r';
                break;
            case 'h':
                fputs(HELP, stdout);
                break;
            case '?':
            default:
                return 1;
        }
    for (int i = optind; i < argc; i++) {
        fprintf(stderr, "non-option argument: %s\n", argv[i]);
    }
    if (nvals != nunits) {
        fputs("Input values are not equal to output units\n", stderr);
        return 1;
    }
    for (int i = 0; i < nunits; i++)
        switch (ounits[i]) {
            case 'c':
                printf("%.2f %c\n", ivals[i], 'C');
                break;
            case 'f':
                printf("%.2f %c\n", C2F(ivals[i]), 'F');
                break;
            case 'k':
                printf("%.2f %c\n", C2K(ivals[i]), 'K');
                break;
            case 'r':
                printf("%.2f %c\n", C2R(ivals[i]), 'R');
                break;
            default:
                fputs("Error in temperature unit conversion", stderr);
                return 1;
        }
    return 0;
}

