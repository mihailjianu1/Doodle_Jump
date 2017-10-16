#include "Help.h"

namespace Help {
    void bound(float &x, int l, int r) {
        if(x < l)
            x = l;
        if(x > r)
            x = r;
    }
}
