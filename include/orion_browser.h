#ifndef ORION_BROWSER_H
#define ORION_BROWSER_H

#include <stdint.h>

#define ORION_BROWSER_NAME "Orion Browser"
#define ORION_BROWSER_VERSION "0.2.1"

typedef enum OrionBrowserAction {
    ORION_BROWSER_BACK=1,
    ORION_BROWSER_FORWARD,
    ORION_BROWSER_RELOAD,
    ORION_BROWSER_LINE_UP,
    ORION_BROWSER_LINE_DOWN,
    ORION_BROWSER_PAGE_UP,
    ORION_BROWSER_PAGE_DOWN,
    ORION_BROWSER_HOME,
    ORION_BROWSER_END
} OrionBrowserAction;

/*
 * Lightweight recovery shell over the shared UN_Vela/Aster runtime.
 * The shell intentionally selects VELA_PROFILE_LITE, so JavaScript is off
 * while HTML/CSS/layout/history/scroll remain provided by the same core.
 */
void orion_browser_init(void);
int orion_browser_compatible(void);
void orion_browser_set_viewport(int width,int height);
void orion_browser_input_char(char c);
void orion_browser_backspace(void);
int orion_browser_go(void);
int orion_browser_load_url(const char *url);
int orion_browser_back(void);
int orion_browser_forward(void);
int orion_browser_reload(void);
int orion_browser_can_back(void);
int orion_browser_can_forward(void);
int orion_browser_navigate(OrionBrowserAction action);
void orion_browser_scroll_by(int delta_y);
int orion_browser_scroll(void);
const char *orion_browser_url(void);
const char *orion_browser_status(void);
const char *orion_browser_title(void);

/* Legacy text-slot accessor. It now aliases the rendered document title. */
const char *orion_browser_page(void);

#endif
