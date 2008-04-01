/*
 * New OO tool system
 *
 * This file is part of the Simutrans project under the artistic licence.
 */

#ifndef simwerkz2_h
#define simwerkz2_h

#include "simtypes.h"
#include "simwerkz.h"
#include "simskin.h"
#include "simsound.h"
#include "simworld.h"
#include "simmenu.h"

#include "besch/way_obj_besch.h"

#include "bauer/fabrikbauer.h"

#include "dataobj/umgebung.h"
#include "dataobj/translator.h"

/*
#include "gui/factory_edit.h"
#include "gui/curiosity_edit.h"
#include "gui/citybuilding_edit.h"
#include "gui/baum_edit.h"
*/
#include "gui/jump_frame.h"
#include "gui/optionen.h"
#include "gui/map_frame.h"
#include "gui/colors.h"
#include "gui/player_frame_t.h"
#include "gui/loadsave_frame.h"
#include "gui/money_frame.h"
#include "gui/schedule_list.h"
#include "gui/sound_frame.h"
#include "gui/sprachen.h"
#include "gui/kennfarbe.h"
#include "gui/help_frame.h"
#include "gui/message_frame_t.h"
#include "gui/messagebox.h"
#include "gui/convoi_frame.h"
#include "gui/halt_list_frame.h"
#include "gui/citylist_frame_t.h"
#include "gui/goods_frame_t.h"
#include "gui/factorylist_frame_t.h"
#include "gui/curiositylist_frame_t.h"

#include "tpl/slist_tpl.h"

class spieler_t;
class koord3d;
class koord;
class toolbar_t;
class werkzeug_waehler_t;

/****************************** helper functions: *****************************/

char *tooltip_with_price(const char * tip, sint64 price);

/************************ general tool *******************************/

// query tile info: default tool
class wkz_abfrage_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Abfrage"); }
	const char *work( karte_t *, spieler_t *, koord3d );
};


// remove uppermost object from tile
class wkz_remover_t : public werkzeug_t {
private:
	static bool wkz_remover_t::wkz_remover_intern(spieler_t *sp, karte_t *welt, koord pos, const char *&msg);
public:
	const char *get_tooltip(spieler_t *) { return translator::translate("Abriss"); }
	const char *work( karte_t *, spieler_t *, koord3d );
};

// alter land height tools
class wkz_raise_t : public werkzeug_t {
private:
	bool is_dragging;
	sint16 drag_height;
public:
	wkz_raise_t() : werkzeug_t() { offset = Z_GRID; }
	const char *get_tooltip(spieler_t *) { return tooltip_with_price("Anheben", umgebung_t::cst_alter_land); }
	bool init( karte_t *, spieler_t * ) { is_dragging = false; return true; }
	bool exit( karte_t *, spieler_t * ) { is_dragging = false; return true; }
	const char *work( karte_t *, spieler_t *, koord3d );
	const char *move( karte_t *, spieler_t *, uint16 /* buttonstate */, koord3d );
};

class wkz_lower_t : public werkzeug_t {
private:
	bool is_dragging;
	sint16 drag_height;
public:
	wkz_lower_t() : werkzeug_t() { offset = Z_GRID; }
	const char *get_tooltip(spieler_t *) { return tooltip_with_price("Absenken", umgebung_t::cst_alter_land); }
	bool init( karte_t *, spieler_t * ) { is_dragging = false; return true; }
	bool exit( karte_t *, spieler_t * ) { is_dragging = false; return true; }
	virtual const char *work( karte_t *, spieler_t *, koord3d);
	virtual const char *move( karte_t *, spieler_t *, uint16 /* buttonstate */, koord3d );
};

/* slope tool definitions */
class wkz_setslope_t : public werkzeug_t {
public:
	static const char *wkz_set_slope_work( karte_t *welt, spieler_t *sp, koord pos, int slope );
	const char *get_tooltip(spieler_t *) { return tooltip_with_price("Built artifical slopes", umgebung_t::cst_set_slope); }
	virtual const char *work( karte_t *welt, spieler_t *sp, koord3d k ) { return wkz_set_slope_work( welt, sp, k.gib_2d(), atoi(default_param) ); }
};

class wkz_restoreslope_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return tooltip_with_price("Restore natural slope", umgebung_t::cst_set_slope); }
	virtual const char *work( karte_t *welt, spieler_t *sp, koord3d k ) { return wkz_setslope_t::wkz_set_slope_work( welt, sp, k.gib_2d(), RESTORE_SLOPE ); }
};

class wkz_marker_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return tooltip_with_price("Marker", umgebung_t::cst_set_slope); }
	virtual const char *work( karte_t *welt, spieler_t *sp, koord3d k );
};

class wkz_clear_reservation_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Clear block reservation"); }
	bool init( karte_t *, spieler_t * );
	bool exit( karte_t *, spieler_t * );
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

class wkz_transformer_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *);
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

class wkz_add_city_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return tooltip_with_price( "Found new city", umgebung_t::cst_found_city ); }
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

/************** the following tools need a valid default_param ************************/

// step size by default_param
class wkz_change_city_size_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate( atoi(default_param)>=0 ? "Grow city" : "Shrink city" ); }
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

class wkz_plant_tree_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate( atoi(default_param)>=0 ? "Grow city" : "Shrink city" ); }
	virtual const char *move( karte_t *welt, spieler_t *sp, uint16 b, koord3d k ) { return b==1 ? work(welt,sp,k) : NULL; }
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

/* only called directly from schedule => no tooltip!
 * default_param must point to a schedule!
 */
class wkz_fahrplan_add_t : public werkzeug_t {
	virtual const char *work( karte_t *welt, spieler_t *sp, koord3d k );
};

class wkz_fahrplan_ins_t : public werkzeug_t {
	virtual const char *work( karte_t *welt, spieler_t *sp, koord3d k );
};

class wkz_wegebau_t : public werkzeug_t {
private:
	bool erster;
	koord3d start;
	zeiger_t *wkz_wegebau_bauer;
	static const weg_besch_t *defaults[17];
	const weg_besch_t *get_besch();
public:
	wkz_wegebau_t() : werkzeug_t() { wkz_wegebau_bauer=NULL; }
	const char *get_tooltip(spieler_t *);
	bool init( karte_t *, spieler_t * );
	bool exit( karte_t *w, spieler_t *s ) { return init(w,s); }
	const char *work( karte_t *, spieler_t *, koord3d );
//	virtual const char *move( karte_t *, spieler_t *, uint16 /* buttonstate */, koord3d );
};

class wkz_brueckenbau_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *);
	const char *work( karte_t *welt, spieler_t *sp, koord3d k );
};

class wkz_tunnelbau_t : public werkzeug_t {
private:
	koord3d start;
	zeiger_t *wkz_tunnelbau_bauer;
public:
	wkz_tunnelbau_t() : werkzeug_t() { wkz_tunnelbau_bauer=NULL; }
	const char *get_tooltip(spieler_t *);
	bool init( karte_t *, spieler_t * );
	bool exit( karte_t *w, spieler_t *s ) { return init(w,s); }
	const char *work( karte_t *welt, spieler_t *sp, koord3d k );
};

class wkz_wayremover_t : public werkzeug_t {
private:
	koord3d start;
	bool erster;
	zeiger_t *wkz_wayremover_bauer;
public:
	wkz_wayremover_t() : werkzeug_t() { wkz_wayremover_bauer=NULL; }
	const char *get_tooltip(spieler_t *);
	bool init( karte_t *, spieler_t * );
	bool exit( karte_t *w, spieler_t *s ) { return init(w,s); }
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

class wkz_wayobj_t : public werkzeug_t {
private:
	koord3d start;
	bool erster;
	zeiger_t *wkz_wayobj_bauer;
	static const way_obj_besch_t *default_electric;
public:
	wkz_wayobj_t() : werkzeug_t() { wkz_wayobj_bauer=NULL; }
	const char *get_tooltip(spieler_t *);
	bool init( karte_t *, spieler_t * );
	bool exit( karte_t *w, spieler_t *s ) { return init(w,s); }
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

class wkz_station_t : public werkzeug_t {
private:
	static char toolstring[256];
	const char *wkz_station_building_aux( karte_t *, spieler_t *, koord3d, const haus_besch_t * );
	const char *wkz_station_dock_aux( karte_t *, spieler_t *, koord3d, const haus_besch_t * );
	const char *wkz_station_aux( karte_t *, spieler_t *, koord3d, const haus_besch_t *, waytype_t, sint64 cost, const char *halt_suffix );
public:
	const char *get_tooltip(spieler_t *);
	bool init( karte_t *, spieler_t * );
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

class wkz_roadsign_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *);
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

class wkz_depot_t : public werkzeug_t {
private:
	static char toolstring[256];
	const char *wkz_depot_aux(karte_t *welt, spieler_t *sp, koord pos, const haus_besch_t *besch, waytype_t wegtype, sint64 cost);
public:
	const char *get_tooltip(spieler_t *);
	bool init( karte_t *, spieler_t * );
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

/* builds (random) tourist attraction (deafult_param==NULL) and maybe adds it to the next city
 * the parameter string is a follow (or NULL):
 * 1#theater
 * first letter: ignore climates
 * second letter: rotation (0,1,2,3,#=random)
 * finally building name
 * @author prissi
 */
class wkz_build_haus_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Built random attraction"); }
	bool init( karte_t *, spieler_t * );
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

/* builts a (if param=NULL random) industry chain starting here *
 * the parameter string is a follow (or NULL):
 * 1#34,oelfeld
 * first letter: ignore climates
 * second letter: rotation (0,1,2,3,#=random)
 * next number is production value
 * finally industry name
 * NULL means random chain!
 */
class wkz_build_industries_land_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Build land consumer"); }
	bool init( karte_t *, spieler_t * );
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

class wkz_build_industries_city_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Build city market"); }
	bool init( karte_t *, spieler_t * );
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

class wkz_build_factory_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Build city market"); }
	bool init( karte_t *, spieler_t * );
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

class wkz_link_factory_t : public werkzeug_t {
private:
	fabrik_t* last_fab;
	zeiger_t *wkz_linkzeiger;
public:
	const char *get_tooltip(spieler_t *) { return translator::translate("Connect factory"); }
	bool init( karte_t *, spieler_t * );
	bool exit( karte_t *w, spieler_t *s ) { return init(w,s); }
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

class wkz_headquarter_t : public werkzeug_t {
private:
	const haus_besch_t *next_level( spieler_t *sp );
public:
	const char *get_tooltip(spieler_t *);
	bool init( karte_t *, spieler_t * );
	virtual const char *work( karte_t *, spieler_t *, koord3d );
};

/* protects map from further change (here because two clicks to confirm it!) */
class wkz_lock_game_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Lock game"); }
	bool init( karte_t *welt, spieler_t * ) { return welt->gib_einstellungen()->gib_allow_player_change(); }
	const char *work( karte_t *welt, spieler_t *sp, koord3d ) {
		welt->gib_einstellungen()->setze_allow_player_change( false );
		destroy_all_win();
		welt->switch_active_player( 0 );
		welt->set_werkzeug( general_tool[WKZ_ABFRAGE] );
		return NULL;
	}
};

/********************* one click tools ****************************/

class wkz_pause_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Pause"); }
	bool init( karte_t *welt, spieler_t * ) {
//		welt->set_pause( welt->is_paused()^1 );
//		welt->do_pause();
		return false;
	}
};

class wkz_fastforward_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Fast forward"); }
	bool init( karte_t *welt, spieler_t * ) {
		welt->set_fast_forward( welt->is_fast_forward()^1 );
		return false;
	}
};

class wkz_screenshot_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Screenshot"); }
	bool init( karte_t *welt, spieler_t * ) {
		display_snapshot();
		create_win( new news_img("Screenshot\ngespeichert.\n"), w_time_delete, magic_none);
		return false;
	}
};

// builts next chain
class wkz_increase_industry_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Increase Industry density"); }
	bool init( karte_t *welt, spieler_t * ) {
		fabrikbauer_t::increase_industry_density( welt, false );
		return false;
	}
};

/* prissi: undo building */
class wkz_undo_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Undo last ways construction"); }
	bool init( karte_t *welt, spieler_t *sp ) {
		if(!sp->undo()) {
			create_win( new news_img("UNDO failed!"), w_time_delete, magic_none);
		}
		return false;
	}
};

/* switch to next player
 * @author prissi
 */
class wkz_switch_player_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Change player"); }
	bool init( karte_t *welt, spieler_t *sp ) {
		welt->switch_active_player( welt->get_active_player_nr()+1 );
		return false;
	}
};

// setp one year forward
class wkz_step_year_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Step timeline one year"); }
	bool init( karte_t *welt, spieler_t *sp ) {
		welt->step_year();
		return false;
	}
};

class wkz_change_game_speed_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Accelerate/Deccelerate time"); }
	bool init( karte_t *welt, spieler_t * ) {
		welt->change_time_multiplier( atoi(default_param) );
		return false;
	}
};

class wkz_zoom_in_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("zooming in"); }
	bool init( karte_t *welt, spieler_t * ) {
		win_change_zoom_factor(true);
		welt->setze_dirty();
		return false;
	}
};

class wkz_zoom_out_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("zooming out"); }
	bool init( karte_t *welt, spieler_t * ) {
		win_change_zoom_factor(false);
		welt->setze_dirty();
		return false;
	}
};

class wkz_show_coverage_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("show station coverage"); }
	bool init( karte_t *welt, spieler_t * ) {
		umgebung_t::station_coverage_show = !umgebung_t::station_coverage_show;
		welt->setze_dirty();
		return false;
	}
};

class wkz_show_name_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) {
		return translator::translate(
			umgebung_t::show_names==3 ? "hide station names" :
			(umgebung_t::show_names&1) ? "show station names" : "show waiting bars");
	}
	bool init( karte_t *welt, spieler_t * ) {
		umgebung_t::show_names = (umgebung_t::show_names+1) & 3;
		welt->setze_dirty();
		return false;
	}
};

class wkz_show_grid_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("show grid"); }
	bool init( karte_t *welt, spieler_t * ) {
		grund_t::toggle_grid();
		welt->setze_dirty();
		return false;
	}
};

class wkz_show_trees_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("hide trees"); }
	bool init( karte_t *welt, spieler_t * ) {
		umgebung_t::hide_trees = !umgebung_t::hide_trees;
		welt->setze_dirty();
		return false;
	}
};

class wkz_show_houses_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) {
		return translator::translate(
			umgebung_t::hide_buildings==0 ? "hide city building" :
			(umgebung_t::hide_buildings==1) ? "hide all building" : "show all building");
	}
	bool init( karte_t *welt, spieler_t * ) {
		umgebung_t::hide_buildings ++;
		if(umgebung_t::hide_buildings>umgebung_t::ALL_HIDDEN_BUIDLING) {
			umgebung_t::hide_buildings = umgebung_t::NOT_HIDE;
		}
		welt->setze_dirty();
		return false;
	}
};

class wkz_show_underground_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("underground mode"); }
	bool init( karte_t *welt, spieler_t * ) {
		grund_t::toggle_underground_mode();
		// renew toolbar
		for (vector_tpl<toolbar_t *>::const_iterator i = werkzeug_t::toolbar_tool.begin(), end = werkzeug_t::toolbar_tool.end();  i != end;  ++i  ) {
			(*i)->update(welt, welt->get_active_player());
		}
		welt->setze_dirty();
		return false;
	}
};

class wkz_rotate90_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Rotate map"); }
	bool init( karte_t *welt, spieler_t * ) {
		welt->rotate90();
		welt->update_map();
		return false;
	}
};

class wkz_quit_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Beenden"); }
	bool init( karte_t *welt, spieler_t * ) {
		destroy_all_win();
		welt->beenden( true );
		return false;
	}
};

/********************** dialoge tools *****************************/

// general help
class wkz_help_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Help"); }
	bool init( karte_t *, spieler_t * ) {
		create_win(new help_frame_t("general.txt"), w_info, magic_mainhelp);
		return false;
	}
};

// open info/quit dialoge
class wkz_optionen_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Einstellungsfenster"); }
	bool init( karte_t *welt, spieler_t * ) {
		create_win(240, 120, new optionen_gui_t(welt), w_info, magic_optionen_gui_t);
		return false;
	}
};

// open minimap
class wkz_minimap_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Reliefkarte"); }
	bool init( karte_t *welt, spieler_t * ) {
		create_win( new map_frame_t(welt), w_info, magic_reliefmap);
		return false;
	}
};

// open line management
class wkz_lines_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Line Management"); }
	bool init( karte_t *, spieler_t *sp ) {
		sp->simlinemgmt.zeige_info( sp );
		return false;
	}
};

// open massages
class wkz_messages_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Mailbox"); }
	bool init( karte_t *welt, spieler_t * ) {
		create_win( new message_frame_t(welt), w_info, magic_messageframe );
		return false;
	}
};

// open messages
class wkz_finances_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Finanzen"); }
	bool init( karte_t *, spieler_t *sp ) {
		sp->zeige_info();
		return false;
	}
};

// open player dialoge
class wkz_players_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Spielerliste"); }
	bool init( karte_t *welt, spieler_t * ) {
		create_win( 272, 160, new ki_kontroll_t(welt), w_info, magic_ki_kontroll_t);
		return false;
	}
};

// open player dialoge
class wkz_displayoptions_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Helligk."); }
	bool init( karte_t *welt, spieler_t * ) {
		create_win(new color_gui_t(welt), w_info, magic_color_gui_t);
		return false;
	}
};

// open sound dialoge
class wkz_sound_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Sound"); }
	bool init( karte_t *, spieler_t * ) {
		create_win(new sound_frame_t(), w_info, magic_sound_kontroll_t);
		return false;
	}
};

// open language dialoge
class wkz_language_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Sprache"); }
	bool init( karte_t *, spieler_t * ) {
		create_win(new sprachengui_t(), w_info, magic_sprachengui_t);
		return false;
	}
};

// open player color dialoge
class wkz_playercolor_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Farbe"); }
	bool init( karte_t *, spieler_t *sp ) {
		create_win(new farbengui_t(sp), w_info, magic_farbengui_t);
		return false;
	}
};

// jump to position dialoge
class wkz_jump_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Jump to"); }
	bool init( karte_t *welt, spieler_t *sp ) {
		create_win( new jump_frame_t(welt), w_info, magic_jump);
		return false;
	}
};

// load game dialoge
class wkz_load_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Laden"); }
	bool init( karte_t *welt, spieler_t * ) {
		destroy_all_win();
		create_win(new loadsave_frame_t(welt, true), w_info, magic_load_t);
		return false;
	}
};

// save game dialoge
class wkz_save_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("Speichern"); }
	bool init( karte_t *welt, spieler_t * ) {
		create_win(new loadsave_frame_t(welt, false), w_info, magic_save_t);
		return false;
	}
};

/* open the list of halt */
class wkz_list_halt_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("hl_title"); }
	bool init( karte_t *, spieler_t *sp ) {
		create_win( new halt_list_frame_t(sp), w_info, magic_halt_list_t );
		return false;
	}
};

/* open the list of vehicle */
class wkz_list_convoi_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("cl_title"); }
	bool init( karte_t *, spieler_t *sp ) {
		create_win( new convoi_frame_t(sp), w_info, magic_convoi_t );
		return false;
	}
};

/* open the list of towns */
class wkz_list_town_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("tl_title"); }
	bool init( karte_t *welt, spieler_t * ) {
		create_win( new citylist_frame_t(welt), w_info, magic_citylist_frame_t );
		return false;
	}
};

/* open the list of goods */
class wkz_list_goods_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("gl_title"); }
	bool init( karte_t *welt, spieler_t * ) {
		create_win( new goods_frame_t(welt), w_info, magic_goodslist );
		return false;
	}
};

/* open the list of factories */
class wkz_list_factory_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("fl_title"); }
	bool init( karte_t *welt, spieler_t * ) {
		create_win( new factorylist_frame_t(welt), w_info, magic_factorylist );
		return false;
	}
};

/* open the list of attraction */
class wkz_list_curiosity_t : public werkzeug_t {
	const char *get_tooltip(spieler_t *) { return translator::translate("curlist_title"); }
	bool init( karte_t *welt, spieler_t * ) {
		create_win( new curiositylist_frame_t(welt), w_info, magic_curiositylist );
		return false;
	}
};


#endif
