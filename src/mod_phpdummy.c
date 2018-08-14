#include <stdio.h>
#include <string.h>
#include "httpd.h"
#include "http_config.h"


/*
 ==============================================================================
 Our directive handlers:
 ==============================================================================
 */
const char *nothing(cmd_parms *cmd, void *cfg, const char *arg, const char *arg2)
{
	return NULL;
}

/*
 ==============================================================================
 The directive structure for our name tag:
 ==============================================================================
*/
const command_rec php_directives[] =
{
	AP_INIT_TAKE2("php_value", nothing, NULL, OR_OPTIONS, "PHP Value Modifier"),
	AP_INIT_TAKE2("php_flag", nothing, NULL, OR_OPTIONS, "PHP Flag Modifier"),
	AP_INIT_TAKE2("php_admin_value", nothing, NULL, ACCESS_CONF | RSRC_CONF, "PHP Value Modifier (Admin)"),
	AP_INIT_TAKE2("php_admin_flag", nothing, NULL, ACCESS_CONF | RSRC_CONF, "PHP Flag Modifier (Admin)"),
	AP_INIT_TAKE1("PHPINIDir", nothing, NULL, RSRC_CONF, "Directory containing the php.ini file"),
	{ NULL }
};

/*
 ==============================================================================
 Our module name tag:
 ==============================================================================
 */
module AP_MODULE_DECLARE_DATA phpdummy_module = 
{
	STANDARD20_MODULE_STUFF,
	NULL,               /* Per-directory configuration handler */
	NULL,               /* Merge handler for per-directory configurations */
	NULL,               /* Per-server configuration handler */
	NULL,               /* Merge handler for per-server configurations */
	php_directives, /* Any directives we may have for httpd */
	NULL      /* Our hook registering function */
};
