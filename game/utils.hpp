#ifndef UTILS_H
#define UTILS_H

static int roundToMultiple(int num, int multiple)
{
    if (multiple == 0)
        return num;
    int r = num % multiple;
    if (r == 0)
        return num;
    return num + multiple - r;
}

#endif
