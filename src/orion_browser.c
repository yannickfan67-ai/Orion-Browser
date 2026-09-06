#include <stddef.h>
#include "orion_browser.h"
#include "net.h"

static char g_url[160];
static int g_url_len;
static char g_status[96];
static char g_page[4096];

static void copy(char *dst,size_t cap,const char *src){size_t i=0;if(!cap)return;while(src&&src[i]&&i+1<cap){dst[i]=src[i];i++;}dst[i]=0;}

void orion_browser_init(void){
    g_url[0]=0;g_url_len=0;
    copy(g_status,sizeof(g_status),"Ready / lightweight HTTP fallback");
    copy(g_page,sizeof(g_page),"Orion Browser\n\nLightweight recovery browser for UN_Orion.\nUse UN_Vela for Aster-rendered pages.");
}
void orion_browser_input_char(char c){if(g_url_len<(int)sizeof(g_url)-1){g_url[g_url_len++]=c;g_url[g_url_len]=0;}}
void orion_browser_backspace(void){if(g_url_len)g_url[--g_url_len]=0;}
int orion_browser_load_url(const char *url){
    if(!url||!*url){copy(g_status,sizeof(g_status),"Enter an HTTP address");return 0;}
    copy(g_status,sizeof(g_status),"Loading...");
    return net_http_get(url,g_page,sizeof(g_page),g_status,sizeof(g_status));
}
int orion_browser_go(void){return orion_browser_load_url(g_url);}
const char *orion_browser_url(void){return g_url;}
const char *orion_browser_status(void){return g_status;}
const char *orion_browser_page(void){return g_page;}
