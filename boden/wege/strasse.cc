/*
 * Roads for Simutrans
 *
 * Revised January 2001
 * Hj. Malthaner
 */

#include <stdio.h>

#include "strasse.h"
#include "../../simworld.h"
#include "../../dataobj/loadsave.h"
#include "../../descriptor/way_desc.h"
#include "../../bauer/wegbauer.h"
#include "../../dataobj/translator.h"


const way_desc_t *strasse_t::default_strasse=NULL;

bool strasse_t::show_masked_ribi = false;


void strasse_t::set_gehweg(bool janein)
{
	weg_t::set_gehweg(janein);
	if(janein  &&  get_desc()  &&  get_desc()->get_topspeed()>50) {
		set_max_speed(50);
	}
}



strasse_t::strasse_t(loadsave_t *file) : weg_t()
{
	rdwr(file);
}


strasse_t::strasse_t() : weg_t()
{
	set_gehweg(false);
	set_desc(default_strasse);
	ribi_mask_oneway = ribi_t::none;
	overtaking_mode = twoway_mode;
}



void strasse_t::rdwr(loadsave_t *file)
{
	xml_tag_t s( file, "strasse_t" );

	weg_t::rdwr(file);

	if(file->get_version()<89000) {
		bool gehweg;
		file->rdwr_bool(gehweg);
		set_gehweg(gehweg);
	}

	if(file->is_saving()) {
		const char *s = get_desc()->get_name();
		file->rdwr_str(s);
	}
	else {
		char bname[128];
		file->rdwr_str(bname, lengthof(bname));

		const way_desc_t *desc = way_builder_t::get_desc(bname);
		int old_max_speed = get_max_speed();
		if(desc==NULL) {
			desc = way_builder_t::get_desc(translator::compatibility_name(bname));
			if(desc==NULL) {
				desc = default_strasse;
				welt->add_missing_paks( bname, karte_t::MISSING_WAY );
			}
			dbg->warning("strasse_t::rdwr()", "Unknown street %s replaced by %s (old_max_speed %i)", bname, desc->get_name(), old_max_speed );
		}
		set_desc(desc);
		if(old_max_speed>0) {
			set_max_speed(old_max_speed);
		}
		if(desc->get_topspeed()>50  &&  hat_gehweg()) {
			set_max_speed(50);
		}
	}
}

void strasse_t::rotate90() {
	weg_t::rotate90();
	ribi_mask_oneway = ribi_t::rotate90( ribi_mask_oneway );
}

void strasse_t::init_statistics() {
	weg_t::init_statistics();
	for(uint8 type=0; type<MAX_WAY_STATISTICS; type++) {
		for(uint8 month=0; month<MAX_WAY_STAT_MONTHS; month++) {
			for(uint8 dir=0; dir<MAX_WAY_STAT_DIRECTIONS; dir++) {
				directional_statistics[month][type][dir] = 0;
			}
		}
	}
}

void strasse_t::book(int amount, way_statistics type, ribi_t::ribi dir) {
	weg_t::book(amount, type);
	if(  (dir&(ribi_t::north))!=0  ||  (dir&(ribi_t::south))!=0  ) {
		// north-south traffic
		directional_statistics[0][type][0] += amount;
	} else {
		// east-west traffic
		directional_statistics[0][type][1] += amount;
	}
}

void strasse_t::new_month() {
	weg_t::new_month();
	for(uint8 type=0; type<MAX_WAY_STATISTICS; type++) {
		for(uint8 dir=0; dir<MAX_WAY_STAT_DIRECTIONS; dir++) {
			for(uint8 month=MAX_WAY_STAT_MONTHS-1; month>0; month--) {
				directional_statistics[month][type][dir] = directional_statistics[month-1][type][dir];
			}
			directional_statistics[0][type][dir] = 0;
		}
	}
}

ribi_t::ribi strasse_t::get_prior_direction() const {
	if(  directional_statistics[1][1][0]>directional_statistics[1][1][1]  ) {
		return ribi_t::northsouth;
	} else if(  directional_statistics[1][1][0]==directional_statistics[1][1][1]  ) {
		if(  directional_statistics[0][1][0]>directional_statistics[0][1][1]  ) {
			return ribi_t::northsouth;
		} else if(  directional_statistics[0][1][0]<directional_statistics[0][1][1]  ) {
			return ribi_t::eastwest;
		} else {
			return ribi_t::all;
		}
	} else {
		return ribi_t::eastwest;
	}
}
