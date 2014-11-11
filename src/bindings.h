#ifndef BINDINGS_H
#define BINDINGS_H

#include <string>
#include <sapi/embed/php_embed.h>

#ifdef ZTS
    void ***tsrm_ls;
#endif

extern zend_module_entry samphp_module_entry;

#endif
