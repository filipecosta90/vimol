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

#include "color.h"
#include "vec.h"
#include "atoms.h"
#include "tok.h"
#include "sel.h"
#include "sys.h"
#include "alias.h"
#include "camera.h"
#include "edit.h"
#include "error.h"
#include "state.h"
#include "cmd.h"
#include "exec.h"
#include "graph.h"
#include "history.h"
#include "log.h"
#include "pair.h"
#include "platform.h"
#include "rec.h"
#include "settings.h"
#include "spi.h"
#include "status.h"
#include "undo.h"
#include "util.h"
#include "view.h"
#include "wins.h"
#include "yank.h"
#include "xmalloc.h"

#endif /* VIMOL_VIMOL_H */
