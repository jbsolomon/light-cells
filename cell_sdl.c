#include <string.h>

#include "cell_sdl.h"

LT_config LTC_sdl_defaults(LT_config c) {
    LT_config cfg;
    memset(&cfg, 0, sizeof(cfg));
    return cfg;
}
