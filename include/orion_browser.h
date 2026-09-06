#ifndef ORION_BROWSER_H
#define ORION_BROWSER_H

#define ORION_BROWSER_NAME "Orion Browser"
#define ORION_BROWSER_VERSION "0.1.0"

void orion_browser_init(void);
void orion_browser_input_char(char c);
void orion_browser_backspace(void);
int orion_browser_go(void);
int orion_browser_load_url(const char *url);
const char *orion_browser_url(void);
const char *orion_browser_status(void);
const char *orion_browser_page(void);

#endif
