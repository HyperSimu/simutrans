#ifndef boden_wege_strasse_h
#define boden_wege_strasse_h

#include "weg.h"

// number of different traffic directions
#define MAX_WAY_STAT_DIRECTIONS 2

/**
 * Cars are able to drive on roads.
 *
 * @author Hj. Malthaner
 */
class strasse_t : public weg_t
{
public:
	static bool show_masked_ribi;

private:
	/**
	* array for statistical values
	* store directional statistics to calculate prior_direction
	* direction: 0 = north-south, 1 = east-west
	*/
	sint16 directional_statistics[MAX_WAY_STAT_MONTHS][MAX_WAY_STATISTICS][MAX_WAY_STAT_DIRECTIONS];

	void init_statistics();

public:
	static const way_desc_t *default_strasse;

	strasse_t(loadsave_t *file);
	strasse_t();

	inline waytype_t get_waytype() const {return road_wt;}

	void set_gehweg(bool janein);

	virtual void rdwr(loadsave_t *file);

	virtual void rotate90();

	void book(int amount, way_statistics type, ribi_t::ribi dir);
	void new_month();
	ribi_t::ribi get_prior_direction() const;

	image_id get_front_image() const {return show_masked_ribi ? skinverwaltung_t::ribi_arrow->get_image_id(get_ribi()) : weg_t::get_front_image();}
};

#endif
