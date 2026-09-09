#include <stdio.h>
#include <string.h>
#include "orion_browser.h"

static unsigned g_features=99;
static int g_view_w,g_view_h,g_scroll;
static char g_url[128]="http://example.test/";
static const char *g_status="Ready";
static const char *g_title="Shared Aster document";

void vela_init(int w){g_view_w=w;}
unsigned vela_api_version(void){return (1u<<16)|2u;}
void vela_set_features(unsigned f){g_features=f;}
void vela_set_viewport_size(int w,int h){g_view_w=w;g_view_h=h;}
void vela_input_char(char c){(void)c;}
void vela_backspace(void){}
int vela_go(void){return 1;}
int vela_load_url(const char *u){if(!u)return 0;snprintf(g_url,sizeof(g_url),"%s",u);return 1;}
int vela_back(void){return 1;}int vela_forward(void){return 1;}int vela_reload(void){return 1;}
int vela_can_back(void){return 1;}int vela_can_forward(void){return 1;}
void vela_scroll_by(int d){g_scroll+=d;}int vela_scroll(void){return g_scroll;}
const char *vela_url(void){return g_url;}const char *vela_status(void){return g_status;}const char *vela_title(void){return g_title;}

int main(void){
    orion_browser_init();
    if(!orion_browser_compatible())return 2;
    if(g_features!=0)return 3; /* VELA_PROFILE_LITE: JS disabled */
    if(g_view_w!=480)return 4;
    orion_browser_set_viewport(640,360);
    if(g_view_w!=640||g_view_h!=360)return 5;
    if(!orion_browser_load_url("http://router.local/"))return 6;
    if(strcmp(orion_browser_url(),"http://router.local/")!=0)return 7;
    if(!orion_browser_can_back()||!orion_browser_can_forward())return 8;
    orion_browser_scroll_by(72);if(orion_browser_scroll()!=72)return 9;
    if(strcmp(orion_browser_page(),g_title)!=0)return 10;
    puts("Orion Browser Lite adapter smoke passed");
    return 0;
}
