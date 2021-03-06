#ifndef GET_CLIMATE_H
#define GET_CLIMATE_H

#include "../../simtypes.h"


/**
 * Convert climates string to bitfield
 * @author Hj. Malthaner
 */
climate_bits get_climate_bits(const char* climate_str);

#endif
