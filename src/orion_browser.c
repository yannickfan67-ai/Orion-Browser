#include "orion_browser.h"
#include "orion_vela_bridge.h"

static int g_compatible;

void orion_browser_init(void){
    vela_init(480);
    g_compatible=orion_vela_api_compatible(vela_api_version());
    if(g_compatible)vela_set_features(ORION_VELA_PROFILE_LITE);
}
int orion_browser_compatible(void){return g_compatible;}
void orion_browser_set_viewport(int w,int h){if(g_compatible)vela_set_viewport_size(w,h);}
void orion_browser_input_char(char c){if(g_compatible)vela_input_char(c);}
void orion_browser_backspace(void){if(g_compatible)vela_backspace();}
int orion_browser_go(void){return g_compatible?vela_go():0;}
int orion_browser_load_url(const char *url){return g_compatible?vela_load_url(url):0;}
int orion_browser_back(void){return g_compatible?vela_back():0;}
int orion_browser_forward(void){return g_compatible?vela_forward():0;}
int orion_browser_reload(void){return g_compatible?vela_reload():0;}
int orion_browser_can_back(void){return g_compatible?vela_can_back():0;}
int orion_browser_can_forward(void){return g_compatible?vela_can_forward():0;}
void orion_browser_scroll_by(int d){if(g_compatible)vela_scroll_by(d);}
int orion_browser_scroll(void){return g_compatible?vela_scroll():0;}
const char *orion_browser_url(void){return g_compatible?vela_url():"";}
const char *orion_browser_status(void){return g_compatible?vela_status():"UN_Vela 0.3 API unavailable";}
const char *orion_browser_title(void){return g_compatible?vela_title():ORION_BROWSER_NAME;}
const char *orion_browser_page(void){return orion_browser_title();}
