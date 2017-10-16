#include "Help.h"

void bound(dloat &x, int l, int r) {
    if(x < l)
        x = l;
    if(x > r)
        x = r;
}
