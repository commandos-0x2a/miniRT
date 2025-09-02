LOG_MSG = LOG_MSG(format, \#\#__VA_ARGS__)

LOG_LEVEL ?= ERROR DEBUG FATAL INFO

DEBUG_FD ?= 2

CPPFLAGS += -D'LOG_MSG(format, ...)=ft_fprintf($(DEBUG_FD), "%s:%d "format"\n",__FILE__, __LINE__, \#\#__VA_ARGS__)'


CPPFLAGS += -D'DEBUG_FD=$(DEBUG_FD)'

ifneq ($(findstring DEBUG,$(LOG_LEVEL)),)
CPPFLAGS += -D'LOG_DEBUG(format, ...)=$(LOG_MSG)'
else
CPPFLAGS += -D'LOG_DEBUG(...)=;'
endif

ifneq ($(findstring INFO,$(LOG_LEVEL)),)
CPPFLAGS += -D'LOG_INFO(format, ...)=$(LOG_MSG)'
else
CPPFLAGS += -D'LOG_INFO(...)=;'
endif

ifneq ($(findstring WARN,$(LOG_LEVEL)),)
CPPFLAGS += -D'LOG_WARN(format, ...)=$(LOG_MSG)'
else
CPPFLAGS += -D'LOG_WARN(...)=;'
endif

ifneq ($(findstring ERROR,$(LOG_LEVEL)),)
CPPFLAGS += -D'LOG_ERROR(format, ...)=$(LOG_MSG)'
else
CPPFLAGS += -D'LOG_ERROR(...)=;'
endif

ifneq ($(findstring FATAL,$(LOG_LEVEL)),)
CPPFLAGS += -D'LOG_FATAL(format, ...)=$(LOG_MSG)'
else
CPPFLAGS += -D'LOG_FATAL(...)=;'
endif

SRC += debug/log.c
