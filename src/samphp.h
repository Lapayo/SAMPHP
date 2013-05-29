#ifndef SAMPHP_H
#define SAMPHP_H

#include <sampgdk/a_players.h>
#include <sampgdk/a_samp.h>
#include <sampgdk/a_vehicles.h>
#include <sampgdk/a_objects.h>
#include <sampgdk/core.h>
#include <sampgdk/plugin.h>
//#include <sapi/embed/php_embed.h>
#include <php_stl.h>

class samphp : public php_stl 
{
public:
    samphp(bool typeError);

    static samphp* instance;
    static samphp* init();
};

void samphp_output_handler(const char *str);

/*
void samphp_init();
void samphp_shutdown();

void samphp_execute(char *filename);

int samphp_output_handler(const char *str, unsigned int str_length TSRMLS_DC);


*/
#endif
