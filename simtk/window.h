#ifndef _SIMTK_WINDOW_H
#define _SIMTK_WINDOW_H

#define SIMTK_WINDOW_DEFAULT_TITLE_FOREGROUND OPAQUE (0)
#define SIMTK_WINDOW_DEFAULT_TITLE_BACKGROUND OPAQUE (RGB (0xff, 0xa5, 0))

#define SIMTK_WINDOW_DEFAULT_TITLE_INACTIVE_FOREGROUND OPAQUE (0)
#define SIMTK_WINDOW_DEFAULT_TITLE_INACTIVE_BACKGROUND OPAQUE (RGB (0x7f, 0x52, 0))

#define SIMTK_WINDOW_MIN_BODY_HEIGHT  8
#define SIMTK_WINDOW_MIN_TITLE_HEIGHT 10
#define SIMTK_WINDOW_MIN_HEIGHT (SIMTK_WINDOW_MIN_BODY_HEIGHT + SIMTK_WINDOW_MIN_TITLE_HEIGHT)

struct simtk_window_properties
{
  SDL_mutex *lock;
  
  char *title;

  uint32_t title_background;
  uint32_t title_foreground;

  uint32_t title_inactive_background;
  uint32_t title_inactive_foreground;

  int params_changed;

  void *opaque;
};

simtk_widget_t *simtk_window_new (struct simtk_container *, int, int, int, int, const char *);
struct simtk_container *simtk_window_get_body_container (simtk_widget_t *);
struct simtk_window_properties *simtk_window_get_properties (const simtk_widget_t *);
char *simtk_window_get_title (simtk_widget_t *);
int simtk_widget_is_window (simtk_widget_t *);
void simtk_window_properties_lock (const struct simtk_window_properties *);
void simtk_window_properties_unlock (const struct simtk_window_properties *);

void *simtk_window_get_opaque (const simtk_widget_t *);
void  simtk_window_set_opaque (simtk_widget_t *, void *);

#endif /* _SIMTK_WINDOW_H */
