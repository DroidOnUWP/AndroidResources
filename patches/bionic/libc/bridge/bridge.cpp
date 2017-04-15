#if defined(_FORTIFY_SOURCE)
#undef _FORTIFY_SOURCE
#endif


#include <stdarg.h>
#include "unistd.h"
#include "sys/capability.h"
#include "sys/mman.h"

#define EXTERN_TYPE

#define MAKE_WRAPPER_(bridgename, exportname, ret, p1_type, p1_name)\
	extern "C" ret _bridge_##bridgename (p1_type p1_name);\
	EXTERN_TYPE ret exportname (p1_type p1_name) { _bridge_##bridgename (p1_name); }

#define MAKE_WRAPPER0(bridgename, exportname, ret)\
	extern "C" ret _bridge_##bridgename(void);\
	EXTERN_TYPE ret exportname (void) { return _bridge_##bridgename (); }

#define MAKE_WRAPPER1(bridgename, exportname, ret, p1_type, p1_name)\
	extern "C" ret _bridge_##bridgename (p1_type p1_name);\
	EXTERN_TYPE ret exportname (p1_type p1_name) { return _bridge_##bridgename (p1_name); }

#define MAKE_WRAPPER2(bridgename, exportname, ret, p1_type, p1_name, p2_type, p2_name)\
	extern "C" ret _bridge_##bridgename (p1_type p1_name, p2_type p2_name);\
	EXTERN_TYPE ret exportname (p1_type p1_name, p2_type p2_name) { return _bridge_##bridgename (p1_name, p2_name); }

#define MAKE_WRAPPER3(bridgename, exportname, ret, p1_type, p1_name, p2_type, p2_name, p3_type, p3_name)\
	extern "C" ret _bridge_##bridgename (p1_type p1_name, p2_type p2_name, p3_type p3_name);\
	EXTERN_TYPE ret exportname (p1_type p1_name, p2_type p2_name, p3_type p3_name) { return _bridge_##bridgename (p1_name, p2_name, p3_name); }

#define MAKE_WRAPPER4(bridgename, exportname, ret, p1_type, p1_name, p2_type, p2_name, p3_type, p3_name, p4_type, p4_name)\
	extern "C"  ret _bridge_##bridgename (p1_type p1_name, p2_type p2_name, p3_type p3_name, p4_type p4_name);\
	EXTERN_TYPE ret exportname (p1_type p1_name, p2_type p2_name, p3_type p3_name, p4_type p4_name) { return _bridge_##bridgename (p1_name, p2_name, p3_name, p4_name); }

#define MAKE_WRAPPER5(bridgename, exportname, ret, p1_type, p1_name, p2_type, p2_name, p3_type, p3_name, p4_type, p4_name, p5_type, p5_name)\
	extern "C" ret _bridge_##bridgename (p1_type p1_name, p2_type p2_name, p3_type p3_name, p4_type p4_name, p5_type p5_name);\
	EXTERN_TYPE ret exportname (p1_type p1_name, p2_type p2_name, p3_type p3_name, p4_type p4_name, p5_type p5_name) { return _bridge_##bridgename (p1_name, p2_name, p3_name, p4_name, p5_name); }

#define MAKE_WRAPPER6(bridgename, exportname, ret, p1_type, p1_name, p2_type, p2_name, p3_type, p3_name, p4_type, p4_name, p5_type, p5_name, p6_type, p6_name)\
	extern "C" ret _bridge_##bridgename (p1_type p1_name, p2_type p2_name, p3_type p3_name, p4_type p4_name, p5_type p5_name, p6_type p6_name);\
	EXTERN_TYPE ret exportname (p1_type p1_name, p2_type p2_name, p3_type p3_name, p4_type p4_name, p5_type p5_name, p6_type p6_name) { return _bridge_##bridgename (p1_name, p2_name, p3_name, p4_name, p5_name, p6_name); }

#define GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, NAME, ...) NAME

#define MAKE_WRAPPER(_A, ...) GET_MACRO(__VA_ARGS__, WRONG_PARAM_NUM, MAKE_WRAPPER6, WRONG_PARAM_NUM, MAKE_WRAPPER5, WRONG_PARAM_NUM, MAKE_WRAPPER4, WRONG_PARAM_NUM, MAKE_WRAPPER3, WRONG_PARAM_NUM, MAKE_WRAPPER2, WRONG_PARAM_NUM, MAKE_WRAPPER1, WRONG_PARAM_NUM, MAKE_WRAPPER0) (_A, __VA_ARGS__)


#include "syscalls.in" 


#if defined(_arm__)
#endif
extern "C" pid_t _bridge_bionic_clone(uint32_t flags, void* child_stack, int* parent_tid, void* tls, int* child_tid, int (*fn)(void*), void* arg);

extern "C" pid_t __bionic_clone(uint32_t flags, void* child_stack, int* parent_tid, void* tls, int* child_tid, int (*fn)(void*), void* arg)
{
	return _bridge_bionic_clone(flags, child_stack, parent_tid, tls, child_tid, fn, arg);
}


extern "C" long _bridge_syscall(long __number, ...);

extern "C" long syscall(long __number, ...)
{
	va_list args;
	va_start(args, __number);
	long ret = _bridge_syscall(__number, args);
	va_end(args);
	return ret;
}




