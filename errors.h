#ifndef ERRORS_H
#define ERRORS_H

/** коды ошибок
 */
#define ERR_ENTRY(code) code

typedef enum
{
#include "errors_entry.inl"
} t_ret;

#undef ERR_ENTRY

#endif // ERRORS_H
