

// These are stubs for functions that are actually defined
// in external bridge library and hijacked at convert time.

#define EXTERN_TYPE

#define MAKE_WRAPPER_(_A, ...)  void    _bridge_##_A() { return; }
#define MAKE_WRAPPER(_A, ...)  void*    _bridge_##_A() { return 0; }

#include "syscalls.in"

int _bridge_bionic_clone() { return 0; }

long _bridge_syscall(long __number, ...) { return __number;}

//int __libc_format_log() { return 0; }
//int __libc_format_buffer() { return 0; }
//int __libc_format_fd() { return 0; }
//int __libc_fatal() { return 0; }

int __libc_init_main_thread() { return 0; }
int __libc_init_globals() { return 0; }
int __libc_init_AT_SECURE() { return 0; }



/*
#if defined(__arm__)
void _bridge_arm_fadvise64_64() { return; }
void _bridge_vfork() { return; }
#endif


//void* __openat(const char* filename __unused, int flag __unused) { return 0; }
void*    _bridge_openat() { return 0; }
//int   uname(void* utsname __unused)  { return 0; }
void*    _bridge_uname() { return 0; }


void*    _bridge_accept4() { return 0; }
void*    _bridge_bind() { return 0; }
void*    _bridge_brk() { return 0; }
void*    _bridge_clock_getres() { return 0; }
void*    _bridge_clock_gettime() { return 0; }
void*    _bridge_clock_nanosleep() { return 0; }
void*    _bridge_close() { return 0; }
void*    _bridge_connect() { return 0; }
void*    _bridge_cxa_thread_finalize() { return 0; }
void*    _bridge_dup() { return 0; }
void*    _bridge_dup3() { return 0; }
void*    _bridge_epoll_create1() { return 0; }
void*    _bridge_epoll_ctl() { return 0; }
void*    _bridge_eventfd() { return 0; }
void*    _bridge_epoll_pwait() { return 0; }
void*    _bridge_execve() { return 0; }
void*    _bridge_exit() { return 0; }
void*    _bridge__exit() { return 0; }
void*    _bridge_Exit() { return 0; }
void*    _bridge_faccessat() { return 0; }
void*    _bridge_fadvise64() { return 0; }
void*    _bridge_fallocate64() { return 0; }
void*    _bridge_fcntl64() { return 0; }
void*    _bridge_fgetxattr() { return 0; }
void*    _bridge_fchdir() { return 0; }
void*    _bridge_fchmod() { return 0; }
void*    _bridge_fchmodat() { return 0; }
void*    _bridge_fchown() { return 0; }
void*    _bridge_fchownat() { return 0; }
void*    _bridge_fdatasync() { return 0; }
void*    _bridge_flock() { return 0; }
void*    _bridge_fsetxattr() { return 0; }
void*    _bridge_fstat() { return 0; }
void*    _bridge_fstatat() { return 0; }
void*    _bridge_fstatfs64() { return 0; }
void*    _bridge_ftruncate64() { return 0; }
void*    _bridge_getcpu() { return 0; }
void*    _bridge_getcwd() { return 0; }
void*    _bridge_getdents64() { return 0; }
void*    _bridge_getegid() { return 0; }
void*    _bridge_geteuid() { return 0; }
void*    _bridge_getgid() { return 0; }
void*    _bridge_getgroups() { return 0; }
void*    _bridge_getpeername() { return 0; }
void*    _bridge_getpgid() { return 0; }
void*    _bridge_getpid() { return 0; }
void*    _bridge_getpriority() { return 0; }
void*    _bridge_getrlimit() { return 0; }
void*    _bridge_getsockname() { return 0; }
void*    _bridge_getsockopt() { return 0; }
void*    _bridge_gettimeofday() { return 0; }
void*    _bridge_getuid() { return 0; }
void*    _bridge_getxattr() { return 0; }
void*    _bridge_gmtime() { return 0; }
void*    _bridge_chdir() { return 0; }
void*    _bridge_inotify_init1() { return 0; }
void*    _bridge_ioctl() { return 0; }
void*    _bridge_kill() { return 0; }
void*    _bridge_linkat() { return 0; }
void*    _bridge_listen() { return 0; }
void*    _bridge_llseek() { return 0; }
void*    _bridge_localtime() { return 0; }
void*    _bridge_localtime_r() { return 0; }
void*    _bridge_lseek() { return 0; }
void*    _bridge_madvise() { return 0; }
void*    _bridge_mkdirat() { return 0; }
void*    _bridge_mknodat() { return 0; }
void*    _bridge_mktime() { return 0; }
void*    _bridge_mmap2() { return 0; }
void*    _bridge_mount() { return 0; }
void*    _bridge_mprotect() { return 0; }
void*    _bridge_munmap() { return 0; }
void*    _bridge_nanosleep() { return 0; }
void*    _bridge_pipe2() { return 0; }
void*    _bridge_ppoll() { return 0; }
void*    _bridge_prctl() { return 0; }
void*    _bridge_pread64() { return 0; }
void*    _bridge_prlimit64() { return 0; }
void*    _bridge_pselect6() { return 0; }
void*    _bridge_ptrace() { return 0; }
void*    _bridge_pwrite64() { return 0; }
void*    _bridge_read() { return 0; }
void*    _bridge_readlinkat() { return 0; }
void*    _bridge_reboot() { return 0; }
void*    _bridge_recvfrom() { return 0; }
void*    _bridge_recvmsg() { return 0; }
void*    _bridge_renameat() { return 0; }
void*    _bridge_rt_sigpending() { return 0; }
void*    _bridge_rt_sigprocmask() { return 0; }
void*    _bridge_rt_sigqueueinfo() { return 0; }
void*    _bridge_rt_sigsuspend() { return 0; }
void*    _bridge_rt_sigtimedwait() { return 0; }
void*    _bridge_sendto() { return 0; }
void*    _bridge_sendmsg() { return 0; }
void*    _bridge_sendfile() { return 0; }
void*    _bridge_setgroups() { return 0; }
void*    _bridge_setitimer() { return 0; }
void*    _bridge_setpgid() { return 0; }
void*    _bridge_setpriority() { return 0; }
void*    _bridge_setresgid() { return 0; }
void*    _bridge_setresuid() { return 0; }
void*    _bridge_setrlimit() { return 0; }
void*    _bridge_setsid() { return 0; }
void*    _bridge_setsockopt() { return 0; }
void*    _bridge_set_thread_area() { return 0; }
void*    _bridge_set_tid_address() { return 0; }
void*    _bridge_setxattr() { return 0; }
void*    _bridge_shutdown() { return 0; }
void*    _bridge_sched_getaffinity() { return 0; }
void*    _bridge_sched_getparam() { return 0; }
void*    _bridge_sched_getscheduler() { return 0; }
void*    _bridge_sched_setscheduler() { return 0; }
void*    _bridge_sched_yield() { return 0; }
void*    _bridge_sigaction() { return 0; }
void*    _bridge_sigaltstack() { return 0; }
void*    _bridge_signalfd4() { return 0; }
void*    _bridge_socket() { return 0; }
void*    _bridge_socketpair() { return 0; }
void*    _bridge_statfs64() { return 0; }
void*    _bridge_symlinkat() { return 0; }
void*    _bridge_sync() { return 0; }
void*    _bridge_tgkill() { return 0; }
void*    _bridge_timer_create() { return 0; }
void*    _bridge_timer_delete() { return 0; }
void*    _bridge_timer_getoverrun() { return 0; }
void*    _bridge_timer_gettime() { return 0; }
void*    _bridge_timer_settime() { return 0; }
void*    _bridge_umask() { return 0; }
void*    _bridge_umount2() { return 0; }
void*    _bridge_unlinkat() { return 0; }
void*    _bridge_unshare() { return 0; }
void*    _bridge_utimensat() { return 0; }
void*    _bridge_waitid() { return 0; }
void*    _bridge_wait4() { return 0; }
void*    _bridge_write() { return 0; }
void*    _bridge_writev() { return 0; }
void**   _bridge_get_tls() { return 0; }
int      _bridge_set_tls() { return 0; }
int      _bridge_bionic_clone() { return 0; }

*/