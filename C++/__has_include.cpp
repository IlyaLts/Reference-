#ifdef __has_include
	#if __has_include(<optional>)
		#include <optional>
		#define have_optional 1
	#elif __has_include(<experimental/optional>)
		#include <experimental/optional>
		#define have_optional 1
		#define experimental_optional
	#else
		#define have_optional 0
	#endif
#endif

#ifdef __has_include
	#if __has_include(<OpenGL/gl.h>)
		#include <OpenGL/gl.h>
		#include <OpenGL/glu.h>
	#elif __has_include(<GL/gl.h>)
		#include <GL/gl.h>
		#include <GL/glu.h>
	#else
		#error No suitable OpenGL headers found.
	#endif
#endif
