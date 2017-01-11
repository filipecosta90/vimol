#ifndef VIMOL_VIMOL_H
#define VIMOL_VIMOL_H

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <SDL.h>
#include <cairo.h>

#define strcasecmp SDL_strcasecmp
#define strncasecmp SDL_strncasecmp
#define snprintf SDL_snprintf
#define vsnprintf SDL_vsnprintf

#ifndef __unused
#define __unused
#endif /* __unused */

#ifndef __dead
#define __dead
#endif /* __dead */

/* number of yank registers */
#define YANK_SIZE 26

struct alias;       /* alias management */
struct atoms;       /* atom storage */
struct camera;      /* an eye of a user */
struct cmd;         /* vimol command */
struct cmdq;        /* command list */
struct edit;        /* string edit control */
struct edge;        /* edge of a graph */
struct graph;       /* vertices connected with edges */
struct history;     /* command-line history management */
struct state;       /* app state */
struct statusbar;   /* status bar and command line */
struct sys;         /* molecular system structure */
struct undo;        /* undo-redo management */
struct wnd;         /* windows */
struct yank;        /* copy-paste buffer */

#include "color.h"
#include "vec.h"
#include "tok.h"
#include "sel.h"
#include "log.h"
#include "pair.h"
#include "platform.h"
#include "rec.h"
#include "settings.h"
#include "spi.h"
#include "util.h"
#include "view.h"
#include "xmalloc.h"

/* alias.c */
struct alias *alias_create(void);
void alias_free(struct alias *);
int alias_set(struct alias *, const char *, const char *);
const char *alias_get(struct alias *, const char *);

/* atoms.c */
struct atoms *atoms_create(void);
struct atoms *atoms_copy(struct atoms *);
void atoms_free(struct atoms *);
void atoms_add(struct atoms *, const char *, vec_t);
void atoms_remove(struct atoms *, int);
void atoms_swap(struct atoms *, int, int);
void atoms_clear(struct atoms *);
int atoms_get_count(struct atoms *);
const char *atoms_get_name(struct atoms *, int);
void atoms_set_name(struct atoms *, int, const char *);
vec_t atoms_get_xyz(struct atoms *, int);
void atoms_set_xyz(struct atoms *, int, vec_t);

/* camera.c */
struct camera *camera_create(void);
void camera_free(struct camera *);
void camera_reset(struct camera *);
void camera_move(struct camera *, vec_t);
void camera_move_to(struct camera *, vec_t);
void camera_rotate(struct camera *, vec_t);
mat_t camera_get_rotation(struct camera *);
void camera_set_scale(struct camera *, double);
double camera_get_scale(struct camera *);
void camera_set_radius(struct camera *, double);
double camera_get_radius(struct camera *);
double camera_get_zoom(struct camera *, int, int);
point_t camera_transform(struct camera *, vec_t);

/* cmd.c */
const char *cmd_name(struct cmd *);
struct tokq *cmd_args(struct cmd *);
int cmd_exec(struct cmd *, struct state *);
struct cmdq *cmdq_from_string(const char *, struct alias *);
void cmdq_free(struct cmdq *);
int cmdq_count(struct cmdq *);
struct cmd *cmdq_cmd(struct cmdq *, int);
int cmdq_exec(struct cmdq *, struct state *);

/* edit.c */
struct edit *edit_create(void);
void edit_free(struct edit *);
const char *edit_get_text(struct edit *);
int edit_get_text_length(struct edit *);
int edit_get_pos(struct edit *);
void edit_set_pos(struct edit *, int);
void edit_set_text(struct edit *, const char *, ...);
void edit_insert_char(struct edit *, char);
void edit_insert_text(struct edit *, const char *);
void edit_backspace_char(struct edit *);
void edit_delete_char(struct edit *);
void edit_backspace_word(struct edit *);
void edit_clear(struct edit *);

/* error.c */
void error_set(const char *, ...);
const char *error_get(void);
void error_clear(void);

/* exec.c */
void exec_init(void);
void exec_free(void);
int exec_valid(const char *);
int exec_run(const char *, struct tokq *, struct state *);

/* graph.c */
struct graph *graph_create(void);
struct graph *graph_copy(struct graph *);
void graph_free(struct graph *);
void graph_clear(struct graph *);
void graph_vertex_add(struct graph *);
void graph_vertex_remove(struct graph *, int);
void graph_vertex_swap(struct graph *, int, int);
int graph_get_vertex_count(struct graph *);
int graph_get_edge_count(struct graph *, int);
void graph_remove_vertex_edges(struct graph *, int);
void graph_edge_create(struct graph *, int, int, int);
void graph_edge_remove(struct graph *, int, int);
struct edge *graph_edges(struct graph *, int);
struct edge *graph_edge_find(struct graph *, int, int);
struct edge *graph_edge_prev(struct edge *);
struct edge *graph_edge_next(struct edge *);
int graph_edge_get_type(struct edge *);
void graph_edge_set_type(struct edge *, int);
int graph_edge_i(struct edge *);
int graph_edge_j(struct edge *);

/* history.c */
struct history *history_create(void);
void history_free(struct history *);
void history_load(struct history *, const char *);
void history_save(struct history *, const char *);
void history_push(struct history *, const char *);
void history_reset_current(struct history *);
int history_next(struct history *);
int history_prev(struct history *);
const char *history_get(struct history *);
int history_search(struct history *, const char *);

/* state.c */
struct state *state_create(void);
void state_free(struct state *);
struct alias *state_get_alias(struct state *);
struct alias *state_get_bind(struct state *);
struct rec *state_get_rec(struct state *);
struct view *state_get_view(struct state *);
struct wnd *state_get_wnd(struct state *);
struct yank *state_get_yank(struct state *);
void state_start_edit(struct state *);
int state_source(struct state *, const char *);
void state_render(struct state *);
void state_save_png(struct state *, const char *);
void state_toggle_fullscreen(struct state *);
void state_quit(struct state *, int);
void state_event_loop(struct state *);
void state_save(struct state *);

/* statusbar.c */
struct statusbar *statusbar_create(void);
void statusbar_free(struct statusbar *);
const char *statusbar_get_text(struct statusbar *);
void statusbar_set_text(struct statusbar *, const char *, ...);
void statusbar_set_error(struct statusbar *, const char *, ...);
void statusbar_clear_text(struct statusbar *);
const char *statusbar_get_info_text(struct statusbar *);
void statusbar_set_info_text(struct statusbar *, const char *, ...);
void statusbar_clear_info_text(struct statusbar *);
void statusbar_set_cursor_pos(struct statusbar *, int);
void statusbar_render(struct statusbar *, cairo_t *);

/* sys.c */
struct sys *sys_create(const char *);
struct sys *sys_copy(struct sys *);
void sys_free(struct sys *);
struct graph *sys_get_graph(struct sys *);
struct sel *sys_get_sel(struct sys *);
struct sel *sys_get_visible(struct sys *);
int sys_read(struct sys *, const char *);
int sys_is_modified(struct sys *);
int sys_get_frame(struct sys *);
void sys_set_frame(struct sys *, int);
int sys_get_frame_count(struct sys *);
void sys_add_atom(struct sys *, const char *, vec_t);
void sys_remove_atom(struct sys *, int);
void sys_swap_atoms(struct sys *, int, int);
int sys_get_atom_count(struct sys *);
const char *sys_get_atom_name(struct sys *, int);
void sys_set_atom_name(struct sys *, int, const char *);
vec_t sys_get_atom_xyz(struct sys *, int);
void sys_set_atom_xyz(struct sys *, int, vec_t);
void sys_add_hydrogens(struct sys *, struct sel *);
vec_t sys_get_sel_center(struct sys *, struct sel *);
void sys_reset_bonds(struct sys *, struct sel *);
int sys_save_to_file(struct sys *, const char *);

/* undo.c */
struct undo *undo_create(void *, void *(*)(void *), void (*)(void *));
void undo_free(struct undo *);
void *undo_get_data(struct undo *);
void undo_snapshot(struct undo *);
int undo_undo(struct undo *);
int undo_redo(struct undo *);

/* wnd.c */
struct wnd *wnd_create(void);
void wnd_free(struct wnd *);
struct view *wnd_get_view(struct wnd *);
int wnd_open(struct wnd *, const char *);
int wnd_close(struct wnd *);
int wnd_is_modified(struct wnd *);
int wnd_any_modified(struct wnd *);
int wnd_next(struct wnd *);
int wnd_prev(struct wnd *);
void wnd_first(struct wnd *);
void wnd_last(struct wnd *);

/* yank.c */
struct yank *yank_create(void);
void yank_free(struct yank *);
void yank_set_register(struct yank *, int);
int yank_get_register(struct yank *);
void yank_copy(struct yank *, struct sys *, struct sel *);
void yank_paste(struct yank *, struct sys *);

#endif /* VIMOL_VIMOL_H */
