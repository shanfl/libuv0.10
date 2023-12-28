project(libuv0.1.0)

set(uv_src_incs ./include/uv.h 
./include/uv-private/tree.h
./include/uv-private/uv-linux.h
)

set(uv_srcs 
./src/unix/async.c
./src/unix/atomic-ops.h
./src/unix/core.c
./src/unix/dl.c
./src/unix/error.c
./src/unix/fs.c
#./src/unix/fsevents.c
./src/unix/getaddrinfo.c
./src/unix/internal.h
./src/unix/linux-core.c
./src/unix/linux-inotify.c
./src/unix/linux-syscalls.c
./src/unix/linux-syscalls.h
./src/unix/loop-watcher.c
./src/unix/loop.c
./src/unix/pipe.c
./src/unix/poll.c
./src/unix/process.c
./src/unix/proctitle.c
./src/unix/signal.c
./src/unix/stream.c
./src/unix/tcp.c
./src/unix/thread.c
./src/unix/timer.c
./src/unix/tty.c
./src/unix/udp.c
./src/fs-poll.c
./src/inet.c
./src/uv-common.c
./src/uv-common.h
./src/version.c
)
include_directories(./include)
add_library(libuv SHARED ${uv_srcs} ${uv_src_incs})
target_include_directories(libuv PRIVATE ./src ./include/uv-private)