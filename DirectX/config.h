
/* Written by Peter Ekberg, peda@lysator.liu.se */

#ifndef CONFIG_H
#define CONFIG_H

#undef const
#undef inline

#define __STDC__ 1
#define fdopen _fdopen
#define fileno _fileno
#define strcasecmp _stricmp
#define tolower _tolower
#define random rand
#define srandom srand
#define usleep(x) Sleep((x)/1000)
#define sleep(x) Sleep((x)*1000)
#define M_PI (3.14159265358979323846)
#define hypot(x, y) sqrt((x)*(x) + (y)*(y))
#include <Windows.h>

#undef HAVE_UNISTD_H
#undef HAVE_VALUES_H

#undef HAVE_DEFINE_SCANCODE_P

#define HAVE_GETOPT_H
#undef HAVE_GETOPT_LONG_ONLY

#define HAVE_RANDOM
#define HAVE_USLEEP
#define HAVE_STRDUP

#define HAVE_ATEXIT
#undef HAVE_ON_EXIT

#undef HAVE_XSHMPUTIMAGE


#undef HAVE_SOUND
#ifdef HAVE_SOUND
# undef HAVE_16BIT_SOUND

# undef HAVE_LINUX_SOUND
# ifdef HAVE_LINUX_SOUND
#  undef HAVE_LINUX_SOUNDCARD_H
# endif /* HAVE_LINUX_SOUND */

# undef HAVE_SUN_SOUND
# ifdef HAVE_SUN_SOUND
#  undef HAVE_SYS_AUDIOIO_H
#  undef HAVE_SUN_AUDIOIO_H
#  undef HAVE_SUN_SPEAKER
#  undef HAVE_SUN_HEADPHONE
#  undef HAVE_SUN_LINE_OUT
# endif /* HAVE_SUN_SOUND */

# undef HAVE_HP_SOUND
# ifdef HAVE_HP_SOUND
#  undef HAVE_SYS_AUDIO_H
#  undef HAVE_HP_INTERNAL_SPEAKER
#  undef HAVE_HP_EXTERNAL_SPEAKER
#  undef HAVE_HP_LINE_OUT
# endif /* HAVE_HP_SOUND */

#endif /* HAVE_SOUND */


#define RETSIGTYPE void

#define PRINTF_RETURN 1

#undef _POSIX_C_SOURCE
#undef _XOPEN_SOURCE

#ifndef HAVE_RANDOM
# define random rand
# define srandom srand
#endif /* HAVE_RANDOM */

#ifndef HAVE_USLEEP
void usleep(unsigned long usec);
#endif /* HAVE_USLEEP */

#ifndef HAVE_STRDUP
char *strdup(const char *s);
#endif /* HAVE_STRDUP */

#ifdef HAVE_XSHMPUTIMAGE
# define MITSHM
#endif

#endif /* CONFIG_H */
