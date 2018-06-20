#ifndef GET_WAYTYPE_H
#define GET_WAYTYPE_H

#include "../../simtypes.h"


/**
 * Convert waytype string to enum waytype_t
 * @author Hj. Malthaner
 */
waytype_t get_waytype(char const* waytype);

overtaking_mode_t get_overtaking_mode(char const* o_mode);

#endif
